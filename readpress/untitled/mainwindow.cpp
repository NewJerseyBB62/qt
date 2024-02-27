#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QDateTime>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_ReadthreadObj(nullptr)
    , m_JsonObj(nullptr)
    , m_DataObj(nullptr)
{
    ui->setupUi(this);
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
    m_ReadthreadObj = new Readthread(m_SetData.serialport, m_SetData.baudrate);
    connect(m_ReadthreadObj, &Readthread::SigRecvData, this, &MainWindow::SlotRecvData, Qt::QueuedConnection);
    if(m_ReadthreadObj->initReadthread() != 0)
    {
        QMessageBox::information(this, "错误", "打开串口失败 请检查串口", QMessageBox::Yes);
        ui->pushButton_2->setEnabled(true);
        return;
    }
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

void MainWindow::SlotRecvData(const float& p_val)
{
    QPalette pe;
    QString strMsg;
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
