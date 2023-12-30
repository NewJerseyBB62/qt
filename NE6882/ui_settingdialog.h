/********************************************************************************
** Form generated from reading UI file 'settingdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGDIALOG_H
#define UI_SETTINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_settingDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *infoWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *iconLab;
    QLabel *settingLab;
    QSpacerItem *horizontalSpacer_2;
    QWidget *taskWidget;
    QPushButton *minBtn;
    QPushButton *closeBtn;
    QTabWidget *settingtabWidget;
    QWidget *tab;
    QGridLayout *gridLayout;
    QLabel *comLab;
    QLabel *baudLab;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QComboBox *baudCBox;
    QComboBox *comCBox;
    QWidget *btnWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *saveBtn;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *cancelBtn;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QDialog *settingDialog)
    {
        if (settingDialog->objectName().isEmpty())
            settingDialog->setObjectName(QString::fromUtf8("settingDialog"));
        settingDialog->resize(1280, 720);
        settingDialog->setMinimumSize(QSize(1280, 720));
        settingDialog->setStyleSheet(QString::fromUtf8("#settingDialog{\n"
"border-image: url(:/icon/bg3.jpg);\n"
"}"));
        verticalLayout = new QVBoxLayout(settingDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(20, 0, 20, 0);
        infoWidget = new QWidget(settingDialog);
        infoWidget->setObjectName(QString::fromUtf8("infoWidget"));
        infoWidget->setMinimumSize(QSize(1240, 80));
        horizontalLayout_2 = new QHBoxLayout(infoWidget);
        horizontalLayout_2->setSpacing(20);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(20, 0, 0, 0);
        iconLab = new QLabel(infoWidget);
        iconLab->setObjectName(QString::fromUtf8("iconLab"));
        iconLab->setMinimumSize(QSize(50, 50));
        iconLab->setMaximumSize(QSize(50, 50));
        iconLab->setStyleSheet(QString::fromUtf8("border-image: url(:/icon/menul1.png);"));

        horizontalLayout_2->addWidget(iconLab);

        settingLab = new QLabel(infoWidget);
        settingLab->setObjectName(QString::fromUtf8("settingLab"));
        settingLab->setMinimumSize(QSize(100, 50));
        settingLab->setMaximumSize(QSize(100, 50));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(18);
        settingLab->setFont(font);
        settingLab->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(settingLab);

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


        verticalLayout->addWidget(infoWidget);

        settingtabWidget = new QTabWidget(settingDialog);
        settingtabWidget->setObjectName(QString::fromUtf8("settingtabWidget"));
        settingtabWidget->setMinimumSize(QSize(1240, 580));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(14);
        settingtabWidget->setFont(font1);
        settingtabWidget->setStyleSheet(QString::fromUtf8("#settingtabWidget{\n"
"background-color: rgb(255, 255, 255);\n"
"border: 2px solid rgb(191, 191, 191);\n"
"}\n"
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
"}"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout = new QGridLayout(tab);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(10);
        gridLayout->setVerticalSpacing(20);
        gridLayout->setContentsMargins(20, 20, 0, 0);
        comLab = new QLabel(tab);
        comLab->setObjectName(QString::fromUtf8("comLab"));
        comLab->setMinimumSize(QSize(100, 34));
        comLab->setFont(font1);
        comLab->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(comLab, 0, 0, 1, 1);

        baudLab = new QLabel(tab);
        baudLab->setObjectName(QString::fromUtf8("baudLab"));
        baudLab->setMinimumSize(QSize(100, 34));
        baudLab->setFont(font1);
        baudLab->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(baudLab, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);

        baudCBox = new QComboBox(tab);
        baudCBox->addItem(QString());
        baudCBox->addItem(QString());
        baudCBox->addItem(QString());
        baudCBox->addItem(QString());
        baudCBox->addItem(QString());
        baudCBox->setObjectName(QString::fromUtf8("baudCBox"));
        baudCBox->setMinimumSize(QSize(100, 34));
        baudCBox->setFont(font1);
        baudCBox->setEditable(false);
        baudCBox->setCurrentText(QString::fromUtf8("9600"));

        gridLayout->addWidget(baudCBox, 1, 1, 1, 1);

        comCBox = new QComboBox(tab);
        comCBox->setObjectName(QString::fromUtf8("comCBox"));
        comCBox->setMinimumSize(QSize(100, 34));
        comCBox->setFont(font1);
        comCBox->setCurrentText(QString::fromUtf8(""));

        gridLayout->addWidget(comCBox, 0, 1, 1, 1);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 1);
        gridLayout->setColumnStretch(2, 8);
        settingtabWidget->addTab(tab, QString());

        verticalLayout->addWidget(settingtabWidget);

        btnWidget = new QWidget(settingDialog);
        btnWidget->setObjectName(QString::fromUtf8("btnWidget"));
        btnWidget->setMinimumSize(QSize(1280, 60));
        btnWidget->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius: 10px;\n"
"color: #FFFFFF;\n"
"background-color: rgba(195, 195, 195, 230);\n"
"}\n"
"QPushButton:hover{\n"
"color: #161616;\n"
"background-color: rgb(255, 255, 255);\n"
"}"));
        horizontalLayout = new QHBoxLayout(btnWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        saveBtn = new QPushButton(btnWidget);
        saveBtn->setObjectName(QString::fromUtf8("saveBtn"));
        saveBtn->setMinimumSize(QSize(100, 40));
        saveBtn->setFont(font1);

        horizontalLayout->addWidget(saveBtn);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        cancelBtn = new QPushButton(btnWidget);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));
        cancelBtn->setMinimumSize(QSize(100, 40));
        cancelBtn->setFont(font1);

        horizontalLayout->addWidget(cancelBtn);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        horizontalLayout->setStretch(0, 4);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(3, 1);
        horizontalLayout->setStretch(4, 4);

        verticalLayout->addWidget(btnWidget);


        retranslateUi(settingDialog);

        settingtabWidget->setCurrentIndex(0);
        baudCBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(settingDialog);
    } // setupUi

    void retranslateUi(QDialog *settingDialog)
    {
        settingDialog->setWindowTitle(QCoreApplication::translate("settingDialog", "Dialog", nullptr));
        iconLab->setText(QString());
        settingLab->setText(QCoreApplication::translate("settingDialog", "\347\263\273\347\273\237\350\256\276\347\275\256", nullptr));
        minBtn->setText(QString());
        closeBtn->setText(QString());
        comLab->setText(QCoreApplication::translate("settingDialog", "\350\256\276\345\244\207\344\270\262\345\217\243\345\217\267:", nullptr));
        baudLab->setText(QCoreApplication::translate("settingDialog", "\350\256\276\345\244\207\346\263\242\347\211\271\347\216\207:", nullptr));
        baudCBox->setItemText(0, QCoreApplication::translate("settingDialog", "4800", nullptr));
        baudCBox->setItemText(1, QCoreApplication::translate("settingDialog", "9600", nullptr));
        baudCBox->setItemText(2, QCoreApplication::translate("settingDialog", "14400", nullptr));
        baudCBox->setItemText(3, QCoreApplication::translate("settingDialog", "19200", nullptr));
        baudCBox->setItemText(4, QCoreApplication::translate("settingDialog", "38400", nullptr));

        settingtabWidget->setTabText(settingtabWidget->indexOf(tab), QCoreApplication::translate("settingDialog", "\347\263\273\347\273\237\350\256\276\347\275\256", nullptr));
        saveBtn->setText(QCoreApplication::translate("settingDialog", "\344\277\235\345\255\230", nullptr));
        cancelBtn->setText(QCoreApplication::translate("settingDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class settingDialog: public Ui_settingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGDIALOG_H
