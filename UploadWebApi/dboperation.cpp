#include "dboperation.h"
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>

dbOperation::dbOperation(QObject *parent) : QObject(parent)
{
    loadDatabase();
}

int dbOperation::openDB()
{
    if(m_DbObj.isOpen())
        return 0;
    if(m_DbObj.open())
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void dbOperation::closeDB()
{
    m_DbObj.close();
}

int dbOperation::queryGroupData(QStringList &p_totalData, QList<ChildStruct> *p_childData)
{
    testzzp(p_totalData, p_childData);
    return 0;
    QSqlQuery queryObj(m_DbObj);
    QString strSql("SELECT TOP 1 * FROM TestInfoBaseSerialNoMES WHERE SERVEROK = -1;");
    if(!queryObj.exec(strSql))
        return 1;
    int i = 0;
    if(!queryObj.next())
        return 1;
    while(i < 22)
    {
        p_totalData.append(queryObj.value(i++).toString());
    }
    strSql = QString("SELECT * FROM TestConditionResultMES WHERE SerialNo = '%1' AND Flag = %2;").arg(
                p_totalData.at(0)).arg(QString(p_totalData.at(19)).toInt());
    queryObj.exec(strSql);
    while(queryObj.next())
    {
        i = 0;
        ChildStruct childData;
        childData.testName = queryObj.value(i++).toString();
        childData.testSet = queryObj.value(i++).toFloat();
        childData.testSetUnit = queryObj.value(i++).toString();
        childData.testVal = queryObj.value(i++).toFloat();
        childData.testValUnit = queryObj.value(i++).toString();
        childData.testTime = queryObj.value(i++).toFloat();
        childData.testWaitTime = queryObj.value(i++).toFloat();
        childData.testResult = queryObj.value(i++).toInt();
        p_childData->append(childData);
    }
    return 0;
}

int dbOperation::updateDB(const QString &p_sql)
{
    QSqlQuery queryObj(m_DbObj);
    if(queryObj.exec(p_sql))
        return 0;
    else
        return 1;
}

void dbOperation::loadDatabase()
{
    m_DbObj = QSqlDatabase::addDatabase("QODBC");
    m_DbObj.setHostName("localhost");
    m_DbObj.setDatabaseName("DRIVER={SQL Server};SERVER=(local);UID=;PWD=;DATABASE=test_empty;");
}

void dbOperation::testzzp(QStringList &p_totalData, QList<ChildStruct> *p_childData)
{
    int i = 0;
    while(i < 22)
    {
        p_totalData.append(QString::number(i++));
    }
    i = 0;
    while(i < 4)
    {
        ChildStruct childData;
        childData.testName = "1";
        childData.testSet = 10.5;
        childData.testSetUnit = "V";
        childData.testVal = 100.1;
        childData.testValUnit = "mA";
        childData.testTime = 10.5;
        childData.testWaitTime = 1;
        childData.testResult = 1;
        p_childData->append(childData);
        i++;
    }
    return;
}
