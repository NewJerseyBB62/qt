#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenuBar>
#include <QStatusBar>
#include <QToolBar>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_SettingObj(nullptr),
    m_DataObj(nullptr)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setWindowState(Qt::WindowMaximized);
    //QMenuBar *menubar = new QMenuBar(this);
    //this->setMenuBar(menubar);
    QStatusBar *statusBar = new QStatusBar(this);
    this->setStatusBar(statusBar);
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setVisible(true);
    //ui->tableWidget->verticalHeader()->setDefaultSectionSize(30);
    ui->tableWidget->horizontalHeader()->setFixedHeight(40);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);//只能单选
    ui->tableWidget->setFocusPolicy(Qt::NoFocus);
    ui->tableWidget->setAlternatingRowColors(true);
    //QToolBar *tooBar = new QToolBar(this);
    //this->addToolBar(tooBar);
}

MainWindow::~MainWindow()
{
    delete ui;
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
