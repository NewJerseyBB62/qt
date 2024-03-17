#include "database.h"
#include <QDir>
#include <QSqlError>
#include <QDateTime>
#include <QFileInfo>
#include <QDebug>

Database::Database(int p_timedis):
    m_SaveDistance(p_timedis)
  , m_SqlQuery(nullptr)
  , m_LastSaveTime(0)
  , m_ThreadRun(true)

{
    QDateTime dateTime= QDateTime::currentDateTime();
    QDir dir(QDir::currentPath());
    if(!dir.exists("db"))
        dir.mkdir("db");
    dir.cd("./db");
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        m_SqlObj = QSqlDatabase::database("qt_sql_default_connection");
    else
        m_SqlObj = QSqlDatabase::addDatabase("QSQLITE");
    m_SqlObj.setDatabaseName("./db/MyDataBase.db");
    if(m_SqlObj.open())
    {
        QSqlQuery sqlQuery;
        QString sqlStr = "SELECT * FROM PressData";
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
    else
        return;
    m_SqlQuery = new QSqlQuery(m_SqlObj);
}

Database::~Database()
{
    if(this->isRunning())
    {
        m_ThreadRun = false;
        this->quit();
        this->wait();
    }
    if(m_SqlQuery != nullptr)
    {
        delete m_SqlQuery;
        m_SqlQuery = nullptr;
    }
    m_SqlObj.close();
}

int Database::executeSql(QString p_sql)
{
    return 0;
}

int Database::querySql(QString p_sql)
{
    return 0;
}

int Database::startDBThread()
{
    if(m_SqlQuery == nullptr)
        return -1;
    m_ThreadRun = true;
    this->start();
    return 0;
}

int Database::stopDBThread()
{
    m_ThreadRun = false;
    this->quit();
    this->wait();
    return 0;
}

void Database::GetTestData(const SqlData &p_data)
{
    m_Mutex.lock();
    m_Data = p_data;
    m_Mutex.unlock();
}

void Database::GetSaveTime(const int &p_time)
{
    m_SaveDistance = p_time;
}

void Database::run()
{
    QString sqlString;
    QString pressState;
    qint64 currentTime;
    QDateTime datetime;
    while(m_ThreadRun)
    {
        if(!m_SqlObj.isOpen())
            m_SqlObj.open();
        if(m_Data.testDate.length() <= 0)
        {
            msleep(500);
            continue;
        }
        currentTime = datetime.fromString(m_Data.testDate, "yyyy-MM-dd hh:mm:ss").toTime_t();
        if(m_LastSaveTime == 0 || currentTime - m_LastSaveTime >= m_SaveDistance)
        {

            m_Mutex.lock();
            if(m_Data.pressVal <= m_Data.pressMin)
                pressState = "压力过低";
            else if(m_Data.pressVal >= m_Data.pressMax)
                pressState = "压力过高";
            else
                pressState = "压力正常";
            //
            sqlString = QString("INSERT INTO PressData (DATE, MAX, MIN, PRESS, COMP, STATE)"
                        "VALUES ('%1', %2, %3, %4, %5, \'%6\');")
                        .arg(m_Data.testDate).arg(m_Data.pressMax).arg(m_Data.pressMin)
                        .arg(m_Data.pressVal).arg(m_Data.pressComp).arg(pressState);
            m_Mutex.unlock();
            m_LastSaveTime = currentTime;
            if(m_SqlQuery == nullptr)
            {
                msleep(1000);
                continue;
            }
            m_SqlQuery->prepare(sqlString);
            bool ret = m_SqlQuery->exec(sqlString);
            qDebug() << ret << " sql " << sqlString;
        }
        msleep(500);
        m_SqlObj.close();
    }
}

int Database::CreateTable()
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
              STATE     char(16)  NULL              \
            );";
    query.prepare(creatTableStr);
    if(!query.exec())
    {
        return 1;
    }
    return 0;
}
