#ifndef KEYBOARDFORM_H
#define KEYBOARDFORM_H

#include <QWidget>


enum KEY_TYPE{
    ENM_KEY_0 = 0,
    ENM_KEY_1,
    ENM_KEY_2,
    ENM_KEY_3,
    ENM_KEY_4,
    ENM_KEY_5,
    ENM_KEY_6,
    ENM_KEY_7,
    ENM_KEY_8,
    ENM_KEY_9,
    ENM_KEY_Dot,
    ENM_KEY_Minus,
    ENM_KEY_Delete,
    ENM_KEY_Enter
};


namespace Ui {
class KeyboardForm;
}

class KeyboardForm : public QWidget
{
    Q_OBJECT

public:
    explicit KeyboardForm(QWidget *parent = nullptr);
    ~KeyboardForm();
    void setPos(const int x, const int y, const int p_width, const int p_height);

signals:
    void sigKeyPressed(const int p_key);

private slots:
    void on_btn0_clicked();

    void on_btn1_clicked();

    void on_btn2_clicked();

    void on_btn3_clicked();

    void on_btn4_clicked();

    void on_btn5_clicked();

    void on_btn6_clicked();

    void on_btn7_clicked();

    void on_btn8_clicked();

    void on_btn9_clicked();

    void on_btnDot_clicked();

    void on_btnMinus_clicked();

    void on_btnDelete_clicked();
    void on_btnEnter_clicked();

private:
    Ui::KeyboardForm *ui;
    int m_X;
    int m_Y;
    int m_Height;
};

#endif // KEYBOARDFORM_H
