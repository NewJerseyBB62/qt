#ifndef DBOPERATION_H
#define DBOPERATION_H

#include <QSqlDatabase>
#include <QSqlQuery>

enum class DB_OPERATION{
    ENM_DB_UNKNOWN = 0,
    ENM_DB_INSERT,
    ENM_DB_SELECT,
    ENM_DB_UPDATE,
    ENM_DB_DELETE
};

class DbOperation
{
public:
    DbOperation();
    ~DbOperation();
    void openDb(const QString &p_dbname);
    void initDb(const QString &p_tablename);
    void closeDb();
    void setTestParamTable(DB_OPERATION p_type, QList<bool>* p_val, QSqlQuery *p_query);

private:
    int createTable(const QString &p_tablenam);

private:
    QSqlDatabase m_SqlObj;
    QSqlQuery *m_SqlQuery;
};

#endif // DBOPERATION_H
