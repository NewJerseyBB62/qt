#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QThread>
#include <QMutex>
#include <QDateTime>
#include <QSqlQuery>

typedef struct SqlStruct{
    float pressVal;
    float pressMax;
    float pressMin;
    float pressComp;
    QString testDate;
}SqlData;

class Database : public QThread
{
    Q_OBJECT
public:
    Database(int p_timedis);
    ~Database();
    int executeSql(QString p_sql);
    int querySql(QString p_sql);
    int startDBThread();
    int stopDBThread();

public slots:
    void GetTestData(const SqlData &p_data);
    void GetSaveTime(const int &p_time);

protected:
    void run() override;

private:
    int CreateTable();

private:
    QSqlDatabase m_SqlObj;
    QSqlQuery *m_SqlQuery;
    SqlData m_Data;
    QMutex m_Mutex;
    qint64 m_LastSaveTime;
    qint64 m_SaveDistance;
    bool m_ThreadRun;

};

#endif // DATABASE_H
