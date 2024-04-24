#include "handlethread.h"
#include <QDebug>
#include <QThread>

HandleThread::HandleThread(QObject *parent) : QObject(parent)
{
    m_ThreadRun = true;
    m_WebObj = nullptr;
    m_Timer = nullptr;
    m_Testing = false;
}

int HandleThread::initThread(const IniStruct &cfg, const int p_timeOut)
{
    m_cfg = cfg;
    m_Timeout = p_timeOut;
    if(m_WebObj == nullptr)
        m_WebObj = new WebApi();
    m_WebObj->initWebApi(m_cfg, m_Timeout);
    m_DbObj = new dbOperation();
    m_Timer = new QTimer();
    m_Timer->setInterval(2000);
    connect(m_Timer, &QTimer::timeout, [&]{
        test();
    });
    if(m_DbObj->openDB() != 0)
    {
        return 1;
    }
    return 0;
}

void HandleThread::uninitThread()
{
    m_Timer->stop();
    delete m_Timer;
    m_DbObj->closeDB();
    m_WebObj->uninitWebApi();
    delete m_DbObj;
    delete m_WebObj;
}

void HandleThread::startTest()
{
    m_ThreadRun = true;
    m_Timer->start();
    //this->start();
}

void HandleThread::stopThread()
{
    m_ThreadRun = false;
    m_Timer->stop();
    QThread::msleep(1000);
}

void HandleThread::setConfig(const IniStruct &cfg)
{
    m_cfg = cfg;
}

void HandleThread::test()
{
    if(m_Testing)
        return;
    do
    {
        m_Testing = true;
        QString strErr;
        QByteArray strData;
        QStringList totalData;
        QList<ChildStruct> childData;
        if(!m_ThreadRun)
            break;
        //if(m_DbObj->openDB() != 0)
        if(0)
        {
            emit sigStatus(0, "打开本地数据库失败");
            break;
        }
        totalData.clear();
        childData.clear();
        m_DbObj->queryGroupData(totalData, &childData);
        int nRet = m_WebObj->sendWebData(totalData, &childData, strErr, strData);
        if(nRet == 0)
        {
            //qDebug()<<"total" << totalData.size() << " child " << childData.size();
            QString strSql = QString("UPDATE TestInfoBaseSerialNoMES SET SERVEROK = 1 WHERE SerialNo = '%1' AND SystemTime = '%2';").arg(
                        totalData.at(0)).arg(totalData.at(17));
            m_DbObj->updateDB(strSql);
            strSql = QString("UPDATE TestConditionResultMES SET SERVEROK = 1 WHERE SerialNo = '%1' and Flag = %2;").arg(
                        totalData.at(0)).arg(totalData.at(19));
            m_DbObj->updateDB(strSql);
            break;
        }
        emit sigStatus(0, strErr);

    }while(0);
    //m_DbObj->closeDB();
    m_Testing = false;
}

#if 0
void HandleThread::run()
{
    if(m_WebObj == nullptr)
        m_WebObj = new WebApi();
    m_WebObj->initWebApi(m_cfg, m_Timeout);
    QStringList totalData;
    QList<ChildStruct> childData;
    while(1)
    {
        if(!m_ThreadRun)
            break;
        //if(m_DbObj->openDB() != 0)
        if(0)
        {
            emit sigStatus((int)ERR_TYPE::ENM_DBOPEN_ERROR, "");
            msleep(1000);
            continue;
        }
        else
            emit sigStatus((int)ERR_TYPE::ENM_NO_ERROR, "");
        totalData.clear();
        childData.clear();
        if(m_DbObj->queryGroupData(totalData, &childData) != 0)
        {
            msleep(1000);
            continue;
        }
        int nRet = m_WebObj->sendWebData(totalData, &childData);
//        int i = 0;
//        int nState;
//        while(i < 20)
//        {
//            nState = m_WebObj->getRequestState();
//            if(nState != (int)RequestState::ENM_REQUEST_WAIT)
//                break;
//            msleep(100);
//            i++;
//        }
        //if(nState == (int)RequestState::ENM_REQUEST_OK)
        if(nRet == 0)
        {
            qDebug()<<"total" << totalData.size() << " child " << childData.size();
            QString strSql = QString("UPDATE TestInfoBaseSerialNoMES SET SERVEROK = 1 WHERE SerialNo = '%1' AND SystemTime = '%2';").arg(
                        totalData.at(0)).arg(totalData.at(17));
            m_DbObj->updateDB(strSql);
            strSql = QString("UPDATE TestConditionResultMES SET SERVEROK = 1 WHERE SerialNo = '%1' and Flag = %2;").arg(
                        totalData.at(0)).arg(totalData.at(19));
            m_DbObj->updateDB(strSql);
            msleep(500);
            break;
        }
        else
        {
            msleep(500);
            break;
        }
    }
    m_WebObj->uninitWebApi();
    delete m_WebObj;
    m_WebObj = nullptr;
}
#endif
