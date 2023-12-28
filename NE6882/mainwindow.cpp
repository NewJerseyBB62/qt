#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "common.h"
#include "login/logindialog.h"
#include "test/testdialog.h"
#include "program/programdialog.h"
#include "setting/settingdialog.h"
#include "report/reportdialog.h"
#include "jsonoperation/jsonoperation.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);

    loginDialog loginObj;
    if(loginObj.exec() == QDialog::Rejected)
    {
        exit(0);
        return;
    }


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
    testObj.exec();
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
    programObj.exec();
}

void MainWindow::on_reportBtn_clicked()
{

}

void MainWindow::on_settingBtn_clicked()
{
    settingDialog settingObj;
    settingObj.show();
    settingObj.exec();
}
