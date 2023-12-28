#ifndef NE6882SERIAL_H
#define NE6882SERIAL_H
#include "QObject"

#include "ne6882serial_global.h"
#include <QThread>
#include <QList>
#include <QMutex>
#include <QSerialPort>

class SerialThread : public QThread
{
    Q_OBJECT
public:
    SerialThread();
    int InitSerialThread(const QString& p_port, const int p_baud, const int p_timeout = 500, requsetCallback p_callback = nullptr, const unsigned int p_user = 0);
    int SendCmd(const NE6882Msg& p_data);
    int SetThreadRun(bool p_state);

public slots:
    void SlotRecvData();

protected:
    void run();

private:
    int ParseSendCmd(const NE6882Msg& p_data, QByteArray *p_senddata, int &p_recvlen);
    int ParseRecvCmd(const QByteArray& p_data);
    quint8 CheckSum(const QByteArray& p_data);
    void SetCmdData(QByteArray* p_data, const float p_val, const int num);
    NE6882_STATE GetGroupState(int p_state);
    NE6882_STATE GetStepState(int p_state);

private:
    QList<NE6882Msg> m_CmdList;
    QMutex m_Mutex;
    bool m_ThreadRun;
    QSerialPort* m_SerialObj;
    QString m_SerialPort;
    int m_Baudrate;
    requsetCallback m_Func;
    unsigned int m_User;
    int m_AckAttempts;
    int m_ReadTimeout;
};

class NE6882SERIALSHARED_EXPORT Ne6882serial : QObject
{
    Q_OBJECT
public:
    Ne6882serial();
    ~Ne6882serial();

    int InitNe6882Serial(const QString p_port, const int p_baud, const int p_timeout = 500, requsetCallback p_callback = nullptr, const unsigned int p_user = 0);
    void StartRun();
    void StopRun();
    int SendCmd(const NE6882Msg p_data);
    void CloseNe6882Serial();

private:
    SerialThread* m_SerialObj;


};

#endif // NE6882SERIAL_H
