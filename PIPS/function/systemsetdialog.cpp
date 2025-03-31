#include "systemsetdialog.h"
#include "ui_systemsetdialog.h"
#include <QListView>
#include "Data/dboperation.h"
#include <QMessageBox>
#include <QStorageInfo>
#include <QFileInfo>
#include <QDir>
#include <QFile>
#include "Common/rtc.h"
#include "Common/lockmanager.h"
#include "Data/logoperation.h"
#include "communication/communication.h"
#include <QEvent>
#include <QKeyEvent>
#include <QCoreApplication>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include "Common/warningdialog.h"

#define DEF_LOG_MAXROW 20
#define DEF_LOG_MAXCOL 8

SystemSetDialog::SystemSetDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SystemSetDialog),
    m_KeyBoard(nullptr),
    m_CurrentObj(nullptr)
{
    int i = 0;
    ui->setupUi(this);
    this->setGeometry(0, 0, 1280, 800);
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->languageCB->setView(new QListView(this));
    ui->ocfoldCB->setView(new QListView(this));
    ui->antiShockCB->setView(new QListView(this));
    ui->baudrateCB->setView(new QListView(this));
    ui->protocolCB->setView(new QListView(this));
    ui->UdiskExportCB->setView(new QListView(this));
    ui->UdiskImportCB->setView(new QListView(this));
    ui->overCurrentLE->installEventFilter(this);
    ui->lineImpedanceLE->installEventFilter(this);
    ui->shockMultLE->installEventFilter(this);
    ui->voltageDropLE->installEventFilter(this);
    ui->retardTimeLE->installEventFilter(this);
    ui->comLE->installEventFilter(this);
    ui->addrLE->installEventFilter(this);
    ui->lockTimeLE->installEventFilter(this);
    ui->lockPwdLE->installEventFilter(this);
    ui->percentLE->installEventFilter(this);
    ui->angleLE->installEventFilter(this);
    this->installEventFilter(this);
    m_KeyboardMap.insert(ui->overCurrentLE, i++);
    m_KeyboardMap.insert(ui->lineImpedanceLE, i++);
    m_KeyboardMap.insert(ui->shockMultLE, i++);
    m_KeyboardMap.insert(ui->voltageDropLE, i++);
    m_KeyboardMap.insert(ui->retardTimeLE, i++);
    m_KeyboardMap.insert(ui->comLE, i++);
    m_KeyboardMap.insert(ui->addrLE, i++);
    m_KeyboardMap.insert(ui->lockTimeLE, i++);
    m_KeyboardMap.insert(ui->lockPwdLE, i++);
    m_KeyboardMap.insert(ui->percentLE, i++);
    m_KeyboardMap.insert(ui->angleLE, i++);
    ui->lockPwdLE->setEchoMode(QLineEdit::Password);
    ui->lockPwdLE->setMaxLength(4);
    ui->harmonTable->setColumnWidth(0, 240);
    ui->harmonTable->setColumnWidth(1, 245);
    ui->harmonTable->setColumnWidth(2, 245);
    ui->logTable->setColumnWidth(0, 70);
    ui->logTable->setColumnWidth(1, 120);
    ui->logTable->setColumnWidth(2, 120);
    ui->logTable->setColumnWidth(3, 248);
    ui->logTable->setColumnWidth(4, 120);
    ui->logTable->setColumnWidth(5, 120);
    ui->logTable->setColumnWidth(6, 120);
    ui->logTable->setColumnWidth(7, 120);
    //ui->lockPwdLE->set
    connect(rtc::getRtcInstance(), &rtc::sigTimeChanged,
            this, &SystemSetDialog::slotDateTime, Qt::QueuedConnection);
    connect(this, &SystemSetDialog::sigResetLockTime,LockManager::getRtcInstance(),
            &LockManager::slotResetLockTime, Qt::QueuedConnection);
}

SystemSetDialog::~SystemSetDialog()
{
    disconnect(rtc::getRtcInstance(), &rtc::sigTimeChanged,
            this, &SystemSetDialog::slotDateTime);
    disconnect(this, &SystemSetDialog::sigResetLockTime,LockManager::getRtcInstance(),
            &LockManager::slotResetLockTime);
    uninitThread();
    delete ui;
}

void SystemSetDialog::initSetting(const ConfigData &p_cfg)
{
    setBtnStatus(ENM_PAGE_SYSTEM, true);
    ui->stackedWidget->setCurrentIndex(ENM_PAGE_SYSTEM);
    m_CurrentPage = ENM_PAGE_SYSTEM;
    initHarmonicsTable();
    initLogTable();
    m_ConfigData = p_cfg;
    readDB();
    harmonics2ui();
    log2ui();
    ui->harmonicsGroupCB->setCurrentIndex(0);
    ui->harmonicsTimesCB->setCurrentIndex(0);
    data2ui();
    updateLogBtnStatus();
    initThread();
}

void SystemSetDialog::getSetting(ConfigData &p_cfg)
{
    p_cfg = m_ConfigData;
}

void SystemSetDialog::slotDateTime(const QString p_datetime)
{
    ui->timeLab->setText(p_datetime);
}

void SystemSetDialog::slotRecvData(const PrintData p_printdata)
{
    m_FanSpeed = p_printdata.fanSpeed;
    m_IGBT = p_printdata.igbt;
    m_Transformer = p_printdata.transformer;
    if(m_CurrentPage == ENM_PAGE_ALARM)
    {
        ui->igbtLE->setText(QString::number(m_IGBT, 'f', 1));
        ui->igbtLE->setText(QString::number(m_Transformer, 'f', 1));
        ui->igbtLE->setText(QString::number(m_FanSpeed));
    }
}

void SystemSetDialog::slotKeyPressed(const int p_key)
{
    if(m_CurrentObj == nullptr)
        return;
    int key;
    QString strKey;
    switch(p_key)
    {
    case ENM_KEY_0:
        key = Qt::Key_0;
        strKey = "0";
        break;
    case ENM_KEY_1:
        key = Qt::Key_1;
        strKey = "1";
        break;
    case ENM_KEY_2:
        key = Qt::Key_2;
        strKey = "2";
        break;
    case ENM_KEY_3:
        key = Qt::Key_3;
        strKey = "3";
        break;
    case ENM_KEY_4:
        key = Qt::Key_4;
        strKey = "4";
        break;
    case ENM_KEY_5:
        key = Qt::Key_5;
        strKey = "5";
        break;
    case ENM_KEY_6:
        key = Qt::Key_6;
        strKey = "6";
        break;
    case ENM_KEY_7:
        key = Qt::Key_7;
        strKey = "7";
        break;
    case ENM_KEY_8:
        key = Qt::Key_8;
        strKey = "8";
        break;
    case ENM_KEY_9:
        key = Qt::Key_9;
        strKey = "9";
        break;
    case ENM_KEY_Dot:
        key = Qt::Key_Period;
        strKey = ".";
        break;
    case ENM_KEY_Minus:
        key = Qt::Key_Minus;
        strKey = "-";
        break;
    case ENM_KEY_Delete:
        key = Qt::Key_Backspace;
        strKey = "";
        break;
    case ENM_KEY_Enter:
        key = Qt::Key_Enter;
        strKey = "";
        break;
    default:
        return;
    }
    QLineEdit *line = nullptr;
    QKeyEvent *keyPressed = new QKeyEvent(QEvent::KeyPress, key, Qt::NoModifier, strKey);
    QString className = m_CurrentObj->metaObject()->className();
    //QKeyEvent *keyReleased = new QKeyEvent(QEvent::KeyRelease, Qt::Key_1, Qt::NoModifier);
    if(className == "QDoubleSpinBox")
    {
        QDoubleSpinBox *obj = qobject_cast<QDoubleSpinBox*>(m_CurrentObj);
        line = obj->findChild<QLineEdit*>();
    }
    else if(className == "QSpinBox")
    {
        QSpinBox *obj = qobject_cast<QSpinBox*>(m_CurrentObj);
        line = obj->findChild<QLineEdit*>();
    }
    else if(className == "QLineEdit")
    {
        line = qobject_cast<QLineEdit*>(m_CurrentObj);
    }
    //QApplication::postEvent(m_CurrentObj, keyPressed);
    if(line != nullptr)
    {
        QCoreApplication::sendEvent(line, keyPressed);
        emit sigResetLockTime();
    }
    if(p_key == ENM_KEY_Enter)
    {
        this->setFocus();
        uninitKeyBoard();
    }
}

void SystemSetDialog::on_saveBtn_clicked()
{
    emit sigResetLockTime();
    do{
        if(ui->lockCHeck->isChecked() && ui->lockPwdLE->text().length() != 4)
        {
            WarningDialog warning(this);
            warning.initWarning(tr("错误"), tr("锁屏密码长度需为4位"));
            warning.exec();
            //QMessageBox::information(this, tr("错误"), tr("锁屏密码长度需为4位"));
            break;
        }
        WarningDialog warning(this);
        warning.initWarning(tr("保存"), tr("保存成功"));
        warning.exec();
        //QMessageBox::information(this, tr("保存"), tr("保存成功"));
        ui2data();
        LogData logdata;
        logdata.TestMode = ENM_TESTMODE_MAX;
        logdata.OutputMode = ENM_OUTPUT_MAX;
        logdata.OperationType = ENM_LOG_SYSTEM_SAVE;
        logdata.Time = ui->timeLab->text();
        logdata.IGBT = m_IGBT;
        logdata.Transformer = m_Transformer;
        logdata.FanSpeed = m_FanSpeed;
        LogOperation::getLogInstance()->writeLog(logdata);
        CanSendData sendData;
        CanDataType systemData;
        sendData.Cmd = ENM_CMD_SET;
        sendData.TestMode = ENM_TESTMODE_SYSTEM;
        systemData.M6_nPhase = m_ConfigData.LinePhase;
        systemData.M6_nOCFold = m_ConfigData.OCFold;
        systemData.M6_nAntiShock = m_ConfigData.AntiShock;
        systemData.M6_fOvercurrentLimit = m_ConfigData.OvercurrentLimit;
        systemData.M6_fLineImpedance = m_ConfigData.LineImpedance;
        if(m_ConfigData.AntiShock == 1)
        {
            systemData.M6_fShockMult = m_ConfigData.ShockMult1;
            systemData.M6_fVoltageDrop = m_ConfigData.VoltageDrop1;
            systemData.M6_fRetardTime = m_ConfigData.RetardTime;
        }
        else if(m_ConfigData.AntiShock == 2)
        {
            systemData.M6_fShockMult = m_ConfigData.ShockMult2;
            systemData.M6_fVoltageDrop = m_ConfigData.VoltageDrop2;
            systemData.M6_fRetardTime = m_ConfigData.HoldTime;
        }
        sendData.TestData.append(systemData);
        emit sigSendData(sendData);
        accept();
        return;
    }while(0);
    reject();
    return;
}

void SystemSetDialog::on_backBtn_clicked()
{
    emit sigResetLockTime();
    reject();
}

void SystemSetDialog::on_systemBtn_clicked(bool checked)
{
    setBtnStatus(ENM_PAGE_SYSTEM, checked);
}

void SystemSetDialog::on_harmonicsBtn_clicked(bool checked)
{
    setBtnStatus(ENM_PAGE_HARMONICS, checked);
}

void SystemSetDialog::on_alarmBtn_clicked(bool checked)
{
    setBtnStatus(ENM_PAGE_ALARM, checked);
}

void SystemSetDialog::on_networkBtn_clicked(bool checked)
{
    setBtnStatus(ENM_PAGE_NETWORK, checked);
}

void SystemSetDialog::on_userBtn_clicked(bool checked)
{
    setBtnStatus(ENM_PAGE_USER, checked);
}

void SystemSetDialog::on_advanceBtn_clicked(bool checked)
{
    setBtnStatus(ENM_PAGE_ADVANCE, checked);
}

void SystemSetDialog::setBtnStatus(const int p_type, const bool p_state)
{
    if(!p_state)
        return;
    bool status[6] = {false, false, false, false, false, false};
    status[p_type] = true;
    ui->systemBtn->setEnabled(!status[0]);
    ui->harmonicsBtn->setEnabled(!status[1]);
    ui->alarmBtn->setEnabled(!status[2]);
    ui->networkBtn->setEnabled(!status[3]);
    ui->userBtn->setEnabled(!status[4]);
    ui->advanceBtn->setEnabled(!status[5]);
    ui->systemBtn->setChecked(status[0]);
    ui->harmonicsBtn->setChecked(status[1]);
    ui->alarmBtn->setChecked(status[2]);
    ui->networkBtn->setChecked(status[3]);
    ui->userBtn->setChecked(status[4]);
    ui->advanceBtn->setChecked(status[5]);
    ui->stackedWidget->setCurrentIndex(p_type);
    emit sigResetLockTime();
}

void SystemSetDialog::data2ui()
{
    ui->languageCB->setCurrentIndex(m_ConfigData.Language);
    ui->themeCB->setCurrentIndex(m_ConfigData.Theme);
    ui->ocfoldCB->setCurrentIndex(m_ConfigData.OCFold);
    ui->phaseCB->setCurrentIndex(m_ConfigData.LinePhase);
    ui->overCurrentLE->setText(QString::number(m_ConfigData.OvercurrentLimit, 'f', 3));
    ui->lineImpedanceLE->setText(QString::number(m_ConfigData.LineImpedance, 'f', 1));
    ui->antiShockCB->setCurrentIndex(m_ConfigData.AntiShock);
    if(m_ConfigData.AntiShock == 1)
    {
        ui->shockLab->setText(tr("缓升"));
        ui->shockMultLE->setText(QString::number(m_ConfigData.ShockMult1, 'f', 1));
        ui->voltageDropLE->setText(QString::number(m_ConfigData.VoltageDrop1, 'f', 2));
        ui->retardTimeLE->setText(QString::number(m_ConfigData.RetardTime, 'f', 2));
    }
    else if(m_ConfigData.AntiShock == 2)
    {
        ui->shockLab->setText(tr("保持"));
        ui->shockMultLE->setText(QString::number(m_ConfigData.ShockMult2, 'f', 1));
        ui->voltageDropLE->setText(QString::number(m_ConfigData.VoltageDrop2, 'f', 2));
        ui->retardTimeLE->setText(QString::number(m_ConfigData.HoldTime, 'f', 2));
    }
    else
    {
        ui->shockMultLE->setText("0.0");
        ui->voltageDropLE->setText("0.0");
        ui->retardTimeLE->setText("0.0");
        ui->shockMultLE->setEnabled(false);
        ui->voltageDropLE->setEnabled(false);
        ui->retardTimeLE->setEnabled(false);
    }
    ui->commCheck->setChecked(m_ConfigData.CommCheck);
    ui->comLE->setText(m_ConfigData.SerialPort);
    ui->baudrateCB->setCurrentIndex(m_ConfigData.Baudrate);
    ui->addrLE->setText(QString::number(m_ConfigData.Addr));
    ui->protocolCB->setCurrentIndex(m_ConfigData.Protocol);
    ui->lockCHeck->setChecked(m_ConfigData.LockCheck);
    ui->lockTimeLE->setText(QString::number(m_ConfigData.LockTime));
    ui->lockPwdLE->setText(m_ConfigData.LockPwd);
    ui->companyLE->setText(m_ConfigData.Company);
    ui->addressLE->setText(m_ConfigData.Address);
    ui->phoneLE->setText(m_ConfigData.Phone);
    ui->mailLE->setText(m_ConfigData.Email);
    switch(m_ConfigData.Serialization)
    {
    case 0:
        ui->serializationBtn4->setChecked(true);
        break;
    case 1:
        ui->serializationBtn1->setChecked(true);
        break;
    case 2:
        ui->serializationBtn2->setChecked(true);
        break;
    case 3:
        ui->serializationBtn3->setChecked(true);
        break;
    }
    ui->harmonicsCheck->setChecked(m_ConfigData.Harmonics);
    ui->outputModeCheck1->setChecked(m_ConfigData.ThreePhase);
    ui->outputModeCheck2->setChecked(m_ConfigData.ThreePhaseDiscrete);
    ui->outputModeCheck3->setChecked(m_ConfigData.ThreePhaseUnbalance);
    ui->outputModeCheck4->setChecked(m_ConfigData.SinglePhase);
    //ui->but
}

void SystemSetDialog::ui2data()
{
    m_ConfigData.Language = ui->languageCB->currentIndex();
    m_ConfigData.Theme = ui->themeCB->currentIndex();
    m_ConfigData.OCFold = ui->ocfoldCB->currentIndex();
    m_ConfigData.LinePhase = ui->phaseCB->currentIndex();
    m_ConfigData.OvercurrentLimit = ui->overCurrentLE->text().toFloat();
    m_ConfigData.LineImpedance = ui->lineImpedanceLE->text().toFloat();
    m_ConfigData.AntiShock = ui->antiShockCB->currentIndex();
    if(m_ConfigData.AntiShock == 1)
    {
        m_ConfigData.ShockMult1 = ui->shockMultLE->text().toFloat();
        m_ConfigData.VoltageDrop1 = ui->voltageDropLE->text().toFloat();
        m_ConfigData.RetardTime = ui->retardTimeLE->text().toFloat();
    }
    else if(m_ConfigData.AntiShock == 2)
    {
        m_ConfigData.ShockMult2 = ui->shockMultLE->text().toFloat();
        m_ConfigData.VoltageDrop2 = ui->voltageDropLE->text().toFloat();
        m_ConfigData.HoldTime = ui->retardTimeLE->text().toFloat();
    }
    m_ConfigData.CommCheck = ui->commCheck->isChecked();
    m_ConfigData.SerialPort = ui->comLE->text();
    m_ConfigData.Baudrate = ui->baudrateCB->currentIndex();
    m_ConfigData.Addr = ui->addrLE->text().toInt();
    m_ConfigData.Protocol = ui->protocolCB->currentIndex();
    m_ConfigData.LockCheck = ui->lockCHeck->isChecked();
    m_ConfigData.LockTime = ui->lockTimeLE->text().toInt();
    m_ConfigData.LockPwd = ui->lockPwdLE->text();
    m_ConfigData.Company = ui->companyLE->text();
    m_ConfigData.Address = ui->addressLE->text();
    m_ConfigData.Phone = ui->phoneLE->text();
    m_ConfigData.Email = ui->mailLE->text();
    if(ui->serializationBtn1->isChecked())
        m_ConfigData.Serialization = 1;
    else if(ui->serializationBtn2->isChecked())
        m_ConfigData.Serialization = 2;
    else if(ui->serializationBtn3->isChecked())
        m_ConfigData.Serialization = 3;
    else if(ui->serializationBtn4->isChecked())
        m_ConfigData.Serialization = 0;

    m_ConfigData.Harmonics = ui->harmonicsCheck->isChecked();
    m_ConfigData.ThreePhase = ui->outputModeCheck1->isChecked();
    m_ConfigData.ThreePhaseDiscrete = ui->outputModeCheck2->isChecked();
    m_ConfigData.ThreePhaseUnbalance = ui->outputModeCheck3->isChecked();
    m_ConfigData.SinglePhase = ui->outputModeCheck4->isChecked();
}

void SystemSetDialog::harmonics2ui()
{
    int i = 0;
    while(i < 39)
    {
        QTableWidgetItem *pItem1 = ui->harmonTable->item(i, 0);
        QTableWidgetItem *pItem2 = ui->harmonTable->item(i, 1);
        QTableWidgetItem *pItem3 = ui->harmonTable->item(i, 2);
        pItem1->setText(QString::number(m_HarmonicsData.at(i).Times));
        pItem2->setText(QString::number(m_HarmonicsData.at(i).Percent, 'f', 2));
        pItem3->setText(QString::number(m_HarmonicsData.at(i).Angles, 'f', 1));
        i++;
    }
}

void SystemSetDialog::harmonics2data()
{
    int i = 0;
    while(i < 39)
    {
        QTableWidgetItem *pItem1 = ui->harmonTable->item(i, 0);
        QTableWidgetItem *pItem2 = ui->harmonTable->item(i, 1);
        QTableWidgetItem *pItem3 = ui->harmonTable->item(i, 2);
        m_HarmonicsData[i].Times = pItem1->text().toInt();
        m_HarmonicsData[i].Percent = pItem2->text().toFloat();
        m_HarmonicsData[i].Angles = pItem3->text().toFloat();
        i++;
    }
}

void SystemSetDialog::harmonicsRowSelect(const int p_row)
{
    if(p_row < 0 || p_row >= ui->harmonTable->rowCount())
        return;
    ui->harmonicsTimesCB->setCurrentIndex(
                ui->harmonTable->item(p_row, 0)->text().toInt() - 2);
    ui->percentLE->setText(ui->harmonTable->item(p_row, 1)->text());
    ui->angleLE->setText(ui->harmonTable->item(p_row, 2)->text());
}

void SystemSetDialog::initHarmonicsTable()
{
    int i = 0;
    while(i < 39)
    {
        int k = 0;
        ui->harmonTable->insertRow(i);
        while(k < 3)
        {
            QTableWidgetItem *pItem = new QTableWidgetItem;
            ui->harmonTable->setItem(i, k, pItem);
            ui->harmonTable->item(i, k)->setTextAlignment(
                        Qt::AlignHCenter | Qt::AlignVCenter);
            k++;
        }
        i++;
    }
    m_HarmonicsGroup = 0;
    m_HarmonicsNeedSave = false;
}

void SystemSetDialog::readHarmonics(const int p_group)
{
    dbOperation dbObj;
    dbObj.HarmonicsRead(p_group, m_HarmonicsData);
}

void SystemSetDialog::initUdisk(const int p_type)
{
    QComboBox *pCB = nullptr;
    if(p_type == 0)
    {
        pCB = ui->UdiskExportCB;
    }
    else
    {
        pCB = ui->UdiskImportCB;
    }
    pCB->clear();
    foreach(const QStorageInfo &temp, QStorageInfo::mountedVolumes())
    {
        if(temp.isValid() && temp.isReady())
        {
            QString path = temp.rootPath();
            if(path.contains("media"))
                pCB->addItem(path);
        }
    }
}

void SystemSetDialog::readDB()
{
    dbOperation dbObj;
    dbObj.HarmonicsRead(0, m_HarmonicsData);
    dbObj.LogRead(0, m_LogData);
    m_CurrentLogPage = 0;
}

void SystemSetDialog::initLogTable()
{
    int i = 0;
    while(i < DEF_LOG_MAXROW)
    {
        int k = 0;
        ui->logTable->insertRow(i);
        while(k < DEF_LOG_MAXCOL)
        {
            QTableWidgetItem *pItem = new QTableWidgetItem;
            ui->logTable->setItem(i, k, pItem);
            ui->logTable->item(i, k)->setTextAlignment(
                        Qt::AlignHCenter | Qt::AlignVCenter);
            k++;
        }
        i++;
    }
}

void SystemSetDialog::log2ui()
{
    int i = 0;
    while(i < DEF_LOG_MAXROW)
    {
        QTableWidgetItem *pItem1 = ui->logTable->item(i, 0);
        QTableWidgetItem *pItem2 = ui->logTable->item(i, 1);
        QTableWidgetItem *pItem3 = ui->logTable->item(i, 2);
        QTableWidgetItem *pItem4 = ui->logTable->item(i, 3);
        QTableWidgetItem *pItem5 = ui->logTable->item(i, 4);
        QTableWidgetItem *pItem6 = ui->logTable->item(i, 5);
        QTableWidgetItem *pItem7 = ui->logTable->item(i, 6);
        QTableWidgetItem *pItem8 = ui->logTable->item(i, 7);
        if(i < m_LogData.count())
        {
            pItem1->setText(QString::number(m_CurrentLogPage * 20 + i + 1));
            pItem2->setText(getTestModeName(ENM_LANGUAGE_CH, m_LogData.at(i).TestMode));
            pItem3->setText(getOutputModeName(ENM_LANGUAGE_CH, m_LogData.at(i).OutputMode));
            pItem4->setText(getLogText(m_LogData.at(i).OperationType));
            pItem5->setText(m_LogData.at(i).Time);
            pItem6->setText(QString::number(m_LogData.at(i).IGBT, 'f', 1));
            pItem7->setText(QString::number(m_LogData.at(i).Transformer, 'f', 1));
            pItem8->setText(QString::number(m_LogData.at(i).FanSpeed));
        }
        else
        {
            pItem1->setText("");
            pItem2->setText("");
            pItem3->setText("");
            pItem4->setText("");
            pItem5->setText("");
            pItem6->setText("");
            pItem7->setText("");
            pItem8->setText("");
        }
        i++;
    }
}

QString SystemSetDialog::getLogText(const int p_log)
{
    QString log;
    switch (p_log) {
    case ENM_LOG_GENERAL_START:
        log = "常规三相启动";
        break;
    case ENM_LOG_GENERAL_STOP:
        log = "常规三相停止";
        break;
    case ENM_LOG_GENERAL_SAVE:
        log = "常规三相修改";
        break;
    case ENM_LOG_STEPLADDER_START:
        log = "阶梯启动";
        break;
    case ENM_LOG_STEPLADDER_STOP:
        log = "阶梯停止";
        break;
    case ENM_LOG_STEPLADDER_SAVE:
        log = "阶梯修改";
        break;
    case ENM_LOG_STEP_START:
        log = "步阶启动";
        break;
    case ENM_LOG_STEP_STOP:
        log = "步阶停止";
        break;
    case ENM_LOG_STEP_SAVE:
        log = "步阶修改";
        break;
    case ENM_LOG_GRADIENT_START:
        log = "渐变启动";
        break;
    case ENM_LOG_GRADIENT_STOP:
        log = "渐变停止";
        break;
    case ENM_LOG_GRADIENT_SAVE:
        log = "渐变保存";
        break;
    case ENM_LOG_THROUGH_START:
        log = "低压穿越启动";
        break;
    case ENM_LOG_THROUGH_STOP:
        log = "低压穿越停止";
        break;
    case ENM_LOG_THROUGH_SAVE:
        log = "低压穿越修改";
        break;
    case ENM_LOG_HARMONICS_SAVE:
        log = "谐波修改";
        break;
    case ENM_LOG_SYSTEM_SAVE:
        log = "系统设置修改";
        break;
    case ENM_LOG_USER_LOGIN:
        log = "登陆";
        break;
    default:
        log = "";
        break;
    }
    return log;
}

void SystemSetDialog::updateLogBtnStatus()
{
    if(m_CurrentLogPage == 0)
    {
        ui->logPreBtn->setEnabled(false);
    }
    else
    {
        ui->logPreBtn->setEnabled(true);
    }
    if(m_LogData.count() < DEF_LOG_MAXROW)
    {
        ui->logNextBtn->setEnabled(false);
    }
    else
    {
        ui->logNextBtn->setEnabled(true);
    }
}

void SystemSetDialog::initThread()
{
    connect(ReadThread::getReadThread(), &ReadThread::sigReadTestData, this,
            &SystemSetDialog::slotRecvData, Qt::QueuedConnection);
    connect(this, &SystemSetDialog::sigSendData, WriteThread::getWriteThread(),
            &WriteThread::slotSendTestData, Qt::QueuedConnection);
}

void SystemSetDialog::uninitThread()
{
    disconnect(ReadThread::getReadThread(), &ReadThread::sigReadTestData, this,
        &SystemSetDialog::slotRecvData);
    disconnect(this, &SystemSetDialog::sigSendData, WriteThread::getWriteThread(),
               &WriteThread::slotSendTestData);
}

void SystemSetDialog::initKeyBoard(const int p_x, const int p_y, const int p_width, const int p_height)
{
    if(m_KeyBoard == nullptr)
    {
        m_KeyBoard = new KeyboardForm();
        connect(m_KeyBoard, &KeyboardForm::sigKeyPressed,
            this, &SystemSetDialog::slotKeyPressed);
    }
    m_KeyBoard->setPos(p_x, p_y, p_width, p_height);
}

void SystemSetDialog::uninitKeyBoard()
{
    m_CurrentObj = nullptr;
    if(m_KeyBoard == nullptr)
        return;
    m_KeyBoard->hide();
    disconnect(m_KeyBoard, &KeyboardForm::sigKeyPressed,
            this, &SystemSetDialog::slotKeyPressed);
    delete m_KeyBoard;
    m_KeyBoard = nullptr;
}

bool SystemSetDialog::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type() == QEvent::FocusIn)
    {
        emit sigResetLockTime();
        if(m_KeyboardMap.find(watched) != m_KeyboardMap.end())
        {
            QWidget *pObj = qobject_cast<QWidget*>(watched);
            QPoint thisPos = pObj->mapToGlobal(pObj->pos());
            //qDebug() << watched->objectName() <<  << thisPos;
            initKeyBoard(mapToGlobal(QCursor::pos()).x(),
                         thisPos.y(), pObj->width(), pObj->height());
            m_CurrentObj = watched;
            m_KeyBoard->show();
        }
        else
        {
            uninitKeyBoard();
        }
    }
    else if (event->type() == QEvent::MouseButtonPress)
    {
        emit sigResetLockTime();
        if(watched == this)
        {
            uninitKeyBoard();
            this->setFocus();
        }
        else if(m_KeyboardMap.find(watched) != m_KeyboardMap.end())
        {
            if(m_KeyBoard != nullptr)
                return false;
            else
            {
                QWidget *pObj = qobject_cast<QWidget*>(watched);
                QPoint thisPos = pObj->mapToGlobal(pObj->pos());
                //qDebug() << watched->objectName() << mapToGlobal(QCursor::pos()) << thisPos;
                initKeyBoard(mapToGlobal(QCursor::pos()).x(),
                             thisPos.y(), pObj->width(), pObj->height());
                m_CurrentObj = watched;
                m_KeyBoard->show();
            }
        }
    }
    return false;
}

void SystemSetDialog::on_harmonicsGroupCB_activated(int index)
{
    if(m_HarmonicsNeedSave)
    {
        //auto btn = QMessageBox::information(this, tr("保存"), tr("是否保存当前编辑?"),
        //                         QMessageBox::No | QMessageBox::Save);
        WarningDialog warning(this);
        warning.initWarning(tr("错误"), tr("锁屏密码长度需为4位"));
        warning.exec();
        if(warning.exec() == QDialog::Accepted)
        {
            harmonics2data();
            dbOperation dbObj;
            dbObj.HarmonicsWrite(m_HarmonicsGroup + 1, m_HarmonicsData);
        }
    }
    readHarmonics(index + 1);
    harmonics2ui();
    ui->harmonTable->selectRow(0);
    harmonicsRowSelect(0);
    m_HarmonicsGroup = index;
    emit sigResetLockTime();
}

void SystemSetDialog::on_harmonicsTimesCB_activated(int index)
{
    if(index < 0 || index >= ui->harmonTable->rowCount())
        return;
    ui->harmonTable->selectRow(index);
    ui->percentLE->setText(ui->harmonTable->item(index, 1)->text());
    ui->angleLE->setText(ui->harmonTable->item(index, 2)->text());
    emit sigResetLockTime();
}

void SystemSetDialog::on_percentLE_editingFinished()
{
    int row = ui->harmonTable->row(ui->harmonTable->selectedItems().at(0));
    ui->harmonTable->item(row, 1)->setText(ui->percentLE->text());
    m_HarmonicsNeedSave = true;
    emit sigResetLockTime();
}

void SystemSetDialog::on_angleLE_editingFinished()
{
    int row = ui->harmonTable->row(ui->harmonTable->selectedItems().at(0));
    ui->harmonTable->item(row, 2)->setText(ui->angleLE->text());
    m_HarmonicsNeedSave = true;
    emit sigResetLockTime();
}

void SystemSetDialog::on_resetBtn_clicked()
{
    int i = 0;
    while(i < ui->harmonTable->rowCount())
    {
        ui->harmonTable->item(i, 1)->setText("0.00");
        ui->harmonTable->item(i, 2)->setText("0.0");
        i++;
    }
    ui->harmonTable->selectRow(0);
    harmonicsRowSelect(0);
    emit sigResetLockTime();
}

void SystemSetDialog::on_signinBtn_clicked()
{
    emit sigResetLockTime();
}

void SystemSetDialog::on_harmonTable_cellClicked(int row, int column)
{
    harmonicsRowSelect(row);
    emit sigResetLockTime();
}

void SystemSetDialog::on_refreshExportBtn_clicked()
{
    initUdisk(0);
    emit sigResetLockTime();
}

void SystemSetDialog::on_exportBtn_clicked()
{
    emit sigResetLockTime();
    if(ui->UdiskExportCB->count() <= 0 ||
            ui->UdiskExportCB->currentText().length() <= 0)
        return;
    QString path = ui->UdiskExportCB->currentText();
    QDir dir(path);
    QFileInfo file(path + "/PIPS/systemdata.db");
    if(!dir.exists("PIPS"))
    {
        dir.mkdir("PIPS");
    }
    if(file.isFile())
    {
        QFile::remove(path + "/PIPS/systemdata.db");
    }
    bool bRet = QFile::copy(QDir::currentPath() + "/db/systemdata.db",
                path + "/PIPS/systemdata.db");
    //if(bRet)
    //    QMessageBox::information(this, tr("导出"), tr("导出成功"));
    //else
    //    QMessageBox::information(this, tr("导出"), tr("导出失败"));
    QString content;
    if(bRet)
        content = tr("导出成功");
    else
        content = tr("导出失败");
    WarningDialog warning(this);
    warning.initWarning(tr("导出"), content);
    warning.exec();
}

void SystemSetDialog::on_efreshImportBtn_clicked()
{
    initUdisk(1);
}

void SystemSetDialog::on_importBtn_clicked()
{
    emit sigResetLockTime();
    if(ui->UdiskImportCB->count() <= 0 ||
            ui->UdiskImportCB->currentText().length() <= 0)
        return;
    QString path = ui->UdiskImportCB->currentText();
    QDir dir(path);
    QFileInfo file(path + "/PIPS/systemdata.db");
    if(!dir.exists("PIPS") || !file.isFile())
    {
        WarningDialog warning(this);
        warning.initWarning(tr("导入"), tr("未读取到导入文件"));
        warning.exec();
        //QMessageBox::information(this, tr("导入"), tr("未读取到导入文件"));
        return;
    }
    QString currentPath = QDir::currentPath() + "/db/systemdata.db";
    QFile::remove(currentPath);
    bool bRet = QFile::copy(path + "/PIPS/systemdata.db", currentPath);
//    if(bRet)
//        QMessageBox::information(this, tr("导入"), tr("导入成功"));
//    else
//        QMessageBox::information(this, tr("导入"), tr("导入失败"));
    QString content;
    if(bRet)
        content = tr("导入成功");
    else
        content = tr("导入失败");
    WarningDialog warning(this);
    warning.initWarning(tr("导入"), content);
    warning.exec();
}

void SystemSetDialog::on_harmonicsSaveBtn_clicked()
{
    harmonics2data();
    dbOperation dbObj;
    dbObj.HarmonicsWrite(m_HarmonicsGroup + 1, m_HarmonicsData);
    WarningDialog warning(this);
    warning.initWarning(tr("保存"), tr("保存成功"));
    warning.exec();
    //QMessageBox::information(this, tr("保存"), tr("保存成功"));
    LogData logdata;
    logdata.TestMode = ENM_TESTMODE_MAX;
    logdata.OutputMode = ENM_OUTPUT_MAX;
    logdata.OperationType = ENM_LOG_HARMONICS_SAVE;
    logdata.Time = ui->timeLab->text();
    logdata.IGBT = m_IGBT;
    logdata.Transformer = m_Transformer;
    logdata.FanSpeed = m_FanSpeed;
    LogOperation::getLogInstance()->writeLog(logdata);
    CanSendData sendData;
    HarmonicsGroupData harmonicsData;
    sendData.Cmd = ENM_CMD_HARMONICSUPDATE;
    sendData.Group = m_HarmonicsGroup + 1;
    sendData.AllHarmonics.clear();
    for(int i = 0; i < 39; i++)
    {
        harmonicsData.Percent[i] = m_HarmonicsData.at(i).Percent;
        harmonicsData.Angles[i] = m_HarmonicsData.at(i).Angles;
    }
    sendData.AllHarmonics.append(harmonicsData);
    emit sigSendData(sendData);
    emit sigResetLockTime();
}

void SystemSetDialog::on_alarmPreBtn_clicked()
{

    emit sigResetLockTime();
}

void SystemSetDialog::on_alarmNextBtn_clicked()
{

    emit sigResetLockTime();
}

void SystemSetDialog::on_alarmClearBtn_clicked()
{
    //auto btn = QMessageBox::information(this, tr("删除"), tr("确认删除所有报警信息?"),
    //                         QMessageBox::No | QMessageBox::Yes);
    WarningDialog warning(this);
    warning.initWarning(tr("删除"), tr("确认删除所有报警信息?"));
    if(warning.exec() == QDialog::Rejected)
    {
        emit sigResetLockTime();
        return;
    }
    emit sigResetLockTime();
}

void SystemSetDialog::on_logPreBtn_clicked()
{
    m_CurrentLogPage--;
    LogOperation::getLogInstance()->readLog(m_CurrentLogPage, m_LogData);
    log2ui();
    updateLogBtnStatus();
    emit sigResetLockTime();
}

void SystemSetDialog::on_logNextBtn_clicked()
{
    m_CurrentLogPage++;
    LogOperation::getLogInstance()->readLog(m_CurrentLogPage, m_LogData);
    log2ui();
    updateLogBtnStatus();
    emit sigResetLockTime();
}

void SystemSetDialog::on_logClearBtn_clicked()
{
    //auto btn = QMessageBox::information(this, tr("删除"), tr("确认删除所有日志?"),
    //                         QMessageBox::No | QMessageBox::Yes);
    WarningDialog warning(this);
    warning.initWarning(tr("删除"), tr("确认删除所有日志?"));
    if(warning.exec() == QDialog::Rejected)
    {
        emit sigResetLockTime();
        return;
    }
    m_CurrentLogPage = 0;
    m_LogData.clear();
    LogOperation::getLogInstance()->clearLog();
    log2ui();
    updateLogBtnStatus();
    emit sigResetLockTime();
}
