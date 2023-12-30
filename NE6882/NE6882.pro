#-------------------------------------------------
#
# Project created by QtCreator 2023-10-10T14:05:28
#
#-------------------------------------------------

QT       += core gui serialport winextras

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

#TARGET = NE6882
#TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

RC_FILE = logo.rc

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    login/logindialog.cpp \
    test/testdialog.cpp \
    setting/settingdialog.cpp \
    report/reportdialog.cpp \
    program/programdialog.cpp \
    jsonoperation/jsonoperation.cpp \
    test/testthread.cpp \
    warningdialog.cpp

HEADERS += \
    mainwindow.h \
    login/logindialog.h \
    test/testdialog.h \
    setting/settingdialog.h \
    report/reportdialog.h \
    common.h \
    program/programdialog.h \
    jsonoperation/jsonoperation.h \
    test/testthread.h \
    warningdialog.h

FORMS += \
        mainwindow.ui \
    login/logindialog.ui \
    test/testdialog.ui \
    setting/settingdialog.ui \
    report/reportdialog.ui \
    program/programdialog.ui \
    warningdialog.ui


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../NE6882communication/ne6882serial/release/ -lne6882serial
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../NE6882communication/ne6882serial/debug/ -lne6882serial
else:unix:!macx: LIBS += -L$$PWD/../NE6882communication/ne6882serial/ -lne6882serial

INCLUDEPATH += $$PWD/../NE6882communication/ne6882serial
DEPENDPATH += $$PWD/../NE6882communication/ne6882serial

DISTFILES += \
    icon/mian/NO PASS-STAMP.png \
    icon/mian/NO PASS-STAMP.png

RESOURCES += \
    res.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
