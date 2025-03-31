#ifndef LOCKDIALOG_H
#define LOCKDIALOG_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class LockDialog;
}

class LockDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LockDialog(QWidget *parent = nullptr);
    ~LockDialog();
    void initLockDialog(const QString &p_pwd, const bool p_istest);

private slots:
    void slotClearPwd();

    void on_btn0_pressed();

    void on_btn0_released();

    void on_btn1_pressed();

    void on_btn1_released();

    void on_btn2_pressed();

    void on_btn2_released();

    void on_btn3_pressed();

    void on_btn3_released();

    void on_btn4_pressed();

    void on_btn4_released();

    void on_btn5_pressed();

    void on_btn5_released();

    void on_btn6_pressed();

    void on_btn6_released();

    void on_btn7_pressed();

    void on_btn7_released();

    void on_btn8_pressed();

    void on_btn8_released();

    void on_btn9_pressed();

    void on_btn9_released();

    void on_okBtn_pressed();

    void on_okBtn_released();

    void on_stopBtn_pressed();

    void on_stopBtn_released();

signals:
    void sigStopTest();

private:
    void pressNumber(const int p_num);

private:
    Ui::LockDialog *ui;
    QString m_Pwd;
    QTimer m_Timer;
};

#endif // LOCKDIALOG_H
