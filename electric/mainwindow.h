#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <setting/settingdialog.h>
#include <database/datadialog.h>
#include "database/dboperation.h"
#include <QMap>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void initUI();
    void initTestParamName();

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
    DbOperation *m_DbObj;
    QMap<int, QString> m_TestParamName;
};

#endif // MAINWINDOW_H
