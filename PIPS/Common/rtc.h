#ifndef RTC_H
#define RTC_H

#include <QObject>
#include <QThread>

class rtc : public QThread
{
    Q_OBJECT
public:
    static rtc *getRtcInstance();
    static void closeRtcInstance();

signals:
    void sigTimeChanged(const QString p_datatime);

protected:
    void run();

public slots:

private:
    explicit rtc(QObject *parent = nullptr);
};

#endif // RTC_H
