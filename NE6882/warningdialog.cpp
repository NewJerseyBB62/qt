#include "warningdialog.h"
#include "ui_warningdialog.h"
#include <QGraphicsDropShadowEffect>

WarningDialog::WarningDialog(QString p_warning, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WarningDialog)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
    //设置阴影距离
    shadow->setOffset(0, 0);
    //设置阴影颜色
    shadow->setColor(QColor("#444444"));
    //设置阴影圆角
    shadow->setBlurRadius(20);
    //给嵌套QWidget设置阴影
    ui->widget->setGraphicsEffect(shadow);
    //给垂直布局器设置边距(此步很重要, 设置宽度为阴影的宽度)
    ui->widget->setContentsMargins(1,1,1,1);
    ui->WarningVal->setText(p_warning);
}

WarningDialog::~WarningDialog()
{
    delete ui;
}

void WarningDialog::on_okBnt_clicked()
{
    close();
    return;
}
