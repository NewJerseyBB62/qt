#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPort>
#include <QSerialPortInfo>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{

}

void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_pushButton_3_clicked()
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
