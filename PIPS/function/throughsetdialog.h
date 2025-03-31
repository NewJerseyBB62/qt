#ifndef THROUGHSETDIALOG_H
#define THROUGHSETDIALOG_H

#include <QDialog>
#include "Common/commontest.h"
#include "Common/keyboardform.h"
#include <QMap>

namespace Ui {
class ThroughSetDialog;
}

class ThroughSetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ThroughSetDialog(QWidget *parent = nullptr);
    ~ThroughSetDialog();
    void setData(const QList<ThroughData> &p_data, const TestCtrl &p_ctrl);
    void getData(QList<ThroughData> &p_data, TestCtrl &p_ctrl);

private slots:
    void slotDateTime(const QString p_datetime);
    void slotKeyPressed(const int p_key);

    void on_saveBtn_clicked();

    void on_backBtn_clicked();

    void on_stepNoCB_activated(int index);

    void on_voltageLE_editingFinished();

    void on_freqLE_editingFinished();

    void on_startTimeLE_editingFinished();

private:
    void updateData();
    void updateOutputMode(const int p_outputmode);
    void data2Ui(const ThroughData &p_data);
    void ui2Data();
    void initKeyBoard(const int p_x, const int p_y,
                      const int p_width, const int p_height);
    void uninitKeyBoard();


signals:
    void sigResetLockTime();

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private:
    Ui::ThroughSetDialog *ui;
    QList<ThroughData> m_Data;
    KeyboardForm *m_KeyBoard;
    QMap<QObject*, int> m_KeyboardMap;
    QObject* m_CurrentObj;
};

#endif // THROUGHSETDIALOG_H
