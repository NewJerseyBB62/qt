#include "datadialog.h"
#include "ui_datadialog.h"
#include <QDateTime>
#include <QFileInfo>
#include <QDir>
#include <QSqlError>
#include <QSqlQuery>


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
    QDir dir(QDir::currentPath());
    if(dir.exists("db"))
    {
        dir.mkdir("db");
        dir.cd("./db");
        m_SqlObj = QSqlDatabase::addDatabase("QSQLITE");
        m_SqlObj.setDatabaseName("./db/MyDataBase.db");
        if(m_SqlObj.open())
        {
            if(CreateTable() != 0)
            {
                m_SqlObj.close();
                return 1;
            }
        }
        else
            m_SqlObj.close();
    }
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

int DataDialog::CreateTable()
{
    QSqlQuery query;
    QString creatTableStr = "CREATE TABLE PressData \
            (                                       \
              ID        INTEGER   PRIMARY KEY AUTOINCREMENT  NOT NULL,     \
              DATE      datetime  NOT NULL ,        \
              MAX       float  NULL ,               \
              MIN       float  NULL ,               \
              PRESS     float  NULL ,               \
              COMP      float  NULL ,               \
              STATE     char(16)  NULL ,            \
            );";
    query.prepare(creatTableStr);
    if(!query.exec())
    {
        return 1;
    }
    return 0;
}
