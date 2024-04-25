#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenuBar>
#include <QStatusBar>
#include <QToolBar>
#include <QGridLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_SettingObj(nullptr),
    m_DataObj(nullptr),
    m_DbObj(nullptr)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setWindowState(Qt::WindowMaximized);
    //QMenuBar *menubar = new QMenuBar(this);
    //this->setMenuBar(menubar);
    //QStatusBar *statusBar = new QStatusBar(this);
    //this->setStatusBar(statusBar);
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setVisible(true);
    //ui->tableWidget->verticalHeader()->setDefaultSectionSize(30);
    ui->tableWidget->horizontalHeader()->setFixedHeight(40);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);//只能单选
    ui->tableWidget->setFocusPolicy(Qt::NoFocus);
    ui->tableWidget->setAlternatingRowColors(true);
    ui->tabWidget->removeTab(2);
    m_DbObj = new DbOperation();
    m_DbObj->openDb("database.db");
    m_DbObj->initDb("TestParameter");
    m_DbObj->closeDb();
    //QToolBar *tooBar = new QToolBar(this);
    //this->addToolBar(tooBar);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_DbObj;
    m_DbObj = nullptr;
}

void MainWindow::initUI()
{
    int i = 0;
    int row = 0;
    int col = 0;
    QList<bool> testParamStatus;
    m_DbObj->openDb("database.db");
    m_DbObj->setTestParamTable(DB_OPERATION::ENM_DB_SELECT, &testParamStatus, nullptr);
    QGridLayout *pLayout = dynamic_cast<QGridLayout*>(ui->tab1_1->layout());
    ui->tab1_1->layout();
    foreach(bool temp, testParamStatus)
    {
        if(temp)
        {
            row = i / 2;
            col = i % 2;
            QLabel *pLabel = new QLabel(ui->tab1_1);
            pLabel->setMaximumWidth(300);
            pLabel->setMinimumHeight(40);
            pLabel->setMaximumHeight(40);
            pLabel->setAlignment(Qt::AlignRight | Qt::AlignHCenter);
            pLabel->setText(m_TestParamName[i + 1] + ":");
            //pLabel->setGeometry(100, 10 + 40 * i, 100, 40);
            QLineEdit *pLE = new QLineEdit(ui->tab1_1);
            pLE->setMaximumWidth(300);
            pLE->setMinimumHeight(40);
            pLE->setMaximumHeight(40);
            //pLE->setGeometry(300, 10 + 40 * i, 100, 40);
            pLayout->addWidget(pLabel, row, col * 2);
            pLayout->addWidget(pLE, row, col * 2 + 1);
            i++;
        }

    }
    ui->tab1_1->setLayout(pLayout);

}

void MainWindow::initTestParamName()
{
    int i = 1;
    m_TestParamName[i++] = "电压";
    m_TestParamName[i++] = "电流";
    m_TestParamName[i++] = "有功功率";
    m_TestParamName[i++] = "无功功率";
    m_TestParamName[i++] = "视在功率";
    m_TestParamName[i++] = "功率因数";
    m_TestParamName[i++] = "角度";
    m_TestParamName[i++] = "电压频率";
    m_TestParamName[i++] = "电压正峰值";
    m_TestParamName[i++] = "电压负峰值";
    m_TestParamName[i++] = "电流正峰值";
    m_TestParamName[i++] = "电流负峰值";
    m_TestParamName[i++] = "功率正峰值";
    m_TestParamName[i++] = "功率负峰值";
    m_TestParamName[i++] = "电能量计时";
    m_TestParamName[i++] = "超阈值电能量计时";
    m_TestParamName[i++] = "电能量正";
    m_TestParamName[i++] = "电能量负";
    m_TestParamName[i++] = "电能量";
    m_TestParamName[i++] = "电流积分";
    m_TestParamName[i++] = "电流积分正";
    m_TestParamName[i++] = "电流积分负";
}

void MainWindow::on_closeBtn_clicked()
{
    exit(0);
}

void MainWindow::on_dataBtn_clicked()
{
    m_DataObj = new DataDialog();
    m_DataObj->exec();
    delete m_DataObj;
    m_DataObj = nullptr;
}

void MainWindow::on_settingBtn_clicked()
{
    m_SettingObj = new SettingDialog();
    m_SettingObj->exec();
    delete m_SettingObj;
    m_SettingObj = nullptr;
}

void MainWindow::on_minBtn_clicked()
{
    this->setWindowState(Qt::WindowMinimized);
}

void MainWindow::on_maxBtn_clicked()
{
    this->setWindowState(Qt::WindowMaximized);
}
