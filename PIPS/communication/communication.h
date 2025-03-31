#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <QObject>
#include <QThread>
#include <QMutex>
#include "communication/canprotocol.h"

class WriteThread : public QThread
{
    Q_OBJECT
public:
    static WriteThread *getWriteThread();
    static void closeWriteThread();
    void StartThread();
    void StopThread();
    void uninitWriteThread();

protected:
    void run();

signals:

public slots:
    void slotSendTestData(const CanSendData p_senddata);

private:
    explicit WriteThread();
    volatile bool m_ThreadStatus;
    QList<CanSendData> m_QueueBuff;
    QMutex m_QueueLock;
    CanProtocol *m_CanObj;
};


class ReadThread : public QThread
{
    Q_OBJECT
public:
    static ReadThread *getReadThread();
    static void closeReadThread();
    void StartThread();
    void StopThread();
    void uninitReadThread();

protected:
    void run();

signals:
    void sigReadTestData(const PrintData p_data);

private:
    explicit ReadThread();
    volatile bool m_ThreadStatus;
    CanProtocol *m_CanObj;
};

#endif // COMMUNICATION_H
