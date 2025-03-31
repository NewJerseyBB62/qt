#include "logoperation.h"
#include "Data/dboperation.h"

static LogOperation *gInstance = nullptr;

LogOperation *LogOperation::getLogInstance()
{
    if(gInstance == nullptr)
    {
        gInstance = new LogOperation();
    }
    return gInstance;
}

void LogOperation::closeLogInstance()
{
    if(gInstance == nullptr)
        return;
    //gInstance->deleteLater();
    delete gInstance;
    gInstance = nullptr;
}

void LogOperation::readLog(const int p_page, QList<LogData> &p_log)
{
    dbOperation dbObj;
    dbObj.LogRead(p_page, p_log);
}

void LogOperation::writeLog(const LogData &p_log)
{
    dbOperation dbObj;
    dbObj.LogWrite(p_log);
}

void LogOperation::clearLog()
{
    dbOperation dbObj;
    dbObj.LogClear();
}

LogOperation::LogOperation()
{

}
