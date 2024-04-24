#include "datadialog.h"
#include "ui_datadialog.h"

DataDialog::DataDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DataDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

DataDialog::~DataDialog()
{
    delete ui;
}

void DataDialog::on_closeBtn_clicked()
{
    this->close();
}
