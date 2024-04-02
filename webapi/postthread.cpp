#include "postthread.h"

#include "QUrl"
#include "QtNetwork/QHttpMultiPart"


#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QtDebug>
#include <QEventLoop>

PostThread::PostThread()
{
    m_Reply = nullptr;
}

void PostThread::initPost()
{
    QJsonArray jsonArray { 1, 2, 3 };
    QJsonObject jsonObject;
    jsonObject["username"] = "test";
    jsonObject["password"] = "123";
    jsonObject["array"] = jsonArray;
    m_request = new QNetworkRequest(QUrl("http://218.94.7.245:8482/api/callback/upperComputer"));
    m_request->setRawHeader("Content-Type", "application/json");
    m_Timer = new QTimer(this);
    m_Timer->setInterval(1000);
    connect(m_Timer, &QTimer::timeout, this, &PostThread::slotTimeout);
    m_Timer->start();
    //this->start();
}

//slotover无法接受线程中所产生的relpy信号。 因为QNetworkAccessManager是在线程中创建 QNetworkReply无法跨线程
void PostThread::slotOver()
{
    if (m_Reply->error() == QNetworkReply::NoError)
    {

    }
    else
    {
        QVariant statusCodeV = m_Reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
        //statusCodeV是HTTP服务器的相应码，reply->error()是Qt定义的错误码，可以参考QT的文档
        //qDebug( "request protobufHttp found error ....code: %d %d\n", statusCodeV.toInt(), (int)m_Reply->error());
        //qDebug(qPrintable(m_Reply->errorString()));
    }
    QByteArray result = m_Reply->readAll();
    //解析JSON
    QJsonParseError jsonError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(result, &jsonError);
    if (jsonError.error != QJsonParseError::NoError) {
        qDebug()<<"Json文件解析错误。";
        //return false;
    }
    if (jsonDoc.isObject()) {
        QJsonObject jsonObject = jsonDoc.object();
        qDebug()<<jsonObject;
    }
    else if (jsonDoc.isArray()) {
        QJsonArray jsonArray = jsonDoc.array();
        qDebug()<<jsonArray;
    }
    else {
        qDebug()<<"Json文件解析为空。";
    }
}

void PostThread::slotTimeout()
{
    QJsonArray jsonArray { 1, 2, 3 };
    QJsonObject jsonObject;
    jsonObject["username"] = "test";
    jsonObject["password"] = "123";
    jsonObject["array"] = jsonArray;
    m_Reply = m_manager.post(*m_request, QJsonDocument(jsonObject).toJson());
    QObject::connect(m_Reply, SIGNAL(finished()), this, SLOT(slotOver()));
}

void PostThread::run()
{
    QJsonArray jsonArray { 1, 2, 3 };
    QJsonObject jsonObject;
    jsonObject["username"] = "test";
    jsonObject["password"] = "123";
    jsonObject["array"] = jsonArray;


    //QSslConfiguration config = QSslConfiguration::defaultConfiguration();
    //config.setProtocol(QSsl::TlsV1_0);
    //config.setPeerVerifyMode(QSslSocket::VerifyNone);
    //request.setSslConfiguration(config);
    //POST 操作需要与QNetworkAccessManager在同一线程中
    m_Reply = m_manager.post(*m_request, QJsonDocument(jsonObject).toJson());
    QObject::connect(m_Reply, SIGNAL(finished()), this, SLOT(slotOver()));
    //使用eventLoop是为了保证QNetworkReply与QNetworkAccessManager在同一线程中，如果异步线程外将接收不到QNetworkReply结果
    //QEventLoop eventLoop;
    //QObject::connect(m_Reply, SIGNAL(finished()), &eventLoop, SLOT(quit()));
    //eventLoop.exec(); // 进入等待返回，但ui事件循环依然进行。
}
