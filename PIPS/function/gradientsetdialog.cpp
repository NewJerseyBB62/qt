#include "gradientsetdialog.h"
#include "ui_gradientsetdialog.h"
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

GradientSetDialog::GradientSetDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GradientSetDialog),
    m_KeyBoard(nullptr),
    m_CurrentObj(nullptr)
{
    int i = 0;
    this->setGeometry(0, 0, 1280, 800);
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->setupUi(this);
    ui->harmonicsCBU->setView(new QListView(this));
    ui->startStepNoLE->installEventFilter(this);
    ui->stopStepNoLE->installEventFilter(this);
    ui->cycleLE->installEventFilter(this);
    ui->jumpLE->installEventFilter(this);
    ui->voltageStartLEU->installEventFilter(this);
    ui->voltageStopLEU->installEventFilter(this);
    ui->freqStartLEU->installEventFilter(this);
    ui->freqStopLEU->installEventFilter(this);
    ui->timeLEU->installEventFilter(this);
    ui->angleLE1->installEventFilter(this);
    ui->angleLE2->installEventFilter(this);
    ui->angleLE3->installEventFilter(this);
    this->installEventFilter(this);
    m_KeyboardMap.insert(ui->startStepNoLE, i++);
    m_KeyboardMap.insert(ui->stopStepNoLE, i++);
    m_KeyboardMap.insert(ui->cycleLE, i++);
    m_KeyboardMap.insert(ui->jumpLE, i++);
    m_KeyboardMap.insert(ui->voltageStartLEU, i++);
    m_KeyboardMap.insert(ui->voltageStopLEU, i++);
    m_KeyboardMap.insert(ui->freqStartLEU, i++);
    m_KeyboardMap.insert(ui->freqStopLEU, i++);
    m_KeyboardMap.insert(ui->timeLEU, i++);
    m_KeyboardMap.insert(ui->angleLE1, i++);
    m_KeyboardMap.insert(ui->angleLE2, i++);
    m_KeyboardMap.insert(ui->angleLE3, i++);
    connect(rtc::getRtcInstance(), &rtc::sigTimeChanged,
            this, &GradientSetDialog::slotDateTime, Qt::QueuedConnection);
    connect(this, &GradientSetDialog::sigResetLockTime,LockManager::getRtcInstance(),
            &LockManager::slotResetLockTime, Qt::QueuedConnection);
}

GradientSetDialog::~GradientSetDialog()
{
    disconnect(rtc::getRtcInstance(), &rtc::sigTimeChanged,
            this, &GradientSetDialog::slotDateTime);
    disconnect(this, &GradientSetDialog::sigResetLockTime,LockManager::getRtcInstance(),
            &LockManager::slotResetLockTime);
    delete ui;
}

void GradientSetDialog::setData(const TestCtrl &p_ctrl, QList<GradientData> &p_data)
{
    int i = 1;
    ui->tableWidget->setColumnWidth(0, 87);
    while(i < ui->tableWidget->columnCount())
    {
        ui->tableWidget->setColumnWidth(i, 140);
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

void GradientSetDialog::getData(TestCtrl &p_ctrl, QList<GradientData> &p_data)
{
    p_data = m_Data;
    p_ctrl.StartNo = ui->startStepNoLE->text().toInt();
    p_ctrl.StopNo = ui->stopStepNoLE->text().toInt();
    p_ctrl.CycleTimes = ui->cycleLE->text().toInt();
}

void GradientSetDialog::slotDateTime(const QString p_datetime)
{
    ui->timeLab->setText(p_datetime);
}

void GradientSetDialog::slotKeyPressed(const int p_key)
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

void GradientSetDialog::on_saveBtn_clicked()
{
    dbOperation dbObj;
    table2Data();
    //qDebug() << m_Data.at(0).StartVoltageU << m_Data.at(1).StartVoltageU;
    dbObj.GradientWrite(m_Data);
    WarningDialog warning(this);
    warning.initWarning(tr("保存"), tr("保存成功"));
    warning.exec();
    //QMessageBox::information(this, tr("保存"), tr("保存成功"));
    emit sigResetLockTime();
    accept();
}

void GradientSetDialog::on_backBtn_clicked()
{
    emit sigResetLockTime();
    reject();
    close();
}

void GradientSetDialog::on_jumpLE_editingFinished()
{
    int row = ui->jumpLE->text().toInt();
    if(row <= 0 || row > 100)
        row = 1;
    if(!m_ThreeMode)
        ui->tableWidget->selectRow(row - 1);
    else
        ui->tableWidget->selectRow((row - 1) * 3);
    emit sigResetLockTime();
}

void GradientSetDialog::on_tableWidget_cellClicked(int row, int column)
{
    //qDebug() << "zzp" << row << column;
    Table2Ui(row);
    emit sigResetLockTime();
}

void GradientSetDialog::updateOutputMode(const int p_outputmode)
{
    switch(p_outputmode)
    {
    case ENM_OUTPUT_THREEPHASE:
    case ENM_OUTPUT_SINGLE:
        ui->angleWidget->setVisible(false);
        m_ThreeMode = false;
        break;
    case ENM_OUTPUT_DISCRETE:
        ui->angleWidget->setVisible(false);
        m_ThreeMode = true;
        break;
    case ENM_OUTPUT_IMBANLANCE:
        m_ThreeMode = true;
        break;
    default:
        break;
    }
}

void GradientSetDialog::Table2Ui(const int p_row)
{
    int i = 2;

    ui->voltageStartLEU->setValue(ui->tableWidget->item(p_row, i++)->text().toDouble());
    ui->voltageStopLEU->setValue(ui->tableWidget->item(p_row, i++)->text().toDouble());
    if(m_OutputMode != ENM_OUTPUT_IMBANLANCE)
    {
        ui->freqStartLEU->setValue(ui->tableWidget->item(p_row, i++)->text().toDouble());
        ui->freqStopLEU->setValue(ui->tableWidget->item(p_row, i++)->text().toDouble());
        ui->timeLEU->setValue(ui->tableWidget->item(p_row, i++)->text().toDouble());
    }
    else
    {
        ui->freqStartLEU->setValue(ui->tableWidget->item(p_row / 3 * 3, i++)->text().toDouble());
        ui->freqStopLEU->setValue(ui->tableWidget->item(p_row / 3 * 3, i++)->text().toDouble());
        ui->timeLEU->setValue(ui->tableWidget->item(p_row / 3 * 3, i++)->text().toDouble());
    }
    ui->harmonicsCBU->setCurrentIndex(ui->tableWidget->item(p_row, i++)->text().toInt());
}

void GradientSetDialog::ui2Table(const int p_col, const QString &p_val)
{
    int row = ui->tableWidget->row(ui->tableWidget->selectedItems().at(0));

    if(m_OutputMode == ENM_OUTPUT_IMBANLANCE && p_col >= 4 &&
            p_col <= 6)
    {
        ui->tableWidget->item(row / 3 * 3, p_col)->setText(p_val);
    }
    else
        ui->tableWidget->item(row, p_col)->setText(p_val);
    emit sigResetLockTime();
}

void GradientSetDialog::data2Table()
{
    int i = 0;
    int cnt = m_Data.count();

    while(i < cnt)
    {
        int k = 0;
        int colCnt = ui->tableWidget->columnCount();
        if(!m_ThreeMode)
            ui->tableWidget->insertRow(i);
        else
        {
            ui->tableWidget->insertRow(i * 3);
            ui->tableWidget->insertRow(i * 3 + 1);
            ui->tableWidget->insertRow(i * 3 + 2);
        }
        while(k < colCnt)
        {
            QTableWidgetItem *pItem = nullptr;
            QTableWidgetItem *pItem2 = nullptr;
            QTableWidgetItem *pItem3 = nullptr;
            switch(k)
            {
            case 0:
                pItem = new QTableWidgetItem(QString::number(m_Data.at(i).StepNo));
                if(m_ThreeMode)
                {
                    pItem2 = new QTableWidgetItem(QString::number(m_Data.at(i).StepNo));
                    pItem3 = new QTableWidgetItem(QString::number(m_Data.at(i).StepNo));
                }
                break;
            case 1:
                if(!m_ThreeMode)
                    pItem = new QTableWidgetItem("UVW");
                else
                {
                    pItem = new QTableWidgetItem("U");
                    pItem2 = new QTableWidgetItem("V");
                    pItem3 = new QTableWidgetItem("W");
                }
                break;
            case 2:
                pItem = new QTableWidgetItem(QString::number(m_Data.at(i).StartVoltageU, 'f', 1));
                if(m_ThreeMode)
                {
                    pItem2 = new QTableWidgetItem(QString::number(m_Data.at(i).StartVoltageV, 'f', 1));
                    pItem3 = new QTableWidgetItem(QString::number(m_Data.at(i).StartVoltageW, 'f', 1));
                }
                break;
            case 3:
                pItem = new QTableWidgetItem(QString::number(m_Data.at(i).StopVoltageV, 'f', 1));
                if(m_ThreeMode)
                {
                    pItem2 = new QTableWidgetItem(QString::number(m_Data.at(i).StopVoltageV, 'f', 1));
                    pItem3 = new QTableWidgetItem(QString::number(m_Data.at(i).StopVoltageW, 'f', 1));
                }
                break;
            case 4:
                pItem = new QTableWidgetItem(QString::number(m_Data.at(i).StartFrequencyU, 'f', 2));
                if(m_ThreeMode)
                {
                    pItem2 = new QTableWidgetItem(QString::number(m_Data.at(i).StartFrequencyV, 'f', 2));
                    pItem3 = new QTableWidgetItem(QString::number(m_Data.at(i).StartFrequencyW, 'f', 2));
                }
                break;
            case 5:
                pItem = new QTableWidgetItem(QString::number(m_Data.at(i).StopFrequencyU, 'f', 2));
                if(m_ThreeMode)
                {
                    pItem2 = new QTableWidgetItem(QString::number(m_Data.at(i).StopFrequencyV, 'f', 2));
                    pItem3 = new QTableWidgetItem(QString::number(m_Data.at(i).StopFrequencyW, 'f', 2));
                }
                break;
            case 6:
                pItem = new QTableWidgetItem(QString::number(m_Data.at(i).StepTimeU, 'f', 1));
                if(m_ThreeMode)
                {
                    pItem2 = new QTableWidgetItem(QString::number(m_Data.at(i).StepTimeV, 'f', 1));
                    pItem3 = new QTableWidgetItem(QString::number(m_Data.at(i).StepTimeW, 'f', 1));
                }
                break;
            case 7:
                pItem = new QTableWidgetItem(QString::number(m_Data.at(i).WaveFormU));
                if(m_ThreeMode)
                {
                    pItem2 = new QTableWidgetItem(QString::number(m_Data.at(i).WaveFormV));
                    pItem3 = new QTableWidgetItem(QString::number(m_Data.at(i).WaveFormW));
                }
                break;
            }
            if(!m_ThreeMode)
            {
                ui->tableWidget->setItem(i, k, pItem);
                ui->tableWidget->item(i, k)->setTextAlignment(
                            Qt::AlignHCenter | Qt::AlignVCenter);
            }
            else
            {
                ui->tableWidget->setItem(i * 3, k, pItem);
                ui->tableWidget->setItem(i * 3 + 1, k, pItem2);
                ui->tableWidget->setItem(i * 3 + 2, k, pItem3);
                ui->tableWidget->item(i * 3, k)->setTextAlignment(
                            Qt::AlignHCenter | Qt::AlignVCenter);
                ui->tableWidget->item(i * 3 + 1, k)->setTextAlignment(
                            Qt::AlignHCenter | Qt::AlignVCenter);
                ui->tableWidget->item(i * 3 + 2, k)->setTextAlignment(
                            Qt::AlignHCenter | Qt::AlignVCenter);
                if(m_OutputMode == ENM_OUTPUT_IMBANLANCE)
                {
                    if(k >= 4 && k <= 6)
                    {
                        ui->tableWidget->setSpan(i * 3, k, 3, 1);
                    }
                }
            }
            k++;
        }
        i++;
    }
}

void GradientSetDialog::table2Data()
{
    int i = 0;
    int cnt = ui->tableWidget->rowCount();

    while(i < cnt - 2)
    {
        int k = 0;
        int colCnt = ui->tableWidget->columnCount();
        while(k < colCnt)
        {
            QTableWidgetItem *pItem = nullptr;
            QTableWidgetItem *pItem2 = nullptr;
            QTableWidgetItem *pItem3 = nullptr;
            if(m_ThreeMode)
            {
                pItem = ui->tableWidget->item(i, k);
                pItem2 = ui->tableWidget->item(i + 1, k);
                pItem3 = ui->tableWidget->item(i + 2, k);
            }
            else
                pItem = ui->tableWidget->item(i, k);
            switch(k)
            {
            case 0:
                if(!m_ThreeMode)
                    m_Data[i].StepNo = pItem->text().toInt();
                else
                {
                    m_Data[i / 3].StepNo = pItem->text().toInt();
                }
                break;
            case 1:
                if(!m_ThreeMode)
                    m_Data[i].Phase = 0;
                else
                    m_Data[i / 3].Phase = 0;
                break;
            case 2:
                if(!m_ThreeMode)
                    m_Data[i].StartVoltageU = pItem->text().toFloat();
                else
                {
                    m_Data[i / 3].StartVoltageU = pItem->text().toFloat();
                    m_Data[i / 3].StartVoltageV = pItem2->text().toFloat();
                    m_Data[i / 3].StartVoltageW = pItem3->text().toFloat();
                }
                break;
            case 3:
                if(!m_ThreeMode)
                    m_Data[i].StopVoltageU = pItem->text().toFloat();
                else
                {
                    m_Data[i / 3].StopVoltageU = pItem->text().toFloat();
                    m_Data[i / 3].StopVoltageV = pItem2->text().toFloat();
                    m_Data[i / 3].StopVoltageW = pItem3->text().toFloat();
                }
                break;
            case 4:
                if(!m_ThreeMode)
                    m_Data[i].StartFrequencyU = pItem->text().toFloat();
                else
                {
                    m_Data[i / 3].StartFrequencyU = pItem->text().toFloat();
                    if(m_OutputMode != ENM_OUTPUT_IMBANLANCE)
                    {
                        m_Data[i / 3].StartFrequencyV = pItem2->text().toFloat();
                        m_Data[i / 3].StartFrequencyW = pItem3->text().toFloat();
                    }
                }
                break;
            case 5:
                if(!m_ThreeMode)
                    m_Data[i].StopFrequencyU = pItem->text().toFloat();
                else
                {
                    m_Data[i / 3].StopFrequencyU = pItem->text().toFloat();
                    if(m_OutputMode != ENM_OUTPUT_IMBANLANCE)
                    {
                        m_Data[i / 3].StopFrequencyV = pItem2->text().toFloat();
                        m_Data[i / 3].StopFrequencyW = pItem3->text().toFloat();
                    }
                }
                break;
            case 6:
                if(!m_ThreeMode)
                    m_Data[i].StepTimeU = pItem->text().toFloat();
                else
                {
                    m_Data[i / 3].StepTimeU = pItem->text().toFloat();
                    if(m_OutputMode != ENM_OUTPUT_IMBANLANCE)
                    {
                        m_Data[i / 3].StepTimeV = pItem2->text().toFloat();
                        m_Data[i / 3].StepTimeW = pItem3->text().toFloat();
                    }
                }
                break;
            case 7:
                if(!m_ThreeMode)
                    m_Data[i].WaveFormU = pItem->text().toInt();
                else
                {
                    m_Data[i / 3].WaveFormU = pItem->text().toInt();
                    m_Data[i / 3].WaveFormV = pItem2->text().toInt();
                    m_Data[i / 3].WaveFormW = pItem3->text().toInt();
                }
                break;
            }
            k++;
        }
        if(m_ThreeMode)
            i += 3;
        else
            i++;
    }
}

void GradientSetDialog::initKeyBoard(const int p_x, const int p_y, const int p_width, const int p_height)
{
    if(m_KeyBoard == nullptr)
    {
        m_KeyBoard = new KeyboardForm();
        connect(m_KeyBoard, &KeyboardForm::sigKeyPressed,
            this, &GradientSetDialog::slotKeyPressed);
    }
    m_KeyBoard->setPos(p_x, p_y, p_width, p_height);
}

void GradientSetDialog::uninitKeyBoard()
{
    m_CurrentObj = nullptr;
    if(m_KeyBoard == nullptr)
        return;
    m_KeyBoard->hide();
    disconnect(m_KeyBoard, &KeyboardForm::sigKeyPressed,
            this, &GradientSetDialog::slotKeyPressed);
    delete m_KeyBoard;
    m_KeyBoard = nullptr;
}

bool GradientSetDialog::eventFilter(QObject *watched, QEvent *event)
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

void GradientSetDialog::on_voltageStartLEU_editingFinished()
{
    ui2Table(2, ui->voltageStartLEU->text());
}

void GradientSetDialog::on_voltageStopLEU_editingFinished()
{
    ui2Table(3, ui->voltageStopLEU->text());
}

void GradientSetDialog::on_freqStartLEU_editingFinished()
{
    ui2Table(4, ui->freqStartLEU->text());
}

void GradientSetDialog::on_freqStopLEU_editingFinished()
{
    ui2Table(5, ui->freqStopLEU->text());
}

void GradientSetDialog::on_harmonicsCBU_activated(int index)
{
    ui2Table(7, QString::number(index));
}

void GradientSetDialog::on_timeLEU_editingFinished()
{
    ui2Table(6, ui->timeLEU->text());
}

void GradientSetDialog::on_angleLE1_editingFinished()
{
    float angle1 = ui->angleLE1->text().toFloat();
    float angle2 = ui->angleLE2->text().toFloat();
    float angle3 = 360 - angle1 - angle2;
    ui->angleLE3->setValue(angle3);
    emit sigResetLockTime();
}

void GradientSetDialog::on_angleLE2_editingFinished()
{
    on_angleLE1_editingFinished();
}
