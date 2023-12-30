#ifndef PROGRAMDIALOG_H
#define PROGRAMDIALOG_H

#include <QDialog>
#include "jsonoperation/jsonoperation.h"
#include <QMap>
#include <QTreeWidgetItem>

namespace Ui {
class programDialog;
}

typedef struct TestMINMAX{
    float irVoltMin;
    float irVoltMax;
    float irResMin;
    float irResMax;
    int irCompMin;
    int irCompMax;
    float irTimeMin;
    float irTimeMax;
    float peqCurrentMin;
    float peqCurrentMax;
    float peqResMin;
    float peqResMax;
    float peqCompMin;
    float peqCompMax;
    float peqTimeMin;
    float peqTimeMax;
}TestValidator;

class programDialog : public QDialog
{
    Q_OBJECT

public:
    explicit programDialog(QString p_path, QWidget *parent = 0);
    ~programDialog();

private slots:
    void on_minBtn_clicked();

    void on_closeBtn_clicked();

    void on_openfileBtn_clicked();

    void on_savefileBtn_clicked();

    void on_newfileBtn_clicked();

    void on_topfileBtn_clicked();

    void on_downfileBtn_clicked();

    void on_deletefileBtn_clicked();

    void on_itemListWidget_clicked(const QModelIndex &index);

    void on_irTestSetLE_textEdited(const QString &arg1);

    void on_irTestModeCBox_currentIndexChanged(int index);

    void on_irTestValLowLE_textEdited(const QString &arg1);

    void on_irTestValHighLE_textEdited(const QString &arg1);

    void on_irTestCompLE_textEdited(const QString &arg1);

    void on_irTestTimeLE_textEdited(const QString &arg1);

    void on_peqTestSetLE_textEdited(const QString &arg1);

    void on_peqTestModeCBox_currentIndexChanged(int index);

    void on_peqTestValLowLE_textEdited(const QString &arg1);

    void on_peqTestValHighLE_textEdited(const QString &arg1);

    void on_peqTestCompLE_textEdited(const QString &arg1);

    void on_peqTestTimeLE_textEdited(const QString &arg1);

    void on_itemTreeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);


    void on_freqLE_textEdited(const QString &arg1);

    void on_failstepCBox_activated(int index);

    void on_powerCBox_activated(int index);

    void on_groupConnCBox_activated(int index);

private:
    void loadTestData();
    void loadCommonData(const GroupData &p_data);
    void selectRow(const int p_row);
    void clearAll();
    IrTestData *GetIRtemData(const int p_row);
    PeqTestData *GetPEQitemData(const int p_row);
    void irDefault(IrTestData *p_TestData);
    void peqDefault(PeqTestData *p_TestData);
    void groupDefault(GroupData *p_GroupData);
    void initValidator();

private:
    Ui::programDialog *ui;
    JsonData m_JsonData;
    QMap<TEST_ITEM, QString> m_ItemNameMap;
    int m_nLastListRow;
    TestValidator m_Validator;
};

#endif // PROGRAMDIALOG_H
