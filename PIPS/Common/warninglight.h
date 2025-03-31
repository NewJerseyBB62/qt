#ifndef WARNINGLIGHT_H
#define WARNINGLIGHT_H

#include <QObject>
#include <QTimer>

enum LIGHTTYPE{
    ENM_LIGHT_UNKNOWN = 0x91,
    ENM_LIGHT_GREEN,
    ENM_LIGHT_YELLOW,
    ENM_LIGHT_RED
};

class WarningLight : public QObject
{
    Q_OBJECT
public:
    explicit WarningLight(QObject *parent = nullptr);
    ~WarningLight();
    void startLight(const int p_status);
    void stopLight();
    void setRedLightDuration(const int p_duration);

signals:

public slots:
    void slotTimeout();

private:
    int m_CurrentStatus;
    int m_Duration;
    QTimer *m_Timer;
};

#endif // WARNINGLIGHT_H
