#include "generalsetdialog.h"
#include "ui_generalsetdialog.h"
#include <QMessageBox>
#include "Data/dboperation.h"
#include <QListView>
#include "Common/rtc.h"
#include "Common/lockmanager.h"
#include <QDebug>
#include <QEvent>
#include <QKeyEvent>
#include <QCoreApplication>
#include "Common/warningdialog.h"

GeneralSetDialog::GeneralSetDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GeneralSetDialog),
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
    ui->voltageLEU->installEventFilter(this);
    ui->voltageLEV->installEventFilter(this);
    ui->voltageLEW->installEventFilter(this);
    ui->freqLEU->installEventFilter(this);
    ui->freqLEV->installEventFilter(this);
    ui->freqLEW->installEventFilter(this);
    ui->softTimeLEU->installEventFilter(this);
    ui->softTimeLEV->installEventFilter(this);
    ui->softTimeLEW->installEventFilter(this);
    ui->angleLE1->installEventFilter(this);
    ui->angleLE2->installEventFilter(this);
    ui->angleLE3->installEventFilter(this);
    this->installEventFilter(this);
    m_KeyboardMap.insert(ui->voltageLEU, i++);
    m_KeyboardMap.insert(ui->voltageLEV, i++);
    m_KeyboardMap.insert(ui->voltageLEW, i++);
    m_KeyboardMap.insert(ui->freqLEU, i++);
    m_KeyboardMap.insert(ui->freqLEV, i++);
    m_KeyboardMap.insert(ui->freqLEW, i++);
    m_KeyboardMap.insert(ui->softTimeLEU, i++);
    m_KeyboardMap.insert(ui->softTimeLEV, i++);
    m_KeyboardMap.insert(ui->softTimeLEW, i++);
    m_KeyboardMap.insert(ui->angleLE1, i++);
    m_KeyboardMap.insert(ui->angleLE2, i++);
    m_KeyboardMap.insert(ui->angleLE3, i++);
    connect(rtc::getRtcInstance(), &rtc::sigTimeChanged,
            this, &GeneralSetDialog::slotDateTime, Qt::QueuedConnection);
    connect(this, &GeneralSetDialog::sigResetLockTime,LockManager::getRtcInstance(),
            &LockManager::slotResetLockTime, Qt::QueuedConnection);
}

GeneralSetDialog::~GeneralSetDialog()
{
    uninitKeyBoard();
    disconnect(rtc::getRtcInstance(), &rtc::sigTimeChanged,
            this, &GeneralSetDialog::slotDateTime);
    disconnect(this, &GeneralSetDialog::sigResetLockTime,LockManager::getRtcInstance(),
            &LockManager::slotResetLockTime);
    delete ui;
}

void GeneralSetDialog::setData(const GeneralData &p_data)
{
    m_Data = p_data;
    updateData();
}

const GeneralData GeneralSetDialog::getData()
{
    return m_Data;
}

void GeneralSetDialog::updateData()
{
    updateOutputMode(m_Data.OutputMode);
    ui->stepNoCB->setCurrentIndex(m_Data.StepNo - 1);
    ui->outputModeLE->setText(getOutputModeName(0, m_Data.OutputMode));
    data2Ui(m_Data);
}

void GeneralSetDialog::updateOutputMode(const int p_outputmode)
{
    switch(p_outputmode)
    {
    case ENM_OUTPUT_THREEPHASE:
    case ENM_OUTPUT_SINGLE:
        ui->VWidget->setVisible(false);
        ui->WWidget->setVisible(false);
        ui->angleWidget->setVisible(false);
        break;
    case ENM_OUTPUT_DISCRETE:
        ui->angleWidget->setVisible(false);
        break;
    case ENM_OUTPUT_IMBANLANCE:
        //ui->angleWidget->setVisible(false);
        ui->freqLEV->setEnabled(false);
        ui->freqLEW->setEnabled(false);
        break;
    default:
        break;
    }
}

void GeneralSetDialog::data2Ui(const GeneralData &p_data)
{
    ui->voltageLEU->setValue(p_data.VoltageU);
    ui->freqLEU->setValue(p_data.FrequencyU);
    ui->harmonicsCBU->setCurrentIndex(p_data.WaveFormU);
    ui->softTimeLEU->setValue(p_data.StartTimeU);
    ui->Ucheck->setChecked(p_data.EnableU);
    if(p_data.OutputMode != ENM_OUTPUT_SINGLE)
    {
        ui->voltageLEV->setValue(p_data.VoltageV);
        ui->voltageLEW->setValue(p_data.VoltageW);
        ui->freqLEV->setValue(p_data.FrequencyV);
        ui->freqLEW->setValue(p_data.FrequencyW);
        ui->harmonicsCBV->setCurrentIndex(p_data.WaveFormV);
        ui->harmonicsCBW->setCurrentIndex(p_data.WaveFormW);
        ui->softTimeLEV->setValue(p_data.StartTimeV);
        ui->softTimeLEW->setValue(p_data.StartTimeW);
        ui->Vcheck->setChecked(p_data.EnableV);
        ui->Wcheck->setChecked(p_data.EnableW);
        if(p_data.OutputMode == ENM_OUTPUT_IMBANLANCE)
        {
            ui->angleLE1->setValue(p_data.AnglesUV);
            ui->angleLE2->setValue(p_data.AnglesUW);
            ui->angleLE3->setValue(p_data.AnglesVW);
        }
    }
}

void GeneralSetDialog::ui2Data(GeneralData &p_data)
{
    p_data.VoltageU = ui->voltageLEU->text().toFloat();
    p_data.FrequencyU = ui->freqLEU->text().toFloat();
    p_data.WaveFormU = ui->harmonicsCBU->currentIndex();
    p_data.StartTimeU = ui->softTimeLEU->text().toFloat();
    p_data.EnableU = ui->Ucheck->isChecked() ? 1 : 0;
    if(p_data.OutputMode != ENM_OUTPUT_SINGLE)
    {
        p_data.VoltageV = ui->voltageLEV->text().toFloat();
        p_data.FrequencyV = ui->freqLEV->text().toFloat();
        p_data.WaveFormV = ui->harmonicsCBV->currentIndex();
        p_data.StartTimeV = ui->softTimeLEV->text().toFloat();
        p_data.EnableV = ui->Vcheck->isChecked() ? 1 : 0;
        p_data.VoltageW = ui->voltageLEW->text().toFloat();
        p_data.FrequencyW = ui->freqLEW->text().toFloat();
        p_data.WaveFormW = ui->harmonicsCBW->currentIndex();
        p_data.StartTimeW = ui->softTimeLEW->text().toFloat();
        p_data.EnableW = ui->Wcheck->isChecked() ? 1 : 0;
        if(p_data.OutputMode == ENM_OUTPUT_IMBANLANCE)
        {
            p_data.AnglesUV = ui->angleLE1->text().toFloat();
            p_data.AnglesUW = ui->angleLE2->text().toFloat();
            p_data.AnglesVW = ui->angleLE3->text().toFloat();
        }
    }
}

void GeneralSetDialog::initKeyBoard(const int p_x, const int p_y, const int p_width, const int p_height)
{
    if(m_KeyBoard == nullptr)
    {
        m_KeyBoard = new KeyboardForm();
        connect(m_KeyBoard, &KeyboardForm::sigKeyPressed,
            this, &GeneralSetDialog::slotKeyPressed);
    }
    m_KeyBoard->setPos(p_x, p_y, p_width, p_height);
}

void GeneralSetDialog::uninitKeyBoard()
{
    m_CurrentObj = nullptr;
    if(m_KeyBoard == nullptr)
        return;
    m_KeyBoard->hide();
    disconnect(m_KeyBoard, &KeyboardForm::sigKeyPressed,
            this, &GeneralSetDialog::slotKeyPressed);
    delete m_KeyBoard;
    m_KeyBoard = nullptr;
}

bool GeneralSetDialog::eventFilter(QObject *watched, QEvent *event)
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

void GeneralSetDialog::slotDateTime(const QString p_datetime)
{
    ui->timeLab->setText(p_datetime);
}

void GeneralSetDialog::slotKeyPressed(const int p_key)
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

void GeneralSetDialog::on_saveBtn_clicked()
{
    ui2Data(m_Data);
    dbOperation dbObj;
    dbObj.GeneralWrite(m_Data);
    WarningDialog warning(this);
    warning.initWarning(tr("保存"), tr("保存成功"));
    warning.exec();
    //QMessageBox::information(this, tr("保存"), tr("保存成功"));
    emit sigResetLockTime();
    accept();
}

void GeneralSetDialog::on_backBtn_clicked()
{
    emit sigResetLockTime();
    reject();
    close();
}

void GeneralSetDialog::on_stepNoCB_activated(int index)
{
    dbOperation dbObj;
    m_Data.StepNo = index + 1;
    dbObj.GeneralRead(m_Data);
    data2Ui(m_Data);
    emit sigResetLockTime();
}

void GeneralSetDialog::on_voltageLEU_editingFinished()
{
    emit sigResetLockTime();
}

void GeneralSetDialog::on_freqLEU_editingFinished()
{
    emit sigResetLockTime();
}

void GeneralSetDialog::on_harmonicsCBU_activated(int index)
{
    emit sigResetLockTime();
}

void GeneralSetDialog::on_softTimeLEU_editingFinished()
{
    emit sigResetLockTime();
}
