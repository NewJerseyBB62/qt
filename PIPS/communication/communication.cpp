#include "communication.h"
#include <QDebug>

static WriteThread *gWriteInstance = nullptr;
static ReadThread *gReadInstance = nullptr;

WriteThread::WriteThread()
{
    m_ThreadStatus = false;
    m_CanObj = nullptr;
}

WriteThread *WriteThread::getWriteThread()
{
    if(gWriteInstance == nullptr)
    {
        gWriteInstance = new WriteThread();
    }
    return gWriteInstance;
}

void WriteThread::closeWriteThread()
{
    if(gWriteInstance == nullptr)
        return;
    //gInstance->deleteLater();
    delete gWriteInstance;
    gWriteInstance = nullptr;
}

void WriteThread::StartThread()
{
    m_ThreadStatus = true;
    m_QueueLock.lock();
    m_QueueBuff.clear();
    m_QueueLock.unlock();
    if(m_CanObj == nullptr)
    {
        m_CanObj = new CanProtocol();
        m_CanObj->initCan();
    }
    this->start();
}

void WriteThread::StopThread()
{
    m_ThreadStatus = false;
    this->quit();
    this->wait();
}

void WriteThread::uninitWriteThread()
{
    if(m_ThreadStatus)
        m_ThreadStatus = false;
    this->quit();
    this->wait();
    if(m_CanObj != nullptr)
    {
        m_CanObj->uninitCan();
        delete m_CanObj;
        m_CanObj = nullptr;
    }
}

void WriteThread::run()
{
    while(1)
    {
        if(!m_ThreadStatus)
            return;
        CanSendData data;
        m_QueueLock.lock();
        if(m_QueueBuff.count() > 0)
        {
            data = m_QueueBuff.at(0);
            m_QueueBuff.pop_front();
        }
        else
        {
            m_QueueLock.unlock();
            msleep(300);
            continue;
        }
        m_QueueLock.unlock();
        m_CanObj->writeCan(data);
    }
}

void WriteThread::slotSendTestData(const CanSendData p_senddata)
{
    m_QueueLock.lock();
    m_QueueBuff.append(p_senddata);
    m_QueueLock.unlock();
}

ReadThread::ReadThread()
{
    m_ThreadStatus = false;
    m_CanObj = nullptr;
}

ReadThread *ReadThread::getReadThread()
{
    if(gReadInstance == nullptr)
    {
        gReadInstance = new ReadThread();
    }
    return gReadInstance;
}

void ReadThread::closeReadThread()
{
    if(gReadInstance == nullptr)
        return;
    //gInstance->deleteLater();
    delete gReadInstance;
    gReadInstance = nullptr;
}

void ReadThread::StartThread()
{
    m_ThreadStatus = true;
    if(m_CanObj == nullptr)
    {
        m_CanObj = new CanProtocol();
        m_CanObj->initCan();
    }
    this->start();
}

void ReadThread::StopThread()
{
    m_ThreadStatus = false;
    this->quit();
    this->wait();
}

void ReadThread::uninitReadThread()
{
    if(m_ThreadStatus)
        m_ThreadStatus = false;
    this->quit();
    this->wait();
    if(m_CanObj != nullptr)
    {
        m_CanObj->uninitCan();
        delete m_CanObj;
        m_CanObj = nullptr;
    }
}

void ReadThread::run()
{
    while(1)
    {
        if(!m_ThreadStatus)
            return;
        QList<struct can_frame> frame;
        PrintData data;
        if(m_CanObj->readCan(frame) != 0)
        {
            msleep(100);
            continue;
        }
        int i = 0;
        while(i < frame.count())
        {
            if(i == 0)
            {
                IntValue nVal;
                data.status = frame.at(i).data[0];
                data.step1 = frame.at(i).data[1];
                data.step2 = frame.at(i).data[2];
                data.step3 = frame.at(i).data[3];
                nVal.byte1 = frame.at(i).data[4];
                nVal.byte2 = frame.at(i).data[5];
                nVal.byte3 = frame.at(i).data[6];
                nVal.byte4 = frame.at(i).data[7];
                data.fanSpeed = nVal.nValue;
            }
            else
            {
                FloatValue fVal[2];
                fVal[0].byte1 = frame.at(i).data[0];
                fVal[0].byte2 = frame.at(i).data[1];
                fVal[0].byte3 = frame.at(i).data[2];
                fVal[0].byte4 = frame.at(i).data[3];
                fVal[1].byte1 = frame.at(i).data[4];
                fVal[1].byte2 = frame.at(i).data[5];
                fVal[1].byte3 = frame.at(i).data[6];
                fVal[1].byte4 = frame.at(i).data[7];
                data.fData[2 * i - 1] = fVal[0].fValue;
                data.fData[2 * i] = fVal[1].fValue;
            }
            i++;
        }
        emit sigReadTestData(data);
        msleep(100);
        continue;
    }
}
