#include "warningdialog.h"
#include "ui_warningdialog.h"

WarningDialog::WarningDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WarningDialog)
{
    this->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
    //this->setWindowFlags(this->windowFlags() & ~Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->setupUi(this);
}

WarningDialog::~WarningDialog()
{
    delete ui;
}

void WarningDialog::initWarning(const QString &p_title, const QString &p_content)
{
    ui->titleLab->setText(p_title);
    ui->textLab->setText(p_content);
}

void WarningDialog::on_okBtn_clicked()
{
    accept();
}

void WarningDialog::on_cancelBtn_clicked()
{
    reject();
}
