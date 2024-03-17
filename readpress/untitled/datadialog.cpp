#include "datadialog.h"
#include "ui_datadialog.h"
#include <QDateTime>
#include <QFileInfo>
#include <QDir>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QTextStream>
#include <QDebug>
#include <QThreadPool>

#define PAGE_DATANUM 20

DataDialog::DataDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DataDialog),
    m_taskObj(nullptr),
    m_TaskDialog(nullptr),
    m_TaskTimer(nullptr),
    m_TimeTick(0)
{
    ui->setupUi(this);
    //this->setAttribute(Qt::WA_DeleteOnClose);
}

DataDialog::~DataDialog()
{
    if(m_TaskDialog != nullptr)
    {
        m_TaskDialog->close();
        delete m_TaskDialog;
        m_TaskDialog = nullptr;
    }
    if(m_TaskTimer != nullptr)
    {
        m_TaskTimer->stop();
        delete m_TaskTimer;
        m_TaskTimer = nullptr;
    }
    if(m_taskObj != nullptr)
    {
        //m_taskObj->stopTask();
        m_taskObj = nullptr;
    }
    delete ui;
    //emit SigClose();
}

int DataDialog::initDatabase()
{
    QDateTime dateTime= QDateTime::currentDateTime();
    ui->startTE->setDate(dateTime.date());
    ui->stopTE->setDate(dateTime.date());
    pageChanged(1, 1);
    QDir dir(QDir::currentPath());
    if(dir.exists("db"))
    {
        dir.mkdir("db");
        dir.cd("./db");
        if(QSqlDatabase::contains("qt_sql_default_connection"))
            m_SqlObj = QSqlDatabase::database("qt_sql_default_connection");
        else
            m_SqlObj = QSqlDatabase::addDatabase("QSQLITE");
        m_SqlObj.setDatabaseName("./db/MyDataBase.db");
        if(m_SqlObj.open())
        {
            m_SqlObj.close();
            return 0;
        }
        else
            return -1;
    }
    else
        return -1;
}

void DataDialog::uninitDatabase()
{
    if(m_SqlObj.isOpen())
        m_SqlObj.close();
}

void DataDialog::SlotTimeOver()
{
    QString showText;
    if(m_TimeTick == 0)
        showText = "  .";
    else if(m_TimeTick == 1)
        showText = "  .  .";
    else
        showText = "  .  .  .";
    m_TaskDialog->SetText(showText);
}

void DataDialog::SlotTaskOver()
{
    m_TaskDialog->close();
    delete m_TaskDialog;
    m_TaskDialog = nullptr;
    m_TaskTimer->stop();
    delete m_TaskTimer;
    m_TaskTimer = nullptr;
    //m_taskObj->stopTask();
    //delete m_taskObj;
    m_taskObj = nullptr;
    ui->exportBtn->setEnabled(true);
}

void DataDialog::on_queryBtn_clicked()
{
    QString startDate = ui->startTE->date().toString("yyyy-MM-dd");
    QString stopDate = ui->stopTE->date().toString("yyyy-MM-dd");
    if(stopDate < startDate)
    {
        QMessageBox::information(this, "错误", "查询日期错误", QMessageBox::Yes);
        return;
    }
    m_SqlObj.open();
    QString sqlStr;
    if(stopDate == startDate)
    {
        stopDate += " 23:59:59";
        sqlStr = QString("SELECT COUNT(*) FROM PressData WHERE DATE > \'%1\' AND DATE < \'%2\'").arg(startDate).arg(stopDate);
    }
    else
    {
        stopDate += " 00:00:00";
        sqlStr = QString("SELECT COUNT(*) FROM PressData WHERE DATE > \'%1\' AND DATE < \'%2\'").arg(startDate).arg(stopDate);
    }
    startDate += " 00:00:00";
    QSqlQuery sqlQuery(m_SqlObj);
    sqlQuery.prepare(sqlStr);
    sqlQuery.exec(sqlStr);
    sqlQuery.next();
    m_TotalNum = sqlQuery.value(0).toInt();
    m_TotalPage = m_TotalNum / 20 + 1;
    m_CurrentPage = 1;
    if(m_TotalNum <= 0)
    {
        m_SqlObj.close();
        return;
    }
    else if(m_TotalNum < 20)
    {
        sqlStr = QString("SELECT * FROM PressData WHERE DATE > \'%1\' AND DATE < \'%2\'").arg(startDate).arg(stopDate);
    }
    else
    {
        sqlStr = QString("SELECT * FROM PressData WHERE DATE > \'%1\' AND DATE < \'%2\'").arg(startDate).arg(stopDate);
        sqlStr += " LIMIT 20";
    }
    excuteSql(sqlStr);
    pageChanged(m_CurrentPage, m_TotalPage);
    m_SqlObj.close();
}

void DataDialog::on_resetBtn_clicked()
{
    QDateTime dateTime= QDateTime::currentDateTime();
    ui->startTE->setDate(dateTime.date());
    ui->stopTE->setDate(dateTime.date());
    ui->tableView->clearSpans();
    ui->currPageLab->setText(QString("当前页 %1").arg(0));
    ui->totalPageLab->setText(QString("总页数 %1").arg(0));
    m_TotalPage = 0;
    m_CurrentPage = 0;
}

void DataDialog::on_firstPageBtn_clicked()
{
    on_queryBtn_clicked();
}

void DataDialog::on_prePageBtn_clicked()
{
    QString startDate = ui->startTE->date().toString("yyyy-MM-dd");
    QString stopDate = ui->stopTE->date().toString("yyyy-MM-dd");
    if(stopDate < startDate)
    {
        QMessageBox::information(this, "错误", "查询日期错误", QMessageBox::Yes);
        return;
    }
    ui->tableView->clearSpans();
    m_SqlObj.open();
    QString sqlStr;
    if(stopDate == startDate)
    {
        stopDate += " 23:59:59";
        sqlStr = QString("SELECT COUNT(*) FROM PressData WHERE DATE > \'%1\' AND DATE < \'%2\'").arg(startDate).arg(stopDate);
    }
    else
    {
        stopDate += " 00:00:00";
        sqlStr = QString("SELECT COUNT(*) FROM PressData WHERE DATE > \'%1\' AND DATE < \'%2\'").arg(startDate).arg(stopDate);
    }
    startDate += " 00:00:00";
    QSqlQuery sqlQuery(m_SqlObj);
    sqlQuery.prepare(sqlStr);
    sqlQuery.exec(sqlStr);
    sqlQuery.next();
    m_TotalNum = sqlQuery.value(0).toInt();
    m_TotalPage = m_TotalNum / 20 + 1;
    m_CurrentPage -= 1;

    sqlStr = QString("SELECT * FROM PressData WHERE DATE > \'%1\' AND DATE < \'%2\' ORDER BY ID ASC LIMIT %3,%4")
            .arg(startDate).arg(stopDate).arg(m_CurrentPage * PAGE_DATANUM - PAGE_DATANUM).arg(PAGE_DATANUM);
    excuteSql(sqlStr);
    pageChanged(m_CurrentPage, m_TotalPage);
    m_SqlObj.close();
}

void DataDialog::on_nextPageBtn_clicked()
{
    QString startDate = ui->startTE->date().toString("yyyy-MM-dd");
    QString stopDate = ui->stopTE->date().toString("yyyy-MM-dd");
    if(stopDate < startDate)
    {
        QMessageBox::information(this, "错误", "查询日期错误", QMessageBox::Yes);
        return;
    }
    ui->tableView->clearSpans();
    m_SqlObj.open();
    QString sqlStr;
    if(stopDate == startDate)
    {
        stopDate += " 23:59:59";
        sqlStr = QString("SELECT COUNT(*) FROM PressData WHERE DATE > \'%1\' AND DATE < \'%2\'").arg(startDate).arg(stopDate);
    }
    else
    {
        stopDate += " 00:00:00";
        sqlStr = QString("SELECT COUNT(*) FROM PressData WHERE DATE > \'%1\' AND DATE < \'%2\'").arg(startDate).arg(stopDate);
    }
    startDate += " 00:00:00";
    QSqlQuery sqlQuery(m_SqlObj);
    sqlQuery.prepare(sqlStr);
    sqlQuery.exec(sqlStr);
    sqlQuery.next();
    m_TotalNum = sqlQuery.value(0).toInt();
    m_TotalPage = m_TotalNum / 20 + 1;
    m_CurrentPage += 1;

    sqlStr = QString("SELECT * FROM PressData WHERE DATE > \'%1\' AND DATE < \'%2\' ORDER BY ID ASC LIMIT %3,%4")
            .arg(startDate).arg(stopDate).arg((m_CurrentPage - 1) * PAGE_DATANUM).arg(PAGE_DATANUM);
    excuteSql(sqlStr);
    pageChanged(m_CurrentPage, m_TotalPage);
    m_SqlObj.close();
}

void DataDialog::on_lastPageBtn_clicked()
{
    QString startDate = ui->startTE->date().toString("yyyy-MM-dd");
    QString stopDate = ui->stopTE->date().toString("yyyy-MM-dd");
    if(stopDate < startDate)
    {
        QMessageBox::information(this, "错误", "查询日期错误", QMessageBox::Yes);
        return;
    }
    ui->tableView->clearSpans();
    m_SqlObj.open();
    QString sqlStr;
    if(stopDate == startDate)
    {
        stopDate += " 23:59:59";
        sqlStr = QString("SELECT COUNT(*) FROM PressData WHERE DATE > \'%1\' AND DATE < \'%2\'").arg(startDate).arg(stopDate);
    }
    else
    {
        stopDate += " 00:00:00";
        sqlStr = QString("SELECT COUNT(*) FROM PressData WHERE DATE > \'%1\' AND DATE < \'%2\'").arg(startDate).arg(stopDate);
    }
    startDate += " 00:00:00";
    QSqlQuery sqlQuery(m_SqlObj);
    sqlQuery.prepare(sqlStr);
    sqlQuery.exec(sqlStr);
    sqlQuery.next();
    m_TotalNum = sqlQuery.value(0).toInt();
    m_TotalPage = m_TotalNum / 20 + 1;
    m_CurrentPage = m_TotalPage;

    sqlStr = QString("SELECT * FROM PressData WHERE DATE > \'%1\' AND DATE < \'%2\' ORDER BY ID ASC LIMIT %3,%4")
            .arg(startDate).arg(stopDate).arg((m_TotalPage - 1) * PAGE_DATANUM).arg(PAGE_DATANUM);
    excuteSql(sqlStr);
    pageChanged(m_CurrentPage, m_TotalPage);
    m_SqlObj.close();
}

void DataDialog::on_closeBtn_clicked(QAbstractButton *button)
{

    emit SigClose();
}

void DataDialog::on_exportBtn_clicked()
{
    ui->exportBtn->setEnabled(false);
    QString startDate = ui->startTE->date().toString("yyyy-MM-dd");
    QString stopDate = ui->stopTE->date().toString("yyyy-MM-dd");

    if(stopDate < startDate)
    {
        QMessageBox::information(this, "错误", "查询日期错误", QMessageBox::Yes);
        return;
    }
    QString sqlStr;
    if(stopDate == startDate)
    {
        startDate += " 00:00:00";
        stopDate += " 23:59:59";
        sqlStr = QString("SELECT * FROM PressData WHERE DATE > '%1' AND DATE < '%2'").arg(startDate).arg(stopDate);
    }
    else
    {
        startDate += " 00:00:00";
        stopDate += " 00:00:00";
        sqlStr = QString("SELECT * FROM PressData WHERE DATE > '%1' AND DATE < '%2'").arg(startDate).arg(stopDate);
    }

    QDir dir;
    if(!dir.exists("data"))
        dir.mkdir("data");
    m_taskObj = new Task();
    connect(m_taskObj, &Task::SigTaskOver, this, &DataDialog::SlotTaskOver, Qt::QueuedConnection);
    QThreadPool::globalInstance()->setMaxThreadCount(10);
    m_TaskDialog = new TaskDialog();
    m_TaskTimer = new QTimer();
    m_TimeTick = 0;
    connect(m_TaskTimer, &QTimer::timeout, this, &DataDialog::SlotTimeOver);
    m_TaskTimer->setInterval(1000);
    m_TaskTimer->start();
    m_taskObj->setSql(sqlStr);
    QThreadPool::globalInstance()->start(m_taskObj);
    m_TaskDialog->exec();
}

void DataDialog::on_jumpToBtn_clicked()
{
    int jumpPage = ui->currPageBtn->text().toUInt();
    if(jumpPage <= 0 || jumpPage > m_TotalPage)
        return;
    if(jumpPage == m_CurrentPage)
        return;
    QString startDate = ui->startTE->date().toString("yyyy-MM-dd");
    QString stopDate = ui->stopTE->date().toString("yyyy-MM-dd");
    if(stopDate < startDate)
    {
        QMessageBox::information(this, "错误", "查询日期错误", QMessageBox::Yes);
        return;
    }
    ui->tableView->clearSpans();
    m_SqlObj.open();
    QString sqlStr;
    if(stopDate == startDate)
    {
        stopDate += " 23:59:59";
        sqlStr = QString("SELECT COUNT(*) FROM PressData WHERE DATE > \'%1\' AND DATE < \'%2\'").arg(startDate).arg(stopDate);
    }
    else
    {
        stopDate += " 00:00:00";
        sqlStr = QString("SELECT COUNT(*) FROM PressData WHERE DATE > \'%1\' AND DATE < \'%2\'").arg(startDate).arg(stopDate);
    }
    startDate += " 00:00:00";
    QSqlQuery sqlQuery(m_SqlObj);
    sqlQuery.prepare(sqlStr);
    sqlQuery.exec(sqlStr);
    sqlQuery.next();
    m_TotalNum = sqlQuery.value(0).toInt();
    m_TotalPage = m_TotalNum / 20 + 1;
    m_CurrentPage = m_TotalPage;

    sqlStr = QString("SELECT * FROM PressData WHERE DATE > \'%1\' AND DATE < \'%2\' ORDER BY ID ASC LIMIT %3,%4")
            .arg(startDate).arg(stopDate).arg((jumpPage - 1) * PAGE_DATANUM).arg(PAGE_DATANUM);
    excuteSql(sqlStr);
    pageChanged(m_CurrentPage, m_TotalPage);
    m_SqlObj.close();
}

void DataDialog::excuteSql(const QString &p_sql)
{
    QSqlQueryModel *sqlMode = new QSqlQueryModel(this);
    sqlMode->setQuery(p_sql);
    ui->tableView->setModel(sqlMode);
}

void DataDialog::pageChanged(int curr, int total)
{
    if(total == 1)
    {
        ui->firstPageBtn->setEnabled(false);
        ui->prePageBtn->setEnabled(false);
        ui->lastPageBtn->setEnabled(false);
        ui->nextPageBtn->setEnabled(false);
        ui->jumpToBtn->setEnabled(false);
    }
    else if(curr == 1)
    {
        ui->firstPageBtn->setEnabled(false);
        ui->prePageBtn->setEnabled(false);
        ui->lastPageBtn->setEnabled(true);
        ui->nextPageBtn->setEnabled(true);
        ui->jumpToBtn->setEnabled(true);
    }
    else if(curr == total)
    {
        ui->firstPageBtn->setEnabled(true);
        ui->prePageBtn->setEnabled(true);
        ui->lastPageBtn->setEnabled(false);
        ui->nextPageBtn->setEnabled(false);
        ui->jumpToBtn->setEnabled(true);
    }
    else
    {
        ui->firstPageBtn->setEnabled(true);
        ui->prePageBtn->setEnabled(true);
        ui->lastPageBtn->setEnabled(true);
        ui->nextPageBtn->setEnabled(true);
        ui->jumpToBtn->setEnabled(true);
    }
    ui->currPageLab->setText(QString("当前页 %1").arg(curr));
    ui->totalPageLab->setText(QString("总页数 %1").arg(total));
}
