/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *taskWidget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *minBtn;
    QPushButton *closeBtn;
    QWidget *mainWidget;
    QVBoxLayout *verticalLayout;
    QLabel *nameLab;
    QWidget *mainBtnWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *testBtn;
    QPushButton *programBtn;
    QPushButton *reportBtn;
    QPushButton *settingBtn;
    QLabel *versionLab;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1280, 720);
        MainWindow->setMinimumSize(QSize(1280, 720));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setMinimumSize(QSize(1280, 720));
        centralWidget->setStyleSheet(QString::fromUtf8("#centralWidget{\n"
"border-image: url(:/icon/bg3.jpg);\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        taskWidget = new QWidget(centralWidget);
        taskWidget->setObjectName(QString::fromUtf8("taskWidget"));
        taskWidget->setMinimumSize(QSize(1280, 40));
        taskWidget->setMaximumSize(QSize(16777215, 40));
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
        horizontalLayout_2 = new QHBoxLayout(taskWidget);
        horizontalLayout_2->setSpacing(20);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 20, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        minBtn = new QPushButton(taskWidget);
        minBtn->setObjectName(QString::fromUtf8("minBtn"));
        minBtn->setMinimumSize(QSize(40, 40));
        minBtn->setMaximumSize(QSize(40, 40));
        minBtn->setIconSize(QSize(70, 70));
        minBtn->setFlat(true);

        horizontalLayout_2->addWidget(minBtn);

        closeBtn = new QPushButton(taskWidget);
        closeBtn->setObjectName(QString::fromUtf8("closeBtn"));
        closeBtn->setMinimumSize(QSize(40, 40));
        closeBtn->setMaximumSize(QSize(40, 40));
        closeBtn->setIconSize(QSize(30, 30));
        closeBtn->setFlat(true);

        horizontalLayout_2->addWidget(closeBtn);


        verticalLayout_2->addWidget(taskWidget);

        mainWidget = new QWidget(centralWidget);
        mainWidget->setObjectName(QString::fromUtf8("mainWidget"));
        mainWidget->setMinimumSize(QSize(1280, 480));
        mainWidget->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout = new QVBoxLayout(mainWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        nameLab = new QLabel(mainWidget);
        nameLab->setObjectName(QString::fromUtf8("nameLab"));
        nameLab->setMinimumSize(QSize(1280, 80));
        nameLab->setMaximumSize(QSize(16777215, 80));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(24);
        font.setBold(true);
        font.setWeight(75);
        nameLab->setFont(font);
        nameLab->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        nameLab->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(nameLab);

        mainBtnWidget = new QWidget(mainWidget);
        mainBtnWidget->setObjectName(QString::fromUtf8("mainBtnWidget"));
        mainBtnWidget->setMinimumSize(QSize(1280, 240));
        mainBtnWidget->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-image: url(:/icon/mode1.png);\n"
"	background-color: rgba(220, 220, 220, 150);\n"
"color: rgb(0, 0, 0);\n"
"}\n"
"QPushButton:hover{\n"
"color: rgb(0, 170, 255);\n"
"	border-image: url(:/icon/mode2.png);\n"
"background-color: rgba(255, 255, 255, 150);\n"
"}\n"
"\n"
"#testBtn{\n"
"	qproperty-icon: url(:/icon/menul.png);\n"
"}\n"
"#testBtn:hover{\n"
"	qproperty-icon: url(:/icon/menus1.png);\n"
"}"));
        horizontalLayout = new QHBoxLayout(mainBtnWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        testBtn = new QPushButton(mainBtnWidget);
        testBtn->setObjectName(QString::fromUtf8("testBtn"));
        testBtn->setMinimumSize(QSize(240, 60));
        testBtn->setMaximumSize(QSize(160, 50));
        testBtn->setSizeIncrement(QSize(0, 0));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        testBtn->setFont(font1);
        testBtn->setIconSize(QSize(40, 40));
        testBtn->setFlat(true);

        horizontalLayout->addWidget(testBtn);

        programBtn = new QPushButton(mainBtnWidget);
        programBtn->setObjectName(QString::fromUtf8("programBtn"));
        programBtn->setMinimumSize(QSize(240, 60));
        programBtn->setMaximumSize(QSize(160, 50));
        programBtn->setFont(font1);
        programBtn->setStyleSheet(QString::fromUtf8(""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/filel.png"), QSize(), QIcon::Normal, QIcon::Off);
        programBtn->setIcon(icon);
        programBtn->setIconSize(QSize(40, 40));
        programBtn->setFlat(true);

        horizontalLayout->addWidget(programBtn);

        reportBtn = new QPushButton(mainBtnWidget);
        reportBtn->setObjectName(QString::fromUtf8("reportBtn"));
        reportBtn->setMinimumSize(QSize(240, 60));
        reportBtn->setMaximumSize(QSize(160, 50));
        reportBtn->setFont(font1);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/addfilel.png"), QSize(), QIcon::Normal, QIcon::Off);
        reportBtn->setIcon(icon1);
        reportBtn->setIconSize(QSize(40, 40));
        reportBtn->setFlat(true);

        horizontalLayout->addWidget(reportBtn);

        settingBtn = new QPushButton(mainBtnWidget);
        settingBtn->setObjectName(QString::fromUtf8("settingBtn"));
        settingBtn->setMinimumSize(QSize(240, 60));
        settingBtn->setMaximumSize(QSize(160, 50));
        settingBtn->setFont(font1);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icon/setl.png"), QSize(), QIcon::Normal, QIcon::Off);
        settingBtn->setIcon(icon2);
        settingBtn->setIconSize(QSize(40, 40));
        settingBtn->setFlat(true);

        horizontalLayout->addWidget(settingBtn);


        verticalLayout->addWidget(mainBtnWidget);

        versionLab = new QLabel(mainWidget);
        versionLab->setObjectName(QString::fromUtf8("versionLab"));
        versionLab->setMinimumSize(QSize(1280, 40));
        versionLab->setMaximumSize(QSize(16777215, 40));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        versionLab->setFont(font2);
        versionLab->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(versionLab);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(2, 1);

        verticalLayout_2->addWidget(mainWidget);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\344\270\273\347\225\214\351\235\242", nullptr));
        minBtn->setText(QString());
        closeBtn->setText(QString());
        nameLab->setText(QCoreApplication::translate("MainWindow", "NE6882\346\216\247\345\210\266\350\275\257\344\273\266", nullptr));
        testBtn->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\346\265\213\350\257\225", nullptr));
        programBtn->setText(QCoreApplication::translate("MainWindow", "\347\250\213\345\272\217\347\274\226\350\276\221", nullptr));
        reportBtn->setText(QCoreApplication::translate("MainWindow", "\346\265\213\350\257\225\346\225\260\346\215\256", nullptr));
        settingBtn->setText(QCoreApplication::translate("MainWindow", "\347\263\273\347\273\237\350\256\276\347\275\256", nullptr));
        versionLab->setText(QCoreApplication::translate("MainWindow", "\350\275\257\344\273\266\347\211\210\346\234\254\345\217\267:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
