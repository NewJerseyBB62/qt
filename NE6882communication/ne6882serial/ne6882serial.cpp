#include "ne6882serial.h"
#include <QtMath>
#include <QDateTime>
#include <QDebug>

SerialThread::SerialThread() :
    m_ThreadRun(true),
    m_SerialObj(nullptr),
    m_Func(nullptr),
    m_User(0),
    m_ReadTimeout(300),
    m_AckAttempts(0),
    m_RecvState(false),
    m_FirstCmd(true)
{

}

int SerialThread::InitSerialThread(const QString& p_port, const int p_baud, const int p_timeout, requsetCallback p_callback, const unsigned int p_user)
{
    m_SerialPort = p_port;
    m_Baudrate = p_baud;
    m_Func = p_callback;
    m_User = p_user;
    m_ReadTimeout = p_timeout;
    m_SerialObj = new QSerialPort();
    m_SerialObj->setPortName(m_SerialPort);
    m_SerialObj->setBaudRate(m_Baudrate);
    m_SerialObj->setDataBits(QSerialPort::Data8);
    m_SerialObj->setParity(QSerialPort::NoParity);
    m_SerialObj->setStopBits(QSerialPort::OneStop);
    m_SerialObj->setFlowControl(QSerialPort::NoFlowControl);
    connect(m_SerialObj, &QSerialPort::readyRead, this, &SerialThread::SlotRecvData);
    m_SerialObj->close();
    if(!m_SerialObj->open(QIODevice::ReadWrite))
    {
        delete m_SerialObj;
        m_SerialObj = nullptr;
        return 1;
    }
    sendACK();
    //msleep(300);
    return 0;
}

void SerialThread::uninitSerial()
{
    if(m_SerialObj != nullptr)
    {
        m_SerialObj->close();
        delete m_SerialObj;
        m_SerialObj = nullptr;
    }
    m_RecvData.clear();

}

int SerialThread::SendCmd(const NE6882Msg &p_data)
{
    m_Mutex.lock();
    if(m_CmdList.size() > 24)
        m_CmdList.clear();
    m_CmdList.append(p_data);
    m_Mutex.unlock();
}

int SerialThread::SetThreadRun(bool p_state)
{
    m_Mutex.lock();
    m_ThreadRun = p_state;
    m_Mutex.unlock();
    msleep(100);
}

void SerialThread::SlotRecvData()
{
    if(m_SerialObj == nullptr)
        return;
    if(m_RecvState)
    {
        m_SerialObj->waitForReadyRead(30);
        m_RecvData.append(m_SerialObj->readAll());
        //qDebug()<< "zzp recv slot: " << m_RecvData.toHex() << " id " << QThread::currentThreadId();
        m_MutexRecv.lock();
        NE6882Msg data;
        data.cmdType = NE6882_CMD::CMD_REQUEST;
        data.testState = NE6882_STATE::STATE_UNKNOWN;
        int nRet = ParseRecvCmd(data);
        m_MutexRecv.unlock();
        if(nRet == 2)
        {
            m_MutexSend.lock();
            sendACK();
            m_MutexSend.unlock();
        }
    }

}

void SerialThread::run()
{
    while(1)
    {
        if(m_ThreadRun)
        {
            if(m_CmdList.size() > 0)
            {
                QByteArray sendData;
                int nRecvLen;
                sendData.clear();
                NE6882Msg currData = m_CmdList.first();
                int nRet = ParseSendCmd(currData, &sendData, nRecvLen);
                if(nRet != 0)
                {
                    m_CmdList.pop_front();
                    m_AckAttempts = 0;
                    msleep(50);
                    continue;
                }
                else
                {
                    _RESEND:
                    int nCnt = 0;
                    int maxCnt = (500 - m_ReadTimeout) / 10;
                    m_MutexSend.lock();

                    int nLen = m_SerialObj->write(sendData);
                    m_SerialObj->waitForBytesWritten(100);

                    m_MutexSend.unlock();
                    //qDebug()<<" zzp send: " << sendData.toHex() << "len " << nLen;
                    //quint64 msec = QDateTime::currentDateTime().toMSecsSinceEpoch();
                    //if(m_SerialObj->waitForReadyRead(1000))//m_ReadTimeout))
                    //quint64 msec = QDateTime::currentDateTime().toMSecsSinceEpoch();
                    if(m_SerialObj->waitForReadyRead(getFirstTimeout()))
                    {
                        m_MutexRecv.lock();
                        m_RecvData.append(m_SerialObj->readAll());
                        m_MutexRecv.unlock();
                        while(m_RecvData.length() < nRecvLen)
                        {
                            m_MutexRecv.lock();
                            m_RecvData.append(m_SerialObj->readAll());
                            m_MutexRecv.unlock();
                            nCnt++;
                            if(nCnt > maxCnt)
                            {
                                m_AckAttempts++;
                                break;
                            }
                            msleep(10);
                        }
                    }
                    else
                    {
                        //qDebug()<<" zzp recv time out" << QDateTime::currentDateTime().toMSecsSinceEpoch() - msec <<
                        m_SerialObj->readAll();
                        m_SerialObj->flush();
                        m_AckAttempts++;
                    }
                    //qDebug()<<" zzp recv thread: " << m_RecvData.toHex() << "len : " << m_RecvData.length() << "id " << QThread::currentThreadId();
                    if(m_AckAttempts >= 3)
                    {
                        if(currData.cmdType == NE6882_CMD::CMD_SET)
                        {
                            NE6882Msg data;
                            data.msgType = DEF_MSGTYPE_RESULT;
                            data.cmdType = NE6882_CMD::CMD_SET;
                            data.testState = NE6882_STATE::STATE_UNKNOWN;
                            if(m_Func != nullptr)
                            {
                                m_Func(data, m_User);
                            }
                        }
                        m_AckAttempts = 0;
                        m_CmdList.pop_front();
                        continue;
                    }
                    if(m_RecvData.size() < nRecvLen)
                    {
                        goto _RESEND;
                    }
                    m_MutexRecv.lock();
                    int nRet = ParseRecvCmd(currData);
                    m_MutexRecv.unlock();
                    if(nRet != 0)
                    {
                        m_AckAttempts++;
                        goto _RESEND;
                    }
                    if(currData.cmdType == NE6882_CMD::CMD_START)
                    {
                        m_RecvData.clear();
                        m_RecvState = true;
                    }
                    else if(currData.cmdType == NE6882_CMD::CMD_STOP)
                    {
                        m_RecvData.clear();
                        m_RecvState = false;
                    }
                    m_AckAttempts = 0;
                    m_CmdList.pop_front();
                    msleep(30);
                    continue;
                }
            }
            msleep(50);
        }
        else
        {
            break;
        }
    }
}

int SerialThread::ParseSendCmd(const NE6882Msg &p_data, QByteArray *p_senddata, int &p_recvlen)
{
    p_senddata->append((char)0x49);
    p_senddata->append((char)0x00);
    p_senddata->append((char)0x01);
    switch(p_data.cmdType)
    {
        case NE6882_CMD::CMD_START:
        {
            p_senddata->append((char)0x07);
            p_senddata->append((char)0x00);
            p_senddata->append((char)0x01);
            p_recvlen = 11;
            break;
        }
        case NE6882_CMD::CMD_STOP:
        {
            p_senddata->append((char)0x07);
            p_senddata->append((char)0x00);
            p_senddata->append((char)0x00);
            p_recvlen = 11;
            break;
        }
        case NE6882_CMD::CMD_QUERY:
        {
            p_senddata->append((char)0x07);
            p_senddata->append((char)0x00);
            p_senddata->append((char)0x14);
            p_recvlen = 10;
            break;
        }
        case NE6882_CMD::CMD_SET:
        {
            p_senddata->clear();
            p_senddata->append((char)0x49);
            p_senddata->append((char)0xFF);
            p_senddata->append((char)0xFF);
            p_senddata->append((char)0x10);
            p_senddata->append((char)0x00);
            p_senddata->append((char)0x03);
            p_senddata->append((char)0x00);
            p_senddata->append((char)0x00);
            p_senddata->append((char)0x00);
            p_senddata->append((char)0x00);
            p_senddata->append((char)0x00);
            p_senddata->append((char)p_data.nFailStep);
            p_senddata->append((char)0x00);
            p_senddata->append((char)0x00);
            p_senddata->append((char)0x01);
            p_recvlen = 11;
            break;
        }
        case NE6882_CMD::CMD_SET_IR:
        {
            p_senddata->append((char)0x22);
            p_senddata->append((char)0x00);
            p_senddata->append((char)0x03);
            p_senddata->append((char)0x63);
            p_senddata->append((char)0x01);
            p_senddata->append(p_data.nStepNo);
            p_senddata->append((char)0x03);
            quint16 volt = p_data.fVolt * 1000;
            p_senddata->append((quint8)((volt >> 8) & 0xFF));
            p_senddata->append((quint8)(volt & 0xFF));
            SetCmdData(p_senddata, p_data.fIrHigh, 2);
            SetCmdData(p_senddata, p_data.fIrLow, 2);
            p_senddata->append((char)0x40);
            p_senddata->append((char)0x01);
            p_senddata->append((char)0x40);
            p_senddata->append((char)0x01);
            p_senddata->append((char)0x00);
            p_senddata->append((char)0x00);
            quint16 nTime = p_data.fTestTime * 10;
            p_senddata->append(0x40 + (quint8)((nTime >> 8) & 0x0F));
            p_senddata->append((quint8)(nTime & 0xFF));
            p_senddata->append(p_data.nConnectMode);
            p_senddata->append((char)0xC0);
            p_senddata->append((char)0x00);
            quint16 nComp = p_data.fComp;
            p_senddata->append((char)0x00);
            p_senddata->append((quint8)(nComp >> 8) & 0xFF);
            p_senddata->append((quint8)(nComp & 0xFF));
            p_senddata->append((char)0x01);
            p_recvlen = 11;
            break;
        }
        case NE6882_CMD::CMD_SET_PEQ:
        {
            p_senddata->append((char)0x18);
            p_senddata->append((char)0x00);
            p_senddata->append((char)0x03);
            p_senddata->append((char)0x63);
            p_senddata->append((char)0x01);
            p_senddata->append(p_data.nStepNo);
            p_senddata->append((char)0x09);
            quint16 nCurrent = p_data.fCurrent * 100;
            p_senddata->append((quint8)(nCurrent >> 8) & 0xFF);
            p_senddata->append((quint8)(nCurrent & 0xFF));
            quint16 nIrHigh = p_data.fIrHigh * 10;
            p_senddata->append((quint8)(nIrHigh >> 8) & 0xFF);
            p_senddata->append((quint8)(nIrHigh & 0xFF));
            quint16 nIrLow = p_data.fIrLow * 10;
            p_senddata->append((quint8)(nIrLow >> 8) & 0xFF);
            p_senddata->append((quint8)(nIrLow & 0xFF));
            quint16 nTime = p_data.fTestTime * 10;
            p_senddata->append(0x40 + (quint8)((nTime >> 8) & 0x0F));
            p_senddata->append((quint8)(nTime & 0xFF));
            p_senddata->append(p_data.nConnectMode);
            quint16 nComp = p_data.fComp * 10;
            p_senddata->append((quint8)((nComp >> 8) & 0x0F));
            p_senddata->append((quint8)(nComp & 0xFF));
            p_senddata->append((char)0x01);
            p_senddata->append((char)0x01);
            p_recvlen = 11;
            break;
        }
        case NE6882_CMD::CMD_COMPENSATION:
        {
            p_senddata->append((char)0x07);
            p_senddata->append((char)0x00);
            p_senddata->append((char)0x06);
            p_recvlen = 11;
            break;
        }
        case NE6882_CMD::CMD_CALIBRATE:
        {
            p_senddata->append((char)0x11);
            p_senddata->append((char)0x00);
            p_senddata->append((char)0x1E);
            p_senddata->append((char)0x00);
            p_senddata->append((char)0x09);
            p_senddata->append((char)0x01);
            p_senddata->append((char)0x00);
            p_recvlen = 11;
            break;
        }
        case NE6882_CMD::CMD_OFFSET:
        {
            p_senddata->append((char)0x0B);
            p_senddata->append((char)0x00);
            p_senddata->append((char)0x1F);
            p_senddata->append((char)0x00);
            p_senddata->append((char)0x09);
            p_senddata->append((char)0x01);
            p_senddata->append((char)0x00);
            p_senddata->append((char)0x00);
            p_senddata->append((char)0x00);
            p_senddata->append((char)0x00);
            p_senddata->append((char)0x00);
            p_senddata->append((char)0x00);
            p_senddata->append((char)0x00);
            p_recvlen = 11;
            break;
        }
        case NE6882_CMD::CMD_VERSION:
        {
            p_senddata->append((char)0x07);
            p_senddata->append((char)0x00);
            p_senddata->append((char)0x21);
            p_recvlen = 14;
            break;
        }
        case NE6882_CMD::CMD_REQUEST:
        {
            p_senddata->append((char)0x08);
            p_senddata->append((char)0x00);
            p_senddata->append((char)0x16);
            p_senddata->append((char)0x01);
            p_recvlen = 0;
            break;
        }
        default:
        {
            p_recvlen = 0;
            return 1;
        }
    }
    p_senddata->append((char)0x44);
    p_senddata->append(CheckSum(*p_senddata));
    return 0;
}

int SerialThread::ParseRecvCmd(const NE6882Msg &p_cmd)
{
    int len = 0;
    QByteArray head;
    NE6882Msg data;
    head.append(0x49);
    head.append(0x80);
    head.append(0x01);
    if(m_RecvData.length() < 10)
         return 1;
    if(!m_RecvData.contains(head))
        return 1;
    m_RecvData = m_RecvData.mid(m_RecvData.indexOf(head));
    len = m_RecvData.at(3);
    if(m_RecvData.length() < len + 1)
        return 1;
    //if(CheckSum(p_data) != (quint8)p_data.at(p_data.size() - 2))
    //    return 1;
    if(m_RecvData.at(5) == 0x16)
    {
        m_RecvData = m_RecvData.right(m_RecvData.length() - len - 1);
        m_MutexSend.lock();
        sendACK();
        m_MutexSend.unlock();
        return ParseRecvCmd(p_cmd);
    }
    switch(p_cmd.cmdType)
    {
        case NE6882_CMD::CMD_SET:
        {
            data.msgType = DEF_MSGTYPE_RESULT;
            data.cmdType = NE6882_CMD::CMD_SET;
            data.testState = NE6882_STATE::STATE_MAX;
            m_RecvData = m_RecvData.right(m_RecvData.length() - len - 1);
            if(m_Func != nullptr)
            {
                m_Func(data, m_User);
            }
            break;
        }
        case NE6882_CMD::CMD_START:
        case NE6882_CMD::CMD_STOP:
        case NE6882_CMD::CMD_SET_IR:
        case NE6882_CMD::CMD_SET_PEQ:
        {
            len = 0x0A;
            int ret = 0;
            if(m_RecvData.at(6) == 0x01)
                ret = 0;
            else
                ret = 1;
            if(p_cmd.testState == NE6882_STATE::STATE_MAX)
            {
                data.msgType = DEF_MSGTYPE_RESULT;
                data.cmdType = p_cmd.cmdType;
                data.testState = NE6882_STATE::STATE_MAX;
                if(m_Func != nullptr)
                {
                    m_Func(data, m_User);
                }
            }
            m_RecvData = m_RecvData.right(m_RecvData.length() - len - 1);
            return ret;
        }
        case NE6882_CMD::CMD_REQUEST:
        {
            len = m_RecvData.at(3);
            if(m_RecvData.at(5) == 0x07)
            {
                data.nStepNo = m_RecvData.at(7);
                switch((m_RecvData.at(9) >> 4) & 0x0F)
                {
                    case 2:
                        data.groupState = NE6882_STATE::STATE_GROUP_TESTING;
                        break;
                    case 3:
                        data.groupState = NE6882_STATE::STATE_GROUP_TESTOVER;
                        break;
                    case 5:
                        data.groupState = NE6882_STATE::STATE_GROUP_STEP;
                        break;
                    default:
                        data.groupState = NE6882_STATE::STATE_GROUP_IDLE;
                        break;
                }
                switch(m_RecvData.at(9) & 0x0F)
                {
                    case 4:
                        data.testState = NE6882_STATE::STATE_STEP_TESTING;
                        break;
                    case 5:
                        data.testState = NE6882_STATE::STATE_STEP_OK;
                        break;
                    case 6:
                        data.testState = NE6882_STATE::STATE_STEP_NG;
                        break;
                    case 7:
                        data.testState = NE6882_STATE::STATE_STEP_NULL;
                        break;
                    default:
                        data.testState = NE6882_STATE::STATE_STEP_ERROR;
                        break;
                }
                if(m_RecvData.at(8) == 0x03)
                {
                    data.cmdType = NE6882_CMD::CMD_GET_IR;
                    quint16 volt = (quint8)m_RecvData.at(10) * 256 + (quint8)m_RecvData.at(11);
                    data.fVolt = volt / 1000.0;
                    if(((m_RecvData.at(12) & 0x10) >> 4) == 1)
                        data.nIrUnit = 3;
                    else
                        data.nIrUnit = 2;
                    data.fTestVal = ((m_RecvData.at(12) & 0x0F) * 4096 + (quint8)m_RecvData.at(13) * 256 + (quint8)m_RecvData.at(14)) / qPow(10, ((m_RecvData.at(12) >> 5) & 0x07));
                    data.fTestTime = ((m_RecvData.at(21) & 0x3F) * 256 + (quint8)m_RecvData.at(22)) / qPow(10, ((m_RecvData.at(21) >> 6) & 0x03));

                }
                else if(m_RecvData.at(8) == 0x09)
                {
                    data.nIrUnit = 0;

                    data.cmdType = NE6882_CMD::CMD_GET_PEQ;
                    data.fCurrent = ((m_RecvData.at(10) & 0x3F) * 256 + (quint8)m_RecvData.at(11)) / qPow(10, ((m_RecvData.at(10) >> 6) & 0x03));
                    data.fTestVal = ((m_RecvData.at(12) & 0x3F) * 256 + (quint8)m_RecvData.at(13)) / qPow(10, ((m_RecvData.at(12) >> 6) & 0x03));
                    data.fTestTime = ((m_RecvData.at(14) & 0x3F) * 256 + (quint8)m_RecvData.at(15)) / qPow(10, ((m_RecvData.at(14) >> 6) & 0x03));
                }
                m_RecvData = m_RecvData.right(m_RecvData.length() - len - 1);
                if(m_Func != nullptr)
                {
                    m_Func(data, m_User);
                }
                return 0;
            }
            else
                return 1;
        }
    }
#if 0
    if(!m_RecvData.contains(head))
        return 1;
    m_RecvData = m_RecvData.mid(m_RecvData.indexOf(head));
    if(m_RecvData.length() < len - 4)
        return 1;

    if(p_cmd)


    switch(p_data.at(5))
    {
        case 0x02:
        {
            if(p_data.at(6) == 0x01)
                return 0;
            else
                return 2;
        }
        case 0x07:
        {
            data.msgType = DEF_MSGTYPE_RESULT;
            quint8 status = p_data.at(9);
            data.groupState = (NE6882_STATE)(status & 0xF0);
            data.groupState = (NE6882_STATE)(status & 0x0F);
            data.nStepNo = p_data.at(7);
            if(p_data.at(8) == 0x03)
            {
                data.cmdType = NE6882_CMD::CMD_GET_IR;
                quint16 volt = p_data.at(10) * 256 + p_data.at(11);
                data.fVolt = volt / 1000.0;
                if(((p_data.at(12) & 0x10) >> 4) == 1)
                    data.nIrUnit = 3;
                else
                    data.nIrUnit = 2;
                data.fTestVal = ((p_data.at(12) & 0x0F) * 4096 + p_data.at(13) * 256 + p_data.at(14)) / qPow(10, ((p_data.at(12) >> 5) & 0x07));
                data.fTestTime = ((p_data.at(21) & 0x3F) * 256 + p_data.at(22)) / qPow(10, ((p_data.at(21) >> 6) & 0x03));

            }
            else if(p_data.at(8) == 0x09)
            {
                data.nIrUnit = 0;
                data.cmdType = NE6882_CMD::CMD_GET_PEQ;
                data.fCurrent = ((p_data.at(10) & 0x3F) * 256 + p_data.at(11)) / qPow(10, ((p_data.at(10) >> 6) & 0x03));
                data.fTestVal = ((p_data.at(12) & 0x3F) * 256 + p_data.at(13)) / qPow(10, ((p_data.at(12) >> 6) & 0x03));
                data.fTestTime = ((p_data.at(14) & 0x3F) * 256 + p_data.at(15)) / qPow(10, ((p_data.at(14) >> 6) & 0x03));
            }
            else
                return 1;
            break;
        }
        case 0x14:
        {
            data.cmdType = NE6882_CMD::CMD_QUERY;
            data.msgType = DEF_MSGTYPE_RESULT;
            quint8 state = p_data.at(6);
            data.groupState = GetGroupState((state >> 4) & 0x0F);
            data.testState = GetGroupState(state & 0x0F);
            break;
        }
        case 0x16:
        {
            data.cmdType = NE6882_CMD::CMD_REQUEST;
            data.msgType = DEF_MSGTYPE_RESULT;
            return 2;
        }
        case 0x21:
        {
            data.cmdType = NE6882_CMD::CMD_VERSION;
            data.msgType = DEF_MSGTYPE_RESULT;
            memset(data.strVersion, 0, 8);
            for(int i = 0; i < 6; i++)
            {
                data.strVersion[i] = p_data.at(i + 6);
            }
            break;
        }
        default:
            return 1;
    }
    if(m_Func != nullptr)
    {
        m_Func(data, m_User);
    }
#endif
    return 0;
}

quint8 SerialThread::CheckSum(const QByteArray &p_data)
{
    quint16 sum = 0;
    for(int i = 0; i < p_data.length(); i++)
    {
        sum += (quint8)p_data.at(i);
    }
    return (quint8)(sum & 0xFF);
}

void SerialThread::SetCmdData(QByteArray *p_data, const float p_val, const int num)
{
    int zoom = qPow(10, num);
    float fVal = p_val * zoom;
    int nVal = p_val;
    int nNoDecimalVal = nVal * zoom;
    int decimal = fVal - nNoDecimalVal;
    if(decimal == 0)
    {
        p_data->append((char)0x00);
        p_data->append((quint8)((nVal >> 8) & 0xFF));
        p_data->append((quint8)(nVal & 0xFF));
    }
    else if(decimal % 10 != 0)
    {
        p_data->append((quint8)(((nNoDecimalVal >> 16) & 0x0F) + (0x02 << 4)));
        p_data->append((quint8)((nNoDecimalVal >> 8) & 0xFF));
        p_data->append((quint8)(nNoDecimalVal & 0xFF));
    }
    else
    {
        p_data->append((quint8)((((nNoDecimalVal / 10) >> 16) & 0x0F) + (0x01 << 4)));
        p_data->append((quint8)(((nNoDecimalVal / 10) >> 8) & 0xFF));
        p_data->append((quint8)((nNoDecimalVal / 10)& 0xFF));
    }
}

NE6882_STATE SerialThread::GetGroupState(int p_state)
{
    switch(p_state)
    {
        case 0:
            return NE6882_STATE::STATE_GROUP_IDLE;
        case 2:
            return NE6882_STATE::STATE_GROUP_TESTING;
        case 3:
            return NE6882_STATE::STATE_GROUP_TESTOVER;
        case 5:
            return NE6882_STATE::STATE_GROUP_STEP;
        case 6:
            return NE6882_STATE::STATE_GROUP_SELFCHECK;
        default:
            return NE6882_STATE::STATE_GROUP_IDLE;
    }
}

NE6882_STATE SerialThread::GetStepState(int p_state)
{
    switch(p_state)
    {
        case 4:
            return NE6882_STATE::STATE_STEP_TESTING;
        case 5:
            return NE6882_STATE::STATE_STEP_OK;
        case 6:
            return NE6882_STATE::STATE_STEP_NG;
        case 7:
            return NE6882_STATE::STATE_STEP_NULL;
        case 8:
            return NE6882_STATE::STATE_STEP_ERROR;
        default:
            return NE6882_STATE::STATE_STEP_NULL;
    }
}

void SerialThread::sendACK()
{
    QByteArray result;
    result.append(0x49);
    result.append((char)0x00);
    result.append(0x01);
    result.append(0x08);
    result.append((char)0x00);
    result.append(0x16);
    result.append(0x01);
    result.append(0x44);
    result.append(0xAD);
    m_SerialObj->write(result);
    m_SerialObj->waitForBytesWritten(50);
}

int SerialThread::getFirstTimeout()
{
    if(m_FirstCmd)
    {
        m_FirstCmd = false;
        return m_ReadTimeout + 700;
    }
    return m_ReadTimeout;
}


Ne6882serial::Ne6882serial() :
    m_SerialObj(nullptr)
{

}

Ne6882serial::~Ne6882serial()
{
    CloseNe6882Serial();
}

int Ne6882serial::InitNe6882Serial(const QString p_port, const int p_baud, const int p_timeout, requsetCallback p_callback, const unsigned int p_user)
{
    m_SerialObj = new SerialThread();
    //m_pThreadObj = new QThread();
    //m_SerialObj->moveToThread(m_pThreadObj);
    return m_SerialObj->InitSerialThread(p_port, p_baud, p_timeout, p_callback, p_user);
}

void Ne6882serial::StartRun()
{
    //if(m_pThreadObj == nullptr)
    //    return;
    if(m_SerialObj == nullptr)
        return;
    m_SerialObj->start();
    //m_pThreadObj->start();
}

void Ne6882serial::StopRun()
{
    //if(m_pThreadObj == nullptr)
    //    return;
    if(m_SerialObj == nullptr)
        return;
    m_SerialObj->quit();
    m_SerialObj->wait();
}

int Ne6882serial::SendCmd(const NE6882Msg p_data)
{
    if(m_SerialObj == nullptr)
        return 1;

    m_SerialObj->SendCmd(p_data);
    return 0;
}

void Ne6882serial::CloseNe6882Serial()
{
//    if(m_pThreadObj != nullptr)
//    {
//        m_pThreadObj->quit();
//        m_pThreadObj->wait();
//        delete m_pThreadObj;
//        m_pThreadObj = nullptr;
//    }
    if(m_SerialObj != nullptr)
    {
        m_SerialObj->SetThreadRun(false);
        m_SerialObj->uninitSerial();
        m_SerialObj->quit();
        m_SerialObj->wait();
        delete m_SerialObj;
        m_SerialObj = nullptr;
    }

}
