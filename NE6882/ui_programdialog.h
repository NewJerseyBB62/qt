/********************************************************************************
** Form generated from reading UI file 'programdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRAMDIALOG_H
#define UI_PROGRAMDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_programDialog
{
public:
    QGridLayout *gridLayout;
    QTableWidget *itemListWidget;
    QStackedWidget *itemStackedWidget;
    QWidget *nullPage;
    QVBoxLayout *verticalLayout_6;
    QWidget *widget;
    QWidget *irPage;
    QVBoxLayout *verticalLayout_7;
    QWidget *iritemWidget;
    QVBoxLayout *verticalLayout;
    QLabel *titleLab;
    QFrame *line;
    QWidget *setirWidget;
    QVBoxLayout *verticalLayout_9;
    QWidget *setItem1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *irTestSetLab;
    QLineEdit *irTestSetLE;
    QLabel *irTestSetUnit;
    QLabel *irTestModeLab;
    QComboBox *irTestModeCBox;
    QLabel *irTestModeLab1;
    QWidget *setItem2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *irTestValLowLab;
    QLineEdit *irTestValLowLE;
    QLabel *irTestValLowUnit;
    QLabel *irTestValHighLab;
    QLineEdit *irTestValHighLE;
    QLabel *irTestValHighUnit;
    QWidget *setItem3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *irTestCompLab;
    QLineEdit *irTestCompLE;
    QLabel *irTestCompUnit;
    QLabel *irTestTimeLab;
    QLineEdit *irTestTimeLE;
    QLabel *irTestTimeUnit;
    QSpacerItem *verticalSpacer;
    QWidget *peqPage;
    QVBoxLayout *verticalLayout_8;
    QWidget *peqitemWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *titleLab2;
    QFrame *line_2;
    QWidget *setpeqWidget;
    QVBoxLayout *verticalLayout_4;
    QWidget *peqItem1;
    QHBoxLayout *horizontalLayout_6;
    QLabel *peqTestSetLab;
    QLineEdit *peqTestSetLE;
    QLabel *peqTestSetUnit;
    QLabel *peqTestModeLab;
    QComboBox *peqTestModeCBox;
    QLabel *Lab;
    QWidget *peqItem2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *peqTestValLowLab;
    QLineEdit *peqTestValLowLE;
    QLabel *peqTestValLowUnit;
    QLabel *peqTestValHighLab;
    QLineEdit *peqTestValHighLE;
    QLabel *peqTestValHighUnit;
    QWidget *peqItem3;
    QHBoxLayout *horizontalLayout_8;
    QLabel *peqTestCompLab;
    QLineEdit *peqTestCompLE;
    QLabel *peqTestCompUnit;
    QLabel *peqTestTimeLab;
    QLineEdit *peqTestTimeLE;
    QLabel *peqTestTimeUnit;
    QSpacerItem *verticalSpacer_2;
    QWidget *btnWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *openfileBtn;
    QPushButton *savefileBtn;
    QPushButton *newfileBtn;
    QPushButton *deletefileBtn;
    QPushButton *topfileBtn;
    QPushButton *downfileBtn;
    QSpacerItem *horizontalSpacer;
    QWidget *infoWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *filenameLab;
    QLineEdit *filenameLE;
    QSpacerItem *horizontalSpacer_2;
    QWidget *taskWidget;
    QPushButton *minBtn;
    QPushButton *closeBtn;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QTreeWidget *itemTreeWidget;
    QWidget *groupWidget;
    QVBoxLayout *verticalLayout_5;
    QWidget *peqItem1_2;
    QHBoxLayout *horizontalLayout_9;
    QLabel *freqLab;
    QLineEdit *freqLE;
    QLabel *pfreqUnit;
    QWidget *peqItem1_3;
    QHBoxLayout *horizontalLayout_10;
    QLabel *failstepLab;
    QComboBox *failstepCBox;
    QWidget *peqItem1_4;
    QHBoxLayout *horizontalLayout_11;
    QLabel *powerLab;
    QComboBox *powerCBox;
    QWidget *peqItem1_5;
    QHBoxLayout *horizontalLayout_12;
    QLabel *groupConnLab;
    QComboBox *groupConnCBox;

    void setupUi(QDialog *programDialog)
    {
        if (programDialog->objectName().isEmpty())
            programDialog->setObjectName(QString::fromUtf8("programDialog"));
        programDialog->resize(1280, 720);
        programDialog->setMinimumSize(QSize(1280, 720));
        programDialog->setStyleSheet(QString::fromUtf8("#programDialog{\n"
"border-image: url(:/icon/bg3.jpg);\n"
"}"));
        gridLayout = new QGridLayout(programDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(5);
        gridLayout->setVerticalSpacing(0);
        gridLayout->setContentsMargins(20, 0, 20, 20);
        itemListWidget = new QTableWidget(programDialog);
        if (itemListWidget->columnCount() < 2)
            itemListWidget->setColumnCount(2);
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        itemListWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        itemListWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        itemListWidget->setObjectName(QString::fromUtf8("itemListWidget"));
        itemListWidget->setMinimumSize(QSize(245, 540));
        itemListWidget->setMaximumSize(QSize(245, 16777215));
        QFont font1;
        font1.setPointSize(14);
        itemListWidget->setFont(font1);
        itemListWidget->setFocusPolicy(Qt::NoFocus);
        itemListWidget->setStyleSheet(QString::fromUtf8("/*\n"
"QTableWidget::item:!alternate:!selected{\n"
"    background-color: white;\n"
"    selection-background-color:#3E66FBDF;  \n"
"}\n"
"QTableWidget::selected{\n"
"	background-color:#3E66FBDF;\n"
"}\n"
"*/\n"
"\n"
"/*\n"
"QTableWidget::item:hover{\n"
"background-color:rgb(92,188,227,200);\n"
"}\n"
"\n"
"QTableWidget::item:selected{\n"
"color:#F4F4F4;\n"
"background-color:#353535;\n"
"}\n"
"\n"
"QTableWidget::selected{\n"
"color:#F4F4F4;\n"
"background-color:#353535;\n"
"}\n"
"QHeaderView::section{\n"
"background-color:#393939;\n"
"}\n"
"QTableWidget{\n"
"color:#C6C6C6;\n"
"background-color:#FFFFFF;\n"
"border:none;\n"
"}\n"
"\n"
"QTableWidget::item{\n"
"    background-color: white;\n"
"    border: none;\n"
"    background-color: #D3D3D3DF; \n"
"    selection-background-color: white;\n"
"    selection-color: black;\n"
"}\n"
"QTableWidget::item:hover{\n"
"	background-color: #3E66FBBF;\n"
"}\n"
"*/\n"
"QTableWidget{\n"
"border-radius: 20px;\n"
"border:none;\n"
"}\n"
"QTableWidget::item:selected{\n"
"	backgroun"
                        "d-color: #E9EFF7;\n"
"}\n"
""));
        itemListWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        itemListWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        itemListWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        itemListWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        itemListWidget->setShowGrid(false);
        itemListWidget->horizontalHeader()->setVisible(true);
        itemListWidget->horizontalHeader()->setHighlightSections(true);
        itemListWidget->verticalHeader()->setVisible(false);

        gridLayout->addWidget(itemListWidget, 2, 0, 2, 1);

        itemStackedWidget = new QStackedWidget(programDialog);
        itemStackedWidget->setObjectName(QString::fromUtf8("itemStackedWidget"));
        itemStackedWidget->setMinimumSize(QSize(760, 540));
        itemStackedWidget->setStyleSheet(QString::fromUtf8("\n"
"\n"
"#itemStackedWidget{\n"
"background-color: rgb(255, 255, 255);\n"
"border: 2px solid rgb(191, 191, 191);\n"
"border-radius: 20px;\n"
"border:none;\n"
"}\n"
"\n"
"QLineEdit{\n"
"color: #424242;\n"
"border: 1px solid #0E55A7;\n"
"border-radius: 5px;\n"
"}\n"
"\n"
"QComboBox{\n"
"color: #424242;\n"
"border: 1px solid #0E55A7;\n"
"border-radius: 5px;\n"
"}\n"
"QComboBox::down-arrow{\n"
"	border-image: url(:/icon/downarrl.png);\n"
"	width: 20px;\n"
"      border:none;\n"
"}\n"
"QComboBox::drop-down {\n"
"      subcontrol-origin: padding;\n"
"      width: 30px;\n"
"      border:none;\n"
"\n"
"}\n"
"QComboBox QAbstractItemView{\n"
"background:rgba(255,255,255,1);\n"
"    border:1px solid #0E55A7;\n"
"    outline: 0px;\n"
"}\n"
"\n"
"QLabel{\n"
"color: #424242;\n"
"}"));
        nullPage = new QWidget();
        nullPage->setObjectName(QString::fromUtf8("nullPage"));
        nullPage->setMinimumSize(QSize(760, 540));
        nullPage->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        verticalLayout_6 = new QVBoxLayout(nullPage);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(nullPage);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(760, 540));

        verticalLayout_6->addWidget(widget);

        itemStackedWidget->addWidget(nullPage);
        irPage = new QWidget();
        irPage->setObjectName(QString::fromUtf8("irPage"));
        irPage->setMinimumSize(QSize(760, 480));
        irPage->setStyleSheet(QString::fromUtf8("#irPage{\n"
"background-color: rgb(255, 255, 255);\n"
"}"));
        verticalLayout_7 = new QVBoxLayout(irPage);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        iritemWidget = new QWidget(irPage);
        iritemWidget->setObjectName(QString::fromUtf8("iritemWidget"));
        iritemWidget->setMinimumSize(QSize(760, 60));
        iritemWidget->setMaximumSize(QSize(16777215, 60));
        verticalLayout = new QVBoxLayout(iritemWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(20, 0, 20, 0);
        titleLab = new QLabel(iritemWidget);
        titleLab->setObjectName(QString::fromUtf8("titleLab"));
        titleLab->setMinimumSize(QSize(720, 55));
        titleLab->setMaximumSize(QSize(16777215, 55));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font2.setPointSize(22);
        font2.setBold(true);
        font2.setWeight(75);
        titleLab->setFont(font2);
        titleLab->setStyleSheet(QString::fromUtf8("QLabel{\n"
"margin-left:20px;\n"
"}"));
        titleLab->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        titleLab->setMargin(0);

        verticalLayout->addWidget(titleLab);

        line = new QFrame(iritemWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setMinimumSize(QSize(720, 5));
        line->setMaximumSize(QSize(16777215, 5));
        line->setStyleSheet(QString::fromUtf8("background-color: #0E55A7;"));
        line->setLineWidth(3);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);


        verticalLayout_7->addWidget(iritemWidget);

        setirWidget = new QWidget(irPage);
        setirWidget->setObjectName(QString::fromUtf8("setirWidget"));
        setirWidget->setMinimumSize(QSize(760, 300));
        setirWidget->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_9 = new QVBoxLayout(setirWidget);
        verticalLayout_9->setSpacing(20);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(10, 40, 10, 0);
        setItem1 = new QWidget(setirWidget);
        setItem1->setObjectName(QString::fromUtf8("setItem1"));
        setItem1->setMinimumSize(QSize(740, 50));
        setItem1->setMaximumSize(QSize(16777215, 50));
        horizontalLayout_3 = new QHBoxLayout(setItem1);
        horizontalLayout_3->setSpacing(10);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        irTestSetLab = new QLabel(setItem1);
        irTestSetLab->setObjectName(QString::fromUtf8("irTestSetLab"));
        irTestSetLab->setMinimumSize(QSize(0, 34));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(14);
        irTestSetLab->setFont(font3);
        irTestSetLab->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(irTestSetLab);

        irTestSetLE = new QLineEdit(setItem1);
        irTestSetLE->setObjectName(QString::fromUtf8("irTestSetLE"));
        irTestSetLE->setMinimumSize(QSize(100, 34));
        irTestSetLE->setMaximumSize(QSize(16777215, 16777215));
        irTestSetLE->setFont(font3);

        horizontalLayout_3->addWidget(irTestSetLE);

        irTestSetUnit = new QLabel(setItem1);
        irTestSetUnit->setObjectName(QString::fromUtf8("irTestSetUnit"));
        irTestSetUnit->setMinimumSize(QSize(0, 34));
        irTestSetUnit->setFont(font3);

        horizontalLayout_3->addWidget(irTestSetUnit);

        irTestModeLab = new QLabel(setItem1);
        irTestModeLab->setObjectName(QString::fromUtf8("irTestModeLab"));
        irTestModeLab->setMinimumSize(QSize(0, 34));
        irTestModeLab->setFont(font3);
        irTestModeLab->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(irTestModeLab);

        irTestModeCBox = new QComboBox(setItem1);
        irTestModeCBox->addItem(QString());
        irTestModeCBox->addItem(QString());
        irTestModeCBox->addItem(QString());
        irTestModeCBox->setObjectName(QString::fromUtf8("irTestModeCBox"));
        irTestModeCBox->setMinimumSize(QSize(100, 34));
        irTestModeCBox->setMaximumSize(QSize(16777215, 16777215));
        irTestModeCBox->setFont(font3);

        horizontalLayout_3->addWidget(irTestModeCBox);

        irTestModeLab1 = new QLabel(setItem1);
        irTestModeLab1->setObjectName(QString::fromUtf8("irTestModeLab1"));
        irTestModeLab1->setMinimumSize(QSize(173, 34));
        irTestModeLab1->setFont(font3);

        horizontalLayout_3->addWidget(irTestModeLab1);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(2, 1);
        horizontalLayout_3->setStretch(3, 1);
        horizontalLayout_3->setStretch(4, 1);
        horizontalLayout_3->setStretch(5, 1);

        verticalLayout_9->addWidget(setItem1);

        setItem2 = new QWidget(setirWidget);
        setItem2->setObjectName(QString::fromUtf8("setItem2"));
        setItem2->setMinimumSize(QSize(740, 50));
        setItem2->setMaximumSize(QSize(16777215, 50));
        horizontalLayout_4 = new QHBoxLayout(setItem2);
        horizontalLayout_4->setSpacing(10);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        irTestValLowLab = new QLabel(setItem2);
        irTestValLowLab->setObjectName(QString::fromUtf8("irTestValLowLab"));
        irTestValLowLab->setMinimumSize(QSize(0, 34));
        irTestValLowLab->setFont(font3);
        irTestValLowLab->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(irTestValLowLab);

        irTestValLowLE = new QLineEdit(setItem2);
        irTestValLowLE->setObjectName(QString::fromUtf8("irTestValLowLE"));
        irTestValLowLE->setMinimumSize(QSize(100, 34));
        irTestValLowLE->setMaximumSize(QSize(16777215, 16777215));
        irTestValLowLE->setFont(font3);

        horizontalLayout_4->addWidget(irTestValLowLE);

        irTestValLowUnit = new QLabel(setItem2);
        irTestValLowUnit->setObjectName(QString::fromUtf8("irTestValLowUnit"));
        irTestValLowUnit->setMinimumSize(QSize(0, 34));
        irTestValLowUnit->setFont(font3);

        horizontalLayout_4->addWidget(irTestValLowUnit);

        irTestValHighLab = new QLabel(setItem2);
        irTestValHighLab->setObjectName(QString::fromUtf8("irTestValHighLab"));
        irTestValHighLab->setMinimumSize(QSize(0, 34));
        irTestValHighLab->setFont(font3);
        irTestValHighLab->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(irTestValHighLab);

        irTestValHighLE = new QLineEdit(setItem2);
        irTestValHighLE->setObjectName(QString::fromUtf8("irTestValHighLE"));
        irTestValHighLE->setMinimumSize(QSize(100, 34));
        irTestValHighLE->setMaximumSize(QSize(16777215, 16777215));
        irTestValHighLE->setFont(font3);

        horizontalLayout_4->addWidget(irTestValHighLE);

        irTestValHighUnit = new QLabel(setItem2);
        irTestValHighUnit->setObjectName(QString::fromUtf8("irTestValHighUnit"));
        irTestValHighUnit->setMinimumSize(QSize(0, 34));
        irTestValHighUnit->setFont(font3);

        horizontalLayout_4->addWidget(irTestValHighUnit);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 1);
        horizontalLayout_4->setStretch(2, 1);
        horizontalLayout_4->setStretch(3, 1);
        horizontalLayout_4->setStretch(4, 1);
        horizontalLayout_4->setStretch(5, 1);

        verticalLayout_9->addWidget(setItem2);

        setItem3 = new QWidget(setirWidget);
        setItem3->setObjectName(QString::fromUtf8("setItem3"));
        setItem3->setMinimumSize(QSize(740, 50));
        setItem3->setMaximumSize(QSize(16777215, 50));
        horizontalLayout_5 = new QHBoxLayout(setItem3);
        horizontalLayout_5->setSpacing(10);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        irTestCompLab = new QLabel(setItem3);
        irTestCompLab->setObjectName(QString::fromUtf8("irTestCompLab"));
        irTestCompLab->setMinimumSize(QSize(0, 34));
        irTestCompLab->setFont(font3);
        irTestCompLab->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(irTestCompLab);

        irTestCompLE = new QLineEdit(setItem3);
        irTestCompLE->setObjectName(QString::fromUtf8("irTestCompLE"));
        irTestCompLE->setMinimumSize(QSize(100, 34));
        irTestCompLE->setMaximumSize(QSize(16777215, 16777215));
        irTestCompLE->setFont(font3);

        horizontalLayout_5->addWidget(irTestCompLE);

        irTestCompUnit = new QLabel(setItem3);
        irTestCompUnit->setObjectName(QString::fromUtf8("irTestCompUnit"));
        irTestCompUnit->setMinimumSize(QSize(0, 34));
        irTestCompUnit->setFont(font3);

        horizontalLayout_5->addWidget(irTestCompUnit);

        irTestTimeLab = new QLabel(setItem3);
        irTestTimeLab->setObjectName(QString::fromUtf8("irTestTimeLab"));
        irTestTimeLab->setMinimumSize(QSize(0, 34));
        irTestTimeLab->setFont(font3);
        irTestTimeLab->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(irTestTimeLab);

        irTestTimeLE = new QLineEdit(setItem3);
        irTestTimeLE->setObjectName(QString::fromUtf8("irTestTimeLE"));
        irTestTimeLE->setMinimumSize(QSize(100, 34));
        irTestTimeLE->setMaximumSize(QSize(16777215, 16777215));
        irTestTimeLE->setFont(font3);

        horizontalLayout_5->addWidget(irTestTimeLE);

        irTestTimeUnit = new QLabel(setItem3);
        irTestTimeUnit->setObjectName(QString::fromUtf8("irTestTimeUnit"));
        irTestTimeUnit->setMinimumSize(QSize(0, 34));
        irTestTimeUnit->setFont(font3);

        horizontalLayout_5->addWidget(irTestTimeUnit);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 1);
        horizontalLayout_5->setStretch(2, 1);
        horizontalLayout_5->setStretch(3, 1);
        horizontalLayout_5->setStretch(4, 1);
        horizontalLayout_5->setStretch(5, 1);

        verticalLayout_9->addWidget(setItem3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer);


        verticalLayout_7->addWidget(setirWidget);

        verticalLayout_7->setStretch(0, 1);
        verticalLayout_7->setStretch(1, 8);
        itemStackedWidget->addWidget(irPage);
        peqPage = new QWidget();
        peqPage->setObjectName(QString::fromUtf8("peqPage"));
        peqPage->setMinimumSize(QSize(760, 480));
        peqPage->setStyleSheet(QString::fromUtf8("#peqPage{\n"
"background-color: rgb(255, 255, 255);\n"
"}"));
        verticalLayout_8 = new QVBoxLayout(peqPage);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        peqitemWidget = new QWidget(peqPage);
        peqitemWidget->setObjectName(QString::fromUtf8("peqitemWidget"));
        peqitemWidget->setMinimumSize(QSize(760, 60));
        peqitemWidget->setMaximumSize(QSize(16777215, 60));
        peqitemWidget->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_3 = new QVBoxLayout(peqitemWidget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(20, 0, 20, 0);
        titleLab2 = new QLabel(peqitemWidget);
        titleLab2->setObjectName(QString::fromUtf8("titleLab2"));
        titleLab2->setMinimumSize(QSize(720, 55));
        titleLab2->setMaximumSize(QSize(16777215, 55));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font4.setPointSize(22);
        font4.setBold(true);
        font4.setItalic(false);
        font4.setWeight(75);
        titleLab2->setFont(font4);
        titleLab2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"margin-left:20px;\n"
"}"));
        titleLab2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        titleLab2->setMargin(0);

        verticalLayout_3->addWidget(titleLab2);

        line_2 = new QFrame(peqitemWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setMinimumSize(QSize(720, 5));
        line_2->setMaximumSize(QSize(16777215, 5));
        line_2->setStyleSheet(QString::fromUtf8("background-color: #0E55A7;"));
        line_2->setLineWidth(2);
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_2);


        verticalLayout_8->addWidget(peqitemWidget);

        setpeqWidget = new QWidget(peqPage);
        setpeqWidget->setObjectName(QString::fromUtf8("setpeqWidget"));
        setpeqWidget->setMinimumSize(QSize(760, 480));
        setpeqWidget->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_4 = new QVBoxLayout(setpeqWidget);
        verticalLayout_4->setSpacing(20);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(10, 40, 10, 0);
        peqItem1 = new QWidget(setpeqWidget);
        peqItem1->setObjectName(QString::fromUtf8("peqItem1"));
        peqItem1->setMinimumSize(QSize(740, 50));
        peqItem1->setMaximumSize(QSize(16777215, 50));
        horizontalLayout_6 = new QHBoxLayout(peqItem1);
        horizontalLayout_6->setSpacing(10);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        peqTestSetLab = new QLabel(peqItem1);
        peqTestSetLab->setObjectName(QString::fromUtf8("peqTestSetLab"));
        peqTestSetLab->setMinimumSize(QSize(0, 34));
        peqTestSetLab->setFont(font3);
        peqTestSetLab->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(peqTestSetLab);

        peqTestSetLE = new QLineEdit(peqItem1);
        peqTestSetLE->setObjectName(QString::fromUtf8("peqTestSetLE"));
        peqTestSetLE->setMinimumSize(QSize(100, 34));
        peqTestSetLE->setMaximumSize(QSize(16777215, 16777215));
        peqTestSetLE->setFont(font3);

        horizontalLayout_6->addWidget(peqTestSetLE);

        peqTestSetUnit = new QLabel(peqItem1);
        peqTestSetUnit->setObjectName(QString::fromUtf8("peqTestSetUnit"));
        peqTestSetUnit->setMinimumSize(QSize(0, 34));
        peqTestSetUnit->setFont(font3);

        horizontalLayout_6->addWidget(peqTestSetUnit);

        peqTestModeLab = new QLabel(peqItem1);
        peqTestModeLab->setObjectName(QString::fromUtf8("peqTestModeLab"));
        peqTestModeLab->setMinimumSize(QSize(0, 34));
        peqTestModeLab->setFont(font3);
        peqTestModeLab->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(peqTestModeLab);

        peqTestModeCBox = new QComboBox(peqItem1);
        peqTestModeCBox->addItem(QString());
        peqTestModeCBox->addItem(QString());
        peqTestModeCBox->addItem(QString());
        peqTestModeCBox->setObjectName(QString::fromUtf8("peqTestModeCBox"));
        peqTestModeCBox->setMinimumSize(QSize(100, 34));
        peqTestModeCBox->setMaximumSize(QSize(16777215, 16777215));
        peqTestModeCBox->setFont(font3);

        horizontalLayout_6->addWidget(peqTestModeCBox);

        Lab = new QLabel(peqItem1);
        Lab->setObjectName(QString::fromUtf8("Lab"));
        Lab->setMinimumSize(QSize(173, 34));
        Lab->setFont(font3);

        horizontalLayout_6->addWidget(Lab);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(1, 1);
        horizontalLayout_6->setStretch(2, 1);
        horizontalLayout_6->setStretch(3, 1);
        horizontalLayout_6->setStretch(4, 1);
        horizontalLayout_6->setStretch(5, 1);

        verticalLayout_4->addWidget(peqItem1);

        peqItem2 = new QWidget(setpeqWidget);
        peqItem2->setObjectName(QString::fromUtf8("peqItem2"));
        peqItem2->setMinimumSize(QSize(740, 50));
        peqItem2->setMaximumSize(QSize(16777215, 50));
        horizontalLayout_7 = new QHBoxLayout(peqItem2);
        horizontalLayout_7->setSpacing(10);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        peqTestValLowLab = new QLabel(peqItem2);
        peqTestValLowLab->setObjectName(QString::fromUtf8("peqTestValLowLab"));
        peqTestValLowLab->setMinimumSize(QSize(0, 34));
        peqTestValLowLab->setFont(font3);
        peqTestValLowLab->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(peqTestValLowLab);

        peqTestValLowLE = new QLineEdit(peqItem2);
        peqTestValLowLE->setObjectName(QString::fromUtf8("peqTestValLowLE"));
        peqTestValLowLE->setMinimumSize(QSize(100, 34));
        peqTestValLowLE->setMaximumSize(QSize(16777215, 16777215));
        peqTestValLowLE->setFont(font3);

        horizontalLayout_7->addWidget(peqTestValLowLE);

        peqTestValLowUnit = new QLabel(peqItem2);
        peqTestValLowUnit->setObjectName(QString::fromUtf8("peqTestValLowUnit"));
        peqTestValLowUnit->setMinimumSize(QSize(0, 34));
        peqTestValLowUnit->setFont(font3);

        horizontalLayout_7->addWidget(peqTestValLowUnit);

        peqTestValHighLab = new QLabel(peqItem2);
        peqTestValHighLab->setObjectName(QString::fromUtf8("peqTestValHighLab"));
        peqTestValHighLab->setMinimumSize(QSize(0, 34));
        peqTestValHighLab->setFont(font3);
        peqTestValHighLab->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(peqTestValHighLab);

        peqTestValHighLE = new QLineEdit(peqItem2);
        peqTestValHighLE->setObjectName(QString::fromUtf8("peqTestValHighLE"));
        peqTestValHighLE->setMinimumSize(QSize(100, 34));
        peqTestValHighLE->setMaximumSize(QSize(16777215, 16777215));
        peqTestValHighLE->setFont(font3);

        horizontalLayout_7->addWidget(peqTestValHighLE);

        peqTestValHighUnit = new QLabel(peqItem2);
        peqTestValHighUnit->setObjectName(QString::fromUtf8("peqTestValHighUnit"));
        peqTestValHighUnit->setMinimumSize(QSize(0, 34));
        peqTestValHighUnit->setFont(font3);

        horizontalLayout_7->addWidget(peqTestValHighUnit);

        horizontalLayout_7->setStretch(0, 1);
        horizontalLayout_7->setStretch(1, 1);
        horizontalLayout_7->setStretch(2, 1);
        horizontalLayout_7->setStretch(3, 1);
        horizontalLayout_7->setStretch(4, 1);
        horizontalLayout_7->setStretch(5, 1);

        verticalLayout_4->addWidget(peqItem2);

        peqItem3 = new QWidget(setpeqWidget);
        peqItem3->setObjectName(QString::fromUtf8("peqItem3"));
        peqItem3->setMinimumSize(QSize(740, 50));
        peqItem3->setMaximumSize(QSize(16777215, 50));
        horizontalLayout_8 = new QHBoxLayout(peqItem3);
        horizontalLayout_8->setSpacing(10);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        peqTestCompLab = new QLabel(peqItem3);
        peqTestCompLab->setObjectName(QString::fromUtf8("peqTestCompLab"));
        peqTestCompLab->setMinimumSize(QSize(0, 34));
        peqTestCompLab->setFont(font3);
        peqTestCompLab->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(peqTestCompLab);

        peqTestCompLE = new QLineEdit(peqItem3);
        peqTestCompLE->setObjectName(QString::fromUtf8("peqTestCompLE"));
        peqTestCompLE->setMinimumSize(QSize(100, 34));
        peqTestCompLE->setMaximumSize(QSize(16777215, 16777215));
        peqTestCompLE->setFont(font3);

        horizontalLayout_8->addWidget(peqTestCompLE);

        peqTestCompUnit = new QLabel(peqItem3);
        peqTestCompUnit->setObjectName(QString::fromUtf8("peqTestCompUnit"));
        peqTestCompUnit->setMinimumSize(QSize(0, 34));
        peqTestCompUnit->setFont(font3);

        horizontalLayout_8->addWidget(peqTestCompUnit);

        peqTestTimeLab = new QLabel(peqItem3);
        peqTestTimeLab->setObjectName(QString::fromUtf8("peqTestTimeLab"));
        peqTestTimeLab->setMinimumSize(QSize(0, 34));
        peqTestTimeLab->setFont(font3);
        peqTestTimeLab->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(peqTestTimeLab);

        peqTestTimeLE = new QLineEdit(peqItem3);
        peqTestTimeLE->setObjectName(QString::fromUtf8("peqTestTimeLE"));
        peqTestTimeLE->setMinimumSize(QSize(100, 34));
        peqTestTimeLE->setMaximumSize(QSize(16777215, 16777215));
        peqTestTimeLE->setFont(font3);

        horizontalLayout_8->addWidget(peqTestTimeLE);

        peqTestTimeUnit = new QLabel(peqItem3);
        peqTestTimeUnit->setObjectName(QString::fromUtf8("peqTestTimeUnit"));
        peqTestTimeUnit->setMinimumSize(QSize(0, 34));
        peqTestTimeUnit->setFont(font3);

        horizontalLayout_8->addWidget(peqTestTimeUnit);

        horizontalLayout_8->setStretch(0, 1);
        horizontalLayout_8->setStretch(1, 1);
        horizontalLayout_8->setStretch(2, 1);
        horizontalLayout_8->setStretch(3, 1);
        horizontalLayout_8->setStretch(4, 1);
        horizontalLayout_8->setStretch(5, 1);

        verticalLayout_4->addWidget(peqItem3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);


        verticalLayout_8->addWidget(setpeqWidget);

        itemStackedWidget->addWidget(peqPage);

        gridLayout->addWidget(itemStackedWidget, 2, 1, 2, 1);

        btnWidget = new QWidget(programDialog);
        btnWidget->setObjectName(QString::fromUtf8("btnWidget"));
        btnWidget->setMinimumSize(QSize(1240, 80));
        btnWidget->setMaximumSize(QSize(16777215, 80));
        btnWidget->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: #FFFFFF;\n"
"border-radius: 15px;\n"
"\n"
"}\n"
"QPushButton:hover{\n"
"border: 2px solid #0E55A7;\n"
"}\n"
"QPushButton:pressed{\n"
"color: #FFFFFF;\n"
"background-color:rgba(210, 210, 210, 150);\n"
"}"));
        horizontalLayout = new QHBoxLayout(btnWidget);
        horizontalLayout->setSpacing(20);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(20, 0, 0, 0);
        openfileBtn = new QPushButton(btnWidget);
        openfileBtn->setObjectName(QString::fromUtf8("openfileBtn"));
        openfileBtn->setMinimumSize(QSize(120, 50));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font5.setPointSize(16);
        openfileBtn->setFont(font5);
        openfileBtn->setStyleSheet(QString::fromUtf8("\n"
"\n"
"/*border: 2px solid rgb(191, 191, 191);\n"
"border-radius: 3px;\n"
"margin-top: 10px;\n"
"margin-left: 10px;\n"
"margin-bottom: 10px;\n"
"margin-right: 10px;*/"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/addfilel.png"), QSize(), QIcon::Normal, QIcon::Off);
        openfileBtn->setIcon(icon);
        openfileBtn->setIconSize(QSize(25, 25));
        openfileBtn->setFlat(false);

        horizontalLayout->addWidget(openfileBtn);

        savefileBtn = new QPushButton(btnWidget);
        savefileBtn->setObjectName(QString::fromUtf8("savefileBtn"));
        savefileBtn->setMinimumSize(QSize(120, 50));
        savefileBtn->setFont(font5);
        savefileBtn->setStyleSheet(QString::fromUtf8(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/savel.png"), QSize(), QIcon::Normal, QIcon::Off);
        savefileBtn->setIcon(icon1);
        savefileBtn->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(savefileBtn);

        newfileBtn = new QPushButton(btnWidget);
        newfileBtn->setObjectName(QString::fromUtf8("newfileBtn"));
        newfileBtn->setMinimumSize(QSize(120, 50));
        newfileBtn->setFont(font5);
        newfileBtn->setStyleSheet(QString::fromUtf8(""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icon/newl.png"), QSize(), QIcon::Normal, QIcon::Off);
        newfileBtn->setIcon(icon2);
        newfileBtn->setIconSize(QSize(25, 25));

        horizontalLayout->addWidget(newfileBtn);

        deletefileBtn = new QPushButton(btnWidget);
        deletefileBtn->setObjectName(QString::fromUtf8("deletefileBtn"));
        deletefileBtn->setMinimumSize(QSize(120, 50));
        deletefileBtn->setFont(font5);
        deletefileBtn->setStyleSheet(QString::fromUtf8(""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icon/deletel.png"), QSize(), QIcon::Normal, QIcon::Off);
        deletefileBtn->setIcon(icon3);
        deletefileBtn->setIconSize(QSize(25, 25));

        horizontalLayout->addWidget(deletefileBtn);

        topfileBtn = new QPushButton(btnWidget);
        topfileBtn->setObjectName(QString::fromUtf8("topfileBtn"));
        topfileBtn->setMinimumSize(QSize(50, 50));
        topfileBtn->setFont(font5);

        horizontalLayout->addWidget(topfileBtn);

        downfileBtn = new QPushButton(btnWidget);
        downfileBtn->setObjectName(QString::fromUtf8("downfileBtn"));
        downfileBtn->setMinimumSize(QSize(50, 50));
        downfileBtn->setFont(font5);

        horizontalLayout->addWidget(downfileBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addWidget(btnWidget, 1, 0, 1, 4);

        infoWidget = new QWidget(programDialog);
        infoWidget->setObjectName(QString::fromUtf8("infoWidget"));
        infoWidget->setMinimumSize(QSize(1240, 80));
        infoWidget->setMaximumSize(QSize(16777215, 80));
        horizontalLayout_2 = new QHBoxLayout(infoWidget);
        horizontalLayout_2->setSpacing(20);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(infoWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(50, 50));
        label->setMaximumSize(QSize(50, 50));
        label->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(label);

        filenameLab = new QLabel(infoWidget);
        filenameLab->setObjectName(QString::fromUtf8("filenameLab"));
        filenameLab->setMinimumSize(QSize(100, 50));
        filenameLab->setMaximumSize(QSize(100, 50));
        QFont font6;
        font6.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font6.setPointSize(18);
        filenameLab->setFont(font6);
        filenameLab->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(filenameLab);

        filenameLE = new QLineEdit(infoWidget);
        filenameLE->setObjectName(QString::fromUtf8("filenameLE"));
        filenameLE->setMinimumSize(QSize(400, 50));
        filenameLE->setMaximumSize(QSize(600, 16777215));
        filenameLE->setFont(font5);
        filenameLE->setStyleSheet(QString::fromUtf8("border-image: url(:/icon/lineeditl.png);"));
        filenameLE->setReadOnly(false);

        horizontalLayout_2->addWidget(filenameLE);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        taskWidget = new QWidget(infoWidget);
        taskWidget->setObjectName(QString::fromUtf8("taskWidget"));
        taskWidget->setMinimumSize(QSize(200, 80));
        taskWidget->setMaximumSize(QSize(200, 80));
        taskWidget->setStyleSheet(QString::fromUtf8("#minBtn{\n"
"	border-image: url(:/icon/mins.png);\n"
"}\n"
"#minBtn:hover{\n"
"	border-image: url(:/icon/nins1.png);\n"
"}\n"
"\n"
"#closeBtn{\n"
"	border-image: url(:/icon/closel.png);\n"
"}\n"
"#closeBtn:hover{\n"
"	border-image: url(:/icon/closel1.png);\n"
"}"));
        minBtn = new QPushButton(taskWidget);
        minBtn->setObjectName(QString::fromUtf8("minBtn"));
        minBtn->setGeometry(QRect(100, 0, 40, 40));
        minBtn->setIconSize(QSize(70, 70));
        minBtn->setFlat(true);
        closeBtn = new QPushButton(taskWidget);
        closeBtn->setObjectName(QString::fromUtf8("closeBtn"));
        closeBtn->setGeometry(QRect(160, 0, 40, 40));
        closeBtn->setIconSize(QSize(30, 30));
        closeBtn->setFlat(true);

        horizontalLayout_2->addWidget(taskWidget);


        gridLayout->addWidget(infoWidget, 0, 0, 1, 4);

        widget_2 = new QWidget(programDialog);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(205, 540));
        widget_2->setMaximumSize(QSize(205, 16777215));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        itemTreeWidget = new QTreeWidget(widget_2);
        new QTreeWidgetItem(itemTreeWidget);
        new QTreeWidgetItem(itemTreeWidget);
        itemTreeWidget->setObjectName(QString::fromUtf8("itemTreeWidget"));
        itemTreeWidget->setMinimumSize(QSize(205, 340));
        itemTreeWidget->setMaximumSize(QSize(205, 16777215));
        QFont font7;
        font7.setPointSize(16);
        itemTreeWidget->setFont(font7);
        itemTreeWidget->setStyleSheet(QString::fromUtf8("QTreeWidget{\n"
"border-radius: 20px;\n"
"border:none;\n"
"}"));

        verticalLayout_2->addWidget(itemTreeWidget);

        groupWidget = new QWidget(widget_2);
        groupWidget->setObjectName(QString::fromUtf8("groupWidget"));
        groupWidget->setMinimumSize(QSize(205, 195));
        groupWidget->setMaximumSize(QSize(195, 16777215));
        groupWidget->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"color: #222222;\n"
"border: 1px solid #0E55A7;\n"
"border-radius: 5px;\n"
"}\n"
"\n"
"QComboBox{\n"
"color: #222222;\n"
"border: 1px solid #0E55A7;\n"
"border-radius: 5px;\n"
"}\n"
"QComboBox::down-arrow{\n"
"	border-image: url(:/icon/downarrl.png);\n"
"	width: 16px;\n"
"      border:none;\n"
"}\n"
"QComboBox::drop-down {\n"
"      subcontrol-origin: padding;\n"
"      width: 30px;\n"
"      border:none;\n"
"\n"
"}\n"
"\n"
"QComboBox QAbstractItemView{\n"
"background:rgba(255,255,255,1);\n"
"    border:1px solid #0E55A7;\n"
"    outline: 0px;\n"
"}\n"
"\n"
"QLabel{\n"
"color: #222222;\n"
"}"));
        verticalLayout_5 = new QVBoxLayout(groupWidget);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 10, 0, 30);
        peqItem1_2 = new QWidget(groupWidget);
        peqItem1_2->setObjectName(QString::fromUtf8("peqItem1_2"));
        peqItem1_2->setMinimumSize(QSize(205, 30));
        peqItem1_2->setMaximumSize(QSize(16777215, 50));
        QFont font8;
        font8.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font8.setPointSize(12);
        peqItem1_2->setFont(font8);
        horizontalLayout_9 = new QHBoxLayout(peqItem1_2);
        horizontalLayout_9->setSpacing(5);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(5, 0, 5, 0);
        freqLab = new QLabel(peqItem1_2);
        freqLab->setObjectName(QString::fromUtf8("freqLab"));
        freqLab->setMinimumSize(QSize(60, 30));
        freqLab->setFont(font8);
        freqLab->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(freqLab);

        freqLE = new QLineEdit(peqItem1_2);
        freqLE->setObjectName(QString::fromUtf8("freqLE"));
        freqLE->setMinimumSize(QSize(60, 30));
        freqLE->setMaximumSize(QSize(100, 16777215));
        freqLE->setFont(font8);

        horizontalLayout_9->addWidget(freqLE);

        pfreqUnit = new QLabel(peqItem1_2);
        pfreqUnit->setObjectName(QString::fromUtf8("pfreqUnit"));
        pfreqUnit->setMinimumSize(QSize(0, 30));
        pfreqUnit->setFont(font8);

        horizontalLayout_9->addWidget(pfreqUnit);


        verticalLayout_5->addWidget(peqItem1_2);

        peqItem1_3 = new QWidget(groupWidget);
        peqItem1_3->setObjectName(QString::fromUtf8("peqItem1_3"));
        peqItem1_3->setMinimumSize(QSize(205, 30));
        peqItem1_3->setMaximumSize(QSize(16777215, 50));
        peqItem1_3->setFont(font8);
        horizontalLayout_10 = new QHBoxLayout(peqItem1_3);
        horizontalLayout_10->setSpacing(5);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(5, 0, 10, 0);
        failstepLab = new QLabel(peqItem1_3);
        failstepLab->setObjectName(QString::fromUtf8("failstepLab"));
        failstepLab->setMinimumSize(QSize(60, 30));
        failstepLab->setFont(font8);
        failstepLab->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(failstepLab);

        failstepCBox = new QComboBox(peqItem1_3);
        failstepCBox->addItem(QString());
        failstepCBox->addItem(QString());
        failstepCBox->setObjectName(QString::fromUtf8("failstepCBox"));
        failstepCBox->setMinimumSize(QSize(100, 30));
        failstepCBox->setFont(font8);

        horizontalLayout_10->addWidget(failstepCBox);


        verticalLayout_5->addWidget(peqItem1_3);

        peqItem1_4 = new QWidget(groupWidget);
        peqItem1_4->setObjectName(QString::fromUtf8("peqItem1_4"));
        peqItem1_4->setMinimumSize(QSize(205, 30));
        peqItem1_4->setMaximumSize(QSize(16777215, 50));
        peqItem1_4->setFont(font8);
        horizontalLayout_11 = new QHBoxLayout(peqItem1_4);
        horizontalLayout_11->setSpacing(5);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(5, 0, 10, 0);
        powerLab = new QLabel(peqItem1_4);
        powerLab->setObjectName(QString::fromUtf8("powerLab"));
        powerLab->setMinimumSize(QSize(60, 30));
        powerLab->setFont(font8);
        powerLab->setAlignment(Qt::AlignCenter);

        horizontalLayout_11->addWidget(powerLab);

        powerCBox = new QComboBox(peqItem1_4);
        powerCBox->addItem(QString());
        powerCBox->addItem(QString());
        powerCBox->addItem(QString());
        powerCBox->setObjectName(QString::fromUtf8("powerCBox"));
        powerCBox->setMinimumSize(QSize(100, 30));
        powerCBox->setFont(font8);

        horizontalLayout_11->addWidget(powerCBox);


        verticalLayout_5->addWidget(peqItem1_4);

        peqItem1_5 = new QWidget(groupWidget);
        peqItem1_5->setObjectName(QString::fromUtf8("peqItem1_5"));
        peqItem1_5->setMinimumSize(QSize(205, 30));
        peqItem1_5->setMaximumSize(QSize(16777215, 50));
        peqItem1_5->setFont(font8);
        horizontalLayout_12 = new QHBoxLayout(peqItem1_5);
        horizontalLayout_12->setSpacing(5);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(5, 0, 10, 0);
        groupConnLab = new QLabel(peqItem1_5);
        groupConnLab->setObjectName(QString::fromUtf8("groupConnLab"));
        groupConnLab->setMinimumSize(QSize(60, 30));
        groupConnLab->setFont(font8);
        groupConnLab->setAlignment(Qt::AlignCenter);

        horizontalLayout_12->addWidget(groupConnLab);

        groupConnCBox = new QComboBox(peqItem1_5);
        groupConnCBox->addItem(QString());
        groupConnCBox->setObjectName(QString::fromUtf8("groupConnCBox"));
        groupConnCBox->setMinimumSize(QSize(100, 30));
        groupConnCBox->setFont(font8);

        horizontalLayout_12->addWidget(groupConnCBox);


        verticalLayout_5->addWidget(peqItem1_5);


        verticalLayout_2->addWidget(groupWidget);


        gridLayout->addWidget(widget_2, 2, 2, 2, 1);


        retranslateUi(programDialog);

        itemStackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(programDialog);
    } // setupUi

    void retranslateUi(QDialog *programDialog)
    {
        programDialog->setWindowTitle(QCoreApplication::translate("programDialog", "Dialog", nullptr));
        QTableWidgetItem *___qtablewidgetitem = itemListWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("programDialog", "\345\272\217\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = itemListWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("programDialog", "\346\265\213\350\257\225\351\241\271", nullptr));
        titleLab->setText(QCoreApplication::translate("programDialog", "\347\273\235\347\274\230", nullptr));
        irTestSetLab->setText(QCoreApplication::translate("programDialog", "\346\265\213\350\257\225\347\224\265\345\216\213:", nullptr));
        irTestSetUnit->setText(QCoreApplication::translate("programDialog", "0.1-1.0 KV             ", nullptr));
        irTestModeLab->setText(QCoreApplication::translate("programDialog", "\350\277\236\346\216\245\346\250\241\345\274\217:", nullptr));
        irTestModeCBox->setItemText(0, QCoreApplication::translate("programDialog", "\347\273\247\347\273\255", nullptr));
        irTestModeCBox->setItemText(1, QCoreApplication::translate("programDialog", "\345\201\234\346\255\242", nullptr));
        irTestModeCBox->setItemText(2, QCoreApplication::translate("programDialog", "\345\215\225\346\255\245", nullptr));

        irTestModeLab1->setText(QString());
        irTestValLowLab->setText(QCoreApplication::translate("programDialog", "\347\224\265\351\230\273\344\270\213\351\231\220:", nullptr));
        irTestValLowUnit->setText(QCoreApplication::translate("programDialog", "0.000-55000 Gohm", nullptr));
        irTestValHighLab->setText(QCoreApplication::translate("programDialog", "\347\224\265\351\230\273\344\270\212\351\231\220:", nullptr));
        irTestValHighUnit->setText(QCoreApplication::translate("programDialog", "0.000-55000 Gohm", nullptr));
        irTestCompLab->setText(QCoreApplication::translate("programDialog", "   \350\241\245\345\201\277\345\200\274:", nullptr));
        irTestCompUnit->setText(QCoreApplication::translate("programDialog", "0-55000 Gohm      ", nullptr));
        irTestTimeLab->setText(QCoreApplication::translate("programDialog", "\346\265\213\350\257\225\346\227\266\351\227\264:", nullptr));
        irTestTimeUnit->setText(QCoreApplication::translate("programDialog", "1.0-999.9 S            ", nullptr));
        titleLab2->setText(QCoreApplication::translate("programDialog", "\347\224\265\344\275\215\345\235\207\350\241\241", nullptr));
        peqTestSetLab->setText(QCoreApplication::translate("programDialog", "\346\265\213\350\257\225\347\224\265\346\265\201:", nullptr));
        peqTestSetUnit->setText(QCoreApplication::translate("programDialog", "2.0-32.0 A            ", nullptr));
        peqTestModeLab->setText(QCoreApplication::translate("programDialog", "\350\277\236\346\216\245\346\250\241\345\274\217:", nullptr));
        peqTestModeCBox->setItemText(0, QCoreApplication::translate("programDialog", "\347\273\247\347\273\255", nullptr));
        peqTestModeCBox->setItemText(1, QCoreApplication::translate("programDialog", "\345\201\234\346\255\242", nullptr));
        peqTestModeCBox->setItemText(2, QCoreApplication::translate("programDialog", "\345\215\225\346\255\245", nullptr));

        Lab->setText(QString());
        peqTestValLowLab->setText(QCoreApplication::translate("programDialog", "\347\224\265\351\230\273\344\270\213\351\231\220:", nullptr));
        peqTestValLowUnit->setText(QCoreApplication::translate("programDialog", "0.0-1000.0 mohm", nullptr));
        peqTestValHighLab->setText(QCoreApplication::translate("programDialog", "\347\224\265\351\230\273\344\270\212\351\231\220:", nullptr));
        peqTestValHighUnit->setText(QCoreApplication::translate("programDialog", "0.0-1000.0 mohm  ", nullptr));
        peqTestCompLab->setText(QCoreApplication::translate("programDialog", "   \350\241\245\345\201\277\345\200\274:", nullptr));
        peqTestCompUnit->setText(QCoreApplication::translate("programDialog", "0.0-100 mohm     ", nullptr));
        peqTestTimeLab->setText(QCoreApplication::translate("programDialog", "\346\265\213\350\257\225\346\227\266\351\227\264:", nullptr));
        peqTestTimeUnit->setText(QCoreApplication::translate("programDialog", "1.0-999.9 S            ", nullptr));
#if QT_CONFIG(tooltip)
        openfileBtn->setToolTip(QCoreApplication::translate("programDialog", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
        openfileBtn->setText(QCoreApplication::translate("programDialog", "\346\211\223\345\274\200", nullptr));
#if QT_CONFIG(tooltip)
        savefileBtn->setToolTip(QCoreApplication::translate("programDialog", "\344\277\235\345\255\230", nullptr));
#endif // QT_CONFIG(tooltip)
        savefileBtn->setText(QCoreApplication::translate("programDialog", "\344\277\235\345\255\230", nullptr));
#if QT_CONFIG(tooltip)
        newfileBtn->setToolTip(QCoreApplication::translate("programDialog", "\346\226\260\345\273\272", nullptr));
#endif // QT_CONFIG(tooltip)
        newfileBtn->setText(QCoreApplication::translate("programDialog", "\346\226\260\345\273\272", nullptr));
#if QT_CONFIG(tooltip)
        deletefileBtn->setToolTip(QCoreApplication::translate("programDialog", "\345\210\240\351\231\244", nullptr));
#endif // QT_CONFIG(tooltip)
        deletefileBtn->setText(QCoreApplication::translate("programDialog", "\345\210\240\351\231\244", nullptr));
        topfileBtn->setText(QCoreApplication::translate("programDialog", "\344\270\212\347\247\273", nullptr));
        downfileBtn->setText(QCoreApplication::translate("programDialog", "\344\270\212\347\247\273", nullptr));
        label->setText(QString());
        filenameLab->setText(QCoreApplication::translate("programDialog", "\346\226\207\344\273\266\345\220\215:", nullptr));
        minBtn->setText(QString());
        closeBtn->setText(QString());
        QTreeWidgetItem *___qtreewidgetitem = itemTreeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("programDialog", "\346\265\213\350\257\225\351\241\271", nullptr));

        const bool __sortingEnabled = itemTreeWidget->isSortingEnabled();
        itemTreeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = itemTreeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QCoreApplication::translate("programDialog", "\347\273\235\347\274\230", nullptr));
        QTreeWidgetItem *___qtreewidgetitem2 = itemTreeWidget->topLevelItem(1);
        ___qtreewidgetitem2->setText(0, QCoreApplication::translate("programDialog", "\347\224\265\344\275\215\345\235\207\350\241\241", nullptr));
        itemTreeWidget->setSortingEnabled(__sortingEnabled);

        freqLab->setText(QCoreApplication::translate("programDialog", "     \351\242\221\347\216\207:     ", nullptr));
        pfreqUnit->setText(QCoreApplication::translate("programDialog", "Hz", nullptr));
        failstepLab->setText(QCoreApplication::translate("programDialog", "\351\201\207\345\244\261\350\264\245\346\255\245:", nullptr));
        failstepCBox->setItemText(0, QCoreApplication::translate("programDialog", "\345\201\234\346\255\242", nullptr));
        failstepCBox->setItemText(1, QCoreApplication::translate("programDialog", "\347\273\247\347\273\255", nullptr));

        powerLab->setText(QCoreApplication::translate("programDialog", "\345\231\250\345\205\267\347\261\273\345\236\213:", nullptr));
        powerCBox->setItemText(0, QCoreApplication::translate("programDialog", "\345\215\225\351\241\271", nullptr));
        powerCBox->setItemText(1, QCoreApplication::translate("programDialog", "\344\270\211\347\233\270\344\270\211\347\272\277", nullptr));
        powerCBox->setItemText(2, QCoreApplication::translate("programDialog", "\344\270\211\347\233\270\345\233\233\347\272\277", nullptr));

        groupConnLab->setText(QCoreApplication::translate("programDialog", "\347\273\204\350\277\236\346\216\245:", nullptr));
        groupConnCBox->setItemText(0, QCoreApplication::translate("programDialog", "\345\205\263", nullptr));

    } // retranslateUi

};

namespace Ui {
    class programDialog: public Ui_programDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRAMDIALOG_H
