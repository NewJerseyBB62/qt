#ifndef CANPROTOCOL_H
#define CANPROTOCOL_H

#include <QObject>
#include "Common/commontest.h"

extern "C" {
#include <linux/can.h>
}

union CanID{
    unsigned int ID;
    struct{
      unsigned int index : 12;
      unsigned int cmd : 8;
      unsigned int type : 4;
      unsigned int addr : 5;
    };
};

union FloatValue{
    float fValue;
    struct{
      unsigned char byte1;
      unsigned char byte2;
      unsigned char byte3;
      unsigned char byte4;
    };
};

union IntValue{
    float nValue;
    struct{
      unsigned char byte1;
      unsigned char byte2;
      unsigned char byte3;
      unsigned char byte4;
    };
};

class CanProtocol : public QObject
{
    Q_OBJECT
public:
    CanProtocol();
    int initCan(const QString &p_can = "can2", const int p_rate = 500000);
    void uninitCan();
    int readCan(QList<struct can_frame> &p_canList);
    int writeCan(const CanSendData &p_data);

private:
    //QCanBusDevice *m_CanDevice;
    int m_Socket;
    QString m_Can;
};

#endif // CANPROTOCOL_H
