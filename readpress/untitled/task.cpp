#include "task.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QThread>

Task::Task(const QString &p_str, QObject *parent)
{
    m_Sqlstr = p_str;
    m_Run = true;
}

void Task::stopTask()
{
    m_Run = false;
    QThread::msleep(20);
}

void Task::run()
{
    int i;
    QString csvName = "./data/" + QDateTime::currentDateTime().toString("yyyyMMddhhmmss") + ".csv";
    QFile csvfile(csvName);
    csvfile.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&csvfile);
    QSqlQuery sqlQuery;
    sqlQuery.prepare(m_Sqlstr);
    sqlQuery.exec(m_Sqlstr);
    out<<tr("序号,")<<tr("日期,")<<tr("气压上限,")<<tr("气压下限,")<<tr("气压值,")<<tr("补偿值,")<<tr("状态\n");
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
    csvfile.close();
}
