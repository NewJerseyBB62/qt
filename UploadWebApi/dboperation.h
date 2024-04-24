#ifndef DBOPERATION_H
#define DBOPERATION_H

#include <QObject>
#include <QSqlDatabase>
#include "common.h"


class dbOperation : public QObject
{
    Q_OBJECT
public:
    explicit dbOperation(QObject *parent = nullptr);
    int openDB();
    void closeDB();
    int queryGroupData(QStringList &p_totalData, QList<ChildStruct> *p_childData);
    int updateDB(const QString &p_sql);

signals:

private:
    void loadDatabase();
    void testzzp(QStringList &p_totalData, QList<ChildStruct> *p_childData);

public slots:

private:
    QSqlDatabase m_DbObj;
};

#endif // DBOPERATION_H
