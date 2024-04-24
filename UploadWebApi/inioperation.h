#ifndef INIOPERATION_H
#define INIOPERATION_H

#include <QObject>
#include "common.h"


class iniOperation : public QObject
{
    Q_OBJECT
public:
    explicit iniOperation(QObject *parent = nullptr);
    int readIniFile(const QString &p_path, IniStruct &p_data);
    int writeIniFile(const QString &p_path, const IniStruct &p_data);

signals:

public slots:
};

#endif // INIOPERATION_H
