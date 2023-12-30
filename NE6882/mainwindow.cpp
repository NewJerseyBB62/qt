#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "common.h"
#include "login/logindialog.h"
#include "test/testdialog.h"
#include "program/programdialog.h"
#include "setting/settingdialog.h"
#include "report/reportdialog.h"
#include "jsonoperation/jsonoperation.h"
#include <windows.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setWindowIcon(QIcon(":/icon/mian/MAIN3.ico"));
    loginDialog loginObj;
    if(loginObj.exec() == QDialog::Rejected)
    {
        exit(0);
        return;
    }

    this->showFullScreen();
    ui->versionLab->setText("软件版本号: V1.00");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_minBtn_clicked()
{
   this->showMinimized();
}

void MainWindow::on_closeBtn_clicked()
{
    exit(0);
}

void MainWindow::on_testBtn_clicked()
{
    testDialog testObj;
    testObj.initTest();
    testObj.show();
    this->hide();
    testObj.exec();
    this->show();
}

void MainWindow::on_programBtn_clicked()
{
    QString szLastFile("");
    JsonData jsonData;
    jsonOperation jsonObj;
    jsonObj.readJsonfile("./systemsetting.json", jsonData);
    if(jsonData.testItemData.canConvert<SystemData>())
        szLastFile = jsonData.testItemData.value<SystemData>().szTestfilePath;
    programDialog programObj(szLastFile);
    programObj.show();
    this->hide();
    programObj.exec();
    this->show();
}

void MainWindow::on_reportBtn_clicked()
{

}

void MainWindow::on_settingBtn_clicked()
{
    settingDialog settingObj;
    settingObj.show();
    this->hide();
    settingObj.exec();
    this->show();
}
