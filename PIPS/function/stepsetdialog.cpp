#include "stepsetdialog.h"
#include "ui_stepsetdialog.h"
#include "Data/dboperation.h"
#include <QMessageBox>
#include <QDebug>
#include <QListView>
#include "Common/rtc.h"
#include "Common/lockmanager.h"
#include <QEvent>
#include <QKeyEvent>
#include <QCoreApplication>
#include "Common/warningdialog.h"

StepSetDialog::StepSetDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StepSetDialog),
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
    ui->startStepNoLE->installEventFilter(this);
    ui->stopStepNoLE->installEventFilter(this);
    ui->cycleLE->installEventFilter(this);
    ui->jumpLE->installEventFilter(this);
    ui->voltageLEU->installEventFilter(this);
    ui->voltageLEV->installEventFilter(this);
    ui->voltageLEW->installEventFilter(this);
    ui->freqLEU->installEventFilter(this);
    ui->freqLEV->installEventFilter(this);
    ui->freqLEW->installEventFilter(this);
    ui->timeLEU->installEventFilter(this);
    ui->timeLEV->installEventFilter(this);
    ui->timeLEW->installEventFilter(this);
    ui->angleLE1->installEventFilter(this);
    ui->angleLE2->installEventFilter(this);
    ui->angleLE3->installEventFilter(this);
    this->installEventFilter(this);
    m_KeyboardMap.insert(ui->startStepNoLE, i++);
    m_KeyboardMap.insert(ui->stopStepNoLE, i++);
    m_KeyboardMap.insert(ui->cycleLE, i++);
    m_KeyboardMap.insert(ui->jumpLE, i++);
    m_KeyboardMap.insert(ui->voltageLEU, i++);
    m_KeyboardMap.insert(ui->voltageLEV, i++);
    m_KeyboardMap.insert(ui->voltageLEW, i++);
    m_KeyboardMap.insert(ui->freqLEU, i++);
    m_KeyboardMap.insert(ui->freqLEV, i++);
    m_KeyboardMap.insert(ui->freqLEW, i++);
    m_KeyboardMap.insert(ui->timeLEU, i++);
    m_KeyboardMap.insert(ui->timeLEV, i++);
    m_KeyboardMap.insert(ui->timeLEW, i++);
    m_KeyboardMap.insert(ui->angleLE1, i++);
    m_KeyboardMap.insert(ui->angleLE2, i++);
    m_KeyboardMap.insert(ui->angleLE3, i++);
    connect(rtc::getRtcInstance(), &rtc::sigTimeChanged,
            this, &StepSetDialog::slotDateTime, Qt::QueuedConnection);
    connect(this, &StepSetDialog::sigResetLockTime,LockManager::getRtcInstance(),
            &LockManager::slotResetLockTime, Qt::QueuedConnection);
}

StepSetDialog::~StepSetDialog()
{
    disconnect(rtc::getRtcInstance(), &rtc::sigTimeChanged,
            this, &StepSetDialog::slotDateTime);
    disconnect(this, &StepSetDialog::sigResetLockTime,LockManager::getRtcInstance(),
            &LockManager::slotResetLockTime);
    delete ui;
}

void StepSetDialog::setData(const TestCtrl &p_ctrl, const QList<StepData> &p_data)
{
    int i = 1;
    ui->tableWidget->setColumnWidth(0, 40);
    while(i < ui->tableWidget->columnCount())
    {
        ui->tableWidget->setColumnWidth(i, 84);
        i++;
    }
    m_OutputMode = p_ctrl.OutputMode;
    ui->outputModeLE->setText(getOutputModeName(0, m_OutputMode));
    ui->startStepNoLE->setValue(p_ctrl.StartNo);
    ui->stopStepNoLE->setValue(p_ctrl.StopNo);
    ui->cycleLE->setValue(p_ctrl.CycleTimes);
    updateOutputMode(m_OutputMode);
    m_Data.clear();
    m_Data = p_data;
    data2Table();
    ui->tableWidget->selectRow(0);
    Table2Ui(0);
}

void StepSetDialog::getData(TestCtrl &p_ctrl, QList<StepData> &p_data)
{
    p_data = m_Data;
    p_ctrl.StartNo = ui->startStepNoLE->text().toInt();
    p_ctrl.StopNo = ui->stopStepNoLE->text().toInt();
    p_ctrl.CycleTimes = ui->cycleLE->text().toInt();
}

void StepSetDialog::slotDateTime(const QString p_datetime)
{
    ui->timeLab->setText(p_datetime);
}

void StepSetDialog::slotKeyPressed(const int p_key)
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

void StepSetDialog::on_saveBtn_clicked()
{
    dbOperation dbObj;
    table2Data();
    dbObj.StepWrite(m_Data);
    WarningDialog warning(this);
    warning.initWarning(tr("保存"), tr("保存成功"));
    warning.exec();
    //QMessageBox::information(this, tr("保存"), tr("保存成功"));
    emit sigResetLockTime();
    accept();
}

void StepSetDialog::on_backBtn_clicked()
{
    emit sigResetLockTime();
    reject();
    close();
}

void StepSetDialog::updateOutputMode(const int p_outputmode)
{
    QLayout *p_lay1 = ui->UWidget->layout();
    QLayout *p_lay2 = ui->UWidget2->layout();
    QLayout *p_lay3 = ui->angleWidget->layout();
    switch(p_outputmode)
    {
    case ENM_OUTPUT_DISCRETE:
        p_lay1->setSpacing(5);
        p_lay2->setSpacing(5);
        p_lay3->setSpacing(5);
        ui->angleWidget->setVisible(false);
        break;
    case ENM_OUTPUT_IMBANLANCE:
        p_lay1->setSpacing(30);
        p_lay2->setSpacing(30);
        p_lay3->setSpacing(30);
        ui->freqLabU->setVisible(false);
        ui->freqLabV->setVisible(false);
        ui->freqLabW->setVisible(false);
        ui->freqLEV->setVisible(false);
        ui->freqLEW->setVisible(false);
        ui->timeLabU->setVisible(false);
        ui->timeLabV->setVisible(false);
        ui->timeLabW->setVisible(false);
        ui->timeLEV->setVisible(false);
        ui->timeLEW->setVisible(false);
        break;
    case ENM_OUTPUT_THREEPHASE:
    case ENM_OUTPUT_SINGLE:
        p_lay1->setSpacing(30);
        p_lay2->setSpacing(30);
        p_lay3->setSpacing(30);
        ui->angleWidget->setVisible(false);
        ui->voltageLabU->setVisible(false);
        ui->voltageLabV->setVisible(false);
        ui->voltageLabW->setVisible(false);
        ui->voltageLEV->setVisible(false);
        ui->voltageLEW->setVisible(false);
        ui->freqLabU->setVisible(false);
        ui->freqLabV->setVisible(false);
        ui->freqLabW->setVisible(false);
        ui->freqLEV->setVisible(false);
        ui->freqLEW->setVisible(false);
        ui->timeLabU->setVisible(false);
        ui->timeLabV->setVisible(false);
        ui->timeLabW->setVisible(false);
        ui->timeLEV->setVisible(false);
        ui->timeLEW->setVisible(false);
        ui->harmonicsLEU->setVisible(false);
        ui->harmonicsLEV->setVisible(false);
        ui->harmonicsLEW->setVisible(false);
        ui->harmonicsCBV->setVisible(false);
        ui->harmonicsCBW->setVisible(false);
        break;
    default:
        break;
    }
}

void StepSetDialog::Table2Ui(int p_row)
{
    int i = 1;
    ui->voltageLEU->setValue(ui->tableWidget->item(p_row, i++)->text().toDouble());
    ui->voltageLEV->setValue(ui->tableWidget->item(p_row, i++)->text().toDouble());
    ui->voltageLEW->setValue(ui->tableWidget->item(p_row, i++)->text().toDouble());
    ui->freqLEU->setValue(ui->tableWidget->item(p_row, i++)->text().toDouble());
    ui->freqLEV->setValue(ui->tableWidget->item(p_row, i++)->text().toDouble());
    ui->freqLEW->setValue(ui->tableWidget->item(p_row, i++)->text().toDouble());
    ui->timeLEU->setValue(ui->tableWidget->item(p_row, i++)->text().toDouble());
    ui->timeLEV->setValue(ui->tableWidget->item(p_row, i++)->text().toDouble());
    ui->timeLEW->setValue(ui->tableWidget->item(p_row, i++)->text().toDouble());
    ui->harmonicsCBU->setCurrentIndex(ui->tableWidget->item(p_row, i++)->text().toInt());
    ui->harmonicsCBV->setCurrentIndex(ui->tableWidget->item(p_row, i++)->text().toInt());
    ui->harmonicsCBW->setCurrentIndex(ui->tableWidget->item(p_row, i++)->text().toInt());
#if 0
    if(p_data.OutputMode == ENM_OUTPUT_IMBANLANCE)
    {
        ui->angleLE1->setText(QString::number(p_data.AnglesUV, 'f', 1));
        ui->angleLE2->setText(QString::number(p_data.AnglesUW, 'f', 1));
        ui->angleLE3->setText(QString::number(p_data.AnglesVW, 'f', 1));
    }
#endif
}

void StepSetDialog::ui2Table(const int p_col, const QString &p_val)
{
    int row = ui->tableWidget->row(ui->tableWidget->selectedItems().at(0));
    ui->tableWidget->item(row, p_col)->setText(p_val);
    emit sigResetLockTime();
}

void StepSetDialog::data2Table()
{
    int i = 0;
    int cnt = m_Data.count();
    while(i < cnt)
    {
        int k = 0;
        int colCnt = ui->tableWidget->columnCount();
        ui->tableWidget->insertRow(i);
        while(k < colCnt)
        {
            QTableWidgetItem *pItem = nullptr;
            switch(k)
            {
            case 0:
                pItem = new QTableWidgetItem(QString::number(m_Data.at(i).StepNo));
                break;
            case 1:
                pItem = new QTableWidgetItem(QString::number(m_Data.at(i).VoltageU, 'f', 1));
                break;
            case 2:
                pItem = new QTableWidgetItem(QString::number(m_Data.at(i).VoltageV, 'f', 1));
                break;
            case 3:
                pItem = new QTableWidgetItem(QString::number(m_Data.at(i).VoltageW, 'f', 1));
                break;
            case 4:
                pItem = new QTableWidgetItem(QString::number(m_Data.at(i).FrequencyU, 'f', 2));
                break;
            case 5:
                pItem = new QTableWidgetItem(QString::number(m_Data.at(i).FrequencyV, 'f', 2));
                break;
            case 6:
                pItem = new QTableWidgetItem(QString::number(m_Data.at(i).FrequencyW, 'f', 2));
                break;
            case 7:
                pItem = new QTableWidgetItem(QString::number(m_Data.at(i).StepTimeU, 'f', 1));
                break;
            case 8:
                pItem = new QTableWidgetItem(QString::number(m_Data.at(i).StepTimeV, 'f', 1));
                break;
            case 9:
                pItem = new QTableWidgetItem(QString::number(m_Data.at(i).StepTimeW, 'f', 1));
                break;
            case 10:
                pItem = new QTableWidgetItem(QString::number(m_Data.at(i).WaveFormU));
                break;
            case 11:
                pItem = new QTableWidgetItem(QString::number(m_Data.at(i).WaveFormV));
                break;
            case 12:
                pItem = new QTableWidgetItem(QString::number(m_Data.at(i).WaveFormW));
                break;
            }
            ui->tableWidget->setItem(i, k, pItem);
            ui->tableWidget->item(i, k)->setTextAlignment(
                        Qt::AlignHCenter | Qt::AlignVCenter);
            k++;
        }
        i++;
    }
}

void StepSetDialog::table2Data()
{
    int i = 0;
    int cnt = ui->tableWidget->rowCount();
    while(i < cnt)
    {
        int k = 0;
        int colCnt = ui->tableWidget->columnCount();
        while(k < colCnt)
        {
            QTableWidgetItem *pItem = ui->tableWidget->item(i, k);
            switch(k)
            {
            case 0:
                m_Data[i].StepNo = pItem->text().toInt();
                break;
            case 1:
                m_Data[i].VoltageU = pItem->text().toFloat();
                break;
            case 2:
                m_Data[i].VoltageV = pItem->text().toFloat();
                break;
            case 3:
                m_Data[i].VoltageW = pItem->text().toFloat();
                break;
            case 4:
                m_Data[i].FrequencyU = pItem->text().toFloat();
                break;
            case 5:
                m_Data[i].FrequencyV = pItem->text().toFloat();
                break;
            case 6:
                m_Data[i].FrequencyW = pItem->text().toFloat();
                break;
            case 7:
                m_Data[i].StepTimeU = pItem->text().toFloat();
                break;
            case 8:
                m_Data[i].StepTimeV = pItem->text().toFloat();
                break;
            case 9:
                m_Data[i].StepTimeW = pItem->text().toFloat();
                break;
            case 10:
                m_Data[i].WaveFormU = pItem->text().toInt();
                break;
            case 11:
                m_Data[i].WaveFormV = pItem->text().toInt();
                break;
            case 12:
                m_Data[i].WaveFormW = pItem->text().toInt();
                break;
            }
            k++;
        }
        i++;
    }
}

void StepSetDialog::initKeyBoard(const int p_x, const int p_y, const int p_width, const int p_height)
{
    if(m_KeyBoard == nullptr)
    {
        m_KeyBoard = new KeyboardForm();
        connect(m_KeyBoard, &KeyboardForm::sigKeyPressed,
            this, &StepSetDialog::slotKeyPressed);
    }
    m_KeyBoard->setPos(p_x, p_y, p_width, p_height);
}

void StepSetDialog::uninitKeyBoard()
{
    m_CurrentObj = nullptr;
    if(m_KeyBoard == nullptr)
        return;
    m_KeyBoard->hide();
    disconnect(m_KeyBoard, &KeyboardForm::sigKeyPressed,
            this, &StepSetDialog::slotKeyPressed);
    delete m_KeyBoard;
    m_KeyBoard = nullptr;
}

bool StepSetDialog::eventFilter(QObject *watched, QEvent *event)
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

void StepSetDialog::on_jumpLE_editingFinished()
{
    int row = ui->jumpLE->text().toInt();
    if(row <= 0 || row > 100)
        row = 1;
    ui->tableWidget->selectRow(row - 1);
    emit sigResetLockTime();
}

void StepSetDialog::on_tableWidget_cellClicked(int row, int column)
{
    Table2Ui(row);
    emit sigResetLockTime();
}

void StepSetDialog::on_voltageLEU_editingFinished()
{
    ui2Table(1, ui->voltageLEU->text());
}

void StepSetDialog::on_voltageLEV_editingFinished()
{
    ui2Table(2, ui->voltageLEV->text());
}

void StepSetDialog::on_voltageLEW_editingFinished()
{
    ui2Table(3, ui->voltageLEW->text());
}

void StepSetDialog::on_freqLEU_editingFinished()
{
    ui2Table(4, ui->freqLEU->text());
}

void StepSetDialog::on_freqLEV_editingFinished()
{
    ui2Table(5, ui->freqLEV->text());
}

void StepSetDialog::on_freqLEW_editingFinished()
{
    ui2Table(6, ui->freqLEW->text());
}

void StepSetDialog::on_harmonicsCBU_activated(int index)
{
    ui2Table(10, QString::number(index));
}

void StepSetDialog::on_harmonicsCBV_activated(int index)
{
    ui2Table(11, QString::number(index));
}

void StepSetDialog::on_harmonicsCBW_activated(int index)
{
    ui2Table(12, QString::number(index));
}

void StepSetDialog::on_timeLEU_editingFinished()
{
    ui2Table(7, ui->timeLEU->text());
}

void StepSetDialog::on_timeLEV_editingFinished()
{
    ui2Table(8, ui->timeLEV->text());
}

void StepSetDialog::on_timeLEW_editingFinished()
{
    ui2Table(9, ui->timeLEW->text());
}

void StepSetDialog::on_angleLE1_editingFinished()
{
    float angle1 = ui->angleLE1->text().toFloat();
    float angle2 = ui->angleLE2->text().toFloat();
    float angle3 = 360 - angle1 - angle2;
    ui->angleLE3->setValue(angle3);
    emit sigResetLockTime();
}

void StepSetDialog::on_angleLE2_editingFinished()
{
    on_angleLE1_editingFinished();
}
