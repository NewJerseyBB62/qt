#include "mainwindow.h"
#include "ui_mainwindow.h"




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_TimeoutTimer(nullptr)
    , m_post(nullptr)
{
    ui->setupUi(this);
    m_TimeoutTimer = new QTimer();
    connect(m_TimeoutTimer, &QTimer::timeout, [&]{
        m_RequestState = RequestState::ENM_REQUEST_TIMEOUT;
        m_TimeoutTimer->stop();
    });
    init(2000);
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init(int p_timeOut)
{
    m_post = new PostThread();
    m_post->initPost();
}

int MainWindow::getRequestState()
{
    return (int)m_RequestState;
}


void MainWindow::slotResult()
{
#if 0
    if(m_TimeoutTimer->isActive())
    {
        m_TimeoutTimer->stop();
    }
    else
    {
        return;
    }
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
#endif
}






