#ifndef LOCKMANAGER_H
#define LOCKMANAGER_H

#include <QObject>
#include <QThread>
#include "Common/lockdialog.h"
#include <QMutex>

class LockManager : public QThread
{
    Q_OBJECT
public:
    static LockManager *getRtcInstance();
    static void closeRtcInstance();
    void updateTestStatus(const bool p_status);
    void updateLockTime(const int p_time);
    void updateLockPwd(const QString &p_pwd);
    void startLockThread();
    void stopLockThread();
    bool getThreadStatus();
    void setParent(QWidget *parent);

signals:
    void sigStartLock();
    void sigStopTest();

public slots:
    void slotStartLock();
    void slotResetLockTime();
    void slotStopTest();

protected:
    void run();

private:
    explicit LockManager(QObject *parent = nullptr);

private:
    bool m_TestStatus;
    volatile int m_LockTime;
    volatile int m_LockTimeCnt;
    QString m_LockPwd;
    LockDialog *m_LockDialog;
    QMutex m_TimeMutex;
    QWidget *m_Parent;
};

#endif // LOCKMANAGER_H
