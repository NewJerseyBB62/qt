#ifndef TESTTHREAD_H
#define TESTTHREAD_H

#include <QObject>
#include <QThread>
#include "ne6882serial.h"
#include "ne6882serial_global.h"


class TestThread : public QObject
{
    Q_OBJECT

public:
    TestThread();

    int initThread(const QString p_port, const int p_baud, const int p_timeout);
    void closeThread();
    void handRecv(const NE6882Msg p_data);

public slots:
    void slotStartRun();
    void slotStopRun();
    void slotSendCmd(const NE6882Msg p_data);

signals:
    void sigRecv(const NE6882Msg);


private:
    Ne6882serial *m_SerialObj;
};

#endif // TESTTHREAD_H
