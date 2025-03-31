#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Common/commontest.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void readConfig();
    void setHarmonics();

private slots:
    void slotSaveCtrlInfo(const int p_testmode, const TestCtrl &p_ctrl);
    void slotDateTime(const QString p_datetime);

signals:
    void sigResetLockTime();
    void sigSendData(const CanSendData p_senddata);

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private:
    void on_setBtn_clicked();
    void on_generalBtn_clicked();
    void on_stepLadderBtn_clicked();
    void on_stepBtn_clicked();
    void on_gradientBtn_clicked();
    void on_throughBtn_clicked();
    void changeQSS(const bool pressed, const int p_type);

private:
    Ui::MainWindow *ui;
    ConfigData m_Config;
};

#endif // MAINWINDOW_H
