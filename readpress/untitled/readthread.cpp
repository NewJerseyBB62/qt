#include "readthread.h"

Readthread::Readthread(const QString& serialport, const int& baud) :
    m_SerialObj(nullptr),
    m_Serialport(serialport),
    m_Baudrate(baud)
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
}
