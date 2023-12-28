/********************************************************************************
** Form generated from reading UI file 'programdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRAMDIALOG_H
#define UI_PROGRAMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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
    QVBoxLayout *verticalLayout_2;
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
    QTableWidget *itemListWidget;
    QTreeWidget *itemTreeWidget;
    QWidget *infoWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *filenameLab;
    QLineEdit *filenameLE;
    QSpacerItem *horizontalSpacer_2;
    QWidget *taskWidget;
    QPushButton *minBtn;
    QPushButton *closeBtn;
    QWidget *btnWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *openfileBtn;
    QPushButton *savefileBtn;
    QPushButton *newfileBtn;
    QPushButton *topfileBtn;
    QPushButton *downfileBtn;
    QPushButton *deletefileBtn;
    QSpacerItem *horizontalSpacer;
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
            programDialog->setObjectName(QStringLiteral("programDialog"));
        programDialog->resize(1280, 720);
        programDialog->setMinimumSize(QSize(1280, 720));
        gridLayout = new QGridLayout(programDialog);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(20, 0, 20, 20);
        itemStackedWidget = new QStackedWidget(programDialog);
        itemStackedWidget->setObjectName(QStringLiteral("itemStackedWidget"));
        itemStackedWidget->setMinimumSize(QSize(780, 540));
        nullPage = new QWidget();
        nullPage->setObjectName(QStringLiteral("nullPage"));
        verticalLayout_6 = new QVBoxLayout(nullPage);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        widget = new QWidget(nullPage);
        widget->setObjectName(QStringLiteral("widget"));

        verticalLayout_6->addWidget(widget);

        itemStackedWidget->addWidget(nullPage);
        irPage = new QWidget();
        irPage->setObjectName(QStringLiteral("irPage"));
        verticalLayout_7 = new QVBoxLayout(irPage);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        iritemWidget = new QWidget(irPage);
        iritemWidget->setObjectName(QStringLiteral("iritemWidget"));
        iritemWidget->setMinimumSize(QSize(780, 60));
        iritemWidget->setMaximumSize(QSize(16777215, 60));
        verticalLayout = new QVBoxLayout(iritemWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleLab = new QLabel(iritemWidget);
        titleLab->setObjectName(QStringLiteral("titleLab"));
        titleLab->setMinimumSize(QSize(780, 50));
        titleLab->setMaximumSize(QSize(16777215, 50));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(20);
        titleLab->setFont(font);
        titleLab->setStyleSheet(QLatin1String("QLabel{\n"
"            margin-left:20px;\n"
"}"));
        titleLab->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        titleLab->setMargin(0);

        verticalLayout->addWidget(titleLab);

        line = new QFrame(iritemWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setMinimumSize(QSize(760, 10));
        line->setMaximumSize(QSize(16777215, 10));
        line->setLineWidth(3);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);


        verticalLayout_7->addWidget(iritemWidget);

        setirWidget = new QWidget(irPage);
        setirWidget->setObjectName(QStringLiteral("setirWidget"));
        setirWidget->setMinimumSize(QSize(780, 500));
        setirWidget->setMaximumSize(QSize(16777215, 50));
        verticalLayout_2 = new QVBoxLayout(setirWidget);
        verticalLayout_2->setSpacing(20);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(10, 30, 10, 0);
        setItem1 = new QWidget(setirWidget);
        setItem1->setObjectName(QStringLiteral("setItem1"));
        setItem1->setMinimumSize(QSize(760, 50));
        setItem1->setMaximumSize(QSize(16777215, 50));
        horizontalLayout_3 = new QHBoxLayout(setItem1);
        horizontalLayout_3->setSpacing(10);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        irTestSetLab = new QLabel(setItem1);
        irTestSetLab->setObjectName(QStringLiteral("irTestSetLab"));
        irTestSetLab->setMinimumSize(QSize(0, 34));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(14);
        irTestSetLab->setFont(font1);
        irTestSetLab->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(irTestSetLab);

        irTestSetLE = new QLineEdit(setItem1);
        irTestSetLE->setObjectName(QStringLiteral("irTestSetLE"));
        irTestSetLE->setMinimumSize(QSize(100, 34));
        irTestSetLE->setMaximumSize(QSize(16777215, 16777215));
        irTestSetLE->setFont(font1);

        horizontalLayout_3->addWidget(irTestSetLE);

        irTestSetUnit = new QLabel(setItem1);
        irTestSetUnit->setObjectName(QStringLiteral("irTestSetUnit"));
        irTestSetUnit->setMinimumSize(QSize(0, 34));
        irTestSetUnit->setFont(font1);

        horizontalLayout_3->addWidget(irTestSetUnit);

        irTestModeLab = new QLabel(setItem1);
        irTestModeLab->setObjectName(QStringLiteral("irTestModeLab"));
        irTestModeLab->setMinimumSize(QSize(0, 34));
        irTestModeLab->setFont(font1);
        irTestModeLab->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(irTestModeLab);

        irTestModeCBox = new QComboBox(setItem1);
        irTestModeCBox->setObjectName(QStringLiteral("irTestModeCBox"));
        irTestModeCBox->setMinimumSize(QSize(100, 34));
        irTestModeCBox->setMaximumSize(QSize(16777215, 16777215));
        irTestModeCBox->setFont(font1);

        horizontalLayout_3->addWidget(irTestModeCBox);

        irTestModeLab1 = new QLabel(setItem1);
        irTestModeLab1->setObjectName(QStringLiteral("irTestModeLab1"));
        irTestModeLab1->setMinimumSize(QSize(173, 34));
        irTestModeLab1->setFont(font1);

        horizontalLayout_3->addWidget(irTestModeLab1);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(2, 1);
        horizontalLayout_3->setStretch(3, 1);
        horizontalLayout_3->setStretch(4, 1);
        horizontalLayout_3->setStretch(5, 1);

        verticalLayout_2->addWidget(setItem1);

        setItem2 = new QWidget(setirWidget);
        setItem2->setObjectName(QStringLiteral("setItem2"));
        setItem2->setMinimumSize(QSize(760, 50));
        setItem2->setMaximumSize(QSize(16777215, 50));
        horizontalLayout_4 = new QHBoxLayout(setItem2);
        horizontalLayout_4->setSpacing(10);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        irTestValLowLab = new QLabel(setItem2);
        irTestValLowLab->setObjectName(QStringLiteral("irTestValLowLab"));
        irTestValLowLab->setMinimumSize(QSize(0, 34));
        irTestValLowLab->setFont(font1);
        irTestValLowLab->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(irTestValLowLab);

        irTestValLowLE = new QLineEdit(setItem2);
        irTestValLowLE->setObjectName(QStringLiteral("irTestValLowLE"));
        irTestValLowLE->setMinimumSize(QSize(100, 34));
        irTestValLowLE->setMaximumSize(QSize(16777215, 16777215));
        irTestValLowLE->setFont(font1);

        horizontalLayout_4->addWidget(irTestValLowLE);

        irTestValLowUnit = new QLabel(setItem2);
        irTestValLowUnit->setObjectName(QStringLiteral("irTestValLowUnit"));
        irTestValLowUnit->setMinimumSize(QSize(0, 34));
        irTestValLowUnit->setFont(font1);

        horizontalLayout_4->addWidget(irTestValLowUnit);

        irTestValHighLab = new QLabel(setItem2);
        irTestValHighLab->setObjectName(QStringLiteral("irTestValHighLab"));
        irTestValHighLab->setMinimumSize(QSize(0, 34));
        irTestValHighLab->setFont(font1);
        irTestValHighLab->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(irTestValHighLab);

        irTestValHighLE = new QLineEdit(setItem2);
        irTestValHighLE->setObjectName(QStringLiteral("irTestValHighLE"));
        irTestValHighLE->setMinimumSize(QSize(100, 34));
        irTestValHighLE->setMaximumSize(QSize(16777215, 16777215));
        irTestValHighLE->setFont(font1);

        horizontalLayout_4->addWidget(irTestValHighLE);

        irTestValHighUnit = new QLabel(setItem2);
        irTestValHighUnit->setObjectName(QStringLiteral("irTestValHighUnit"));
        irTestValHighUnit->setMinimumSize(QSize(0, 34));
        irTestValHighUnit->setFont(font1);

        horizontalLayout_4->addWidget(irTestValHighUnit);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 1);
        horizontalLayout_4->setStretch(2, 1);
        horizontalLayout_4->setStretch(3, 1);
        horizontalLayout_4->setStretch(4, 1);
        horizontalLayout_4->setStretch(5, 1);

        verticalLayout_2->addWidget(setItem2);

        setItem3 = new QWidget(setirWidget);
        setItem3->setObjectName(QStringLiteral("setItem3"));
        setItem3->setMinimumSize(QSize(760, 50));
        setItem3->setMaximumSize(QSize(16777215, 50));
        horizontalLayout_5 = new QHBoxLayout(setItem3);
        horizontalLayout_5->setSpacing(10);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        irTestCompLab = new QLabel(setItem3);
        irTestCompLab->setObjectName(QStringLiteral("irTestCompLab"));
        irTestCompLab->setMinimumSize(QSize(0, 34));
        irTestCompLab->setFont(font1);
        irTestCompLab->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(irTestCompLab);

        irTestCompLE = new QLineEdit(setItem3);
        irTestCompLE->setObjectName(QStringLiteral("irTestCompLE"));
        irTestCompLE->setMinimumSize(QSize(100, 34));
        irTestCompLE->setMaximumSize(QSize(16777215, 16777215));
        irTestCompLE->setFont(font1);

        horizontalLayout_5->addWidget(irTestCompLE);

        irTestCompUnit = new QLabel(setItem3);
        irTestCompUnit->setObjectName(QStringLiteral("irTestCompUnit"));
        irTestCompUnit->setMinimumSize(QSize(0, 34));
        irTestCompUnit->setFont(font1);

        horizontalLayout_5->addWidget(irTestCompUnit);

        irTestTimeLab = new QLabel(setItem3);
        irTestTimeLab->setObjectName(QStringLiteral("irTestTimeLab"));
        irTestTimeLab->setMinimumSize(QSize(0, 34));
        irTestTimeLab->setFont(font1);
        irTestTimeLab->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(irTestTimeLab);

        irTestTimeLE = new QLineEdit(setItem3);
        irTestTimeLE->setObjectName(QStringLiteral("irTestTimeLE"));
        irTestTimeLE->setMinimumSize(QSize(100, 34));
        irTestTimeLE->setMaximumSize(QSize(16777215, 16777215));
        irTestTimeLE->setFont(font1);

        horizontalLayout_5->addWidget(irTestTimeLE);

        irTestTimeUnit = new QLabel(setItem3);
        irTestTimeUnit->setObjectName(QStringLiteral("irTestTimeUnit"));
        irTestTimeUnit->setMinimumSize(QSize(0, 34));
        irTestTimeUnit->setFont(font1);

        horizontalLayout_5->addWidget(irTestTimeUnit);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 1);
        horizontalLayout_5->setStretch(2, 1);
        horizontalLayout_5->setStretch(3, 1);
        horizontalLayout_5->setStretch(4, 1);
        horizontalLayout_5->setStretch(5, 1);

        verticalLayout_2->addWidget(setItem3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        verticalLayout_7->addWidget(setirWidget);

        verticalLayout_7->setStretch(0, 1);
        verticalLayout_7->setStretch(1, 8);
        itemStackedWidget->addWidget(irPage);
        peqPage = new QWidget();
        peqPage->setObjectName(QStringLiteral("peqPage"));
        verticalLayout_8 = new QVBoxLayout(peqPage);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        peqitemWidget = new QWidget(peqPage);
        peqitemWidget->setObjectName(QStringLiteral("peqitemWidget"));
        peqitemWidget->setMinimumSize(QSize(760, 60));
        peqitemWidget->setMaximumSize(QSize(16777215, 60));
        verticalLayout_3 = new QVBoxLayout(peqitemWidget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        titleLab2 = new QLabel(peqitemWidget);
        titleLab2->setObjectName(QStringLiteral("titleLab2"));
        titleLab2->setMinimumSize(QSize(760, 50));
        titleLab2->setMaximumSize(QSize(16777215, 50));
        titleLab2->setFont(font);
        titleLab2->setStyleSheet(QLatin1String("QLabel{\n"
"            margin-left:20px;\n"
"}"));
        titleLab2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        titleLab2->setMargin(0);

        verticalLayout_3->addWidget(titleLab2);

        line_2 = new QFrame(peqitemWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setMinimumSize(QSize(760, 10));
        line_2->setMaximumSize(QSize(16777215, 10));
        line_2->setLineWidth(3);
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_2);


        verticalLayout_8->addWidget(peqitemWidget);

        setpeqWidget = new QWidget(peqPage);
        setpeqWidget->setObjectName(QStringLiteral("setpeqWidget"));
        setpeqWidget->setMinimumSize(QSize(760, 500));
        setpeqWidget->setMaximumSize(QSize(16777215, 50));
        verticalLayout_4 = new QVBoxLayout(setpeqWidget);
        verticalLayout_4->setSpacing(20);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(10, 30, 10, 0);
        peqItem1 = new QWidget(setpeqWidget);
        peqItem1->setObjectName(QStringLiteral("peqItem1"));
        peqItem1->setMinimumSize(QSize(760, 50));
        peqItem1->setMaximumSize(QSize(16777215, 50));
        horizontalLayout_6 = new QHBoxLayout(peqItem1);
        horizontalLayout_6->setSpacing(10);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        peqTestSetLab = new QLabel(peqItem1);
        peqTestSetLab->setObjectName(QStringLiteral("peqTestSetLab"));
        peqTestSetLab->setMinimumSize(QSize(0, 34));
        peqTestSetLab->setFont(font1);
        peqTestSetLab->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(peqTestSetLab);

        peqTestSetLE = new QLineEdit(peqItem1);
        peqTestSetLE->setObjectName(QStringLiteral("peqTestSetLE"));
        peqTestSetLE->setMinimumSize(QSize(100, 34));
        peqTestSetLE->setMaximumSize(QSize(16777215, 16777215));
        peqTestSetLE->setFont(font1);

        horizontalLayout_6->addWidget(peqTestSetLE);

        peqTestSetUnit = new QLabel(peqItem1);
        peqTestSetUnit->setObjectName(QStringLiteral("peqTestSetUnit"));
        peqTestSetUnit->setMinimumSize(QSize(0, 34));
        peqTestSetUnit->setFont(font1);

        horizontalLayout_6->addWidget(peqTestSetUnit);

        peqTestModeLab = new QLabel(peqItem1);
        peqTestModeLab->setObjectName(QStringLiteral("peqTestModeLab"));
        peqTestModeLab->setMinimumSize(QSize(0, 34));
        peqTestModeLab->setFont(font1);
        peqTestModeLab->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(peqTestModeLab);

        peqTestModeCBox = new QComboBox(peqItem1);
        peqTestModeCBox->setObjectName(QStringLiteral("peqTestModeCBox"));
        peqTestModeCBox->setMinimumSize(QSize(100, 34));
        peqTestModeCBox->setMaximumSize(QSize(16777215, 16777215));
        peqTestModeCBox->setFont(font1);

        horizontalLayout_6->addWidget(peqTestModeCBox);

        Lab = new QLabel(peqItem1);
        Lab->setObjectName(QStringLiteral("Lab"));
        Lab->setMinimumSize(QSize(162, 34));
        Lab->setFont(font1);

        horizontalLayout_6->addWidget(Lab);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(1, 1);
        horizontalLayout_6->setStretch(2, 1);
        horizontalLayout_6->setStretch(3, 1);
        horizontalLayout_6->setStretch(4, 1);
        horizontalLayout_6->setStretch(5, 1);

        verticalLayout_4->addWidget(peqItem1);

        peqItem2 = new QWidget(setpeqWidget);
        peqItem2->setObjectName(QStringLiteral("peqItem2"));
        peqItem2->setMinimumSize(QSize(760, 50));
        peqItem2->setMaximumSize(QSize(16777215, 50));
        horizontalLayout_7 = new QHBoxLayout(peqItem2);
        horizontalLayout_7->setSpacing(10);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        peqTestValLowLab = new QLabel(peqItem2);
        peqTestValLowLab->setObjectName(QStringLiteral("peqTestValLowLab"));
        peqTestValLowLab->setMinimumSize(QSize(0, 34));
        peqTestValLowLab->setFont(font1);
        peqTestValLowLab->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(peqTestValLowLab);

        peqTestValLowLE = new QLineEdit(peqItem2);
        peqTestValLowLE->setObjectName(QStringLiteral("peqTestValLowLE"));
        peqTestValLowLE->setMinimumSize(QSize(100, 34));
        peqTestValLowLE->setMaximumSize(QSize(16777215, 16777215));
        peqTestValLowLE->setFont(font1);

        horizontalLayout_7->addWidget(peqTestValLowLE);

        peqTestValLowUnit = new QLabel(peqItem2);
        peqTestValLowUnit->setObjectName(QStringLiteral("peqTestValLowUnit"));
        peqTestValLowUnit->setMinimumSize(QSize(0, 34));
        peqTestValLowUnit->setFont(font1);

        horizontalLayout_7->addWidget(peqTestValLowUnit);

        peqTestValHighLab = new QLabel(peqItem2);
        peqTestValHighLab->setObjectName(QStringLiteral("peqTestValHighLab"));
        peqTestValHighLab->setMinimumSize(QSize(0, 34));
        peqTestValHighLab->setFont(font1);
        peqTestValHighLab->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(peqTestValHighLab);

        peqTestValHighLE = new QLineEdit(peqItem2);
        peqTestValHighLE->setObjectName(QStringLiteral("peqTestValHighLE"));
        peqTestValHighLE->setMinimumSize(QSize(100, 34));
        peqTestValHighLE->setMaximumSize(QSize(16777215, 16777215));
        peqTestValHighLE->setFont(font1);

        horizontalLayout_7->addWidget(peqTestValHighLE);

        peqTestValHighUnit = new QLabel(peqItem2);
        peqTestValHighUnit->setObjectName(QStringLiteral("peqTestValHighUnit"));
        peqTestValHighUnit->setMinimumSize(QSize(0, 34));
        peqTestValHighUnit->setFont(font1);

        horizontalLayout_7->addWidget(peqTestValHighUnit);

        horizontalLayout_7->setStretch(0, 1);
        horizontalLayout_7->setStretch(1, 1);
        horizontalLayout_7->setStretch(2, 1);
        horizontalLayout_7->setStretch(3, 1);
        horizontalLayout_7->setStretch(4, 1);
        horizontalLayout_7->setStretch(5, 1);

        verticalLayout_4->addWidget(peqItem2);

        peqItem3 = new QWidget(setpeqWidget);
        peqItem3->setObjectName(QStringLiteral("peqItem3"));
        peqItem3->setMinimumSize(QSize(760, 50));
        peqItem3->setMaximumSize(QSize(16777215, 50));
        horizontalLayout_8 = new QHBoxLayout(peqItem3);
        horizontalLayout_8->setSpacing(10);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        peqTestCompLab = new QLabel(peqItem3);
        peqTestCompLab->setObjectName(QStringLiteral("peqTestCompLab"));
        peqTestCompLab->setMinimumSize(QSize(0, 34));
        peqTestCompLab->setFont(font1);
        peqTestCompLab->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(peqTestCompLab);

        peqTestCompLE = new QLineEdit(peqItem3);
        peqTestCompLE->setObjectName(QStringLiteral("peqTestCompLE"));
        peqTestCompLE->setMinimumSize(QSize(100, 34));
        peqTestCompLE->setMaximumSize(QSize(16777215, 16777215));
        peqTestCompLE->setFont(font1);

        horizontalLayout_8->addWidget(peqTestCompLE);

        peqTestCompUnit = new QLabel(peqItem3);
        peqTestCompUnit->setObjectName(QStringLiteral("peqTestCompUnit"));
        peqTestCompUnit->setMinimumSize(QSize(0, 34));
        peqTestCompUnit->setFont(font1);

        horizontalLayout_8->addWidget(peqTestCompUnit);

        peqTestTimeLab = new QLabel(peqItem3);
        peqTestTimeLab->setObjectName(QStringLiteral("peqTestTimeLab"));
        peqTestTimeLab->setMinimumSize(QSize(0, 34));
        peqTestTimeLab->setFont(font1);
        peqTestTimeLab->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(peqTestTimeLab);

        peqTestTimeLE = new QLineEdit(peqItem3);
        peqTestTimeLE->setObjectName(QStringLiteral("peqTestTimeLE"));
        peqTestTimeLE->setMinimumSize(QSize(100, 34));
        peqTestTimeLE->setMaximumSize(QSize(16777215, 16777215));
        peqTestTimeLE->setFont(font1);

        horizontalLayout_8->addWidget(peqTestTimeLE);

        peqTestTimeUnit = new QLabel(peqItem3);
        peqTestTimeUnit->setObjectName(QStringLiteral("peqTestTimeUnit"));
        peqTestTimeUnit->setMinimumSize(QSize(0, 34));
        peqTestTimeUnit->setFont(font1);

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

        gridLayout->addWidget(itemStackedWidget, 2, 1, 1, 1);

        itemListWidget = new QTableWidget(programDialog);
        if (itemListWidget->columnCount() < 2)
            itemListWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        itemListWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        itemListWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        itemListWidget->setObjectName(QStringLiteral("itemListWidget"));
        itemListWidget->setMinimumSize(QSize(250, 540));
        itemListWidget->setMaximumSize(QSize(250, 16777215));
        QFont font2;
        font2.setPointSize(16);
        itemListWidget->setFont(font2);
        itemListWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        itemListWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        itemListWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        itemListWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        itemListWidget->setShowGrid(true);
        itemListWidget->horizontalHeader()->setVisible(false);
        itemListWidget->horizontalHeader()->setHighlightSections(true);
        itemListWidget->verticalHeader()->setVisible(false);

        gridLayout->addWidget(itemListWidget, 2, 0, 1, 1);

        itemTreeWidget = new QTreeWidget(programDialog);
        new QTreeWidgetItem(itemTreeWidget);
        new QTreeWidgetItem(itemTreeWidget);
        itemTreeWidget->setObjectName(QStringLiteral("itemTreeWidget"));
        itemTreeWidget->setMinimumSize(QSize(210, 340));
        itemTreeWidget->setMaximumSize(QSize(210, 16777215));
        itemTreeWidget->setFont(font2);

        gridLayout->addWidget(itemTreeWidget, 2, 2, 1, 1);

        infoWidget = new QWidget(programDialog);
        infoWidget->setObjectName(QStringLiteral("infoWidget"));
        infoWidget->setMinimumSize(QSize(1280, 80));
        horizontalLayout_2 = new QHBoxLayout(infoWidget);
        horizontalLayout_2->setSpacing(20);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(20, 0, 0, 0);
        label = new QLabel(infoWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(50, 50));
        label->setMaximumSize(QSize(50, 50));

        horizontalLayout_2->addWidget(label);

        filenameLab = new QLabel(infoWidget);
        filenameLab->setObjectName(QStringLiteral("filenameLab"));
        filenameLab->setMinimumSize(QSize(100, 50));
        filenameLab->setMaximumSize(QSize(100, 50));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(18);
        filenameLab->setFont(font3);
        filenameLab->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(filenameLab);

        filenameLE = new QLineEdit(infoWidget);
        filenameLE->setObjectName(QStringLiteral("filenameLE"));
        filenameLE->setMinimumSize(QSize(400, 50));
        filenameLE->setMaximumSize(QSize(600, 16777215));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(16);
        filenameLE->setFont(font4);
        filenameLE->setReadOnly(false);

        horizontalLayout_2->addWidget(filenameLE);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        taskWidget = new QWidget(infoWidget);
        taskWidget->setObjectName(QStringLiteral("taskWidget"));
        taskWidget->setMinimumSize(QSize(200, 80));
        taskWidget->setMaximumSize(QSize(200, 80));
        minBtn = new QPushButton(taskWidget);
        minBtn->setObjectName(QStringLiteral("minBtn"));
        minBtn->setGeometry(QRect(40, 0, 40, 40));
        closeBtn = new QPushButton(taskWidget);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));
        closeBtn->setGeometry(QRect(140, 0, 40, 40));

        horizontalLayout_2->addWidget(taskWidget);


        gridLayout->addWidget(infoWidget, 0, 0, 1, 3);

        btnWidget = new QWidget(programDialog);
        btnWidget->setObjectName(QStringLiteral("btnWidget"));
        btnWidget->setMinimumSize(QSize(1280, 80));
        horizontalLayout = new QHBoxLayout(btnWidget);
        horizontalLayout->setSpacing(20);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(20, 0, 0, 0);
        openfileBtn = new QPushButton(btnWidget);
        openfileBtn->setObjectName(QStringLiteral("openfileBtn"));
        openfileBtn->setMinimumSize(QSize(50, 50));

        horizontalLayout->addWidget(openfileBtn);

        savefileBtn = new QPushButton(btnWidget);
        savefileBtn->setObjectName(QStringLiteral("savefileBtn"));
        savefileBtn->setMinimumSize(QSize(50, 50));

        horizontalLayout->addWidget(savefileBtn);

        newfileBtn = new QPushButton(btnWidget);
        newfileBtn->setObjectName(QStringLiteral("newfileBtn"));
        newfileBtn->setMinimumSize(QSize(50, 50));

        horizontalLayout->addWidget(newfileBtn);

        topfileBtn = new QPushButton(btnWidget);
        topfileBtn->setObjectName(QStringLiteral("topfileBtn"));
        topfileBtn->setMinimumSize(QSize(50, 50));

        horizontalLayout->addWidget(topfileBtn);

        downfileBtn = new QPushButton(btnWidget);
        downfileBtn->setObjectName(QStringLiteral("downfileBtn"));
        downfileBtn->setMinimumSize(QSize(50, 50));

        horizontalLayout->addWidget(downfileBtn);

        deletefileBtn = new QPushButton(btnWidget);
        deletefileBtn->setObjectName(QStringLiteral("deletefileBtn"));
        deletefileBtn->setMinimumSize(QSize(50, 50));

        horizontalLayout->addWidget(deletefileBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addWidget(btnWidget, 1, 0, 1, 3);

        groupWidget = new QWidget(programDialog);
        groupWidget->setObjectName(QStringLiteral("groupWidget"));
        groupWidget->setMinimumSize(QSize(210, 200));
        groupWidget->setMaximumSize(QSize(210, 16777215));
        verticalLayout_5 = new QVBoxLayout(groupWidget);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 10, 0, 30);
        peqItem1_2 = new QWidget(groupWidget);
        peqItem1_2->setObjectName(QStringLiteral("peqItem1_2"));
        peqItem1_2->setMinimumSize(QSize(210, 30));
        peqItem1_2->setMaximumSize(QSize(16777215, 50));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font5.setPointSize(12);
        peqItem1_2->setFont(font5);
        horizontalLayout_9 = new QHBoxLayout(peqItem1_2);
        horizontalLayout_9->setSpacing(5);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(5, 0, 5, 0);
        freqLab = new QLabel(peqItem1_2);
        freqLab->setObjectName(QStringLiteral("freqLab"));
        freqLab->setMinimumSize(QSize(60, 30));
        freqLab->setFont(font5);
        freqLab->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(freqLab);

        freqLE = new QLineEdit(peqItem1_2);
        freqLE->setObjectName(QStringLiteral("freqLE"));
        freqLE->setMinimumSize(QSize(60, 30));
        freqLE->setMaximumSize(QSize(100, 16777215));
        freqLE->setFont(font5);

        horizontalLayout_9->addWidget(freqLE);

        pfreqUnit = new QLabel(peqItem1_2);
        pfreqUnit->setObjectName(QStringLiteral("pfreqUnit"));
        pfreqUnit->setMinimumSize(QSize(0, 30));
        pfreqUnit->setFont(font5);

        horizontalLayout_9->addWidget(pfreqUnit);


        verticalLayout_5->addWidget(peqItem1_2);

        peqItem1_3 = new QWidget(groupWidget);
        peqItem1_3->setObjectName(QStringLiteral("peqItem1_3"));
        peqItem1_3->setMinimumSize(QSize(210, 30));
        peqItem1_3->setMaximumSize(QSize(16777215, 50));
        peqItem1_3->setFont(font5);
        horizontalLayout_10 = new QHBoxLayout(peqItem1_3);
        horizontalLayout_10->setSpacing(5);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(5, 0, 30, 0);
        failstepLab = new QLabel(peqItem1_3);
        failstepLab->setObjectName(QStringLiteral("failstepLab"));
        failstepLab->setMinimumSize(QSize(60, 30));
        failstepLab->setFont(font5);
        failstepLab->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(failstepLab);

        failstepCBox = new QComboBox(peqItem1_3);
        failstepCBox->setObjectName(QStringLiteral("failstepCBox"));
        failstepCBox->setMinimumSize(QSize(90, 30));

        horizontalLayout_10->addWidget(failstepCBox);


        verticalLayout_5->addWidget(peqItem1_3);

        peqItem1_4 = new QWidget(groupWidget);
        peqItem1_4->setObjectName(QStringLiteral("peqItem1_4"));
        peqItem1_4->setMinimumSize(QSize(210, 30));
        peqItem1_4->setMaximumSize(QSize(16777215, 50));
        peqItem1_4->setFont(font5);
        horizontalLayout_11 = new QHBoxLayout(peqItem1_4);
        horizontalLayout_11->setSpacing(5);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(5, 0, 30, 0);
        powerLab = new QLabel(peqItem1_4);
        powerLab->setObjectName(QStringLiteral("powerLab"));
        powerLab->setMinimumSize(QSize(60, 30));
        powerLab->setFont(font5);
        powerLab->setAlignment(Qt::AlignCenter);

        horizontalLayout_11->addWidget(powerLab);

        powerCBox = new QComboBox(peqItem1_4);
        powerCBox->setObjectName(QStringLiteral("powerCBox"));
        powerCBox->setMinimumSize(QSize(90, 30));

        horizontalLayout_11->addWidget(powerCBox);


        verticalLayout_5->addWidget(peqItem1_4);

        peqItem1_5 = new QWidget(groupWidget);
        peqItem1_5->setObjectName(QStringLiteral("peqItem1_5"));
        peqItem1_5->setMinimumSize(QSize(210, 30));
        peqItem1_5->setMaximumSize(QSize(16777215, 50));
        peqItem1_5->setFont(font5);
        horizontalLayout_12 = new QHBoxLayout(peqItem1_5);
        horizontalLayout_12->setSpacing(5);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(5, 0, 30, 0);
        groupConnLab = new QLabel(peqItem1_5);
        groupConnLab->setObjectName(QStringLiteral("groupConnLab"));
        groupConnLab->setMinimumSize(QSize(60, 30));
        groupConnLab->setFont(font5);
        groupConnLab->setAlignment(Qt::AlignCenter);

        horizontalLayout_12->addWidget(groupConnLab);

        groupConnCBox = new QComboBox(peqItem1_5);
        groupConnCBox->setObjectName(QStringLiteral("groupConnCBox"));
        groupConnCBox->setMinimumSize(QSize(90, 30));

        horizontalLayout_12->addWidget(groupConnCBox);


        verticalLayout_5->addWidget(peqItem1_5);


        gridLayout->addWidget(groupWidget, 3, 2, 1, 1);


        retranslateUi(programDialog);

        itemStackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(programDialog);
    } // setupUi

    void retranslateUi(QDialog *programDialog)
    {
        programDialog->setWindowTitle(QApplication::translate("programDialog", "Dialog", Q_NULLPTR));
        titleLab->setText(QApplication::translate("programDialog", "\347\273\235\347\274\230", Q_NULLPTR));
        irTestSetLab->setText(QApplication::translate("programDialog", "\346\265\213\350\257\225\347\224\265\345\216\213:", Q_NULLPTR));
        irTestSetUnit->setText(QApplication::translate("programDialog", "0.1-3.0 KV             ", Q_NULLPTR));
        irTestModeLab->setText(QApplication::translate("programDialog", "\350\277\236\346\216\245\346\250\241\345\274\217:", Q_NULLPTR));
        irTestModeCBox->clear();
        irTestModeCBox->insertItems(0, QStringList()
         << QApplication::translate("programDialog", "\347\273\247\347\273\255", Q_NULLPTR)
         << QApplication::translate("programDialog", "\345\201\234\346\255\242", Q_NULLPTR)
         << QApplication::translate("programDialog", "\345\215\225\346\255\245", Q_NULLPTR)
        );
        irTestModeLab1->setText(QString());
        irTestValLowLab->setText(QApplication::translate("programDialog", "\347\224\265\351\230\273\344\270\213\351\231\220:", Q_NULLPTR));
        irTestValLowUnit->setText(QApplication::translate("programDialog", "0.1-10000.0 Mohm", Q_NULLPTR));
        irTestValHighLab->setText(QApplication::translate("programDialog", "\347\224\265\351\230\273\344\270\212\351\231\220:", Q_NULLPTR));
        irTestValHighUnit->setText(QApplication::translate("programDialog", "0.1-10000.0 Mohm", Q_NULLPTR));
        irTestCompLab->setText(QApplication::translate("programDialog", "   \350\241\245\345\201\277\345\200\274:", Q_NULLPTR));
        irTestCompUnit->setText(QApplication::translate("programDialog", "0.03-55000 Gohm ", Q_NULLPTR));
        irTestTimeLab->setText(QApplication::translate("programDialog", "\346\265\213\350\257\225\346\227\266\351\227\264:", Q_NULLPTR));
        irTestTimeUnit->setText(QApplication::translate("programDialog", "1.0-999.9 S            ", Q_NULLPTR));
        titleLab2->setText(QApplication::translate("programDialog", "\347\224\265\344\275\215\345\235\207\350\241\241", Q_NULLPTR));
        peqTestSetLab->setText(QApplication::translate("programDialog", "\346\265\213\350\257\225\347\224\265\346\265\201:", Q_NULLPTR));
        peqTestSetUnit->setText(QApplication::translate("programDialog", "2.0-32.0 A          ", Q_NULLPTR));
        peqTestModeLab->setText(QApplication::translate("programDialog", "\350\277\236\346\216\245\346\250\241\345\274\217:", Q_NULLPTR));
        peqTestModeCBox->clear();
        peqTestModeCBox->insertItems(0, QStringList()
         << QApplication::translate("programDialog", "\347\273\247\347\273\255", Q_NULLPTR)
         << QApplication::translate("programDialog", "\345\201\234\346\255\242", Q_NULLPTR)
         << QApplication::translate("programDialog", "\345\215\225\346\255\245", Q_NULLPTR)
        );
        Lab->setText(QString());
        peqTestValLowLab->setText(QApplication::translate("programDialog", "\347\224\265\351\230\273\344\270\213\351\231\220:", Q_NULLPTR));
        peqTestValLowUnit->setText(QApplication::translate("programDialog", "0.0-660.0 mohm", Q_NULLPTR));
        peqTestValHighLab->setText(QApplication::translate("programDialog", "\347\224\265\351\230\273\344\270\212\351\231\220:", Q_NULLPTR));
        peqTestValHighUnit->setText(QApplication::translate("programDialog", "0.0-660.0 mohm  ", Q_NULLPTR));
        peqTestCompLab->setText(QApplication::translate("programDialog", "   \350\241\245\345\201\277\345\200\274:", Q_NULLPTR));
        peqTestCompUnit->setText(QApplication::translate("programDialog", "0.0-100 mohm   ", Q_NULLPTR));
        peqTestTimeLab->setText(QApplication::translate("programDialog", "\346\265\213\350\257\225\346\227\266\351\227\264:", Q_NULLPTR));
        peqTestTimeUnit->setText(QApplication::translate("programDialog", "1.0-999.9 S          ", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = itemListWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("programDialog", "\345\272\217\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = itemListWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("programDialog", "\346\265\213\350\257\225\351\241\271", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem = itemTreeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("programDialog", "\346\265\213\350\257\225\351\241\271", Q_NULLPTR));

        const bool __sortingEnabled = itemTreeWidget->isSortingEnabled();
        itemTreeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = itemTreeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("programDialog", "\347\273\235\347\274\230", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem2 = itemTreeWidget->topLevelItem(1);
        ___qtreewidgetitem2->setText(0, QApplication::translate("programDialog", "\347\224\265\344\275\215\345\235\207\350\241\241", Q_NULLPTR));
        itemTreeWidget->setSortingEnabled(__sortingEnabled);

        label->setText(QApplication::translate("programDialog", "icon", Q_NULLPTR));
        filenameLab->setText(QApplication::translate("programDialog", "\346\226\207\344\273\266\345\220\215:", Q_NULLPTR));
        minBtn->setText(QApplication::translate("programDialog", "PushButton", Q_NULLPTR));
        closeBtn->setText(QApplication::translate("programDialog", "PushButton", Q_NULLPTR));
        openfileBtn->setText(QApplication::translate("programDialog", "\346\211\223\345\274\200", Q_NULLPTR));
        savefileBtn->setText(QApplication::translate("programDialog", "\344\277\235\345\255\230", Q_NULLPTR));
        newfileBtn->setText(QApplication::translate("programDialog", "\346\226\260\345\273\272", Q_NULLPTR));
        topfileBtn->setText(QApplication::translate("programDialog", "\344\270\212\347\247\273", Q_NULLPTR));
        downfileBtn->setText(QApplication::translate("programDialog", "\344\270\212\347\247\273", Q_NULLPTR));
        deletefileBtn->setText(QApplication::translate("programDialog", "\345\210\240\351\231\244", Q_NULLPTR));
        freqLab->setText(QApplication::translate("programDialog", "\351\242\221\347\216\207:", Q_NULLPTR));
        pfreqUnit->setText(QApplication::translate("programDialog", "Hz", Q_NULLPTR));
        failstepLab->setText(QApplication::translate("programDialog", "\351\201\207\345\244\261\350\264\245\346\255\245:", Q_NULLPTR));
        failstepCBox->clear();
        failstepCBox->insertItems(0, QStringList()
         << QApplication::translate("programDialog", "\347\273\247\347\273\255", Q_NULLPTR)
         << QApplication::translate("programDialog", "\345\201\234\346\255\242", Q_NULLPTR)
         << QApplication::translate("programDialog", "\345\215\225\346\255\245", Q_NULLPTR)
        );
        powerLab->setText(QApplication::translate("programDialog", "\345\231\250\345\205\267\347\261\273\345\236\213:", Q_NULLPTR));
        powerCBox->clear();
        powerCBox->insertItems(0, QStringList()
         << QApplication::translate("programDialog", "\345\215\225\351\241\271", Q_NULLPTR)
         << QApplication::translate("programDialog", "\344\270\211\347\233\270\344\270\211\347\272\277", Q_NULLPTR)
         << QApplication::translate("programDialog", "\344\270\211\347\233\270\345\233\233\347\272\277", Q_NULLPTR)
        );
        groupConnLab->setText(QApplication::translate("programDialog", "\347\273\204\350\277\236\346\216\245:", Q_NULLPTR));
        groupConnCBox->clear();
        groupConnCBox->insertItems(0, QStringList()
         << QApplication::translate("programDialog", "\345\205\263", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class programDialog: public Ui_programDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRAMDIALOG_H
