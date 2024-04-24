#ifndef DBOPERATION_H
#define DBOPERATION_H

#include <QSqlDatabase>
#include <QSqlQuery>

class DbOperation
{
public:
    DbOperation();
    void openDb(const QString &p_dbname);
    void initDb(const QString &p_tablename);

private:
    int createTable(const QString &p_tablenam);

private:
    QSqlDatabase m_SqlObj;
    QSqlQuery *m_SqlQuery;
};

#endif // DBOPERATION_H
