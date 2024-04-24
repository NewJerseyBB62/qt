#ifndef WEBAPI_H
#define WEBAPI_H

#include <QObject>
#include "common.h"
#include <QtNetwork/QNetworkReply>
#include <QTimer>

enum class RequestState{
    ENM_REQUEST_OK = 0,
    ENM_REQUEST_WAIT,
    ENM_REQUEST_TIMEOUT,
    ENM_REQUEST_ERROR,
    ENM_REQUEST_JSONERR,
    ENM_REQUEST_NULL
};

class WebApi : public QObject
{
    Q_OBJECT
public:
    explicit WebApi(QObject *parent = nullptr);
    int initWebApi(const IniStruct &cfg, const int p_timeOut);
    void setConfig(const IniStruct &cfg);
    void uninitWebApi();
    int sendWebData(const QStringList &p_totalData, QList<ChildStruct> *p_childData, QString &p_strErr, QByteArray &p_strData);
    int getRequestState();

signals:
    void sigTimerStart();

public slots:
    void slotTimerStart();
    void slotResult();
    void slotTimeout();

private:
    IniStruct m_Cfg;
    volatile RequestState m_RequestState;
    QNetworkReply *m_Reply;
    common *m_CommFunc;
    QTimer *m_Timer;
};

#endif // WEBAPI_H

