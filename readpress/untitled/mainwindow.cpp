#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QDateTime>
#include <QMetaType>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_ReadthreadObj(nullptr)
    , m_JsonObj(nullptr)
    , m_DataObj(nullptr)
    , m_DatabaseObj(nullptr)
{
    ui->setupUi(this);
    ui->textBrowser->document()->setMaximumBlockCount(100);
    qRegisterMetaType<SqlData>("SqlData");
    qRegisterMetaType<SqlData>("SqlData&");
}

MainWindow::~MainWindow()
{
//    SlotCloseDataObj();
//    WriteSetting(m_SetData);
//    if(m_ReadthreadObj != nullptr)
//    {
//        m_ReadthreadObj->uninitReadthread();
//        delete m_ReadthreadObj;
//    }
    delete ui;
}

void MainWindow::init()
{
    initSerialPort();
    ReadSetting(m_SetData);
    int idx = ui->serialCB->findText(m_SetData.serialport);
    if(idx >= 0)
    {
        ui->serialCB->setCurrentIndex(idx);
    }
    else
        ui->serialCB->setCurrentIndex(-1);
    ui->baudCB->setCurrentText(QString::number(m_SetData.baudrate));
    ui->alamMaxLE->setText(QString::number(m_SetData.alamMax, 'f', 2));
    ui->alamMinLE->setText(QString::number(m_SetData.alamMin, 'f', 2));
    ui->copeLE->setText(QString::number(m_SetData.copeVal, 'f', 2));
    ui->savetimeCB->setCurrentIndex(GetSavetimeIdx(m_SetData.saveTime));
    m_ReadthreadObj = new Readthread(m_SetData.serialport, m_SetData.baudrate);
    connect(m_ReadthreadObj, &Readthread::SigRecvData, this, &MainWindow::SlotRecvData, Qt::QueuedConnection);
    if(m_ReadthreadObj->initReadthread() != 0)
    {
        QMessageBox::information(this, "错误", "打开串口失败 请检查串口", QMessageBox::Yes);
        ui->pushButton_2->setEnabled(true);
        return;
    }
    m_DatabaseObj = new Database(m_SetData.saveTime);
    connect(this, &MainWindow::SigSendData, m_DatabaseObj, &Database::GetTestData, Qt::QueuedConnection);
    connect(this, &MainWindow::SigSaveTime, m_DatabaseObj, &Database::GetSaveTime, Qt::QueuedConnection);
    m_DatabaseObj->startDBThread();
    m_ReadthreadObj->SlotStart();
    ui->pushButton_2->setEnabled(false);
}

void MainWindow::closeEvent(QCloseEvent *)
{
    SlotCloseDataObj();
    WriteSetting(m_SetData);
    if(m_ReadthreadObj != nullptr)
    {
        m_ReadthreadObj->uninitReadthread();
        delete m_ReadthreadObj;
    }
    if(m_DatabaseObj != nullptr)
    {
        delete m_DatabaseObj;
        m_DatabaseObj = nullptr;
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    m_ReadthreadObj->SetSerialport(m_SetData.serialport, m_SetData.baudrate);
    if(m_ReadthreadObj->SlotStart() != 0)
    {
        QMessageBox::information(this, "错误", "打开串口失败 请检查串口", QMessageBox::Yes);
        return;
    }
    ui->pushButton_2->setEnabled(false);
}

void MainWindow::on_pushButton_clicked()
{
    m_ReadthreadObj->SlotStop();
    ui->pushButton_2->setEnabled(true);
}

void MainWindow::on_pushButton_3_clicked()
{
    if(m_DataObj != nullptr)
    {
        m_DataObj->setFocus();
        return;
    }
    ui->pushButton_3->setEnabled(false);
    m_DataObj = new DataDialog;
    connect(m_DataObj, &DataDialog::rejected, this, &MainWindow::SlotCloseDataObj);
    connect(m_DataObj, &DataDialog::accepted, this, &MainWindow::SlotCloseDataObj);
    connect(m_DataObj, &DataDialog::SigClose, this, &MainWindow::SlotCloseDataObj);
    m_DataObj->initDatabase();
    m_DataObj->show();
    m_DataObj->setFocus();
    ui->pushButton_3->setEnabled(true);
}

void MainWindow::SlotRecvData(const float& p_val,  const QByteArray &p_data)
{
    QPalette pe;
    QString strMsg;
    SqlData sendData;
    QDateTime dateTime= QDateTime::currentDateTime();
    strMsg = dateTime.toString("yyyy-MM-dd hh:mm:ss");
    strMsg.append(" 压力值: ");
    float val = p_val + m_SetData.copeVal;
    strMsg.append(QString::number(val, 'f', 2));
    pe.setColor(QPalette::WindowText, Qt::black);
    ui->CurrValLab->setPalette(pe);
    if(val >= m_SetData.alamMax)
    {
        pe.setColor(QPalette::WindowText, Qt::red);
        ui->CurrValLab->setPalette(pe);
        ui->CurrValLab->setText(QString::number(val, 'f', 2));
        strMsg.append(" 过高 ");
        ui->textBrowser->append("<font color=\"#FF0000\">" + strMsg + "</font> ");
        return;
    }
    else if(val <= m_SetData.alamMin)
    {
        pe.setColor(QPalette::WindowText, Qt::blue);
        ui->CurrValLab->setPalette(pe);
        ui->CurrValLab->setText(QString::number(val, 'f', 2));
        strMsg.append(" 过低 ");
        ui->textBrowser->append("<font color=\"#0000FF\">" + strMsg + "</font> ");
        return;
    }
    ui->CurrValLab->setText(QString::number(val, 'f', 2));
    strMsg.append(" 正常 ");
    ui->textBrowser->append("<font color=\"#000000\">" + strMsg + "</font> ");
    //ui->textBrowser->append(p_data.toHex());
    sendData.pressVal = val;
    sendData.pressMax = m_SetData.alamMax;
    sendData.pressMin = m_SetData.alamMin;
    sendData.testDate = dateTime.toString("yyyy-MM-dd hh:mm:ss");
    sendData.pressComp = m_SetData.copeVal;
    emit SigSendData(sendData);
}

void MainWindow::SlotCloseDataObj()
{
    if(m_DataObj != nullptr)
    {
        m_DataObj->uninitDatabase();
        m_DataObj->close();
        delete m_DataObj;
        m_DataObj = nullptr;
    }
}

void MainWindow::initSerialPort()
{
    QStringList serialList;
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
       serialList << info.portName();
    }
    if(serialList.size() > 0)
        ui->serialCB->addItems(serialList);
}

void MainWindow::ReadSetting(SetData &p_data)
{
    m_JsonObj->readJsonfile("./setting.json", p_data);
}

void MainWindow::WriteSetting(const SetData &p_data)
{
    m_JsonObj->writeJsonfile("./setting.json", p_data);
}

void MainWindow::on_baudCB_currentTextChanged(const QString &arg1)
{
    m_SetData.baudrate = arg1.toInt();
}

void MainWindow::on_alamMaxLE_textChanged(const QString &arg1)
{
    m_SetData.alamMax = arg1.toDouble();
}

void MainWindow::on_alamMinLE_textChanged(const QString &arg1)
{
    m_SetData.alamMin = arg1.toDouble();
}

void MainWindow::on_copeLE_textChanged(const QString &arg1)
{
    m_SetData.copeVal = arg1.toDouble();
}

void MainWindow::on_serialCB_currentIndexChanged(const QString &arg1)
{
    m_SetData.serialport = arg1;
}

int MainWindow::GetSavetime(int index)
{
    int savetime = 60;
    switch(index)
    {
        case 0:
            savetime = 1;
        break;
        case 1:
            savetime = 10;
        break;
        case 2:
            savetime = 30;
        break;
        case 3:
            savetime = 60;
        break;
        case 4:
            savetime = 600;
        break;
        case 5:
            savetime = 1800;
        break;
        case 6:
            savetime = 3600;
        break;
        default:
            break;
    }
    return savetime;
}

int MainWindow::GetSavetimeIdx(int time)
{
    int idx = 3;
    switch(time)
    {
        case 1:
            idx = 0;
        break;
        case 10:
            idx = 1;
        break;
        case 30:
            idx = 2;
        break;
        case 60:
            idx = 3;
        break;
        case 600:
            idx = 4;
        break;
        case 1800:
            idx = 5;
        break;
        case 3600:
            idx = 6;
        break;
        default:
            break;
    }
    return idx;
}

void MainWindow::on_savetimeCB_activated(int index)
{
    m_SetData.saveTime = GetSavetime(index);
}
