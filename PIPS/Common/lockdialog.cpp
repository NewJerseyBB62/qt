#include "lockdialog.h"
#include "ui_lockdialog.h"

LockDialog::LockDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LockDialog)
{
    this->setGeometry(0, 0, 1280, 800);
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    //this->setAttribute(Qt::WA_TranslucentBackground);
    this->setWindowOpacity(0.5);
    ui->pwdLE->setEchoMode(QLineEdit::Password);
}

LockDialog::~LockDialog()
{
    delete ui;
}

void LockDialog::initLockDialog(const QString &p_pwd, const bool p_istest)
{
    m_Pwd = p_pwd;
    connect(&m_Timer, &QTimer::timeout, this, &LockDialog::slotClearPwd);
    if(!p_istest)
        ui->stopBtn->setVisible(false);
}

void LockDialog::slotClearPwd()
{
    ui->pwdLE->clear();
    //ui->pwdLE->setText("");
    m_Timer.stop();
}

void LockDialog::pressNumber(const int p_num)
{
    if(ui->pwdLE->text().length() >= 4)
        return;
    QString pwd = ui->pwdLE->text();
    pwd.append('0' + p_num);
    ui->pwdLE->setText(pwd);
    if(pwd.length() >= 4)
    {
        on_okBtn_released();
    }
}

void LockDialog::on_btn0_pressed()
{
    ui->btn0->setIcon(QIcon(":/png/main/01.png"));
}

void LockDialog::on_btn0_released()
{
    ui->btn0->setIcon(QIcon(":/png/main/0.png"));
    pressNumber(0);
}

void LockDialog::on_btn1_pressed()
{
    ui->btn1->setIcon(QIcon(":/png/main/11.png"));
}

void LockDialog::on_btn1_released()
{
    ui->btn1->setIcon(QIcon(":/png/main/1.png"));
    pressNumber(1);
}

void LockDialog::on_btn2_pressed()
{
    ui->btn2->setIcon(QIcon(":/png/main/21.png"));
}

void LockDialog::on_btn2_released()
{
    ui->btn2->setIcon(QIcon(":/png/main/2.png"));
    pressNumber(2);
}

void LockDialog::on_btn3_pressed()
{
    ui->btn3->setIcon(QIcon(":/png/main/31.png"));
}

void LockDialog::on_btn3_released()
{
    ui->btn3->setIcon(QIcon(":/png/main/1.png"));
    pressNumber(3);
}

void LockDialog::on_btn4_pressed()
{
    ui->btn4->setIcon(QIcon(":/png/main/41.png"));
}

void LockDialog::on_btn4_released()
{
    ui->btn4->setIcon(QIcon(":/png/main/4.png"));
    pressNumber(4);
}

void LockDialog::on_btn5_pressed()
{
    ui->btn5->setIcon(QIcon(":/png/main/51.png"));
}

void LockDialog::on_btn5_released()
{
    ui->btn5->setIcon(QIcon(":/png/main/5.png"));
    pressNumber(5);
}

void LockDialog::on_btn6_pressed()
{
    ui->btn6->setIcon(QIcon(":/png/main/61.png"));
}

void LockDialog::on_btn6_released()
{
    ui->btn6->setIcon(QIcon(":/png/main/6.png"));
    pressNumber(6);
}

void LockDialog::on_btn7_pressed()
{
    ui->btn7->setIcon(QIcon(":/png/main/71.png"));
}

void LockDialog::on_btn7_released()
{
    ui->btn7->setIcon(QIcon(":/png/main/7.png"));
    pressNumber(7);
}

void LockDialog::on_btn8_pressed()
{
    ui->btn8->setIcon(QIcon(":/png/main/81.png"));
}

void LockDialog::on_btn8_released()
{
    ui->btn8->setIcon(QIcon(":/png/main/8.png"));
    pressNumber(8);
}

void LockDialog::on_btn9_pressed()
{
    ui->btn9->setIcon(QIcon(":/png/main/91.png"));
}

void LockDialog::on_btn9_released()
{
    ui->btn9->setIcon(QIcon(":/png/main/9.png"));
    pressNumber(9);
}

void LockDialog::on_okBtn_pressed()
{
    ui->okBtn->setIcon(QIcon(":/png/main/lock1.png"));
}

void LockDialog::on_okBtn_released()
{
    ui->okBtn->setIcon(QIcon(":/png/main/lock.png"));
    if(ui->pwdLE->text().length() < 4)
        return;
    if(m_Pwd == ui->pwdLE->text())
        accept();
    m_Timer.setSingleShot(true);
    m_Timer.setInterval(1000);
    m_Timer.start();
    return;
}

void LockDialog::on_stopBtn_pressed()
{

}

void LockDialog::on_stopBtn_released()
{
    emit sigStopTest();
}
