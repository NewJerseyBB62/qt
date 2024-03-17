#ifndef DATADIALOG_H
#define DATADIALOG_H

#include <QDialog>
#include <QAbstractButton>
#include <QSqlDatabase>
#include "task.h"
#include <taskdialog.h>
#include <QTimer>

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
    void SlotTimeOver();
    void SlotTaskOver();
    void on_queryBtn_clicked();

    void on_resetBtn_clicked();

    void on_firstPageBtn_clicked();

    void on_prePageBtn_clicked();

    void on_nextPageBtn_clicked();

    void on_lastPageBtn_clicked();

    void on_closeBtn_clicked(QAbstractButton *button);

    void on_exportBtn_clicked();

    void on_jumpToBtn_clicked();

private:
    void excuteSql(const QString &p_sql);
    void pageChanged(int curr, int total);

private:
    Ui::DataDialog *ui;
    QSqlDatabase m_SqlObj;
    int m_TotalPage;
    int m_CurrentPage;
    int m_TotalNum;
    Task *m_taskObj;
    TaskDialog *m_TaskDialog;
    QTimer *m_TaskTimer;
    int m_TimeTick;
};

#endif // DATADIALOG_H
