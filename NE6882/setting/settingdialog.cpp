#include "settingdialog.h"
#include "ui_settingdialog.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QMessageBox>

settingDialog::settingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settingDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    //this->showMaximized();
    this->showFullScreen();
    settingPath = "./systemsetting.json";
    initSerialPort();
    jsonOperation jsonObj;
    if(jsonObj.readJsonfile(settingPath, m_JsonData) == 0)
        initSetting();
    else
    {
        ui->baudCBox->setCurrentText(QString::number(9600));
        ui->comCBox->setCurrentIndex(-1);
        SystemData sysData;
        sysData.nBaudrate = 9600;
        sysData.strSerialPort = "";
        sysData.szTestfilePath = "";
        m_JsonData.testItemType = JSON_STRUCTTYPE::ENM_ITEM_SYSTEM;
        m_JsonData.testItemData.setValue(sysData);
    }
}

settingDialog::~settingDialog()
{
    delete ui;
}

void settingDialog::on_minBtn_clicked()
{
    this->showMinimized();
}

void settingDialog::on_closeBtn_clicked()
{
    done(Rejected);
    close();
}

void settingDialog::on_saveBtn_clicked()
{
    m_JsonData.testItemType = JSON_STRUCTTYPE::ENM_ITEM_SYSTEM;
    if(m_JsonData.testItemData.canConvert<SystemData>())
    {
        SystemData *pSysData = reinterpret_cast<SystemData *>(m_JsonData.testItemData.data());
        pSysData->nBaudrate = ui->baudCBox->currentText().toInt();
        pSysData->strSerialPort = ui->comCBox->currentText();
    }
    else
    {
        SystemData systemData;
        systemData.strSerialPort = ui->comCBox->currentText();
        systemData.nBaudrate = ui->baudCBox->currentText().toInt();
        m_JsonData.testItemData.setValue(systemData);
    }

    jsonOperation jsonObj;
    if(jsonObj.writeJsonfile(settingPath, m_JsonData) == 0)
    {
        QMessageBox::information(this, "保存", "保存成功", QMessageBox::Yes);
    }
    else
    {
        QMessageBox::information(this, "保存", "保存失败", QMessageBox::Yes);
    }
    return;
    //done(Accepted);
    //close();
}

void settingDialog::on_cancelBtn_clicked()
{
    done(Rejected);
    close();
}

void settingDialog::initSerialPort()
{
    QStringList serialList;
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
       serialList << info.portName();
    }
    if(serialList.size() > 0)
        ui->comCBox->addItems(serialList);
}

void settingDialog::initSetting()
{
    SystemData systemData = m_JsonData.testItemData.value<SystemData>();
    if(systemData.strSerialPort.length() > 0)
        ui->comCBox->setCurrentText(systemData.strSerialPort);
    if(systemData.nBaudrate >= 4800)
        ui->baudCBox->setCurrentText(QString::number(systemData.nBaudrate));
}
