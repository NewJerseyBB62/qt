#ifndef SETTINGDIALOG_H
#define SETTINGDIALOG_H

#include <QDialog>
#include "jsonoperation/jsonoperation.h"

namespace Ui {
class settingDialog;
}

class settingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit settingDialog(QWidget *parent = 0);
    ~settingDialog();

private slots:
    void on_minBtn_clicked();

    void on_closeBtn_clicked();

    void on_saveBtn_clicked();

    void on_cancelBtn_clicked();

private:
    void initSerialPort();
    void initSetting();

private:
    Ui::settingDialog *ui;
    JsonData m_JsonData;
    QString settingPath;
};

#endif // SETTINGDIALOG_H
