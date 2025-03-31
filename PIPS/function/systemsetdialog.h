#ifndef SYSTEMSETDIALOG_H
#define SYSTEMSETDIALOG_H

#include <QDialog>
#include "Common/commontest.h"
#include "Common/keyboardform.h"
#include <QMap>

enum SettingPage{
    ENM_PAGE_UNKNOWN = -1,
    ENM_PAGE_SYSTEM,
    ENM_PAGE_HARMONICS,
    ENM_PAGE_ALARM,
    ENM_PAGE_NETWORK,
    ENM_PAGE_USER,
    ENM_PAGE_ADVANCE
};

namespace Ui {
class SystemSetDialog;
}

class SystemSetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SystemSetDialog(QWidget *parent = nullptr);
    ~SystemSetDialog();
    void initSetting(const ConfigData &p_cfg);
    void getSetting(ConfigData &p_cfg);

private slots:
    void slotDateTime(const QString p_datetime);
    void slotRecvData(const PrintData p_printdata);
    void slotKeyPressed(const int p_key);

    void on_saveBtn_clicked();

    void on_backBtn_clicked();

    void on_systemBtn_clicked(bool checked);

    void on_harmonicsBtn_clicked(bool checked);

    void on_alarmBtn_clicked(bool checked);

    void on_networkBtn_clicked(bool checked);

    void on_userBtn_clicked(bool checked);

    void on_advanceBtn_clicked(bool checked);

    void on_harmonicsGroupCB_activated(int index);

    void on_harmonicsTimesCB_activated(int index);

    void on_percentLE_editingFinished();

    void on_angleLE_editingFinished();

    void on_resetBtn_clicked();

    void on_signinBtn_clicked();

    void on_harmonTable_cellClicked(int row, int column);

    void on_refreshExportBtn_clicked();

    void on_exportBtn_clicked();

    void on_efreshImportBtn_clicked();

    void on_importBtn_clicked();

    void on_harmonicsSaveBtn_clicked();

    void on_alarmPreBtn_clicked();

    void on_alarmNextBtn_clicked();

    void on_alarmClearBtn_clicked();

    void on_logPreBtn_clicked();

    void on_logNextBtn_clicked();

    void on_logClearBtn_clicked();

private:
    void setBtnStatus(const int p_type, const bool p_state);
    void data2ui();
    void ui2data();
    void harmonics2ui();
    void harmonics2data();
    void harmonicsRowSelect(const int p_row);
    void initHarmonicsTable();
    void readHarmonics(const int p_group);
    void initUdisk(const int p_type);
    void readDB();
    void initLogTable();
    void log2ui();
    QString getLogText(const int p_log);
    void updateLogBtnStatus();
    void initThread();
    void uninitThread();
    void initKeyBoard(const int p_x, const int p_y,
                      const int p_width, const int p_height);
    void uninitKeyBoard();

signals:
    void sigResetLockTime();
    void sigSendData(const CanSendData p_senddata);

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private:
    Ui::SystemSetDialog *ui;
    int m_CurrentPage;
    QList<HarmonicsData> m_HarmonicsData;
    ConfigData m_ConfigData;
    int m_HarmonicsGroup;
    bool m_HarmonicsNeedSave;
    int m_CurrentAlarmPage;
    int m_CurrentLogPage;
    QList<LogData> m_LogData;
    float m_IGBT;
    float m_Transformer;
    unsigned int m_FanSpeed;
    KeyboardForm *m_KeyBoard;
    QMap<QObject*, int> m_KeyboardMap;
    QObject* m_CurrentObj;
};

#endif // SYSTEMSETDIALOG_H
