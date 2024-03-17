#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "readthread.h"
#include "jsonfile.h"
#include "datadialog.h"
#include "database.h"

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

protected:
    void closeEvent(QCloseEvent *);

signals:
    void SigSendData(const SqlData &p_data);
    void SigSaveTime(const int &p_time);

public slots:
    void SlotRecvData(const float& p_val, const QByteArray &p_data);
    void SlotCloseDataObj();

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();

    void on_baudCB_currentTextChanged(const QString &arg1);

    void on_alamMaxLE_textChanged(const QString &arg1);

    void on_alamMinLE_textChanged(const QString &arg1);

    void on_copeLE_textChanged(const QString &arg1);

    void on_serialCB_currentIndexChanged(const QString &arg1);

    void on_savetimeCB_activated(int index);

private:
    void initSerialPort();
    void ReadSetting(SetData &p_data);
    void WriteSetting(const SetData &p_data);
    int GetSavetime(int index);
    int GetSavetimeIdx(int time);

private:
    Ui::MainWindow *ui;
    Readthread *m_ReadthreadObj;
    SetStruct m_SetData;
    jsonfile *m_JsonObj;
    DataDialog *m_DataObj;
    Database *m_DatabaseObj;

};
#endif // MAINWINDOW_H
