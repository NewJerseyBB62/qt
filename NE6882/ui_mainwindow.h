/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1920, 1080);
        MainWindow->setMinimumSize(QSize(1280, 720));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        taskWidget = new QWidget(centralWidget);
        taskWidget->setObjectName(QStringLiteral("taskWidget"));
        taskWidget->setMinimumSize(QSize(200, 40));
        taskWidget->setMaximumSize(QSize(16777215, 40));
        horizontalLayout_2 = new QHBoxLayout(taskWidget);
        horizontalLayout_2->setSpacing(20);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 20, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        minBtn = new QPushButton(taskWidget);
        minBtn->setObjectName(QStringLiteral("minBtn"));
        minBtn->setMinimumSize(QSize(40, 40));
        minBtn->setMaximumSize(QSize(40, 40));

        horizontalLayout_2->addWidget(minBtn);

        closeBtn = new QPushButton(taskWidget);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));
        closeBtn->setMinimumSize(QSize(40, 40));
        closeBtn->setMaximumSize(QSize(40, 40));

        horizontalLayout_2->addWidget(closeBtn);


        verticalLayout_2->addWidget(taskWidget);

        mainWidget = new QWidget(centralWidget);
        mainWidget->setObjectName(QStringLiteral("mainWidget"));
        mainWidget->setMinimumSize(QSize(854, 480));
        mainWidget->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout = new QVBoxLayout(mainWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        nameLab = new QLabel(mainWidget);
        nameLab->setObjectName(QStringLiteral("nameLab"));
        nameLab->setMinimumSize(QSize(854, 80));
        nameLab->setMaximumSize(QSize(16777215, 80));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(24);
        nameLab->setFont(font);
        nameLab->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(nameLab);

        mainBtnWidget = new QWidget(mainWidget);
        mainBtnWidget->setObjectName(QStringLiteral("mainBtnWidget"));
        mainBtnWidget->setMinimumSize(QSize(854, 240));
        horizontalLayout = new QHBoxLayout(mainBtnWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        testBtn = new QPushButton(mainBtnWidget);
        testBtn->setObjectName(QStringLiteral("testBtn"));
        testBtn->setMinimumSize(QSize(160, 160));
        testBtn->setMaximumSize(QSize(160, 160));
        testBtn->setSizeIncrement(QSize(0, 0));

        horizontalLayout->addWidget(testBtn);

        programBtn = new QPushButton(mainBtnWidget);
        programBtn->setObjectName(QStringLiteral("programBtn"));
        programBtn->setMinimumSize(QSize(160, 160));
        programBtn->setMaximumSize(QSize(160, 160));

        horizontalLayout->addWidget(programBtn);

        reportBtn = new QPushButton(mainBtnWidget);
        reportBtn->setObjectName(QStringLiteral("reportBtn"));
        reportBtn->setMinimumSize(QSize(160, 160));
        reportBtn->setMaximumSize(QSize(160, 160));

        horizontalLayout->addWidget(reportBtn);

        settingBtn = new QPushButton(mainBtnWidget);
        settingBtn->setObjectName(QStringLiteral("settingBtn"));
        settingBtn->setMinimumSize(QSize(160, 160));
        settingBtn->setMaximumSize(QSize(160, 160));

        horizontalLayout->addWidget(settingBtn);


        verticalLayout->addWidget(mainBtnWidget);

        versionLab = new QLabel(mainWidget);
        versionLab->setObjectName(QStringLiteral("versionLab"));
        versionLab->setMinimumSize(QSize(1280, 40));
        versionLab->setMaximumSize(QSize(16777215, 40));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(14);
        versionLab->setFont(font1);
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\344\270\273\347\225\214\351\235\242", Q_NULLPTR));
        minBtn->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        closeBtn->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        nameLab->setText(QApplication::translate("MainWindow", "NE6882\346\216\247\345\210\266\350\275\257\344\273\266", Q_NULLPTR));
        testBtn->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        programBtn->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        reportBtn->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        settingBtn->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        versionLab->setText(QApplication::translate("MainWindow", "\350\275\257\344\273\266\347\211\210\346\234\254\345\217\267:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
