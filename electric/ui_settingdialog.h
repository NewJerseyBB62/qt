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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
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
    QCheckBox *checkBox12;
    QCheckBox *checkBox13;
    QCheckBox *checkBox14;
    QCheckBox *checkBox18;
    QCheckBox *checkBox15;
    QCheckBox *checkBox11;
    QCheckBox *checkBox9;
    QCheckBox *checkBox10;
    QCheckBox *checkBox16;
    QCheckBox *checkBox;
    QCheckBox *checkBox5;
    QCheckBox *checkBox2;
    QCheckBox *checkBox6;
    QCheckBox *checkBox7;
    QCheckBox *checkBox8;
    QCheckBox *checkBox3;
    QCheckBox *checkBox4;
    QCheckBox *checkBox20;
    QCheckBox *checkBox17;
    QCheckBox *checkBox19;
    QCheckBox *checkBox21;
    QCheckBox *checkBox22;
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
    QWidget *widget_16;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *saveBtn;

    void setupUi(QDialog *SettingDialog)
    {
        if (SettingDialog->objectName().isEmpty())
            SettingDialog->setObjectName(QString::fromUtf8("SettingDialog"));
        SettingDialog->resize(800, 600);
        SettingDialog->setStyleSheet(QString::fromUtf8("QDialog{\n"
"border-image: url(:/res/img/bg/bg10.jpg);\n"
"border-radius: 10px;\n"
"}\n"
"QLabel{\n"
"font: 75 14pt \"\351\273\221\344\275\223\";\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QCheckBox{\n"
"color: rgb(255, 255, 255);\n"
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
"font: 75 12pt \"\351\273\221\344\275\223\";\n"
"border: 1px solid #0E55A7;\n"
"border-radius: 2px;\n"
"}\n"
"QComboBox::down-arrow{\n"
"	border-image: url(:/res/img/downarrl.png);\n"
"	width: 15px;\n"
"      border:none;\n"
"}\n"
"QComboBox::drop-dow"
                        "n {\n"
"      subcontrol-origin: padding;\n"
"      width: 30px;\n"
"      border:none;\n"
"\n"
"}\n"
"QComboBox QAbstractItemView{\n"
"background:rgba(255,255,255,1);\n"
"    border:1px solid #0E55A7;\n"
"}"));
        verticalLayout = new QVBoxLayout(SettingDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 10);
        widget = new QWidget(SettingDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("#minBtn{\n"
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
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 20, 0);
        horizontalSpacer = new QSpacerItem(687, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);

        minBtn = new QPushButton(widget);
        minBtn->setObjectName(QString::fromUtf8("minBtn"));
        minBtn->setMinimumSize(QSize(40, 40));
        minBtn->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_8->addWidget(minBtn);

        closeBtn = new QPushButton(widget);
        closeBtn->setObjectName(QString::fromUtf8("closeBtn"));
        closeBtn->setMinimumSize(QSize(40, 40));
        closeBtn->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_8->addWidget(closeBtn);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(SettingDialog);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        verticalLayout_3 = new QVBoxLayout(widget_3);
        verticalLayout_3->setSpacing(5);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(10, 10, 10, 10);
        widget_7 = new QWidget(widget_3);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        horizontalLayout_2 = new QHBoxLayout(widget_7);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(50, 0, 0, 0);
        label = new QLabel(widget_7);
        label->setObjectName(QString::fromUtf8("label"));
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
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        widget_8->setStyleSheet(QString::fromUtf8("#widget_8{\n"
"border:3px solid rgba(0, 0, 0, 80);\n"
"}\n"
"/*border-style: dotted;\n"
"border-radius: 10, 10, 10, 10;\n"
"*/"));
        gridLayout = new QGridLayout(widget_8);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(10, 0, 0, 0);
        checkBox12 = new QCheckBox(widget_8);
        checkBox12->setObjectName(QString::fromUtf8("checkBox12"));

        gridLayout->addWidget(checkBox12, 5, 1, 1, 1);

        checkBox13 = new QCheckBox(widget_8);
        checkBox13->setObjectName(QString::fromUtf8("checkBox13"));

        gridLayout->addWidget(checkBox13, 6, 0, 1, 1);

        checkBox14 = new QCheckBox(widget_8);
        checkBox14->setObjectName(QString::fromUtf8("checkBox14"));

        gridLayout->addWidget(checkBox14, 6, 1, 1, 1);

        checkBox18 = new QCheckBox(widget_8);
        checkBox18->setObjectName(QString::fromUtf8("checkBox18"));

        gridLayout->addWidget(checkBox18, 8, 1, 1, 1);

        checkBox15 = new QCheckBox(widget_8);
        checkBox15->setObjectName(QString::fromUtf8("checkBox15"));

        gridLayout->addWidget(checkBox15, 7, 0, 1, 1);

        checkBox11 = new QCheckBox(widget_8);
        checkBox11->setObjectName(QString::fromUtf8("checkBox11"));

        gridLayout->addWidget(checkBox11, 5, 0, 1, 1);

        checkBox9 = new QCheckBox(widget_8);
        checkBox9->setObjectName(QString::fromUtf8("checkBox9"));

        gridLayout->addWidget(checkBox9, 4, 0, 1, 1);

        checkBox10 = new QCheckBox(widget_8);
        checkBox10->setObjectName(QString::fromUtf8("checkBox10"));

        gridLayout->addWidget(checkBox10, 4, 1, 1, 1);

        checkBox16 = new QCheckBox(widget_8);
        checkBox16->setObjectName(QString::fromUtf8("checkBox16"));

        gridLayout->addWidget(checkBox16, 7, 1, 1, 1);

        checkBox = new QCheckBox(widget_8);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        gridLayout->addWidget(checkBox, 0, 0, 1, 1);

        checkBox5 = new QCheckBox(widget_8);
        checkBox5->setObjectName(QString::fromUtf8("checkBox5"));

        gridLayout->addWidget(checkBox5, 0, 1, 1, 1);

        checkBox2 = new QCheckBox(widget_8);
        checkBox2->setObjectName(QString::fromUtf8("checkBox2"));

        gridLayout->addWidget(checkBox2, 1, 0, 1, 1);

        checkBox6 = new QCheckBox(widget_8);
        checkBox6->setObjectName(QString::fromUtf8("checkBox6"));

        gridLayout->addWidget(checkBox6, 1, 1, 1, 1);

        checkBox7 = new QCheckBox(widget_8);
        checkBox7->setObjectName(QString::fromUtf8("checkBox7"));

        gridLayout->addWidget(checkBox7, 2, 1, 1, 1);

        checkBox8 = new QCheckBox(widget_8);
        checkBox8->setObjectName(QString::fromUtf8("checkBox8"));

        gridLayout->addWidget(checkBox8, 3, 1, 1, 1);

        checkBox3 = new QCheckBox(widget_8);
        checkBox3->setObjectName(QString::fromUtf8("checkBox3"));

        gridLayout->addWidget(checkBox3, 2, 0, 1, 1);

        checkBox4 = new QCheckBox(widget_8);
        checkBox4->setObjectName(QString::fromUtf8("checkBox4"));

        gridLayout->addWidget(checkBox4, 3, 0, 1, 1);

        checkBox20 = new QCheckBox(widget_8);
        checkBox20->setObjectName(QString::fromUtf8("checkBox20"));

        gridLayout->addWidget(checkBox20, 9, 1, 1, 1);

        checkBox17 = new QCheckBox(widget_8);
        checkBox17->setObjectName(QString::fromUtf8("checkBox17"));

        gridLayout->addWidget(checkBox17, 8, 0, 1, 1);

        checkBox19 = new QCheckBox(widget_8);
        checkBox19->setObjectName(QString::fromUtf8("checkBox19"));

        gridLayout->addWidget(checkBox19, 9, 0, 1, 1);

        checkBox21 = new QCheckBox(widget_8);
        checkBox21->setObjectName(QString::fromUtf8("checkBox21"));

        gridLayout->addWidget(checkBox21, 10, 0, 1, 1);

        checkBox22 = new QCheckBox(widget_8);
        checkBox22->setObjectName(QString::fromUtf8("checkBox22"));

        gridLayout->addWidget(checkBox22, 10, 1, 1, 1);


        verticalLayout_3->addWidget(widget_8);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 21);

        horizontalLayout->addWidget(widget_3);

        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        verticalLayout_2 = new QVBoxLayout(widget_4);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 10);
        widget_5 = new QWidget(widget_4);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        verticalLayout_4 = new QVBoxLayout(widget_5);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(10, 10, 10, 10);
        widget_9 = new QWidget(widget_5);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        horizontalLayout_3 = new QHBoxLayout(widget_9);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(50, 0, 0, 0);
        label_4 = new QLabel(widget_9);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        horizontalLayout_3->addWidget(label_4);


        verticalLayout_4->addWidget(widget_9);

        widget_10 = new QWidget(widget_5);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        widget_10->setStyleSheet(QString::fromUtf8("#widget_10{\n"
"border:3px solid rgba(0, 0, 0, 80);\n"
"}"));
        verticalLayout_6 = new QVBoxLayout(widget_10);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        widget_13 = new QWidget(widget_10);
        widget_13->setObjectName(QString::fromUtf8("widget_13"));
        horizontalLayout_5 = new QHBoxLayout(widget_13);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        checkBox_9 = new QCheckBox(widget_13);
        checkBox_9->setObjectName(QString::fromUtf8("checkBox_9"));

        horizontalLayout_5->addWidget(checkBox_9);

        label_2 = new QLabel(widget_13);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_2);

        lineEdit = new QLineEdit(widget_13);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(80, 30));

        horizontalLayout_5->addWidget(lineEdit);

        label_7 = new QLabel(widget_13);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_7);

        lineEdit_2 = new QLineEdit(widget_13);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setMinimumSize(QSize(80, 30));

        horizontalLayout_5->addWidget(lineEdit_2);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 1);
        horizontalLayout_5->setStretch(2, 1);
        horizontalLayout_5->setStretch(3, 1);
        horizontalLayout_5->setStretch(4, 1);

        verticalLayout_6->addWidget(widget_13);

        widget_14 = new QWidget(widget_10);
        widget_14->setObjectName(QString::fromUtf8("widget_14"));
        horizontalLayout_6 = new QHBoxLayout(widget_14);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        checkBox_10 = new QCheckBox(widget_14);
        checkBox_10->setObjectName(QString::fromUtf8("checkBox_10"));

        horizontalLayout_6->addWidget(checkBox_10);

        label_3 = new QLabel(widget_14);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_3);

        lineEdit_4 = new QLineEdit(widget_14);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setMinimumSize(QSize(80, 30));

        horizontalLayout_6->addWidget(lineEdit_4);

        label_8 = new QLabel(widget_14);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_8);

        lineEdit_3 = new QLineEdit(widget_14);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setMinimumSize(QSize(80, 30));

        horizontalLayout_6->addWidget(lineEdit_3);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(1, 1);
        horizontalLayout_6->setStretch(2, 1);
        horizontalLayout_6->setStretch(3, 1);
        horizontalLayout_6->setStretch(4, 1);

        verticalLayout_6->addWidget(widget_14);

        widget_15 = new QWidget(widget_10);
        widget_15->setObjectName(QString::fromUtf8("widget_15"));
        horizontalLayout_7 = new QHBoxLayout(widget_15);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        checkBox_11 = new QCheckBox(widget_15);
        checkBox_11->setObjectName(QString::fromUtf8("checkBox_11"));

        horizontalLayout_7->addWidget(checkBox_11);

        label_6 = new QLabel(widget_15);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_6);

        lineEdit_6 = new QLineEdit(widget_15);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setMinimumSize(QSize(80, 30));

        horizontalLayout_7->addWidget(lineEdit_6);

        label_9 = new QLabel(widget_15);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_9);

        lineEdit_5 = new QLineEdit(widget_15);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
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
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        verticalLayout_5 = new QVBoxLayout(widget_6);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(10, 10, 10, 10);
        widget_11 = new QWidget(widget_6);
        widget_11->setObjectName(QString::fromUtf8("widget_11"));
        horizontalLayout_4 = new QHBoxLayout(widget_11);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(50, 0, 0, 0);
        label_5 = new QLabel(widget_11);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        horizontalLayout_4->addWidget(label_5);


        verticalLayout_5->addWidget(widget_11);

        widget_12 = new QWidget(widget_6);
        widget_12->setObjectName(QString::fromUtf8("widget_12"));
        widget_12->setStyleSheet(QString::fromUtf8("#widget_12{\n"
"border:3px solid rgba(0, 0, 0, 80);\n"
"}"));
        gridLayout_2 = new QGridLayout(widget_12);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(widget_12);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(0, 30));
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_10, 0, 0, 1, 1);

        comboBox = new QComboBox(widget_12);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setMinimumSize(QSize(0, 30));

        gridLayout_2->addWidget(comboBox, 0, 1, 1, 1);

        label_11 = new QLabel(widget_12);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(0, 30));
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_11, 0, 2, 1, 1);

        comboBox_2 = new QComboBox(widget_12);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setMinimumSize(QSize(0, 30));

        gridLayout_2->addWidget(comboBox_2, 0, 3, 1, 1);

        label_12 = new QLabel(widget_12);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMinimumSize(QSize(0, 30));
        label_12->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_12, 1, 0, 1, 1);

        comboBox_3 = new QComboBox(widget_12);
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setMinimumSize(QSize(0, 30));

        gridLayout_2->addWidget(comboBox_3, 1, 1, 1, 1);

        gridLayout_2->setRowStretch(0, 1);
        gridLayout_2->setRowStretch(1, 1);
        gridLayout_2->setColumnStretch(0, 1);
        gridLayout_2->setColumnStretch(1, 2);
        gridLayout_2->setColumnStretch(2, 1);
        gridLayout_2->setColumnStretch(3, 2);

        verticalLayout_5->addWidget(widget_12);

        verticalLayout_5->setStretch(0, 1);
        verticalLayout_5->setStretch(1, 7);

        verticalLayout_2->addWidget(widget_6);

        widget_16 = new QWidget(widget_4);
        widget_16->setObjectName(QString::fromUtf8("widget_16"));
        horizontalLayout_9 = new QHBoxLayout(widget_16);
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        saveBtn = new QPushButton(widget_16);
        saveBtn->setObjectName(QString::fromUtf8("saveBtn"));
        saveBtn->setMaximumSize(QSize(100, 35));
        saveBtn->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_9->addWidget(saveBtn);


        verticalLayout_2->addWidget(widget_16);

        verticalLayout_2->setStretch(0, 7);
        verticalLayout_2->setStretch(1, 7);
        verticalLayout_2->setStretch(2, 1);

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
        SettingDialog->setWindowTitle(QCoreApplication::translate("SettingDialog", "Dialog", nullptr));
        minBtn->setText(QString());
        closeBtn->setText(QString());
        label->setText(QCoreApplication::translate("SettingDialog", "\346\225\260\346\215\256\350\256\276\347\275\256", nullptr));
        checkBox12->setText(QCoreApplication::translate("SettingDialog", "\347\224\265\346\265\201\350\264\237\345\263\260\345\200\274", nullptr));
        checkBox13->setText(QCoreApplication::translate("SettingDialog", "\345\212\237\347\216\207\346\255\243\345\263\260\345\200\274", nullptr));
        checkBox14->setText(QCoreApplication::translate("SettingDialog", "\345\212\237\347\216\207\350\264\237\345\263\260\345\200\274", nullptr));
        checkBox18->setText(QCoreApplication::translate("SettingDialog", "\347\224\265\350\203\275\351\207\217\350\264\237", nullptr));
        checkBox15->setText(QCoreApplication::translate("SettingDialog", "\347\224\265\350\203\275\351\207\217\350\256\241\346\227\266", nullptr));
        checkBox11->setText(QCoreApplication::translate("SettingDialog", "\347\224\265\346\265\201\346\255\243\345\263\260\345\200\274", nullptr));
        checkBox9->setText(QCoreApplication::translate("SettingDialog", "\347\224\265\345\216\213\346\255\243\345\263\260\345\200\274", nullptr));
        checkBox10->setText(QCoreApplication::translate("SettingDialog", "\347\224\265\345\216\213\350\264\237\345\263\260\345\200\274", nullptr));
        checkBox16->setText(QCoreApplication::translate("SettingDialog", "\350\266\205\351\230\210\345\200\274\345\220\216\347\224\265\350\203\275\351\207\217\350\256\241\346\227\266", nullptr));
        checkBox->setText(QCoreApplication::translate("SettingDialog", "\347\224\265\345\216\213", nullptr));
        checkBox5->setText(QCoreApplication::translate("SettingDialog", "\350\247\206\345\234\250\345\212\237\347\216\207", nullptr));
        checkBox2->setText(QCoreApplication::translate("SettingDialog", "\347\224\265\346\265\201", nullptr));
        checkBox6->setText(QCoreApplication::translate("SettingDialog", "\345\212\237\347\216\207\345\233\240\346\225\260", nullptr));
        checkBox7->setText(QCoreApplication::translate("SettingDialog", "\350\247\222\345\272\246", nullptr));
        checkBox8->setText(QCoreApplication::translate("SettingDialog", "\347\224\265\345\216\213\351\242\221\347\216\207", nullptr));
        checkBox3->setText(QCoreApplication::translate("SettingDialog", "\346\234\211\345\212\237\345\212\237\347\216\207", nullptr));
        checkBox4->setText(QCoreApplication::translate("SettingDialog", "\346\227\240\345\212\237\345\212\237\347\216\207", nullptr));
        checkBox20->setText(QCoreApplication::translate("SettingDialog", "\347\224\265\346\265\201\347\247\257\345\210\206", nullptr));
        checkBox17->setText(QCoreApplication::translate("SettingDialog", "\347\224\265\350\203\275\351\207\217\346\255\243", nullptr));
        checkBox19->setText(QCoreApplication::translate("SettingDialog", "\347\224\265\350\203\275\351\207\217", nullptr));
        checkBox21->setText(QCoreApplication::translate("SettingDialog", "\347\224\265\346\265\201\347\247\257\345\210\206\346\255\243", nullptr));
        checkBox22->setText(QCoreApplication::translate("SettingDialog", "\347\224\265\346\265\201\347\247\257\345\210\206\350\264\237", nullptr));
        label_4->setText(QCoreApplication::translate("SettingDialog", "\346\212\245\350\255\246\350\256\276\347\275\256", nullptr));
        checkBox_9->setText(QCoreApplication::translate("SettingDialog", "\347\224\265\345\216\213\346\212\245\350\255\246", nullptr));
        label_2->setText(QCoreApplication::translate("SettingDialog", "\344\270\212\351\231\220", nullptr));
        label_7->setText(QCoreApplication::translate("SettingDialog", "\344\270\213\351\231\220", nullptr));
        checkBox_10->setText(QCoreApplication::translate("SettingDialog", "\347\224\265\346\265\201\346\212\245\350\255\246", nullptr));
        label_3->setText(QCoreApplication::translate("SettingDialog", "\344\270\212\351\231\220", nullptr));
        label_8->setText(QCoreApplication::translate("SettingDialog", "\344\270\213\351\231\220", nullptr));
        checkBox_11->setText(QCoreApplication::translate("SettingDialog", "\345\212\237\347\216\207\346\212\245\350\255\246", nullptr));
        label_6->setText(QCoreApplication::translate("SettingDialog", "\344\270\212\351\231\220", nullptr));
        label_9->setText(QCoreApplication::translate("SettingDialog", "\344\270\213\351\231\220", nullptr));
        label_5->setText(QCoreApplication::translate("SettingDialog", "\347\263\273\347\273\237\350\256\276\347\275\256", nullptr));
        label_10->setText(QCoreApplication::translate("SettingDialog", "\350\257\255\350\250\200", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("SettingDialog", "\344\270\255\346\226\207", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("SettingDialog", "English", nullptr));

        label_11->setText(QCoreApplication::translate("SettingDialog", "\344\270\273\351\242\230", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("SettingDialog", "\346\265\205\350\211\262", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("SettingDialog", "\346\267\261\350\211\262", nullptr));

        label_12->setText(QCoreApplication::translate("SettingDialog", "\345\236\213\345\217\267", nullptr));
        comboBox_3->setItemText(0, QCoreApplication::translate("SettingDialog", "IDI310XL", nullptr));

        saveBtn->setText(QCoreApplication::translate("SettingDialog", "\344\277\235\345\255\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingDialog: public Ui_SettingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGDIALOG_H
