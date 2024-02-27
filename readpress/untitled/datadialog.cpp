#include "datadialog.h"
#include "ui_datadialog.h"
#include <QDateTime>

DataDialog::DataDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DataDialog)
{
    ui->setupUi(this);
    //this->setAttribute(Qt::WA_DeleteOnClose);
}

DataDialog::~DataDialog()
{
    delete ui;
    //emit SigClose();
}

int DataDialog::initDatabase()
{
    QDateTime dateTime= QDateTime::currentDateTime();
    ui->startTE->setDate(dateTime.date());
    ui->stopTE->setDate(dateTime.date());
    return 0;
}

void DataDialog::uninitDatabase()
{

}

void DataDialog::on_queryBtn_clicked()
{

}

void DataDialog::on_resetBtn_clicked()
{

}

void DataDialog::on_firstPageBtn_clicked()
{

}

void DataDialog::on_prePageBtn_clicked()
{

}

void DataDialog::on_pushButton_5_clicked()
{

}

void DataDialog::on_nextPageBtn_clicked()
{

}

void DataDialog::on_lastPageBtn_clicked()
{

}

void DataDialog::on_closeBtn_clicked(QAbstractButton *button)
{
    this->close();
    emit SigClose();
}
