#ifndef DATADIALOG_H
#define DATADIALOG_H

#include <QDialog>

namespace Ui {
class DataDialog;
}

class DataDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DataDialog(QWidget *parent = 0);
    ~DataDialog();

private slots:
    void on_closeBtn_clicked();

private:
    Ui::DataDialog *ui;
};

#endif // DATADIALOG_H
