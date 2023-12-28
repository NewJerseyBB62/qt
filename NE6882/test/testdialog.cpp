#include "testdialog.h"
#include "ui_testdialog.h"
#include <QFileInfo>
#include <QMessageBox>
#include <QFileDialog>
#include <windows.h>

testDialog::testDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::testDialog),
    m_Thread(nullptr),
    m_ThreadObj(nullptr)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    //this->showMaximized();
    this->showFullScreen();
    qRegisterMetaType<NE6882Msg>("NE6882Msg");

    ui->testTableWidget->setColumnWidth(0, 40);
    ui->testTableWidget->setColumnWidth(1, 100);
    ui->testTableWidget->setColumnWidth(2, 100);
    ui->testTableWidget->setColumnWidth(3, 100);
    ui->infoTableWidget->setColumnWidth(0, 85);
    ui->infoTableWidget->setColumnWidth(1, 85);
    ui->infoTableWidget->setColumnWidth(2, 80);

    m_ItemNameMap.insert(TEST_ITEM::ENM_ITEM_IR, QStringLiteral("绝缘"));
    m_ItemNameMap.insert(TEST_ITEM::ENM_ITEM_PEQ, QStringLiteral("电位均衡"));
    m_TeststateMap.insert(NE6882_STATE::STATE_STEP_TESTING, QStringLiteral("测试中"));
    m_TeststateMap.insert(NE6882_STATE::STATE_STEP_OK, QStringLiteral("合格"));
    m_TeststateMap.insert(NE6882_STATE::STATE_STEP_NG, QStringLiteral("不合格"));
    m_TeststateMap.insert(NE6882_STATE::STATE_STEP_NULL, QStringLiteral("测试完成"));
    m_TeststateMap.insert(NE6882_STATE::STATE_GROUP_STEP, QStringLiteral("暂停"));
    ui->testTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->testTableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->infoTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->infoTableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    //QFont font = ui->testTableWidget->horizontalHeader()->font();
    QFont font = ui->testTableWidget->font();
    font.setPixelSize(18);
    ui->testTableWidget->horizontalHeader()->setFont(font);
    //font = ui->infoTableWidget->horizontalHeader()->font();
    font = ui->infoTableWidget->font();
    font.setPixelSize(14);
    ui->infoTableWidget->horizontalHeader()->setFont(font);
}

testDialog::~testDialog()
{
    closeThread();
    if(ui->testfileValLab->text().length() > 0)
    {
        QString path("./systemsetting.json");
        QString lastPath("../json/");
        lastPath += ui->testfileValLab->text();
        if(!m_SysData.testItemData.canConvert<SystemData>())
            return;
        SystemData *pSysData = reinterpret_cast<SystemData *>(m_SysData.testItemData.data());
        pSysData->szTestfilePath = lastPath;
        jsonOperation jsonObj;
        jsonObj.writeJsonfile(path, m_SysData);
    }
    delete ui;
}

void testDialog::slotRecv(const NE6882Msg p_data)
{
    switch(p_data.cmdType)
    {
        case NE6882_CMD::CMD_GET_IR:
        case NE6882_CMD::CMD_GET_PEQ:
            if(m_ResultList.size() <= p_data.nStepNo)
                m_ResultList.append(p_data);
            updateTestdata(p_data);
            break;
        default:
            break;
    }
}

void testDialog::on_minBtn_clicked()
{
    this->showMinimized();
}

void testDialog::on_closeBtn_clicked()
{
    done(Rejected);
    close();
}

void testDialog::on_starttestBtn_clicked()
{
    NE6882Msg msg;
    msg.cmdType = NE6882_CMD::CMD_START;
    msg.msgType = DEF_MSGTYPE_REQUEST;
    emit sigSendCmd(msg);
    ui->testTableWidget->selectRow(0);
    m_ResultList.clear();
    clearTestdata();
}

void testDialog::on_stoptestBtn_clicked()
{
    NE6882Msg msg;
    msg.cmdType = NE6882_CMD::CMD_STOP;
    msg.msgType = DEF_MSGTYPE_REQUEST;
    emit sigSendCmd(msg);
}

int testDialog::initTest()
{
    QFileInfo info("./systemsetting.json");
    if(!info.isFile())
        return DEF_JSONERROR_OPEN;
    enableBtn(false);
    jsonOperation jsonObj;
    jsonObj.readJsonfile(info.filePath(), m_SysData);
    if(!m_SysData.testItemData.canConvert<SystemData>())
    {
        enableBtn(false);
        return DEF_JSONERROR_OPEN;
    }
    SystemData sysData = m_SysData.testItemData.value<SystemData>();
    m_currentFile = sysData.szTestfilePath;
    QFileInfo testInfo(m_currentFile);
    if(testInfo.isFile())
        ui->testfileValLab->setText(testInfo.fileName());
    else
        m_currentFile = "";
    if(sysData.strSerialPort.length() <= 0 || sysData.nBaudrate < 4800)
    {
        enableBtn(false);
        QMessageBox::information(this, "错误", "串口配置错误", QMessageBox::Yes);
        return DEF_JSONERROR_OPEN;
    }
    m_Thread = new QThread();
    m_ThreadObj = new TestThread();
    m_ThreadObj->moveToThread(m_Thread);
    connect(this, &testDialog::sigStartRun, m_ThreadObj, &TestThread::slotStartRun, Qt::QueuedConnection);
    connect(this, &testDialog::sigStopRun, m_ThreadObj, &TestThread::slotStopRun, Qt::QueuedConnection);
    connect(this, &testDialog::sigSendCmd, m_ThreadObj, &TestThread::slotSendCmd, Qt::QueuedConnection);
    connect(m_ThreadObj, &TestThread::sigRecv, this, &testDialog::slotRecv, Qt::QueuedConnection);
    m_Thread->start();
    if(m_ThreadObj->initThread(sysData.strSerialPort, sysData.nBaudrate, 500) != 0)
    {
        m_Thread->quit();
        m_Thread->wait();
        delete m_Thread;
        m_Thread = nullptr;
        delete m_ThreadObj;
        m_ThreadObj = nullptr;
        enableBtn(false);
        QMessageBox::information(this, "错误", "串口打开失败", QMessageBox::Yes);
        return DEF_JSONERROR_OPEN;
    }
    emit sigStartRun();

    setTestSet();
    jsonObj.readJsonfile(m_currentFile, m_TestData);
    loadTestList();
    setTestGroup();
    Sleep(300);
    enableBtn(true);
    //connect(m_SerialObj, &QSerialPort::readyRead, this, &SerialThread::SlotRecvData);
}

void testDialog::closeThread()
{
    if(m_ThreadObj != nullptr)
    {
        m_ThreadObj->closeThread();
        m_Thread->quit();
        m_Thread->wait();
        delete m_Thread;
        m_Thread = nullptr;
        delete m_ThreadObj;
        m_ThreadObj = nullptr;
    }
}

void testDialog::setTestSet()
{
    if(m_ThreadObj != nullptr && m_TestData.testItemData.canConvert<TestGroupData>())
    {
        NE6882Msg msg;
        msg.cmdType = NE6882_CMD::CMD_SET;
        msg.msgType = DEF_MSGTYPE_REQUEST;
        msg.nFailStep = m_TestData.testItemData.value<TestGroupData>().testGroupData.nFailStep;
        emit sigSendCmd(msg);
    }
}

void testDialog::setTestGroup()
{
    if(m_ThreadObj != nullptr && m_TestData.testItemData.canConvert<TestGroupData>())
    {
        NE6882Msg msg;
        msg.msgType = DEF_MSGTYPE_REQUEST;
        int num = m_TestData.testItemData.value<TestGroupData>().testDataList.size();
        for(int i = 0; i < num; i++)
        {
            int nRet = Json2Msg(m_TestData.testItemData.value<TestGroupData>().testDataList.at(i).testData,
                     msg);
            if(nRet == 0)
                emit sigSendCmd(msg);
        }
    }
}

int testDialog::Json2Msg(const QVariant &p_src,  NE6882Msg &p_data)
{
     if(p_src.canConvert<IrTestData>())
     {
         IrTestData currData = p_src.value<IrTestData>();
         p_data.cmdType = NE6882_CMD::CMD_SET_IR;
         p_data.fVolt = currData.fVolt;
         p_data.nConnectMode = currData.nConnectMode;
         p_data.fIrLow = currData.fIrLow;
         p_data.fIrHigh = currData.fIrHigh;
         p_data.fComp = currData.fComp;
         p_data.fTestTime = currData.fTestTime;
     }
     else if(p_src.canConvert<PeqTestData>())
     {
         PeqTestData currData = p_src.value<PeqTestData>();
         p_data.cmdType = NE6882_CMD::CMD_SET_PEQ;
         p_data.fCurrent = currData.fCurrent;
         p_data.nConnectMode = currData.nConnectMode;
         p_data.fIrLow = currData.fIrLow;
         p_data.fIrHigh = currData.fIrHigh;
         p_data.fComp = currData.fComp;
         p_data.fTestTime = currData.fTestTime;
     }
     else
         return 1;
     return 0;
}

void testDialog::loadTestList()
{
    ui->testTableWidget->clear();
    while(ui->testTableWidget->rowCount() > 0)
        ui->testTableWidget->removeRow(0);
    initHorHead();
    if(!m_TestData.testItemData.canConvert<TestGroupData>())
        return;
    int num = m_TestData.testItemData.value<TestGroupData>().testDataList.size();
    for(int i = 0; i < num; i++)
    {
        TEST_ITEM testType = m_TestData.testItemData.value<TestGroupData>().testDataList.at(i).testItemType;
        ui->testTableWidget->insertRow(i);
        ui->testTableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(i + 1)));
        ui->testTableWidget->setItem(i, 1, new QTableWidgetItem(m_ItemNameMap.value(testType)));
        ui->testTableWidget->setItem(i, 2, new QTableWidgetItem(""));
        ui->testTableWidget->setItem(i, 3, new QTableWidgetItem(""));
    }
    loadGroupData();
}

void testDialog::loadGroupData()
{
    if(!m_TestData.testItemData.canConvert<TestGroupData>())
        return;
    QString failStep = m_TestData.testItemData.value<TestGroupData>().testGroupData.nFailStep == 1 ? "继续" : "停止";
    ui->infoTableWidget->setItem(0, 1, new QTableWidgetItem(QString::number(
         m_TestData.testItemData.value<TestGroupData>().testGroupData.nVoltFreq)));
    ui->infoTableWidget->setItem(1, 1, new QTableWidgetItem(failStep));
    ui->infoTableWidget->setItem(2, 1, new QTableWidgetItem("单相"));
    ui->infoTableWidget->setItem(3, 1, new QTableWidgetItem("关"));
}

int testDialog::setTestGroupData()
{
    if(!m_TestData.testItemData.canConvert<TestGroupData>())
        return 1;
    int num = m_TestData.testItemData.value<TestGroupData>().testDataList.size();
    for(int i = 0; i < num; i++)
    {
        ui->testTableWidget->insertRow(i);
        ui->testTableWidget->setItem(i, 0, new QTableWidgetItem(""));
        ui->testTableWidget->setItem(i, 1, new QTableWidgetItem(m_ItemNameMap.value(TEST_ITEM::ENM_ITEM_IR)));
        ui->testTableWidget->setItem(i, 2, new QTableWidgetItem(""));
        ui->testTableWidget->setItem(i, 3, new QTableWidgetItem(""));
    }
}

void testDialog::enableBtn(const bool &p_enable)
{
    ui->starttestBtn->setDisabled(!p_enable);
    ui->openfileBtn->setDisabled(!p_enable);
    ui->stoptestBtn->setDisabled(!p_enable);
    ui->testTableWidget->setDisabled(!p_enable);
}

void testDialog::updateTestdata(const NE6882Msg &p_data)
{
    ui->testTableWidget->selectRow(p_data.nStepNo);
    if(p_data.cmdType == NE6882_CMD::CMD_GET_IR)
    {
        int nVolt = p_data.fVolt * 1000;
        ui->outputValLab->setText(QString::number(nVolt));
        ui->outputUnitLab->setText("V");
        ui->testoutValLab->setText(QString::number(p_data.fTestVal, 'g', 3));
        ui->testoutUnitLab->setText("Mohm");
        ui->testtimeValLab->setText(QString::number(p_data.fTestTime, 'g', 1));
        ui->teststateLab->setText(m_TeststateMap.value(p_data.testState));
    }
    else if(p_data.cmdType == NE6882_CMD::CMD_GET_PEQ)
    {
        ui->outputValLab->setText(QString::number(p_data.fCurrent, 'g', 3));
        ui->outputUnitLab->setText("A");
        ui->testoutValLab->setText(QString::number(p_data.fTestVal, 'g', 3));
        ui->testoutUnitLab->setText("mohm");
        ui->testtimeValLab->setText(QString::number(p_data.fTestTime, 'g', 1));
        ui->teststateLab->setText(m_TeststateMap.value(p_data.testState));
    }
    if(p_data.testState == NE6882_STATE::STATE_STEP_TESTING)
    {
        ui->testTableWidget->setItem(p_data.nStepNo, 2, new QTableWidgetItem(
                                         m_TeststateMap.value(NE6882_STATE::STATE_STEP_TESTING)));
        ui->testTableWidget->setItem(p_data.nStepNo, 3, new QTableWidgetItem(""));
    }
    else if(p_data.groupState == NE6882_STATE::STATE_STEP_NG)
    {
        if(p_data.groupState == NE6882_STATE::STATE_GROUP_STEP)
        {
            ui->testTableWidget->setItem(p_data.nStepNo, 2, new QTableWidgetItem(
                                             m_TeststateMap.value(NE6882_STATE::STATE_GROUP_STEP)));
        }
        ui->testTableWidget->setItem(p_data.nStepNo, 3, new QTableWidgetItem(
                                         m_TeststateMap.value(NE6882_STATE::STATE_STEP_NG)));
    }
    else if(p_data.groupState == NE6882_STATE::STATE_STEP_OK)
    {
        if(p_data.groupState == NE6882_STATE::STATE_GROUP_STEP)
        {
            ui->testTableWidget->setItem(p_data.nStepNo, 2, new QTableWidgetItem(
                                             m_TeststateMap.value(NE6882_STATE::STATE_GROUP_STEP)));
        }
        ui->testTableWidget->setItem(p_data.nStepNo, 3, new QTableWidgetItem(
                                         m_TeststateMap.value(NE6882_STATE::STATE_STEP_OK)));
    }
}

void testDialog::selectRow(const int p_row)
{
    if(ui->testTableWidget->rowCount() <= 0 || p_row >= ui->testTableWidget->rowCount())
        return;
    ui->testTableWidget->selectRow(p_row);
    if(m_ResultList.size() <= 0)
        clearTestdata();
    else
        updateTestdata(m_ResultList.at(p_row));
}

void testDialog::clearTestdata()
{
    ui->outputValLab->setText("");
    ui->outputUnitLab->setText("");
    ui->testoutValLab->setText("");
    ui->testoutUnitLab->setText("");
    ui->testtimeValLab->setText("");
    ui->teststateLab->setText("");
}

void testDialog::initHorHead()
{
    QStringList head;
    head <<"序号"<<"测试项目"<<"测试状态"<<"测试结果";
    ui->testTableWidget->setHorizontalHeaderLabels(head);
}

void testDialog::on_openfileBtn_clicked()
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
    int nRet = jsonObj.readJsonfile(filename, m_TestData);
    if(nRet != 0)
    {
        return;
    }
    QFileInfo fileInfo(filename);
    ui->testfileValLab->setText(fileInfo.fileName());
    loadTestList();
    if(m_TestData.testItemData.value<TestGroupData>().testDataList.size() > 0)
    {
        selectRow(0);
    }
}

void testDialog::on_testTableWidget_clicked(const QModelIndex &index)
{
    selectRow(index.row());
}
