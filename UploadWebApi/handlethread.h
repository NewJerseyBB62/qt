#ifndef HANDLETHREAD_H
#define HANDLETHREAD_H

#include <QObject>
#include "dboperation.h"
#include "webapi.h"
#include <QTimer>

enum class ERR_TYPE{
    ENM_NO_ERROR = 0,
    ENM_DBOPEN_ERROR,
    ENM_SEND_ERROR,
    ENM_RECV_ERROR
};

class HandleThread : public QObject
{
    Q_OBJECT
public:
    explicit HandleThread(QObject *parent = nullptr);
    int initThread(const IniStruct &cfg, const int p_timeOut);
    void uninitThread();
    void startTest();
    void stopThread();
    void setConfig(const IniStruct &cfg);
    void test();

#if 0
protected:
    void run();
#endif

signals:
    void sigStatus(int p_status, const QString &p_errInfo);
    void sigSendData(const QByteArray &p_data);
public slots:

private:
    dbOperation *m_DbObj;
    volatile bool m_ThreadRun;
    WebApi *m_WebObj;
    IniStruct m_cfg;
    int m_Timeout;
    QTimer *m_Timer;
    bool m_Testing;
};

#endif // HANDLETHREAD_H
