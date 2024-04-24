#include "inioperation.h"
#include <QSettings>

iniOperation::iniOperation(QObject *parent) : QObject(parent)
{

}

int iniOperation::readIniFile(const QString &p_path, IniStruct &p_data)
{
    QSettings *iniRead = new QSettings(p_path, QSettings::IniFormat);
    p_data.strUrl = iniRead->value("/Config/url").toString();
    p_data.logCheck = iniRead->value("/Config/log").toInt() == 1 ? true : false;
    delete iniRead;
    return 0;
}

int iniOperation::writeIniFile(const QString &p_path, const IniStruct &p_data)
{
    QSettings *iniWrite = new QSettings(p_path, QSettings::IniFormat);
    iniWrite->setValue("/Config/url", p_data.strUrl);
    iniWrite->setValue("/Config/log", p_data.logCheck ? "1" : "0");
    delete iniWrite;
    return 0;
}
