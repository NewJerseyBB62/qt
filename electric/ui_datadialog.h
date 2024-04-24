/********************************************************************************
** Form generated from reading UI file 'datadialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATADIALOG_H
#define UI_DATADIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *minBtn;
    QPushButton *closeBtn;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QDateEdit *dateEdit;
    QLabel *label_2;
    QDateEdit *dateEdit_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_3;
    QTableView *tableView;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QLineEdit *lineEdit;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;

    void setupUi(QDialog *DataDialog)
    {
        if (DataDialog->objectName().isEmpty())
            DataDialog->setObjectName(QStringLiteral("DataDialog"));
        DataDialog->resize(800, 600);
        DataDialog->setStyleSheet(QString::fromUtf8("QDialog{\n"
"border-image: url(:/res/img/bg/bg6.jpg);\n"
"}\n"
"\n"
"QPushButton{\n"
"Border-radius: 2px;\n"
"background-color: rgb(255, 255, 255);\n"
"border: 1px solid rgba(0, 0, 0, 100);\n"
"color: rgb(50, 50, 50);\n"
"font-family: \351\273\221\344\275\223;\n"
"font-size: 16px;\n"
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
"QLabel{\n"
"font-family: \351\273\221\344\275\223;\n"
"font-size: 16px;\n"
"}\n"
"\n"
"QDateEdit{\n"
"font-family: \351\273\221\344\275\223;\n"
"font-size: 16px;\n"
"}\n"
"\n"
""));
        verticalLayout = new QVBoxLayout(DataDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(DataDialog);
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
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(20);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 20, 0);
        horizontalSpacer = new QSpacerItem(657, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        minBtn = new QPushButton(widget);
        minBtn->setObjectName(QStringLiteral("minBtn"));
        minBtn->setMinimumSize(QSize(40, 40));
        minBtn->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout->addWidget(minBtn);

        closeBtn = new QPushButton(widget);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));
        closeBtn->setMinimumSize(QSize(40, 40));
        closeBtn->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout->addWidget(closeBtn);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(DataDialog);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 20);
        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(10, 0, 10, 0);
        label = new QLabel(widget_3);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        label->setFont(font);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label);

        dateEdit = new QDateEdit(widget_3);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setMinimumSize(QSize(0, 30));
        dateEdit->setFont(font);
        dateEdit->setCalendarPopup(true);

        horizontalLayout_2->addWidget(dateEdit);

        label_2 = new QLabel(widget_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_2);

        dateEdit_2 = new QDateEdit(widget_3);
        dateEdit_2->setObjectName(QStringLiteral("dateEdit_2"));
        dateEdit_2->setMinimumSize(QSize(0, 30));
        dateEdit_2->setFont(font);
        dateEdit_2->setCalendarPopup(true);

        horizontalLayout_2->addWidget(dateEdit_2);

        pushButton_3 = new QPushButton(widget_3);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(0, 30));
        pushButton_3->setFont(font);

        horizontalLayout_2->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(widget_3);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(0, 30));
        pushButton_4->setFont(font);

        horizontalLayout_2->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(widget_3);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(0, 30));
        pushButton_5->setFont(font);

        horizontalLayout_2->addWidget(pushButton_5);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 2);
        horizontalLayout_2->setStretch(2, 1);
        horizontalLayout_2->setStretch(3, 2);
        horizontalLayout_2->setStretch(4, 1);
        horizontalLayout_2->setStretch(5, 1);
        horizontalLayout_2->setStretch(6, 1);

        verticalLayout_2->addWidget(widget_3);

        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        verticalLayout_3 = new QVBoxLayout(widget_4);
        verticalLayout_3->setSpacing(5);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(10, 0, 10, 0);
        tableView = new QTableView(widget_4);
        tableView->setObjectName(QStringLiteral("tableView"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        tableView->setFont(font1);

        verticalLayout_3->addWidget(tableView);


        verticalLayout_2->addWidget(widget_4);

        widget_5 = new QWidget(widget_2);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(14);
        widget_5->setFont(font2);
        horizontalLayout_3 = new QHBoxLayout(widget_5);
        horizontalLayout_3->setSpacing(5);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(10, 0, 10, 0);
        label_3 = new QLabel(widget_5);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        label_4 = new QLabel(widget_5);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        horizontalLayout_3->addWidget(label_4);

        label_5 = new QLabel(widget_5);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_3->addWidget(label_5);

        pushButton_6 = new QPushButton(widget_5);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setMinimumSize(QSize(0, 30));
        pushButton_6->setFont(font);

        horizontalLayout_3->addWidget(pushButton_6);

        pushButton_7 = new QPushButton(widget_5);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setMinimumSize(QSize(0, 30));
        pushButton_7->setFont(font);

        horizontalLayout_3->addWidget(pushButton_7);

        lineEdit = new QLineEdit(widget_5);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 30));
        lineEdit->setFont(font);

        horizontalLayout_3->addWidget(lineEdit);

        pushButton_8 = new QPushButton(widget_5);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setMinimumSize(QSize(0, 30));
        pushButton_8->setFont(font);

        horizontalLayout_3->addWidget(pushButton_8);

        pushButton_9 = new QPushButton(widget_5);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setMinimumSize(QSize(0, 30));
        pushButton_9->setFont(font);

        horizontalLayout_3->addWidget(pushButton_9);

        pushButton_10 = new QPushButton(widget_5);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setMinimumSize(QSize(0, 30));
        pushButton_10->setFont(font);

        horizontalLayout_3->addWidget(pushButton_10);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(2, 2);
        horizontalLayout_3->setStretch(3, 1);
        horizontalLayout_3->setStretch(4, 1);
        horizontalLayout_3->setStretch(5, 1);
        horizontalLayout_3->setStretch(6, 1);
        horizontalLayout_3->setStretch(7, 1);
        horizontalLayout_3->setStretch(8, 1);

        verticalLayout_2->addWidget(widget_5);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 8);
        verticalLayout_2->setStretch(2, 1);

        verticalLayout->addWidget(widget_2);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 12);

        retranslateUi(DataDialog);

        QMetaObject::connectSlotsByName(DataDialog);
    } // setupUi

    void retranslateUi(QDialog *DataDialog)
    {
        DataDialog->setWindowTitle(QApplication::translate("DataDialog", "Dialog", Q_NULLPTR));
        minBtn->setText(QString());
        closeBtn->setText(QString());
        label->setText(QApplication::translate("DataDialog", "\350\265\267\345\247\213\346\227\266\351\227\264", Q_NULLPTR));
        label_2->setText(QApplication::translate("DataDialog", "\347\273\223\346\235\237\346\227\266\351\227\264", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("DataDialog", "\346\237\245\350\257\242", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("DataDialog", "\345\257\274\345\207\272", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("DataDialog", "\351\207\215\347\275\256", Q_NULLPTR));
        label_3->setText(QApplication::translate("DataDialog", "\345\275\223\345\211\215\351\241\265: ", Q_NULLPTR));
        label_4->setText(QApplication::translate("DataDialog", "\346\200\273\351\241\265\346\225\260: ", Q_NULLPTR));
        label_5->setText(QString());
        pushButton_6->setText(QApplication::translate("DataDialog", "\351\246\226\351\241\265", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("DataDialog", "\344\270\212\344\270\200\351\241\265", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("DataDialog", "\350\267\263\350\275\254", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("DataDialog", "\344\270\213\344\270\200\351\241\265", Q_NULLPTR));
        pushButton_10->setText(QApplication::translate("DataDialog", "\346\234\253\351\241\265", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DataDialog: public Ui_DataDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATADIALOG_H
