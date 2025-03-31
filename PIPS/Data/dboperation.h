#ifndef DBOPERATION_H
#define DBOPERATION_H

#include <QDir>
#include <Common/commontest.h>

enum DB_TABLE{
    ENM_TABLE_GENERAL = 0,
    ENM_TABLE_STEPLADDER,
    ENM_TABLE_STEP,
    ENM_TABLE_GRADIENT,
    ENM_TABLE_THROUGH,
    ENM_TABLE_HARMONICS,
    ENM_TABLE_LOG,
    ENM_TABLE_ERROR,
    ENM_TABLE_MAX
};

class dbOperation
{
public:
    dbOperation();
    int initDB();
    int GeneralRead(GeneralData &p_data);
    int GeneralWrite(const GeneralData &p_data);
    int StepLadderRead(StepLadderData &p_data);
    int StepLadderWrite(const StepLadderData &p_data);
    int StepRead(const int p_outputmode, QList<StepData> &p_data);
    int StepWrite(const QList<StepData> &p_data);
    int GradientRead(const int p_outputmode, QList<GradientData> &p_data);
    int GradientWrite(const QList<GradientData> &p_data);
    int ThroughRead(const int p_outputmode, QList<ThroughData> &p_data);
    int ThroughWrite(const QList<ThroughData> &p_data);
    int HarmonicsRead(const int p_group, QList<HarmonicsData> &p_data);
    int HarmonicsReadAll(QList<HarmonicsGroupData> &p_data);
    int HarmonicsWrite(const int p_group, const QList<HarmonicsData> &p_data);
    int LogRead(const int p_page, QList<LogData> &p_log);
    int LogWrite(const LogData &p_log);
    int LogClear();

private:
    int checkDBStatus();
    int createDB(const bool p_check, const QDir &p_dir);
    QString createTable(const int p_table);
    QString initTable(const int p_step, const int p_table);

};

#endif // DBOPERATION_H
