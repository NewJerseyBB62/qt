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
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *minBtn;
    QPushButton *maxBtn;
    QPushButton *closeBtn;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *label_3;
    QPushButton *dataBtn;
    QPushButton *settingBtn;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_4;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout;
    QLabel *label_7;
    QLabel *label_6;
    QLabel *label_46;
    QLabel *label_5;
    QLabel *label_4;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_6;
    QTabWidget *tabWidget;
    QWidget *tab1;
    QVBoxLayout *verticalLayout_5;
    QWidget *widget_12;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_38;
    QComboBox *comboBox_4;
    QPushButton *pushButton_11;
    QComboBox *comboBox_5;
    QLabel *label_39;
    QPushButton *pushButton_13;
    QTabWidget *tabWidget_2;
    QWidget *tab1_1;
    QGridLayout *gridLayout;
    QWidget *tab1_2;
    QGridLayout *gridLayout_2;
    QLabel *label_35;
    QLineEdit *lineEdit_26;
    QLabel *label_33;
    QLineEdit *lineEdit_20;
    QLabel *label_32;
    QLineEdit *lineEdit_16;
    QLabel *label_34;
    QLineEdit *lineEdit_15;
    QLabel *label_28;
    QLineEdit *lineEdit_25;
    QLabel *label_24;
    QLineEdit *lineEdit_17;
    QLabel *label_37;
    QLineEdit *lineEdit_24;
    QLabel *label_30;
    QLineEdit *lineEdit_21;
    QLabel *label_25;
    QLineEdit *lineEdit_23;
    QLabel *label_27;
    QLineEdit *lineEdit_22;
    QLabel *label_29;
    QLineEdit *lineEdit_28;
    QLabel *label_36;
    QLineEdit *lineEdit_19;
    QLabel *label_26;
    QLineEdit *lineEdit_18;
    QLabel *label_31;
    QLineEdit *lineEdit_27;
    QWidget *tab2;
    QVBoxLayout *verticalLayout_4;
    QTableWidget *tableWidget;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_7;
    QWidget *widget_10;
    QWidget *widget_11;
    QVBoxLayout *verticalLayout_9;
    QWidget *widget_16;
    QHBoxLayout *horizontalLayout_10;
    QCheckBox *checkBox;
    QPushButton *pushButton_15;
    QWidget *widget_17;
    QHBoxLayout *horizontalLayout_11;
    QCheckBox *checkBox_2;
    QPushButton *pushButton_16;
    QWidget *widget_18;
    QHBoxLayout *horizontalLayout_12;
    QCheckBox *checkBox_3;
    QPushButton *pushButton_17;
    QWidget *widget_19;
    QHBoxLayout *horizontalLayout_13;
    QCheckBox *checkBox_4;
    QPushButton *pushButton_18;
    QWidget *tab3;
    QVBoxLayout *verticalLayout_8;
    QWidget *widget_14;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_40;
    QComboBox *comboBox_6;
    QPushButton *pushButton_12;
    QComboBox *comboBox_7;
    QLabel *label_41;
    QPushButton *pushButton_14;
    QWidget *widget_15;
    QGridLayout *gridLayout_3;
    QLabel *label_42;
    QLCDNumber *lcdNumber;
    QLabel *label_43;
    QLCDNumber *lcdNumber_2;
    QLabel *label_44;
    QLCDNumber *lcdNumber_3;
    QLabel *label_45;
    QLCDNumber *lcdNumber_4;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_13;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_8;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_5;
    QComboBox *comboBox_3;
    QPushButton *pushButton_7;
    QWidget *widget_7;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_9;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1000, 800);
        MainWindow->setMinimumSize(QSize(1000, 800));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setStyleSheet(QString::fromUtf8("#centralWidget{\n"
"border-image: url(:/res/img/bg/bg16.jpg);\n"
"border-radius: 10px;\n"
"}\n"
"\n"
"QLabel{\n"
"font-family: \351\273\221\344\275\223;\n"
"font-size: 16px;\n"
"}\n"
"\n"
"QPushButton{\n"
"Border-radius: 2px;\n"
"background-color: rgb(255, 255, 255);\n"
"border: 1px solid #C00D6EFD;\n"
"color: rgb(50, 50, 50);\n"
"font-family: \351\273\221\344\275\223;\n"
"font-size: 16px;\n"
"/*font-weight: 600;*/\n"
"}\n"
"QPushButton:hover{\n"
"border: 3px solid #FF605DEC;\n"
"}\n"
"QPushButton:pressed{\n"
"color: #FFFFFF;\n"
"background-color:rgb(130, 130, 130);\n"
"}\n"
"\n"
"QLineEdit{\n"
"border-image: url(:/res/img/lineedit.png);\n"
"font-family: \351\273\221\344\275\223;\n"
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
"font-family: \351\273\221\344\275\223;\n"
"font-size: 16px;\n"
"}\n"
"QComboBox::down-arrow{\n"
"	border-image: url(:/res/img/downarrl.png);\n"
"	w"
                        "idth: 18px;\n"
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
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(10);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 10);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 0));
        widget->setMaximumSize(QSize(16777215, 16777215));
        widget->setStyleSheet(QString::fromUtf8("#widget{\n"
"	\n"
"}\n"
"\n"
"#minBtn{\n"
"	\n"
"border-image: url(:/res/img/minwhite.png);\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}\n"
"#minBtn:hover{\n"
"	border-image: url(:/res/img/minblack.png);\n"
"}\n"
"\n"
"#closeBtn{\n"
"	border-image: url(:/res/img/closes.png);\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}\n"
"#closeBtn:hover{\n"
"border-image: url(:/res/img/closes1.png);\n"
"	\n"
"}\n"
"\n"
"#maxBtn{\n"
"	border-image: url(:/res/img/maxwhite.png);\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}\n"
"#maxBtn:hover{\n"
"	border-image: url(:/res/img/maxblack.png);\n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setSpacing(20);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 20, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        minBtn = new QPushButton(widget);
        minBtn->setObjectName(QString::fromUtf8("minBtn"));
        minBtn->setMinimumSize(QSize(40, 40));
        minBtn->setMaximumSize(QSize(40, 40));

        horizontalLayout_3->addWidget(minBtn);

        maxBtn = new QPushButton(widget);
        maxBtn->setObjectName(QString::fromUtf8("maxBtn"));
        maxBtn->setMinimumSize(QSize(40, 40));
        maxBtn->setMaximumSize(QSize(40, 40));
        maxBtn->setFlat(true);

        horizontalLayout_3->addWidget(maxBtn);

        closeBtn = new QPushButton(widget);
        closeBtn->setObjectName(QString::fromUtf8("closeBtn"));
        closeBtn->setMinimumSize(QSize(40, 40));
        closeBtn->setMaximumSize(QSize(40, 40));
        closeBtn->setFlat(true);

        horizontalLayout_3->addWidget(closeBtn);


        verticalLayout->addWidget(widget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(20, 0, 30, 0);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        label->setFont(font);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label);

        comboBox = new QComboBox(centralWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setMinimumSize(QSize(100, 30));

        horizontalLayout_2->addWidget(comboBox);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_2);

        comboBox_2 = new QComboBox(centralWidget);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setMinimumSize(QSize(100, 30));

        horizontalLayout_2->addWidget(comboBox_2);

        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(100, 30));
        pushButton_3->setFont(font);

        horizontalLayout_2->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(100, 30));
        pushButton_4->setFont(font);

        horizontalLayout_2->addWidget(pushButton_4);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(100, 0));
        label_3->setFont(font);

        horizontalLayout_2->addWidget(label_3);

        dataBtn = new QPushButton(centralWidget);
        dataBtn->setObjectName(QString::fromUtf8("dataBtn"));
        dataBtn->setMinimumSize(QSize(100, 30));
        dataBtn->setFont(font);
        dataBtn->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(dataBtn);

        settingBtn = new QPushButton(centralWidget);
        settingBtn->setObjectName(QString::fromUtf8("settingBtn"));
        settingBtn->setMinimumSize(QSize(100, 30));
        settingBtn->setFont(font);
        settingBtn->setFlat(false);

        horizontalLayout_2->addWidget(settingBtn);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 1);
        horizontalLayout_2->setStretch(3, 1);
        horizontalLayout_2->setStretch(4, 1);
        horizontalLayout_2->setStretch(6, 3);
        horizontalLayout_2->setStretch(7, 1);
        horizontalLayout_2->setStretch(8, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        widget_3 = new QWidget(centralWidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_4 = new QHBoxLayout(widget_3);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(widget_3);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_6 = new QWidget(widget_2);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        horizontalLayout = new QHBoxLayout(widget_6);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(widget_6);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_7);

        label_6 = new QLabel(widget_6);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        horizontalLayout->addWidget(label_6);

        label_46 = new QLabel(widget_6);
        label_46->setObjectName(QString::fromUtf8("label_46"));
        label_46->setMinimumSize(QSize(30, 30));
        label_46->setMaximumSize(QSize(30, 30));
        label_46->setStyleSheet(QString::fromUtf8("border-image: url(:/res/img/errorl.png);"));

        horizontalLayout->addWidget(label_46);

        label_5 = new QLabel(widget_6);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(236, 0, 0);\n"
""));
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_5);

        label_4 = new QLabel(widget_6);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(236, 0, 0);"));

        horizontalLayout->addWidget(label_4);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(3, 1);
        horizontalLayout->setStretch(4, 5);

        verticalLayout_2->addWidget(widget_6);

        widget_5 = new QWidget(widget_2);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_6 = new QHBoxLayout(widget_5);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(10, 0, 0, 0);
        tabWidget = new QTabWidget(widget_5);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(16);
        tabWidget->setFont(font1);
        tabWidget->setStyleSheet(QString::fromUtf8("#tabWidget{\n"
"/*background-color: rgba(255, 255, 255, 0);\n"
"background-color:transparent;	*/\n"
"background-color: rgba(255, 255, 255);\n"
"}\n"
"\n"
"#tab1,\n"
"#tab2,\n"
"#tab3{\n"
"/*\n"
"background-color:transparent;*/\n"
"background-color: rgba(255, 255, 255);\n"
"\n"
"}\n"
"\n"
"QTabBar::tab{\n"
"	font: 75 14pt \"\351\273\221\344\275\223\";		\n"
"	width:150px;					\n"
"	height:40;\n"
"	\n"
"	/*\n"
"	margin-left:20px; 					\n"
"	margin-top:5px; 			\n"
"	margin-right:1px;\n"
"	\n"
"	border-radius: 10px;*/\n"
"	border-top: 1px solid #000000; \n"
"	border-bottom: 1px solid #000000;\n"
"	margin-bottom:5px;\n"
"}\n"
"QTabBar::tab:first{\n"
"	margin-left:20px; \n"
"	border-left: 1px solid #000000; \n"
"	border-top-left-radius: 20px;\n"
"	border-bottom-left-radius: 20px;\n"
"}\n"
"QTabBar::tab:last{\n"
"	border-right: 1px solid #000000; \n"
"	border-top-right-radius: 20px;\n"
"	border-bottom-right-radius: 20px;\n"
"}\n"
"\n"
"QTabBar::tab:selected{\n"
"	color: #FFFFFF;\n"
"	background-color: #C00D6EFD;\n"
"}"
                        "\n"
" \n"
"QTabBar::tab:hover:!selected {\n"
"    background-color: #640D6EFD;\n"
"}\n"
"\n"
"QTabWidget::pane {\n"
"    border: 1px solid rgb(108, 117, 125, 65);\n"
"}"));
        tab1 = new QWidget();
        tab1->setObjectName(QString::fromUtf8("tab1"));
        tab1->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_5 = new QVBoxLayout(tab1);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        widget_12 = new QWidget(tab1);
        widget_12->setObjectName(QString::fromUtf8("widget_12"));
        horizontalLayout_8 = new QHBoxLayout(widget_12);
        horizontalLayout_8->setSpacing(10);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(20, 10, 10, 10);
        label_38 = new QLabel(widget_12);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setMinimumSize(QSize(0, 30));
        label_38->setFont(font);

        horizontalLayout_8->addWidget(label_38);

        comboBox_4 = new QComboBox(widget_12);
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));
        comboBox_4->setMinimumSize(QSize(0, 30));
        comboBox_4->setMaximumSize(QSize(16777215, 50));
        comboBox_4->setFont(font);

        horizontalLayout_8->addWidget(comboBox_4);

        pushButton_11 = new QPushButton(widget_12);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setMinimumSize(QSize(0, 30));
        pushButton_11->setMaximumSize(QSize(16777215, 50));
        pushButton_11->setFont(font);

        horizontalLayout_8->addWidget(pushButton_11);

        comboBox_5 = new QComboBox(widget_12);
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->setObjectName(QString::fromUtf8("comboBox_5"));
        comboBox_5->setMinimumSize(QSize(0, 30));
        comboBox_5->setMaximumSize(QSize(16777215, 50));
        comboBox_5->setFont(font);

        horizontalLayout_8->addWidget(comboBox_5);

        label_39 = new QLabel(widget_12);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setMinimumSize(QSize(0, 30));
        label_39->setFont(font);

        horizontalLayout_8->addWidget(label_39);

        pushButton_13 = new QPushButton(widget_12);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));
        pushButton_13->setMinimumSize(QSize(30, 30));
        pushButton_13->setFont(font);
        pushButton_13->setStyleSheet(QString::fromUtf8("border-image: url(:/res/img/MenuSmallblack.png);"));
        pushButton_13->setFlat(true);

        horizontalLayout_8->addWidget(pushButton_13);

        horizontalLayout_8->setStretch(0, 1);
        horizontalLayout_8->setStretch(1, 1);
        horizontalLayout_8->setStretch(2, 1);
        horizontalLayout_8->setStretch(3, 1);
        horizontalLayout_8->setStretch(4, 5);

        verticalLayout_5->addWidget(widget_12);

        tabWidget_2 = new QTabWidget(tab1);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(12);
        tabWidget_2->setFont(font2);
        tabWidget_2->setStyleSheet(QString::fromUtf8("\n"
"QTabBar::tab{	\n"
"	width:120px;					\n"
"	height:30;\n"
"	\n"
"	/* 					\n"
"	margin-top:5px; 			\n"
"	margin-right:1px;\n"
"	\n"
"	border-radius: 10px;*/\n"
"	margin-bottom:5px;\n"
"}\n"
"\n"
"QTabBar::tab:first{\n"
"	margin-left:20px;\n"
"	border-left: 1px solid #000000; \n"
"	border-top-left-radius: 15px;\n"
"	border-bottom-left-radius: 15px;\n"
"}\n"
"QTabBar::tab:last{\n"
"	border-right: 1px solid #000000; \n"
"	border-top-right-radius: 15px;\n"
"	border-bottom-right-radius: 15px;\n"
"}\n"
""));
        tab1_1 = new QWidget();
        tab1_1->setObjectName(QString::fromUtf8("tab1_1"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        tab1_1->setFont(font3);
        tab1_1->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(tab1_1);
        gridLayout->setSpacing(10);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(20, 0, 20, 0);
        tabWidget_2->addTab(tab1_1, QString());
        tab1_2 = new QWidget();
        tab1_2->setObjectName(QString::fromUtf8("tab1_2"));
        tab1_2->setFont(font3);
        gridLayout_2 = new QGridLayout(tab1_2);
        gridLayout_2->setSpacing(10);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(20, 0, 20, 0);
        label_35 = new QLabel(tab1_2);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setMinimumSize(QSize(0, 30));
        label_35->setFont(font);
        label_35->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_35, 0, 0, 1, 1);

        lineEdit_26 = new QLineEdit(tab1_2);
        lineEdit_26->setObjectName(QString::fromUtf8("lineEdit_26"));
        lineEdit_26->setMinimumSize(QSize(0, 30));
        lineEdit_26->setFont(font);

        gridLayout_2->addWidget(lineEdit_26, 0, 1, 1, 1);

        label_33 = new QLabel(tab1_2);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setMinimumSize(QSize(0, 30));
        label_33->setFont(font);
        label_33->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_33, 0, 2, 1, 1);

        lineEdit_20 = new QLineEdit(tab1_2);
        lineEdit_20->setObjectName(QString::fromUtf8("lineEdit_20"));
        lineEdit_20->setMinimumSize(QSize(0, 30));
        lineEdit_20->setFont(font);

        gridLayout_2->addWidget(lineEdit_20, 0, 3, 1, 1);

        label_32 = new QLabel(tab1_2);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setMinimumSize(QSize(0, 30));
        label_32->setFont(font);
        label_32->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_32, 1, 0, 1, 1);

        lineEdit_16 = new QLineEdit(tab1_2);
        lineEdit_16->setObjectName(QString::fromUtf8("lineEdit_16"));
        lineEdit_16->setMinimumSize(QSize(0, 30));
        lineEdit_16->setFont(font);

        gridLayout_2->addWidget(lineEdit_16, 1, 1, 1, 1);

        label_34 = new QLabel(tab1_2);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setMinimumSize(QSize(0, 30));
        label_34->setFont(font);
        label_34->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_34, 1, 2, 1, 1);

        lineEdit_15 = new QLineEdit(tab1_2);
        lineEdit_15->setObjectName(QString::fromUtf8("lineEdit_15"));
        lineEdit_15->setMinimumSize(QSize(0, 30));
        lineEdit_15->setFont(font);

        gridLayout_2->addWidget(lineEdit_15, 1, 3, 1, 1);

        label_28 = new QLabel(tab1_2);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setMinimumSize(QSize(0, 30));
        label_28->setFont(font);
        label_28->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_28, 2, 0, 1, 1);

        lineEdit_25 = new QLineEdit(tab1_2);
        lineEdit_25->setObjectName(QString::fromUtf8("lineEdit_25"));
        lineEdit_25->setMinimumSize(QSize(0, 30));
        lineEdit_25->setFont(font);

        gridLayout_2->addWidget(lineEdit_25, 2, 1, 1, 1);

        label_24 = new QLabel(tab1_2);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setMinimumSize(QSize(0, 30));
        label_24->setFont(font);
        label_24->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_24, 2, 2, 1, 1);

        lineEdit_17 = new QLineEdit(tab1_2);
        lineEdit_17->setObjectName(QString::fromUtf8("lineEdit_17"));
        lineEdit_17->setMinimumSize(QSize(0, 30));
        lineEdit_17->setFont(font);

        gridLayout_2->addWidget(lineEdit_17, 2, 3, 1, 1);

        label_37 = new QLabel(tab1_2);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setMinimumSize(QSize(0, 30));
        label_37->setFont(font);
        label_37->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_37, 3, 0, 1, 1);

        lineEdit_24 = new QLineEdit(tab1_2);
        lineEdit_24->setObjectName(QString::fromUtf8("lineEdit_24"));
        lineEdit_24->setMinimumSize(QSize(0, 30));
        lineEdit_24->setFont(font);

        gridLayout_2->addWidget(lineEdit_24, 3, 1, 1, 1);

        label_30 = new QLabel(tab1_2);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setMinimumSize(QSize(0, 30));
        label_30->setFont(font);
        label_30->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_30, 3, 2, 1, 1);

        lineEdit_21 = new QLineEdit(tab1_2);
        lineEdit_21->setObjectName(QString::fromUtf8("lineEdit_21"));
        lineEdit_21->setMinimumSize(QSize(0, 30));
        lineEdit_21->setFont(font);

        gridLayout_2->addWidget(lineEdit_21, 3, 3, 1, 1);

        label_25 = new QLabel(tab1_2);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setMinimumSize(QSize(0, 30));
        label_25->setFont(font);
        label_25->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_25, 4, 0, 1, 1);

        lineEdit_23 = new QLineEdit(tab1_2);
        lineEdit_23->setObjectName(QString::fromUtf8("lineEdit_23"));
        lineEdit_23->setMinimumSize(QSize(0, 30));
        lineEdit_23->setFont(font);

        gridLayout_2->addWidget(lineEdit_23, 4, 1, 1, 1);

        label_27 = new QLabel(tab1_2);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setMinimumSize(QSize(0, 30));
        label_27->setFont(font);
        label_27->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_27, 4, 2, 1, 1);

        lineEdit_22 = new QLineEdit(tab1_2);
        lineEdit_22->setObjectName(QString::fromUtf8("lineEdit_22"));
        lineEdit_22->setMinimumSize(QSize(0, 30));
        lineEdit_22->setFont(font);

        gridLayout_2->addWidget(lineEdit_22, 4, 3, 1, 1);

        label_29 = new QLabel(tab1_2);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setMinimumSize(QSize(0, 30));
        label_29->setFont(font);
        label_29->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_29, 5, 0, 1, 1);

        lineEdit_28 = new QLineEdit(tab1_2);
        lineEdit_28->setObjectName(QString::fromUtf8("lineEdit_28"));
        lineEdit_28->setMinimumSize(QSize(0, 30));
        lineEdit_28->setFont(font);

        gridLayout_2->addWidget(lineEdit_28, 5, 1, 1, 1);

        label_36 = new QLabel(tab1_2);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setMinimumSize(QSize(0, 30));
        label_36->setFont(font);
        label_36->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_36, 5, 2, 1, 1);

        lineEdit_19 = new QLineEdit(tab1_2);
        lineEdit_19->setObjectName(QString::fromUtf8("lineEdit_19"));
        lineEdit_19->setMinimumSize(QSize(0, 30));
        lineEdit_19->setFont(font);

        gridLayout_2->addWidget(lineEdit_19, 5, 3, 1, 1);

        label_26 = new QLabel(tab1_2);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setMinimumSize(QSize(0, 30));
        label_26->setFont(font);
        label_26->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_26, 6, 0, 1, 1);

        lineEdit_18 = new QLineEdit(tab1_2);
        lineEdit_18->setObjectName(QString::fromUtf8("lineEdit_18"));
        lineEdit_18->setMinimumSize(QSize(0, 30));
        lineEdit_18->setFont(font);

        gridLayout_2->addWidget(lineEdit_18, 6, 1, 1, 1);

        label_31 = new QLabel(tab1_2);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setMinimumSize(QSize(0, 30));
        label_31->setFont(font);
        label_31->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_31, 6, 2, 1, 1);

        lineEdit_27 = new QLineEdit(tab1_2);
        lineEdit_27->setObjectName(QString::fromUtf8("lineEdit_27"));
        lineEdit_27->setMinimumSize(QSize(0, 30));
        lineEdit_27->setFont(font);

        gridLayout_2->addWidget(lineEdit_27, 6, 3, 1, 1);

        gridLayout_2->setColumnStretch(0, 1);
        gridLayout_2->setColumnStretch(1, 1);
        gridLayout_2->setColumnStretch(2, 1);
        gridLayout_2->setColumnStretch(3, 1);
        tabWidget_2->addTab(tab1_2, QString());

        verticalLayout_5->addWidget(tabWidget_2);

        verticalLayout_5->setStretch(0, 1);
        verticalLayout_5->setStretch(1, 12);
        tabWidget->addTab(tab1, QString());
        tab2 = new QWidget();
        tab2->setObjectName(QString::fromUtf8("tab2"));
        tab2->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_4 = new QVBoxLayout(tab2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 10, 0, 0);
        tableWidget = new QTableWidget(tab2);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        if (tableWidget->rowCount() < 4)
            tableWidget->setRowCount(4);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setItem(0, 1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setItem(0, 2, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setItem(0, 3, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setItem(0, 4, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setItem(0, 5, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setItem(1, 0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setItem(1, 1, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setItem(1, 2, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget->setItem(1, 3, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget->setItem(1, 4, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget->setItem(1, 5, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget->setItem(2, 0, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget->setItem(2, 1, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget->setItem(2, 2, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget->setItem(2, 3, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget->setItem(2, 4, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget->setItem(2, 5, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget->setItem(3, 0, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget->setItem(3, 1, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget->setItem(3, 2, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget->setItem(3, 3, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableWidget->setItem(3, 4, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableWidget->setItem(3, 5, __qtablewidgetitem33);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setStyleSheet(QString::fromUtf8("#tableWidget{\n"
"\n"
"	color: rgb(52, 52, 52);\n"
"	font: 75 14pt \"\351\273\221\344\275\223\";\n"
"border:1px solid #A0A0A0;\n"
"border-radius: 6px;\n"
"/*border:none;\n"
"background-color:transparent;*/\n"
"}\n"
"\n"
"QTableWidget::item\n"
"{\n"
"    border-bottom:1px solid #A0A0A0;\n"
"	background-color: #FFFFFF;\n"
"}\n"
"\n"
"QTableWidget::item:!alternate:!selected{\n"
"    selection-background-color:#3E66FBDF;\n"
"	background: #E0E0E0;  \n"
"}\n"
"\n"
"QTableWidget::item:hover{\n"
"background-color:#640D6EFD;\n"
"}\n"
"\n"
"QTableWidget::item:selected{\n"
"color: #FFFFFF;\n"
"background-color: #C00D6EFD;\n"
"}\n"
"\n"
"QHeaderView::section{\n"
"	font: 75 14pt \"\351\273\221\344\275\223\";\n"
"	background-color:transparent;\n"
"	border-radius: 6px;\n"
"}\n"
"\n"
"/*\n"
"\n"
"QTableWidget::selected{\n"
"color: #FFFFFF;\n"
"background-color: #C00D6EFD;\n"
"}\n"
"\n"
"QTableWidget::selected{\n"
"color:#F4F4F4;\n"
"background-color:#353535;\n"
"}\n"
"QHeaderView::section{\n"
"background-color:#393939;\n"
"ba"
                        "ckground-color:transparent;\n"
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
"*/"));
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setShowGrid(false);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(true);
        tableWidget->horizontalHeader()->setHighlightSections(true);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setHighlightSections(true);

        verticalLayout_4->addWidget(tableWidget);

        widget_9 = new QWidget(tab2);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        horizontalLayout_7 = new QHBoxLayout(widget_9);
        horizontalLayout_7->setSpacing(10);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        widget_10 = new QWidget(widget_9);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        widget_10->setStyleSheet(QString::fromUtf8("border-image: url(:/res/img/bg/tu.png);"));

        horizontalLayout_7->addWidget(widget_10);

        widget_11 = new QWidget(widget_9);
        widget_11->setObjectName(QString::fromUtf8("widget_11"));
        widget_11->setStyleSheet(QString::fromUtf8("\n"
"QCheckBox{\n"
"color: rgb(0, 0, 0);\n"
"font: 75 16pt \"\351\273\221\344\275\223\";\n"
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
"}"));
        verticalLayout_9 = new QVBoxLayout(widget_11);
        verticalLayout_9->setSpacing(5);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        widget_16 = new QWidget(widget_11);
        widget_16->setObjectName(QString::fromUtf8("widget_16"));
        horizontalLayout_10 = new QHBoxLayout(widget_16);
        horizontalLayout_10->setSpacing(5);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 10, 0);
        checkBox = new QCheckBox(widget_16);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setIconSize(QSize(16, 16));
        checkBox->setChecked(true);

        horizontalLayout_10->addWidget(checkBox);

        pushButton_15 = new QPushButton(widget_16);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));
        pushButton_15->setMinimumSize(QSize(30, 30));
        pushButton_15->setMaximumSize(QSize(40, 40));
        pushButton_15->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));

        horizontalLayout_10->addWidget(pushButton_15);


        verticalLayout_9->addWidget(widget_16);

        widget_17 = new QWidget(widget_11);
        widget_17->setObjectName(QString::fromUtf8("widget_17"));
        horizontalLayout_11 = new QHBoxLayout(widget_17);
        horizontalLayout_11->setSpacing(5);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 10, 0);
        checkBox_2 = new QCheckBox(widget_17);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setIconSize(QSize(16, 16));
        checkBox_2->setChecked(true);

        horizontalLayout_11->addWidget(checkBox_2);

        pushButton_16 = new QPushButton(widget_17);
        pushButton_16->setObjectName(QString::fromUtf8("pushButton_16"));
        pushButton_16->setMinimumSize(QSize(30, 30));
        pushButton_16->setMaximumSize(QSize(40, 40));
        pushButton_16->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 0);"));

        horizontalLayout_11->addWidget(pushButton_16);


        verticalLayout_9->addWidget(widget_17);

        widget_18 = new QWidget(widget_11);
        widget_18->setObjectName(QString::fromUtf8("widget_18"));
        horizontalLayout_12 = new QHBoxLayout(widget_18);
        horizontalLayout_12->setSpacing(5);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 10, 0);
        checkBox_3 = new QCheckBox(widget_18);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setIconSize(QSize(16, 16));
        checkBox_3->setChecked(true);

        horizontalLayout_12->addWidget(checkBox_3);

        pushButton_17 = new QPushButton(widget_18);
        pushButton_17->setObjectName(QString::fromUtf8("pushButton_17"));
        pushButton_17->setMinimumSize(QSize(30, 30));
        pushButton_17->setMaximumSize(QSize(40, 40));
        pushButton_17->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 255);"));

        horizontalLayout_12->addWidget(pushButton_17);

        pushButton_17->raise();
        checkBox_3->raise();

        verticalLayout_9->addWidget(widget_18);

        widget_19 = new QWidget(widget_11);
        widget_19->setObjectName(QString::fromUtf8("widget_19"));
        horizontalLayout_13 = new QHBoxLayout(widget_19);
        horizontalLayout_13->setSpacing(5);
        horizontalLayout_13->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(0, 0, 10, 0);
        checkBox_4 = new QCheckBox(widget_19);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setIconSize(QSize(16, 16));
        checkBox_4->setChecked(true);

        horizontalLayout_13->addWidget(checkBox_4);

        pushButton_18 = new QPushButton(widget_19);
        pushButton_18->setObjectName(QString::fromUtf8("pushButton_18"));
        pushButton_18->setMinimumSize(QSize(30, 30));
        pushButton_18->setMaximumSize(QSize(40, 40));
        pushButton_18->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 0);"));

        horizontalLayout_13->addWidget(pushButton_18);


        verticalLayout_9->addWidget(widget_19);


        horizontalLayout_7->addWidget(widget_11);

        horizontalLayout_7->setStretch(0, 5);
        horizontalLayout_7->setStretch(1, 1);

        verticalLayout_4->addWidget(widget_9);

        verticalLayout_4->setStretch(0, 1);
        verticalLayout_4->setStretch(1, 1);
        tabWidget->addTab(tab2, QString());
        tab3 = new QWidget();
        tab3->setObjectName(QString::fromUtf8("tab3"));
        verticalLayout_8 = new QVBoxLayout(tab3);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        widget_14 = new QWidget(tab3);
        widget_14->setObjectName(QString::fromUtf8("widget_14"));
        horizontalLayout_9 = new QHBoxLayout(widget_14);
        horizontalLayout_9->setSpacing(10);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(20, 10, 10, 10);
        label_40 = new QLabel(widget_14);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setMinimumSize(QSize(0, 30));
        label_40->setFont(font);

        horizontalLayout_9->addWidget(label_40);

        comboBox_6 = new QComboBox(widget_14);
        comboBox_6->setObjectName(QString::fromUtf8("comboBox_6"));
        comboBox_6->setMinimumSize(QSize(0, 30));
        comboBox_6->setMaximumSize(QSize(16777215, 50));
        comboBox_6->setFont(font);

        horizontalLayout_9->addWidget(comboBox_6);

        pushButton_12 = new QPushButton(widget_14);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        pushButton_12->setMinimumSize(QSize(0, 30));
        pushButton_12->setMaximumSize(QSize(16777215, 50));
        pushButton_12->setFont(font);

        horizontalLayout_9->addWidget(pushButton_12);

        comboBox_7 = new QComboBox(widget_14);
        comboBox_7->addItem(QString());
        comboBox_7->addItem(QString());
        comboBox_7->addItem(QString());
        comboBox_7->addItem(QString());
        comboBox_7->setObjectName(QString::fromUtf8("comboBox_7"));
        comboBox_7->setMinimumSize(QSize(0, 30));
        comboBox_7->setMaximumSize(QSize(16777215, 50));
        comboBox_7->setFont(font);

        horizontalLayout_9->addWidget(comboBox_7);

        label_41 = new QLabel(widget_14);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setMinimumSize(QSize(0, 30));
        label_41->setFont(font);

        horizontalLayout_9->addWidget(label_41);

        pushButton_14 = new QPushButton(widget_14);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));
        pushButton_14->setMinimumSize(QSize(30, 30));
        pushButton_14->setStyleSheet(QString::fromUtf8("border-image: url(:/res/img/MenuBigblack.png);"));

        horizontalLayout_9->addWidget(pushButton_14);

        horizontalLayout_9->setStretch(0, 1);
        horizontalLayout_9->setStretch(1, 1);
        horizontalLayout_9->setStretch(2, 1);
        horizontalLayout_9->setStretch(3, 1);
        horizontalLayout_9->setStretch(4, 5);

        verticalLayout_8->addWidget(widget_14);

        widget_15 = new QWidget(tab3);
        widget_15->setObjectName(QString::fromUtf8("widget_15"));
        widget_15->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font: 75 54pt \"\351\273\221\344\275\223\";\n"
"}"));
        gridLayout_3 = new QGridLayout(widget_15);
        gridLayout_3->setSpacing(20);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 10, 10, 10);
        label_42 = new QLabel(widget_15);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font4.setPointSize(54);
        font4.setBold(false);
        font4.setItalic(false);
        font4.setWeight(9);
        label_42->setFont(font4);
        label_42->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_42, 0, 0, 1, 1);

        lcdNumber = new QLCDNumber(widget_15);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        QFont font5;
        font5.setPointSize(9);
        lcdNumber->setFont(font5);
        lcdNumber->setStyleSheet(QString::fromUtf8(""));
        lcdNumber->setFrameShape(QFrame::StyledPanel);
        lcdNumber->setFrameShadow(QFrame::Raised);

        gridLayout_3->addWidget(lcdNumber, 0, 1, 1, 1);

        label_43 = new QLabel(widget_15);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setFont(font4);
        label_43->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_43, 0, 2, 1, 1);

        lcdNumber_2 = new QLCDNumber(widget_15);
        lcdNumber_2->setObjectName(QString::fromUtf8("lcdNumber_2"));
        lcdNumber_2->setFrameShape(QFrame::StyledPanel);
        lcdNumber_2->setFrameShadow(QFrame::Raised);

        gridLayout_3->addWidget(lcdNumber_2, 0, 3, 1, 1);

        label_44 = new QLabel(widget_15);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setFont(font4);
        label_44->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_44, 1, 0, 1, 1);

        lcdNumber_3 = new QLCDNumber(widget_15);
        lcdNumber_3->setObjectName(QString::fromUtf8("lcdNumber_3"));
        lcdNumber_3->setFrameShape(QFrame::StyledPanel);

        gridLayout_3->addWidget(lcdNumber_3, 1, 1, 1, 1);

        label_45 = new QLabel(widget_15);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        label_45->setFont(font4);
        label_45->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_45, 1, 2, 1, 1);

        lcdNumber_4 = new QLCDNumber(widget_15);
        lcdNumber_4->setObjectName(QString::fromUtf8("lcdNumber_4"));
        lcdNumber_4->setFrameShape(QFrame::StyledPanel);

        gridLayout_3->addWidget(lcdNumber_4, 1, 3, 1, 1);


        verticalLayout_8->addWidget(widget_15);

        verticalLayout_8->setStretch(0, 1);
        verticalLayout_8->setStretch(1, 12);
        tabWidget->addTab(tab3, QString());

        horizontalLayout_6->addWidget(tabWidget);


        verticalLayout_2->addWidget(widget_5);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 9);

        horizontalLayout_4->addWidget(widget_2);

        widget_4 = new QWidget(widget_3);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_3 = new QVBoxLayout(widget_4);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(20, 0, 20, 10);
        widget_13 = new QWidget(widget_4);
        widget_13->setObjectName(QString::fromUtf8("widget_13"));
        verticalLayout_7 = new QVBoxLayout(widget_13);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(widget_13);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        verticalLayout_7->addWidget(label_8);

        widget_8 = new QWidget(widget_13);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        horizontalLayout_5 = new QHBoxLayout(widget_8);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        comboBox_3 = new QComboBox(widget_8);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setMinimumSize(QSize(60, 40));
        comboBox_3->setFont(font);

        horizontalLayout_5->addWidget(comboBox_3);

        pushButton_7 = new QPushButton(widget_8);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setMinimumSize(QSize(60, 40));
        pushButton_7->setFont(font);

        horizontalLayout_5->addWidget(pushButton_7);


        verticalLayout_7->addWidget(widget_8);

        verticalLayout_7->setStretch(0, 1);
        verticalLayout_7->setStretch(1, 3);

        verticalLayout_3->addWidget(widget_13);

        widget_7 = new QWidget(widget_4);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        verticalLayout_6 = new QVBoxLayout(widget_7);
        verticalLayout_6->setSpacing(30);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(widget_7);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);

        verticalLayout_6->addWidget(label_9);

        pushButton_8 = new QPushButton(widget_7);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setMinimumSize(QSize(0, 40));
        pushButton_8->setFont(font);

        verticalLayout_6->addWidget(pushButton_8);

        pushButton_9 = new QPushButton(widget_7);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setMinimumSize(QSize(0, 40));
        pushButton_9->setFont(font);

        verticalLayout_6->addWidget(pushButton_9);

        pushButton_10 = new QPushButton(widget_7);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setMinimumSize(QSize(0, 40));
        pushButton_10->setFont(font);

        verticalLayout_6->addWidget(pushButton_10);

        verticalLayout_6->setStretch(0, 1);
        verticalLayout_6->setStretch(1, 2);
        verticalLayout_6->setStretch(2, 2);
        verticalLayout_6->setStretch(3, 2);

        verticalLayout_3->addWidget(widget_7);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 1);

        horizontalLayout_4->addWidget(widget_4);

        horizontalLayout_4->setStretch(0, 6);
        horizontalLayout_4->setStretch(1, 1);

        verticalLayout->addWidget(widget_3);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 12);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        minBtn->setText(QString());
        maxBtn->setText(QString());
        closeBtn->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\345\217\267:", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));

        label_2->setText(QCoreApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207:", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));

        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245\350\256\276\345\244\207", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\346\226\255\345\274\200\350\256\276\345\244\207", nullptr));
        label_3->setText(QString());
        dataBtn->setText(QCoreApplication::translate("MainWindow", "\345\216\206\345\217\262\346\225\260\346\215\256", nullptr));
        settingBtn->setText(QCoreApplication::translate("MainWindow", "\347\263\273\347\273\237\350\256\276\347\275\256", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\350\256\276\345\244\207\347\212\266\346\200\201: ", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\345\267\262\350\277\236\346\216\245", nullptr));
        label_46->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", " \346\212\245\350\255\246\344\277\241\346\201\257: ", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\347\224\265\345\216\213\350\266\205\344\270\212\351\231\220", nullptr));
        label_38->setText(QCoreApplication::translate("MainWindow", "\345\275\223\345\211\215\351\200\232\351\201\223", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "\345\217\254\346\265\213", nullptr));
        comboBox_5->setItemText(0, QCoreApplication::translate("MainWindow", "A", nullptr));
        comboBox_5->setItemText(1, QCoreApplication::translate("MainWindow", "B", nullptr));
        comboBox_5->setItemText(2, QCoreApplication::translate("MainWindow", "C", nullptr));
        comboBox_5->setItemText(3, QCoreApplication::translate("MainWindow", "\345\220\210\351\241\271", nullptr));

        label_39->setText(QString());
        pushButton_13->setText(QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab1_1), QCoreApplication::translate("MainWindow", "\345\215\225\351\241\271", nullptr));
        label_35->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_33->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_32->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_34->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_37->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_36->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab1_2), QCoreApplication::translate("MainWindow", "\344\270\211\347\233\270", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab1), QCoreApplication::translate("MainWindow", "\345\217\254\346\265\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\345\272\217\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\347\224\265\345\216\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\265\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "\345\212\237\347\216\207", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "\351\242\221\347\216\207", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "\345\234\260\345\235\200", nullptr));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->item(0, 0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->item(0, 1);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "220", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->item(0, 2);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "1.00", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->item(0, 3);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "220", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->item(0, 4);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "50", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->item(0, 5);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->item(1, 0);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->item(1, 1);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "220", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->item(1, 2);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "2.00", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->item(1, 3);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "440", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->item(1, 4);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "60", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->item(1, 5);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->item(2, 0);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->item(2, 1);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("MainWindow", "220", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->item(2, 2);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("MainWindow", "3.00", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->item(2, 3);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("MainWindow", "660", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->item(2, 4);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("MainWindow", "50", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget->item(2, 5);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget->item(3, 0);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget->item(3, 1);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("MainWindow", "220", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget->item(3, 2);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("MainWindow", "4.00", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget->item(3, 3);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("MainWindow", "880", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget->item(3, 4);
        ___qtablewidgetitem28->setText(QCoreApplication::translate("MainWindow", "60", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget->item(3, 5);
        ___qtablewidgetitem29->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        tableWidget->setSortingEnabled(__sortingEnabled);

        checkBox->setText(QCoreApplication::translate("MainWindow", " V ", nullptr));
        pushButton_15->setText(QString());
        checkBox_2->setText(QCoreApplication::translate("MainWindow", " I ", nullptr));
        pushButton_16->setText(QString());
        checkBox_3->setText(QCoreApplication::translate("MainWindow", " P ", nullptr));
        pushButton_17->setText(QString());
        checkBox_4->setText(QCoreApplication::translate("MainWindow", " HZ ", nullptr));
        pushButton_18->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab2), QCoreApplication::translate("MainWindow", "\345\267\241\346\243\200", nullptr));
        label_40->setText(QCoreApplication::translate("MainWindow", "\345\275\223\345\211\215\351\200\232\351\201\223", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "\345\217\254\346\265\213", nullptr));
        comboBox_7->setItemText(0, QCoreApplication::translate("MainWindow", "A", nullptr));
        comboBox_7->setItemText(1, QCoreApplication::translate("MainWindow", "B", nullptr));
        comboBox_7->setItemText(2, QCoreApplication::translate("MainWindow", "C", nullptr));
        comboBox_7->setItemText(3, QCoreApplication::translate("MainWindow", "\345\220\210\351\241\271", nullptr));

        label_41->setText(QString());
        pushButton_14->setText(QString());
        label_42->setText(QCoreApplication::translate("MainWindow", "\347\224\265\345\216\213", nullptr));
        label_43->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\265\201", nullptr));
        label_44->setText(QCoreApplication::translate("MainWindow", "\345\212\237\347\216\207", nullptr));
        label_45->setText(QCoreApplication::translate("MainWindow", "\351\242\221\347\216\207", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab3), QCoreApplication::translate("MainWindow", "\345\217\254\346\265\213", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\351\200\232\351\201\223\345\217\267", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\347\224\265\350\203\275\346\216\247\345\210\266", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "\347\224\265\350\203\275\345\220\257\345\212\250", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "\347\224\265\350\203\275\345\201\234\346\255\242", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "\347\224\265\350\203\275\346\270\205\351\233\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
