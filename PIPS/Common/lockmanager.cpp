#include "lockmanager.h"
#include "QDebug"

static LockManager *gInstance = nullptr;
static volatile bool gStopThread = true;

LockManager *LockManager::getRtcInstance()
{
    if(gInstance == nullptr)
    {
        gInstance = new LockManager();
    }
    return gInstance;
}

void LockManager::closeRtcInstance()
{
    if(gInstance == nullptr)
        return;
    gInstance->stopLockThread();
    delete gInstance;
    gInstance = nullptr;
}

void LockManager::updateTestStatus(const bool p_status)
{
    m_TestStatus = p_status;
}

void LockManager::updateLockTime(const int p_time)
{
    m_TimeMutex.lock();
    m_LockTime = p_time;
    m_TimeMutex.unlock();
}

void LockManager::updateLockPwd(const QString &p_pwd)
{
    m_LockPwd = p_pwd;
}

void LockManager::startLockThread()
{
    connect(this, &LockManager::sigStartLock, this,
            &LockManager::slotStartLock, Qt::QueuedConnection);
    gStopThread = false;
    m_LockTimeCnt = 0;
    gInstance->start();
}

void LockManager::stopLockThread()
{
    disconnect(this, &LockManager::sigStartLock, this,
            &LockManager::slotStartLock);
    gStopThread = true;
    m_LockTimeCnt = 0;
    this->quit();
    this->wait();
}

bool LockManager::getThreadStatus()
{
    return gStopThread;
}

void LockManager::setParent(QWidget *parent)
{
    m_Parent = parent;
}

void LockManager::slotStartLock()
{
    if(m_LockDialog == nullptr)
        m_LockDialog = new LockDialog(m_Parent);
    connect(m_LockDialog, &LockDialog::sigStopTest, this, &LockManager::slotStopTest);
    m_LockDialog->initLockDialog(m_LockPwd, m_TestStatus);
    if(m_LockDialog->exec() == QDialog::Accepted)
    {

    }
    disconnect(m_LockDialog, &LockDialog::sigStopTest, this, &LockManager::slotStopTest);
    delete m_LockDialog;
    m_LockDialog = nullptr;
    m_TimeMutex.lock();
    m_LockTimeCnt = 0;
    m_TimeMutex.unlock();
}

void LockManager::slotResetLockTime()
{
    m_TimeMutex.lock();
    m_LockTimeCnt = 0;
    m_TimeMutex.unlock();
}

void LockManager::slotStopTest()
{
    emit sigStopTest();
}

void LockManager::run()
{
    while(1)
    {
        if(gStopThread)
            return;
        //qDebug() << "zzp " << m_LockTimeCnt << m_LockTime;
        m_TimeMutex.lock();
        if(m_LockTimeCnt < m_LockTime)
        {
            m_LockTimeCnt++;
            m_TimeMutex.unlock();
            QThread::sleep(1);
            continue;
        }
        m_LockTimeCnt = 0;
        m_TimeMutex.unlock();
        if(m_LockDialog != nullptr)
        {
            QThread::sleep(1);
            continue;
        }
        emit sigStartLock();
        QThread::sleep(1);
    }
}

LockManager::LockManager(QObject *parent)
{
    m_LockDialog = nullptr;
    m_Parent = nullptr;
}
