#ifndef DATADIALOG_H
#define DATADIALOG_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class DataDialog;
}

class DataDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DataDialog(QWidget *parent = nullptr);
    ~DataDialog();
    int initDatabase();
    void uninitDatabase();

signals:
    void SigClose();

private slots:
    void on_queryBtn_clicked();

    void on_resetBtn_clicked();

    void on_firstPageBtn_clicked();

    void on_prePageBtn_clicked();

    void on_pushButton_5_clicked();

    void on_nextPageBtn_clicked();

    void on_lastPageBtn_clicked();

    void on_closeBtn_clicked(QAbstractButton *button);

private:
    Ui::DataDialog *ui;
};

#endif // DATADIALOG_H
