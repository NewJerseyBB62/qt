#include "settingdialog.h"
#include "ui_settingdialog.h"

SettingDialog::SettingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

SettingDialog::~SettingDialog()
{
    delete ui;
}

void SettingDialog::on_closeBtn_clicked()
{
    this->close();
}

void SettingDialog::on_saveBtn_clicked()
{

}
