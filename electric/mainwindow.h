#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <setting/settingdialog.h>
#include <database/datadialog.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_closeBtn_clicked();

    void on_dataBtn_clicked();

    void on_settingBtn_clicked();

    void on_minBtn_clicked();

    void on_maxBtn_clicked();

private:
    Ui::MainWindow *ui;
    SettingDialog *m_SettingObj;
    DataDialog *m_DataObj;
};

#endif // MAINWINDOW_H
