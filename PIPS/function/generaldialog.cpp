#include "generaldialog.h"
#include "ui_generaldialog.h"
#include "function/stepladdersetdialog.h"
#include "function/stepsetdialog.h"
#include "function/gradientsetdialog.h"
#include "function/throughsetdialog.h"
#include "Data/dboperation.h"
#include "Data/jsonopration.h"
#include "function/generalsetdialog.h"
#include "function/stepladdersetdialog.h"
#include "function/stepsetdialog.h"
#include "function/gradientsetdialog.h"
#include "function/throughsetdialog.h"
#include <QListView>
#include "Common/rtc.h"
#include <QDebug>
#include "Common/lockmanager.h"
#include "Data/logoperation.h"
#include "communication/communication.h"
#include <QEvent>
#include <QKeyEvent>
#include <QCoreApplication>

GeneralDialog::GeneralDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GeneralDialog),
    m_TestingStatus(false),
    m_KeyBoard(nullptr),
    m_CurrentObj(nullptr)
{
    int i = 0;
    this->setGeometry(0, 0, 1280, 800);
    this->setWindowFlags(Qt::FramelessWindowHint);
    //ui->currentStepNoCB->lineEdit()->setAlignment(Qt::AlignCenter);
    ui->setupUi(this);
    //ui->stepNoLayoutU->setEnabled(false);
    ui->currentStepNoCB->setView(new QListView(this));
    ui->outputModeCB->setView(new QListView(this));
    ui->outputModeCB2->setView(new QListView(this));
    ui->outputModeCB3->setView(new QListView(this));
    ui->outputModeCB4->setView(new QListView(this));
    ui->outputModeCB5->setView(new QListView(this));
    ui->voltageGearCB->setView(new QListView(this));
    ui->voltageSetLEU->installEventFilter(this);
    ui->voltageSetLEV->installEventFilter(this);
    ui->voltageSetLEW->installEventFilter(this);
    ui->freqSetLEU->installEventFilter(this);
    ui->freqSetLEV->installEventFilter(this);
    ui->freqSetLEW->installEventFilter(this);
    this->installEventFilter(this);
    m_KeyboardMap.insert(ui->voltageSetLEU, i++);
    m_KeyboardMap.insert(ui->voltageSetLEV, i++);
    m_KeyboardMap.insert(ui->voltageSetLEW, i++);
    m_KeyboardMap.insert(ui->freqSetLEU, i++);
    m_KeyboardMap.insert(ui->freqSetLEV, i++);
    m_KeyboardMap.insert(ui->freqSetLEW, i++);
    ui->outputModeCB5->setItemData(1, QVariant(0), Qt::UserRole - 1);
    ui->outputModeCB5->setItemData(2, QVariant(0), Qt::UserRole - 1);
    connect(rtc::getRtcInstance(), &rtc::sigTimeChanged,
            this, &GeneralDialog::slotDateTime, Qt::QueuedConnection);
    connect(this, &GeneralDialog::sigResetLockTime, LockManager::getRtcInstance(),
            &LockManager::slotResetLockTime, Qt::QueuedConnection);
    connect(LockManager::getRtcInstance(), &LockManager::sigStopTest, this,
            &GeneralDialog::slotStopTest);
}

GeneralDialog::~GeneralDialog()
{
    disconnect(rtc::getRtcInstance(), &rtc::sigTimeChanged,
            this, &GeneralDialog::slotDateTime);
    disconnect(this, &GeneralDialog::sigResetLockTime, LockManager::getRtcInstance(),
            &LockManager::slotResetLockTime);
    disconnect(LockManager::getRtcInstance(), &LockManager::sigStopTest, this,
            &GeneralDialog::slotStopTest);
    uninitThread();
    delete ui;
}

void GeneralDialog::initTestMode(const int p_testmode)
{
    m_TestMode = p_testmode;
    ui->infoWidget->setCurrentIndex(m_TestMode);
    updateInfoWidget();
    m_StepSet.clear();
    m_GradientSet.clear();
    m_ThroughSet.clear();
    initThread();
}

void GeneralDialog::setGeneral(const GeneralData &p_data)
{
    m_GenralSet = p_data;
    ui->currentStepNoCB->setCurrentIndex(m_GenralSet.StepNo - 1);
    ui->outputModeCB->setCurrentIndex(m_GenralSet.OutputMode);
    m_CurrentOutputMode = m_GenralSet.OutputMode;
    ui->voltageGearCB->setCurrentIndex(m_GenralSet.VoltageLevel);
}

void GeneralDialog::setStepLadder(const StepLadderData &p_data)
{
    m_StepLadderSet = p_data;
    ui->outputModeCB2->setCurrentIndex(m_StepLadderSet.OutputMode);
    m_CurrentOutputMode = m_StepLadderSet.OutputMode;
    m_TestCtrl.OutputMode = m_StepLadderSet.OutputMode;
}

void GeneralDialog::setStep(const QList<StepData> &p_data)
{
    m_StepSet = p_data;
    ui->outputModeCB3->setCurrentIndex(m_TestCtrl.OutputMode);
    m_CurrentOutputMode = m_TestCtrl.OutputMode;
    ui->startStepNoLE3->setText(QString::number(m_TestCtrl.StartNo));
    ui->stopStepNoLE3->setText(QString::number(m_TestCtrl.StopNo));
    ui->cycleLE3->setText(QString::number(m_TestCtrl.CycleTimes));
}

void GeneralDialog::setGradient(const QList<GradientData> &p_data)
{
    m_GradientSet = p_data;
    ui->outputModeCB4->setCurrentIndex(m_TestCtrl.OutputMode);
    m_CurrentOutputMode = m_TestCtrl.OutputMode;
    ui->startStepNoLE4->setText(QString::number(m_TestCtrl.StartNo));
    ui->stopStepNoLE4->setText(QString::number(m_TestCtrl.StopNo));
    ui->cycleLE4->setText(QString::number(m_TestCtrl.CycleTimes));
}

void GeneralDialog::setThrough(const QList<ThroughData> &p_data)
{
    m_ThroughSet = p_data;
    //ui->currentStepNoCB->setCurrentIndex(m_TestCtrl.StepNo - 1);
    ui->startStepNoLE5->setText(QString::number(m_TestCtrl.StartNo));
    m_CurrentOutputMode = m_TestCtrl.OutputMode;
    ui->stopStepNoLE5->setText(QString::number(m_TestCtrl.StopNo));
    ui->outputModeCB5->setCurrentIndex(m_TestCtrl.OutputMode);
    ui->cycleLE5->setText(QString::number(m_TestCtrl.CycleTimes));
}

void GeneralDialog::getCtrlInfo(const ConfigData &p_cfg)
{
    switch(m_TestMode)
    {
    case ENM_TESTMODE_STEP:
        m_TestCtrl.OutputMode = p_cfg.StepOutputMode;
        m_TestCtrl.StartNo = p_cfg.StepStartNo;
        m_TestCtrl.StopNo = p_cfg.StepStopNo;
        m_TestCtrl.CycleTimes = p_cfg.StepCycleTimes;
        break;
    case ENM_TESTMODE_GRADIENT:
        m_TestCtrl.OutputMode = p_cfg.GradientOutputMode;
        m_TestCtrl.StartNo = p_cfg.GradientStartNo;
        m_TestCtrl.StopNo = p_cfg.GradientStopNo;
        m_TestCtrl.CycleTimes = p_cfg.GradientCycleTimes;
        break;
    case ENM_TESTMODE_THROUGH:
        m_TestCtrl.OutputMode = p_cfg.ThroughOutputMode;
        m_TestCtrl.StepNo = p_cfg.ThroughStep;
        m_TestCtrl.StartNo = p_cfg.ThroughStartNo;
        m_TestCtrl.StopNo = p_cfg.ThroughStopNo;
        m_TestCtrl.CycleTimes = p_cfg.ThroughCycleTimes;
        break;
    default:
        break;
    }
}

void GeneralDialog::setCtrlInfo(const int p_testmode, TestCtrl &p_cfg)
{
    switch(p_testmode)
    {
    case ENM_TESTMODE_GENERAL:
        p_cfg.StepNo = ui->currentStepNoCB->currentIndex() + 1;
        p_cfg.OutputMode = m_CurrentOutputMode;
        break;
    case ENM_TESTMODE_STEPLADDER:
        p_cfg.OutputMode = m_CurrentOutputMode;
        break;
    case ENM_TESTMODE_STEP:
        p_cfg.StartNo = ui->startStepNoLE3->text().toInt();
        p_cfg.StopNo = ui->stopStepNoLE3->text().toInt();
        p_cfg.CycleTimes = ui->cycleLE3->text().toInt();
        break;
    case ENM_TESTMODE_GRADIENT:
        p_cfg.StartNo = ui->startStepNoLE4->text().toInt();
        p_cfg.StopNo = ui->stopStepNoLE4->text().toInt();
        p_cfg.CycleTimes = ui->cycleLE4->text().toInt();
        break;
    case ENM_TESTMODE_THROUGH:
        p_cfg.StartNo = ui->startStepNoLE5->text().toInt();
        p_cfg.StopNo = ui->stopStepNoLE5->text().toInt();
        p_cfg.CycleTimes = ui->cycleLE5->text().toInt();
        break;
    default:
        return;
    }
}

void GeneralDialog::slotDateTime(const QString p_datetime)
{
    ui->timeLab->setText(p_datetime);
}

void GeneralDialog::slotStopTest()
{
    if(m_TestingStatus)
    {
        startStopBtn();
    }
}

void GeneralDialog::slotRecvData(const PrintData p_printdata)
{
    m_DeviceTestingStatus = p_printdata.status;
    m_StepNo[0] = p_printdata.step1;
    m_StepNo[1] = p_printdata.step2;
    m_StepNo[2] = p_printdata.step3;
    m_FanSpeed = p_printdata.fanSpeed;
    m_IGBT = p_printdata.igbt;
    m_Transformer = p_printdata.transformer;
    QComboBox *p_cbox = nullptr;
    int i = 3;
    switch(m_TestMode)
    {
    case ENM_TESTMODE_GENERAL:
        p_cbox = ui->outputModeCB;
        break;
    case ENM_TESTMODE_STEPLADDER:
        p_cbox = ui->outputModeCB2;
        if(p_cbox->currentIndex() == ENM_OUTPUT_DISCRETE)
        {
            ui->singleStepTimeLEU2->setText(QString::number(p_printdata.fData[0],
                                            'f', DEF_DECIMAL_TIME) + DEF_UNIT_TIME);
            ui->singleStepTimeLEV2->setText(QString::number(p_printdata.fData[1],
                                            'f', DEF_DECIMAL_TIME) + DEF_UNIT_TIME);
            ui->singleStepTimeLEW2->setText(QString::number(p_printdata.fData[2],
                                               'f', DEF_DECIMAL_TIME) + DEF_UNIT_TIME);
            ui->stepNoLEU2->setText(QString::number(m_StepNo[0]));
            ui->stepNoLEV2->setText(QString::number(m_StepNo[1]));
            ui->stepNoLEW2->setText(QString::number(m_StepNo[2]));
        }
        else
        {
            ui->singleStepTimeLEU2->setText(QString::number(p_printdata.fData[0],
                                               'f', DEF_DECIMAL_TIME) + DEF_UNIT_TIME);
            ui->stepNoLEU2->setText(QString::number(m_StepNo[0]));
        }
        break;
    case ENM_TESTMODE_STEP:
        p_cbox = ui->outputModeCB3;
        if(p_cbox->currentIndex() == ENM_OUTPUT_DISCRETE)
        {
            ui->singleStepTimeLEU3->setText(QString::number(p_printdata.fData[0],
                                            'f', DEF_DECIMAL_TIME) + DEF_UNIT_TIME);
            ui->singleStepTimeLEV3->setText(QString::number(p_printdata.fData[1],
                                            'f', DEF_DECIMAL_TIME) + DEF_UNIT_TIME);
            ui->singleStepTimeLEW3->setText(QString::number(p_printdata.fData[2],
                                               'f', DEF_DECIMAL_TIME) + DEF_UNIT_TIME);
        }
        else
        {
            ui->singleStepTimeLEU3->setText(QString::number(p_printdata.fData[0],
                                               'f', DEF_DECIMAL_TIME) + DEF_UNIT_TIME);
        }
        break;
    case ENM_TESTMODE_GRADIENT:
        p_cbox = ui->outputModeCB4;
        if(p_cbox->currentIndex() == ENM_OUTPUT_DISCRETE)
        {
            ui->singleStepSetTimeLEU4->setText(QString::number(p_printdata.fData[0],
                                               'f', DEF_DECIMAL_TIME) + DEF_UNIT_TIME);
            ui->singleStepSetTimeLEV4->setText(QString::number(p_printdata.fData[1],
                                               'f', DEF_DECIMAL_TIME) + DEF_UNIT_TIME);
            ui->singleStepSetTimeLEW4->setText(QString::number(p_printdata.fData[2],
                                               'f', DEF_DECIMAL_TIME) + DEF_UNIT_TIME);
        }
        else
        {
            ui->singleStepSetTimeLEU4->setText(QString::number(p_printdata.fData[0],
                                               'f', DEF_DECIMAL_TIME) + DEF_UNIT_TIME);
        }
        break;
    case ENM_TESTMODE_THROUGH:
        p_cbox = ui->outputModeCB5;
        ui->singleStepTimeLEU5->setText(QString::number(p_printdata.fData[0],
                                           'f', DEF_DECIMAL_TIME) + DEF_UNIT_TIME);
        break;
    default:
        p_cbox = ui->outputModeCB;
        break;
    }
    int outputMode = p_cbox->currentIndex();
    QStringList dataList;
    getValueString(dataList, p_printdata);
    switch(outputMode)
    {
    case ENM_OUTPUT_THREEPHASE:
        ui->voltageLabU->setText(dataList.at(i++));
        ui->voltageLabV->setText(dataList.at(i++));
        ui->voltageLabW->setText(dataList.at(i++));
        ui->currentLabU->setText(dataList.at(i++));
        ui->currentLabV->setText(dataList.at(i++));
        ui->currentLabW->setText(dataList.at(i++));
        ui->detailValU1->setText(dataList.at(i++));
        ui->detailValV1->setText(dataList.at(i++));
        ui->detailValW1->setText(dataList.at(i++));
        ui->detailValU2->setText(dataList.at(i++));
        ui->detailValV2->setText(dataList.at(i++));
        ui->detailValW2->setText(dataList.at(i++));
        i++;
        ui->detailValU4->setText(dataList.at(i++));
        ui->detailValV4->setText(dataList.at(i++));
        ui->detailValW4->setText(dataList.at(i++));
        ui->detailValU5->setText(dataList.at(i++));
        ui->detailValV5->setText(dataList.at(i++));
        ui->detailValW5->setText(dataList.at(i++));
        ui->detailValU6->setText(dataList.at(i++));
        ui->detailValV6->setText(dataList.at(i++));
        ui->detailValW6->setText(dataList.at(i++));
        ui->powerTotalVal->setText(dataList.at(12));
        ui->freqTotalVal->setText("");
        ui->powerVal1->setText(dataList.at(i++));
        ui->powerVal2->setText(dataList.at(i++));
        ui->powerVal3->setText(dataList.at(i++));
        break;
    case ENM_OUTPUT_DISCRETE:
        ui->voltageLabU->setText(dataList.at(i++));
        ui->voltageLabV->setText(dataList.at(i++));
        ui->voltageLabW->setText(dataList.at(i++));
        ui->currentLabU->setText(dataList.at(i++));
        ui->currentLabV->setText(dataList.at(i++));
        ui->currentLabW->setText(dataList.at(i++));
        ui->detailValU1->setText(dataList.at(i++));
        ui->detailValV1->setText(dataList.at(i++));
        ui->detailValW1->setText(dataList.at(i++));
        ui->detailValU2->setText(dataList.at(i++));
        ui->detailValV2->setText(dataList.at(i++));
        ui->detailValW2->setText(dataList.at(i++));
        ui->detailValU3->setText("");
        ui->detailValV3->setText("");
        ui->detailValW3->setText("");
        i++;
        ui->detailValU4->setText(dataList.at(i++));
        ui->detailValV4->setText(dataList.at(i++));
        ui->detailValW4->setText(dataList.at(i++));
        ui->detailValU5->setText(dataList.at(i++));
        ui->detailValV5->setText(dataList.at(i++));
        ui->detailValW5->setText(dataList.at(i++));
        ui->detailValU6->setText(dataList.at(i++));
        ui->detailValV6->setText(dataList.at(i++));
        ui->detailValW6->setText(dataList.at(i++));
        break;
    case ENM_OUTPUT_IMBANLANCE:
        ui->voltageLabU->setText(dataList.at(i++));
        ui->voltageLabV->setText(dataList.at(i++));
        ui->voltageLabW->setText(dataList.at(i++));
        ui->currentLabU->setText(dataList.at(i++));
        ui->currentLabV->setText(dataList.at(i++));
        ui->currentLabW->setText(dataList.at(i++));
        ui->detailValU1->setText(dataList.at(i++));
        ui->detailValV1->setText(dataList.at(i++));
        ui->detailValW1->setText(dataList.at(i++));
        ui->detailValU2->setText(dataList.at(i++));
        ui->detailValV2->setText(dataList.at(i++));
        ui->detailValW2->setText(dataList.at(i++));
        i++;
        ui->detailValU4->setText(dataList.at(i++));
        ui->detailValV4->setText(dataList.at(i++));
        ui->detailValW4->setText(dataList.at(i++));
        ui->detailValU5->setText(dataList.at(i++));
        ui->detailValV5->setText(dataList.at(i++));
        ui->detailValW5->setText(dataList.at(i++));
        ui->detailValU6->setText(dataList.at(i++));
        ui->detailValV6->setText(dataList.at(i++));
        ui->detailValW6->setText(dataList.at(i++));
        ui->powerTotalVal->setText(dataList.at(12));
        ui->freqTotalVal->setText("");
        break;
    case ENM_OUTPUT_SINGLE:
        ui->voltageLabU->setText(dataList.at(3));

        ui->currentLabU->setText(dataList.at(6));

        ui->detailValU1->setText(dataList.at(9));

        ui->detailValU2->setText(dataList.at(13));

        ui->detailValU4->setText(dataList.at(16));

        ui->detailValU5->setText(dataList.at(19));

        ui->detailValU6->setText(dataList.at(22));

        ui->powerTotalVal->setText(dataList.at(12));
        ui->freqTotalVal->setText("");
        break;
    default:
        break;
    }
    if(m_DeviceTestingStatus == 0xFF)
        m_WarnLight.startLight(ENM_LIGHT_RED);
}

void GeneralDialog::slotKeyPressed(const int p_key)
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
    //QCoreApplication::sendEvent(obj, keyReleased);
    //emit virtualKeyPress(Qt::Key_0, "0", Qt::NoModifier, false);
}

void GeneralDialog::updateInfoWidget()
{
    QLayout *pLayout = nullptr;
    switch(m_TestMode)
    {
    case ENM_TESTMODE_GENERAL:
        ui->currentStepNoCB->setEnabled(!m_TestingStatus);
        ui->outputModeCB->setEnabled(!m_TestingStatus);
        ui->voltageGearLab->setVisible(!m_TestingStatus);
        ui->voltageGearCB->setVisible(!m_TestingStatus);
        ui->voltageSetLab->setVisible(m_TestingStatus);
        ui->voltageSetLOU->setVisible(m_TestingStatus);
        ui->voltageSetLOV->setVisible(m_TestingStatus);
        ui->voltageSetLOW->setVisible(m_TestingStatus);
        ui->freqSetLab->setVisible(m_TestingStatus);
        ui->freqSetLOU->setVisible(m_TestingStatus);
        ui->freqSetLOV->setVisible(m_TestingStatus);
        ui->freqSetLOW->setVisible(m_TestingStatus);
        ui->startBtn->setText(m_TestingStatus ? tr(" 停止") : tr(" 启动"));
        if(m_TestingStatus)
            ui->startBtn->setIcon(QIcon(":/png/main/icon_stop_selected.png"));
        else
            ui->startBtn->setIcon(QIcon(":/png/main/icon_start_selected.png"));
        ui->setDataBtn->setVisible(!m_TestingStatus);
        ui->backBtn->setVisible(!m_TestingStatus);
        pLayout = ui->generalPage->layout();
        break;
    case ENM_TESTMODE_STEPLADDER:
        ui->outputModeCB2->setEnabled(!m_TestingStatus);
        ui->stepNumLab2->setVisible(m_TestingStatus);
        ui->stepNumLOU2->setVisible(m_TestingStatus);
        ui->stepNumLOV2->setVisible(m_TestingStatus);
        ui->stepNumLOW2->setVisible(m_TestingStatus);
        ui->singleStepTimeLab2->setVisible(m_TestingStatus);
        ui->singleStepTimeLOU2->setVisible(m_TestingStatus);
        ui->singleStepTimeLOV2->setVisible(m_TestingStatus);
        ui->singleStepTimeLOW2->setVisible(m_TestingStatus);
        ui->totalTimeLab2->setVisible(m_TestingStatus);
        ui->totalTimeLOU2->setVisible(m_TestingStatus);
        ui->totalTimeLOV2->setVisible(m_TestingStatus);
        ui->totalTimeLOW2->setVisible(m_TestingStatus);
        ui->startBtn2->setText(m_TestingStatus ? tr(" 停止") : tr(" 启动"));
        if(m_TestingStatus)
            ui->startBtn2->setIcon(QIcon(":/png/main/icon_stop_selected.png"));
        else
            ui->startBtn2->setIcon(QIcon(":/png/main/icon_start_selected.png"));
        ui->setDataBtn2->setVisible(!m_TestingStatus);
        ui->backBtn2->setVisible(!m_TestingStatus);
        pLayout = ui->stepLadderPage->layout();
        break;
    case ENM_TESTMODE_STEP:
        ui->outputModeCB3->setEnabled(!m_TestingStatus);
        ui->singleStepTimeLab3->setVisible(m_TestingStatus);
        ui->singleStepTimeLOU3->setVisible(m_TestingStatus);
        ui->singleStepTimeLOV3->setVisible(m_TestingStatus);
        ui->singleStepTimeLOW3->setVisible(m_TestingStatus);
        ui->totalTimeLab3->setVisible(m_TestingStatus);
        ui->totalTimeLOU3->setVisible(m_TestingStatus);
        ui->totalTimeLOV3->setVisible(m_TestingStatus);
        ui->totalTimeLOW3->setVisible(m_TestingStatus);
        ui->startBtn3->setText(m_TestingStatus ? tr(" 停止") : tr(" 启动"));
        if(m_TestingStatus)
            ui->startBtn3->setIcon(QIcon(":/png/main/icon_stop_selected.png"));
        else
            ui->startBtn3->setIcon(QIcon(":/png/main/icon_start_selected.png"));
        ui->setDataBtn3->setVisible(!m_TestingStatus);
        ui->backBtn3->setVisible(!m_TestingStatus);
        pLayout = ui->stepPage->layout();
        break;
    case ENM_TESTMODE_GRADIENT:
        ui->outputModeCB4->setEnabled(!m_TestingStatus);
        ui->singleStepTimeLab4->setVisible(m_TestingStatus);
        ui->singleStepTimeLOU4->setVisible(m_TestingStatus);
        ui->singleStepTimeLOV4->setVisible(m_TestingStatus);
        ui->singleStepTimeLOW4->setVisible(m_TestingStatus);
        ui->totalTimeLab4->setVisible(m_TestingStatus);
        ui->totalTimeLOU4->setVisible(m_TestingStatus);
        ui->totalTimeLOV4->setVisible(m_TestingStatus);
        ui->totalTimeLOW4->setVisible(m_TestingStatus);
        ui->startBtn4->setText(m_TestingStatus ? tr(" 停止") : tr(" 启动"));
        if(m_TestingStatus)
            ui->startBtn4->setIcon(QIcon(":/png/main/icon_stop_selected.png"));
        else
            ui->startBtn4->setIcon(QIcon(":/png/main/icon_start_selected.png"));
        ui->setDataBtn4->setVisible(!m_TestingStatus);
        ui->backBtn4->setVisible(!m_TestingStatus);
        pLayout = ui->GradientPage->layout();
        break;
    case ENM_TESTMODE_THROUGH:
        ui->outputModeCB5->setEnabled(!m_TestingStatus);
        ui->singleStepTimeLab5->setVisible(m_TestingStatus);
        ui->singleStepTimeLO5->setVisible(m_TestingStatus);
        ui->totalTimeLab5->setVisible(m_TestingStatus);
        ui->totalTimeLO5->setVisible(m_TestingStatus);
        ui->startBtn5->setText(m_TestingStatus ? tr(" 停止") : tr(" 启动"));
        if(m_TestingStatus)
            ui->startBtn5->setIcon(QIcon(":/png/main/icon_stop_selected.png"));
        else
            ui->startBtn5->setIcon(QIcon(":/png/main/icon_start_selected.png"));
        ui->setDataBtn5->setVisible(!m_TestingStatus);
        ui->backBtn5->setVisible(!m_TestingStatus);
        pLayout = ui->throughPage->layout();
        break;
    default:
        break;
    }
    if(pLayout != nullptr)
    {
        int spacing = 10;
        if(!m_TestingStatus)
            spacing = 20;
        pLayout->setSpacing(spacing);
    }
}

void GeneralDialog::startStopBtn()
{
    LogData logdata;
    m_TestingStatus = !m_TestingStatus;
    updateInfoWidget();

    LockManager::getRtcInstance()->updateTestStatus(m_TestingStatus);
    if(m_TestingStatus)
        m_WarnLight.startLight(ENM_LIGHT_YELLOW);
    else
        m_WarnLight.startLight(ENM_LIGHT_GREEN);
    logdata.TestMode = ui->infoWidget->currentIndex();
    logdata.OutputMode = m_CurrentOutputMode;
    logdata.OperationType = m_TestingStatus ? ENM_LOG_THROUGH_START : ENM_LOG_THROUGH_STOP;
    logdata.Time = ui->timeLab->text();
    logdata.IGBT = m_IGBT;
    logdata.Transformer = m_Transformer;
    logdata.FanSpeed = m_FanSpeed;
    LogOperation::getLogInstance()->writeLog(logdata);
    emit sigResetLockTime();
}

void GeneralDialog::initThread()
{
    connect(ReadThread::getReadThread(), &ReadThread::sigReadTestData, this,
            &GeneralDialog::slotRecvData, Qt::QueuedConnection);
    connect(this, &GeneralDialog::sigSendData, WriteThread::getWriteThread(),
            &WriteThread::slotSendTestData, Qt::QueuedConnection);
}

void GeneralDialog::uninitThread()
{
    disconnect(ReadThread::getReadThread(), &ReadThread::sigReadTestData, this,
            &GeneralDialog::slotRecvData);
    disconnect(this, &GeneralDialog::sigSendData, WriteThread::getWriteThread(),
            &WriteThread::slotSendTestData);
}

void GeneralDialog::updateTestData(const int p_outputmode)
{

}

QString GeneralDialog::getValueString(QStringList &p_list, const PrintData &p_data)
{
    int i = 3;
    QString volt1 = QString::number(p_data.fData[i++], 'f', DEF_DECIMAL_VOLTAGE) +
            DEF_UNIT_VOLTAGE;
    QString volt2 = QString::number(p_data.fData[i++], 'f', DEF_DECIMAL_VOLTAGE) +
            DEF_UNIT_VOLTAGE;
    QString volt3 = QString::number(p_data.fData[i++], 'f', DEF_DECIMAL_VOLTAGE) +
            DEF_UNIT_VOLTAGE;
    QString curr1 = QString::number(p_data.fData[i++], 'f', DEF_DECIMAL_CURRENT) +
            DEF_UNIT_CURRENT;
    QString curr2 = QString::number(p_data.fData[i++], 'f', DEF_DECIMAL_CURRENT) +
            DEF_UNIT_CURRENT;
    QString curr3 = QString::number(p_data.fData[i++], 'f', DEF_DECIMAL_CURRENT) +
            DEF_UNIT_CURRENT;
    QString pow1 = QString::number(p_data.fData[i++], 'f', DEF_DECIMAL_POWER) +
            DEF_UNIT_POWER;
    QString pow2 = QString::number(p_data.fData[i++], 'f', DEF_DECIMAL_POWER) +
            DEF_UNIT_POWER;
    QString pow3 = QString::number(p_data.fData[i++], 'f', DEF_DECIMAL_POWER) +
            DEF_UNIT_POWER;
    QString pow4 = QString::number(p_data.fData[i++], 'f', DEF_DECIMAL_POWER) +
            DEF_UNIT_POWER;
    QString apow1 = QString::number(p_data.fData[i++], 'f', DEF_DECIMAL_POWER) +
            DEF_UNIT_POWER;
    QString apow2 = QString::number(p_data.fData[i++], 'f', DEF_DECIMAL_POWER) +
            DEF_UNIT_POWER;
    QString apow3 = QString::number(p_data.fData[i++], 'f', DEF_DECIMAL_POWER) +
            DEF_UNIT_POWER;
    QString pf1 = QString::number(p_data.fData[i++], 'f', DEF_DECIMAL_CFPF);
    QString pf2 = QString::number(p_data.fData[i++], 'f', DEF_DECIMAL_CFPF);
    QString pf3 = QString::number(p_data.fData[i++], 'f', DEF_DECIMAL_CFPF);
    QString cf1 = QString::number(p_data.fData[i++], 'f', DEF_DECIMAL_CFPF);
    QString cf2 = QString::number(p_data.fData[i++], 'f', DEF_DECIMAL_CFPF);
    QString cf3 = QString::number(p_data.fData[i++], 'f', DEF_DECIMAL_CFPF);
    QString lpeak1 = QString::number(p_data.fData[i++], 'f', DEF_DECIMAL_CURRENT) +
            DEF_UNIT_CURRENT;
    QString lpeak2 = QString::number(p_data.fData[i++], 'f', DEF_DECIMAL_CURRENT) +
            DEF_UNIT_CURRENT;
    QString lpeak3 = QString::number(p_data.fData[i++], 'f', DEF_DECIMAL_CURRENT) +
            DEF_UNIT_CURRENT;
    QString lineVolt1 = QString::number(p_data.fData[i++], 'f', DEF_DECIMAL_VOLTAGE) +
            DEF_UNIT_VOLTAGE;
    QString lineVolt2 = QString::number(p_data.fData[i++], 'f', DEF_DECIMAL_VOLTAGE) +
            DEF_UNIT_VOLTAGE;
    QString lineVolt3 = QString::number(p_data.fData[i++], 'f', DEF_DECIMAL_VOLTAGE) +
            DEF_UNIT_VOLTAGE;
    p_list << volt1 << volt2 << volt3 << curr1 << curr2 << curr3 << pow1 << pow2 <<
              pow3 << pow4 << apow1 << apow2 << apow3 << pf1 << pf2 << pf3 <<
              cf1 << cf2 << cf3 << lpeak1 << lpeak2 << lpeak3 << lineVolt1 <<
              lineVolt2 << lineVolt3;
}

void GeneralDialog::getSendData(const int p_testmode, QList<CanDataType> &p_senddata)
{
    switch(p_testmode)
    {
    case ENM_TESTMODE_GENERAL:
    {
        CanDataType data;
        data.M1_nVoltageLevel = m_GenralSet.VoltageLevel;
        data.M1_nWaveForm1 = m_GenralSet.WaveFormU;
        data.M1_nWaveForm2 = m_GenralSet.WaveFormV;
        data.M1_nWaveForm3 = m_GenralSet.WaveFormW;
        data.M1_nEnble1 = m_GenralSet.EnableU;
        data.M1_nEnble2 = m_GenralSet.EnableV;
        data.M1_nEnble3 = m_GenralSet.EnableW;
        data.M1_fVoltage1 = m_GenralSet.VoltageU;
        data.M1_fVoltage2 = m_GenralSet.VoltageV;
        data.M1_fVoltage3 = m_GenralSet.VoltageW;
        data.M1_fFrequency1 = m_GenralSet.FrequencyU;
        data.M1_fFrequency2 = m_GenralSet.FrequencyV;
        data.M1_fFrequency3 = m_GenralSet.FrequencyW;
        data.M1_fAngles1 = m_GenralSet.AnglesUV;
        data.M1_fAngles2 = m_GenralSet.AnglesUW;
        data.M1_fAngles3 = m_GenralSet.AnglesVW;
        data.M1_fStartTime1 = m_GenralSet.StartTimeU;
        data.M1_fStartTime2 = m_GenralSet.StartTimeV;
        data.M1_fStartTime3 = m_GenralSet.StartTimeW;
        p_senddata.append(data);
    }
        break;
    case ENM_TESTMODE_STEPLADDER:
    {
        CanDataType data;
        data.M2_nWaveForm1 = m_StepLadderSet.WaveFormU;
        data.M2_nWaveForm2 = m_StepLadderSet.WaveFormV;
        data.M2_nWaveForm3 = m_StepLadderSet.WaveFormW;
        data.M2_nStepCount1 = m_StepLadderSet.StepCountU;
        data.M2_nStepCount2 = m_StepLadderSet.StepCountV;
        data.M2_nStepCount3 = m_StepLadderSet.StepCountW;
        data.M2_fStartVoltage1 = m_StepLadderSet.StartVoltageU;
        data.M2_fStartVoltage2 = m_StepLadderSet.StartVoltageV;
        data.M2_fStartVoltage3 = m_StepLadderSet.StartVoltageW;
        data.M2_fStepVoltage1 = m_StepLadderSet.StepVoltageU;
        data.M2_fStepVoltage2 = m_StepLadderSet.StepVoltageV;
        data.M2_fStepVoltage3 = m_StepLadderSet.StepVoltageW;
        data.M2_fStartFrequency1 = m_StepLadderSet.StartFrequencyU;
        data.M2_fStartFrequency2 = m_StepLadderSet.StartFrequencyV;
        data.M2_fStartFrequency3 = m_StepLadderSet.StartFrequencyW;
        data.M2_fStepFrequency1 = m_StepLadderSet.StepFrequencyU;
        data.M2_fStepFrequency2 = m_StepLadderSet.StepFrequencyV;
        data.M2_fStepFrequency3 = m_StepLadderSet.StepFrequencyW;
        data.M2_fAngles1 = m_StepLadderSet.AnglesUV;
        data.M2_fAngles2 = m_StepLadderSet.AnglesUW;
        data.M2_fAngles3 = m_StepLadderSet.AnglesVW;
        data.M2_fTime1 = m_StepLadderSet.StepTimeU;
        data.M2_fTime2 = m_StepLadderSet.StepTimeV;
        data.M2_fTime3 = m_StepLadderSet.StepTimeW;
        p_senddata.append(data);
    }
        break;
    case ENM_TESTMODE_STEP:
    {
        int i = 0;
        while(i < m_StepSet.count())
        {
            CanDataType data;
            data.M3_nWaveForm1 = m_StepSet.at(i).WaveFormU;
            data.M3_nWaveForm2 = m_StepSet.at(i).WaveFormV;
            data.M3_nWaveForm3 = m_StepSet.at(i).WaveFormW;
            data.M3_nCycle1 = ui->cycleLE3->text().toInt();
            data.M3_fVoltage1 = m_StepSet.at(i).VoltageU;
            data.M3_fVoltage2 = m_StepSet.at(i).VoltageV;
            data.M3_fVoltage3 = m_StepSet.at(i).VoltageW;
            data.M3_fFrequency1 = m_StepSet.at(i).FrequencyU;
            data.M3_fFrequency2 = m_StepSet.at(i).FrequencyV;
            data.M3_fFrequency3 = m_StepSet.at(i).FrequencyW;
            data.M3_fAngles1 = m_StepSet.at(i).AnglesUV;
            data.M3_fAngles2 = m_StepSet.at(i).AnglesUW;
            data.M3_fAngles3 = m_StepSet.at(i).AnglesVW;
            data.M3_fTime1 = m_StepSet.at(i).StepTimeU;
            data.M3_fTime2 = m_StepSet.at(i).StepTimeV;
            data.M3_fTime3 = m_StepSet.at(i).StepTimeW;
            p_senddata.append(data);
            i++;
        }
    }
        break;
    case ENM_TESTMODE_GRADIENT:
    {
        int i = 0;
        while(i < m_GradientSet.count())
        {
            CanDataType data;
            data.M4_nWaveForm1 = m_GradientSet.at(i).WaveFormU;
            data.M4_nWaveForm2 = m_GradientSet.at(i).WaveFormV;
            data.M4_nWaveForm3 = m_GradientSet.at(i).WaveFormW;
            data.M4_nCycle1 = ui->cycleLE4->text().toInt();
            data.M4_fStartVoltage1 = m_GradientSet.at(i).StartVoltageU;
            data.M4_fStartVoltage2 = m_GradientSet.at(i).StartVoltageV;
            data.M4_fStartVoltage3 = m_GradientSet.at(i).StartVoltageW;
            data.M4_fStopVoltage1 = m_GradientSet.at(i).StopVoltageU;
            data.M4_fStopVoltage2 = m_GradientSet.at(i).StopVoltageV;
            data.M4_fStopVoltage3 = m_GradientSet.at(i).StopVoltageW;
            data.M4_fStartFrequency1 = m_GradientSet.at(i).StartFrequencyU;
            data.M4_fStartFrequency2 = m_GradientSet.at(i).StartFrequencyV;
            data.M4_fStartFrequency3 = m_GradientSet.at(i).StartFrequencyW;
            data.M4_fStopFrequency1 = m_GradientSet.at(i).StopFrequencyU;
            data.M4_fStopFrequency2 = m_GradientSet.at(i).StopFrequencyV;
            data.M4_fStopFrequency3 = m_GradientSet.at(i).StopFrequencyW;
            data.M4_fAngles1 = m_GradientSet.at(i).AnglesUV;
            data.M4_fAngles2 = m_GradientSet.at(i).AnglesUW;
            data.M4_fAngles3 = m_GradientSet.at(i).AnglesVW;
            data.M4_fTime1 = m_GradientSet.at(i).StepTimeU;
            data.M4_fTime2 = m_GradientSet.at(i).StepTimeV;
            data.M4_fTime3 = m_GradientSet.at(i).StepTimeW;
            p_senddata.append(data);
            i++;
        }
    }
        break;
    case ENM_TESTMODE_THROUGH:
    {
        int i = 0;
        while(i < m_ThroughSet.count())
        {
            CanDataType data;
            data.M5_nWaveForm1 = m_ThroughSet.at(i).WaveFormU;
            data.M5_nWaveForm2 = m_ThroughSet.at(i).WaveFormV;
            data.M5_nWaveForm3 = m_ThroughSet.at(i).WaveFormW;
            data.M5_nDropPhase = m_ThroughSet.at(i).DropPhase;
            data.M5_nCycle1 = ui->cycleLE5->text().toInt();
            data.M5_fStartVoltage = m_ThroughSet.at(i).StartVoltage;
            data.M5_fStartFrequency = m_ThroughSet.at(i).StartFrequency;
            data.M5_fStartTime = m_ThroughSet.at(i).StartTime;
            data.M5_fAngles = m_ThroughSet.at(i).Angles;
            data.M5_fZeroVoltage = m_ThroughSet.at(i).ZeroVoltage;
            data.M5_fZeroTime = m_ThroughSet.at(i).ZeroTime;
            data.M5_fDropVoltage = m_ThroughSet.at(i).DropVoltage;
            data.M5_fDropTime = m_ThroughSet.at(i).DropTime;
            data.M5_fRecoveryVoltage = m_ThroughSet.at(i).RecoveryVoltage;
            data.M5_fRecoveryTime = m_ThroughSet.at(i).RecoveryTime;
            data.M5_fStopTime = m_ThroughSet.at(i).StopTime;
            p_senddata.append(data);
            i++;
        }
    }
        break;
    default:
        break;
    }
}

void GeneralDialog::initSendData(const int p_testmode, const int p_output, CanSendData &p_data)
{
    p_data.Cmd = ENM_CMD_SET;
    p_data.TestMode = p_testmode;
    p_data.OutputMode = p_output;
    p_data.TestData.clear();
    getSendData(p_testmode, p_data.TestData);
}

void GeneralDialog::initKeyBoard(const int p_x, const int p_y, const int p_width, const int p_height)
{
    if(m_KeyBoard == nullptr)
    {
        m_KeyBoard = new KeyboardForm();
        connect(m_KeyBoard, &KeyboardForm::sigKeyPressed,
            this, &GeneralDialog::slotKeyPressed);
    }
    m_KeyBoard->setPos(p_x, p_y, p_width, p_height);
}

void GeneralDialog::uninitKeyBoard()
{
    m_CurrentObj = nullptr;
    if(m_KeyBoard == nullptr)
        return;
    m_KeyBoard->hide();
    disconnect(m_KeyBoard, &KeyboardForm::sigKeyPressed,
            this, &GeneralDialog::slotKeyPressed);
    delete m_KeyBoard;
    m_KeyBoard = nullptr;
}

void GeneralDialog::updatePrintUI(const int p_outputmode)
{
    switch(p_outputmode)
    {
    case ENM_OUTPUT_THREEPHASE:
        ui->printWidget2->setVisible(true);
        ui->printWidget3->setVisible(true);
        ui->powerWidget->setVisible(true);
        ui->powerDetailWidget->setVisible(true);
        ui->detailValU3->clear();
        ui->detailValV3->clear();
        ui->detailValW3->clear();
        break;
    case ENM_OUTPUT_DISCRETE:
        ui->printWidget2->setVisible(true);
        ui->printWidget3->setVisible(true);
        ui->powerWidget->setVisible(false);
        //ui->powerDetailWidget->setVisible(false);
        ui->powerVal1->clear();
        ui->powerVal2->clear();
        ui->powerVal3->clear();
        break;
    case ENM_OUTPUT_IMBANLANCE:
        ui->printWidget2->setVisible(true);
        ui->printWidget3->setVisible(true);
        ui->powerWidget->setVisible(true);
        //ui->powerDetailWidget->setVisible(false);
        ui->powerVal1->clear();
        ui->powerVal2->clear();
        ui->powerVal3->clear();
        ui->detailValU3->clear();
        ui->detailValV3->clear();
        ui->detailValW3->clear();
        break;
    case ENM_OUTPUT_SINGLE:
        ui->printWidget2->setVisible(false);
        ui->printWidget3->setVisible(false);
        ui->powerWidget->setVisible(true);
        //ui->powerDetailWidget->setVisible(false);
        ui->powerVal1->clear();
        ui->powerVal2->clear();
        ui->powerVal3->clear();
        ui->detailValU3->clear();
        ui->detailValV3->clear();
        ui->detailValW3->clear();
        break;
    }
}

bool GeneralDialog::eventFilter(QObject *watched, QEvent *event)
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

void GeneralDialog::on_backBtn_clicked()
{
    emit sigResetLockTime();
    close();
}

void GeneralDialog::on_backBtn2_clicked()
{
    emit sigResetLockTime();
    close();
}

void GeneralDialog::on_backBtn3_clicked()
{
    emit sigResetLockTime();
    close();
}

void GeneralDialog::on_backBtn4_clicked()
{
    emit sigResetLockTime();
    close();
}

void GeneralDialog::on_backBtn5_clicked()
{
    emit sigResetLockTime();
    close();
}

void GeneralDialog::on_currentStepNoCB_activated(int index)
{
    dbOperation dbObj;
    m_GenralSet.StepNo = index + 1;
    dbObj.GeneralRead(m_GenralSet);
    ui->outputModeCB->setCurrentIndex(m_GenralSet.OutputMode);
    CanSendData sendData;
    initSendData(ENM_TESTMODE_GENERAL, index, sendData);
    emit sigSendData(sendData);
    emit sigResetLockTime();
}

void GeneralDialog::on_outputModeCB_activated(int index)
{
    if(m_GenralSet.OutputMode == index)
        return;
    m_CurrentOutputMode = index;
    m_GenralSet.OutputMode = index;
    updatePrintUI(index);
    dbOperation dbObj;
    dbObj.GeneralRead(m_GenralSet);
    CanSendData sendData;
    initSendData(ENM_TESTMODE_GENERAL, index, sendData);
    emit sigSendData(sendData);
    emit sigResetLockTime();
}

void GeneralDialog::on_voltageGearCB_activated(int index)
{
    m_GenralSet.VoltageLevel = index;
    emit sigResetLockTime();
}

void GeneralDialog::on_setDataBtn_clicked()
{
    GeneralSetDialog setObj(this);
    setObj.setData(m_GenralSet);
    if(setObj.exec() == QDialog::Accepted)
    {
        LogData logdata;
        logdata.TestMode = ENM_TESTMODE_GENERAL;
        logdata.OutputMode = ui->outputModeCB->currentIndex();
        logdata.OperationType = ENM_LOG_GENERAL_SAVE;
        logdata.Time = ui->timeLab->text();
        logdata.IGBT = m_IGBT;
        logdata.Transformer = m_Transformer;
        logdata.FanSpeed = m_FanSpeed;
        LogOperation::getLogInstance()->writeLog(logdata);
        m_GenralSet = setObj.getData();
        ui->currentStepNoCB->setCurrentIndex(m_GenralSet.StepNo - 1);
        CanSendData sendData;
        initSendData(ENM_TESTMODE_GENERAL, logdata.OutputMode, sendData);
        emit sigSendData(sendData);
    }
    emit sigResetLockTime();
}

void GeneralDialog::on_voltageSetLEU_editingFinished()
{
    emit sigResetLockTime();
}

void GeneralDialog::on_outputModeCB2_activated(int index)
{
    if(m_StepLadderSet.OutputMode == index)
        return;
    m_StepLadderSet.OutputMode = index;
    updatePrintUI(index);
    dbOperation dbObj;
    dbObj.StepLadderRead(m_StepLadderSet);
    CanSendData sendData;
    initSendData(ENM_TESTMODE_STEPLADDER, index, sendData);
    emit sigSendData(sendData);
    emit sigResetLockTime();
}

void GeneralDialog::on_setDataBtn2_clicked()
{
    StepLadderSetDialog setObj(this);
    setObj.setData(m_StepLadderSet);
    if(setObj.exec() == QDialog::Accepted)
    {
        LogData logdata;
        logdata.TestMode = ENM_TESTMODE_STEPLADDER;
        logdata.OutputMode = ui->outputModeCB->currentIndex();
        logdata.OperationType = ENM_LOG_STEPLADDER_SAVE;
        logdata.Time = ui->timeLab->text();
        logdata.IGBT = m_IGBT;
        logdata.Transformer = m_Transformer;
        logdata.FanSpeed = m_FanSpeed;
        LogOperation::getLogInstance()->writeLog(logdata);
        m_StepLadderSet = setObj.getData();
        CanSendData sendData;
        initSendData(ENM_TESTMODE_STEPLADDER, logdata.OutputMode, sendData);
        emit sigSendData(sendData);
    }
    emit sigResetLockTime();
}

void GeneralDialog::on_outputModeCB3_activated(int index)
{
    if(m_TestCtrl.OutputMode == index)
        return;
    m_TestCtrl.OutputMode = index;
    updatePrintUI(index);
    dbOperation dbObj;
    m_StepSet.clear();
    dbObj.StepRead(index, m_StepSet);
    CanSendData sendData;
    initSendData(ENM_TESTMODE_STEP, index, sendData);
    emit sigSendData(sendData);
    emit sigResetLockTime();
}

void GeneralDialog::on_setDataBtn3_clicked()
{
    StepSetDialog setObj(this);
    setObj.setData(m_TestCtrl, m_StepSet);
    if(setObj.exec() == QDialog::Accepted)
    {
        LogData logdata;
        logdata.TestMode = ENM_TESTMODE_STEP;
        logdata.OutputMode = ui->outputModeCB->currentIndex();
        logdata.OperationType = ENM_LOG_STEP_SAVE;
        logdata.Time = ui->timeLab->text();
        logdata.IGBT = m_IGBT;
        logdata.Transformer = m_Transformer;
        logdata.FanSpeed = m_FanSpeed;
        LogOperation::getLogInstance()->writeLog(logdata);
        setObj.getData(m_TestCtrl, m_StepSet);
        //emit sigSaveCtrlInfo(m_TestMode, m_TestCtrl);
        ui->startStepNoLE3->setText(QString::number(m_TestCtrl.StartNo));
        ui->stopStepNoLE3->setText(QString::number(m_TestCtrl.StopNo));
        ui->cycleLE3->setText(QString::number(m_TestCtrl.CycleTimes));
        CanSendData sendData;
        initSendData(ENM_TESTMODE_STEP, logdata.OutputMode, sendData);
        emit sigSendData(sendData);
    }
    emit sigResetLockTime();
}

void GeneralDialog::on_outputModeCB4_activated(int index)
{
    if(m_TestCtrl.OutputMode == index)
        return;
    m_TestCtrl.OutputMode = index;
    updatePrintUI(index);
    dbOperation dbObj;
    m_GradientSet.clear();
    dbObj.GradientRead(index, m_GradientSet);
    CanSendData sendData;
    initSendData(ENM_TESTMODE_GRADIENT, index, sendData);
    emit sigSendData(sendData);
    emit sigResetLockTime();
}

void GeneralDialog::on_setDataBtn4_clicked()
{
    GradientSetDialog gradientSet(this);
    gradientSet.setData(m_TestCtrl, m_GradientSet);
    if(gradientSet.exec() == QDialog::Accepted)
    {
        LogData logdata;
        logdata.TestMode = ENM_TESTMODE_GRADIENT;
        logdata.OutputMode = ui->outputModeCB->currentIndex();
        logdata.OperationType = ENM_LOG_GRADIENT_SAVE;
        logdata.Time = ui->timeLab->text();
        logdata.IGBT = m_IGBT;
        logdata.Transformer = m_Transformer;
        logdata.FanSpeed = m_FanSpeed;
        LogOperation::getLogInstance()->writeLog(logdata);
        gradientSet.getData(m_TestCtrl, m_GradientSet);
        //emit sigSaveCtrlInfo(m_TestMode, m_TestCtrl);
        ui->startStepNoLE4->setText(QString::number(m_TestCtrl.StartNo));
        ui->stopStepNoLE4->setText(QString::number(m_TestCtrl.StopNo));
        ui->cycleLE4->setText(QString::number(m_TestCtrl.CycleTimes));
        CanSendData sendData;
        initSendData(ENM_TESTMODE_GRADIENT, logdata.OutputMode, sendData);
        emit sigSendData(sendData);
    }
    emit sigResetLockTime();
}

void GeneralDialog::on_outputModeCB5_activated(int index)
{
    if(m_TestCtrl.OutputMode == index)
        return;
    m_TestCtrl.OutputMode = index;
    updatePrintUI(index);
    dbOperation dbObj;
    m_ThroughSet.clear();
    dbObj.ThroughRead(index, m_ThroughSet);
    CanSendData sendData;
    initSendData(ENM_TESTMODE_THROUGH, index, sendData);
    emit sigSendData(sendData);
    emit sigResetLockTime();
}

void GeneralDialog::on_setDataBtn5_clicked()
{
    ThroughSetDialog throughSetObj(this);
    throughSetObj.setData(m_ThroughSet, m_TestCtrl);
    if(throughSetObj.exec() == QDialog::Accepted)
    {
        LogData logdata;
        logdata.TestMode = ENM_TESTMODE_THROUGH;
        logdata.OutputMode = ui->outputModeCB->currentIndex();
        logdata.OperationType = ENM_LOG_THROUGH_SAVE;
        logdata.Time = ui->timeLab->text();
        logdata.IGBT = m_IGBT;
        logdata.Transformer = m_Transformer;
        logdata.FanSpeed = m_FanSpeed;
        LogOperation::getLogInstance()->writeLog(logdata);
        throughSetObj.getData(m_ThroughSet, m_TestCtrl);
        //emit sigSaveCtrlInfo(m_TestMode, m_TestCtrl);
        ui->startStepNoLE5->setText(QString::number(m_TestCtrl.StartNo));
        ui->stopStepNoLE5->setText(QString::number(m_TestCtrl.StopNo));
        ui->cycleLE5->setText(QString::number(m_TestCtrl.CycleTimes));
        CanSendData sendData;
        initSendData(ENM_TESTMODE_THROUGH, logdata.OutputMode, sendData);
        emit sigSendData(sendData);
    }
    emit sigResetLockTime();
}

void GeneralDialog::on_startBtn_clicked(bool checked)
{
    if(checked)
    {
        m_TestCtrl.StepNo = ui->currentStepNoCB->currentIndex() + 1;
        m_TestCtrl.OutputMode = ui->outputModeCB->currentIndex();
        emit sigSaveCtrlInfo(m_TestMode, m_TestCtrl);
    }
    startStopBtn();
}

void GeneralDialog::on_startBtn2_clicked(bool checked)
{
    if(checked)
    {
        m_TestCtrl.OutputMode = ui->outputModeCB2->currentIndex();
        emit sigSaveCtrlInfo(m_TestMode, m_TestCtrl);
    }
    startStopBtn();
}

void GeneralDialog::on_startBtn3_clicked(bool checked)
{
    if(checked)
    {
        m_TestCtrl.OutputMode = ui->outputModeCB3->currentIndex();
        emit sigSaveCtrlInfo(m_TestMode, m_TestCtrl);
    }
    startStopBtn();
}

void GeneralDialog::on_startBtn4_clicked(bool checked)
{
    if(checked)
    {
        m_TestCtrl.OutputMode = ui->outputModeCB4->currentIndex();
        emit sigSaveCtrlInfo(m_TestMode, m_TestCtrl);
    }
    startStopBtn();
}

void GeneralDialog::on_startBtn5_clicked(bool checked)
{
    if(checked)
    {
        m_TestCtrl.OutputMode = ui->outputModeCB5->currentIndex();
        emit sigSaveCtrlInfo(m_TestMode, m_TestCtrl);
    }
    startStopBtn();
}
