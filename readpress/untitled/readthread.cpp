#include "readthread.h"

Readthread::Readthread(const QString& serialport, const int& baud) :
    m_SerialObj(nullptr),
    m_Serialport(serialport),
    m_Baudrate(baud),
    m_threadRun(true)
{

}

int Readthread::initReadthread()
{
    m_SerialObj = new QSerialPort();
    m_SerialObj->setPortName(m_Serialport);
    m_SerialObj->setBaudRate(m_Baudrate);
    m_SerialObj->setDataBits(QSerialPort::Data8);
    m_SerialObj->setParity(QSerialPort::NoParity);
    m_SerialObj->setStopBits(QSerialPort::OneStop);
    m_SerialObj->setFlowControl(QSerialPort::NoFlowControl);
    //connect(m_SerialObj, &QSerialPort::readyRead, this, &Readthread::SlotRecvData);
    m_SerialObj->close();
    if(!m_SerialObj->open(QIODevice::ReadWrite))
    {
        delete m_SerialObj;
        m_SerialObj = nullptr;
        return 1;
    }
    return 0;
}

int Readthread::uninitReadthread()
{
    SlotStop();
}

int Readthread::SlotStart()
{
    if(m_SerialObj == nullptr)
        return 1;
    if(!m_SerialObj->isOpen())
    {
        m_SerialObj->close();
        m_SerialObj->setPortName(m_Serialport);
        if(!m_SerialObj->open(QIODevice::ReadWrite))
            return 1;
    }
    m_threadRun = true;
    this->start();
    return 0;
}

void Readthread::SlotStop()
{
    m_threadRun = false;
    this->quit();
    this->wait();
    if(m_SerialObj == nullptr)
        return;
    m_SerialObj->close();
}

void Readthread::SetSerialport(const QString &serialport, const int &baud)
{
    m_Serialport = serialport;
    m_Baudrate = baud;
}

void Readthread::run()
{
    QByteArray recvData;
    while(m_threadRun)
    {
        m_SerialObj->waitForReadyRead(100);
        recvData.append(m_SerialObj->readAll());
        if(recvData.length() > 0)
        {
            emit SigRecvData(recvData.toFloat());
            recvData.clear();
        }
        msleep(50);
    }
    return;
}
