#ifndef GENERALSETDIALOG_H
#define GENERALSETDIALOG_H

#include <QDialog>
#include "Common/commontest.h"
#include "Common/keyboardform.h"
#include <QMap>

namespace Ui {
class GeneralSetDialog;
}

class GeneralSetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GeneralSetDialog(QWidget *parent = nullptr);
    ~GeneralSetDialog();
    void setData(const GeneralData &p_data);
    const GeneralData getData();

private slots:
    void slotDateTime(const QString p_datetime);
    void slotKeyPressed(const int p_key);

    void on_saveBtn_clicked();

    void on_backBtn_clicked();

    void on_stepNoCB_activated(int index);

    void on_voltageLEU_editingFinished();

    void on_freqLEU_editingFinished();

    void on_harmonicsCBU_activated(int index);

    void on_softTimeLEU_editingFinished();

private:
    void updateData();
    void updateOutputMode(const int p_outputmode);
    void data2Ui(const GeneralData &p_data);
    void ui2Data(GeneralData &p_data);
    void initKeyBoard(const int p_x, const int p_y,
                      const int p_width, const int p_height);
    void uninitKeyBoard();

signals:
    void sigResetLockTime();

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private:
    Ui::GeneralSetDialog *ui;
    GeneralData m_Data;
    KeyboardForm *m_KeyBoard;
    QMap<QObject*, int> m_KeyboardMap;
    QObject* m_CurrentObj;
};

#endif // GENERALSETDIALOG_H
