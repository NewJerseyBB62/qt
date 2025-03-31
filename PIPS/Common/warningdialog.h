#ifndef WARNINGDIALOG_H
#define WARNINGDIALOG_H

#include <QDialog>

namespace Ui {
class WarningDialog;
}

class WarningDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WarningDialog(QWidget *parent = nullptr);
    ~WarningDialog();
    void initWarning(const QString &p_title, const QString &p_content);

private slots:
    void on_okBtn_clicked();

    void on_cancelBtn_clicked();

private:
    Ui::WarningDialog *ui;
};

#endif // WARNINGDIALOG_H
