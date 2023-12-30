#include "testthread.h"
#include <QDebug>

static void callbackData(const NE6882Msg p_data, unsigned int p_User)
{
    if(p_User != 0)
    {
        TestThread *threadObj = (TestThread *)p_User;
        threadObj->handRecv(p_data);
    }
    return;
}

TestThread::TestThread() :
    m_SerialObj(nullptr)
{

}

int TestThread::initThread(const QString p_port, const int p_baud, const int p_timeout)
{
    m_SerialObj = new Ne6882serial();
    int nRet = m_SerialObj->InitNe6882Serial(p_port, p_baud, p_timeout, callbackData, (unsigned int)this);
    if(nRet != 0)
    {
        delete m_SerialObj;
        m_SerialObj = nullptr;
        return nRet;
    }
    m_SerialObj->StartRun();
    return nRet;
}

void TestThread::slotStartRun()
{
    if(m_SerialObj != nullptr)
        m_SerialObj->StartRun();
}

void TestThread::slotStopRun()
{
    if(m_SerialObj != nullptr)
        m_SerialObj->StopRun();
}

void TestThread::slotSendCmd(const NE6882Msg p_data)
{
    if(m_SerialObj != nullptr)
        m_SerialObj->SendCmd(p_data);
}

void TestThread::closeThread()
{
    if(m_SerialObj != nullptr)
    {
        m_SerialObj->CloseNe6882Serial();
        delete m_SerialObj;
        m_SerialObj = nullptr;
    }

}

void TestThread::handRecv(const NE6882Msg p_data)
{
    emit sigRecv(p_data);
}
