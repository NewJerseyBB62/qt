#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QtNetwork/QNetworkAccessManager"
#include "QUrl"
#include "QtNetwork/QHttpMultiPart"
#include "QtNetwork/QNetworkRequest"
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QtNetwork/QNetworkReply>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_IniObj(nullptr),
    m_Thread(nullptr)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog | Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint);
    ui->logTB->document()->setMaximumBlockCount(20);
}

void MainWindow::initMainWindow()
{
    m_IniObj = new iniOperation();
    m_IniObj->readIniFile("./config.ini", m_IniData);
    ui->urlLE->setText(m_IniData.strUrl);
    ui->logCB->setChecked(m_IniData.logCheck);
    m_LogCheck = m_IniData.logCheck;
    m_Thread = new HandleThread();
    connect(m_Thread, &HandleThread::sigStatus, this, &MainWindow::slotStatus);
    connect(m_Thread, &HandleThread::sigSendData, this, &MainWindow::slotSendData);
    if(m_Thread->initThread(m_IniData, 2000) != 0)
        ui->errLab->setText("打开本地数据库失败");
    else
        ui->errLab->setText("");
    m_Thread->startTest();
    ui->startBtn->setEnabled(false);
}

MainWindow::~MainWindow()
{
    m_IniData.strUrl = ui->urlLE->text();
    m_IniData.logCheck = ui->logCB->isChecked();
    m_IniObj->writeIniFile("./config.ini", m_IniData);
    delete m_IniObj;
    m_Thread->stopThread();
    m_Thread->uninitThread();
    delete m_Thread;
    delete ui;
}

void MainWindow::slotStatus(int p_status, const QString &p_errInfo)
{
    ui->errLab->setText(p_errInfo);
}

void MainWindow::slotSendData(const QByteArray &p_data)
{
    ui->logTB->append(p_data);
}

void MainWindow::on_startBtn_clicked()
{
    ui->startBtn->setEnabled(false);
    ui->urlLE->setEnabled(false);
    m_Thread->startTest();
}

void MainWindow::on_stopBtn_clicked()
{
    m_Thread->stopThread();
    ui->startBtn->setEnabled(true);
    ui->urlLE->setEnabled(true);
}

void MainWindow::on_logCB_toggled(bool checked)
{
    m_LogCheck = checked;
}

