#include "webapi.h"
#include "QtNetwork/QNetworkAccessManager"
#include "QUrl"
#include "QtNetwork/QHttpMultiPart"
#include "QtNetwork/QNetworkRequest"
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>
#include <QEventLoop>
#include <QThread>


WebApi::WebApi(QObject *parent) : QObject(parent)
    , m_Reply(nullptr)
    , m_CommFunc(nullptr)
    //, m_Timer(nullptr)
{

}

void WebApi::setConfig(const IniStruct &cfg)
{
    m_Cfg = cfg;
}

int WebApi::initWebApi(const IniStruct &cfg, const int p_timeOut)
{
    m_Cfg = cfg;
    m_CommFunc = new common();
    //m_Timer = new QTimer();
    //m_Timer->setInterval(2000);
}

void WebApi::uninitWebApi()
{
    //m_Timer->stop();
    //delete m_Timer;
    delete m_CommFunc;
}

int WebApi::sendWebData(const QStringList &p_totalData, QList<ChildStruct> *p_childData, QString &p_strErr, QByteArray &p_strData)
{
    QString strAppId, strSecret;
    int flag;
    QNetworkAccessManager manager;

    QString strTimestamp = QString::number(m_CommFunc->getTimestamp());
    QNetworkRequest request(QUrl(m_Cfg.strUrl));
    m_CommFunc->writeLog(m_Cfg.strUrl.toLatin1());
    request.setRawHeader("Content-Type", "application/json");
    request.setRawHeader("ts", strTimestamp.toStdString().c_str());
    request.setRawHeader("appid", QString(p_totalData.at(17)).toStdString().c_str());
    request.setRawHeader("token", QString(p_totalData.at(17) + strTimestamp + p_totalData.at(20)).toStdString().c_str());
    QJsonObject jsonObject;
    QJsonArray jsonArray;
    int idx = 0;
    jsonObject["barCode"] = p_totalData.at(idx++);
    jsonObject["userCode"] = p_totalData.at(idx++);
    jsonObject["siteCode"] = p_totalData.at(idx++);
    jsonObject["barCodeType"] = p_totalData.at(idx++);
    idx++;
    jsonObject["userName"] = p_totalData.at(idx++);
    jsonObject["deviceCode"] = p_totalData.at(idx++);
    jsonObject["lineDesc"] = p_totalData.at(idx++);
    jsonObject["cellDesc"] = p_totalData.at(idx++);
    jsonObject["checkType"] = p_totalData.at(idx++);
    jsonObject["checkContent"] = p_totalData.at(idx++);
    strAppId = p_totalData.at(idx++);
    strSecret = p_totalData.at(idx++);
    jsonObject["lineCode"] = p_totalData.at(idx++);
    jsonObject["cellCode"] = p_totalData.at(idx++);
    jsonObject["checkResult"] = p_totalData.at(idx++);
    jsonObject["checkValue"] = "";
    idx++;
    jsonObject["checkTime"]= p_totalData.at(idx++);
    idx++;
    flag = QString(p_totalData.at(idx++)).toInt();
    int i = 0;
    while(i < p_childData->size())
    {
        QJsonObject itemObject;
        char setValue[64] = {0};
        char resultVal[64] = {0};
        sprintf(setValue, "%.3f%s", p_childData->at(i).testSet, p_childData->at(i).testSetUnit.toStdString().c_str());
        sprintf(resultVal, "%.3f%s", p_childData->at(i).testVal, p_childData->at(i).testValUnit.toStdString().c_str());
        if(p_childData->at(i).testName.contains("交耐") || p_childData->at(i).testName.contains("耐压"))
        {
            itemObject["item"] = "交流耐压";
            itemObject["checkContent"] = "电流值测试";

        }
        else if(p_childData->at(i).testName.contains("接地"))
        {
            itemObject["item"] = "接地电阻";
            itemObject["checkContent"] = "电阻值测试";

        }
        else if(p_childData->at(i).testName.contains("绝缘"))
        {
            itemObject["item"] = "绝缘测试";
            itemObject["checkContent"] = "电流值测试";

        }
        else if(p_childData->at(i).testName.contains("泄漏"))
        {
            itemObject["item"] = "泄漏测试";
            itemObject["checkContent"] = "电流值测试";

        }
        else if(p_childData->at(i).testName.contains("功率"))
        {
            itemObject["item"] = "功率测试";
            itemObject["checkContent"] = "功率值测试";

        }
        else if(p_childData->at(i).testName.contains("启动"))
        {
            itemObject["item"] = "低压启动";
            itemObject["checkContent"] = "电流值测试";

        }
        else if(p_childData->at(i).testName.contains("开短"))
        {
            itemObject["item"] = "开短路测试";
            itemObject["checkContent"] = "电阻值测试";

        }
        else
        {
            itemObject["item"] = "";
            itemObject["checkContent"] = "";
            strcpy(resultVal, "");
        }
        itemObject["result"] = QString::number(p_childData->at(i).testResult);
        itemObject["checkValue"] = resultVal;
        jsonArray.append(itemObject);
        i++;
    }
    jsonObject["checkItems"] = jsonArray;
    QByteArray rawJson = QJsonDocument(jsonObject).toJson();
    p_strData = rawJson;
    QEventLoop eventLoop;
    QNetworkReply *pReply = manager.post(request, rawJson);
    connect(pReply, &QNetworkReply::finished, &eventLoop, &QEventLoop::quit);
    //connect(m_Reply, &QNetworkReply::finished, this, &WebApi::slotResult);
    //m_CommFunc->writeLog(rawJson);
    m_RequestState = RequestState::ENM_REQUEST_WAIT;
#if 1
    //connect(m_Timer, &QTimer::timeout, &eventLoop, &QEventLoop::quit);
    //m_Timer->start();
    eventLoop.exec();
    if (pReply->error() == QNetworkReply::NoError)
    {
        QByteArray result = pReply->readAll();
        m_CommFunc->writeLog(result);
        //解析JSON
        QJsonParseError jsonError;
        QJsonDocument jsonDoc = QJsonDocument::fromJson(result, &jsonError);
        if (jsonError.error != QJsonParseError::NoError)
        {
            p_strErr = "错误 解析应答内容失败";
            return (int)RequestState::ENM_REQUEST_ERROR;
        }
        if (jsonDoc.isObject() || jsonDoc.isArray())
        {
            QJsonObject jsonObject = jsonDoc.object();
            if(jsonObject["code"].toString() == "200")
            {
                m_RequestState = RequestState::ENM_REQUEST_OK;
                p_strErr = "";
            }
            else
            {
                m_RequestState = RequestState::ENM_REQUEST_ERROR;
                p_strErr = jsonObject["data"].toString();
            }
            qDebug()<<jsonObject;
        }
        else
        {
            p_strErr = "错误 应答内容为空";
            m_RequestState = RequestState::ENM_REQUEST_NULL;
        }
    }
    else
    {
        QVariant statusCodeV = pReply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
        //statusCodeV是HTTP服务器的相应码，reply->error()是Qt定义的错误码，可以参考QT的文档
        //qDebug( "request protobufHttp found error ....code: %d %d\n", statusCodeV.toInt(), (int)m_Reply->error());
        //qDebug(qPrintable(m_Reply->errorString()));
        //m_CommFunc->writeLog(pReply->errorString().toLatin1());
        p_strErr = QString("请求错误 错误代码: %1").arg(statusCodeV.toInt());
        m_RequestState = RequestState::ENM_REQUEST_ERROR;
    }

#endif
    return (int)m_RequestState;
}

int WebApi::getRequestState()
{
    return (int)m_RequestState;
}

void WebApi::slotTimerStart()
{

}

void WebApi::slotResult()
{
    if (m_Reply->error() == QNetworkReply::NoError)
    {
        m_RequestState = RequestState::ENM_REQUEST_OK;
    }
    else
    {
        QVariant statusCodeV = m_Reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
        //statusCodeV是HTTP服务器的相应码，reply->error()是Qt定义的错误码，可以参考QT的文档
        //qDebug( "request protobufHttp found error ....code: %d %d\n", statusCodeV.toInt(), (int)m_Reply->error());
        //qDebug(qPrintable(m_Reply->errorString()));
        m_CommFunc->writeLog(m_Reply->errorString().toLatin1());
        m_RequestState = RequestState::ENM_REQUEST_ERROR;
    }
    QByteArray result = m_Reply->readAll();
    //解析JSON
    QJsonParseError jsonError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(result, &jsonError);
    if (jsonError.error != QJsonParseError::NoError) {
        qDebug()<<"Json文件解析错误。";
        //return false;
    }
    if (jsonDoc.isObject())
    {
        QJsonObject jsonObject = jsonDoc.object();
        qDebug()<<jsonObject;
    }
    else if (jsonDoc.isArray())
    {
        QJsonArray jsonArray = jsonDoc.array();
        qDebug()<<jsonArray;
    }
    else
    {
        qDebug()<<"Json文件解析为空。";
    }
    //m_Reply->abort();
    //m_Reply->deleteLater();
    //m_Reply = nullptr;
}

void WebApi::slotTimeout()
{
    if (m_Reply->error() == QNetworkReply::NoError)
    {
        m_RequestState = RequestState::ENM_REQUEST_OK;
    }
    else
    {
        QVariant statusCodeV = m_Reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
        //statusCodeV是HTTP服务器的相应码，reply->error()是Qt定义的错误码，可以参考QT的文档
        //qDebug( "request protobufHttp found error ....code: %d %d\n", statusCodeV.toInt(), (int)m_Reply->error());
        //qDebug(qPrintable(m_Reply->errorString()));
        m_CommFunc->writeLog(m_Reply->errorString().toLatin1());
        m_RequestState = RequestState::ENM_REQUEST_ERROR;
    }
    QByteArray result = m_Reply->readAll();
    m_CommFunc->writeLog(result);
    //解析JSON
    QJsonParseError jsonError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(result, &jsonError);
    if (jsonError.error != QJsonParseError::NoError)
    {
        qDebug()<<"Json文件解析错误。";
        return;
    }
    if (jsonDoc.isObject())
    {
        QJsonObject jsonObject = jsonDoc.object();
        qDebug()<<jsonObject;
    }
    else if (jsonDoc.isArray())
    {
        QJsonArray jsonArray = jsonDoc.array();
        qDebug()<<jsonArray;
    }
    else
    {
        qDebug()<<"Json文件解析为空。";
    }
}
