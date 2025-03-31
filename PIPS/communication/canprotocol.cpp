#include "canprotocol.h"
#include <QThread>
#include <QCanBusDevice>
#include <QCanBus>
extern "C" {
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/ioctl.h>
#include <net/if.h>
}

//各个命令帧数
#define DEF_HARMONICS_MAX 39
#define DEF_SYSTEM_MAX 3
#define DEF_M1SET_MAX 7
#define DEF_M2SET_MAX 10
#define DEF_M3SET_MAX 7
#define DEF_M4SET_MAX 10
#define DEF_M5SET_MAX 7
#define DEF_READ_MAX 16


CanProtocol::CanProtocol()
{
    m_Socket = 0;
    m_Can = "";
    //m_CanDevice = nullptr;
}

int CanProtocol::initCan(const QString &p_can, const int p_rate)
{
    if(p_can.length() <= 0 || p_rate < 0)
        return -1;
    struct sockaddr_can addr;
    m_Can = p_can;
    char downStr[32] = {0};
    char rateStr[64] = {0};
    char upStr[32] = {0};
    sprintf(downStr, "ip link set %s down", p_can.toStdString().c_str());
    sprintf(rateStr, "ip link set can2 type can bitrate %d", p_rate);
    sprintf(upStr, "ip link set %s up", p_can.toStdString().c_str());
    system(downStr);
    system(rateStr);
    system(upStr);
    m_Socket = ::socket(PF_CAN, SOCK_RAW, CAN_RAW);
    struct ifreq ifr;
    strcpy(ifr.ifr_name, p_can.toStdString().c_str());
    //fcntl(socket, F_SETFL, ReadMode);
    fcntl(m_Socket, F_SETFL, FNDELAY);
    ioctl(m_Socket, SIOCGIFINDEX, &ifr);
    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;
    return bind(m_Socket, (struct sockaddr*)&addr, sizeof(addr));
}

void CanProtocol::uninitCan()
{
    if(m_Socket != 0)
        ::close(m_Socket);
    m_Socket = 0;
    if(m_Can.length() > 0)
    {
        char downStr[32] = {0};
        sprintf(downStr, "ip link set %s down", m_Can.toStdString().c_str());
        system(downStr);
    }
}

int CanProtocol::readCan(QList<struct can_frame> &p_canList)
{
    long nbytes;
    int readCnt = 0;
    bool hasFirst = false;
    struct can_frame frame;
    QVector<struct can_frame> canVect;
    memset(&frame, 0, sizeof(struct can_frame));
    while(1)
    {
        if(readCnt > 20 && !hasFirst)
            return -1;
        //system("date +%Y-%m-%d' '%H:%M:%S.%N | cut -b 1-23");
        nbytes = read(m_Socket, &frame, sizeof(frame));
        //system("date +%Y-%m-%d' '%H:%M:%S.%N | cut -b 1-23");
        if(nbytes > 0)
        {
            CanID id;
            id.ID = frame.can_id;
            if(id.index != 0)
            {
                readCnt++;
                memset(&frame, 0, sizeof(struct can_frame));
                QThread::msleep(2);
                continue;
            }
            else
                hasFirst = true;
            canVect.append(frame);
            if(canVect.count() >= DEF_READ_MAX)
                break;
            memset(&frame, 0, sizeof(struct can_frame));
            readCnt++;
            QThread::msleep(2);
            continue;
        }
        else
        {
            readCnt++;
            QThread::msleep(2);
            continue;
        }
    }
    int listIdx[DEF_READ_MAX] = {0};
    for(int i = 0; i < canVect.count(); i++)
    {
        CanID id;
        id.ID = canVect.at(i).can_id;
        listIdx[id.index] = i;
    }
    for(int i = 0; i < canVect.count(); i++)
    {
        p_canList.append(canVect.at(listIdx[i]));
    }
    return 0;
}

int CanProtocol::writeCan(const CanSendData &p_data)
{
    switch(p_data.Cmd)
    {
    case ENM_CMD_START:
    case ENM_CMD_STOP:
    {
        struct can_frame frame;
        CanID canID;
        canID.index = 0;
        canID.cmd = 0x01;
        canID.type = 0;
        canID.addr = 0x01;
        memset(&frame, 0, sizeof(struct can_frame));
        frame.can_id = (canID.ID & CAN_EFF_MASK) | CAN_EFF_FLAG;
        frame.can_dlc = 8;
        frame.data[0] = p_data.Cmd == ENM_CMD_START ? 0x01 : 0;
        frame.data[1] = 0;
        frame.data[2] = 0;
        frame.data[3] = 0;
        frame.data[4] = 0;
        frame.data[5] = 0;
        frame.data[6] = 0;
        frame.data[7] = 0;
        write(m_Socket, &frame, sizeof(frame));
    }
        break;
    case ENM_CMD_SET:
        {
            switch(p_data.TestMode)
            {
            case ENM_TESTMODE_GENERAL:
            {
                const CanDataType temp = p_data.TestData.at(0);
                unsigned int k = 0;
                while(k < DEF_M1SET_MAX)
                {
                    struct can_frame frame;
                    CanID canID;
                    FloatValue fVal[12];
                    memset(&frame, 0, sizeof(struct can_frame));
                    canID.index = (k + 1);
                    canID.cmd = 0x80 | p_data.OutputMode;
                    if(k == 0)
                        canID.type = 0x01;
                    else if(k == DEF_M1SET_MAX - 1)
                        canID.type = 0x03;
                    else
                        canID.type = 0x02;
                    canID.addr = 0x01;
                    frame.can_id = (canID.ID & CAN_EFF_MASK) | CAN_EFF_FLAG;
                    frame.can_dlc = 8;
                    for(int m = 0; m < 12; m++)
                    {
                        fVal[m].fValue = temp.fData[m];
                    }
                    /*
                    fVal[0].fValue = temp.M1_fVoltage1;
                    fVal[1].fValue = temp.M1_fVoltage2;
                    fVal[2].fValue = temp.M1_fVoltage3;
                    fVal[3].fValue = temp.M1_fFrequency1;
                    fVal[4].fValue = temp.M1_fFrequency2;
                    fVal[5].fValue = temp.M1_fFrequency3;
                    fVal[6].fValue = temp.M1_fAngles1;
                    fVal[7].fValue = temp.M1_fAngles2;
                    fVal[8].fValue = temp.M1_fAngles3;
                    fVal[9].fValue = temp.M1_fStartTime1;
                    fVal[10].fValue = temp.M1_fStartTime2;
                    fVal[11].fValue = temp.M1_fStartTime3;
                    */
                    if(k == 0)
                    {
                        frame.data[0] = temp.M1_nVoltageLevel;
                        frame.data[1] = temp.M1_nWaveForm1;
                        frame.data[2] = temp.M1_nWaveForm2;
                        frame.data[3] = temp.M1_nWaveForm3;
                        frame.data[4] = temp.M1_nEnble1;
                        frame.data[5] = temp.M1_nEnble2;
                        frame.data[6] = temp.M1_nEnble3;
                        frame.data[7] = 0;
                    }
                    else
                    {
                        frame.data[0] = fVal[2 * k].byte1;
                        frame.data[1] = fVal[2 * k].byte2;
                        frame.data[2] = fVal[2 * k].byte3;
                        frame.data[3] = fVal[2 * k].byte4;
                        frame.data[4] = fVal[2 * k + 1].byte1;
                        frame.data[5] = fVal[2 * k + 1].byte2;
                        frame.data[6] = fVal[2 * k + 1].byte3;
                        frame.data[7] = fVal[2 * k + 1].byte4;
                    }
                    write(m_Socket, &frame, sizeof(frame));
                    k++;
                    QThread::msleep(1);
                }
            }
                break;
            case ENM_TESTMODE_STEPLADDER:
            {
                const CanDataType temp = p_data.TestData.at(0);
                unsigned int k = 0;
                while(k < DEF_M2SET_MAX)
                {
                    struct can_frame frame;
                    CanID canID;
                    FloatValue fVal[18];
                    memset(&frame, 0, sizeof(struct can_frame));
                    canID.index = (k + 1);
                    canID.cmd = 0x90 | p_data.OutputMode;
                    if(k == 0)
                        canID.type = 0x01;
                    else if(k == DEF_M2SET_MAX - 1)
                        canID.type = 0x03;
                    else
                        canID.type = 0x02;
                    canID.addr = 0x01;
                    frame.can_id = (canID.ID & CAN_EFF_MASK) | CAN_EFF_FLAG;
                    frame.can_dlc = 8;
                    for(int m = 0; m < 18; m++)
                    {
                        fVal[m].fValue = temp.fData[m];
                    }
                    /*
                    fVal[0].fValue = temp.M2_fStartVoltage1;
                    fVal[1].fValue = temp.M2_fStartVoltage2;
                    fVal[2].fValue = temp.M2_fStartVoltage3;
                    fVal[3].fValue = temp.M2_fStepVoltage1;
                    fVal[4].fValue = temp.M2_fStepVoltage2;
                    fVal[5].fValue = temp.M2_fStepVoltage3;
                    fVal[6].fValue = temp.M2_fStartFrequency1;
                    fVal[7].fValue = temp.M2_fStartFrequency2;
                    fVal[8].fValue = temp.M2_fStartFrequency3;
                    fVal[9].fValue = temp.M2_fStepFrequency1;
                    fVal[10].fValue = temp.M2_fStepFrequency2;
                    fVal[11].fValue = temp.M2_fStepFrequency3;
                    fVal[12].fValue = temp.M2_fAngles1;
                    fVal[13].fValue = temp.M2_fAngles2;
                    fVal[14].fValue = temp.M2_fAngles3;
                    fVal[15].fValue = temp.M2_fTime1;
                    fVal[16].fValue = temp.M2_fTime2;
                    fVal[17].fValue = temp.M2_fTime3;
                    */
                    if(k == 0)
                    {
                        frame.data[0] = temp.M2_nWaveForm1;
                        frame.data[1] = temp.M2_nWaveForm2;
                        frame.data[2] = temp.M2_nWaveForm3;
                        frame.data[3] = temp.M2_nStepCount1;
                        frame.data[4] = temp.M2_nStepCount2;
                        frame.data[5] = temp.M2_nStepCount3;
                        frame.data[6] = 0;
                        frame.data[7] = 0;
                    }
                    else
                    {
                        frame.data[0] = fVal[2 * k].byte1;
                        frame.data[1] = fVal[2 * k].byte2;
                        frame.data[2] = fVal[2 * k].byte3;
                        frame.data[3] = fVal[2 * k].byte4;
                        frame.data[4] = fVal[2 * k + 1].byte1;
                        frame.data[5] = fVal[2 * k + 1].byte2;
                        frame.data[6] = fVal[2 * k + 1].byte3;
                        frame.data[7] = fVal[2 * k + 1].byte4;
                    }
                    write(m_Socket, &frame, sizeof(frame));
                    k++;
                    QThread::msleep(1);
                }
            }
                break;
            case ENM_TESTMODE_STEP:
            {
                unsigned int i = 0;
                foreach(const CanDataType temp, p_data.TestData)
                {
                    unsigned int k = 0;
                    while(k < DEF_M3SET_MAX)
                    {
                        struct can_frame frame;
                        CanID canID;
                        IntValue iVal;
                        FloatValue fVal[12];
                        memset(&frame, 0, sizeof(struct can_frame));
                        canID.index = i * DEF_M3SET_MAX + (k + 1);
                        canID.cmd = 0xA0 | p_data.OutputMode;
                        if(i == 0 && k == 0)
                            canID.type = 0x01;
                        else if(i == p_data.TestData.count() - 1 && k == DEF_M3SET_MAX - 1)
                            canID.type = 0x03;
                        else
                            canID.type = 0x02;
                        canID.addr = 0x01;
                        frame.can_id = (canID.ID & CAN_EFF_MASK) | CAN_EFF_FLAG;
                        frame.can_dlc = 8;
                        for(int m = 0; m < 12; m++)
                        {
                            fVal[m].fValue = temp.fData[m];
                        }
                        iVal.nValue = temp.M3_nCycle1;
                        if(k == 0)
                        {
                            frame.data[0] = temp.M3_nWaveForm1;
                            frame.data[1] = temp.M3_nWaveForm2;
                            frame.data[2] = temp.M3_nWaveForm3;
                            frame.data[3] = iVal.byte1;
                            frame.data[4] = iVal.byte2;
                            frame.data[5] = iVal.byte3;
                            frame.data[6] = iVal.byte4;
                            frame.data[7] = 0;
                        }
                        else
                        {
                            frame.data[0] = fVal[2 * k - 2].byte1;
                            frame.data[1] = fVal[2 * k - 2].byte2;
                            frame.data[2] = fVal[2 * k - 2].byte3;
                            frame.data[3] = fVal[2 * k - 2].byte4;
                            frame.data[4] = fVal[2 * k - 1].byte1;
                            frame.data[5] = fVal[2 * k - 1].byte2;
                            frame.data[6] = fVal[2 * k - 1].byte3;
                            frame.data[7] = fVal[2 * k - 1].byte4;
                        }
                        write(m_Socket, &frame, sizeof(frame));
                        k++;
                        QThread::msleep(1);
                    }
                    i++;
                }
            }
                break;
            case ENM_TESTMODE_GRADIENT:
            {
                unsigned int i = 0;
                foreach(const CanDataType temp, p_data.TestData)
                {
                    unsigned int k = 0;
                    while(k < DEF_M4SET_MAX)
                    {
                        struct can_frame frame;
                        CanID canID;
                        IntValue iVal;
                        FloatValue fVal[18];
                        memset(&frame, 0, sizeof(struct can_frame));
                        canID.index = i * DEF_M4SET_MAX + (k + 1);
                        canID.cmd = 0xB0 | p_data.OutputMode;
                        if(i == 0 && k == 0)
                            canID.type = 0x01;
                        else if(i == p_data.TestData.count() - 1 && k == DEF_M4SET_MAX - 1)
                            canID.type = 0x03;
                        else
                            canID.type = 0x02;
                        canID.addr = 0x01;
                        frame.can_id = (canID.ID & CAN_EFF_MASK) | CAN_EFF_FLAG;
                        frame.can_dlc = 8;
                        for(int m = 0; m < 18; m++)
                        {
                            fVal[m].fValue = temp.fData[m];
                        }
                        iVal.nValue = temp.M4_nCycle1;
                        if(k == 0)
                        {
                            frame.data[0] = temp.M4_nWaveForm1;
                            frame.data[1] = temp.M4_nWaveForm2;
                            frame.data[2] = temp.M4_nWaveForm3;
                            frame.data[3] = iVal.byte1;
                            frame.data[4] = iVal.byte2;
                            frame.data[5] = iVal.byte3;
                            frame.data[6] = iVal.byte4;
                            frame.data[7] = 0;
                        }
                        else
                        {
                            frame.data[0] = fVal[2 * k - 2].byte1;
                            frame.data[1] = fVal[2 * k - 2].byte2;
                            frame.data[2] = fVal[2 * k - 2].byte3;
                            frame.data[3] = fVal[2 * k - 2].byte4;
                            frame.data[4] = fVal[2 * k - 1].byte1;
                            frame.data[5] = fVal[2 * k - 1].byte2;
                            frame.data[6] = fVal[2 * k - 1].byte3;
                            frame.data[7] = fVal[2 * k - 1].byte4;
                        }
                        write(m_Socket, &frame, sizeof(frame));
                        k++;
                        QThread::msleep(1);
                    }
                    i++;
                }
            }
                break;
            case ENM_TESTMODE_THROUGH:
            {
                unsigned int i = 0;
                foreach(const CanDataType temp, p_data.TestData)
                {
                    unsigned int k = 0;
                    while(k < DEF_M5SET_MAX)
                    {
                        struct can_frame frame;
                        CanID canID;
                        IntValue iVal;
                        FloatValue fVal[11];
                        memset(&frame, 0, sizeof(struct can_frame));
                        canID.index = i * DEF_M5SET_MAX + (k + 1);
                        canID.cmd = 0xC0 | p_data.OutputMode;
                        if(i == 0 && k == 0)
                            canID.type = 0x01;
                        else if(i == p_data.TestData.count() - 1 && k == DEF_M5SET_MAX - 1)
                            canID.type = 0x03;
                        else
                            canID.type = 0x02;
                        canID.addr = 0x01;
                        frame.can_id = (canID.ID & CAN_EFF_MASK) | CAN_EFF_FLAG;
                        frame.can_dlc = 8;
                        for(int m = 0; m < 11; m++)
                        {
                            fVal[m].fValue = temp.fData[m];
                        }
                        iVal.nValue = temp.M5_nCycle1;
                        if(k == 0)
                        {
                            frame.data[0] = temp.M5_nWaveForm1;
                            frame.data[1] = temp.M5_nWaveForm2;
                            frame.data[2] = temp.M5_nWaveForm3;
                            frame.data[3] = temp.M5_nDropPhase;
                            frame.data[4] = iVal.byte1;
                            frame.data[5] = iVal.byte2;
                            frame.data[6] = iVal.byte3;
                            frame.data[7] = iVal.byte4;
                        }
                        else
                        {
                            frame.data[0] = fVal[2 * k - 2].byte1;
                            frame.data[1] = fVal[2 * k - 2].byte2;
                            frame.data[2] = fVal[2 * k - 2].byte3;
                            frame.data[3] = fVal[2 * k - 2].byte4;
                            frame.data[4] = fVal[2 * k - 1].byte1;
                            frame.data[5] = fVal[2 * k - 1].byte2;
                            frame.data[6] = fVal[2 * k - 1].byte3;
                            frame.data[7] = fVal[2 * k - 1].byte4;
                        }
                        write(m_Socket, &frame, sizeof(frame));
                        k++;
                        QThread::msleep(1);
                    }
                    i++;
                }
            }
                break;
            case ENM_TESTMODE_SYSTEM:
            {
                const CanDataType temp = p_data.TestData.at(0);
                unsigned int k = 0;
                while(k < DEF_SYSTEM_MAX)
                {
                    struct can_frame frame;
                    CanID canID;
                    FloatValue fVal[5];
                    memset(&frame, 0, sizeof(struct can_frame));
                    canID.index = (k + 1);
                    canID.cmd = 0x02;
                    if(k == 0)
                        canID.type = 0x01;
                    else if(k == DEF_SYSTEM_MAX - 1)
                        canID.type = 0x03;
                    else
                        canID.type = 0x02;
                    canID.addr = 0x01;
                    frame.can_id = (canID.ID & CAN_EFF_MASK) | CAN_EFF_FLAG;
                    frame.can_dlc = 8;
                    fVal[0].fValue = temp.M6_fOvercurrentLimit;
                    fVal[1].fValue = temp.M6_fLineImpedance;
                    fVal[2].fValue = temp.M6_fShockMult;
                    fVal[3].fValue = temp.M6_fVoltageDrop;
                    fVal[4].fValue = temp.M6_fRetardTime;
                    if(k == 0)
                    {
                        frame.data[0] = temp.M6_nPhase;
                        frame.data[1] = temp.M6_nOCFold;
                        frame.data[2] = temp.M6_nAntiShock;
                        frame.data[3] = 0;
                        frame.data[4] = fVal[0].byte1;
                        frame.data[5] = fVal[0].byte2;
                        frame.data[6] = fVal[0].byte3;
                        frame.data[7] = fVal[0].byte4;
                    }
                    else
                    {
                        frame.data[0] = fVal[2 * k - 1].byte1;
                        frame.data[1] = fVal[2 * k - 1].byte2;
                        frame.data[2] = fVal[2 * k - 1].byte3;
                        frame.data[3] = fVal[2 * k - 1].byte4;
                        frame.data[4] = fVal[2 * k].byte1;
                        frame.data[5] = fVal[2 * k].byte2;
                        frame.data[6] = fVal[2 * k].byte3;
                        frame.data[7] = fVal[2 * k].byte4;
                    }
                    write(m_Socket, &frame, sizeof(frame));
                    k++;
                    QThread::msleep(1);
                }
            }
                break;
            }
            break;
        }
    case ENM_CMD_HARMONICSSET:
    {
        unsigned int i = 0;
        foreach(const HarmonicsGroupData temp, p_data.AllHarmonics)
        {
            unsigned int k = 0;
            while(k < DEF_HARMONICS_MAX)
            {
                struct can_frame frame;
                CanID canID;
                FloatValue fVal[2];
                memset(&frame, 0, sizeof(struct can_frame));
                canID.index = i * DEF_HARMONICS_MAX + (k + 1);
                canID.cmd = 0x40 | i;
                if(i == 0 && k == 0)
                    canID.type = 0x01;
                else if(i == p_data.AllHarmonics.count() - 1 && k == DEF_HARMONICS_MAX - 1)
                    canID.type = 0x03;
                else
                    canID.type = 0x02;
                canID.addr = 0x01;
                frame.can_id = (canID.ID & CAN_EFF_MASK) | CAN_EFF_FLAG;
                frame.can_dlc = 8;
                fVal[0].fValue = temp.Percent[k];
                fVal[1].fValue = temp.Angles[k];
                frame.data[0] = fVal[0].byte1;
                frame.data[1] = fVal[0].byte2;
                frame.data[2] = fVal[0].byte3;
                frame.data[3] = fVal[0].byte4;
                frame.data[4] = fVal[1].byte1;
                frame.data[5] = fVal[1].byte2;
                frame.data[6] = fVal[1].byte3;
                frame.data[7] = fVal[1].byte4;
                write(m_Socket, &frame, sizeof(frame));
                k++;
                QThread::msleep(1);
            }
            i++;
        }
    }
        break;
    case ENM_CMD_HARMONICSUPDATE:
    {
        const HarmonicsGroupData temp = p_data.AllHarmonics.at(0);
        unsigned int k = 0;
        while(k < DEF_HARMONICS_MAX)
        {
            struct can_frame frame;
            CanID canID;
            FloatValue fVal[2];
            memset(&frame, 0, sizeof(struct can_frame));
            canID.index = (k + 1);
            canID.cmd = 0x60 | k;
            if(k == 0)
                canID.type = 0x01;
            else if(k == DEF_HARMONICS_MAX - 1)
                canID.type = 0x03;
            else
                canID.type = 0x02;
            canID.addr = 0x01;
            frame.can_id = (canID.ID & CAN_EFF_MASK) | CAN_EFF_FLAG;
            frame.can_dlc = 8;
            fVal[0].fValue = temp.Percent[k];
            fVal[1].fValue = temp.Angles[k];
            frame.data[0] = fVal[0].byte1;
            frame.data[1] = fVal[0].byte2;
            frame.data[2] = fVal[0].byte3;
            frame.data[3] = fVal[0].byte4;
            frame.data[4] = fVal[1].byte1;
            frame.data[5] = fVal[1].byte2;
            frame.data[6] = fVal[1].byte3;
            frame.data[7] = fVal[1].byte4;
            write(m_Socket, &frame, sizeof(frame));
            k++;
            QThread::msleep(1);
        }
    }
        break;
    }
    return 0;
}
