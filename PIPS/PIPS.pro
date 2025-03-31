#-------------------------------------------------
#
# Project created by QtCreator 2025-01-21T13:06:57
#
#-------------------------------------------------

QT       += core gui widgets sql serialbus

TARGET = PIPS
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    Data/dboperation.cpp \
    main.cpp \
    mainwindow.cpp \
    Data/jsonopration.cpp \
    function/generaldialog.cpp \
    function/generalsetdialog.cpp \
    function/stepladdersetdialog.cpp \
    function/stepsetdialog.cpp \
    function/gradientsetdialog.cpp \
    function/throughsetdialog.cpp \
#    function/harmonicssetdialog.cpp \
    function/systemsetdialog.cpp \
    Common/commontest.cpp \
    Common/rtc.cpp \
    Common/lockdialog.cpp \
    Common/lockmanager.cpp \
    communication/communication.cpp \
    communication/canprotocol.cpp \
    Data/logoperation.cpp \
    Common/keyboardform.cpp \
    Common/warninglight.cpp \
    Common/warningdialog.cpp \
    Common/physicalkey.cpp
#    mainbtnform.cpp

HEADERS += \
    Data/dboperation.h \
    mainwindow.h \
    Common/commontest.h \
    Data/jsonopration.h \
    function/generaldialog.h \
    function/generalsetdialog.h \
    function/stepladdersetdialog.h \
    function/stepsetdialog.h \
    function/gradientsetdialog.h \
    function/throughsetdialog.h \
#    function/harmonicssetdialog.h \
    function/systemsetdialog.h \
    Common/rtc.h \
    Common/lockdialog.h \
    Common/lockmanager.h \
    communication/communication.h \
    communication/canprotocol.h \
    Data/logoperation.h \
    Common/keyboardform.h \
    Common/warninglight.h \
    Common/warningdialog.h \
    Common/physicalkey.h
#    mainbtnform.h

FORMS += \
        mainwindow.ui \
    function/generaldialog.ui \
    function/generalsetdialog.ui \
    function/stepladdersetdialog.ui \
    function/stepsetdialog.ui \
    function/gradientsetdialog.ui \
    function/throughsetdialog.ui \
#    function/harmonicssetdialog.ui \
    function/systemsetdialog.ui \
    Common/lockdialog.ui \
    Common/keyboardform.ui \
    Common/warningdialog.ui
#    mainbtnform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res/res.qrc

