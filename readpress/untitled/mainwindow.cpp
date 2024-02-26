#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPortInfo>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_ReadthreadObj(nullptr)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    if(m_ReadthreadObj != nullptr)
    {
        m_ReadthreadObj->uninitReadthread();
        delete m_ReadthreadObj;
    }
    delete ui;
}

void MainWindow::init()
{
    ReadSetting(m_SetData);
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


void MainWindow::on_pushButton_2_clicked()
{
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

}

void MainWindow::SlotRecvData(const float& p_val)
{

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

}

void MainWindow::WriteSetting(const SetData &p_data)
{

}
