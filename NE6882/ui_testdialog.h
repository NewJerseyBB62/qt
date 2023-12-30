/********************************************************************************
** Form generated from reading UI file 'testdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTDIALOG_H
#define UI_TESTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_testDialog
{
public:
    QGridLayout *gridLayout;
    QWidget *topWidget;
    QVBoxLayout *verticalLayout_3;
    QWidget *testinfoWidget;
    QHBoxLayout *horizontalLayout_4;
    QLabel *testfileLab;
    QLineEdit *testfileValLab;
    QSpacerItem *horizontalSpacer_2;
    QWidget *taskWidget;
    QPushButton *minBtn;
    QPushButton *closeBtn;
    QWidget *testctrlWidget;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *starttestBtn;
    QPushButton *stoptestBtn;
    QPushButton *openfileBtn;
    QSpacerItem *horizontalSpacer;
    QTableWidget *testTableWidget;
    QWidget *testWidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *outputWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *outputLab;
    QLabel *outputValLab;
    QLabel *outputUnitLab;
    QWidget *testoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *testoutLab;
    QLabel *testoutValLab;
    QLabel *testoutUnitLab;
    QWidget *testtimeWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *testtimeLab;
    QLabel *testtimeValLab;
    QLabel *testtimeUnitLab;
    QWidget *testresultWidget;
    QGridLayout *gridLayout_2;
    QLabel *teststateLab;
    QWidget *infoWidget;
    QVBoxLayout *verticalLayout;
    QLabel *infoLab;
    QTableWidget *infoTableWidget;
    QLabel *resultLab;

    void setupUi(QDialog *testDialog)
    {
        if (testDialog->objectName().isEmpty())
            testDialog->setObjectName(QString::fromUtf8("testDialog"));
        testDialog->resize(1280, 720);
        testDialog->setMinimumSize(QSize(1280, 720));
        testDialog->setStyleSheet(QString::fromUtf8("#testDialog{\n"
"border-image: url(:/icon/bg3.jpg);\n"
"}"));
        gridLayout = new QGridLayout(testDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        topWidget = new QWidget(testDialog);
        topWidget->setObjectName(QString::fromUtf8("topWidget"));
        topWidget->setMinimumSize(QSize(1240, 120));
        verticalLayout_3 = new QVBoxLayout(topWidget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        testinfoWidget = new QWidget(topWidget);
        testinfoWidget->setObjectName(QString::fromUtf8("testinfoWidget"));
        testinfoWidget->setMinimumSize(QSize(1240, 60));
        horizontalLayout_4 = new QHBoxLayout(testinfoWidget);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        testfileLab = new QLabel(testinfoWidget);
        testfileLab->setObjectName(QString::fromUtf8("testfileLab"));
        testfileLab->setMinimumSize(QSize(200, 40));
        testfileLab->setMaximumSize(QSize(200, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(16);
        testfileLab->setFont(font);
        testfileLab->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(testfileLab);

        testfileValLab = new QLineEdit(testinfoWidget);
        testfileValLab->setObjectName(QString::fromUtf8("testfileValLab"));
        testfileValLab->setMinimumSize(QSize(400, 50));
        testfileValLab->setMaximumSize(QSize(400, 50));
        testfileValLab->setFont(font);
        testfileValLab->setStyleSheet(QString::fromUtf8("border-image: url(:/icon/lineeditl.png);"));

        horizontalLayout_4->addWidget(testfileValLab);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        taskWidget = new QWidget(testinfoWidget);
        taskWidget->setObjectName(QString::fromUtf8("taskWidget"));
        taskWidget->setMinimumSize(QSize(200, 60));
        taskWidget->setMaximumSize(QSize(200, 60));
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

        horizontalLayout_4->addWidget(taskWidget);


        verticalLayout_3->addWidget(testinfoWidget);

        testctrlWidget = new QWidget(topWidget);
        testctrlWidget->setObjectName(QString::fromUtf8("testctrlWidget"));
        testctrlWidget->setMinimumSize(QSize(1240, 60));
        testctrlWidget->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        horizontalLayout_5 = new QHBoxLayout(testctrlWidget);
        horizontalLayout_5->setSpacing(30);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(30, 0, 0, 0);
        starttestBtn = new QPushButton(testctrlWidget);
        starttestBtn->setObjectName(QString::fromUtf8("starttestBtn"));
        starttestBtn->setMinimumSize(QSize(120, 50));
        starttestBtn->setMaximumSize(QSize(120, 50));
        starttestBtn->setFont(font);
        starttestBtn->setFocusPolicy(Qt::NoFocus);
        starttestBtn->setStyleSheet(QString::fromUtf8(""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/startl.png"), QSize(), QIcon::Normal, QIcon::Off);
        starttestBtn->setIcon(icon);
        starttestBtn->setIconSize(QSize(25, 25));

        horizontalLayout_5->addWidget(starttestBtn);

        stoptestBtn = new QPushButton(testctrlWidget);
        stoptestBtn->setObjectName(QString::fromUtf8("stoptestBtn"));
        stoptestBtn->setMinimumSize(QSize(120, 50));
        stoptestBtn->setMaximumSize(QSize(120, 50));
        stoptestBtn->setFont(font);
        stoptestBtn->setFocusPolicy(Qt::NoFocus);
        stoptestBtn->setStyleSheet(QString::fromUtf8(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/stopl.png"), QSize(), QIcon::Normal, QIcon::Off);
        stoptestBtn->setIcon(icon1);
        stoptestBtn->setIconSize(QSize(25, 25));

        horizontalLayout_5->addWidget(stoptestBtn);

        openfileBtn = new QPushButton(testctrlWidget);
        openfileBtn->setObjectName(QString::fromUtf8("openfileBtn"));
        openfileBtn->setMinimumSize(QSize(120, 50));
        openfileBtn->setMaximumSize(QSize(120, 50));
        openfileBtn->setFont(font);
        openfileBtn->setFocusPolicy(Qt::NoFocus);
        openfileBtn->setStyleSheet(QString::fromUtf8(""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icon/addfilel.png"), QSize(), QIcon::Normal, QIcon::Off);
        openfileBtn->setIcon(icon2);
        openfileBtn->setIconSize(QSize(25, 25));

        horizontalLayout_5->addWidget(openfileBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 1);
        horizontalLayout_5->setStretch(2, 1);
        horizontalLayout_5->setStretch(3, 1);

        verticalLayout_3->addWidget(testctrlWidget);


        gridLayout->addWidget(topWidget, 0, 0, 1, 3);

        testTableWidget = new QTableWidget(testDialog);
        if (testTableWidget->columnCount() < 4)
            testTableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        testTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        testTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        testTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        testTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        testTableWidget->setObjectName(QString::fromUtf8("testTableWidget"));
        testTableWidget->setMinimumSize(QSize(340, 560));
        testTableWidget->setMaximumSize(QSize(300, 16777215));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        testTableWidget->setFont(font1);
        testTableWidget->setFocusPolicy(Qt::NoFocus);
        testTableWidget->setStyleSheet(QString::fromUtf8("QTableWidget{\n"
"border-radius: 20px;\n"
"border:none;\n"
"}\n"
"QTableWidget::item:selected{\n"
"	background-color: #E9EFF7;\n"
"}\n"
" "));
        testTableWidget->setFrameShape(QFrame::StyledPanel);
        testTableWidget->setFrameShadow(QFrame::Sunken);
        testTableWidget->setLineWidth(1);
        testTableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        testTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        testTableWidget->setDefaultDropAction(Qt::IgnoreAction);
        testTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        testTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        testTableWidget->setShowGrid(false);
        testTableWidget->setGridStyle(Qt::SolidLine);
        testTableWidget->setSortingEnabled(false);
        testTableWidget->setWordWrap(true);
        testTableWidget->setCornerButtonEnabled(true);
        testTableWidget->horizontalHeader()->setVisible(true);
        testTableWidget->verticalHeader()->setVisible(false);
        testTableWidget->verticalHeader()->setCascadingSectionResizes(false);
        testTableWidget->verticalHeader()->setMinimumSectionSize(36);
        testTableWidget->verticalHeader()->setDefaultSectionSize(30);

        gridLayout->addWidget(testTableWidget, 1, 0, 1, 1);

        testWidget = new QWidget(testDialog);
        testWidget->setObjectName(QString::fromUtf8("testWidget"));
        testWidget->setMinimumSize(QSize(640, 560));
        testWidget->setAutoFillBackground(false);
        testWidget->setStyleSheet(QString::fromUtf8("#testWidget{\n"
"background-color: rgb(255, 255, 255);\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(testWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        outputWidget = new QWidget(testWidget);
        outputWidget->setObjectName(QString::fromUtf8("outputWidget"));
        outputWidget->setMinimumSize(QSize(640, 150));
        horizontalLayout = new QHBoxLayout(outputWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, -1, 0, 0);
        outputLab = new QLabel(outputWidget);
        outputLab->setObjectName(QString::fromUtf8("outputLab"));
        outputLab->setMinimumSize(QSize(240, 50));
        outputLab->setMaximumSize(QSize(16777215, 50));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(24);
        outputLab->setFont(font2);
        outputLab->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(outputLab);

        outputValLab = new QLabel(outputWidget);
        outputValLab->setObjectName(QString::fromUtf8("outputValLab"));
        outputValLab->setMinimumSize(QSize(100, 50));
        outputValLab->setMaximumSize(QSize(16777215, 50));
        outputValLab->setFont(font2);
        outputValLab->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(outputValLab);

        outputUnitLab = new QLabel(outputWidget);
        outputUnitLab->setObjectName(QString::fromUtf8("outputUnitLab"));
        outputUnitLab->setMinimumSize(QSize(100, 50));
        outputUnitLab->setMaximumSize(QSize(16777215, 50));
        outputUnitLab->setFont(font2);

        horizontalLayout->addWidget(outputUnitLab);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);

        verticalLayout_2->addWidget(outputWidget);

        testoutWidget = new QWidget(testWidget);
        testoutWidget->setObjectName(QString::fromUtf8("testoutWidget"));
        testoutWidget->setMinimumSize(QSize(640, 150));
        horizontalLayout_2 = new QHBoxLayout(testoutWidget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        testoutLab = new QLabel(testoutWidget);
        testoutLab->setObjectName(QString::fromUtf8("testoutLab"));
        testoutLab->setMinimumSize(QSize(240, 50));
        testoutLab->setMaximumSize(QSize(16777215, 50));
        testoutLab->setFont(font2);
        testoutLab->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(testoutLab);

        testoutValLab = new QLabel(testoutWidget);
        testoutValLab->setObjectName(QString::fromUtf8("testoutValLab"));
        testoutValLab->setMinimumSize(QSize(100, 50));
        testoutValLab->setMaximumSize(QSize(16777215, 50));
        testoutValLab->setFont(font2);
        testoutValLab->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(testoutValLab);

        testoutUnitLab = new QLabel(testoutWidget);
        testoutUnitLab->setObjectName(QString::fromUtf8("testoutUnitLab"));
        testoutUnitLab->setMinimumSize(QSize(100, 50));
        testoutUnitLab->setMaximumSize(QSize(16777215, 50));
        testoutUnitLab->setFont(font2);

        horizontalLayout_2->addWidget(testoutUnitLab);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 1);

        verticalLayout_2->addWidget(testoutWidget);

        testtimeWidget = new QWidget(testWidget);
        testtimeWidget->setObjectName(QString::fromUtf8("testtimeWidget"));
        testtimeWidget->setMinimumSize(QSize(640, 150));
        horizontalLayout_3 = new QHBoxLayout(testtimeWidget);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        testtimeLab = new QLabel(testtimeWidget);
        testtimeLab->setObjectName(QString::fromUtf8("testtimeLab"));
        testtimeLab->setMinimumSize(QSize(240, 50));
        testtimeLab->setMaximumSize(QSize(16777215, 50));
        testtimeLab->setFont(font2);
        testtimeLab->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(testtimeLab);

        testtimeValLab = new QLabel(testtimeWidget);
        testtimeValLab->setObjectName(QString::fromUtf8("testtimeValLab"));
        testtimeValLab->setMinimumSize(QSize(100, 50));
        testtimeValLab->setMaximumSize(QSize(16777215, 50));
        testtimeValLab->setFont(font2);
        testtimeValLab->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(testtimeValLab);

        testtimeUnitLab = new QLabel(testtimeWidget);
        testtimeUnitLab->setObjectName(QString::fromUtf8("testtimeUnitLab"));
        testtimeUnitLab->setMinimumSize(QSize(100, 50));
        testtimeUnitLab->setMaximumSize(QSize(16777215, 50));
        testtimeUnitLab->setFont(font2);

        horizontalLayout_3->addWidget(testtimeUnitLab);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(2, 1);

        verticalLayout_2->addWidget(testtimeWidget);

        testresultWidget = new QWidget(testWidget);
        testresultWidget->setObjectName(QString::fromUtf8("testresultWidget"));
        testresultWidget->setMinimumSize(QSize(640, 110));
        gridLayout_2 = new QGridLayout(testresultWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        teststateLab = new QLabel(testresultWidget);
        teststateLab->setObjectName(QString::fromUtf8("teststateLab"));
        teststateLab->setMinimumSize(QSize(240, 50));
        teststateLab->setMaximumSize(QSize(240, 50));
        teststateLab->setFont(font2);
        teststateLab->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(teststateLab, 0, 0, 1, 1);


        verticalLayout_2->addWidget(testresultWidget);


        gridLayout->addWidget(testWidget, 1, 1, 1, 1);

        infoWidget = new QWidget(testDialog);
        infoWidget->setObjectName(QString::fromUtf8("infoWidget"));
        infoWidget->setMinimumSize(QSize(250, 560));
        infoWidget->setMaximumSize(QSize(250, 16777215));
        verticalLayout = new QVBoxLayout(infoWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        infoLab = new QLabel(infoWidget);
        infoLab->setObjectName(QString::fromUtf8("infoLab"));
        infoLab->setMinimumSize(QSize(250, 40));
        infoLab->setMaximumSize(QSize(250, 60));
        infoLab->setFont(font);
        infoLab->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(infoLab);

        infoTableWidget = new QTableWidget(infoWidget);
        if (infoTableWidget->columnCount() < 3)
            infoTableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        infoTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        infoTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        infoTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem6);
        if (infoTableWidget->rowCount() < 4)
            infoTableWidget->setRowCount(4);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        infoTableWidget->setVerticalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        infoTableWidget->setVerticalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        infoTableWidget->setVerticalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        infoTableWidget->setVerticalHeaderItem(3, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setTextAlignment(Qt::AlignCenter);
        infoTableWidget->setItem(0, 0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        infoTableWidget->setItem(0, 1, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setTextAlignment(Qt::AlignCenter);
        infoTableWidget->setItem(0, 2, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setTextAlignment(Qt::AlignCenter);
        infoTableWidget->setItem(1, 0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        infoTableWidget->setItem(1, 1, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        infoTableWidget->setItem(1, 2, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setTextAlignment(Qt::AlignCenter);
        infoTableWidget->setItem(2, 0, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        infoTableWidget->setItem(2, 1, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        infoTableWidget->setItem(2, 2, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        __qtablewidgetitem20->setTextAlignment(Qt::AlignCenter);
        infoTableWidget->setItem(3, 0, __qtablewidgetitem20);
        infoTableWidget->setObjectName(QString::fromUtf8("infoTableWidget"));
        infoTableWidget->setMinimumSize(QSize(250, 300));
        infoTableWidget->setMaximumSize(QSize(250, 300));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        infoTableWidget->setFont(font3);
        infoTableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        infoTableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        infoTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        infoTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        infoTableWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        infoTableWidget->horizontalHeader()->setVisible(false);
        infoTableWidget->horizontalHeader()->setHighlightSections(true);
        infoTableWidget->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(infoTableWidget);

        resultLab = new QLabel(infoWidget);
        resultLab->setObjectName(QString::fromUtf8("resultLab"));
        resultLab->setMinimumSize(QSize(250, 220));
        resultLab->setMaximumSize(QSize(250, 16777215));

        verticalLayout->addWidget(resultLab);


        gridLayout->addWidget(infoWidget, 1, 2, 1, 1);


        retranslateUi(testDialog);

        QMetaObject::connectSlotsByName(testDialog);
    } // setupUi

    void retranslateUi(QDialog *testDialog)
    {
        testDialog->setWindowTitle(QCoreApplication::translate("testDialog", "\346\265\213\350\257\225", nullptr));
        testfileLab->setText(QCoreApplication::translate("testDialog", "\346\265\213\350\257\225\346\226\207\344\273\266:  ", nullptr));
        minBtn->setText(QString());
        closeBtn->setText(QString());
#if QT_CONFIG(statustip)
        starttestBtn->setStatusTip(QCoreApplication::translate("testDialog", "\345\274\200\345\247\213\346\265\213\350\257\225", nullptr));
#endif // QT_CONFIG(statustip)
        starttestBtn->setText(QCoreApplication::translate("testDialog", "\345\274\200\345\247\213", nullptr));
#if QT_CONFIG(statustip)
        stoptestBtn->setStatusTip(QCoreApplication::translate("testDialog", "\345\201\234\346\255\242\346\265\213\350\257\225", nullptr));
#endif // QT_CONFIG(statustip)
        stoptestBtn->setText(QCoreApplication::translate("testDialog", "\345\201\234\346\255\242", nullptr));
#if QT_CONFIG(statustip)
        openfileBtn->setStatusTip(QCoreApplication::translate("testDialog", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(statustip)
        openfileBtn->setText(QCoreApplication::translate("testDialog", "\346\211\223\345\274\200", nullptr));
        QTableWidgetItem *___qtablewidgetitem = testTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("testDialog", "\345\272\217\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = testTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("testDialog", "\346\265\213\350\257\225\351\241\271\347\233\256", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = testTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("testDialog", "\346\265\213\350\257\225\347\212\266\346\200\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = testTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("testDialog", "\346\265\213\350\257\225\347\273\223\346\236\234", nullptr));
        outputLab->setText(QCoreApplication::translate("testDialog", "\350\276\223\345\207\272:", nullptr));
        outputValLab->setText(QCoreApplication::translate("testDialog", "0.00", nullptr));
        outputUnitLab->setText(QCoreApplication::translate("testDialog", "V", nullptr));
        testoutLab->setText(QCoreApplication::translate("testDialog", "\347\224\265\351\230\273:", nullptr));
        testoutValLab->setText(QCoreApplication::translate("testDialog", "0.00", nullptr));
        testoutUnitLab->setText(QCoreApplication::translate("testDialog", "ohm", nullptr));
        testtimeLab->setText(QCoreApplication::translate("testDialog", "\346\265\213\350\257\225\346\227\266\351\227\264:", nullptr));
        testtimeValLab->setText(QCoreApplication::translate("testDialog", "0.0", nullptr));
        testtimeUnitLab->setText(QCoreApplication::translate("testDialog", "S", nullptr));
        teststateLab->setText(QCoreApplication::translate("testDialog", "\346\265\213\350\257\225\347\212\266\346\200\201", nullptr));
        infoLab->setText(QCoreApplication::translate("testDialog", "\347\273\204\345\205\254\345\205\261\344\277\241\346\201\257", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = infoTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("testDialog", "\351\241\271\347\233\256", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = infoTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("testDialog", "\345\200\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = infoTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("testDialog", "\345\215\225\344\275\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = infoTableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("testDialog", "\347\224\265\345\216\213\351\242\221\347\216\207", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = infoTableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("testDialog", "\351\201\207\345\244\261\350\264\245\346\255\245", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = infoTableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("testDialog", "\345\231\250\345\205\267\347\261\273\345\236\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = infoTableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("testDialog", "\347\273\204\350\277\236\346\216\245", nullptr));

        const bool __sortingEnabled = infoTableWidget->isSortingEnabled();
        infoTableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem11 = infoTableWidget->item(0, 0);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("testDialog", "\347\224\265\345\216\213\351\242\221\347\216\207", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = infoTableWidget->item(0, 2);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("testDialog", "HZ", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = infoTableWidget->item(1, 0);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("testDialog", "\351\201\207\345\244\261\350\264\245\346\255\245", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = infoTableWidget->item(2, 0);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("testDialog", "\345\231\250\345\205\267\347\261\273\345\236\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = infoTableWidget->item(3, 0);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("testDialog", "\347\273\204\350\277\236\346\216\245", nullptr));
        infoTableWidget->setSortingEnabled(__sortingEnabled);

        resultLab->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class testDialog: public Ui_testDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTDIALOG_H
