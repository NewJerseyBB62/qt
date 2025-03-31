#include "stepladdersetdialog.h"
#include "ui_stepladdersetdialog.h"
#include "Data/dboperation.h"
#include <QMessageBox>
#include <QListView>
#include "Common/rtc.h"
#include "Common/lockmanager.h"
#include <QEvent>
#include <QKeyEvent>
#include <QCoreApplication>
#include "Common/warningdialog.h"

StepLadderSetDialog::StepLadderSetDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StepLadderSetDialog),
    m_KeyBoard(nullptr),
    m_CurrentObj(nullptr)
{
    int i = 0;
    this->setGeometry(0, 0, 1280, 800);
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->setupUi(this);
    ui->harmonicsCBU->setView(new QListView(this));
    ui->harmonicsCBV->setView(new QListView(this));
    ui->harmonicsCBW->setView(new QListView(this));
    ui->voltageStartLEU->installEventFilter(this);
    ui->voltageStartLEV->installEventFilter(this);
    ui->voltageStartLEW->installEventFilter(this);
    ui->voltageStepLEU->installEventFilter(this);
    ui->voltageStepLEV->installEventFilter(this);
    ui->voltageStepLEW->installEventFilter(this);
    ui->freqStartLEU->installEventFilter(this);
    ui->freqStartLEV->installEventFilter(this);
    ui->freqStartLEW->installEventFilter(this);
    ui->freqStepLEU->installEventFilter(this);
    ui->freqStepLEV->installEventFilter(this);
    ui->freqStepLEW->installEventFilter(this);
    ui->timeLEU->installEventFilter(this);
    ui->timeLEV->installEventFilter(this);
    ui->timeLEW->installEventFilter(this);
    ui->angleLE1->installEventFilter(this);
    ui->angleLE2->installEventFilter(this);
    ui->angleLE3->installEventFilter(this);
    this->installEventFilter(this);
    m_KeyboardMap.insert(ui->voltageStartLEU, i++);
    m_KeyboardMap.insert(ui->voltageStartLEV, i++);
    m_KeyboardMap.insert(ui->voltageStartLEW, i++);
    m_KeyboardMap.insert(ui->voltageStepLEU, i++);
    m_KeyboardMap.insert(ui->voltageStepLEV, i++);
    m_KeyboardMap.insert(ui->voltageStepLEW, i++);
    m_KeyboardMap.insert(ui->freqStartLEU, i++);
    m_KeyboardMap.insert(ui->freqStartLEV, i++);
    m_KeyboardMap.insert(ui->freqStartLEW, i++);
    m_KeyboardMap.insert(ui->freqStepLEU, i++);
    m_KeyboardMap.insert(ui->freqStepLEV, i++);
    m_KeyboardMap.insert(ui->freqStepLEW, i++);
    m_KeyboardMap.insert(ui->timeLEU, i++);
    m_KeyboardMap.insert(ui->timeLEV, i++);
    m_KeyboardMap.insert(ui->timeLEW, i++);
    m_KeyboardMap.insert(ui->angleLE1, i++);
    m_KeyboardMap.insert(ui->angleLE2, i++);
    m_KeyboardMap.insert(ui->angleLE3, i++);
    connect(rtc::getRtcInstance(), &rtc::sigTimeChanged,
            this, &StepLadderSetDialog::slotDateTime, Qt::QueuedConnection);
    connect(this, &StepLadderSetDialog::sigResetLockTime,LockManager::getRtcInstance(),
            &LockManager::slotResetLockTime, Qt::QueuedConnection);
}

StepLadderSetDialog::~StepLadderSetDialog()
{
    disconnect(rtc::getRtcInstance(), &rtc::sigTimeChanged,
            this, &StepLadderSetDialog::slotDateTime);
    disconnect(this, &StepLadderSetDialog::sigResetLockTime,LockManager::getRtcInstance(),
            &LockManager::slotResetLockTime);
    delete ui;
}

void StepLadderSetDialog::setData(const StepLadderData &p_data)
{
    m_Data = p_data;
    updateData();
}

const StepLadderData StepLadderSetDialog::getData()
{
    return m_Data;
}

void StepLadderSetDialog::updateData()
{
    updateOutputMode(m_Data.OutputMode);
    //ui->stepNoCB->setCurrentIndex(m_Data.StepNo - 1);
    ui->outputModeLE->setText(getOutputModeName(0, m_Data.OutputMode));
    data2Ui(m_Data);
}

void StepLadderSetDialog::updateOutputMode(const int p_outputmode)
{
    switch(p_outputmode)
    {
    case ENM_OUTPUT_DISCRETE:
        ui->angleWidget->setVisible(false);
        break;
    case ENM_OUTPUT_IMBANLANCE:
        ui->freqStartLabV->setVisible(false);
        ui->freqStartLEV->setVisible(false);
        ui->freqStartLabW->setVisible(false);
        ui->freqStartLEW->setVisible(false);
        ui->timeLabV->setVisible(false);
        ui->timeLabW->setVisible(false);
        ui->timeLEV->setVisible(false);
        ui->timeLEW->setVisible(false);
        //ui->angleWidget->setVisible(false);
        break;
    case ENM_OUTPUT_THREEPHASE:
    case ENM_OUTPUT_SINGLE:
        ui->voltageStartLabV->setVisible(false);
        ui->voltageStartLEV->setVisible(false);
        ui->voltageStartLabW->setVisible(false);
        ui->voltageStartLEW->setVisible(false);
        ui->freqStartLabV->setVisible(false);
        ui->freqStartLEV->setVisible(false);
        ui->freqStartLabW->setVisible(false);
        ui->freqStartLEW->setVisible(false);
        ui->voltageStepLabV->setVisible(false);
        ui->voltageStepLEV->setVisible(false);
        ui->voltageStepLabW->setVisible(false);
        ui->voltageStepLEW->setVisible(false);
        ui->freqStepLabV->setVisible(false);
        ui->freqStepLEV->setVisible(false);
        ui->freqStepLabW->setVisible(false);
        ui->freqStepLEW->setVisible(false);
        ui->harmonicsLEV->setVisible(false);
        ui->harmonicsLEW->setVisible(false);
        ui->harmonicsCBV->setVisible(false);
        ui->harmonicsCBW->setVisible(false);
        ui->timeLabV->setVisible(false);
        ui->timeLabW->setVisible(false);
        ui->timeLEV->setVisible(false);
        ui->timeLEW->setVisible(false);
        ui->angleWidget->setVisible(false);
        break;
    default:
        break;
    }
}

void StepLadderSetDialog::data2Ui(const StepLadderData &p_data)
{
    ui->voltageStartLEU->setValue(p_data.StartVoltageU);
    ui->voltageStartLEV->setValue(p_data.StartVoltageV);
    ui->voltageStartLEW->setValue(p_data.StartVoltageW);
    ui->freqStartLEU->setValue(p_data.StartFrequencyU);
    ui->freqStartLEV->setValue(p_data.StartFrequencyV);
    ui->freqStartLEW->setValue(p_data.StartFrequencyW);
    ui->voltageStepLEU->setValue(p_data.StepVoltageU);
    ui->voltageStepLEV->setValue(p_data.StepVoltageV);
    ui->voltageStepLEW->setValue(p_data.StepVoltageW);
    ui->freqStepLEU->setValue(p_data.StepFrequencyU);
    ui->freqStepLEV->setValue(p_data.StepFrequencyV);
    ui->freqStepLEW->setValue(p_data.StepFrequencyW);
    ui->harmonicsCBU->setCurrentIndex(p_data.WaveFormU);
    ui->harmonicsCBV->setCurrentIndex(p_data.WaveFormV);
    ui->harmonicsCBW->setCurrentIndex(p_data.WaveFormW);
    ui->timeLEU->setValue(p_data.StepTimeU);
    ui->timeLEV->setValue(p_data.StepTimeV);
    ui->timeLEW->setValue(p_data.StepTimeW);
    ui->angleLE1->setValue(p_data.AnglesUV);
    ui->angleLE2->setValue(p_data.AnglesUW);
    ui->angleLE3->setValue(p_data.AnglesVW);
}

void StepLadderSetDialog::ui2Data(StepLadderData &p_data)
{
    p_data.StartVoltageU = ui->voltageStartLEU->text().toFloat();
    p_data.StartVoltageV = ui->voltageStartLEV->text().toFloat();
    p_data.StartVoltageW = ui->voltageStartLEW->text().toFloat();
    p_data.StartFrequencyU = ui->freqStartLEU->text().toFloat();
    p_data.StartFrequencyV = ui->freqStartLEV->text().toFloat();
    p_data.StartFrequencyW = ui->freqStartLEW->text().toFloat();
    p_data.StepVoltageU = ui->voltageStepLEU->text().toFloat();
    p_data.StepVoltageV = ui->voltageStepLEV->text().toFloat();
    p_data.StepVoltageW = ui->voltageStepLEW->text().toFloat();
    p_data.StepFrequencyU = ui->freqStepLEU->text().toFloat();
    p_data.StepFrequencyV = ui->freqStepLEV->text().toFloat();
    p_data.StepFrequencyW = ui->freqStepLEW->text().toFloat();
    p_data.WaveFormU = ui->harmonicsCBU->currentIndex();
    p_data.WaveFormV = ui->harmonicsCBV->currentIndex();
    p_data.WaveFormW = ui->harmonicsCBW->currentIndex();
    p_data.StepTimeU = ui->timeLEU->text().toFloat();
    p_data.StepTimeV = ui->timeLEV->text().toFloat();
    p_data.StepTimeW = ui->timeLEW->text().toFloat();
    p_data.AnglesUV = ui->angleLE1->text().toFloat();
    p_data.AnglesUW = ui->angleLE2->text().toFloat();
    p_data.AnglesVW = ui->angleLE3->text().toFloat();
}

void StepLadderSetDialog::initKeyBoard(const int p_x, const int p_y, const int p_width, const int p_height)
{
    if(m_KeyBoard == nullptr)
    {
        m_KeyBoard = new KeyboardForm();
        connect(m_KeyBoard, &KeyboardForm::sigKeyPressed,
            this, &StepLadderSetDialog::slotKeyPressed);
    }
    m_KeyBoard->setPos(p_x, p_y, p_width, p_height);
}

void StepLadderSetDialog::uninitKeyBoard()
{
    m_CurrentObj = nullptr;
    if(m_KeyBoard == nullptr)
        return;
    m_KeyBoard->hide();
    disconnect(m_KeyBoard, &KeyboardForm::sigKeyPressed,
            this, &StepLadderSetDialog::slotKeyPressed);
    delete m_KeyBoard;
    m_KeyBoard = nullptr;
}

bool StepLadderSetDialog::eventFilter(QObject *watched, QEvent *event)
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

void StepLadderSetDialog::slotDateTime(const QString p_datetime)
{
    ui->timeLab->setText(p_datetime);
}

void StepLadderSetDialog::slotKeyPressed(const int p_key)
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

void StepLadderSetDialog::on_saveBtn_clicked()
{
    ui2Data(m_Data);
    dbOperation dbObj;
    dbObj.StepLadderWrite(m_Data);
    WarningDialog warning(this);
    warning.initWarning(tr("保存"), tr("保存成功"));
    warning.exec();
    //QMessageBox::information(this, tr("保存"), tr("保存成功"));
    emit sigResetLockTime();
    accept();
}

void StepLadderSetDialog::on_backBtn_clicked()
{
    emit sigResetLockTime();
    reject();
    close();
}

void StepLadderSetDialog::on_voltageStartLEU_editingFinished()
{
    emit sigResetLockTime();
}

void StepLadderSetDialog::on_voltageStepLEU_editingFinished()
{
    emit sigResetLockTime();
}

void StepLadderSetDialog::on_freqStartLEU_editingFinished()
{
    emit sigResetLockTime();
}

void StepLadderSetDialog::on_freqStepLEU_editingFinished()
{
    emit sigResetLockTime();
}

void StepLadderSetDialog::on_harmonicsCBU_activated(int index)
{
    emit sigResetLockTime();
}

void StepLadderSetDialog::on_timeLEU_editingFinished()
{
    emit sigResetLockTime();
}

void StepLadderSetDialog::on_angleLE1_editingFinished()
{
    emit sigResetLockTime();
}
