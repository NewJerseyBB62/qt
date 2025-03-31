#include "jsonopration.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QDir>
#include <QFile>
#include <QFileInfo>

JsonOpration::JsonOpration()
{

}

int JsonOpration::ReadJson(ConfigData &p_data)
{
    do
    {
        QFile jsonFile("./config.json");
        if(!jsonFile.open(QIODevice::ReadOnly))
            break;
        QJsonDocument doc = QJsonDocument::fromJson(jsonFile.readAll());
        if(doc.isNull())
        {
            jsonFile.close();
            break;
        }
        jsonFile.close();
        QJsonObject root = doc.object();
        p_data.Language = root["Language"].toInt();
        p_data.Theme = root["Theme"].toInt();
        p_data.LinePhase = root["LinePhase"].toInt();
        p_data.OvercurrentLimit = root["OvercurrentLimit"].toDouble();
        p_data.LineImpedance = root["LineImpedance"].toDouble();
        p_data.LockCheck = root["LockCheck"].toBool();
        p_data.LockTime = root["LockTime"].toInt();
        p_data.LockPwd = root["LockPwd"].toString();
        p_data.SerialPort = root["SerialPort"].toString();
        p_data.Baudrate = root["Baudrate"].toInt();
        p_data.Addr = root["Addr"].toInt();
        p_data.Protocol = root["Protocol"].toInt();
        p_data.Company = root["Company"].toString();
        p_data.Address = root["Address"].toString();
        p_data.Phone = root["Phone"].toString();
        p_data.Email = root["Email"].toString();
        p_data.TCPIP = root["TCPIP"].toString();
        p_data.TCPPort = root["TCPPort"].toInt();
        p_data.NeutralMode = root["NeutralMode"].toBool();
        p_data.Serialization = root["Serialization"].toInt();
        p_data.ThreePhase = root["ThreePhase"].toBool();
        p_data.ThreePhaseDiscrete = root["ThreePhaseDiscrete"].toBool();
        p_data.ThreePhaseUnbalance = root["ThreePhaseUnbalance"].toBool();
        p_data.SinglePhase = root["SinglePhase"].toBool();
        p_data.Harmonics = root["Harmonics"].toBool();
        p_data.DeviceMode = root["DeviceMode"].toString();
        p_data.Support = root["Support"].toString();
        p_data.AntiShock = root["AntiShock"].toInt();
        p_data.ShockMult1 = root["ShockMult1"].toDouble();
        p_data.VoltageDrop1 = root["VoltageDrop1"].toDouble();
        p_data.RetardTime = root["RetardTime"].toDouble();
        p_data.ShockMult2 = root["ShockMult2"].toDouble();
        p_data.VoltageDrop2 = root["VoltageDrop2"].toDouble();
        p_data.HoldTime = root["HoldTime"].toDouble();
        p_data.OCFold = root["OCFold"].toBool();
        p_data.GeneralStep = root["GeneralStep"].toInt();
        p_data.GeneralOutputMode = root["GeneralOutputMode"].toInt();
        p_data.StepLadderOutputMode = root["StepLadderOutputMode"].toInt();
        p_data.StepOutputMode = root["StepOutputMode"].toInt();
        p_data.StepStartNo = root["StepStartNo"].toInt();
        p_data.StepStopNo = root["StepStopNo"].toInt();
        p_data.StepCycleTimes = root["StepCycleTimes"].toInt();
        p_data.GradientOutputMode = root["GradientOutputMode"].toInt();
        p_data.GradientStartNo = root["GradientStartNo"].toInt();
        p_data.GradientStopNo = root["GradientStopNo"].toInt();
        p_data.GradientCycleTimes = root["GradientCycleTimes"].toInt();
        p_data.ThroughStep = root["ThroughStep"].toInt();
        p_data.ThroughOutputMode = root["ThroughOutputMode"].toInt();
        p_data.ThroughStartNo = root["ThroughStartNo"].toInt();
        p_data.ThroughStopNo = root["ThroughStopNo"].toInt();
        p_data.ThroughCycleTimes = root["ThroughCycleTimes"].toInt();
        return 0;
    }
    while(0);
    p_data.Language = 0;
    p_data.Theme = 0;
    p_data.LinePhase = 0;
    p_data.OvercurrentLimit = 0.0;
    p_data.LineImpedance = 0.0;
    p_data.LockCheck = false;
    p_data.LockTime = 0;
    p_data.LockPwd = "";
    p_data.SerialPort = "COM1";
    p_data.Baudrate = 9600;
    p_data.Addr = 1;
    p_data.Protocol = 0;
    p_data.Company = "";
    p_data.Address = "";
    p_data.Phone = "";
    p_data.Email = "";
    p_data.TCPIP = "";
    p_data.TCPPort = 0;
    p_data.NeutralMode = false;
    p_data.Serialization = 3;
    p_data.ThreePhase = true;
    p_data.ThreePhaseDiscrete = true;
    p_data.ThreePhaseUnbalance = true;
    p_data.SinglePhase = true;
    p_data.Harmonics = true;
    p_data.DeviceMode = "PIPS";
    p_data.Support = "XXX";
    p_data.AntiShock = 0;
    p_data.ShockMult1 = 1.0;
    p_data.VoltageDrop1 = 0;
    p_data.RetardTime = 1.0;
    p_data.ShockMult2 = 1.0;
    p_data.VoltageDrop2 = 0;
    p_data.HoldTime = 1.0;
    p_data.OCFold = false;
    p_data.GeneralStep = 1;
    p_data.GeneralOutputMode = 0;
    p_data.StepLadderOutputMode = 0;
    p_data.StepOutputMode = 0;
    p_data.StepStartNo = 1;
    p_data.StepStopNo = 1;
    p_data.StepCycleTimes = 1;
    p_data.GradientOutputMode = 0;
    p_data.GradientStartNo = 1;
    p_data.GradientStopNo = 1;
    p_data.GradientCycleTimes = 1;
    p_data.ThroughStep = 1;
    p_data.ThroughOutputMode = 0;
    p_data.ThroughStartNo = 1;
    p_data.ThroughStopNo = 1;
    p_data.ThroughCycleTimes = 1;
    return 0;
}

int JsonOpration::WriteJson(const ConfigData &p_data)
{
    QFile jsonFile("./config.json");
    jsonFile.open(QIODevice::WriteOnly);
    QJsonObject root;
    root.insert("Language", p_data.Language);
    root.insert("Theme", p_data.Theme);
    root.insert("LinePhase", p_data.LinePhase);
    root.insert("OvercurrentLimit", p_data.OvercurrentLimit);
    root.insert("LineImpedance", p_data.LineImpedance);
    root.insert("LockCheck", p_data.LockCheck);
    root.insert("LockTime", p_data.LockTime);
    root.insert("LockPwd", p_data.LockPwd);
    root.insert("SerialPort", p_data.SerialPort);
    root.insert("Baudrate", p_data.Baudrate);
    root.insert("Addr", p_data.Addr);
    root.insert("Protocol", p_data.Protocol);
    root.insert("Company", p_data.Company);
    root.insert("Address", p_data.Address);
    root.insert("Phone", p_data.Phone);
    root.insert("Email", p_data.Email);
    root.insert("TCPIP", p_data.TCPIP);
    root.insert("TCPPort", p_data.TCPPort);
    root.insert("NeutralMode", p_data.NeutralMode);
    root.insert("Serialization", p_data.Serialization);
    root.insert("ThreePhase", p_data.ThreePhase);
    root.insert("ThreePhaseDiscrete", p_data.ThreePhaseDiscrete);
    root.insert("ThreePhaseUnbalance", p_data.ThreePhaseUnbalance);
    root.insert("SinglePhase", p_data.SinglePhase);
    root.insert("Harmonics", p_data.Harmonics);
    root.insert("DeviceMode", p_data.DeviceMode);
    root.insert("Support", p_data.Support);
    root.insert("AntiShock", p_data.AntiShock);
    root.insert("ShockMult1", p_data.ShockMult1);
    root.insert("VoltageDrop1", p_data.VoltageDrop1);
    root.insert("RetardTime", p_data.RetardTime);
    root.insert("ShockMult2", p_data.ShockMult2);
    root.insert("VoltageDrop2", p_data.VoltageDrop2);
    root.insert("HoldTime", p_data.HoldTime);
    root.insert("OCFold", p_data.OCFold);
    root.insert("GeneralStep", p_data.GeneralStep);
    root.insert("GeneralOutputMode", p_data.GeneralOutputMode);
    root.insert("StepLadderOutputMode", p_data.StepLadderOutputMode);
    root.insert("StepOutputMode", p_data.StepOutputMode);
    root.insert("StepStartNo", p_data.StepStartNo);
    root.insert("StepStopNo", p_data.StepStopNo);
    root.insert("StepCycleTimes", p_data.StepCycleTimes);
    root.insert("GradientOutputMode", p_data.GradientOutputMode);
    root.insert("GradientStartNo", p_data.GradientStartNo);
    root.insert("GradientStopNo", p_data.GradientStopNo);
    root.insert("GradientCycleTimes", p_data.GradientCycleTimes);
    root.insert("ThroughStep", p_data.ThroughStep);
    root.insert("ThroughOutputMode", p_data.ThroughOutputMode);
    root.insert("ThroughStartNo", p_data.ThroughStartNo);
    root.insert("ThroughStopNo", p_data.ThroughStopNo);
    root.insert("ThroughCycleTimes", p_data.ThroughCycleTimes);
    QJsonDocument doc(root);
    jsonFile.write(doc.toJson());
    jsonFile.close();
    return 0;
}

int JsonOpration::openJson()
{
    QDir dir(QDir::currentPath());
    QFileInfo file("./config.json");
    if(!file.isFile())
    {
        return 1;
    }
    return 0;
}
