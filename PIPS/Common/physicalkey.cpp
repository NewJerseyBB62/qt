#include "physicalkey.h"
extern "C" {
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <linux/ioctl.h>
#include <linux/gpio.h>
}
//G3C1 113  停止
//G3B5 109  启动
//G3A7 103  旋钮按下
//G3A6 102  旋钮左
//G3A5 101  旋钮右

#define DEF_GPIO_START  "109"
#define DEF_GPIO_STOP   "113"
#define DEF_GPIO_PRESS  "103"
#define DEF_GPIO_LEFT   "102"
#define DEF_GPIO_RIGHT  "101"

PhysicalKey::PhysicalKey(QObject *parent)
{
    m_ThreadStatus = true;
    m_ThreadStart = false;
    memset(m_FDList, 0, sizeof(m_FDList));
}

void PhysicalKey::initPhysicalKey()
{
    char start[64] = {0};
    char stop[64] = {0};
    char pressed[64] = {0};
    char left[64] = {0};
    char right[64] = {0};
    sprintf(start, "echo %s > /sys/class/gpio/export",
            DEF_GPIO_START);
    sprintf(stop, "echo %s > /sys/class/gpio/export",
            DEF_GPIO_STOP);
    sprintf(pressed, "echo %s > /sys/class/gpio/export",
            DEF_GPIO_PRESS);
    sprintf(left, "echo %s > /sys/class/gpio/export",
            DEF_GPIO_LEFT);
    sprintf(right, "echo %s > /sys/class/gpio/export",
            DEF_GPIO_RIGHT);
    system(start);
    system(stop);
    system(pressed);
    system(left);
    system(right);
    sprintf(start, "echo in > /sys/class/gpio/gpio%s/direction",
           DEF_GPIO_START);
    sprintf(stop, "echo in > /sys/class/gpio/gpio%s/direction",
           DEF_GPIO_STOP);
    sprintf(pressed, "echo in > /sys/class/gpio/gpio%s/direction",
           DEF_GPIO_PRESS);
    sprintf(left, "echo in > /sys/class/gpio/gpio%s/direction",
           DEF_GPIO_LEFT);
    sprintf(right, "echo in > /sys/class/gpio/gpio%s/direction",
           DEF_GPIO_RIGHT);
    system(start);
    system(stop);
    system(pressed);
    system(left);
    system(right);
    sprintf(start, "/sys/class/gpio/gpio%s/value",
           DEF_GPIO_START);
    sprintf(stop, "/sys/class/gpio/gpio%s/value",
           DEF_GPIO_STOP);
    sprintf(pressed, "/sys/class/gpio/gpio%s/value",
           DEF_GPIO_PRESS);
    sprintf(left, "/sys/class/gpio/gpio%s/value",
           DEF_GPIO_LEFT);
    sprintf(right, "/sys/class/gpio/gpio%s/value",
           DEF_GPIO_RIGHT);
    m_FDList[0] = open(start, O_RDWR);
    m_FDList[1] = open(stop, O_RDWR);
    m_FDList[2] = open(pressed, O_RDWR);
    m_FDList[3] = open(left, O_RDWR);
    m_FDList[4] = open(right, O_RDWR);
    m_ThreadStatus = true;
    this->start();
}

void PhysicalKey::startThread()
{
    m_ThreadStart = true;
}

void PhysicalKey::stopThread()
{

    m_ThreadStart = false;

}

void PhysicalKey::closeThread()
{
    char start[64] = {0};
    char stop[64] = {0};
    char pressed[64] = {0};
    char left[64] = {0};
    char right[64] = {0};
    m_ThreadStart = false;
    m_ThreadStatus = false;
    close(m_FDList[0]);
    close(m_FDList[1]);
    close(m_FDList[2]);
    close(m_FDList[3]);
    close(m_FDList[4]);
    sprintf(start, "echo %s > /sys/class/gpio/unexport",
           DEF_GPIO_START);
    sprintf(stop, "echo %s > /sys/class/gpio/unexport",
           DEF_GPIO_STOP);
    sprintf(pressed, "echo %s > /sys/class/gpio/unexport",
           DEF_GPIO_PRESS);
    sprintf(left, "echo %s > /sys/class/gpio/unexport",
           DEF_GPIO_LEFT);
    sprintf(right, "echo %s > /sys/class/gpio/unexport",
           DEF_GPIO_RIGHT);
    system(start);
    system(stop);
    system(pressed);
    system(left);
    system(right);
    this->quit();
    this->wait();
}

void PhysicalKey::run()
{
    while(1)
    {
        if(!m_ThreadStatus)
            return;
        if(!m_ThreadStart)
        {
            msleep(500);
            continue;
        }
        lseek(m_FDList[0], 0, SEEK_SET);
        lseek(m_FDList[1], 0, SEEK_SET);
        lseek(m_FDList[2], 0, SEEK_SET);
        lseek(m_FDList[3], 0, SEEK_SET);
        lseek(m_FDList[4], 0, SEEK_SET);
        char recvdata[32] = {0};
        int nRet = read(m_FDList[1], recvdata, 32);
        if(recvdata[0] == '0')
        {
            emit sigRecvBtn(ENM_PHYSICALKEY_STOP);
            msleep(500);
            continue;
        }
        nRet = read(m_FDList[0], recvdata, 32);
        if(recvdata[0] == '0')
        {
            emit sigRecvBtn(ENM_PHYSICALKEY_START);
            msleep(500);
            continue;
        }
        nRet = read(m_FDList[2], recvdata, 32);
        if(recvdata[0] == '0')
        {
            emit sigRecvBtn(ENM_PHYSICALKEY_PRESS);
            msleep(500);
            continue;
        }
        nRet = read(m_FDList[3], recvdata, 32);
        if(recvdata[0] == '0')
        {
            handleRotation();
        }
        nRet = read(m_FDList[4], recvdata, 32);
        if(recvdata[0] == '0')
        {
            handleRotation();
        }
    }
}

void PhysicalKey::handleRotation()
{
    int m_LeftStatus = 0;
    int m_RightStatus = 0;
    int m_FirstStatus = 0;
    char recvData[32] = {0};
    int maxCnt = 50;
    while(1)
    {
        if(maxCnt <= 0)
            return;
        int nRet = read(m_FDList[3], recvData, 32);
        if(recvData[0] == '0')
        {
            m_LeftStatus = 1;
            if(m_FirstStatus == 0)
                m_FirstStatus = 1;
        }
        else
            m_LeftStatus = 0;
        nRet = read(m_FDList[4], recvData, 32);
        if(recvData[0] == '0')
        {
            m_RightStatus = 1;
            if(m_FirstStatus == 0)
                m_FirstStatus = 2;
        }
        else
            m_RightStatus = 0;
        lseek(m_FDList[3], 0, SEEK_SET);
        lseek(m_FDList[4], 0, SEEK_SET);
        //printf("left recv %lld %d %d %d \n", m_Count++, m_RightStatus, m_LeftStatus, m_FirstStatus);
        if(m_RightStatus == 1 && m_LeftStatus == 1 && m_FirstStatus > 0)
        {
            if(m_FirstStatus == 1)
                emit sigRecvBtn(ENM_PHYSICALKEY_LEFT);
            else
                emit sigRecvBtn(ENM_PHYSICALKEY_RIGHT);
            m_FirstStatus = 0;
            return;
        }
        else
            QThread::msleep(1);
        maxCnt--;
        continue;
    }
}
