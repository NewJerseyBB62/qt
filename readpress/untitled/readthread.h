#ifndef READTHREAD_H
#define READTHREAD_H

#include <QObject>
#include <QThread>
#include <QSerialPort>



class Readthread : public QThread
{
    Q_OBJECT
public:
    Readthread(const QString& serialport, const int& baud);
    int initReadthread();
    int uninitReadthread();
    int SlotStart();
    void SlotStop();
    void SetSerialport(const QString& serialport, const int& baud);

protected:
    void run();


signals:
    void SigRecvData(const float& p_val, const QByteArray &p_data);

private:
    QSerialPort* m_SerialObj;
    QString m_Serialport;
    int m_Baudrate;
    bool m_threadRun;
};

#endif // READTHREAD_H
