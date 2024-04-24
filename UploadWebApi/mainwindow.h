#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "handlethread.h"
#include "inioperation.h"
#include <QThread>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void initMainWindow();
    ~MainWindow();

public slots:
    void slotStatus(int p_status, const QString &p_errInfo);
    void slotSendData(const QByteArray &p_data);

private slots:
    void on_startBtn_clicked();

    void on_stopBtn_clicked();

    void on_logCB_toggled(bool checked);


private:
    Ui::MainWindow *ui;
    iniOperation *m_IniObj;
    IniStruct m_IniData;
    HandleThread *m_Thread;
    bool m_LogCheck;
};

#endif // MAINWINDOW_H
