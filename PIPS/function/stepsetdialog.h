#ifndef STEPSETDIALOG_H
#define STEPSETDIALOG_H

#include <QDialog>
#include "Common/commontest.h"
#include "Common/keyboardform.h"
#include <QMap>

namespace Ui {
class StepSetDialog;
}

class StepSetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StepSetDialog(QWidget *parent = nullptr);
    ~StepSetDialog();
    void setData(const TestCtrl &p_ctrl, const QList<StepData> &p_data);
    void getData(TestCtrl &p_ctrl, QList<StepData> &p_data);

private slots:
    void slotDateTime(const QString p_datetime);
    void slotKeyPressed(const int p_key);

    void on_saveBtn_clicked();

    void on_backBtn_clicked();

    void on_jumpLE_editingFinished();

    void on_tableWidget_cellClicked(int row, int column);

    void on_voltageLEU_editingFinished();

    void on_voltageLEV_editingFinished();

    void on_voltageLEW_editingFinished();

    void on_freqLEU_editingFinished();

    void on_freqLEV_editingFinished();

    void on_freqLEW_editingFinished();

    void on_harmonicsCBU_activated(int index);

    void on_harmonicsCBV_activated(int index);

    void on_harmonicsCBW_activated(int index);

    void on_timeLEU_editingFinished();

    void on_timeLEV_editingFinished();

    void on_timeLEW_editingFinished();

    void on_angleLE1_editingFinished();

    void on_angleLE2_editingFinished();

private:
    void updateOutputMode(const int p_outputmode);
    void Table2Ui(const int p_row);
    void ui2Table(const int p_col, const QString &p_val);
    void data2Table();
    void table2Data();
    void initKeyBoard(const int p_x, const int p_y,
                      const int p_width, const int p_height);
    void uninitKeyBoard();

signals:
    void sigResetLockTime();

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private:
    Ui::StepSetDialog *ui;
    QList<StepData> m_Data;
    int m_OutputMode;
    KeyboardForm *m_KeyBoard;
    QMap<QObject*, int> m_KeyboardMap;
    QObject* m_CurrentObj;
};

#endif // STEPSETDIALOG_H
