#include "programdialog.h"
#include "ui_programdialog.h"
#include <QFileDialog>
#include <QDebug>
#include <QValidator>
#include <QMessageBox>

enum TEST_PAGE{
  ENM_PAGE_UNKNOWN = 0,
  ENM_PAGE_IR,
  ENM_PAGE_PEQ
};

programDialog::programDialog(QString p_path, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::programDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    //this->showMaximized();
    this->showFullScreen();

    //ui->itemListWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //ui->itemListWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->itemListWidget->setColumnWidth(0, 80);
    ui->itemListWidget->setColumnWidth(1, 162);
    ui->itemListWidget->verticalHeader()->setDefaultSectionSize(40);
    ui->itemListWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->itemListWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    QFont font = ui->itemListWidget->horizontalHeader()->font();
    font.setPixelSize(16);
    font.setBold(true);
    ui->itemListWidget->horizontalHeader()->setFont(font);
    ui->itemListWidget->setAlternatingRowColors(true);

    m_ItemNameMap.insert(TEST_ITEM::ENM_ITEM_IR, QStringLiteral("绝缘"));
    m_ItemNameMap.insert(TEST_ITEM::ENM_ITEM_PEQ, QStringLiteral("电位均衡"));
    initValidator();
    ui->irTestSetLE->setValidator(new QDoubleValidator(m_Validator.irVoltMin, m_Validator.irVoltMax, 3, this));
    ui->irTestValLowLE->setValidator(new QDoubleValidator(m_Validator.irResMin, m_Validator.irResMax, 3, this));
    ui->irTestValHighLE->setValidator(new QDoubleValidator(m_Validator.irResMin, m_Validator.irResMax, 3, this));
    ui->irTestCompLE->setValidator(new QIntValidator(m_Validator.irCompMin, m_Validator.irCompMax, this));
    ui->irTestTimeLE->setValidator(new QDoubleValidator(m_Validator.irTimeMin, m_Validator.irTimeMax, 1, this));
    ui->peqTestSetLE->setValidator(new QDoubleValidator(m_Validator.peqCurrentMin, m_Validator.peqCurrentMax, 2, this));
    ui->peqTestValLowLE->setValidator(new QDoubleValidator(m_Validator.peqResMin, m_Validator.peqResMax, 1, this));
    ui->peqTestValHighLE->setValidator(new QDoubleValidator(m_Validator.peqResMin, m_Validator.peqResMax, 1, this));
    ui->peqTestCompLE->setValidator(new QDoubleValidator(m_Validator.peqCompMin, m_Validator.peqCompMax, 1, this));
    ui->peqTestTimeLE->setValidator(new QDoubleValidator(m_Validator.peqTimeMin, m_Validator.peqTimeMax, 1, this));
    ui->topfileBtn->setVisible(false);
    ui->downfileBtn->setVisible(false);

    if(p_path.length() > 0)
    {
        QFileInfo fileInfo(p_path);
        if(!fileInfo.isFile())
            return;
        ui->filenameLE->setText(fileInfo.baseName());
        jsonOperation jsonObj;
        int nRet = jsonObj.readJsonfile(p_path, m_JsonData);
        if(nRet != 0)
        {
            return;
        }
        loadTestData();
        if(m_JsonData.testItemData.value<TestGroupData>().testDataList.size() > 0)
        {
            selectRow(0);
        }
    }
    else
    {
        clearAll();
    }
}

programDialog::~programDialog()
{
    delete ui;
}

void programDialog::on_minBtn_clicked()
{
    this->showMinimized();
}

void programDialog::on_closeBtn_clicked()
{
    done(Rejected);
    close();
}

void programDialog::on_openfileBtn_clicked()
{
    QFileDialog fileDialog;
    fileDialog.setWindowTitle("选择测试文件");
    fileDialog.setDirectory("../json/");
    fileDialog.setNameFilter("File(*.json)");
    fileDialog.setFileMode(QFileDialog::ExistingFile);
    fileDialog.setViewMode(QFileDialog::Detail);
    QStringList fileNames;
    if(fileDialog.exec())
        fileNames = fileDialog.selectedFiles();
    if(fileNames.size() <= 0)
        return;
    QString filename = fileNames.first();
    if(filename.length() <= 0)
        return;
    jsonOperation jsonObj;
    int nRet = jsonObj.readJsonfile(filename, m_JsonData);
    if(nRet != 0)
    {
        return;
    }
    QFileInfo fileInfo(filename);
    ui->filenameLE->setText(fileInfo.baseName());
    loadTestData();
    if(m_JsonData.testItemData.value<TestGroupData>().testDataList.size() > 0)
    {
        selectRow(0);
    }
}

void programDialog::on_savefileBtn_clicked()
{
    if(ui->filenameLE->text().length() <= 0)
    {
        return;
    }

    QString filePath("../json/");
    QDir dir(filePath);
    if(!dir.exists())
        dir.mkdir(filePath);
    filePath = filePath + ui->filenameLE->text() + ".json";
    m_JsonData.testItemType = JSON_STRUCTTYPE::ENM_ITEM_TEST;
    TestGroupData *pTestData = reinterpret_cast<TestGroupData*>(m_JsonData.testItemData.data());
    pTestData->testGroupData.nVoltFreq = ui->freqLE->text().toInt();
    pTestData->testGroupData.nFailStep = ui->failstepCBox->currentIndex();
    pTestData->testGroupData.nPowerType = ui->powerCBox->currentIndex();
    pTestData->testGroupData.nGroupConnect = ui->groupConnCBox->currentIndex();
    jsonOperation jsonObj;
    if(jsonObj.writeJsonfile(filePath, m_JsonData) == 0)
    {
        QMessageBox::information(this, "保存", "保存成功", QMessageBox::Yes);
    }
    else
    {
        QMessageBox::information(this, "保存", "保存失败", QMessageBox::Yes);
    }
}

void programDialog::on_newfileBtn_clicked()
{
    clearAll();
}

void programDialog::on_topfileBtn_clicked()
{

}

void programDialog::on_downfileBtn_clicked()
{

}

void programDialog::on_deletefileBtn_clicked()
{
    if(ui->itemListWidget->rowCount() <= 0)
        return;
    if(!m_JsonData.testItemData.canConvert<TestGroupData>())
        return;
    TestGroupData *pData = reinterpret_cast<TestGroupData *>(m_JsonData.testItemData.data());
    int currRow = ui->itemListWidget->currentRow();
    if(currRow < pData->testDataList.size())
    {
        ui->itemListWidget->removeRow(currRow);
        pData->testDataList.removeAt(currRow);
    }

}

void programDialog::on_itemListWidget_clicked(const QModelIndex &index)
{
    if(m_nLastListRow == index.row())
    {
        return;
    }
    selectRow(index.row());
}

void programDialog::on_irTestSetLE_textEdited(const QString &arg1)
{
    if(arg1.length() <= 0)
        return;
    float volt = arg1.toFloat();
    if(volt < m_Validator.irVoltMin)
    {
        volt = m_Validator.irVoltMin;
        ui->irTestSetLE->setText(QString::number(volt, 'f', 3));
    }
    else if(volt > m_Validator.irVoltMax)
    {
        volt = m_Validator.irVoltMax;
        ui->irTestSetLE->setText(QString::number(volt, 'f', 3));
    }
    GetIRtemData(ui->itemListWidget->currentRow())->fVolt = volt;
}

void programDialog::on_irTestModeCBox_currentIndexChanged(int index)
{
    GetIRtemData(ui->itemListWidget->currentRow())->nConnectMode = index;
}

void programDialog::on_irTestValLowLE_textEdited(const QString &arg1)
{
    if(arg1.length() <= 0)
        return;
    float res = arg1.toFloat();
    if(res < m_Validator.irResMin)
    {
        res = m_Validator.irResMin;
        ui->irTestValLowLE->setText(QString::number(res, 'f', 3));
    }
    else if(res > m_Validator.irResMax)
    {
        res = m_Validator.irResMax;
        ui->irTestValLowLE->setText(QString::number(res, 'f', 3));
    }
    GetIRtemData(ui->itemListWidget->currentRow())->fIrLow = res;
}

void programDialog::on_irTestValHighLE_textEdited(const QString &arg1)
{
    if(arg1.length() <= 0)
        return;
    float res = arg1.toFloat();
    if(res < m_Validator.irResMin)
    {
        res = m_Validator.irResMin;
        ui->irTestValHighLE->setText(QString::number(res, 'f', 3));
    }
    else if(res > m_Validator.irResMax)
    {
        res = m_Validator.irResMax;
        ui->irTestValHighLE->setText(QString::number(res, 'f', 3));
    }
    GetIRtemData(ui->itemListWidget->currentRow())->fIrHigh = res;
}

void programDialog::on_irTestCompLE_textEdited(const QString &arg1)
{
    if(arg1.length() <= 0)
        return;
    int comp = arg1.toInt();
    if(comp < m_Validator.irCompMin)
    {
        comp = m_Validator.irCompMin;
        ui->irTestCompLE->setText(QString::number(comp));
    }
    else if(comp > m_Validator.irCompMax)
    {
        comp = m_Validator.irCompMax;
        ui->irTestCompLE->setText(QString::number(comp));
    }
    GetIRtemData(ui->itemListWidget->currentRow())->fComp = comp;
}

void programDialog::on_irTestTimeLE_textEdited(const QString &arg1)
{
    if(arg1.length() <= 0)
        return;
    float time = arg1.toFloat();
    if(time < m_Validator.irTimeMin)
    {
        time = m_Validator.irTimeMin;
        ui->irTestTimeLE->setText(QString::number(time, 'f', 1));
    }
    else if(time > m_Validator.irTimeMax)
    {
        time = m_Validator.irTimeMax;
        ui->irTestTimeLE->setText(QString::number(time, 'f', 1));
    }
    GetIRtemData(ui->itemListWidget->currentRow())->fTestTime = time;
}

void programDialog::on_peqTestSetLE_textEdited(const QString &arg1)
{
    if(arg1.length() <= 0)
        return;
    float current = arg1.toFloat();
    if(current < m_Validator.peqCurrentMin)
    {
        current = m_Validator.peqCurrentMin;
        ui->peqTestSetLE->setText(QString::number(current, 'f', 2));
    }
    else if(current > m_Validator.peqCurrentMax)
    {
        current = m_Validator.peqCurrentMax;
        ui->peqTestSetLE->setText(QString::number(current, 'f', 2));
    }
    GetPEQitemData(ui->itemListWidget->currentRow())->fCurrent = current;
}

void programDialog::on_peqTestModeCBox_currentIndexChanged(int index)
{
    GetPEQitemData(ui->itemListWidget->currentRow())->nConnectMode = index;
}

void programDialog::on_peqTestValLowLE_textEdited(const QString &arg1)
{
    if(arg1.length() <= 0)
        return;
    float res = arg1.toFloat();
    if(res < m_Validator.peqResMin)
    {
        res = m_Validator.peqResMin;
        ui->peqTestValLowLE->setText(QString::number(res, 'f', 1));
    }
    else if(res > m_Validator.peqResMax)
    {
        res = m_Validator.peqResMax;
        ui->peqTestValLowLE->setText(QString::number(res, 'f', 1));
    }
    GetPEQitemData(ui->itemListWidget->currentRow())->fIrLow = res;
}

void programDialog::on_peqTestValHighLE_textEdited(const QString &arg1)
{
    if(arg1.length() <= 0)
        return;
    float res = arg1.toFloat();
    if(res < m_Validator.peqResMin)
    {
        res = m_Validator.peqResMin;
        ui->peqTestValHighLE->setText(QString::number(res, 'f', 1));
    }
    else if(res > m_Validator.peqResMax)
    {
        res = m_Validator.peqResMax;
        ui->peqTestValHighLE->setText(QString::number(res, 'f', 1));
    }
    GetPEQitemData(ui->itemListWidget->currentRow())->fIrHigh = res;
}

void programDialog::on_peqTestCompLE_textEdited(const QString &arg1)
{
    if(arg1.length() <= 0)
        return;
    int comp = arg1.toInt();
    if(comp < m_Validator.peqCompMin)
    {
        comp = m_Validator.peqCompMin;
        ui->peqTestCompLE->setText(QString::number(comp));
    }
    else if(comp > m_Validator.peqCompMax)
    {
        comp = m_Validator.peqCompMax;
        ui->peqTestCompLE->setText(QString::number(comp));
    }
    GetPEQitemData(ui->itemListWidget->currentRow())->fComp = comp;
}

void programDialog::on_peqTestTimeLE_textEdited(const QString &arg1)
{
    if(arg1.length() <= 0)
        return;
    float time = arg1.toFloat();
    if(time < m_Validator.peqTimeMin)
    {
        time = m_Validator.peqTimeMin;
        ui->peqTestTimeLE->setText(QString::number(time, 'f', 1));
    }
    else if(time > m_Validator.peqTimeMax)
    {
        time = m_Validator.peqTimeMax;
        ui->peqTestTimeLE->setText(QString::number(time, 'f', 1));
    }
    GetPEQitemData(ui->itemListWidget->currentRow())->fTestTime = time;
}

void programDialog::loadTestData()
{
    while(ui->itemListWidget->rowCount() > 0)
        ui->itemListWidget->removeRow(0);
    if(m_JsonData.testItemData.canConvert<TestGroupData>())
    {
        int rowCnt = 0;
        foreach(const auto &item, m_JsonData.testItemData.value<TestGroupData>().testDataList)
        {
            ui->itemListWidget->insertRow(rowCnt);
            ui->itemListWidget->setItem(rowCnt, 0, new QTableWidgetItem(QString::number(rowCnt + 1)));
            if(item.testItemType == TEST_ITEM::ENM_ITEM_IR)
            {
                ui->itemListWidget->setItem(rowCnt, 1, new QTableWidgetItem(m_ItemNameMap.value(TEST_ITEM::ENM_ITEM_IR)));
            }
            else
            {
                ui->itemListWidget->setItem(rowCnt, 1, new QTableWidgetItem(m_ItemNameMap.value(TEST_ITEM::ENM_ITEM_PEQ)));
            }
            rowCnt++;
        }
        loadCommonData(m_JsonData.testItemData.value<TestGroupData>().testGroupData);
    }
}

void programDialog::loadCommonData(const GroupData &p_data)
{
    ui->freqLE->setText(QString::number(p_data.nVoltFreq));
    ui->failstepCBox->setCurrentIndex(p_data.nFailStep);
    ui->powerCBox->setCurrentIndex(p_data.nPowerType);
    ui->groupConnCBox->setCurrentIndex(p_data.nGroupConnect);
}

void programDialog::selectRow(const int p_row)
{
    if(p_row >= ui->itemListWidget->rowCount() || p_row < 0)
        return;
    TestGroupData testGroupData = m_JsonData.testItemData.value<TestGroupData>();
    ui->itemListWidget->selectRow(p_row);
    m_nLastListRow = p_row;
    if(testGroupData.testDataList.at(p_row).testItemType == TEST_ITEM::ENM_ITEM_IR)
    {
        ui->itemStackedWidget->setCurrentIndex(ENM_PAGE_IR);
        IrTestData irData = testGroupData.testDataList.at(p_row).testData.value<IrTestData>();
        ui->irTestSetLE->setText(QString::number(irData.fVolt));
        ui->irTestModeCBox->setCurrentIndex(irData.nConnectMode);
        ui->irTestValLowLE->setText(QString::number(irData.fIrLow));
        ui->irTestValHighLE->setText(QString::number(irData.fIrHigh));
        ui->irTestCompLE->setText(QString::number(irData.fComp));
        ui->irTestTimeLE->setText(QString::number(irData.fTestTime));
    }
    else if(testGroupData.testDataList.at(p_row).testItemType == TEST_ITEM::ENM_ITEM_PEQ)
    {
        ui->itemStackedWidget->setCurrentIndex(ENM_PAGE_PEQ);
        PeqTestData peqData = testGroupData.testDataList.at(p_row).testData.value<PeqTestData>();
        ui->peqTestSetLE->setText(QString::number(peqData.fCurrent));
        ui->peqTestModeCBox->setCurrentIndex(peqData.nConnectMode);
        ui->peqTestValLowLE->setText(QString::number(peqData.fIrLow));
        ui->peqTestValHighLE->setText(QString::number(peqData.fIrHigh));
        ui->peqTestCompLE->setText(QString::number(peqData.fComp));
        ui->peqTestTimeLE->setText(QString::number(peqData.fTestTime));
    }
    else
        return;
}

void programDialog::clearAll()
{
    //ui->itemListWidget->clear();
    while(ui->itemListWidget->rowCount() > 0)
        ui->itemListWidget->removeRow(0);
    ui->itemStackedWidget->setCurrentIndex((int)TEST_ITEM::ENM_ITEM_UNKNOWN);
    ui->filenameLE->setText("");
    m_JsonData.testItemType = JSON_STRUCTTYPE::ENM_ITEM_TEST;
    TestGroupData TestGroupData;
    groupDefault(&(TestGroupData.testGroupData));
    loadCommonData(TestGroupData.testGroupData);
    TestGroupData.testDataList.clear();
    m_JsonData.testItemData.setValue(TestGroupData);
}

IrTestData * programDialog::GetIRtemData(const int p_row)
{
    if(m_JsonData.testItemData.canConvert<TestGroupData>())
    {
        TestGroupData *pTestGroupData = reinterpret_cast<TestGroupData *>(m_JsonData.testItemData.data());
        if(pTestGroupData->testDataList.size() < p_row)
            return nullptr;
        else if(pTestGroupData->testDataList.size() == p_row)
        {
            IrTestData irData;
            TestStepData irStepData;
            irStepData.testItemType = TEST_ITEM::ENM_ITEM_IR;
            irDefault(&irData);
            irStepData.testData.setValue(irData);
            pTestGroupData->testDataList.append(irStepData);
            return reinterpret_cast<IrTestData *>(pTestGroupData->testDataList[p_row].testData.data());
        }
        else
        {
            if(pTestGroupData->testDataList[p_row].testData.canConvert<IrTestData>())
            {
                return reinterpret_cast<IrTestData *>(pTestGroupData->testDataList[p_row].testData.data());
            }
            else
                return nullptr;
        }
    }
    else
    {
        m_JsonData.testItemType == JSON_STRUCTTYPE::ENM_ITEM_TEST;
        TestGroupData groupData;
        groupDefault(&(groupData.testGroupData));
        IrTestData irData;
        TestStepData irStepData;
        irStepData.testItemType = TEST_ITEM::ENM_ITEM_IR;
        irDefault(&irData);
        irStepData.testData.setValue(irData);
        groupData.testDataList.append(irStepData);
        m_JsonData.testItemData.setValue(groupData);
        return reinterpret_cast<IrTestData *>(reinterpret_cast<TestGroupData *>(m_JsonData.testItemData.data())->testDataList[0].testData.data());
    }
}

PeqTestData * programDialog::GetPEQitemData(const int p_row)
{
    if(m_JsonData.testItemData.canConvert<TestGroupData>())
    {
        TestGroupData *pTestGroupData = reinterpret_cast<TestGroupData *>(m_JsonData.testItemData.data());
        if(pTestGroupData->testDataList.size() < p_row)
            return nullptr;
        else if(pTestGroupData->testDataList.size() == p_row)
        {
            PeqTestData peqData;
            TestStepData peqStepData;
            peqStepData.testItemType = TEST_ITEM::ENM_ITEM_IR;
            peqDefault(&peqData);
            peqStepData.testData.setValue(peqData);
            pTestGroupData->testDataList.append(peqStepData);
            return reinterpret_cast<PeqTestData *>(pTestGroupData->testDataList[p_row].testData.data());
        }
        else
        {
            if(pTestGroupData->testDataList[p_row].testData.canConvert<PeqTestData>())
            {
                return reinterpret_cast<PeqTestData *>(pTestGroupData->testDataList[p_row].testData.data());
            }
            else
                return nullptr;
        }
    }
    else
    {
        m_JsonData.testItemType == JSON_STRUCTTYPE::ENM_ITEM_TEST;
        TestGroupData groupData;
        groupDefault(&(groupData.testGroupData));
        PeqTestData peqData;
        TestStepData peqStepData;
        peqStepData.testItemType = TEST_ITEM::ENM_ITEM_IR;
        peqDefault(&peqData);
        peqStepData.testData.setValue(peqData);
        groupData.testDataList.append(peqStepData);
        m_JsonData.testItemData.setValue(groupData);
        return reinterpret_cast<PeqTestData *>(reinterpret_cast<TestGroupData *>(m_JsonData.testItemData.data())->testDataList[0].testData.data());
    }
}

void programDialog::irDefault(IrTestData *p_TestData)
{
    p_TestData->fVolt = 0.5;
    p_TestData->nConnectMode = 0;
    p_TestData->fIrLow = 50;
    p_TestData->fIrHigh = 10000.0;
    p_TestData->fTestTime = 1.0;
    p_TestData->fComp = 55000;
}

void programDialog::peqDefault(PeqTestData *p_TestData)
{
    p_TestData->fCurrent = 5.0;
    p_TestData->nConnectMode = 0;
    p_TestData->fIrLow = 0.0;
    p_TestData->fIrHigh = 600.0;
    p_TestData->fTestTime = 1.0;
    p_TestData->fComp = 0;
}

void programDialog::groupDefault(GroupData *p_GroupData)
{
    p_GroupData->nVoltFreq = 50;
    p_GroupData->nFailStep = 1;
    p_GroupData->nPowerType = 0;
    p_GroupData->nGroupConnect = 0;
}

void programDialog::initValidator()
{
    m_Validator.irVoltMin = 0.1;
    m_Validator.irVoltMax = 1.0;
    m_Validator.irResMin = 0;
    m_Validator.irResMax = 55000;
    m_Validator.irCompMin = 0;
    m_Validator.irCompMax = 55000;
    m_Validator.irTimeMin = 0.1;
    m_Validator.irTimeMax = 999.9;
    m_Validator.peqCurrentMin = 0.1;
    m_Validator.peqCurrentMax = 32.0;
    m_Validator.peqResMin = 0;
    m_Validator.peqResMax = 1000;
    m_Validator.peqCompMin = 0;
    m_Validator.peqCompMax = 100;
    m_Validator.peqTimeMin = 0.1;
    m_Validator.peqTimeMax = 999.9;
}

void programDialog::on_itemTreeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    int rowCnt = ui->itemListWidget->rowCount();
    if(rowCnt >= DEF_TESTITEM_MAX - 1)
    {
        QMessageBox::information(this, "错误", "无法超出最大测试项数", QMessageBox::Yes);
        return;
    }
    if(rowCnt < 0)
        rowCnt = 0;
    TestGroupData *pTestGroupData = nullptr;

    if(!m_JsonData.testItemData.canConvert<TestGroupData>())
    {
        TestGroupData TestGroupData;
        m_JsonData.testItemData.setValue(TestGroupData);
    }
    pTestGroupData = reinterpret_cast<TestGroupData *>(m_JsonData.testItemData.data());
    TestStepData stepData;
    if(item->text(column).contains("绝缘"))
    {
        stepData.testItemType = TEST_ITEM::ENM_ITEM_IR;
        ui->itemListWidget->insertRow(rowCnt);
        ui->itemListWidget->setItem(rowCnt, 0, new QTableWidgetItem(QString::number(rowCnt + 1)));
        ui->itemListWidget->setItem(rowCnt, 1, new QTableWidgetItem(m_ItemNameMap.value(TEST_ITEM::ENM_ITEM_IR)));
        IrTestData TestData;
        irDefault(&TestData);
        stepData.testData.setValue(TestData);
        pTestGroupData->testDataList.append(stepData);
        selectRow(rowCnt);
    }
    else if(item->text(column).contains("电位均衡"))
    {
        stepData.testItemType = TEST_ITEM::ENM_ITEM_PEQ;
        ui->itemListWidget->insertRow(rowCnt);
        ui->itemListWidget->setItem(rowCnt, 0, new QTableWidgetItem(QString::number(rowCnt + 1)));
        ui->itemListWidget->setItem(rowCnt, 1, new QTableWidgetItem(m_ItemNameMap.value(TEST_ITEM::ENM_ITEM_PEQ)));
        PeqTestData TestData;
        peqDefault(&TestData);
        stepData.testData.setValue(TestData);
        pTestGroupData->testDataList.append(stepData);
        selectRow(rowCnt);
    }
    else
        return;
}

void programDialog::on_freqLE_textEdited(const QString &arg1)
{
    //TestGroupData *pTestData = reinterpret_cast<TestGroupData*>(m_JsonData.testItemData.data());
    //pTestData->testGroupData.nVoltFreq = arg1.toInt();
}

void programDialog::on_failstepCBox_activated(int index)
{
    //TestGroupData *pTestData = reinterpret_cast<TestGroupData*>(m_JsonData.testItemData.data());
    //pTestData->testGroupData.nFailStep = index;
}

void programDialog::on_powerCBox_activated(int index)
{
    //TestGroupData *pTestData = reinterpret_cast<TestGroupData*>(m_JsonData.testItemData.data());
    //pTestData->testGroupData.nPowerType = index;
}

void programDialog::on_groupConnCBox_activated(int index)
{
    //TestGroupData *pTestData = reinterpret_cast<TestGroupData*>(m_JsonData.testItemData.data());
    //pTestData->testGroupData.nGroupConnect = index;
}
