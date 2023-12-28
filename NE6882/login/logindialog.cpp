#include "logindialog.h"
#include "ui_logindialog.h"

loginDialog::loginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->showFullScreen();
}

loginDialog::~loginDialog()
{
    delete ui;
}


void loginDialog::on_loginBtn_clicked()
{
    done(Accepted);
    close();
}

void loginDialog::on_minBtn_clicked()
{
    this->showMinimized();
}

void loginDialog::on_closeBtn_clicked()
{
    done(Rejected);
    close();
}
