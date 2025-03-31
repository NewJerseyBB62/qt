#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Data/dboperation.h"
#include "Data/jsonopration.h"
#include "function/systemsetdialog.h"
#include "function/generaldialog.h"
#include "Common/rtc.h"
#include <QDebug>
#include "Common/lockmanager.h"
#include "communication/communication.h"
#include "Common/warninglight.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setWindowFlags(Qt::FramelessWindowHint);
    //this->showFullScreen();
    ui->setupUi(this);
    qRegisterMetaType<CanSendData>("CanSendData");
    ui->generalBtn->installEventFilter(this);
    ui->stepLadderBtn->installEventFilter(this);
    ui->stepBtn->installEventFilter(this);
    ui->gradientBtn->installEventFilter(this);
    ui->throughBtn->installEventFilter(this);
    ui->setBtn->installEventFilter(this);
    ui->centralWidget->installEventFilter(this);
    rtc::getRtcInstance();
    connect(rtc::getRtcInstance(), &rtc::sigTimeChanged,
            this, &MainWindow::slotDateTime, Qt::QueuedConnection);
}

MainWindow::~MainWindow()
{
    disconnect(rtc::getRtcInstance(), &rtc::sigTimeChanged,
            this, &MainWindow::slotDateTime);
    rtc::closeRtcInstance();
    WriteThread::getWriteThread()->uninitWriteThread();
    WriteThread::closeWriteThread();
    ReadThread::getReadThread()->uninitReadThread();
    ReadThread::closeReadThread();
    delete ui;
}

void MainWindow::readConfig()
{
    JsonOpration jsonObj;
    jsonObj.ReadJson(m_Config);
    dbOperation DBtest;
    DBtest.initDB();
    connect(this, &MainWindow::sigResetLockTime,LockManager::getRtcInstance(),
            &LockManager::slotResetLockTime, Qt::QueuedConnection);
    LockManager::getRtcInstance()->setParent(this);
    if(m_Config.LockCheck)
    {
        LockManager::getRtcInstance()->updateTestStatus(false);
        LockManager::getRtcInstance()->updateLockTime(m_Config.LockTime);
        LockManager::getRtcInstance()->updateLockPwd(m_Config.LockPwd);
        LockManager::getRtcInstance()->startLockThread();
    }
    WarningLight warnLight;
    warnLight.startLight(ENM_LIGHT_GREEN);
}

void MainWindow::setHarmonics()
{
    WriteThread::getWriteThread();
    ReadThread::getReadThread();
    connect(this, &MainWindow::sigSendData, WriteThread::getWriteThread(),
            &WriteThread::slotSendTestData, Qt::QueuedConnection);
    WriteThread::getWriteThread()->StartThread();
    ReadThread::getReadThread()->StartThread();
    dbOperation dbObj;
    CanSendData sendData;
    sendData.Cmd = ENM_CMD_HARMONICSSET;
    dbObj.HarmonicsReadAll(sendData.AllHarmonics);
    emit sigSendData(sendData);
    disconnect(this, &MainWindow::sigSendData, WriteThread::getWriteThread(),
            &WriteThread::slotSendTestData);
}

void MainWindow::slotSaveCtrlInfo(const int p_testmode, const TestCtrl &p_ctrl)
{
    switch(p_testmode)
    {
    case ENM_TESTMODE_GENERAL:
        m_Config.GeneralStep = p_ctrl.StepNo;
        m_Config.GeneralOutputMode = p_ctrl.OutputMode;
        break;
    case ENM_TESTMODE_STEPLADDER:
        m_Config.StepLadderOutputMode = p_ctrl.OutputMode;
        break;
    case ENM_TESTMODE_STEP:
        m_Config.StepStartNo = p_ctrl.StartNo;
        m_Config.StepStopNo = p_ctrl.StopNo;
        m_Config.StepCycleTimes = p_ctrl.CycleTimes;
        break;
    case ENM_TESTMODE_GRADIENT:
        m_Config.GradientStartNo = p_ctrl.StartNo;
        m_Config.GradientStopNo = p_ctrl.StopNo;
        m_Config.GradientCycleTimes = p_ctrl.CycleTimes;
        break;
    case ENM_TESTMODE_THROUGH:
        m_Config.ThroughStartNo = p_ctrl.StartNo;
        m_Config.ThroughStopNo = p_ctrl.StopNo;
        m_Config.ThroughCycleTimes = p_ctrl.CycleTimes;
        break;
    default:
        return;
    }
    JsonOpration jsonObj;
    jsonObj.WriteJson(m_Config);
}

void MainWindow::slotDateTime(const QString p_datetime)
{
    ui->timeLab->setText(p_datetime);
}

void MainWindow::on_setBtn_clicked()
{
    SystemSetDialog setObj(this);
    setObj.initSetting(m_Config);
    if(setObj.exec() == QDialog::Accepted)
    {
        JsonOpration jsonObj;
        setObj.getSetting(m_Config);
        jsonObj.WriteJson(m_Config);

    }
    if(m_Config.LockCheck)
    {
        LockManager::getRtcInstance()->updateTestStatus(false);
        LockManager::getRtcInstance()->updateLockTime(m_Config.LockTime);
        LockManager::getRtcInstance()->updateLockPwd(m_Config.LockPwd);
        if(LockManager::getRtcInstance()->getThreadStatus())
            LockManager::getRtcInstance()->startLockThread();
    }
    else
    {
        if(!LockManager::getRtcInstance()->getThreadStatus())
            LockManager::getRtcInstance()->stopLockThread();
    }
    return;
}

void MainWindow::on_generalBtn_clicked()
{
    GeneralData general;
    GeneralDialog testObj(this);
    dbOperation dbObj;
    TestCtrl ctrlData;
    general.StepNo = m_Config.GeneralStep;
    general.OutputMode = m_Config.GeneralOutputMode;
    if(dbObj.GeneralRead(general) != 0)
    {

    }
    testObj.initTestMode(ENM_TESTMODE_GENERAL);
    testObj.setGeneral(general);
    testObj.exec();
    testObj.setCtrlInfo(ENM_TESTMODE_GENERAL, ctrlData);
    slotSaveCtrlInfo(ENM_TESTMODE_GENERAL, ctrlData);
}

void MainWindow::on_stepLadderBtn_clicked()
{
    StepLadderData stepLadder;
    GeneralDialog testObj(this);
    dbOperation dbObj;
    TestCtrl ctrlData;
    stepLadder.OutputMode = m_Config.StepLadderOutputMode;
    if(dbObj.StepLadderRead(stepLadder) != 0)
    {

    }
    testObj.initTestMode(ENM_TESTMODE_STEPLADDER);
    testObj.setStepLadder(stepLadder);
    testObj.exec();
    testObj.setCtrlInfo(ENM_TESTMODE_STEPLADDER, ctrlData);
    slotSaveCtrlInfo(ENM_TESTMODE_STEPLADDER, ctrlData);
}

void MainWindow::on_stepBtn_clicked()
{
    GeneralDialog testObj(this);
    QList<StepData> step;
    dbOperation dbObj;
    TestCtrl ctrlData;
    if(dbObj.StepRead(m_Config.StepOutputMode, step) != 0)
    {

    }
    testObj.initTestMode(ENM_TESTMODE_STEP);
    testObj.getCtrlInfo(m_Config);
    testObj.setStep(step);
    testObj.exec();
    testObj.setCtrlInfo(ENM_TESTMODE_STEP, ctrlData);
    slotSaveCtrlInfo(ENM_TESTMODE_STEP, ctrlData);
}

void MainWindow::on_gradientBtn_clicked()
{
    GeneralDialog testObj(this);
    QList<GradientData> gradient;
    dbOperation dbObj;
    TestCtrl ctrlData;
    if(dbObj.GradientRead(m_Config.StepOutputMode, gradient) != 0)
    {

    }
    testObj.initTestMode(ENM_TESTMODE_GRADIENT);
    testObj.getCtrlInfo(m_Config);
    testObj.setGradient(gradient);
    testObj.exec();
    testObj.setCtrlInfo(ENM_TESTMODE_GRADIENT, ctrlData);
    slotSaveCtrlInfo(ENM_TESTMODE_GRADIENT, ctrlData);
}

void MainWindow::on_throughBtn_clicked()
{
    QList<ThroughData> throughData;
    GeneralDialog testObj(this);
    dbOperation dbObj;
    TestCtrl ctrlData;
    if(dbObj.ThroughRead(m_Config.ThroughOutputMode, throughData) != 0)
    {

    }
    testObj.initTestMode(ENM_TESTMODE_THROUGH);
    testObj.getCtrlInfo(m_Config);
    testObj.setThrough(throughData);
    testObj.exec();
    testObj.setCtrlInfo(ENM_TESTMODE_THROUGH, ctrlData);
    slotSaveCtrlInfo(ENM_TESTMODE_THROUGH, ctrlData);
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress)
    {
        if(obj->objectName().contains("generalBtn"))
        {
            changeQSS(true, ENM_TESTMODE_GENERAL);
        }
        else if(obj->objectName().contains("stepLadderBtn"))
        {
            changeQSS(true, ENM_TESTMODE_STEPLADDER);
        }
        else if(obj->objectName().contains("stepBtn"))
        {
            changeQSS(true, ENM_TESTMODE_STEP);
        }
        else if(obj->objectName().contains("gradientBtn"))
        {
            changeQSS(true, ENM_TESTMODE_GRADIENT);
        }
        else if(obj->objectName().contains("throughBtn"))
        {
            changeQSS(true, ENM_TESTMODE_THROUGH);
        }
        else if(obj->objectName().contains("setBtn"))
        {
            changeQSS(true, 5);
        }
    }
    else if (event->type() == QEvent::MouseButtonRelease)
    {
        emit sigResetLockTime();
        if(obj->objectName().contains("generalBtn"))
        {
            changeQSS(false, ENM_TESTMODE_GENERAL);
            on_generalBtn_clicked();
        }
        else if(obj->objectName().contains("stepLadderBtn"))
        {
            changeQSS(false, ENM_TESTMODE_STEPLADDER);
            on_stepLadderBtn_clicked();
        }
        else if(obj->objectName().contains("stepBtn"))
        {
            changeQSS(false, ENM_TESTMODE_STEP);
            on_stepBtn_clicked();
        }
        else if(obj->objectName().contains("gradientBtn"))
        {
            changeQSS(false, ENM_TESTMODE_GRADIENT);
            on_gradientBtn_clicked();
        }
        else if(obj->objectName().contains("throughBtn"))
        {
            changeQSS(false, ENM_TESTMODE_THROUGH);
            on_throughBtn_clicked();
        }
        else if(obj->objectName().contains("setBtn"))
        {
            changeQSS(false, 5);
            on_setBtn_clicked();
        }
    }
    return false;
}

void MainWindow::changeQSS(const bool pressed, const int p_type)
{
    QString qss1;
    switch(p_type)
    {
    case ENM_TESTMODE_GENERAL:
        if(pressed)
        {
            qss1 = QString("#generalBtn{border-image: url(:/png/main/btn_selected.png);}"
                        "#generalIcon{border-image: url(:/png/main/icon_general_selected.png);}"
                        "QLabel{color: rgb(240, 240, 240);font: 600 22pt \"Ubuntu\";}");
        }
        else
        {
            qss1 = QString("#generalBtn{border-image: url(:/png/main/btn.png);}"
                        "#generalIcon{border-image: url(:/png/main/icon_general.png);}"
                        "QLabel{color: rgb(26, 95, 180);font: 600 22pt \"Ubuntu\";}");
        }
        ui->generalBtn->setStyleSheet(qss1);
        break;
    case ENM_TESTMODE_STEPLADDER:
        if(pressed)
        {
            qss1 = QString("#stepLadderBtn{border-image: url(:/png/main/btn_selected.png);}"
                        "#stepLadderIcon{border-image: url(:/png/main/icon_stepladder_selected.png);}"
                        "QLabel{color: rgb(240, 240, 240);font: 600 22pt \"Ubuntu\";}");
        }
        else
        {
            qss1 = QString("#stepLadderBtn{border-image: url(:/png/main/btn.png);}"
                        "#stepLadderIcon{border-image: url(:/png/main/icon_stepladder.png);}"
                        "QLabel{color: rgb(26, 95, 180);font: 600 22pt \"Ubuntu\";}");
        }
        ui->stepLadderBtn->setStyleSheet(qss1);
        break;
    case ENM_TESTMODE_STEP:
        if(pressed)
        {
            qss1 = QString("#stepBtn{border-image: url(:/png/main/btn_selected.png);}"
                        "#stepIcon{border-image: url(:/png/main/icon_step_selected.png);}"
                        "QLabel{color: rgb(240, 240, 240);font: 600 22pt \"Ubuntu\";}");
        }
        else
        {
            qss1 = QString("#stepBtn{border-image: url(:/png/main/btn.png);}"
                        "#stepIcon{border-image: url(:/png/main/icon_step.png);}"
                        "QLabel{color: rgb(26, 95, 180);font: 600 22pt \"Ubuntu\";}");
        }
        ui->stepBtn->setStyleSheet(qss1);
        break;
    case ENM_TESTMODE_GRADIENT:
        if(pressed)
        {
            qss1 = QString("#gradientBtn{border-image: url(:/png/main/btn_selected.png);}"
                        "#gradientIcon{border-image: url(:/png/main/icon_gradient_selected.png);}"
                        "QLabel{color: rgb(240, 240, 240);font: 600 22pt \"Ubuntu\";}");
        }
        else
        {
            qss1 = QString("#gradientBtn{border-image: url(:/png/main/btn.png);}"
                        "#gradientIcon{border-image: url(:/png/main/icon_gradient.png);}"
                        "QLabel{color: rgb(26, 95, 180);font: 600 22pt \"Ubuntu\";}");
        }
        ui->gradientBtn->setStyleSheet(qss1);
        break;
    case ENM_TESTMODE_THROUGH:
        if(pressed)
        {
            qss1 = QString("#throughBtn{border-image: url(:/png/main/btn_selected.png);}"
                        "#throughIcon{border-image: url(:/png/main/icon_cross_selected.png);}"
                        "QLabel{color: rgb(240, 240, 240);font: 600 22pt \"Ubuntu\";}");
        }
        else
        {
            qss1 = QString("#throughBtn{border-image: url(:/png/main/btn.png);}"
                        "#throughIcon{border-image: url(:/png/main/icon_cross.png);}"
                        "QLabel{color: rgb(26, 95, 180);font: 600 22pt \"Ubuntu\";}");
        }
        ui->throughBtn->setStyleSheet(qss1);
        break;
    case 5:
        if(pressed)
        {
            qss1 = QString("#setBtn{border-image: url(:/png/main/btn_selected.png);}"
                        "#setIcon{border-image: url(:/png/main/icon_set_selected.png);}"
                        "QLabel{color: rgb(240, 240, 240);font: 600 22pt \"Ubuntu\";}");
        }
        else
        {
            qss1 = QString("#setBtn{border-image: url(:/png/main/btn.png);}"
                        "#setIcon{border-image: url(:/png/main/icon_set.png);}"
                        "QLabel{color: rgb(26, 95, 180);font: 600 22pt \"Ubuntu\";}");
        }
        ui->setBtn->setStyleSheet(qss1);
        break;
    default:
        break;
    }
}
