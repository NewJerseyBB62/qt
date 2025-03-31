#ifndef GENERALDIALOG_H
#define GENERALDIALOG_H

#include <QDialog>
#include "Common/commontest.h"
#include "Common/keyboardform.h"
#include <QMap>
#include "Common/warninglight.h"

namespace Ui {
class GeneralDialog;
}

class GeneralDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GeneralDialog(QWidget *parent = nullptr);
    ~GeneralDialog();
    void initTestMode(const int p_testmode);
    void setGeneral(const GeneralData &p_data);
    void setStepLadder(const StepLadderData &p_data);
    void setStep(const QList<StepData> &p_data);
    void setGradient(const QList<GradientData> &p_data);
    void setThrough(const QList<ThroughData> &p_data);
    void getCtrlInfo(const ConfigData &p_cfg);
    void setCtrlInfo(const int p_testmode, TestCtrl &p_cfg);

private slots:
    void slotDateTime(const QString p_datetime);
    void slotStopTest();
    void slotRecvData(const PrintData p_printdata);
    void slotKeyPressed(const int p_key);

    void on_backBtn_clicked();

    void on_backBtn2_clicked();

    void on_backBtn3_clicked();

    void on_backBtn4_clicked();

    void on_backBtn5_clicked();

    void on_currentStepNoCB_activated(int index);

    void on_outputModeCB_activated(int index);

    void on_voltageGearCB_activated(int index);

    void on_setDataBtn_clicked();

    void on_voltageSetLEU_editingFinished();

    void on_outputModeCB2_activated(int index);

    void on_setDataBtn2_clicked();

    void on_outputModeCB3_activated(int index);

    void on_setDataBtn3_clicked();

    void on_outputModeCB4_activated(int index);

    void on_setDataBtn4_clicked();

    void on_outputModeCB5_activated(int index);

    void on_setDataBtn5_clicked();

    void on_startBtn_clicked(bool checked);

    void on_startBtn2_clicked(bool checked);

    void on_startBtn3_clicked(bool checked);

    void on_startBtn4_clicked(bool checked);

    void on_startBtn5_clicked(bool checked);

private:
    void updateInfoWidget();
    void startStopBtn();
    void initThread();
    void uninitThread();
    void updatePrintUI(const int p_outputmode);
    void updateTestData(const int p_outputmode);
    QString getValueString(QStringList &p_list, const PrintData &p_data);
    void getSendData(const int p_testmode, QList<CanDataType> &p_senddata);
    void initSendData(const int p_testmode,
                      const int p_output, CanSendData &p_data);
    void initKeyBoard(const int p_x, const int p_y,
                      const int p_width, const int p_height);
    void uninitKeyBoard();

protected:
    bool eventFilter(QObject *watched, QEvent *event);

signals:
    void sigSaveCtrlInfo(const int p_testmode, const TestCtrl &p_ctrl);
    void sigResetLockTime();
    void sigSendData(const CanSendData p_senddata);

private:
    Ui::GeneralDialog *ui;
    int m_TestMode;
    bool m_TestingStatus;
    GeneralData m_GenralSet;
    StepLadderData m_StepLadderSet;
    QList<StepData> m_StepSet;
    QList<GradientData> m_GradientSet;
    QList<ThroughData> m_ThroughSet;
    TestCtrl m_TestCtrl;
    int m_DeviceTestingStatus;
    int m_StepNo[3];
    float m_IGBT;
    float m_Transformer;
    unsigned int m_FanSpeed;
    KeyboardForm *m_KeyBoard;
    QMap<QObject*, int> m_KeyboardMap;
    QObject* m_CurrentObj;          //当前焦点控件
    WarningLight m_WarnLight;
    int m_CurrentOutputMode;
};

#endif // GENERALDIALOG_H
