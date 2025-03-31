#include "keyboardform.h"
#include "ui_keyboardform.h"

#define DEF_SCREEN_WIDTH 1280
#define DEF_SCREEN_HEIGHT 800
#define DEF_KEYBOARD_WIDTH 460
#define DEF_KEYBOARD_HEIGHT 360

KeyboardForm::KeyboardForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KeyboardForm)
{
    this->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::WindowDoesNotAcceptFocus |
                         Qt::FramelessWindowHint);
    //this->setWindowFlags(this->windowFlags() & ~Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->setupUi(this);
    ui->btn0->setFocusPolicy(Qt::FocusPolicy::NoFocus);
    ui->btn1->setFocusPolicy(Qt::FocusPolicy::NoFocus);
    ui->btn2->setFocusPolicy(Qt::FocusPolicy::NoFocus);
    ui->btn3->setFocusPolicy(Qt::FocusPolicy::NoFocus);
    ui->btn4->setFocusPolicy(Qt::FocusPolicy::NoFocus);
    ui->btn5->setFocusPolicy(Qt::FocusPolicy::NoFocus);
    ui->btn6->setFocusPolicy(Qt::FocusPolicy::NoFocus);
    ui->btn7->setFocusPolicy(Qt::FocusPolicy::NoFocus);
    ui->btn8->setFocusPolicy(Qt::FocusPolicy::NoFocus);
    ui->btn9->setFocusPolicy(Qt::FocusPolicy::NoFocus);
    ui->btnDot->setFocusPolicy(Qt::FocusPolicy::NoFocus);
    ui->btnMinus->setFocusPolicy(Qt::FocusPolicy::NoFocus);
    ui->btnDelete->setFocusPolicy(Qt::FocusPolicy::NoFocus);
}

KeyboardForm::~KeyboardForm()
{
    delete ui;
}

void KeyboardForm::setPos(const int x, const int y, const int p_width, const int p_height)
{
    int setX;
    int setY;
    m_X = x;
    m_Y = y;
    m_Height = p_height;

    if(DEF_SCREEN_WIDTH - x >= DEF_KEYBOARD_WIDTH)
    {
        setX = x - p_width;
        if(setX < 0)
            setX = 0;
    }
    else
    {
        setX = DEF_SCREEN_WIDTH - DEF_KEYBOARD_WIDTH;
    }
    if(DEF_SCREEN_HEIGHT - p_height - y >= DEF_KEYBOARD_HEIGHT)
    {
        setY = y + p_height;
    }
    else
    {
        setY = y - DEF_KEYBOARD_HEIGHT;
    }
    this->setGeometry(setX, setY, DEF_KEYBOARD_WIDTH, DEF_KEYBOARD_HEIGHT);
}

void KeyboardForm::on_btn0_clicked()
{
    emit sigKeyPressed(ENM_KEY_0);
}

void KeyboardForm::on_btn1_clicked()
{
    emit sigKeyPressed(ENM_KEY_1);
}

void KeyboardForm::on_btn2_clicked()
{
    emit sigKeyPressed(ENM_KEY_2);
}

void KeyboardForm::on_btn3_clicked()
{
    emit sigKeyPressed(ENM_KEY_3);
}

void KeyboardForm::on_btn4_clicked()
{
    emit sigKeyPressed(ENM_KEY_4);
}

void KeyboardForm::on_btn5_clicked()
{
    emit sigKeyPressed(ENM_KEY_5);
}

void KeyboardForm::on_btn6_clicked()
{
    emit sigKeyPressed(ENM_KEY_6);
}

void KeyboardForm::on_btn7_clicked()
{
    emit sigKeyPressed(ENM_KEY_7);
}

void KeyboardForm::on_btn8_clicked()
{
    emit sigKeyPressed(ENM_KEY_8);
}

void KeyboardForm::on_btn9_clicked()
{
    emit sigKeyPressed(ENM_KEY_9);
}

void KeyboardForm::on_btnDot_clicked()
{
    emit sigKeyPressed(ENM_KEY_Dot);
}

void KeyboardForm::on_btnMinus_clicked()
{
    emit sigKeyPressed(ENM_KEY_Minus);
}

void KeyboardForm::on_btnDelete_clicked()
{
    emit sigKeyPressed(ENM_KEY_Delete);
}

void KeyboardForm::on_btnEnter_clicked()
{
    emit sigKeyPressed(ENM_KEY_Enter);
}
