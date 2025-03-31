#ifndef PHYSICALKEY_H
#define PHYSICALKEY_H

#include <QObject>
#include <QThread>


enum PHYSICALKEY{
    ENM_PHYSICALKEY_UNKNOWN = 0xA0,
    ENM_PHYSICALKEY_START,
    ENM_PHYSICALKEY_STOP,
    ENM_PHYSICALKEY_PRESS,
    ENM_PHYSICALKEY_LEFT,
    ENM_PHYSICALKEY_RIGHT
};

class PhysicalKey : public QThread
{
    Q_OBJECT
public:
    explicit PhysicalKey(QObject *parent = nullptr);
    void initPhysicalKey();
    void startThread();
    void stopThread();
    void closeThread();

protected:
    void run();

signals:
    void sigRecvBtn(const int p_btn);

public slots:

private:
    void handleRotation();

private:
    bool m_ThreadStatus;
    bool m_ThreadStart;
    int m_FDList[5];
};

#endif // PHYSICALKEY_H
