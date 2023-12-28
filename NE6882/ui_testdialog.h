/********************************************************************************
** Form generated from reading UI file 'testdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTDIALOG_H
#define UI_TESTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
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
    QTableWidget *testTableWidget;
    QWidget *infoWidget;
    QVBoxLayout *verticalLayout;
    QLabel *infoLab;
    QTableWidget *infoTableWidget;
    QLabel *resultLab;
    QWidget *topWidget;
    QVBoxLayout *verticalLayout_3;
    QWidget *testinfoWidget;
    QHBoxLayout *horizontalLayout_4;
    QLabel *testfileLab;
    QLabel *testfileValLab;
    QWidget *taskWidget;
    QPushButton *minBtn;
    QPushButton *closeBtn;
    QWidget *testctrlWidget;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *starttestBtn;
    QPushButton *stoptestBtn;
    QPushButton *openfileBtn;
    QSpacerItem *horizontalSpacer;
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

    void setupUi(QDialog *testDialog)
    {
        if (testDialog->objectName().isEmpty())
            testDialog->setObjectName(QStringLiteral("testDialog"));
        testDialog->resize(1280, 720);
        testDialog->setMinimumSize(QSize(1280, 720));
        gridLayout = new QGridLayout(testDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(0);
        gridLayout->setVerticalSpacing(20);
        gridLayout->setContentsMargins(20, 0, 20, 20);
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
        testTableWidget->setObjectName(QStringLiteral("testTableWidget"));
        testTableWidget->setMinimumSize(QSize(340, 560));
        testTableWidget->setMaximumSize(QSize(300, 16777215));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        testTableWidget->setFont(font);
        testTableWidget->setFrameShape(QFrame::StyledPanel);
        testTableWidget->setFrameShadow(QFrame::Sunken);
        testTableWidget->setLineWidth(1);
        testTableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        testTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        testTableWidget->setDefaultDropAction(Qt::IgnoreAction);
        testTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        testTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        testTableWidget->setShowGrid(true);
        testTableWidget->setGridStyle(Qt::SolidLine);
        testTableWidget->setSortingEnabled(false);
        testTableWidget->setWordWrap(true);
        testTableWidget->setCornerButtonEnabled(true);
        testTableWidget->horizontalHeader()->setVisible(true);
        testTableWidget->verticalHeader()->setVisible(false);
        testTableWidget->verticalHeader()->setCascadingSectionResizes(false);
        testTableWidget->verticalHeader()->setDefaultSectionSize(30);
        testTableWidget->verticalHeader()->setMinimumSectionSize(36);

        gridLayout->addWidget(testTableWidget, 1, 0, 1, 1);

        infoWidget = new QWidget(testDialog);
        infoWidget->setObjectName(QStringLiteral("infoWidget"));
        infoWidget->setMinimumSize(QSize(250, 560));
        infoWidget->setMaximumSize(QSize(250, 16777215));
        verticalLayout = new QVBoxLayout(infoWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        infoLab = new QLabel(infoWidget);
        infoLab->setObjectName(QStringLiteral("infoLab"));
        infoLab->setMinimumSize(QSize(250, 40));
        infoLab->setMaximumSize(QSize(250, 60));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(16);
        infoLab->setFont(font1);
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
        infoTableWidget->setObjectName(QStringLiteral("infoTableWidget"));
        infoTableWidget->setMinimumSize(QSize(250, 300));
        infoTableWidget->setMaximumSize(QSize(250, 300));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        infoTableWidget->setFont(font2);
        infoTableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        infoTableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        infoTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        infoTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        infoTableWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        infoTableWidget->horizontalHeader()->setVisible(true);
        infoTableWidget->horizontalHeader()->setHighlightSections(true);
        infoTableWidget->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(infoTableWidget);

        resultLab = new QLabel(infoWidget);
        resultLab->setObjectName(QStringLiteral("resultLab"));
        resultLab->setMinimumSize(QSize(250, 220));
        resultLab->setMaximumSize(QSize(250, 16777215));

        verticalLayout->addWidget(resultLab);


        gridLayout->addWidget(infoWidget, 1, 2, 1, 1);

        topWidget = new QWidget(testDialog);
        topWidget->setObjectName(QStringLiteral("topWidget"));
        topWidget->setMinimumSize(QSize(1240, 120));
        verticalLayout_3 = new QVBoxLayout(topWidget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        testinfoWidget = new QWidget(topWidget);
        testinfoWidget->setObjectName(QStringLiteral("testinfoWidget"));
        testinfoWidget->setMinimumSize(QSize(1240, 60));
        horizontalLayout_4 = new QHBoxLayout(testinfoWidget);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        testfileLab = new QLabel(testinfoWidget);
        testfileLab->setObjectName(QStringLiteral("testfileLab"));
        testfileLab->setMinimumSize(QSize(200, 40));
        testfileLab->setMaximumSize(QSize(200, 40));
        testfileLab->setFont(font1);
        testfileLab->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(testfileLab);

        testfileValLab = new QLabel(testinfoWidget);
        testfileValLab->setObjectName(QStringLiteral("testfileValLab"));
        testfileValLab->setMinimumSize(QSize(400, 40));
        testfileValLab->setMaximumSize(QSize(16777215, 40));
        testfileValLab->setFont(font1);

        horizontalLayout_4->addWidget(testfileValLab);

        taskWidget = new QWidget(testinfoWidget);
        taskWidget->setObjectName(QStringLiteral("taskWidget"));
        taskWidget->setMinimumSize(QSize(200, 60));
        taskWidget->setMaximumSize(QSize(200, 60));
        minBtn = new QPushButton(taskWidget);
        minBtn->setObjectName(QStringLiteral("minBtn"));
        minBtn->setGeometry(QRect(70, 0, 40, 40));
        closeBtn = new QPushButton(taskWidget);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));
        closeBtn->setGeometry(QRect(140, 0, 40, 40));

        horizontalLayout_4->addWidget(taskWidget);


        verticalLayout_3->addWidget(testinfoWidget);

        testctrlWidget = new QWidget(topWidget);
        testctrlWidget->setObjectName(QStringLiteral("testctrlWidget"));
        testctrlWidget->setMinimumSize(QSize(1240, 60));
        horizontalLayout_5 = new QHBoxLayout(testctrlWidget);
        horizontalLayout_5->setSpacing(30);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(30, 0, 0, 0);
        starttestBtn = new QPushButton(testctrlWidget);
        starttestBtn->setObjectName(QStringLiteral("starttestBtn"));
        starttestBtn->setMinimumSize(QSize(50, 50));
        starttestBtn->setMaximumSize(QSize(50, 50));

        horizontalLayout_5->addWidget(starttestBtn);

        stoptestBtn = new QPushButton(testctrlWidget);
        stoptestBtn->setObjectName(QStringLiteral("stoptestBtn"));
        stoptestBtn->setMinimumSize(QSize(50, 50));
        stoptestBtn->setMaximumSize(QSize(50, 50));

        horizontalLayout_5->addWidget(stoptestBtn);

        openfileBtn = new QPushButton(testctrlWidget);
        openfileBtn->setObjectName(QStringLiteral("openfileBtn"));
        openfileBtn->setMinimumSize(QSize(50, 50));
        openfileBtn->setMaximumSize(QSize(50, 50));

        horizontalLayout_5->addWidget(openfileBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 1);
        horizontalLayout_5->setStretch(2, 1);
        horizontalLayout_5->setStretch(3, 1);

        verticalLayout_3->addWidget(testctrlWidget);


        gridLayout->addWidget(topWidget, 0, 0, 1, 3);

        testWidget = new QWidget(testDialog);
        testWidget->setObjectName(QStringLiteral("testWidget"));
        testWidget->setMinimumSize(QSize(650, 560));
        testWidget->setAutoFillBackground(false);
        testWidget->setStyleSheet(QLatin1String("#testWidget{\n"
"background-color: rgb(255, 255, 255);\n"
"border: 2px solid rgb(191, 191, 191);\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(testWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        outputWidget = new QWidget(testWidget);
        outputWidget->setObjectName(QStringLiteral("outputWidget"));
        outputWidget->setMinimumSize(QSize(650, 150));
        horizontalLayout = new QHBoxLayout(outputWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, -1, 0, 0);
        outputLab = new QLabel(outputWidget);
        outputLab->setObjectName(QStringLiteral("outputLab"));
        outputLab->setMinimumSize(QSize(240, 50));
        outputLab->setMaximumSize(QSize(240, 50));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(24);
        outputLab->setFont(font3);
        outputLab->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(outputLab);

        outputValLab = new QLabel(outputWidget);
        outputValLab->setObjectName(QStringLiteral("outputValLab"));
        outputValLab->setMinimumSize(QSize(100, 50));
        outputValLab->setMaximumSize(QSize(100, 50));
        outputValLab->setFont(font3);
        outputValLab->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(outputValLab);

        outputUnitLab = new QLabel(outputWidget);
        outputUnitLab->setObjectName(QStringLiteral("outputUnitLab"));
        outputUnitLab->setMinimumSize(QSize(100, 50));
        outputUnitLab->setMaximumSize(QSize(100, 50));
        outputUnitLab->setFont(font3);

        horizontalLayout->addWidget(outputUnitLab);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);

        verticalLayout_2->addWidget(outputWidget);

        testoutWidget = new QWidget(testWidget);
        testoutWidget->setObjectName(QStringLiteral("testoutWidget"));
        testoutWidget->setMinimumSize(QSize(650, 150));
        horizontalLayout_2 = new QHBoxLayout(testoutWidget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        testoutLab = new QLabel(testoutWidget);
        testoutLab->setObjectName(QStringLiteral("testoutLab"));
        testoutLab->setMinimumSize(QSize(240, 50));
        testoutLab->setMaximumSize(QSize(240, 50));
        testoutLab->setFont(font3);
        testoutLab->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(testoutLab);

        testoutValLab = new QLabel(testoutWidget);
        testoutValLab->setObjectName(QStringLiteral("testoutValLab"));
        testoutValLab->setMinimumSize(QSize(100, 50));
        testoutValLab->setMaximumSize(QSize(100, 50));
        testoutValLab->setFont(font3);
        testoutValLab->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(testoutValLab);

        testoutUnitLab = new QLabel(testoutWidget);
        testoutUnitLab->setObjectName(QStringLiteral("testoutUnitLab"));
        testoutUnitLab->setMinimumSize(QSize(100, 50));
        testoutUnitLab->setMaximumSize(QSize(100, 50));
        testoutUnitLab->setFont(font3);

        horizontalLayout_2->addWidget(testoutUnitLab);

        horizontalLayout_2->setStretch(0, 2);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 1);

        verticalLayout_2->addWidget(testoutWidget);

        testtimeWidget = new QWidget(testWidget);
        testtimeWidget->setObjectName(QStringLiteral("testtimeWidget"));
        testtimeWidget->setMinimumSize(QSize(650, 150));
        horizontalLayout_3 = new QHBoxLayout(testtimeWidget);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        testtimeLab = new QLabel(testtimeWidget);
        testtimeLab->setObjectName(QStringLiteral("testtimeLab"));
        testtimeLab->setMinimumSize(QSize(240, 50));
        testtimeLab->setMaximumSize(QSize(240, 50));
        testtimeLab->setFont(font3);
        testtimeLab->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(testtimeLab);

        testtimeValLab = new QLabel(testtimeWidget);
        testtimeValLab->setObjectName(QStringLiteral("testtimeValLab"));
        testtimeValLab->setMinimumSize(QSize(100, 50));
        testtimeValLab->setMaximumSize(QSize(100, 50));
        testtimeValLab->setFont(font3);
        testtimeValLab->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(testtimeValLab);

        testtimeUnitLab = new QLabel(testtimeWidget);
        testtimeUnitLab->setObjectName(QStringLiteral("testtimeUnitLab"));
        testtimeUnitLab->setMinimumSize(QSize(100, 50));
        testtimeUnitLab->setMaximumSize(QSize(100, 50));
        testtimeUnitLab->setFont(font3);

        horizontalLayout_3->addWidget(testtimeUnitLab);

        horizontalLayout_3->setStretch(0, 2);
        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(2, 1);

        verticalLayout_2->addWidget(testtimeWidget);

        testresultWidget = new QWidget(testWidget);
        testresultWidget->setObjectName(QStringLiteral("testresultWidget"));
        testresultWidget->setMinimumSize(QSize(650, 110));
        gridLayout_2 = new QGridLayout(testresultWidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        teststateLab = new QLabel(testresultWidget);
        teststateLab->setObjectName(QStringLiteral("teststateLab"));
        teststateLab->setMinimumSize(QSize(240, 50));
        teststateLab->setMaximumSize(QSize(240, 50));
        teststateLab->setFont(font3);
        teststateLab->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(teststateLab, 0, 0, 1, 1);


        verticalLayout_2->addWidget(testresultWidget);


        gridLayout->addWidget(testWidget, 1, 1, 1, 1);


        retranslateUi(testDialog);

        QMetaObject::connectSlotsByName(testDialog);
    } // setupUi

    void retranslateUi(QDialog *testDialog)
    {
        testDialog->setWindowTitle(QApplication::translate("testDialog", "\346\265\213\350\257\225", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = testTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("testDialog", "\345\272\217\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = testTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("testDialog", "\346\265\213\350\257\225\351\241\271\347\233\256", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = testTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("testDialog", "\346\265\213\350\257\225\347\212\266\346\200\201", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = testTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("testDialog", "\346\265\213\350\257\225\347\273\223\346\236\234", Q_NULLPTR));
        infoLab->setText(QApplication::translate("testDialog", "\347\273\204\345\205\254\345\205\261\344\277\241\346\201\257", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = infoTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("testDialog", "\351\241\271\347\233\256", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = infoTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("testDialog", "\345\200\274", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = infoTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem6->setText(QApplication::translate("testDialog", "\345\215\225\344\275\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = infoTableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem7->setText(QApplication::translate("testDialog", "\347\224\265\345\216\213\351\242\221\347\216\207", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = infoTableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem8->setText(QApplication::translate("testDialog", "\351\201\207\345\244\261\350\264\245\346\255\245", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = infoTableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem9->setText(QApplication::translate("testDialog", "\345\231\250\345\205\267\347\261\273\345\236\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = infoTableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem10->setText(QApplication::translate("testDialog", "\347\273\204\350\277\236\346\216\245", Q_NULLPTR));

        const bool __sortingEnabled = infoTableWidget->isSortingEnabled();
        infoTableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem11 = infoTableWidget->item(0, 0);
        ___qtablewidgetitem11->setText(QApplication::translate("testDialog", "\347\224\265\345\216\213\351\242\221\347\216\207", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = infoTableWidget->item(0, 2);
        ___qtablewidgetitem12->setText(QApplication::translate("testDialog", "HZ", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem13 = infoTableWidget->item(1, 0);
        ___qtablewidgetitem13->setText(QApplication::translate("testDialog", "\351\201\207\345\244\261\350\264\245\346\255\245", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem14 = infoTableWidget->item(2, 0);
        ___qtablewidgetitem14->setText(QApplication::translate("testDialog", "\345\231\250\345\205\267\347\261\273\345\236\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem15 = infoTableWidget->item(3, 0);
        ___qtablewidgetitem15->setText(QApplication::translate("testDialog", "\347\273\204\350\277\236\346\216\245", Q_NULLPTR));
        infoTableWidget->setSortingEnabled(__sortingEnabled);

        resultLab->setText(QString());
        testfileLab->setText(QApplication::translate("testDialog", "\346\265\213\350\257\225\346\226\207\344\273\266:  ", Q_NULLPTR));
        testfileValLab->setText(QString());
        minBtn->setText(QApplication::translate("testDialog", "min", Q_NULLPTR));
        closeBtn->setText(QApplication::translate("testDialog", "close", Q_NULLPTR));
        starttestBtn->setText(QApplication::translate("testDialog", "start", Q_NULLPTR));
        stoptestBtn->setText(QApplication::translate("testDialog", "stop", Q_NULLPTR));
        openfileBtn->setText(QApplication::translate("testDialog", "open", Q_NULLPTR));
        outputLab->setText(QApplication::translate("testDialog", "\350\276\223\345\207\272:", Q_NULLPTR));
        outputValLab->setText(QApplication::translate("testDialog", "0.00", Q_NULLPTR));
        outputUnitLab->setText(QApplication::translate("testDialog", "V", Q_NULLPTR));
        testoutLab->setText(QApplication::translate("testDialog", "\347\224\265\351\230\273:", Q_NULLPTR));
        testoutValLab->setText(QApplication::translate("testDialog", "0.00", Q_NULLPTR));
        testoutUnitLab->setText(QApplication::translate("testDialog", "ohm", Q_NULLPTR));
        testtimeLab->setText(QApplication::translate("testDialog", "\346\265\213\350\257\225\346\227\266\351\227\264:", Q_NULLPTR));
        testtimeValLab->setText(QApplication::translate("testDialog", "0.0", Q_NULLPTR));
        testtimeUnitLab->setText(QApplication::translate("testDialog", "S", Q_NULLPTR));
        teststateLab->setText(QApplication::translate("testDialog", "\346\265\213\350\257\225\347\212\266\346\200\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class testDialog: public Ui_testDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTDIALOG_H
