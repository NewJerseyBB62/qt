/********************************************************************************
** Form generated from reading UI file 'warningdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WARNINGDIALOG_H
#define UI_WARNINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WarningDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QLabel *warningLab;
    QLabel *WarningVal;
    QPushButton *okBnt;

    void setupUi(QDialog *WarningDialog)
    {
        if (WarningDialog->objectName().isEmpty())
            WarningDialog->setObjectName(QString::fromUtf8("WarningDialog"));
        WarningDialog->setWindowModality(Qt::NonModal);
        WarningDialog->resize(480, 270);
        WarningDialog->setMinimumSize(QSize(480, 270));
        WarningDialog->setMaximumSize(QSize(480, 270));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font.setPointSize(16);
        WarningDialog->setFont(font);
        WarningDialog->setStyleSheet(QString::fromUtf8(""));
        WarningDialog->setSizeGripEnabled(false);
        WarningDialog->setModal(false);
        verticalLayout = new QVBoxLayout(WarningDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(7, 7, 7, 7);
        widget = new QWidget(WarningDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("#widget{\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 20px;\n"
"border:none;\n"
"}"));
        warningLab = new QLabel(widget);
        warningLab->setObjectName(QString::fromUtf8("warningLab"));
        warningLab->setGeometry(QRect(40, 40, 41, 41));
        warningLab->setStyleSheet(QString::fromUtf8("border-image: url(:/icon/errorl.png);"));
        WarningVal = new QLabel(widget);
        WarningVal->setObjectName(QString::fromUtf8("WarningVal"));
        WarningVal->setGeometry(QRect(100, 50, 341, 91));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(14);
        WarningVal->setFont(font1);
        WarningVal->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        WarningVal->setWordWrap(true);
        okBnt = new QPushButton(widget);
        okBnt->setObjectName(QString::fromUtf8("okBnt"));
        okBnt->setGeometry(QRect(340, 180, 80, 40));
        okBnt->setMinimumSize(QSize(80, 40));
        okBnt->setMaximumSize(QSize(80, 40));
        okBnt->setFont(font1);
        okBnt->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: #A92525;\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 8px;\n"
"}\n"
"QPushButton::hover{\n"
"background-color: #F7E9E9;\n"
"color: #A92525;\n"
"};"));
        okBnt->setFlat(true);

        verticalLayout->addWidget(widget);

        verticalLayout->setStretch(0, 2);

        retranslateUi(WarningDialog);

        QMetaObject::connectSlotsByName(WarningDialog);
    } // setupUi

    void retranslateUi(QDialog *WarningDialog)
    {
        WarningDialog->setWindowTitle(QCoreApplication::translate("WarningDialog", "Warning", nullptr));
        warningLab->setText(QString());
        WarningVal->setText(QString());
        okBnt->setText(QCoreApplication::translate("WarningDialog", "\347\241\256\350\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WarningDialog: public Ui_WarningDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WARNINGDIALOG_H
