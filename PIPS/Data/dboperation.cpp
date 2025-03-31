#include "dboperation.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QFileInfo>

#define DEF_TABLE_GENERAL QStringLiteral("GeneralTable")
#define DEF_TABLE_STEPLADDER QStringLiteral("StepLadderTable")
#define DEF_TABLE_STEP QStringLiteral("StepTable")
#define DEF_TABLE_GRADIENT QStringLiteral("GradientTable")
#define DEF_TABLE_THROUGH QStringLiteral("ThroughTable")
#define DEF_TABLE_HARMONICS QStringLiteral("HarmonicsTable")
#define DEF_TABLE_LOG QStringLiteral("LogTable")
#define DEF_TABLE_ERROR QStringLiteral("ErrorTable")

void setDB();

void setDB(QSqlDatabase &QSqlObj, const QDir &p_dir)
{
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        QSqlObj = QSqlDatabase::database("qt_sql_default_connection");
    else
        QSqlObj = QSqlDatabase::addDatabase("QSQLITE");
    QString dbPath = p_dir.absolutePath() + "/db/systemdata.db";
    QSqlObj.setDatabaseName(dbPath);
    return;
}

dbOperation::dbOperation()
{

}

int dbOperation::initDB()
{
    return checkDBStatus();
}

int dbOperation::GeneralRead(GeneralData &p_data)
{
    QDir dir(QDir::currentPath());
    QSqlDatabase QSqlObj;
    setDB(QSqlObj, dir);
    if(!QSqlObj.open())
        return 1;
    QSqlQuery sqlQuery(QSqlObj);
    QString strSQL = QString("SELECT * FROM GeneralTable WHERE StepNo = %1 AND OutputMode = %2").
                        arg(p_data.StepNo).arg(p_data.OutputMode);
    sqlQuery.prepare(strSQL);
    if(sqlQuery.exec())
    {
        if(sqlQuery.next())
        {
            int i = 1;
            p_data.VoltageLevel = sqlQuery.value(i++).toInt();
            p_data.OutputMode = sqlQuery.value(i++).toInt();
            p_data.StepNo = sqlQuery.value(i++).toInt();
            p_data.StartTimeU = sqlQuery.value(i++).toFloat();
            p_data.StartTimeV = sqlQuery.value(i++).toFloat();
            p_data.StartTimeW = sqlQuery.value(i++).toFloat();
            p_data.EnableU = sqlQuery.value(i++).toInt();
            p_data.EnableV = sqlQuery.value(i++).toInt();
            p_data.EnableW = sqlQuery.value(i++).toInt();
            p_data.VoltageU = sqlQuery.value(i++).toFloat();
            p_data.VoltageV = sqlQuery.value(i++).toFloat();
            p_data.VoltageW = sqlQuery.value(i++).toFloat();
            p_data.FrequencyU = sqlQuery.value(i++).toFloat();
            p_data.FrequencyV = sqlQuery.value(i++).toFloat();
            p_data.FrequencyW = sqlQuery.value(i++).toFloat();
            p_data.WaveFormU = sqlQuery.value(i++).toInt();
            p_data.WaveFormV = sqlQuery.value(i++).toInt();
            p_data.WaveFormW = sqlQuery.value(i++).toInt();
            p_data.AnglesUV = sqlQuery.value(i++).toFloat();
            p_data.AnglesUW = sqlQuery.value(i++).toFloat();
            p_data.AnglesVW = sqlQuery.value(i++).toFloat();
            QSqlObj.close();
            return 0;
        }
    }
    QSqlObj.close();
    p_data.VoltageLevel = 0;
    p_data.StartTimeU = 0;
    p_data.StartTimeV = 0;
    p_data.StartTimeW = 0;
    p_data.EnableU = 1;
    p_data.EnableV = 1;
    p_data.EnableW = 1;
    p_data.VoltageU = 100;
    p_data.VoltageV = 100;
    p_data.VoltageW = 100;
    p_data.FrequencyU = 50;
    p_data.FrequencyV = 50;
    p_data.FrequencyW = 50;
    p_data.WaveFormU = 0;
    p_data.WaveFormV = 0;
    p_data.WaveFormW = 0;
    p_data.AnglesUV = 120;
    p_data.AnglesUW = 120;
    p_data.AnglesVW = 120;
    return 0;
}

int dbOperation::GeneralWrite(const GeneralData &p_data)
{
    QDir dir(QDir::currentPath());
    QSqlDatabase QSqlObj;
    setDB(QSqlObj, dir);
    if(!QSqlObj.open())
        return 1;
    QSqlQuery sqlQuery(QSqlObj);
    QString strSQL = QString("DELETE FROM GeneralTable WHERE StepNo = %1 AND OutputMode = %2")
            .arg(p_data.StepNo).arg(p_data.OutputMode);
    sqlQuery.prepare(strSQL);
    sqlQuery.exec();
    QString strData;
    QSqlQuery sqlDataQuery(QSqlObj);
#if 0
            strData = QString("UPDATE GeneralTable SET VoltageLevel = %1, OutputMode = %2, StepNo = %3, "    \
                            "StartTimeU = %4, StartTimeV = %5, StartTimeW = %6, EnableU = %7, "   \
                            "EnableV = %8, EnableW = %9, VoltageU = %10, VoltageV = %11, VoltageW = %12, " \
                            "FrequencyU = %13, FrequencyV = %14, FrequencyW = %15, WaveFormU = %16, "  \
                            "WaveFormV = %17, WaveFormW = %18, AnglesUV = %19, AnglesUW = %20, AnglesVW = %21)").
                    arg(p_data.VoltageLevel).
                    arg(p_data.OutputMode).arg(p_data.StepNo).arg(p_data.StartTimeU).arg(p_data.StartTimeV).
                    arg(p_data.StartTimeW).arg(p_data.EnableU).arg(p_data.EnableV).arg(p_data.EnableW).arg(p_data.VoltageU).
                    arg(p_data.VoltageV).arg(p_data.VoltageW).arg(p_data.FrequencyU).arg(p_data.FrequencyV).
                    arg(p_data.FrequencyW).arg(p_data.WaveFormU).arg(p_data.WaveFormV).arg(p_data.WaveFormW).
                    arg(p_data.AnglesUV).arg(p_data.AnglesUW).arg(p_data.AnglesVW);
#endif
    strData = QString("INSERT INTO GeneralTable (VoltageLevel, OutputMode, StepNo, "    \
                            "StartTimeU, StartTimeV, StartTimeW, EnableU, "   \
                            "EnableV, EnableW, VoltageU, VoltageV, VoltageW, " \
                            "FrequencyU, FrequencyV, FrequencyW, WaveFormU, "  \
                            "WaveFormV, WaveFormW, AnglesUV, AnglesUW, AnglesVW) " \
                            "VALUES (%1, %2, %3, %4, %5, %6, %7, %8, %9, %10, %11, %12, %13, %14, "  \
                            "%15, %16, %17, %18, %19, %20, %21)").arg(p_data.VoltageLevel).
                    arg(p_data.OutputMode).arg(p_data.StepNo).arg(p_data.StartTimeU).arg(p_data.StartTimeV).
                    arg(p_data.StartTimeW).arg(p_data.EnableU).arg(p_data.EnableV).arg(p_data.EnableW).arg(p_data.VoltageU).
                    arg(p_data.VoltageV).arg(p_data.VoltageW).arg(p_data.FrequencyU).arg(p_data.FrequencyV).
                    arg(p_data.FrequencyW).arg(p_data.WaveFormU).arg(p_data.WaveFormV).arg(p_data.WaveFormW).
                    arg(p_data.AnglesUV).arg(p_data.AnglesUW).arg(p_data.AnglesVW);

    sqlDataQuery.prepare(strData);
    sqlDataQuery.exec();
    QSqlObj.close();
    return 0;
}

int dbOperation::StepLadderRead(StepLadderData &p_data)
{
    QDir dir(QDir::currentPath());
    QSqlDatabase QSqlObj;
    setDB(QSqlObj, dir);
    if(!QSqlObj.open())
        return 1;
    QSqlQuery sqlQuery(QSqlObj);
    QString strSQL = QString("SELECT * FROM StepLadderTable WHERE OutputMode = %1").
                            arg(p_data.OutputMode);
    sqlQuery.prepare(strSQL);
    if(sqlQuery.exec())
    {
        if(sqlQuery.next())
        {
            int i = 1;
            p_data.OutputMode = sqlQuery.value(i++).toInt();
            p_data.StartVoltageU = sqlQuery.value(i++).toFloat();
            p_data.StartVoltageV = sqlQuery.value(i++).toFloat();
            p_data.StartVoltageW = sqlQuery.value(i++).toFloat();
            p_data.StepVoltageU = sqlQuery.value(i++).toFloat();
            p_data.StepVoltageV = sqlQuery.value(i++).toFloat();
            p_data.StepVoltageW = sqlQuery.value(i++).toFloat();
            p_data.StartFrequencyU = sqlQuery.value(i++).toFloat();
            p_data.StartFrequencyV = sqlQuery.value(i++).toFloat();
            p_data.StartFrequencyW = sqlQuery.value(i++).toFloat();
            p_data.StepFrequencyU = sqlQuery.value(i++).toFloat();
            p_data.StepFrequencyV = sqlQuery.value(i++).toFloat();
            p_data.StepFrequencyW = sqlQuery.value(i++).toFloat();
            p_data.WaveFormU = sqlQuery.value(i++).toInt();
            p_data.WaveFormV = sqlQuery.value(i++).toInt();
            p_data.WaveFormW = sqlQuery.value(i++).toInt();
            p_data.AnglesUV = sqlQuery.value(i++).toFloat();
            p_data.AnglesUW = sqlQuery.value(i++).toFloat();
            p_data.AnglesVW = sqlQuery.value(i++).toFloat();
            p_data.StepTimeU = sqlQuery.value(i++).toFloat();
            p_data.StepTimeV = sqlQuery.value(i++).toFloat();
            p_data.StepTimeW = sqlQuery.value(i++).toFloat();
            p_data.StepCountU = sqlQuery.value(i++).toInt();
            p_data.StepCountV = sqlQuery.value(i++).toInt();
            p_data.StepCountW = sqlQuery.value(i++).toInt();
            QSqlObj.close();
            return 0;
        }
    }
    QSqlObj.close();
    p_data.StartVoltageU = 100;
    p_data.StartVoltageV = 100;
    p_data.StartVoltageW = 100;
    p_data.StepVoltageU = 1;
    p_data.StepVoltageV = 1;
    p_data.StepVoltageW = 1;
    p_data.StartFrequencyU = 50;
    p_data.StartFrequencyV = 50;
    p_data.StartFrequencyW = 50;
    p_data.StepFrequencyU = 1;
    p_data.StepFrequencyV = 1;
    p_data.StepFrequencyW = 1;
    p_data.WaveFormU = 0;
    p_data.WaveFormV = 0;
    p_data.WaveFormW = 0;
    p_data.AnglesUV = 120;
    p_data.AnglesUW = 120;
    p_data.AnglesVW = 120;
    p_data.StepTimeU = 1;
    p_data.StepTimeV = 1;
    p_data.StepTimeW = 1;
    p_data.StepCountU = 1;
    p_data.StepCountV = 1;
    p_data.StepCountW = 1;
    return 0;
}

int dbOperation::StepLadderWrite(const StepLadderData &p_data)
{
    QDir dir(QDir::currentPath());
    QSqlDatabase QSqlObj;
    setDB(QSqlObj, dir);
    if(!QSqlObj.open())
        return 1;
    QSqlQuery sqlQuery(QSqlObj);
    QString strSQL = QString("DELETE * FROM StepLadderTable WHERE OutputMode = %1").arg(p_data.OutputMode);
    sqlQuery.prepare(strSQL);
    sqlQuery.exec();
    QString strData;
    QSqlQuery sqlDataQuery(QSqlObj);
#if 0
            strData = QString("UPDATE StepLadderTable SET OutputMode = %1, StartVoltageU = %2, StartVoltageV = %3, StartVoltageW = %4, "    \
                            "StepVoltageU = %5, StepVoltageV = %6, StepVoltageW = %7, StartFrequencyU = %8, "   \
                            "StartFrequencyV = %9, StartFrequencyW = %10, StepFrequencyU = %11, StepFrequencyV = %12, StepFrequencyW = %13, " \
                            "WaveFormU = %14, WaveFormV = %15, WaveFormW = %16, AnglesUV = %17, "  \
                            "AnglesUW = %18, AnglesVW = %19, StepTimeU = %20, StepTimeV = %21, StepTimeW = %22, "  \
                            "StepCountU = %23, StepCountV = %24, StepCountW = %25)").
                    arg(p_data.OutputMode).arg(p_data.StartVoltageU).
                    arg(p_data.StartVoltageV).arg(p_data.StartVoltageW).arg(p_data.StepVoltageU).arg(p_data.StepVoltageV).
                    arg(p_data.StepVoltageW).arg(p_data.StartFrequencyU).arg(p_data.StartFrequencyV).arg(p_data.StartFrequencyW).arg(p_data.StepFrequencyU).
                    arg(p_data.StepFrequencyV).arg(p_data.StepFrequencyW).arg(p_data.WaveFormU).arg(p_data.WaveFormV).
                    arg(p_data.WaveFormW).arg(p_data.AnglesUV).arg(p_data.AnglesUW).arg(p_data.AnglesVW).
                    arg(p_data.StepTimeU).arg(p_data.StepTimeV).arg(p_data.StepTimeW).arg(p_data.StepCountU).arg(p_data.StepCountV).arg(p_data.StepCountW);
#endif
    strData = QString("INSERT INTO StepLadderTable (OutputMode, StartVoltageU, StartVoltageV, "    \
                        "StartVoltageW, StepVoltageU, StepVoltageV, StepVoltageW, "   \
                        "StartFrequencyU, StartFrequencyV, StartFrequencyW, StepFrequencyU, StepFrequencyV, " \
                        "StepFrequencyW, WaveFormU, WaveFormV, WaveFormW, AnglesUV, AnglesUW, AnglesVW, " \
                        "StepTimeU, StepTimeV, StepTimeW, StepCountU, StepCountV, StepCountW) "  \
                        "VALUES (%1, %2, %3, %4, %5, %6, %7, %8, %9, %10, %11, %12, %13, %14, "  \
                        "%15, %16, %17, %18, %19, %20, %21, %22, %23, %24, %25)").arg(p_data.OutputMode).arg(p_data.StartVoltageU).
                arg(p_data.StartVoltageV).arg(p_data.StartVoltageW).arg(p_data.StepVoltageU).arg(p_data.StepVoltageV).
                arg(p_data.StepVoltageW).arg(p_data.StartFrequencyU).arg(p_data.StartFrequencyV).arg(p_data.StartFrequencyW).arg(p_data.StepFrequencyU).
                arg(p_data.StepFrequencyV).arg(p_data.StepFrequencyW).arg(p_data.WaveFormU).arg(p_data.WaveFormV).
                arg(p_data.WaveFormW).arg(p_data.AnglesUV).arg(p_data.AnglesUW).
                arg(p_data.AnglesVW).arg(p_data.StepTimeU).arg(p_data.StepTimeV).arg(p_data.StepTimeW).
                arg(p_data.StepCountU).arg(p_data.StepCountV).arg(p_data.StepCountW);
    sqlDataQuery.prepare(strData);
    sqlDataQuery.exec();
    QSqlObj.close();
    return 0;
}

int dbOperation::StepRead(const int p_outputmode, QList<StepData> &p_data)
{
    int i = 1;
    QDir dir(QDir::currentPath());
    QSqlDatabase QSqlObj;
    StepData data[100];
    p_data.clear();
    memset(data, 0, sizeof(data));
    while(i <= 100)
    {
        data[i - 1].OutputMode = p_outputmode;
        data[i - 1].StepNo = i;
        data[i - 1].Phase = 0;
        data[i - 1].VoltageU = 100;
        data[i - 1].VoltageV = 100;
        data[i - 1].VoltageW = 100;
        data[i - 1].FrequencyU = 50;
        data[i - 1].FrequencyV = 50;
        data[i - 1].FrequencyW = 50;
        data[i - 1].WaveFormU = 0;
        data[i - 1].WaveFormV = 0;
        data[i - 1].WaveFormW = 0;
        data[i - 1].AnglesUV = 120;
        data[i - 1].AnglesUW = 120;
        data[i - 1].AnglesVW = 120;
        data[i - 1].StepTimeU = 1;
        data[i - 1].StepTimeV = 1;
        data[i - 1].StepTimeW = 1;
        p_data.append(data[i - 1]);
        i++;
    }
    setDB(QSqlObj, dir);
    if(!QSqlObj.open())
        return 1;
    QSqlQuery sqlQuery(QSqlObj);
    QString strSQL = QString("SELECT * FROM StepTable WHERE OutputMode = %1").
                            arg(p_outputmode);
    sqlQuery.prepare(strSQL);
    if(sqlQuery.exec())
    {
        while(sqlQuery.next())
        {
            i = 1;
            int idx = sqlQuery.value(2).toInt() - 1;
            p_data[idx].OutputMode = sqlQuery.value(i++).toInt();
            //data[idx].StepNo = sqlQuery.value(i++).toInt();
            i++;
            p_data[idx].Phase = sqlQuery.value(i++).toInt();
            p_data[idx].VoltageU = sqlQuery.value(i++).toFloat();
            p_data[idx].VoltageV = sqlQuery.value(i++).toFloat();
            p_data[idx].VoltageW = sqlQuery.value(i++).toFloat();
            p_data[idx].FrequencyU = sqlQuery.value(i++).toFloat();
            p_data[idx].FrequencyV = sqlQuery.value(i++).toFloat();
            p_data[idx].FrequencyW = sqlQuery.value(i++).toFloat();
            p_data[idx].WaveFormU = sqlQuery.value(i++).toInt();
            p_data[idx].WaveFormV = sqlQuery.value(i++).toInt();
            p_data[idx].WaveFormW = sqlQuery.value(i++).toInt();
            p_data[idx].AnglesUV = sqlQuery.value(i++).toFloat();
            p_data[idx].AnglesUW = sqlQuery.value(i++).toFloat();
            p_data[idx].AnglesVW = sqlQuery.value(i++).toFloat();
            p_data[idx].StepTimeU = sqlQuery.value(i++).toFloat();
            p_data[idx].StepTimeV = sqlQuery.value(i++).toFloat();
            p_data[idx].StepTimeW = sqlQuery.value(i++).toFloat();
        }
    }
    sqlQuery.finish();
    QSqlObj.close();
    return 0;
}

int dbOperation::StepWrite(const QList<StepData> &p_data)
{
    int i = 0;
    QDir dir(QDir::currentPath());
    QSqlDatabase QSqlObj;
    setDB(QSqlObj, dir);
    int cnt = p_data.count();
    if(!QSqlObj.open())
        return 1;
    if(cnt <= 0)
        return 1;
    QSqlQuery sqlQuery(QSqlObj);
    QString strSQL = QString("DELETE FROM StepTable WHERE OutputMode = %1").
            arg(p_data.at(0).OutputMode);
    sqlQuery.prepare(strSQL);
    sqlQuery.exec();
    while(i < cnt)
    {
        QString strData;
        QSqlQuery sqlDataQuery(QSqlObj);
#if 0
                strData = QString("UPDATE StepTable SET VoltageU = %1, VoltageV = %2, "   \
                                "VoltageW = %3, FrequencyU = %4, FrequencyV = %5, FrequencyW = %6, WaveFormU = %7, " \
                                "WaveFormV = %8, WaveFormW = %9, AnglesUV = %10, AnglesUW = %11, "  \
                                "AnglesVW = %12, StepTimeU = %13, StepTimeV = %14, StepTimeW = %15 " \
                                "WHERE StepNo = %16 AND Phase = %17 AND OutputMode = %18").
                        arg(p_data.at(i).VoltageU).arg(p_data.at(i).VoltageV).arg(p_data.at(i).VoltageW).
                        arg(p_data.at(i).FrequencyU).arg(p_data.at(i).FrequencyV).
                        arg(p_data.at(i).FrequencyW).arg(p_data.at(i).WaveFormU).arg(p_data.at(i).WaveFormV).arg(p_data.at(i).WaveFormW).
                        arg(p_data.at(i).AnglesUV).arg(p_data.at(i).AnglesUW).arg(p_data.at(i).AnglesVW).
                        arg(p_data.at(i).StepTimeU).arg(p_data.at(i).StepTimeV).arg(p_data.at(i).StepTimeW).
                        arg(p_data.at(i).StepNo).arg(p_data.at(i).Phase).arg(p_data.at(i).OutputMode);
#endif
         strData = QString("INSERT INTO StepTable (OutputMode, StepNo, Phase, VoltageU, "   \
                                "VoltageV, VoltageW, FrequencyU, FrequencyV, FrequencyW, " \
                                "WaveFormU, WaveFormV, WaveFormW, AnglesUV, AnglesUW, AnglesVW, " \
                                "StepTimeU, StepTimeV, StepTimeW) "  \
                                "VALUES (%1, %2, %3, %4, %5, %6, %7, %8, %9, %10, %11, %12, %13, %14, "  \
                                "%15, %16, %17, %18)").arg(p_data.at(i).OutputMode).
                        arg(p_data.at(i).StepNo).arg(p_data.at(i).Phase).
                        arg(p_data.at(i).VoltageU).arg(p_data.at(i).VoltageV).
                        arg(p_data.at(i).VoltageW).arg(p_data.at(i).FrequencyU).arg(p_data.at(i).FrequencyV).
                        arg(p_data.at(i).FrequencyW).arg(p_data.at(i).WaveFormU).arg(p_data.at(i).WaveFormV).
                        arg(p_data.at(i).WaveFormW).arg(p_data.at(i).AnglesUV).arg(p_data.at(i).AnglesUW).
                        arg(p_data.at(i).AnglesVW).arg(p_data.at(i).StepTimeU).arg(p_data.at(i).StepTimeV).arg(p_data.at(i).StepTimeW);

        sqlDataQuery.prepare(strData);
        sqlDataQuery.exec();
        i++;
    }
    QSqlObj.close();
    return 0;
}

int dbOperation::GradientRead(const int p_outputmode, QList<GradientData> &p_data)
{
    int i = 1;
    QDir dir(QDir::currentPath());
    QSqlDatabase QSqlObj;
    GradientData data[100];
    p_data.clear();
    memset(data, 0, sizeof(data));
    while(i <= 100)
    {
        data[i - 1].StepNo = i;
        data[i - 1].OutputMode = p_outputmode;
        data[i - 1].Phase = 0;
        data[i - 1].StartVoltageU = 100;
        data[i - 1].StartVoltageV = 100;
        data[i - 1].StartVoltageW = 100;
        data[i - 1].StopVoltageU = 100;
        data[i - 1].StopVoltageV = 100;
        data[i - 1].StopVoltageW = 100;
        data[i - 1].StartFrequencyU = 50;
        data[i - 1].StartFrequencyV = 50;
        data[i - 1].StartFrequencyW = 50;
        data[i - 1].StopFrequencyU = 50;
        data[i - 1].StopFrequencyV = 50;
        data[i - 1].StopFrequencyW = 50;
        data[i - 1].WaveFormU = 0;
        data[i - 1].WaveFormV = 0;
        data[i - 1].WaveFormW = 0;
        data[i - 1].AnglesUV = 120;
        data[i - 1].AnglesUW = 120;
        data[i - 1].AnglesVW = 120;
        data[i - 1].StepTimeU = 1;
        data[i - 1].StepTimeV = 1;
        data[i - 1].StepTimeW = 1;
        p_data.append(data[i - 1]);
        i++;
    }
    setDB(QSqlObj, dir);
    if(!QSqlObj.open())
        return 1;
    QSqlQuery sqlQuery(QSqlObj);
    QString strSQL = QString("SELECT * FROM GradientTable WHERE OutputMode = %1").
                            arg(p_outputmode);
    sqlQuery.prepare(strSQL);
    if(sqlQuery.exec())
    {
        while(sqlQuery.next())
        {
            i = 1;
            int idx = sqlQuery.value(2).toInt() - 1;
            p_data[idx].OutputMode = sqlQuery.value(i++).toInt();
            i++;
            //data[idx].StepNo = sqlQuery.value(i++).toInt();
            p_data[idx].Phase = sqlQuery.value(i++).toInt();
            p_data[idx].StartVoltageU = sqlQuery.value(i++).toFloat();
            p_data[idx].StartVoltageV = sqlQuery.value(i++).toFloat();
            p_data[idx].StartVoltageW = sqlQuery.value(i++).toFloat();
            p_data[idx].StopVoltageU = sqlQuery.value(i++).toFloat();
            p_data[idx].StopVoltageV = sqlQuery.value(i++).toFloat();
            p_data[idx].StopVoltageW = sqlQuery.value(i++).toFloat();
            p_data[idx].StartFrequencyU = sqlQuery.value(i++).toFloat();
            p_data[idx].StartFrequencyV = sqlQuery.value(i++).toFloat();
            p_data[idx].StartFrequencyW = sqlQuery.value(i++).toFloat();
            p_data[idx].StopFrequencyU = sqlQuery.value(i++).toFloat();
            p_data[idx].StopFrequencyV = sqlQuery.value(i++).toFloat();
            p_data[idx].StopFrequencyW = sqlQuery.value(i++).toFloat();
            p_data[idx].WaveFormU = sqlQuery.value(i++).toInt();
            p_data[idx].WaveFormV = sqlQuery.value(i++).toInt();
            p_data[idx].WaveFormW = sqlQuery.value(i++).toInt();
            p_data[idx].AnglesUV = sqlQuery.value(i++).toFloat();
            p_data[idx].AnglesUW = sqlQuery.value(i++).toFloat();
            p_data[idx].AnglesVW = sqlQuery.value(i++).toFloat();
            p_data[idx].StepTimeU = sqlQuery.value(i++).toFloat();
            p_data[idx].StepTimeV = sqlQuery.value(i++).toFloat();
            p_data[idx].StepTimeW = sqlQuery.value(i++).toFloat();
        }
    }
    sqlQuery.finish();
    QSqlObj.close();
    return 0;
}

int dbOperation::GradientWrite(const QList<GradientData> &p_data)
{
    int i = 0;
    QDir dir(QDir::currentPath());
    QSqlDatabase QSqlObj;
    setDB(QSqlObj, dir);
    int cnt = p_data.count();
    if(!QSqlObj.open())
        return 1;
    if(cnt <= 0)
        return 1;
    QSqlQuery sqlQuery(QSqlObj);
    QString strSQL = QString("DELETE FROM GradientTable WHERE OutputMode = %1").
            arg(p_data.at(0).OutputMode);
    sqlQuery.prepare(strSQL);
    sqlQuery.exec();
    while(i < cnt)
    {
        QString strData;
        QSqlQuery sqlDataQuery(QSqlObj);
#if 0
            strData = QString("UPDATE GradientTable SET StartVoltageU = %1, StartVoltageV = %2, "   \
                            "StartVoltageW = %3, StopVoltageU = %4, StopVoltageV = %5, StopVoltageW = %6, " \
                            "StartFrequencyU = %7, StartFrequencyV = %8, StartFrequencyW = %9, " \
                            "StopFrequencyU = %10, StopFrequencyV = %11, StopFrequencyW = %12, " \
                            "WaveFormU = %13, WaveFormV = %14, WaveFormW = %15, AnglesUV = %16, AnglesUW = %17, "  \
                            "AnglesVW = %18, StepTimeU = %19, StepTimeV = %20, StepTimeW = %21 " \
                            "WHERE StepNo = %22 AND Phase = %23 AND OutputMode = %24").
                    arg(p_data.at(i).StartVoltageU).arg(p_data.StartVoltageV).arg(p_data.StartVoltageW).
                    arg(p_data.at(i).StopVoltageU).arg(p_data.StopVoltageV).arg(p_data.StopVoltageW).
                    arg(p_data.at(i).StartFrequencyU).arg(p_data.StartFrequencyV).arg(p_data.StartFrequencyW).
                    arg(p_data.at(i).StopFrequencyU).arg(p_data.StopFrequencyV).arg(p_data.StopFrequencyW).
                    arg(p_data.at(i).WaveFormU).arg(p_data.WaveFormV).arg(p_data.WaveFormW).
                    arg(p_data.at(i).AnglesUV).arg(p_data.AnglesUW).arg(p_data.AnglesVW).
                    arg(p_data.at(i).StepTimeU).arg(p_data.StepTimeV).arg(p_data.StepTimeW).
                    arg(p_data.at(i).StepNo).arg(p_data.Phase).arg(p_data.OutputMode);
#endif
         strData = QString("INSERT INTO GradientTable (OutputMode, StepNo, Phase, StartVoltageU, StartVoltageV, "   \
                            "StartVoltageW, StopVoltageU, StopVoltageV, StopVoltageW, " \
                            "StartFrequencyU, StartFrequencyV, StartFrequencyW, " \
                            "StopFrequencyU, StopFrequencyV, StopFrequencyW, " \
                            "WaveFormU, WaveFormV, WaveFormW, AnglesUV, AnglesUW, AnglesVW, " \
                            "StepTimeU, StepTimeV, StepTimeW) "  \
                            "VALUES (%1, %2, %3, %4, %5, %6, %7, %8, %9, %10, %11, %12, %13, %14, "  \
                            "%15, %16, %17, %18, %19, %20, %21, %22, %23, %24)").arg(p_data.at(i).OutputMode).
                    arg(p_data.at(i).StepNo).arg(p_data.at(i).Phase).
                    arg(p_data.at(i).StartVoltageU).arg(p_data.at(i).StartVoltageV).
                    arg(p_data.at(i).StartVoltageW).arg(p_data.at(i).StopVoltageU).arg(p_data.at(i).StopVoltageV).
                    arg(p_data.at(i).StopVoltageW).arg(p_data.at(i).StartFrequencyU).arg(p_data.at(i).StartFrequencyV).arg(p_data.at(i).StartFrequencyW).
                    arg(p_data.at(i).StopFrequencyU).arg(p_data.at(i).StopFrequencyV).arg(p_data.at(i).StopFrequencyW).
                    arg(p_data.at(i).WaveFormU).arg(p_data.at(i).WaveFormV).arg(p_data.at(i).WaveFormW).
                    arg(p_data.at(i).AnglesUV).arg(p_data.at(i).AnglesUW).arg(p_data.at(i).AnglesVW).
                    arg(p_data.at(i).StepTimeU).arg(p_data.at(i).StepTimeV).arg(p_data.at(i).StepTimeW);
        sqlDataQuery.prepare(strData);
        sqlDataQuery.exec();
        i++;
    }
    QSqlObj.close();
    return 0;
}

int dbOperation::ThroughRead(const int p_outputmode, QList<ThroughData> &p_data)
{
    int i = 1;
    QDir dir(QDir::currentPath());
    QSqlDatabase QSqlObj;
    ThroughData data[10];
    p_data.clear();
    memset(data, 0, sizeof(data));
    while(i <= 10)
    {
        data[i - 1].StepNo = i;
        data[i - 1].OutputMode = p_outputmode;
        data[i - 1].Phase = 0;
        data[i - 1].DropPhase = 0;
        data[i - 1].StartVoltage = 220;
        data[i - 1].StartFrequency = 50;
        data[i - 1].StartTime = 10;
        data[i - 1].Angles = 0;
        data[i - 1].ZeroVoltage = 0;
        data[i - 1].ZeroTime = 3;
        data[i - 1].DropVoltage = 20;
        data[i - 1].DropTime = 3;
        data[i - 1].RecoveryVoltage = 220;
        data[i - 1].RecoveryTime = 10;
        data[i - 1].StopTime = 10;
        data[i - 1].WaveFormU = 120;
        data[i - 1].WaveFormV = 120;
        data[i - 1].WaveFormW = 120;
        p_data.append(data[i - 1]);
        i++;
    }
    setDB(QSqlObj, dir);
    if(!QSqlObj.open())
        return 1;
    QSqlQuery sqlQuery(QSqlObj);
    QString strSQL = QString("SELECT * FROM ThroughTable WHERE OutputMode = %1").arg(p_outputmode);
    sqlQuery.prepare(strSQL);
    if(sqlQuery.exec())
    {
        while(sqlQuery.next())
        {
            i = 1;
            int stepNo = sqlQuery.value(2).toInt();
            data[stepNo].OutputMode = sqlQuery.value(i++).toInt();
            //data[stepNo].StepNo = sqlQuery.value(i++).toInt();
            data[stepNo].Phase = sqlQuery.value(i++).toInt();
            data[stepNo].DropPhase = sqlQuery.value(i++).toInt();
            data[stepNo].StartVoltage = sqlQuery.value(i++).toFloat();
            data[stepNo].StartFrequency = sqlQuery.value(i++).toFloat();
            data[stepNo].StartTime = sqlQuery.value(i++).toFloat();
            data[stepNo].Angles = sqlQuery.value(i++).toFloat();
            data[stepNo].ZeroVoltage = sqlQuery.value(i++).toFloat();
            data[stepNo].ZeroTime = sqlQuery.value(i++).toFloat();
            data[stepNo].DropVoltage = sqlQuery.value(i++).toFloat();
            data[stepNo].DropTime = sqlQuery.value(i++).toFloat();
            data[stepNo].RecoveryVoltage = sqlQuery.value(i++).toFloat();
            data[stepNo].RecoveryTime = sqlQuery.value(i++).toFloat();
            data[stepNo].StopTime = sqlQuery.value(i++).toFloat();
            data[stepNo].WaveFormU = sqlQuery.value(i++).toInt();
            data[stepNo].WaveFormV = sqlQuery.value(i++).toInt();
            data[stepNo].WaveFormW = sqlQuery.value(i++).toInt();
        }
    }
    QSqlObj.close();
    return 0;
}

int dbOperation::ThroughWrite(const QList<ThroughData> &p_data)
{
    QDir dir(QDir::currentPath());
    QSqlDatabase QSqlObj;
    setDB(QSqlObj, dir);
    int cnt = p_data.count();
    if(!QSqlObj.open())
        return 1;
    if(cnt <= 0)
        return 0;
    int i = 0;
    QSqlQuery sqlQuery(QSqlObj);
    QString strSQL = QString("DELETE FROM ThroughTable WHERE OutputMode = %1").
            arg(p_data.at(0).OutputMode);
    sqlQuery.prepare(strSQL);
    sqlQuery.exec();
    while(i < cnt)
    {
        QString strData;
        QSqlQuery sqlDataQuery(QSqlObj);
#if 0
                strData = QString("UPDATE ThroughTable SET "    \
                                "DropPhase = %1, StartVoltage = %2, StartFrequency = %3, StartTime = %4, "  \
                                "Angles = %5, ZeroVoltage = %6, " \
                                "ZeroTime = %7, DropVoltage = %8, DropTime = %9, " \
                                "RecoveryVoltage = %10, RecoveryTime = %11, StopTime = %12, " \
                                "WaveFormU = %13, WaveFormV = %14, WaveFormW = %15 "    \
                                "WHERE StepNo = %16 AND OutputMode = %17").
                        arg(p_data.at(i).DropPhase).arg(p_data.at(i).StartVoltage).arg(p_data.at(i).StartFrequency).
                        arg(p_data.at(i).StartTime).arg(p_data.at(i).Angles).arg(p_data.at(i).ZeroVoltage).
                        arg(p_data.at(i).ZeroTime).arg(p_data.at(i).DropVoltage).arg(p_data.at(i).DropTime).
                        arg(p_data.at(i).RecoveryVoltage).arg(p_data.at(i).RecoveryTime).arg(p_data.at(i).StopTime).
                        arg(p_data.at(i).WaveFormU).arg(p_data.at(i).WaveFormV).arg(p_data.at(i).WaveFormW).
                        arg(p_data.at(i).StepNo).arg(p_data.at(i).OutputMode);
#endif
       strData = QString("INSERT INTO ThroughTable (OutputMode, StepNo, Phase, DropPhase, StartVoltage, "   \
                                "StartFrequency, StartTime, Angles, ZeroVoltage, " \
                                "ZeroTime, DropVoltage, DropTime, " \
                                "RecoveryVoltage, RecoveryTime, StopTime, " \
                                "WaveFormU, WaveFormV, WaveFormW) " \
                                "VALUES (%1, %2, %3, %4, %5, %6, %7, %8, %9, %10, %11, %12, %13, %14, "  \
                                "%15, %16, %17, %18)").
                        arg(p_data.at(i).OutputMode).arg(p_data.at(i).StepNo).arg(p_data.at(i).Phase).
                        arg(p_data.at(i).DropPhase).arg(p_data.at(i).StartVoltage).arg(p_data.at(i).StartFrequency).arg(p_data.at(i).StartTime).
                        arg(p_data.at(i).Angles).arg(p_data.at(i).ZeroVoltage).arg(p_data.at(i).ZeroTime).
                        arg(p_data.at(i).DropVoltage).arg(p_data.at(i).DropTime).arg(p_data.at(i).RecoveryVoltage).
                        arg(p_data.at(i).RecoveryTime).arg(p_data.at(i).StopTime).
                        arg(p_data.at(i).WaveFormU).arg(p_data.at(i).WaveFormV).arg(p_data.at(i).WaveFormW);
        sqlDataQuery.prepare(strData);
        sqlDataQuery.exec();
        i++;
    }
    QSqlObj.close();
    return 0;
}

int dbOperation::HarmonicsRead(const int p_group, QList<HarmonicsData> &p_data)
{
    int i = 0;
    HarmonicsData data[39];
    QDir dir(QDir::currentPath());
    QSqlDatabase QSqlObj;
    setDB(QSqlObj, dir);
    p_data.clear();
    do
    {
        i = 0;
        if(!QSqlObj.open())
            break;
        QSqlQuery sqlQuery(QSqlObj);
        QString strSQL = QString("SELECT * FROM GradientTable WHERE StepNo = %1 ORDER BY Times ASC").arg(p_group);
        sqlQuery.prepare(strSQL);
        bool bRet = sqlQuery.exec();
        if(!bRet)
            break;
        while(sqlQuery.next())
        {
            //data[i].StepNo = sqlQuery.value(1).toInt();
            data[i].Times = sqlQuery.value(2).toInt();
            data[i].Percent = sqlQuery.value(3).toFloat();
            data[i].Angles = sqlQuery.value(4).toFloat();
            p_data.append(data[i]);
            i++;
        }
        QSqlObj.close();
        return 0;
    }
    while(0);
    i = 0;
    while(i < 39)
    {
        data[i].StepNo = p_group;
        data[i].Times = i + 2;
        data[i].Percent = 0.0;
        data[i].Angles = 0.0;
        p_data.append(data[i]);
        i++;
    }
    return 0;
}

int dbOperation::HarmonicsReadAll(QList<HarmonicsGroupData> &p_data)
{
    int groupIdx = 0;
    HarmonicsGroupData data[10];
    QDir dir(QDir::currentPath());
    QSqlDatabase QSqlObj;
    setDB(QSqlObj, dir);
    if(!QSqlObj.open())
    {
        HarmonicsGroupData temp;
        int k = 0;
        while(k < 39)
        {
            temp.Percent[k] = 0.0;
            temp.Angles[k] = 0.0;
            k++;
        }
        p_data.append(temp);
        p_data.append(temp);
        p_data.append(temp);
        p_data.append(temp);
        p_data.append(temp);
        p_data.append(temp);
        p_data.append(temp);
        p_data.append(temp);
        p_data.append(temp);
        p_data.append(temp);
        return 1;
    }
    p_data.clear();
    while(groupIdx < 10)
    {

        QSqlQuery sqlQuery(QSqlObj);
        QString strSQL = QString("SELECT * FROM GradientTable WHERE StepNo = %1 ORDER BY Times ASC").arg(groupIdx);
        sqlQuery.prepare(strSQL);
        bool bRet = sqlQuery.exec();
        if(!bRet)
        {
            int k = 0;
            while(k < 39)
            {
                data[groupIdx].Percent[k] = 0.0;
                data[groupIdx].Angles[k] = 0.0;
                k++;
            }
        }
        else
        {
            int i = 0;
            while(sqlQuery.next())
            {
                data[groupIdx].Percent[i] = sqlQuery.value(3).toFloat();
                data[groupIdx].Angles[i] = sqlQuery.value(4).toFloat();
                i++;
            }
        }
        p_data.append(data[groupIdx]);
        groupIdx++;
    }
    QSqlObj.close();
    return 0;
}

int dbOperation::HarmonicsWrite(const int p_group, const QList<HarmonicsData> &p_data)
{
    QDir dir(QDir::currentPath());
    QSqlDatabase QSqlObj;
    setDB(QSqlObj, dir);
    if(!QSqlObj.open())
        return 1;
    QSqlQuery sqlQuery(QSqlObj);
    QString strSQL = QString("DELETE FROM HarmonicsTable WHERE StepNo = %1").arg(p_group);
    sqlQuery.prepare(strSQL);
    sqlQuery.exec();
    QString strData;
    QSqlQuery sqlDataQuery(QSqlObj);
#if 0
        strData = QString("UPDATE ThroughTable Times = %1, Percent = %2, Angles = %3 WHERE StepNo = %4").
                arg(p_data.Times).arg(p_data.Percent).arg(p_data.Angles).arg(p_data.StepNo);
#endif
    foreach(const HarmonicsData temp, p_data)
    {
        strData = QString("INSERT INTO HarmonicsTable (StepNo, Times, Percent, Angles, StopNo, "    \
                        "VALUES (%1, %2, %3, %4)").
                arg(temp.StepNo).arg(temp.Times).arg(temp.Percent).arg(temp.Angles);
    }
    sqlDataQuery.prepare(strData);
    sqlDataQuery.exec();
    QSqlObj.close();
    return 0;
}

int dbOperation::LogRead(const int p_page, QList<LogData> &p_log)
{
    QDir dir(QDir::currentPath());
    QSqlDatabase QSqlObj;
    setDB(QSqlObj, dir);
    p_log.clear();
    do
    {
        if(!QSqlObj.open())
            break;
        QSqlQuery sqlQuery(QSqlObj);
        QString strSQL = QString("SELECT * FROM LogTable ORDER BY Time ASC LIMIT 20 OFFSET %1").
                arg(p_page * 20);
        sqlQuery.prepare(strSQL);
        bool bRet = sqlQuery.exec();
        if(!bRet)
            break;
        while(sqlQuery.next())
        {
            LogData data;
            data.TestMode = sqlQuery.value(1).toInt();
            data.OutputMode = sqlQuery.value(2).toInt();
            data.OperationType = sqlQuery.value(3).toInt();
            data.Time = sqlQuery.value(4).toString();
            data.IGBT = sqlQuery.value(5).toFloat();
            data.Transformer = sqlQuery.value(6).toFloat();
            data.FanSpeed = sqlQuery.value(7).toInt();
            p_log.append(data);
        }
        QSqlObj.close();
        return 0;
    }
    while(0);
    return 0;
}

int dbOperation::LogWrite(const LogData &p_log)
{
    QDir dir(QDir::currentPath());
    QSqlDatabase QSqlObj;
    setDB(QSqlObj, dir);
    if(!QSqlObj.open())
        return 1;
    QString strData;
    QSqlQuery sqlDataQuery(QSqlObj);
    strData = QString("INSERT INTO LogTable (TestMode, OutputMode, OperationType, Time, IGBT, "    \
                      "Transformer, FanSpeed) VALUES (%1, %2, %3, '%4', %5, %6, %7)").
            arg(p_log.TestMode).arg(p_log.OutputMode).arg(p_log.OperationType).arg(p_log.Time).
            arg(p_log.IGBT).arg(p_log.Transformer).arg(p_log.FanSpeed);
    sqlDataQuery.prepare(strData);
    bool ret = sqlDataQuery.exec();
    //qDebug() << strData << ret;
    QSqlObj.close();
    return 0;
}

int dbOperation::LogClear()
{
    QDir dir(QDir::currentPath());
    QSqlDatabase QSqlObj;
    setDB(QSqlObj, dir);
    if(!QSqlObj.open())
        return 1;
    QString strData;
    QSqlQuery sqlDataQuery(QSqlObj);
    strData = QString("DELETE FROM LogTable");
    sqlDataQuery.prepare(strData);
    bool ret = sqlDataQuery.exec();
    //qDebug() << strData << ret;
    QSqlObj.close();
    return 0;
}

int dbOperation::checkDBStatus()
{
    QDir dir(QDir::currentPath());
    QFileInfo file("./db/systemdata.db");
    if(!dir.exists("db"))
    {
        dir.mkdir("db");
        return createDB(false, dir);
    }
    if(!file.isFile())
    {
        return createDB(false, dir);
    }
    return createDB(true, dir);
}

int dbOperation::createDB(const bool p_check, const QDir &p_dir)
{
    QSqlDatabase QSqlObj;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        QSqlObj = QSqlDatabase::database("qt_sql_default_connection");
    else
        QSqlObj = QSqlDatabase::addDatabase("QSQLITE");
    QString dbPath = p_dir.absolutePath() + "/db/systemdata.db";
    QSqlObj.setDatabaseName(dbPath);
    if(QSqlObj.open())
    {
        QSqlQuery openQuery(QSqlObj);
        QSqlQuery queryObj(QSqlObj);
        if(p_check)
        {
            openQuery.prepare("SELECT * FROM " + DEF_TABLE_GENERAL);
            if(!openQuery.exec())
            {
                queryObj.prepare(createTable(ENM_TABLE_GENERAL));
                queryObj.exec();
                //queryObj.prepare(initTable(0, ENM_TABLE_GENERAL));
                //queryObj.exec();
                //qDebug() << "GENERAL: " << queryObj.exec();
            }
            openQuery.prepare("SELECT * FROM " + DEF_TABLE_STEPLADDER);
            if(!openQuery.exec())
            {
                queryObj.prepare(createTable(ENM_TABLE_STEPLADDER));
                queryObj.exec();
                //queryObj.prepare(initTable(0, ENM_TABLE_STEPLADDER));
                //queryObj.exec();
                //qDebug() << "STEPLADDER: " << queryObj.exec();
            }
            openQuery.prepare("SELECT * FROM " + DEF_TABLE_STEP);
            if(!openQuery.exec())
            {
                queryObj.prepare(createTable(ENM_TABLE_STEP));
                queryObj.exec();
                //for(int i = 0; i < 100; i++)
                //{
                //    queryObj.prepare(initTable(i, ENM_TABLE_STEP));
                //    queryObj.exec();
                //}
                //qDebug() << "STEP: " << queryObj.exec();
            }
            openQuery.prepare("SELECT * FROM " + DEF_TABLE_GRADIENT);
            if(!openQuery.exec())
            {
                queryObj.prepare(createTable(ENM_TABLE_GRADIENT));
                queryObj.exec();
                //for(int i = 0; i < 100; i++)
                //{
                //    queryObj.prepare(initTable(i, ENM_TABLE_GRADIENT));
                //    queryObj.exec();
                //}
                //qDebug() << "GRADIENT: " << queryObj.exec();
            }
            openQuery.prepare("SELECT * FROM " + DEF_TABLE_THROUGH);
            if(!openQuery.exec())
            {
                queryObj.prepare(createTable(ENM_TABLE_THROUGH));
                queryObj.exec();
                //queryObj.prepare(initTable(0, ENM_TABLE_THROUGH));
                //queryObj.exec();
                //qDebug() << "THROUGH: " << queryObj.exec();
            }
            openQuery.prepare("SELECT * FROM " + DEF_TABLE_HARMONICS);
            if(!openQuery.exec())
            {
                queryObj.prepare(createTable(ENM_TABLE_HARMONICS));
                queryObj.exec();
                //for(int i = 1; i <= 40; i++)
                //{
                //    queryObj.prepare(initTable(i, ENM_TABLE_HARMONICS));
                //    queryObj.exec();
                //}
                //qDebug() << "HARMONICS: " << queryObj.exec();
            }
            openQuery.prepare("SELECT * FROM " + DEF_TABLE_LOG);
            if(!openQuery.exec())
            {
                queryObj.prepare(createTable(ENM_TABLE_LOG));
                queryObj.exec();
                //qDebug() << "LOG: " << queryObj.exec();
            }
            openQuery.prepare("SELECT * FROM " + DEF_TABLE_ERROR);
            if(!openQuery.exec())
            {
                queryObj.prepare(createTable(ENM_TABLE_ERROR));
                queryObj.exec();
                //qDebug() << "ERROR: " << queryObj.exec();
            }
        }
        else
        {
            queryObj.prepare(createTable(ENM_TABLE_GENERAL));
            queryObj.exec();
            //qDebug() << "GENERAL: " << queryObj.exec();
            queryObj.prepare(createTable(ENM_TABLE_STEPLADDER));
            queryObj.exec();
            //qDebug() << "STEPLADDER: " << queryObj.exec();
            queryObj.prepare(createTable(ENM_TABLE_STEP));
            queryObj.exec();
            //qDebug() << "STEP: " << queryObj.exec();
            queryObj.prepare(createTable(ENM_TABLE_GRADIENT));
            queryObj.exec();
            //qDebug() << "GRADIENT: " << queryObj.exec();
            queryObj.prepare(createTable(ENM_TABLE_THROUGH));
            queryObj.exec();
            //qDebug() << "THROUGH: " << queryObj.exec();
            queryObj.prepare(createTable(ENM_TABLE_HARMONICS));
            queryObj.exec();
            //qDebug() << "HARMONICS: " << queryObj.exec();
            queryObj.prepare(createTable(ENM_TABLE_LOG));
            queryObj.exec();
            //qDebug() << "LOG: " << queryObj.exec();
            queryObj.prepare(createTable(ENM_TABLE_ERROR));
            queryObj.exec();
            //qDebug() << "ERROR: " << queryObj.exec();
#if 0
            queryObj.prepare(initTable(0, ENM_TABLE_GENERAL));
            queryObj.exec();
            queryObj.prepare(initTable(0, ENM_TABLE_STEPLADDER));
            queryObj.exec();
            for(int i = 0; i < 100; i++)
            {
                queryObj.prepare(initTable(i, ENM_TABLE_STEP));
                queryObj.exec();
                queryObj.prepare(initTable(i, ENM_TABLE_GRADIENT));
                queryObj.exec();
                if(i < 40)
                {
                    queryObj.prepare(initTable(i + 1, ENM_TABLE_HARMONICS));
                    queryObj.exec();
                }
            }
            queryObj.prepare(initTable(0, ENM_TABLE_THROUGH));
            queryObj.exec();
#endif
        }
        QSqlObj.close();
        return 0;
    }
    QSqlObj.close();
    return 1;
}

QString dbOperation::createTable(const int p_table)
{
    QString strSql = "CREATE TABLE ";
    switch(p_table)
    {
    case ENM_TABLE_GENERAL:
        strSql += "GeneralTable (ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "    \
                "VoltageLevel INT, OutputMode INT, StepNo INT, "    \
                "StartTimeU FLOAT, StartTimeV FLOAT, StartTimeW FLOAT, EnableU INT, "   \
                "EnableV INT, EnableW INT, VoltageU FLOAT, VoltageV FLOAT, VoltageW FLOAT, " \
                "FrequencyU FLOAT, FrequencyV FLOAT, FrequencyW FLOAT, WaveFormU int, "  \
                "WaveFormV int, WaveFormW int, AnglesUV FLOAT, AnglesUW FLOAT, " \
                "AnglesVW FLOAT)";
        break;
    case ENM_TABLE_STEPLADDER:
        strSql += "StepLadderTable (ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "    \
                "OutputMode INT, StartVoltageU FLOAT, StartVoltageV FLOAT, StartVoltageW FLOAT, "    \
                "StepVoltageU FLOAT, StepVoltageV FLOAT, StepVoltageW FLOAT, "   \
                "StartFrequencyU FLOAT, StartFrequencyV FLOAT, StartFrequencyW FLOAT, " \
                "StepFrequencyU FLOAT, StepFrequencyV FLOAT, StepFrequencyW FLOAT, "    \
                "WaveFormU INT, WaveFormV INT, WaveFormW INT, "   \
                "AnglesUV FLOAT, AnglesUW FLOAT, AnglesVW FLOAT, "    \
                "StepTimeU FLOAT, StepTimeV FLOAT, StepTimeW FLOAT, "   \
                "StepCountU INT, StepCountV INT, StepCountW INT)";
        break;
    case ENM_TABLE_STEP:
        strSql += "StepTable (ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "    \
                "OutputMode INT, "    \
                "StepNo INT, Phase INT, VoltageU FLOAT, VoltageV FLOAT, VoltageW FLOAT, "   \
                "FrequencyU FLOAT, FrequencyV FLOAT, FrequencyW FLOAT, "    \
                "WaveFormU int, WaveFormV int, WaveFormW int, AnglesUV FLOAT, "   \
                "AnglesUW FLOAT, AnglesVW FLOAT, StepTimeU FLOAT, "  \
                "StepTimeV FLOAT, StepTimeW FLOAT)";
        break;
    case ENM_TABLE_GRADIENT:
        strSql += "GradientTable (ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "    \
                 "OutputMode INT, "    \
                 "StepNo INT, Phase INT, StartVoltageU FLOAT, StartVoltageV FLOAT, StartVoltageW FLOAT, "   \
                 "StopVoltageU FLOAT, StopVoltageV FLOAT, StopVoltageW FLOAT, "   \
                 "StartFrequencyU FLOAT, StartFrequencyV FLOAT, StartFrequencyW FLOAT, "    \
                 "StopFrequencyU FLOAT, StopFrequencyV FLOAT, StopFrequencyW FLOAT, "    \
                 "WaveFormU int, WaveFormV int, WaveFormW int, AnglesUV FLOAT, "   \
                 "AnglesUW FLOAT, AnglesVW FLOAT, StepTimeU FLOAT, "  \
                 "StepTimeV FLOAT, StepTimeW FLOAT)";
        break;
    case ENM_TABLE_THROUGH:
        strSql += "ThroughTable (ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "    \
                "CurrentItem INT, OutputMode INT, StartNo INT, StopNo INT, CycleTimes INT, "    \
                "StepNo INT, DropPhase INT, StartVoltage FLOAT, StartFrequency FLOAT, "    \
                "StartTime FLOAT, Angles FLOAT, ZeroVoltage FLOAT, ZeroTime FLOAT, "    \
                "DropVoltage FLOAT, DropTime FLOAT, RecoveryVoltage FLOAT, RecoveryTime FLOAT, "    \
                "StopTime FLOAT, WaveFormU INT, WaveFormV INT, WaveFormW INT)";
        break;
    case ENM_TABLE_HARMONICS:
        strSql += "HarmonicsTable (ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "    \
                "Times INT, Percent FLOAT, Angles FLOAT)";
        break;
    case ENM_TABLE_LOG:
        strSql += "LogTable (ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "    \
                "TestMode INT, OutputMode INT, OperationType INT, Time NVARCHAR(32), "    \
                "IGBT FLOAT, Transformer FLOAT, FanSpeed INT, Remark1 NVARCHAR(256), "  \
                "Remark2 NVARCHAR(256), Remark3 NVARCHAR(256), Remark4 NVARCHAR(256))";
        break;
    case ENM_TABLE_ERROR:
        strSql += "ErrorTable (ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "    \
                "ErrorType NVARCHAR(256), TestMode NVARCHAR(32), InputVoltage FLOAT, "    \
                "OutputVoltage FLOAT, Time NVARCHAR(32), IGBT FLOAT, Transformer FLOAT, "   \
                "FanSpeed int, Remark1 NVARCHAR(256), Remark2 NVARCHAR(256), "  \
                "Remark3 NVARCHAR(256), Remark4 NVARCHAR(256))";
        break;
    default:
        return "";
    }
    return strSql;
}

//不需要初始化数据库，在读取数据库时初始化数据
QString dbOperation::initTable(const int p_step, const int p_table)
{
    QString strSql = "INSERT INTO ";
    switch(p_table)
    {
    case ENM_TABLE_GENERAL:
        strSql += "GeneralTable (VoltageLevel, OutputMode, StepNo, "    \
                "StartTimeU, StartTimeV, StartTimeW, EnableU, "   \
                "EnableV, EnableW, VoltageU, VoltageV, VoltageW, " \
                "FrequencyU, FrequencyV, FrequencyW, WaveFormU, "  \
                "WaveFormV, WaveFormW, AnglesU, AnglesV, AnglesW) " \
                "VALUES (0, 0, 0, 0.0, 0.0, 0.0, 1, 1, 1, 220.0, 220.0, 220.0, 50.00, "  \
                "50.00, 50.00, 0, 0, 0, '0.0,0.0', '0.0,0.0', '0.0,0.0')";
        break;
    case ENM_TABLE_STEPLADDER:
        strSql += "StepLadderTable (OutputMode, StartVoltageU, StartVoltageV, StartVoltageW, "    \
                "StepVoltageU, StepVoltageV, StepVoltageW, "   \
                "StartFrequencyU, StartFrequencyV, StartFrequencyW, " \
                "StepFrequencyU, StepFrequencyV, StepFrequencyW, "    \
                "WaveFormU, WaveFormV, WaveFormW, "   \
                "AnglesU, AnglesV, AnglesW, "    \
                "StepTimeU, StepTimeV, StepTimeW, "   \
                "StepCountU, StepCountV, StepCountW)"   \
                "VALUES (0, 50.0, 50.0, 50.0, 1.0, 1.0, 1.0, 50.00, 50.00, 50.00, 1.00, 1.00,"   \
                "1.00, 0, 0, 0, '0.0,0.0', '0.0,0.0', '0.0,0.0', 5.0, 5.0, 5.0, 10, 10, 10)";
        break;
    case ENM_TABLE_STEP:
        strSql += QString("StepTable (OutputMode, StartNo, StopNo, CycleTimes, "    \
                "StepNo, VoltageU, VoltageV, VoltageW, FrequencyU, FrequencyV, FrequencyW, "    \
                "WaveFormU, WaveFormV, WaveFormW, AnglesU, "   \
                "AnglesV, AnglesW, StepTimeU, StepTimeV, StepTimeW) "
                "VALUES (0, 0, 0, 1, %1, 220.0, 220.0, 220.0, 50.00, 50.00, 50.00, 0, 0, 0, "   \
                "'0.0,0.0', '0.0,0.0', '0.0,0.0', 5.0, 5.0, 5.0)").arg(p_step);
        break;
    case ENM_TABLE_GRADIENT:
        strSql += QString("GradientTable (OutputMode, StartNo, StopNo, CycleTimes, "    \
                 "StepNo, StartVoltageU, StartVoltageV, StartVoltageW, "   \
                 "StopVoltageU, StopVoltageV, StopVoltageW, "   \
                 "StartFrequencyU, StartFrequencyV, StartFrequencyW, "    \
                 "StopFrequencyU, StopFrequencyV, StopFrequencyW, "    \
                 "WaveFormU, WaveFormV, WaveFormW, AnglesU, "   \
                 "AnglesV, AnglesW, StepTimeU, StepTimeV, StepTimeW) "
                 "VALUES (0, 0, 0, 1, %1, 220.0, 220.0, 220.0, 240.0, 240.0, 240.0, "   \
                 "50.00, 50.00, 50.00, 60.00, 60.00, 60.00, 0, 0, 0, '0.0,0.0', "   \
                 "'0.0,0.0', '0.0,0.0', 5.0, 5.0, 5.0)").arg(p_step);
        break;
    case ENM_TABLE_THROUGH:
        strSql += "ThroughTable (CurrentItem, OutputMode, StartNo, StopNo, CycleTimes, "    \
                "StepNo, DropPhase, StartVoltage, StartFrequency, "    \
                "StartTime, Angles, ZeroVoltage, ZeroTime, "    \
                "DropVoltage, DropTime, RecoveryVoltage, RecoveryTime, "    \
                "StopTime, WaveFormU, WaveFormV, WaveFormW) "    \
                "VALUES (1, 0, 0, 0, 1, 0, 0, 220.0, 50.00, 10.0, '0.0,0.0', 50.0, "  \
                "10.0, 100.0, 10.0, 220.0, 10.0, 10.0, 0, 0, 0)";
        break;
    case ENM_TABLE_HARMONICS:
        strSql += "HarmonicsTable (Times, Percent, Angles) "    \
                "VALUES (%1, 0.00, '0.0,0.0')";
        break;
    default:
        return "";
    }
    return strSql;
}
