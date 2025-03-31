#include "rtc.h"
#include <QProcess>

static rtc *gInstance = nullptr;
static volatile bool gStopThread = false;

rtc *rtc::getRtcInstance()
{
    if(gInstance == nullptr)
    {
        gInstance = new rtc();
        gStopThread = false;
        gInstance->start();
    }
    return gInstance;
}

void rtc::closeRtcInstance()
{
    if(gInstance == nullptr)
        return;
    gInstance->quit();
    gStopThread = true;
    //QThread::sleep(1);
    gInstance->wait();
    //gInstance->deleteLater();
    delete gInstance;
    gInstance = nullptr;
}

void rtc::run()
{
    QProcess process;
    QString datetime;
    while(1)
    {
        if(gStopThread)
            return;
        process.start("cat /sys/class/rtc/rtc0/date\n");
        //process.execute("cat /sys/class/rtc/rtc0/date\n");
        //process.waitForReadyRead(500);
        process.waitForStarted();
        process.waitForFinished();
        datetime = process.readAllStandardOutput();
        datetime.replace(datetime.indexOf('\n'), 1, ' ');
        //process.execute("cat /sys/class/rtc/rtc0/time\n");
        process.start("cat /sys/class/rtc/rtc0/time\n");
        process.waitForStarted();
        process.waitForFinished();
        datetime += process.readAllStandardOutput();
        //datetime.replace(datetime.indexOf('\n'), 1, '\0');
        //process.close();
        emit sigTimeChanged(datetime.left(datetime.length() - 1));
        QThread::msleep(500);
    }
    process.close();
}

rtc::rtc(QObject *parent)
{

}
