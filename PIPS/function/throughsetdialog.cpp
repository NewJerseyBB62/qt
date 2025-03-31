#include "throughsetdialog.h"
#include "ui_throughsetdialog.h"
#include "Data/dboperation.h"
#include <QMessageBox>
#include <QListView>
#include "Common/rtc.h"
#include "Common/lockmanager.h"
#include <QEvent>
#include <QKeyEvent>
#include <QCoreApplication>
#include "Common/warningdialog.h"

ThroughSetDialog::ThroughSetDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ThroughSetDialog),
    m_KeyBoard(nullptr),
    m_CurrentObj(nullptr)
{
    int i = 0;
    this->setGeometry(0, 0, 1280, 800);
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->setupUi(this);
    ui->stepNoCB->setView(new QListView(this));
    ui->harmonicsCBU->setView(new QListView(this));
    ui->harmonicsCBV->setView(new QListView(this));
    ui->harmonicsCBW->setView(new QListView(this));
    ui->phaseCB->setView(new QListView(this));
    ui->startStepNoLE->installEventFilter(this);
    ui->stopStepNoLE->installEventFilter(this);
    ui->cycleLE->installEventFilter(this);
    ui->voltageLE->installEventFilter(this);
    ui->freqLE->installEventFilter(this);
    ui->startTimeLE->installEventFilter(this);
    ui->crossAngleLE->installEventFilter(this);
    ui->zeroVoltageLE->installEventFilter(this);
    ui->zeroTimeLE->installEventFilter(this);
    ui->dropVoltageLE->installEventFilter(this);
    ui->dropTimeLE->installEventFilter(this);
    ui->RecoveryLE->installEventFilter(this);
    ui->stopTimeLE->installEventFilter(this);
    this->installEventFilter(this);
    m_KeyboardMap.insert(ui->startStepNoLE, i++);
    m_KeyboardMap.insert(ui->stopStepNoLE, i++);
    m_KeyboardMap.insert(ui->cycleLE, i++);
    m_KeyboardMap.insert(ui->voltageLE, i++);
    m_KeyboardMap.insert(ui->freqLE, i++);
    m_KeyboardMap.insert(ui->startTimeLE, i++);
    m_KeyboardMap.insert(ui->crossAngleLE, i++);
    m_KeyboardMap.insert(ui->zeroVoltageLE, i++);
    m_KeyboardMap.insert(ui->zeroTimeLE, i++);
    m_KeyboardMap.insert(ui->dropVoltageLE, i++);
    m_KeyboardMap.insert(ui->dropTimeLE, i++);
    m_KeyboardMap.insert(ui->RecoveryLE, i++);
    m_KeyboardMap.insert(ui->stopTimeLE, i++);
    connect(rtc::getRtcInstance(), &rtc::sigTimeChanged,
            this, &ThroughSetDialog::slotDateTime, Qt::QueuedConnection);
    connect(this, &ThroughSetDialog::sigResetLockTime,LockManager::getRtcInstance(),
            &LockManager::slotResetLockTime, Qt::QueuedConnection);
}

ThroughSetDialog::~ThroughSetDialog()
{
    disconnect(rtc::getRtcInstance(), &rtc::sigTimeChanged,
            this, &ThroughSetDialog::slotDateTime);
    disconnect(this, &ThroughSetDialog::sigResetLockTime,LockManager::getRtcInstance(),
            &LockManager::slotResetLockTime);
    delete ui;
}

void ThroughSetDialog::setData(const QList<ThroughData> &p_data, const TestCtrl &p_ctrl)
{
    m_Data = p_data;
    updateData();
}

void ThroughSetDialog::getData(QList<ThroughData> &p_data, TestCtrl &p_ctrl)
{
    p_data = m_Data;
    p_ctrl.StartNo = ui->startStepNoLE->text().toInt();
    p_ctrl.StopNo = ui->stopStepNoLE->text().toInt();
    p_ctrl.CycleTimes = ui->cycleLE->text().toInt();
}

void ThroughSetDialog::slotDateTime(const QString p_datetime)
{
    ui->timeLab->setText(p_datetime);
}

void ThroughSetDialog::slotKeyPressed(const int p_key)
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

void ThroughSetDialog::on_saveBtn_clicked()
{
    ui2Data();
    dbOperation dbObj;
    dbObj.ThroughWrite(m_Data);
    WarningDialog warning(this);
    warning.initWarning(tr("保存"), tr("保存成功"));
    warning.exec();
    //QMessageBox::information(this, tr("保存"), tr("保存成功"));
    emit sigResetLockTime();
    accept();
}

void ThroughSetDialog::on_backBtn_clicked()
{
    emit sigResetLockTime();
    reject();
    close();
}

void ThroughSetDialog::updateData()
{
    updateOutputMode(m_Data.at(0).OutputMode);
    ui->stepNoCB->setCurrentIndex(m_Data.at(0).StepNo - 1);
    ui->outputModeLE->setText(getOutputModeName(0, m_Data.at(0).OutputMode));
    data2Ui(m_Data.at(0));
}

void ThroughSetDialog::updateOutputMode(const int p_outputmode)
{
    switch(p_outputmode)
    {
    case ENM_OUTPUT_THREEPHASE:
        //ui->angleWidget->setVisible(false);
        break;
    case ENM_OUTPUT_SINGLE:
        ui->phaseCB->setEnabled(false);
        break;
    default:
        break;
    }
}

void ThroughSetDialog::data2Ui(const ThroughData &p_data)
{
    ui->stepNoCB->setCurrentIndex(p_data.StepNo - 1);
    ui->voltageLE->setValue(p_data.StartVoltage);
    ui->freqLE->setValue(p_data.StartFrequency);
    ui->startTimeLE->setValue(p_data.StartTime);
    ui->zeroVoltageLE->setValue(p_data.ZeroVoltage);
    ui->zeroTimeLE->setValue(p_data.ZeroTime);
    ui->dropVoltageLE->setValue(p_data.DropVoltage);
    ui->dropTimeLE->setValue(p_data.DropTime);
    ui->RecoveryLE->setValue(p_data.RecoveryVoltage);
    ui->stopTimeLE->setValue(p_data.StopTime);
    ui->crossAngleLE->setValue(p_data.Angles);
    if(p_data.OutputMode == ENM_OUTPUT_SINGLE)
    {
        ui->phaseCB->setEnabled(false);
        ui->harmonicsCBV->setEnabled(false);
        ui->harmonicsCBW->setEnabled(false);
    }
}

void ThroughSetDialog::ui2Data()
{
    int idx = ui->stepNoCB->currentIndex();
    m_Data[idx].StartVoltage = ui->voltageLE->text().toFloat();
    m_Data[idx].StartFrequency = ui->freqLE->text().toFloat();
    m_Data[idx].StartTime = ui->startTimeLE->text().toFloat();
    m_Data[idx].ZeroVoltage = ui->zeroVoltageLE->text().toFloat();
    m_Data[idx].ZeroTime = ui->zeroTimeLE->text().toFloat();
    m_Data[idx].DropVoltage = ui->dropVoltageLE->text().toFloat();
    m_Data[idx].DropTime = ui->dropTimeLE->text().toFloat();
    m_Data[idx].RecoveryVoltage = ui->RecoveryLE->text().toFloat();
    m_Data[idx].StopTime = ui->stopTimeLE->text().toFloat();
    m_Data[idx].Angles = ui->crossAngleLE->text().toFloat();
    m_Data[idx].Phase = ui->phaseCB->currentIndex();
    m_Data[idx].WaveFormU = ui->harmonicsCBU->currentIndex();
    m_Data[idx].WaveFormV = ui->harmonicsCBV->currentIndex();
    m_Data[idx].WaveFormW = ui->harmonicsCBW->currentIndex();
    m_Data[idx].StepNo = ui->stepNoCB->currentIndex() + 1;
}

void ThroughSetDialog::initKeyBoard(const int p_x, const int p_y, const int p_width, const int p_height)
{
    if(m_KeyBoard == nullptr)
    {
        m_KeyBoard = new KeyboardForm();
        connect(m_KeyBoard, &KeyboardForm::sigKeyPressed,
            this, &ThroughSetDialog::slotKeyPressed);
    }
    m_KeyBoard->setPos(p_x, p_y, p_width, p_height);
}

void ThroughSetDialog::uninitKeyBoard()
{
    m_CurrentObj = nullptr;
    if(m_KeyBoard == nullptr)
        return;
    m_KeyBoard->hide();
    disconnect(m_KeyBoard, &KeyboardForm::sigKeyPressed,
            this, &ThroughSetDialog::slotKeyPressed);
    delete m_KeyBoard;
    m_KeyBoard = nullptr;
}

bool ThroughSetDialog::eventFilter(QObject *watched, QEvent *event)
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


void ThroughSetDialog::on_stepNoCB_activated(int index)
{
    data2Ui(m_Data.at(index));
    emit sigResetLockTime();
}

void ThroughSetDialog::on_voltageLE_editingFinished()
{
    emit sigResetLockTime();
}

void ThroughSetDialog::on_freqLE_editingFinished()
{
    emit sigResetLockTime();
}

void ThroughSetDialog::on_startTimeLE_editingFinished()
{
    emit sigResetLockTime();
}
