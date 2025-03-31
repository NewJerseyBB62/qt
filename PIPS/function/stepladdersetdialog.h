#ifndef STEPLADDERSETDIALOG_H
#define STEPLADDERSETDIALOG_H

#include <QDialog>
#include "Common/commontest.h"
#include "Common/keyboardform.h"
#include <QMap>

namespace Ui {
class StepLadderSetDialog;
}

class StepLadderSetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StepLadderSetDialog(QWidget *parent = nullptr);
    ~StepLadderSetDialog();
    void setData(const StepLadderData &p_data);
    const StepLadderData getData();

private slots:
    void slotDateTime(const QString p_datetime);
    void slotKeyPressed(const int p_key);

    void on_saveBtn_clicked();

    void on_backBtn_clicked();

    void on_voltageStartLEU_editingFinished();

    void on_voltageStepLEU_editingFinished();

    void on_freqStartLEU_editingFinished();

    void on_freqStepLEU_editingFinished();

    void on_harmonicsCBU_activated(int index);

    void on_timeLEU_editingFinished();

    void on_angleLE1_editingFinished();

private:
    void updateData();
    void updateOutputMode(const int p_outputmode);
    void data2Ui(const StepLadderData &p_data);
    void ui2Data(StepLadderData &p_data);
    void initKeyBoard(const int p_x, const int p_y,
                      const int p_width, const int p_height);
    void uninitKeyBoard();

signals:
    void sigResetLockTime();

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private:
    Ui::StepLadderSetDialog *ui;
    StepLadderData m_Data;
    KeyboardForm *m_KeyBoard;
    QMap<QObject*, int> m_KeyboardMap;
    QObject* m_CurrentObj;
};

#endif // STEPLADDERSETDIALOG_H
