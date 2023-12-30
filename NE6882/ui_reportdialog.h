/********************************************************************************
** Form generated from reading UI file 'reportdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTDIALOG_H
#define UI_REPORTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_reportDialog
{
public:

    void setupUi(QDialog *reportDialog)
    {
        if (reportDialog->objectName().isEmpty())
            reportDialog->setObjectName(QString::fromUtf8("reportDialog"));
        reportDialog->resize(400, 300);

        retranslateUi(reportDialog);

        QMetaObject::connectSlotsByName(reportDialog);
    } // setupUi

    void retranslateUi(QDialog *reportDialog)
    {
        reportDialog->setWindowTitle(QCoreApplication::translate("reportDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class reportDialog: public Ui_reportDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTDIALOG_H
