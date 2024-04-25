#include "dboperation.h"
#include <QDir>
#include <QVariant>

DbOperation::DbOperation()
{
    m_SqlQuery = nullptr;
}

DbOperation::~DbOperation()
{
    if(m_SqlObj.isOpen())
        m_SqlObj.close();
    if(m_SqlQuery != nullptr)
        delete m_SqlQuery;
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
        if(createTable("TestParameter") != 0)
        {
            m_SqlObj.close();
            return;
        }
    }
}

void DbOperation::closeDb()
{
    if(m_SqlObj.isOpen())
        m_SqlObj.close();
}

void DbOperation::setTestParamTable(DB_OPERATION p_type, QList<bool> *p_val, QSqlQuery *p_query)
{
    QString sqlStr;
    QSqlQuery sqlQuery(m_SqlObj);
    int i = 0;
    if(p_type == DB_OPERATION::ENM_DB_INSERT)
    {
        sqlStr = "SELECT COUNT(*) FROM TestParameter";
        sqlQuery.prepare(sqlStr);
        sqlQuery.exec();
        if(sqlQuery.next())
        {
            if(sqlQuery.value(0).toInt() == 0)
            {
                sqlStr = QString("INSERT INTO TestParameter(Voltage, Current, ActivePower, ReactivePower, ApparentPower, PowerFactor, Angles, Frequency, PositiveVoltagePeak, NegativeVoltagePeak, \
                        PositivPeakCurrent, NegativPeakCurrent, PositivPeakPower, NegativPeakPower, ElectricEnergyTiming, ElectricEnergyOverTiming, PositiveElectricEnergy, NegativeElectricEnergy, \
                        ElectricEnergy, CurrentIntegral, PositiveCurrentIntegral, NegativeCurrentIntegral) \
                        VALUES (%1, %2, %3, %4, %5, %6, %7, %8, %9, %10, %11, %12, %13, %14, %15, %16, %17, %18, %19, %20, %21, %22)").arg(p_val->at(i++)).arg(p_val->at(i++)).arg(p_val->at(i++)).
                        arg(p_val->at(i++)).arg(p_val->at(i++)).arg(p_val->at(i++)).arg(p_val->at(i++)).arg(p_val->at(i++)).arg(p_val->at(i++)).arg(p_val->at(i++)).arg(p_val->at(i++)).arg(p_val->at(i++)).
                        arg(p_val->at(i++)).arg(p_val->at(i++)).arg(p_val->at(i++)).arg(p_val->at(i++)).arg(p_val->at(i++)).arg(p_val->at(i++)).arg(p_val->at(i++)).arg(p_val->at(i++)).arg(p_val->at(i++)).arg(p_val->at(i++));
                sqlQuery.prepare(sqlStr);
                sqlQuery.exec();
            }
            else
            {
                setTestParamTable(DB_OPERATION::ENM_DB_UPDATE, p_val, nullptr);
            }
        }
    }
    else if(p_type == DB_OPERATION::ENM_DB_SELECT)
    {
        i = 1;
        sqlStr = "SELECT * FROM TestParameter";
        sqlQuery.prepare(sqlStr);
        sqlQuery.exec();
        if(sqlQuery.next())
        {
            p_val->clear();
            while(i <= 22)
            {
               p_val->append(sqlQuery.value(i).toInt() == 1 ? true : false);
               i++;
            }
        }
    }
    else if(p_type == DB_OPERATION::ENM_DB_UPDATE)
    {
        i = 0;
        sqlStr = QString("UPDATE TestParameter SET Voltage = %1, Current = %2, ActivePower = %3, ReactivePower = %4, ApparentPower = %5, PowerFactor = %6, Angles = %7, Frequency = %8, PositiveVoltagePeak = %9, \
                        NegativeVoltagePeak = %10, PositivPeakCurrent = %11, NegativPeakCurrent = %12, PositivPeakPower = %13, NegativPeakPower = %14, ElectricEnergyTiming = %15, ElectricEnergyOverTiming = %16, \
                        PositiveElectricEnergy = %17, NegativeElectricEnergy = %18, ElectricEnergy = %19, CurrentIntegral = %20, PositiveCurrentIntegral = %21, NegativeCurrentIntegral = %22").
                arg(p_val->at(i++)).arg(p_val->at(i++)).arg(p_val->at(i++)).arg(p_val->at(i++)).arg(p_val->at(i++)).arg(p_val->at(i++)).arg(p_val->at(i++)).arg(p_val->at(i++)).arg(p_val->at(i++)).
                arg(p_val->at(i++)).arg(p_val->at(i++)).arg(p_val->at(i++)).arg(p_val->at(i++)).arg(p_val->at(i++)).arg(p_val->at(i++)).arg(p_val->at(i++)).arg(p_val->at(i++)).arg(p_val->at(i++)).arg(p_val->at(i++));
        sqlQuery.prepare(sqlStr);
        sqlQuery.exec();
    }
    else if(p_type == DB_OPERATION::ENM_DB_DELETE)
    {

    }
}

int DbOperation::createTable(const QString &p_tablenam)
{
    if(p_tablenam == "TestParameter")
    {
        QSqlQuery query;
        QString creatTableStr = QString("CREATE TABLE %1 \
                (                                       \
                  ID        INTEGER   PRIMARY KEY AUTOINCREMENT  NOT NULL,     \
                  Voltage           INTEGER NOT NULL ,        \
                  Current           INTEGER NOT NULL ,               \
                  ActivePower       INTEGER NOT NULL ,               \
                  ReactivePower     INTEGER NOT NULL ,               \
                  ApparentPower     INTEGER NOT NULL ,               \
                  PowerFactor       INTEGER NOT NULL ,               \
                  Angles            INTEGER NOT NULL ,               \
                  Frequency         INTEGER NOT NULL ,               \
                  PositiveVoltagePeak               INTEGER NOT NULL ,               \
                  NegativeVoltagePeak               INTEGER NOT NULL ,               \
                  PositivPeakCurrent                INTEGER NOT NULL ,               \
                  NegativPeakCurrent                INTEGER NOT NULL ,               \
                  PositivPeakPower                  INTEGER NOT NULL ,               \
                  NegativPeakPower                  INTEGER NOT NULL ,               \
                  ElectricEnergyTiming              INTEGER NOT NULL ,               \
                  ElectricEnergyOverTiming          INTEGER NOT NULL ,               \
                  PositiveElectricEnergy            INTEGER NOT NULL ,               \
                  NegativeElectricEnergy            INTEGER NOT NULL ,               \
                  ElectricEnergy                    INTEGER NOT NULL ,               \
                  CurrentIntegral                   INTEGER NOT NULL ,               \
                  PositiveCurrentIntegral           INTEGER NOT NULL ,               \
                  NegativeCurrentIntegral           INTEGER NOT NULL               \
                );").arg(p_tablenam);
        query.prepare(creatTableStr);
        if(!query.exec())
        {
            return 1;
        }
    }
    return 0;
}


