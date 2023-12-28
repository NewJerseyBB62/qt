/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loginDialog
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QWidget *taskWidget;
    QPushButton *minBtn;
    QPushButton *closeBtn;
    QWidget *loginWidget;
    QLabel *userLab;
    QLineEdit *userLE;
    QLabel *label;
    QLabel *userLab_2;
    QLabel *pwdLab;
    QLineEdit *pwdLE;
    QCheckBox *rememberPwdCB;
    QPushButton *forgetPwdBtn;
    QPushButton *loginBtn;
    QPushButton *registBtn;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *loginDialog)
    {
        if (loginDialog->objectName().isEmpty())
            loginDialog->setObjectName(QStringLiteral("loginDialog"));
        loginDialog->resize(1920, 1080);
        loginDialog->setMinimumSize(QSize(1280, 720));
        gridLayout = new QGridLayout(loginDialog);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 3, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        taskWidget = new QWidget(loginDialog);
        taskWidget->setObjectName(QStringLiteral("taskWidget"));
        taskWidget->setMinimumSize(QSize(200, 40));
        taskWidget->setMaximumSize(QSize(200, 40));
        minBtn = new QPushButton(taskWidget);
        minBtn->setObjectName(QStringLiteral("minBtn"));
        minBtn->setGeometry(QRect(40, 0, 40, 40));
        closeBtn = new QPushButton(taskWidget);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));
        closeBtn->setGeometry(QRect(110, 0, 40, 40));

        gridLayout->addWidget(taskWidget, 0, 3, 1, 1);

        loginWidget = new QWidget(loginDialog);
        loginWidget->setObjectName(QStringLiteral("loginWidget"));
        loginWidget->setMinimumSize(QSize(400, 550));
        loginWidget->setMaximumSize(QSize(400, 550));
        userLab = new QLabel(loginWidget);
        userLab->setObjectName(QStringLiteral("userLab"));
        userLab->setGeometry(QRect(30, 90, 40, 40));
        userLE = new QLineEdit(loginWidget);
        userLE->setObjectName(QStringLiteral("userLE"));
        userLE->setGeometry(QRect(160, 90, 220, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(16);
        userLE->setFont(font);
        label = new QLabel(loginWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 90, 60, 40));
        label->setFont(font);
        userLab_2 = new QLabel(loginWidget);
        userLab_2->setObjectName(QStringLiteral("userLab_2"));
        userLab_2->setGeometry(QRect(30, 160, 40, 40));
        pwdLab = new QLabel(loginWidget);
        pwdLab->setObjectName(QStringLiteral("pwdLab"));
        pwdLab->setGeometry(QRect(80, 160, 60, 40));
        pwdLab->setFont(font);
        pwdLE = new QLineEdit(loginWidget);
        pwdLE->setObjectName(QStringLiteral("pwdLE"));
        pwdLE->setGeometry(QRect(160, 160, 220, 40));
        pwdLE->setFont(font);
        pwdLE->setEchoMode(QLineEdit::Password);
        rememberPwdCB = new QCheckBox(loginWidget);
        rememberPwdCB->setObjectName(QStringLiteral("rememberPwdCB"));
        rememberPwdCB->setGeometry(QRect(40, 240, 90, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        font1.setUnderline(true);
        rememberPwdCB->setFont(font1);
        rememberPwdCB->setIconSize(QSize(20, 20));
        forgetPwdBtn = new QPushButton(loginWidget);
        forgetPwdBtn->setObjectName(QStringLiteral("forgetPwdBtn"));
        forgetPwdBtn->setGeometry(QRect(260, 240, 90, 30));
        forgetPwdBtn->setFont(font1);
        forgetPwdBtn->setFlat(true);
        loginBtn = new QPushButton(loginWidget);
        loginBtn->setObjectName(QStringLiteral("loginBtn"));
        loginBtn->setGeometry(QRect(90, 390, 100, 40));
        loginBtn->setFont(font);
        registBtn = new QPushButton(loginWidget);
        registBtn->setObjectName(QStringLiteral("registBtn"));
        registBtn->setGeometry(QRect(230, 390, 100, 40));
        registBtn->setFont(font);

        gridLayout->addWidget(loginWidget, 2, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 1, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 2, 1, 2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 2, 1);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 1);
        gridLayout->setColumnStretch(2, 2);

        retranslateUi(loginDialog);

        QMetaObject::connectSlotsByName(loginDialog);
    } // setupUi

    void retranslateUi(QDialog *loginDialog)
    {
        loginDialog->setWindowTitle(QApplication::translate("loginDialog", "\347\231\273\345\275\225", Q_NULLPTR));
        minBtn->setText(QApplication::translate("loginDialog", "min", Q_NULLPTR));
        closeBtn->setText(QApplication::translate("loginDialog", "close", Q_NULLPTR));
        userLab->setText(QApplication::translate("loginDialog", "user", Q_NULLPTR));
        label->setText(QApplication::translate("loginDialog", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        userLab_2->setText(QApplication::translate("loginDialog", "pwd", Q_NULLPTR));
        pwdLab->setText(QApplication::translate("loginDialog", "\345\257\206   \347\240\201", Q_NULLPTR));
        rememberPwdCB->setText(QApplication::translate("loginDialog", "\350\256\260\344\275\217\345\257\206\347\240\201", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        rememberPwdCB->setShortcut(QString());
#endif // QT_NO_SHORTCUT
        forgetPwdBtn->setText(QApplication::translate("loginDialog", "\345\277\230\350\256\260\345\257\206\347\240\201?", Q_NULLPTR));
        loginBtn->setText(QApplication::translate("loginDialog", "\347\231\273\345\275\225", Q_NULLPTR));
        registBtn->setText(QApplication::translate("loginDialog", "\346\263\250\345\206\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class loginDialog: public Ui_loginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
