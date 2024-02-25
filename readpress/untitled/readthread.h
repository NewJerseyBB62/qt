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

protected:
    void run();

public slots:
    void SlotStart();
    void SlotStop();

signals:
    void SigRecvData(const float& p_data);

private:
    QSerialPort* m_SerialObj;
    QString m_Serialport;
    int m_Baudrate;
};

#endif // READTHREAD_H
