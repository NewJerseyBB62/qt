#ifndef JSONFILE_H
#define JSONFILE_H

#include <QObject>
#include <QJsonObject>

typedef struct SetData{
    QString serialport;
    int baudrate;
    float alamMax;
    float alamMin;
    float copeVal;
}SetStruct;

class jsonfile : public QObject
{
    Q_OBJECT
public:
    explicit jsonfile(QObject *parent = nullptr);

    int readJsonfile(const QString &p_path, SetStruct &p_data);
    int writeJsonfile(const QString &p_path, const SetStruct &p_data);
};

#endif // JSONFILE_H
