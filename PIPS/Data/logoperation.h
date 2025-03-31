#ifndef LOGOPERATION_H
#define LOGOPERATION_H

#include "Common/commontest.h"

class LogOperation
{
public:
    static LogOperation *getLogInstance();
    static void closeLogInstance();

    void readLog(const int p_page, QList<LogData> &p_log);
    void writeLog(const LogData &p_log);
    void clearLog();

private:
    LogOperation();
};

#endif // LOGOPERATION_H
