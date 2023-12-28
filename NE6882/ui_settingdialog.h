/********************************************************************************
** Form generated from reading UI file 'settingdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGDIALOG_H
#define UI_SETTINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
            settingDialog->setObjectName(QStringLiteral("settingDialog"));
        settingDialog->resize(1280, 720);
        settingDialog->setMinimumSize(QSize(1280, 720));
        verticalLayout = new QVBoxLayout(settingDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        infoWidget = new QWidget(settingDialog);
        infoWidget->setObjectName(QStringLiteral("infoWidget"));
        infoWidget->setMinimumSize(QSize(1280, 80));
        horizontalLayout_2 = new QHBoxLayout(infoWidget);
        horizontalLayout_2->setSpacing(20);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(20, 0, 0, 0);
        iconLab = new QLabel(infoWidget);
        iconLab->setObjectName(QStringLiteral("iconLab"));
        iconLab->setMinimumSize(QSize(50, 50));
        iconLab->setMaximumSize(QSize(50, 50));

        horizontalLayout_2->addWidget(iconLab);

        settingLab = new QLabel(infoWidget);
        settingLab->setObjectName(QStringLiteral("settingLab"));
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


        verticalLayout->addWidget(infoWidget);

        settingtabWidget = new QTabWidget(settingDialog);
        settingtabWidget->setObjectName(QStringLiteral("settingtabWidget"));
        settingtabWidget->setMinimumSize(QSize(1280, 580));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(14);
        settingtabWidget->setFont(font1);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout = new QGridLayout(tab);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(10);
        gridLayout->setVerticalSpacing(20);
        gridLayout->setContentsMargins(20, 20, 0, 0);
        comLab = new QLabel(tab);
        comLab->setObjectName(QStringLiteral("comLab"));
        comLab->setMinimumSize(QSize(100, 34));
        comLab->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(comLab, 0, 0, 1, 1);

        baudLab = new QLabel(tab);
        baudLab->setObjectName(QStringLiteral("baudLab"));
        baudLab->setMinimumSize(QSize(100, 34));
        baudLab->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(baudLab, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);

        baudCBox = new QComboBox(tab);
        baudCBox->setObjectName(QStringLiteral("baudCBox"));
        baudCBox->setMinimumSize(QSize(100, 34));
        baudCBox->setEditable(false);
        baudCBox->setCurrentText(QStringLiteral("9600"));

        gridLayout->addWidget(baudCBox, 1, 1, 1, 1);

        comCBox = new QComboBox(tab);
        comCBox->setObjectName(QStringLiteral("comCBox"));
        comCBox->setMinimumSize(QSize(100, 34));
        comCBox->setCurrentText(QStringLiteral(""));

        gridLayout->addWidget(comCBox, 0, 1, 1, 1);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 1);
        gridLayout->setColumnStretch(2, 8);
        settingtabWidget->addTab(tab, QString());

        verticalLayout->addWidget(settingtabWidget);

        btnWidget = new QWidget(settingDialog);
        btnWidget->setObjectName(QStringLiteral("btnWidget"));
        btnWidget->setMinimumSize(QSize(1280, 60));
        horizontalLayout = new QHBoxLayout(btnWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        saveBtn = new QPushButton(btnWidget);
        saveBtn->setObjectName(QStringLiteral("saveBtn"));
        saveBtn->setMinimumSize(QSize(100, 40));
        saveBtn->setFont(font1);

        horizontalLayout->addWidget(saveBtn);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        cancelBtn = new QPushButton(btnWidget);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));
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
        settingDialog->setWindowTitle(QApplication::translate("settingDialog", "Dialog", Q_NULLPTR));
        iconLab->setText(QApplication::translate("settingDialog", "icon", Q_NULLPTR));
        settingLab->setText(QApplication::translate("settingDialog", "\347\263\273\347\273\237\350\256\276\347\275\256", Q_NULLPTR));
        minBtn->setText(QApplication::translate("settingDialog", "PushButton", Q_NULLPTR));
        closeBtn->setText(QApplication::translate("settingDialog", "PushButton", Q_NULLPTR));
        comLab->setText(QApplication::translate("settingDialog", "\350\256\276\345\244\207\344\270\262\345\217\243\345\217\267:", Q_NULLPTR));
        baudLab->setText(QApplication::translate("settingDialog", "\350\256\276\345\244\207\346\263\242\347\211\271\347\216\207:", Q_NULLPTR));
        baudCBox->clear();
        baudCBox->insertItems(0, QStringList()
         << QApplication::translate("settingDialog", "4800", Q_NULLPTR)
         << QApplication::translate("settingDialog", "9600", Q_NULLPTR)
         << QApplication::translate("settingDialog", "14400", Q_NULLPTR)
         << QApplication::translate("settingDialog", "19200", Q_NULLPTR)
         << QApplication::translate("settingDialog", "38400", Q_NULLPTR)
        );
        settingtabWidget->setTabText(settingtabWidget->indexOf(tab), QApplication::translate("settingDialog", "\347\263\273\347\273\237\350\256\276\347\275\256", Q_NULLPTR));
        saveBtn->setText(QApplication::translate("settingDialog", "\344\277\235\345\255\230", Q_NULLPTR));
        cancelBtn->setText(QApplication::translate("settingDialog", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class settingDialog: public Ui_settingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGDIALOG_H
