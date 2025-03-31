#include "warninglight.h"

#define DEF_GPIO_GREEN "108"
#define DEF_GPIO_YELLOW "104"
#define DEF_GPIO_RED "107"

WarningLight::WarningLight(QObject *parent) : QObject(parent)
{
    m_Duration = 0;
    m_Timer = nullptr;
}

WarningLight::~WarningLight()
{
    if(m_Timer != nullptr)
    {
        m_Timer->stop();
        delete m_Timer;
    }
}

void WarningLight::startLight(const int p_status)
{
    char green[64] = {0};
    char yellow[64] = {0};
    char red[64] = {0};
    sprintf(green, "echo %s > /sys/class/gpio/export",
            DEF_GPIO_GREEN);
    sprintf(yellow, "echo %s > /sys/class/gpio/export",
            DEF_GPIO_YELLOW);
    sprintf(red, "echo %s > /sys/class/gpio/export",
            DEF_GPIO_RED);
    system(green);
    system(yellow);
    system(red);
    sprintf(green, "echo out > /sys/class/gpio/gpio%s/direction",
           DEF_GPIO_GREEN);
    sprintf(yellow, "echo out > /sys/class/gpio/gpio%s/direction",
           DEF_GPIO_YELLOW);
    sprintf(red, "echo out > /sys/class/gpio/gpio%s/direction",
           DEF_GPIO_RED);
    system(green);
    system(yellow);
    system(red);
    switch(p_status)
    {
    case ENM_LIGHT_GREEN:
        sprintf(green, "echo 1 > /sys/class/gpio/gpio%s/value",
               DEF_GPIO_GREEN);
        sprintf(yellow, "echo 0 > /sys/class/gpio/gpio%s/value",
               DEF_GPIO_YELLOW);
        sprintf(red, "echo 0 > /sys/class/gpio/gpio%s/value",
               DEF_GPIO_RED);
        system(yellow);
        system(red);
        system(green);
        break;
    case ENM_LIGHT_YELLOW:
        sprintf(green, "echo 0 > /sys/class/gpio/gpio%s/value",
               DEF_GPIO_GREEN);
        sprintf(yellow, "echo 1 > /sys/class/gpio/gpio%s/value",
               DEF_GPIO_YELLOW);
        sprintf(red, "echo 0 > /sys/class/gpio/gpio%s/value",
               DEF_GPIO_RED);
        system(red);
        system(green);
        system(yellow);
        break;
    case ENM_LIGHT_RED:
    {
        sprintf(green, "echo 0 > /sys/class/gpio/gpio%s/value",
               DEF_GPIO_GREEN);
        sprintf(yellow, "echo 0 > /sys/class/gpio/gpio%s/value",
               DEF_GPIO_YELLOW);
        sprintf(red, "echo 1 > /sys/class/gpio/gpio%s/value",
               DEF_GPIO_RED);
        system(yellow);
        system(green);
        system(red);
        if(m_Duration > 0)
        {
            if(m_Timer == nullptr)
                m_Timer = new QTimer();
            connect(m_Timer, &QTimer::timeout, this, &WarningLight::slotTimeout);
            m_Timer->stop();
            m_Timer->setSingleShot(true);
            m_Timer->setInterval(m_Duration * 1000);
            m_Timer->start();
        }
    }
        break;
    }
    sprintf(green, "echo %s > /sys/class/gpio/unexport",
           DEF_GPIO_GREEN);
    sprintf(yellow, "echo %s > /sys/class/gpio/unexport",
           DEF_GPIO_YELLOW);
    sprintf(red, "echo %s > /sys/class/gpio/unexport",
           DEF_GPIO_RED);
    system(green);
    system(yellow);
    system(red);
}

void WarningLight::stopLight()
{
    char green[64] = {0};
    char yellow[64] = {0};
    char red[64] = {0};
    sprintf(green, "echo %s > /sys/class/gpio/export",
            DEF_GPIO_GREEN);
    sprintf(yellow, "echo %s > /sys/class/gpio/export",
            DEF_GPIO_YELLOW);
    sprintf(red, "echo %s > /sys/class/gpio/export",
            DEF_GPIO_RED);
    system(green);
    system(yellow);
    system(red);
    sprintf(green, "echo out > /sys/class/gpio/gpio%s/direction",
           DEF_GPIO_GREEN);
    sprintf(yellow, "echo out > /sys/class/gpio/gpio%s/direction",
           DEF_GPIO_YELLOW);
    sprintf(red, "echo out > /sys/class/gpio/gpio%s/direction",
           DEF_GPIO_RED);
    system(green);
    system(yellow);
    system(red);
    sprintf(green, "echo 0 > /sys/class/gpio/gpio%s/value",
           DEF_GPIO_GREEN);
    sprintf(yellow, "echo 0 > /sys/class/gpio/gpio%s/value",
           DEF_GPIO_YELLOW);
    sprintf(red, "echo 0 > /sys/class/gpio/gpio%s/value",
           DEF_GPIO_RED);
    system(green);
    system(yellow);
    system(red);
    sprintf(green, "echo %s > /sys/class/gpio/unexport",
           DEF_GPIO_GREEN);
    sprintf(yellow, "echo %s > /sys/class/gpio/unexport",
           DEF_GPIO_YELLOW);
    sprintf(red, "echo %s > /sys/class/gpio/unexport",
           DEF_GPIO_RED);
    system(green);
    system(yellow);
    system(red);
}

void WarningLight::setRedLightDuration(const int p_duration)
{
    m_Duration = p_duration;
}

void WarningLight::slotTimeout()
{
    char red[64] = {0};
    sprintf(red, "echo %s > /sys/class/gpio/export",
            DEF_GPIO_RED);
    system(red);
    sprintf(red, "echo out > /sys/class/gpio/gpio%s/direction",
           DEF_GPIO_RED);
    system(red);
    sprintf(red, "echo 0 > /sys/class/gpio/gpio%s/value",
           DEF_GPIO_RED);
    system(red);
    sprintf(red, "echo %s > /sys/class/gpio/unexport",
           DEF_GPIO_RED);
    system(red);
    m_Timer->stop();
    delete m_Timer;
}
