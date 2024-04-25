#include "settingdialog.h"
#include "ui_settingdialog.h"

SettingDialog::SettingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingDialog),
    m_TestParamList(nullptr)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setWindowState(Qt::WindowMaximized);
    initParam();
}

SettingDialog::~SettingDialog()
{
    delete ui;
}

void SettingDialog::initUI()
{
    int i = 0;
    QList<bool> testParamStatus;
    DbOperation *dbObj = new DbOperation();
    dbObj->openDb("database.db");
    dbObj->setTestParamTable(DB_OPERATION::ENM_DB_SELECT, &testParamStatus, nullptr);
    delete dbObj;
    foreach(bool temp, testParamStatus)
    {
        m_TestParamList->at(i)->setChecked(temp);
        i++;
    }
}

void SettingDialog::on_closeBtn_clicked()
{
    this->close();
}

void SettingDialog::on_saveBtn_clicked()
{
    QList<bool> testParamStatus;
    int i = 0;
    while(i < 22)
    {
        testParamStatus.append(m_TestParamList->at(i)->isChecked());
        i++;
    }
    DbOperation *dbObj = new DbOperation();
    dbObj->openDb("database.db");
    dbObj->setTestParamTable(DB_OPERATION::ENM_DB_INSERT, &testParamStatus, nullptr);
    delete dbObj;
}

void SettingDialog::initParam()
{
    m_TestParamList = new QList<QCheckBox*>();
    m_TestParamList->append(ui->checkBox);
    m_TestParamList->append(ui->checkBox2);
    m_TestParamList->append(ui->checkBox3);
    m_TestParamList->append(ui->checkBox4);
    m_TestParamList->append(ui->checkBox5);
    m_TestParamList->append(ui->checkBox6);
    m_TestParamList->append(ui->checkBox7);
    m_TestParamList->append(ui->checkBox8);
    m_TestParamList->append(ui->checkBox9);
    m_TestParamList->append(ui->checkBox10);
    m_TestParamList->append(ui->checkBox11);
    m_TestParamList->append(ui->checkBox12);
    m_TestParamList->append(ui->checkBox13);
    m_TestParamList->append(ui->checkBox14);
    m_TestParamList->append(ui->checkBox15);
    m_TestParamList->append(ui->checkBox16);
    m_TestParamList->append(ui->checkBox17);
    m_TestParamList->append(ui->checkBox18);
    m_TestParamList->append(ui->checkBox19);
    m_TestParamList->append(ui->checkBox20);
    m_TestParamList->append(ui->checkBox21);
    m_TestParamList->append(ui->checkBox22);
}
