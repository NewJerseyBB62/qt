#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "readthread.h"
#include "jsonfile.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void init();

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void SlotRecvData(const float& p_val);

private:
    void initSerialPort();
    void ReadSetting(SetData &p_data);
    void WriteSetting(const SetData &p_data);

private:
    Ui::MainWindow *ui;
    Readthread *m_ReadthreadObj;
    SetStruct m_SetData;

};
#endif // MAINWINDOW_H
