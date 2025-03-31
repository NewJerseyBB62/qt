#include "mainbtnform.h"
#include "ui_mainbtnform.h"
#include "Common/commontest.h"
#include <QDebug>

MainBtnForm::MainBtnForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainBtnForm)
{
    ui->setupUi(this);
    this->installEventFilter(this);
    ui->btnTextLab->installEventFilter(this);
    ui->iconLab->installEventFilter(this);
}

MainBtnForm::~MainBtnForm()
{
    delete ui;
}

void MainBtnForm::setBtnType(const int p_type)
{
    QString css;
    switch(p_type)
    {
    case ENM_TESTMODE_GENERAL:
        css = "border-image: url(:/png/main/icon_general.png);";
        ui->btnTextLab->setText(tr("常规"));
        break;
    case ENM_TESTMODE_STEPLADDER:
        css = "border-image: url(:/png/main/icon_stepladder.png);";
        ui->btnTextLab->setText(tr("阶梯"));
        break;
    case ENM_TESTMODE_STEP:
        css = "border-image: url(:/png/main/icon_step.png);";
        ui->btnTextLab->setText(tr("步阶"));
        break;
    case ENM_TESTMODE_GRADIENT:
        css = "border-image: url(:/png/main/icon_gradient.png);";
        ui->btnTextLab->setText(tr("渐变"));
        break;
    case ENM_TESTMODE_THROUGH:
        css = "border-image: url(:/png/main/icon_through.png);";
        ui->btnTextLab->setText(tr("低电压穿越"));
        break;
    case 5:
        css = "border-image: url(:/png/main/icon_set.png);";
        ui->btnTextLab->setText(tr("系统设置"));
        break;
    }
    this->setStyleSheet("#MainBtnForm{" \
                            "border-image: url(:/png/main/btn.png);}");
    ui->iconLab->setStyleSheet(css);
}

void MainBtnForm::setFont(const QString p_font, const int p_size, const int p_width, const QString p_color)
{
    QString font = "Ubuntu";
    int size = 18;
    int width = 600;
    QString color = "#0000F0";
    if(p_font.length() > 0)
        font = p_font;
    if(p_size > 0)
        size = p_size;
    if(p_width > 0)
        width = p_width;
    if(p_color.length() > 0)
        color = p_color;
    QString css = QString("font: %1 %2pt \"%3\";color: %4;").arg(font).arg(size).arg(width).arg(color);
    ui->btnTextLab->setStyleSheet(css);
}

void MainBtnForm::setBtnText(const QString p_text)
{
    ui->btnTextLab->setText(p_text);
}

bool MainBtnForm::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress)
    {
        qDebug() << " zzp press";
        emit sigPressed(true);
    }
    else if (event->type() == QEvent::MouseButtonRelease)
    {
        qDebug() << " zzp release";
        emit sigPressed(false);
    }
    return true;
}
