#include "task.h"
#include <QSqlError>
#include <QSqlQuery>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QThread>

Task::Task(QObject *parent)
{

    m_Run = true;

    if(QSqlDatabase::contains("qt_sql_default_connection"))
        m_SqlObj = QSqlDatabase::database("qt_sql_default_connection");
    else
        m_SqlObj = QSqlDatabase::addDatabase("QSQLITE");
    m_SqlObj.setDatabaseName("./db/MyDataBase.db");
    if(!m_SqlObj.open())
    {
        emit SigTaskOver();
        return;
    }
    m_SqlObj.close();
}

void Task::setSql(const QString &p_str)
{
    m_Sqlstr = p_str;
}

void Task::stopTask()
{
    m_Run = false;
    m_SqlObj.close();
    QThread::msleep(20);
}

void Task::run()
{
    int i = 1;
    m_SqlObj.open();
    QString csvName = "./data/" + QDateTime::currentDateTime().toString("yyyyMMddhhmmss") + ".csv";
    QFile csvfile(csvName);
    csvfile.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&csvfile);
    QSqlQuery sqlQuery(m_SqlObj);
    sqlQuery.prepare(m_Sqlstr);
    sqlQuery.exec(m_Sqlstr);
    out<<tr("序号,")<<tr("日期,")<<tr("压力上限,")<<tr("压力下限,")<<tr("压力值,")<<tr("补偿值,")<<tr("状态\n");
    csvfile.flush();
    while(m_Run && sqlQuery.next())
    {

        out << QString::number(i++) + "," << sqlQuery.value(1).toString() + "," << sqlQuery.value(2).toString() + ","
            << sqlQuery.value(3).toString() + "," << sqlQuery.value(4).toString() + "," << sqlQuery.value(5).toString() + ","
            << tr(sqlQuery.value(6).toString().toStdString().c_str()) << "\n";
        //含中文字符的要用tr包裹，否则乱码，元素(单元格)之间用逗号分隔，用\n换行
        csvfile.flush();
        QThread::msleep(10);
    }
    if(!sqlQuery.next())
        emit SigTaskOver();
    m_SqlObj.close();
    csvfile.close();
}
