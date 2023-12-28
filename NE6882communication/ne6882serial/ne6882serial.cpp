#include "ne6882serial.h"
#include <QtMath>
//#include <QDateTime>
#include <QDebug>

SerialThread::SerialThread() :
    m_ThreadRun(true),
    m_SerialObj(nullptr),
    m_Func(nullptr),
    m_User(0),
    m_ReadTimeout(500)
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
    return 0;
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
}

void SerialThread::SlotRecvData()
{
    if(m_SerialObj == nullptr)
        return;
    QByteArray readData = m_SerialObj->readAll();
    ParseRecvCmd(readData);
}

void SerialThread::run()
{
    while(1)
    {
        if(m_ThreadRun)
        {
            if(m_CmdList.size() > 0)
            {
                while(m_AckAttempts < 3)
                {
                    QByteArray sendData;
                    QByteArray recvData;
                    int nRecvLen;
                    int nRet = ParseSendCmd(m_CmdList.first(), &sendData, nRecvLen);
                    if(nRet != 0)
                    {
                        m_CmdList.pop_front();
                        m_AckAttempts = 0;
                        break;
                    }
                    else
                    {
                        int nCnt = 0;
                        int maxCnt = m_ReadTimeout / 10;
                        m_SerialObj->write(sendData);
                        //quint64 msec = QDateTime::currentDateTime().toMSecsSinceEpoch();
                        while(recvData.size() < nRecvLen)
                        {
                            recvData.append(m_SerialObj->readAll());
                            nCnt++;
                            if(nCnt > maxCnt)
                            {
                                m_AckAttempts++;
                                continue;
                            }
                            msleep(10);
                        }
                        int nRet = ParseRecvCmd(recvData);
                        if(nRet != 0)
                        {
                            if(nRet == 2)
                            {
                                QByteArray result;
                                result.append(0x49);
                                result.append((char)0x00);
                                result.append(0x01);
                                result.append(0x08);
                                result.append((char)0x00);
                                result.append(0x16);
                                result.append(0x44);
                                result.append(0xAD);
                                m_SerialObj->write(result);
                                m_AckAttempts = 0;
                                m_CmdList.pop_front();
                                break;
                            }
                            else
                            {
                                m_AckAttempts++;
                                continue;
                            }
                        }
                    }
                }
                if(m_AckAttempts >= 3)
                {
                    m_AckAttempts = 0;
                    m_CmdList.pop_front();
                }
            }
            msleep(50);
        }
        else
        {
            msleep(100);
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
            p_senddata->append((char)0x0F);
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
            p_senddata->append((char)0x00);
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
            p_senddata->append((char)0x00);
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

int SerialThread::ParseRecvCmd(const QByteArray &p_data)
{
    int sum;
    quint8 sumChk;
    for(int i = 0; i < p_data.size() - 1; i++)
    {
        sum += p_data.at(i);
    }
    sumChk = sum & 0xFF;
    if(sumChk != p_data.at(p_data.size() - 1))
        return 1;
    NE6882Msg data;
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
    return 0;
}

quint8 SerialThread::CheckSum(const QByteArray &p_data)
{
    quint16 sum;
    for(int i = 0; i < p_data.size(); i++)
    {
        sum += p_data.at(i);
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
    m_SerialObj->exit();
    //m_pThreadObj->quit();
    //m_pThreadObj->wait();
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

        delete m_SerialObj;
        m_SerialObj = nullptr;
    }

}
