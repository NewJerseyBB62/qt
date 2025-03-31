#ifndef GRADIENTSETDIALOG_H
#define GRADIENTSETDIALOG_H

#include <QDialog>
#include "Common/commontest.h"
#include "Common/keyboardform.h"
#include <QMap>

namespace Ui {
class GradientSetDialog;
}

class GradientSetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GradientSetDialog(QWidget *parent = nullptr);
    ~GradientSetDialog();
    void setData(const TestCtrl &p_ctrl, QList<GradientData> &p_data);
    void getData(TestCtrl &p_ctrl, QList<GradientData> &p_datd);

private slots:
    void slotDateTime(const QString p_datetime);
    void slotKeyPressed(const int p_key);

    void on_saveBtn_clicked();

    void on_backBtn_clicked();

    void on_jumpLE_editingFinished();

    void on_tableWidget_cellClicked(int row, int column);

    void on_voltageStartLEU_editingFinished();

    void on_voltageStopLEU_editingFinished();

    void on_freqStartLEU_editingFinished();

    void on_freqStopLEU_editingFinished();

    void on_harmonicsCBU_activated(int index);

    void on_timeLEU_editingFinished();

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
    Ui::GradientSetDialog *ui;
    QList<GradientData> m_Data;
    int m_OutputMode;
    bool m_ThreeMode;
    KeyboardForm *m_KeyBoard;
    QMap<QObject*, int> m_KeyboardMap;
    QObject* m_CurrentObj;
};

#endif // GRADIENTSETDIALOG_H
