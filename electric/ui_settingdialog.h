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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer;
    QPushButton *minBtn;
    QPushButton *closeBtn;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QWidget *widget_8;
    QGridLayout *gridLayout;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_6;
    QCheckBox *checkBox_7;
    QCheckBox *checkBox_8;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QWidget *widget_10;
    QVBoxLayout *verticalLayout_6;
    QWidget *widget_13;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *checkBox_9;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_7;
    QLineEdit *lineEdit_2;
    QWidget *widget_14;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *checkBox_10;
    QLabel *label_3;
    QLineEdit *lineEdit_4;
    QLabel *label_8;
    QLineEdit *lineEdit_3;
    QWidget *widget_15;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *checkBox_11;
    QLabel *label_6;
    QLineEdit *lineEdit_6;
    QLabel *label_9;
    QLineEdit *lineEdit_5;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_5;
    QWidget *widget_11;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QWidget *widget_12;
    QGridLayout *gridLayout_2;
    QLabel *label_10;
    QComboBox *comboBox;
    QLabel *label_11;
    QComboBox *comboBox_2;
    QLabel *label_12;
    QComboBox *comboBox_3;

    void setupUi(QDialog *SettingDialog)
    {
        if (SettingDialog->objectName().isEmpty())
            SettingDialog->setObjectName(QStringLiteral("SettingDialog"));
        SettingDialog->resize(800, 600);
        SettingDialog->setStyleSheet(QString::fromUtf8("QDialog{\n"
"border-image: url(:/res/img/bg/bg7.jpg);\n"
"border-radius: 10px;\n"
"}\n"
"QLabel{\n"
"font: 75 14pt \"\351\273\221\344\275\223\";\n"
"}\n"
"\n"
"QCheckBox{\n"
"color: rgb(0, 0, 0);\n"
"font: 75 14pt \"\351\273\221\344\275\223\";\n"
"}\n"
"QCheckBox::indicator{\n"
"width: 20px;\n"
"height: 20px;\n"
"}\n"
"QCheckBox::indicator:checked {\n"
"border-image: url(:/res/img/check1l.png);\n"
"}\n"
"QCheckBox::indicator:unchecked {\n"
"border-image: url(:/res/img/checkl.png);\n"
"}\n"
"QLineEdit{\n"
"border-image: url(:/res/img/lineedit.png);\n"
"font: 75 14pt \"\351\273\221\344\275\223\";\n"
"}\n"
"\n"
"QLineEdit:hover{\n"
"border-image: url(:/res/img/lineedithover.png);\n"
"}\n"
"\n"
"QComboBox{\n"
"color: #424242;\n"
"border: 1px solid #0E55A7;\n"
"border-radius: 2px;\n"
"}\n"
"QComboBox::down-arrow{\n"
"	border-image: url(:/res/img/downarrl.png);\n"
"	width: 20px;\n"
"      border:none;\n"
"}\n"
"QComboBox::drop-down {\n"
"      subcontrol-origin: padding;\n"
"      width: 30px;\n"
"      border:none;"
                        "\n"
"\n"
"}\n"
"QComboBox QAbstractItemView{\n"
"background:rgba(255,255,255,1);\n"
"    border:1px solid #0E55A7;\n"
"}"));
        verticalLayout = new QVBoxLayout(SettingDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(SettingDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setStyleSheet(QLatin1String("#minBtn{\n"
"	border-image: url(:/res/img/mins.png);\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}\n"
"#minBtn:hover{\n"
"	border-image: url(:/res/img/nins1.png);\n"
"}\n"
"\n"
"#closeBtn{\n"
"	border-image: url(:/res/img/closes.png);\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}\n"
"#closeBtn:hover{\n"
"	border-image: url(:/res/img/closes1.png);\n"
"}"));
        horizontalLayout_8 = new QHBoxLayout(widget);
        horizontalLayout_8->setSpacing(20);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 20, 0);
        horizontalSpacer = new QSpacerItem(687, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);

        minBtn = new QPushButton(widget);
        minBtn->setObjectName(QStringLiteral("minBtn"));
        minBtn->setMinimumSize(QSize(40, 40));
        minBtn->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_8->addWidget(minBtn);

        closeBtn = new QPushButton(widget);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));
        closeBtn->setMinimumSize(QSize(40, 40));
        closeBtn->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_8->addWidget(closeBtn);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(SettingDialog);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        verticalLayout_3 = new QVBoxLayout(widget_3);
        verticalLayout_3->setSpacing(5);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(10, 10, 10, 10);
        widget_7 = new QWidget(widget_3);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        horizontalLayout_2 = new QHBoxLayout(widget_7);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(50, 0, 0, 0);
        label = new QLabel(widget_7);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(14);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        label->setFont(font);

        horizontalLayout_2->addWidget(label);


        verticalLayout_3->addWidget(widget_7);

        widget_8 = new QWidget(widget_3);
        widget_8->setObjectName(QStringLiteral("widget_8"));
        widget_8->setStyleSheet(QLatin1String("#widget_8{\n"
"border:3px solid rgba(0, 0, 0, 80);\n"
"}\n"
"/*border-style: dotted;\n"
"border-radius: 10, 10, 10, 10;\n"
"*/"));
        gridLayout = new QGridLayout(widget_8);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        checkBox = new QCheckBox(widget_8);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        gridLayout->addWidget(checkBox, 0, 0, 1, 1);

        checkBox_2 = new QCheckBox(widget_8);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        gridLayout->addWidget(checkBox_2, 0, 1, 1, 1);

        checkBox_3 = new QCheckBox(widget_8);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));

        gridLayout->addWidget(checkBox_3, 1, 0, 1, 1);

        checkBox_4 = new QCheckBox(widget_8);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));

        gridLayout->addWidget(checkBox_4, 1, 1, 1, 1);

        checkBox_5 = new QCheckBox(widget_8);
        checkBox_5->setObjectName(QStringLiteral("checkBox_5"));

        gridLayout->addWidget(checkBox_5, 2, 0, 1, 1);

        checkBox_6 = new QCheckBox(widget_8);
        checkBox_6->setObjectName(QStringLiteral("checkBox_6"));

        gridLayout->addWidget(checkBox_6, 2, 1, 1, 1);

        checkBox_7 = new QCheckBox(widget_8);
        checkBox_7->setObjectName(QStringLiteral("checkBox_7"));

        gridLayout->addWidget(checkBox_7, 3, 0, 1, 1);

        checkBox_8 = new QCheckBox(widget_8);
        checkBox_8->setObjectName(QStringLiteral("checkBox_8"));

        gridLayout->addWidget(checkBox_8, 3, 1, 1, 1);


        verticalLayout_3->addWidget(widget_8);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 11);

        horizontalLayout->addWidget(widget_3);

        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        verticalLayout_2 = new QVBoxLayout(widget_4);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_5 = new QWidget(widget_4);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        verticalLayout_4 = new QVBoxLayout(widget_5);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(10, 10, 10, 10);
        widget_9 = new QWidget(widget_5);
        widget_9->setObjectName(QStringLiteral("widget_9"));
        horizontalLayout_3 = new QHBoxLayout(widget_9);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(50, 0, 0, 0);
        label_4 = new QLabel(widget_9);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        horizontalLayout_3->addWidget(label_4);


        verticalLayout_4->addWidget(widget_9);

        widget_10 = new QWidget(widget_5);
        widget_10->setObjectName(QStringLiteral("widget_10"));
        widget_10->setStyleSheet(QLatin1String("#widget_10{\n"
"border:3px solid rgba(0, 0, 0, 80);\n"
"}"));
        verticalLayout_6 = new QVBoxLayout(widget_10);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        widget_13 = new QWidget(widget_10);
        widget_13->setObjectName(QStringLiteral("widget_13"));
        horizontalLayout_5 = new QHBoxLayout(widget_13);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        checkBox_9 = new QCheckBox(widget_13);
        checkBox_9->setObjectName(QStringLiteral("checkBox_9"));

        horizontalLayout_5->addWidget(checkBox_9);

        label_2 = new QLabel(widget_13);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_2);

        lineEdit = new QLineEdit(widget_13);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(80, 30));

        horizontalLayout_5->addWidget(lineEdit);

        label_7 = new QLabel(widget_13);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_7);

        lineEdit_2 = new QLineEdit(widget_13);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setMinimumSize(QSize(80, 30));

        horizontalLayout_5->addWidget(lineEdit_2);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 1);
        horizontalLayout_5->setStretch(2, 1);
        horizontalLayout_5->setStretch(3, 1);
        horizontalLayout_5->setStretch(4, 1);

        verticalLayout_6->addWidget(widget_13);

        widget_14 = new QWidget(widget_10);
        widget_14->setObjectName(QStringLiteral("widget_14"));
        horizontalLayout_6 = new QHBoxLayout(widget_14);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        checkBox_10 = new QCheckBox(widget_14);
        checkBox_10->setObjectName(QStringLiteral("checkBox_10"));

        horizontalLayout_6->addWidget(checkBox_10);

        label_3 = new QLabel(widget_14);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_3);

        lineEdit_4 = new QLineEdit(widget_14);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setMinimumSize(QSize(80, 30));

        horizontalLayout_6->addWidget(lineEdit_4);

        label_8 = new QLabel(widget_14);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_8);

        lineEdit_3 = new QLineEdit(widget_14);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setMinimumSize(QSize(80, 30));

        horizontalLayout_6->addWidget(lineEdit_3);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(1, 1);
        horizontalLayout_6->setStretch(2, 1);
        horizontalLayout_6->setStretch(3, 1);
        horizontalLayout_6->setStretch(4, 1);

        verticalLayout_6->addWidget(widget_14);

        widget_15 = new QWidget(widget_10);
        widget_15->setObjectName(QStringLiteral("widget_15"));
        horizontalLayout_7 = new QHBoxLayout(widget_15);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        checkBox_11 = new QCheckBox(widget_15);
        checkBox_11->setObjectName(QStringLiteral("checkBox_11"));

        horizontalLayout_7->addWidget(checkBox_11);

        label_6 = new QLabel(widget_15);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_6);

        lineEdit_6 = new QLineEdit(widget_15);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setMinimumSize(QSize(80, 30));

        horizontalLayout_7->addWidget(lineEdit_6);

        label_9 = new QLabel(widget_15);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_9);

        lineEdit_5 = new QLineEdit(widget_15);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setMinimumSize(QSize(80, 30));

        horizontalLayout_7->addWidget(lineEdit_5);

        horizontalLayout_7->setStretch(0, 1);
        horizontalLayout_7->setStretch(1, 1);
        horizontalLayout_7->setStretch(2, 1);
        horizontalLayout_7->setStretch(3, 1);
        horizontalLayout_7->setStretch(4, 1);

        verticalLayout_6->addWidget(widget_15);


        verticalLayout_4->addWidget(widget_10);

        verticalLayout_4->setStretch(0, 1);
        verticalLayout_4->setStretch(1, 7);

        verticalLayout_2->addWidget(widget_5);

        widget_6 = new QWidget(widget_4);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        verticalLayout_5 = new QVBoxLayout(widget_6);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(10, 10, 10, 10);
        widget_11 = new QWidget(widget_6);
        widget_11->setObjectName(QStringLiteral("widget_11"));
        horizontalLayout_4 = new QHBoxLayout(widget_11);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(50, 0, 0, 0);
        label_5 = new QLabel(widget_11);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        horizontalLayout_4->addWidget(label_5);


        verticalLayout_5->addWidget(widget_11);

        widget_12 = new QWidget(widget_6);
        widget_12->setObjectName(QStringLiteral("widget_12"));
        widget_12->setStyleSheet(QLatin1String("#widget_12{\n"
"border:3px solid rgba(0, 0, 0, 80);\n"
"}"));
        gridLayout_2 = new QGridLayout(widget_12);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_10 = new QLabel(widget_12);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMinimumSize(QSize(0, 30));
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_10, 0, 0, 1, 1);

        comboBox = new QComboBox(widget_12);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMinimumSize(QSize(0, 30));

        gridLayout_2->addWidget(comboBox, 0, 1, 1, 1);

        label_11 = new QLabel(widget_12);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setMinimumSize(QSize(0, 30));
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_11, 0, 2, 1, 1);

        comboBox_2 = new QComboBox(widget_12);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setMinimumSize(QSize(0, 30));

        gridLayout_2->addWidget(comboBox_2, 0, 3, 1, 1);

        label_12 = new QLabel(widget_12);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setMinimumSize(QSize(0, 30));
        label_12->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_12, 1, 0, 1, 1);

        comboBox_3 = new QComboBox(widget_12);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setMinimumSize(QSize(0, 30));

        gridLayout_2->addWidget(comboBox_3, 1, 1, 1, 1);


        verticalLayout_5->addWidget(widget_12);

        verticalLayout_5->setStretch(0, 1);
        verticalLayout_5->setStretch(1, 7);

        verticalLayout_2->addWidget(widget_6);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 1);

        horizontalLayout->addWidget(widget_4);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);

        verticalLayout->addWidget(widget_2);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 15);

        retranslateUi(SettingDialog);

        QMetaObject::connectSlotsByName(SettingDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingDialog)
    {
        SettingDialog->setWindowTitle(QApplication::translate("SettingDialog", "Dialog", Q_NULLPTR));
        minBtn->setText(QString());
        closeBtn->setText(QString());
        label->setText(QApplication::translate("SettingDialog", "\346\225\260\346\215\256\350\256\276\347\275\256", Q_NULLPTR));
        checkBox->setText(QApplication::translate("SettingDialog", "CheckBox", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("SettingDialog", "CheckBox", Q_NULLPTR));
        checkBox_3->setText(QApplication::translate("SettingDialog", "CheckBox", Q_NULLPTR));
        checkBox_4->setText(QApplication::translate("SettingDialog", "CheckBox", Q_NULLPTR));
        checkBox_5->setText(QApplication::translate("SettingDialog", "CheckBox", Q_NULLPTR));
        checkBox_6->setText(QApplication::translate("SettingDialog", "CheckBox", Q_NULLPTR));
        checkBox_7->setText(QApplication::translate("SettingDialog", "CheckBox", Q_NULLPTR));
        checkBox_8->setText(QApplication::translate("SettingDialog", "CheckBox", Q_NULLPTR));
        label_4->setText(QApplication::translate("SettingDialog", "\346\212\245\350\255\246\350\256\276\347\275\256", Q_NULLPTR));
        checkBox_9->setText(QApplication::translate("SettingDialog", "\347\224\265\345\216\213\346\212\245\350\255\246", Q_NULLPTR));
        label_2->setText(QApplication::translate("SettingDialog", "\344\270\212\351\231\220", Q_NULLPTR));
        label_7->setText(QApplication::translate("SettingDialog", "\344\270\213\351\231\220", Q_NULLPTR));
        checkBox_10->setText(QApplication::translate("SettingDialog", "\347\224\265\346\265\201\346\212\245\350\255\246", Q_NULLPTR));
        label_3->setText(QApplication::translate("SettingDialog", "\344\270\212\351\231\220", Q_NULLPTR));
        label_8->setText(QApplication::translate("SettingDialog", "\344\270\213\351\231\220", Q_NULLPTR));
        checkBox_11->setText(QApplication::translate("SettingDialog", "\345\212\237\347\216\207\346\212\245\350\255\246", Q_NULLPTR));
        label_6->setText(QApplication::translate("SettingDialog", "\344\270\212\351\231\220", Q_NULLPTR));
        label_9->setText(QApplication::translate("SettingDialog", "\344\270\213\351\231\220", Q_NULLPTR));
        label_5->setText(QApplication::translate("SettingDialog", "\347\263\273\347\273\237\350\256\276\347\275\256", Q_NULLPTR));
        label_10->setText(QApplication::translate("SettingDialog", "\350\257\255\350\250\200", Q_NULLPTR));
        label_11->setText(QApplication::translate("SettingDialog", "\344\270\273\351\242\230", Q_NULLPTR));
        label_12->setText(QApplication::translate("SettingDialog", "\345\236\213\345\217\267", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SettingDialog: public Ui_SettingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGDIALOG_H
