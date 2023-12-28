#ifndef TESTDIALOG_H
#define TESTDIALOG_H

#include <QDialog>
#include "jsonoperation/jsonoperation.h"
#include <test/testthread.h>
#include <QThread>
#include <QList>

namespace Ui {
class testDialog;
}

class testDialog : public QDialog
{
    Q_OBJECT

public:
    explicit testDialog(QWidget *parent = 0);
    ~testDialog();

signals:
    void sigStartRun();
    void sigStopRun();
    void sigSendCmd(const NE6882Msg p_data);

public slots:
    void slotRecv(const NE6882Msg p_data);

private slots:
    void on_minBtn_clicked();
    void on_closeBtn_clicked();
    void on_starttestBtn_clicked();
    void on_stoptestBtn_clicked();
    void on_openfileBtn_clicked();

    void on_testTableWidget_clicked(const QModelIndex &index);

public:
    int initTest();

private:
    void closeThread();
    void setTestSet();
    void setTestGroup();
    int Json2Msg(const QVariant &p_src, NE6882Msg &p_data);
    void loadTestList();
    void loadGroupData();
    int setTestGroupData();
    void enableBtn(const bool &p_enable);
    void updateTestdata(const NE6882Msg &p_data);
    void selectRow(const int p_row);
    void clearTestdata();
    void initHorHead();


private:
    Ui::testDialog *ui;
    JsonData m_SysData;
    JsonData m_TestData;
    QThread *m_Thread;
    TestThread *m_ThreadObj;
    QString m_currentFile;
    QMap<TEST_ITEM, QString> m_ItemNameMap;
    QList<NE6882Msg> m_ResultList;
    QMap<NE6882_STATE, QString> m_TeststateMap;
};

#endif // TESTDIALOG_H
