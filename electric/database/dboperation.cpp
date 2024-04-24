#include "dboperation.h"
#include <QDir>

DbOperation::DbOperation()
{
    m_SqlQuery = nullptr;
}

void DbOperation::openDb(const QString &p_dbname)
{
    QDir dir(QDir::currentPath());
    if(!dir.exists("db"))
        dir.mkdir("db");
    dir.cd("./db");
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        m_SqlObj = QSqlDatabase::database("qt_sql_default_connection");
    else
        m_SqlObj = QSqlDatabase::addDatabase("QSQLITE");
    m_SqlObj.setDatabaseName("./db/" + p_dbname);
    if(m_SqlObj.open())
    {
       m_SqlQuery = new QSqlQuery(m_SqlObj);
    }
    else
        return;
}

void DbOperation::initDb(const QString &p_tablename)
{
    QSqlQuery sqlQuery;
    QString sqlStr = "SELECT * FROM " + p_tablename;
    sqlQuery.prepare(sqlStr);
    if(!sqlQuery.exec())
    {
        if(CreateTable() != 0)
        {
            m_SqlObj.close();
            return;
        }
    }
}

int DbOperation::CreateTable(const QString &p_tablenam)
{
    if(p_tablenam == "TestParameter")
    {
        QSqlQuery query;
        QString creatTableStr = QString("CREATE TABLE %1 \
                (                                       \
                  ID        INTEGER   PRIMARY KEY AUTOINCREMENT  NOT NULL,     \
                  DATE      datetime  NOT NULL ,        \
                  MAX       float  NULL ,               \
                  MIN       float  NULL ,               \
                  PRESS     float  NULL ,               \
                  COMP      float  NULL ,               \
                  STATE     char(16)  NULL              \
                );").arg(p_tablenam);
        query.prepare(creatTableStr);
        if(!query.exec())
        {
            return 1;
        }
    }
    return 0;
}


