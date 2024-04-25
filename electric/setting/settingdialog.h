#ifndef SETTINGDIALOG_H
#define SETTINGDIALOG_H

#include <QDialog>
#include <QList>
#include <QCheckBox>
#include "database/dboperation.h"

namespace Ui {
class SettingDialog;
}

class SettingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingDialog(QWidget *parent = 0);
    ~SettingDialog();
    void initUI();

private slots:
    void on_closeBtn_clicked();

    void on_saveBtn_clicked();

 private:
    void initParam();

private:
    Ui::SettingDialog *ui;
    QList<QCheckBox*> *m_TestParamList;
};

#endif // SETTINGDIALOG_H
