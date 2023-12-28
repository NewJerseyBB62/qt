#ifndef JSONOPERATION_H
#define JSONOPERATION_H

#include <QObject>
#include <QVariant>
#include "common.h"
#include <QJsonObject>

#define DEF_JSONERROR_OPEN 1
#define DEF_JSONERROR_PRASEJSON 2
#define DEF_JSONERROR_UNKNOWNDATA 3

typedef struct GroupItem{
    int nVoltFreq;
    int nFailStep;
    int nPowerType;
    int nGroupConnect;
}GroupData;

typedef struct IrItem{
    float fVolt;
    float fIrLow;
    float fIrHigh;
    float fTestTime;
    float fComp;
    int nConnectMode;   //0 继续 1 停止 2 单步
}IrTestData;

typedef struct PeqItem{
    float fCurrent;
    float fIrLow;
    float fIrHigh;
    float fTestTime;
    float fComp;
    int nConnectMode;   //0 继续 1 停止 2 单步
}PeqTestData;

typedef struct SystemItem{
    QString strSerialPort;
    int nBaudrate;
    QString szTestfilePath;
}SystemData;

typedef struct JsonStruct{
    JSON_STRUCTTYPE testItemType;
    QVariant testItemData;
}JsonData;

typedef struct TestItem{
    TEST_ITEM testItemType;
    QVariant testData;
}TestStepData;

typedef struct TestFileItem{
    GroupData testGroupData;
    QList<TestStepData> testDataList;
}TestGroupData;

Q_DECLARE_METATYPE(TestGroupData)
Q_DECLARE_METATYPE(SystemData)
Q_DECLARE_METATYPE(IrTestData)
Q_DECLARE_METATYPE(PeqTestData)

class jsonOperation : public QObject
{
    Q_OBJECT
public:
    explicit jsonOperation(QObject *parent = nullptr);

    int readJsonfile(const QString &p_path, JsonData &p_data);
    int writeJsonfile(const QString &p_path, const JsonData &p_data);

signals:

private:
    void setGroupData(GroupData &p_group, const QJsonObject &p_jsonObj);
    void getGroupData(const GroupData &p_group, QJsonObject &p_jsonObj);

public slots:
};

#endif // JSONOPERATION_H
