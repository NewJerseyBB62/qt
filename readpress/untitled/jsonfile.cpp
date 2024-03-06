#include "jsonfile.h"
#include <QFileInfo>
#include <QJsonDocument>
#include <QJsonArray>

jsonfile::jsonfile(QObject *parent) : QObject(parent)
{

}

int jsonfile::readJsonfile(const QString &p_path, SetStruct &p_data)
{
    QFileInfo fi(p_path);
    if(fi.isFile())
    {
        QFile jsonFile(p_path);
        bool bRet = jsonFile.open(QIODevice::ReadOnly);
        if(!bRet)
            return 1;
        QJsonDocument doc = QJsonDocument::fromJson(jsonFile.readAll());
        if(doc.isNull())
            return 2;
        jsonFile.close();
        QJsonObject root = doc.object();
        p_data.serialport = root["Serialport"].toString();
        p_data.baudrate = root["Baudrate"].toInt();
        p_data.alamMax = root["AlamMax"].toDouble();
        p_data.alamMin = root["AlamMin"].toDouble();
        p_data.copeVal = root["Cope"].toDouble();
        p_data.saveTime = root["SaveTime"].toInt();
    }
    else
    {
        p_data.serialport = "";
        p_data.baudrate = 9600;
        p_data.alamMax = 3.0;
        p_data.alamMin = 0.0;
        p_data.copeVal = 0.0;
        p_data.saveTime = 60;
    }
    return 0;
}

int jsonfile::writeJsonfile(const QString &p_path, const SetStruct &p_data)
{
    QFile file(p_path);
    if(!file.open(QIODevice::WriteOnly))
    {
        return 1;
    }
    QJsonObject root;
    root.insert("Serialport", p_data.serialport);
    root.insert("Baudrate", p_data.baudrate);
    root.insert("AlamMax", p_data.alamMax);
    root.insert("AlamMin", p_data.alamMin);
    root.insert("Cope", p_data.copeVal);
    root.insert("SaveTime", p_data.saveTime);
    QJsonDocument doc(root);
    file.write(doc.toJson());
    file.close();
    return 0;
}
