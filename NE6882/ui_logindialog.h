/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
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
            loginDialog->setObjectName(QString::fromUtf8("loginDialog"));
        loginDialog->resize(1280, 720);
        loginDialog->setMinimumSize(QSize(1280, 720));
        loginDialog->setStyleSheet(QString::fromUtf8("#loginDialog{\n"
"border-image: url(:/icon/loginbg.png);\n"
"}"));
        gridLayout = new QGridLayout(loginDialog);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 3, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        taskWidget = new QWidget(loginDialog);
        taskWidget->setObjectName(QString::fromUtf8("taskWidget"));
        taskWidget->setMinimumSize(QSize(120, 40));
        taskWidget->setMaximumSize(QSize(120, 40));
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
        minBtn->setGeometry(QRect(0, 0, 40, 40));
        minBtn->setFocusPolicy(Qt::NoFocus);
        minBtn->setIconSize(QSize(70, 70));
        minBtn->setFlat(true);
        closeBtn = new QPushButton(taskWidget);
        closeBtn->setObjectName(QString::fromUtf8("closeBtn"));
        closeBtn->setGeometry(QRect(60, 0, 40, 40));
        closeBtn->setFocusPolicy(Qt::NoFocus);
        closeBtn->setIconSize(QSize(30, 30));
        closeBtn->setFlat(true);

        gridLayout->addWidget(taskWidget, 0, 3, 1, 1);

        loginWidget = new QWidget(loginDialog);
        loginWidget->setObjectName(QString::fromUtf8("loginWidget"));
        loginWidget->setMinimumSize(QSize(400, 480));
        loginWidget->setMaximumSize(QSize(400, 550));
        loginWidget->setStyleSheet(QString::fromUtf8("#loginWidget{\n"
"background-color: rgba(255, 255, 255, 255);\n"
"border-radius: 30px;\n"
"}\n"
"QLabel{\n"
"color:#0E55A7;\n"
"}\n"
"QLineEdit{\n"
"color:#0E55A7;\n"
"}"));
        userLab = new QLabel(loginWidget);
        userLab->setObjectName(QString::fromUtf8("userLab"));
        userLab->setGeometry(QRect(20, 95, 40, 40));
        userLab->setStyleSheet(QString::fromUtf8("border-image: url(:/icon/userl.png);"));
        userLE = new QLineEdit(loginWidget);
        userLE->setObjectName(QString::fromUtf8("userLE"));
        userLE->setGeometry(QRect(70, 90, 280, 50));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(16);
        userLE->setFont(font);
        userLE->setStyleSheet(QString::fromUtf8("border-image: url(:/icon/userlel.png);\n"
"padding-left:15px;"));
        userLE->setMaxLength(20);
        label = new QLabel(loginWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 70, 80, 30));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255, 255);"));
        label->setAlignment(Qt::AlignCenter);
        userLab_2 = new QLabel(loginWidget);
        userLab_2->setObjectName(QString::fromUtf8("userLab_2"));
        userLab_2->setGeometry(QRect(20, 185, 40, 40));
        userLab_2->setStyleSheet(QString::fromUtf8("border-image: url(:/icon/waringl.png);"));
        pwdLab = new QLabel(loginWidget);
        pwdLab->setObjectName(QString::fromUtf8("pwdLab"));
        pwdLab->setGeometry(QRect(80, 160, 80, 30));
        pwdLab->setFont(font);
        pwdLab->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 255);"));
        pwdLab->setAlignment(Qt::AlignCenter);
        pwdLE = new QLineEdit(loginWidget);
        pwdLE->setObjectName(QString::fromUtf8("pwdLE"));
        pwdLE->setGeometry(QRect(70, 180, 280, 50));
        pwdLE->setFont(font);
        pwdLE->setStyleSheet(QString::fromUtf8("padding-left:15px;\n"
"border-image: url(:/icon/userlel.png);"));
        pwdLE->setMaxLength(16);
        pwdLE->setEchoMode(QLineEdit::Password);
        rememberPwdCB = new QCheckBox(loginWidget);
        rememberPwdCB->setObjectName(QString::fromUtf8("rememberPwdCB"));
        rememberPwdCB->setGeometry(QRect(80, 280, 90, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        font1.setUnderline(true);
        rememberPwdCB->setFont(font1);
        rememberPwdCB->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"color:#0E55A7;\n"
"}\n"
"QCheckBox::indicator{\n"
"width: 20px;\n"
"height: 20px;\n"
"}\n"
"QCheckBox::indicator:checked {\n"
"border-image: url(:/icon/checks.png);\n"
"}\n"
"QCheckBox::indicator:unchecked {\n"
"border-image: url(:/icon/check1s.png);\n"
"}"));
        rememberPwdCB->setIconSize(QSize(20, 20));
        forgetPwdBtn = new QPushButton(loginWidget);
        forgetPwdBtn->setObjectName(QString::fromUtf8("forgetPwdBtn"));
        forgetPwdBtn->setGeometry(QRect(260, 280, 90, 30));
        forgetPwdBtn->setFont(font1);
        forgetPwdBtn->setStyleSheet(QString::fromUtf8("color:#0E55A7;"));
        forgetPwdBtn->setFlat(true);
        loginBtn = new QPushButton(loginWidget);
        loginBtn->setObjectName(QString::fromUtf8("loginBtn"));
        loginBtn->setGeometry(QRect(70, 390, 280, 40));
        loginBtn->setFont(font);
        loginBtn->setStyleSheet(QString::fromUtf8("#loginBtn{\n"
"border-radius: 10px;\n"
"color: #FFFFFF;\n"
"background-color:#0E55A7;\n"
"}\n"
"#loginBtn:hover{\n"
"color: #0E55A7;\n"
"background-color: rgba(210, 210, 210, 200);\n"
"}"));
        loginBtn->setFlat(false);
        registBtn = new QPushButton(loginWidget);
        registBtn->setObjectName(QString::fromUtf8("registBtn"));
        registBtn->setGeometry(QRect(130, 430, 140, 40));
        registBtn->setFont(font);
        registBtn->setStyleSheet(QString::fromUtf8("#registBtn{\n"
"border-radius: 10px;\n"
"color: #FFFFFF;\n"
"background-color: rgba(195, 195, 195, 200);\n"
"}\n"
"#registBtn:hover{\n"
"color: #161616;\n"
"background-color: rgb(255, 255, 255);\n"
"}"));
        userLab->raise();
        userLE->raise();
        label->raise();
        userLab_2->raise();
        pwdLE->raise();
        rememberPwdCB->raise();
        forgetPwdBtn->raise();
        loginBtn->raise();
        registBtn->raise();
        pwdLab->raise();

        gridLayout->addWidget(loginWidget, 2, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 1, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 2, 1, 2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 2, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 1);
        gridLayout->setRowStretch(2, 1);
        gridLayout->setRowStretch(3, 1);
        gridLayout->setColumnStretch(0, 7);
        gridLayout->setColumnStretch(1, 3);
        gridLayout->setColumnStretch(2, 1);
        gridLayout->setColumnStretch(3, 1);

        retranslateUi(loginDialog);

        QMetaObject::connectSlotsByName(loginDialog);
    } // setupUi

    void retranslateUi(QDialog *loginDialog)
    {
        loginDialog->setWindowTitle(QCoreApplication::translate("loginDialog", "\347\231\273\345\275\225", nullptr));
        minBtn->setText(QString());
        closeBtn->setText(QString());
        userLab->setText(QString());
        label->setText(QCoreApplication::translate("loginDialog", "\347\224\250\346\210\267\345\220\215", nullptr));
        userLab_2->setText(QString());
        pwdLab->setText(QCoreApplication::translate("loginDialog", "\345\257\206   \347\240\201", nullptr));
        rememberPwdCB->setText(QCoreApplication::translate("loginDialog", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
#if QT_CONFIG(shortcut)
        rememberPwdCB->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        forgetPwdBtn->setText(QCoreApplication::translate("loginDialog", "\345\277\230\350\256\260\345\257\206\347\240\201?", nullptr));
        loginBtn->setText(QCoreApplication::translate("loginDialog", "\347\231\273\345\275\225", nullptr));
        registBtn->setText(QCoreApplication::translate("loginDialog", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loginDialog: public Ui_loginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
