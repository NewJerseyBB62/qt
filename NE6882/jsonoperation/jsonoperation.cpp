#include "jsonoperation.h"
#include <QFileInfo>
#include <QJsonDocument>
#include <QJsonArray>


#define SETTING_SYSTEM_SERIALPORT   QStringLiteral("serialport")
#define SETTING_SYSTEM_BAUDRATE   QStringLiteral("baudrate")
#define SETTING_SYSTEM_TESTFILE   QStringLiteral("testfile")
#define SETTING_KEY_TYPE    QStringLiteral("datatype")
#define SETTING_KEY_DATA    QStringLiteral("testdata")
#define SETTING_KEY_GROUP   QStringLiteral("groupdata")
#define SETTING_GROUP_FREQ  QStringLiteral("voltfreq")
#define SETTING_GROUP_STEP  QStringLiteral("failstep")
#define SETTING_GROUP_POWER QStringLiteral("powertype")
#define SETTING_GROUP_CONNECT   QStringLiteral("groupconnect")
#define SETTING_TEST_VOLT   QStringLiteral("volt")
#define SETTING_TEST_CURRENT    QStringLiteral("current")
#define SETTING_TEST_IRMIN  QStringLiteral("irlow")
#define SETTING_TEST_IRMAX  QStringLiteral("irhigh")
#define SETTING_TEST_COMP   QStringLiteral("compensation")
#define SETTING_TEST_TIME   QStringLiteral("testtime")
#define SETTING_TEST_CONNECT    QStringLiteral("connectmode")


jsonOperation::jsonOperation(QObject *parent) : QObject(parent)
{

}

int jsonOperation::readJsonfile(const QString &p_path, JsonData &p_data)
{
    QFileInfo fi(p_path);
    if(fi.isFile())
    {
        QFile jsonFile(p_path);
        bool bRet = jsonFile.open(QIODevice::ReadOnly);
        if(!bRet)
            return DEF_JSONERROR_OPEN;
        QJsonDocument doc = QJsonDocument::fromJson(jsonFile.readAll());
        if(doc.isNull())
            return DEF_JSONERROR_PRASEJSON;
        jsonFile.close();
        QJsonObject root = doc.object();
        p_data.testItemType = (JSON_STRUCTTYPE)root[SETTING_KEY_TYPE].toInt();
        if(p_data.testItemType == JSON_STRUCTTYPE::ENM_ITEM_SYSTEM)
        {
            SystemData sysData;
            sysData.strSerialPort = root[SETTING_SYSTEM_SERIALPORT].toString();
            sysData.nBaudrate = root[SETTING_SYSTEM_BAUDRATE].toInt();
            sysData.szTestfilePath = root[SETTING_SYSTEM_TESTFILE].toString();
            p_data.testItemData = QVariant::fromValue(sysData);
        }
        else if(p_data.testItemType == JSON_STRUCTTYPE::ENM_ITEM_TEST)
        {
            TestGroupData testData;
            setGroupData(testData.testGroupData, root[SETTING_KEY_GROUP].toObject());
            QJsonObject dataObj = root[SETTING_KEY_DATA].toObject();
            for(int i = 1; i <= DEF_TESTITEM_MAX; i++)
            {
                if(dataObj.contains(QString::number(i)))
                {
                    QJsonArray array = dataObj.value(QString::number(i)).toArray();
                    if(array.at(0).toInt() == (int)TEST_ITEM::ENM_ITEM_IR)
                    {
                        TestStepData stepData;
                        IrTestData irData;
                        stepData.testItemType = TEST_ITEM::ENM_ITEM_IR;
                        irData.fVolt = array.at(1).toDouble();
                        irData.fIrLow = array.at(2).toDouble();
                        irData.fIrHigh = array.at(3).toDouble();
                        irData.fTestTime = array.at(4).toDouble();
                        irData.fComp = array.at(5).toDouble();
                        irData.nConnectMode = array.at(6).toInt();
                        stepData.testData = QVariant::fromValue(irData);
                        testData.testDataList.append(stepData);
                        p_data.testItemData = QVariant::fromValue(testData);
                    }
                    else if(array.at(0).toInt() == (int)TEST_ITEM::ENM_ITEM_PEQ)
                    {
                        TestStepData stepData;
                        PeqTestData peqData;
                        stepData.testItemType = TEST_ITEM::ENM_ITEM_PEQ;
                        peqData.fCurrent = array.at(1).toDouble();
                        peqData.fIrLow = array.at(2).toDouble();
                        peqData.fIrHigh = array.at(3).toDouble();
                        peqData.fTestTime = array.at(4).toDouble();
                        peqData.fComp = array.at(5).toDouble();
                        peqData.nConnectMode = array.at(6).toInt();
                        stepData.testData = QVariant::fromValue(peqData);
                        testData.testDataList.append(stepData);
                        p_data.testItemData = QVariant::fromValue(testData);
                    }
                    else
                    {
                        return DEF_JSONERROR_UNKNOWNDATA;
                    }
                }
            }
        }
        else
        {
            return DEF_JSONERROR_UNKNOWNDATA;
        }
    }
    else
    {
        if(p_data.testItemType == JSON_STRUCTTYPE::ENM_ITEM_SYSTEM)
        {
            SystemData sysData;
            sysData.strSerialPort = "";
            sysData.nBaudrate = 9600;
            p_data.testItemData = QVariant::fromValue(sysData);
            return 0;
        }
        return DEF_JSONERROR_OPEN;
    }
    return 0;
}

int jsonOperation::writeJsonfile(const QString &p_path, const JsonData &p_data)
{
    QFile file(p_path);
    if(!file.open(QIODevice::WriteOnly))
    {
        return DEF_JSONERROR_OPEN;
    }
    QJsonObject root;
    if(p_data.testItemType == JSON_STRUCTTYPE::ENM_ITEM_SYSTEM)
    {
        root.insert(SETTING_KEY_TYPE, (int)JSON_STRUCTTYPE::ENM_ITEM_SYSTEM);
        SystemData sysData = p_data.testItemData.value<SystemData>();
        root.insert(SETTING_SYSTEM_SERIALPORT, sysData.strSerialPort);
        root.insert(SETTING_SYSTEM_BAUDRATE, sysData.nBaudrate);
        root.insert(SETTING_SYSTEM_TESTFILE, sysData.szTestfilePath);
        QJsonDocument doc(root);
        file.write(doc.toJson());
        file.close();
    }
    else if(p_data.testItemType == JSON_STRUCTTYPE::ENM_ITEM_TEST)
    {
        QJsonObject group, data;
        root.insert(SETTING_KEY_TYPE, (int)JSON_STRUCTTYPE::ENM_ITEM_TEST);
        TestGroupData groupData = p_data.testItemData.value<TestGroupData>();
        getGroupData(groupData.testGroupData, group);
        root.insert(SETTING_KEY_GROUP, group);
        for(int i = 0; i < groupData.testDataList.size(); i++)
        {
            if(groupData.testDataList.at(i).testItemType == TEST_ITEM::ENM_ITEM_IR)
            {
                IrTestData irData = groupData.testDataList.at(i).testData.value<IrTestData>();
                QJsonArray array;
                array.append((int)TEST_ITEM::ENM_ITEM_IR);
                array.append(irData.fVolt);
                array.append(irData.fIrLow);
                array.append(irData.fIrHigh);
                array.append(irData.fTestTime);
                array.append(irData.fComp);
                array.append(irData.nConnectMode);
                data.insert(QString::number(i + 1), QJsonValue(array));
            }
            else if(groupData.testDataList.at(i).testItemType == TEST_ITEM::ENM_ITEM_PEQ)
            {
                PeqTestData peqData = groupData.testDataList.at(i).testData.value<PeqTestData>();
                QJsonArray array;
                array.append((int)TEST_ITEM::ENM_ITEM_PEQ);
                array.append(peqData.fCurrent);
                array.append(peqData.fIrLow);
                array.append(peqData.fIrHigh);
                array.append(peqData.fTestTime);
                array.append(peqData.fComp);
                array.append(peqData.nConnectMode);
                data.insert(QString::number(i + 1), QJsonValue(array));
            }
            else
            {
                file.close();
                return DEF_JSONERROR_UNKNOWNDATA;
            }
        }
        root.insert(SETTING_KEY_DATA, data);
        QJsonDocument doc(root);
        file.write(doc.toJson());
        file.close();
    }
    else
    {
        file.close();
        return DEF_JSONERROR_UNKNOWNDATA;
    }
    return 0;
}

void jsonOperation::setGroupData(GroupData &p_group, const QJsonObject &p_jsonObj)
{
    p_group.nVoltFreq = p_jsonObj[SETTING_GROUP_FREQ].toInt();
    p_group.nFailStep = p_jsonObj[SETTING_GROUP_STEP].toInt();
    p_group.nPowerType = p_jsonObj[SETTING_GROUP_POWER].toInt();
    p_group.nGroupConnect = p_jsonObj[SETTING_GROUP_CONNECT].toInt();
}

void jsonOperation::getGroupData(const GroupData &p_group, QJsonObject &p_jsonObj)
{
    p_jsonObj.insert(SETTING_GROUP_FREQ, p_group.nVoltFreq);
    p_jsonObj.insert(SETTING_GROUP_STEP, p_group.nFailStep);
    p_jsonObj.insert(SETTING_GROUP_POWER, p_group.nPowerType);
    p_jsonObj.insert(SETTING_GROUP_CONNECT, p_group.nGroupConnect);
}
