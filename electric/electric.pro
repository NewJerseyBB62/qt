#-------------------------------------------------
#
# Project created by QtCreator 2024-03-01T11:31:16
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = electric
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    setting/settingdialog.cpp \
    database/datadialog.cpp \
    errordialog.cpp \
    database/dboperation.cpp

HEADERS += \
        mainwindow.h \
    setting/settingdialog.h \
    database/datadialog.h \
    errordialog.h \
    database/dboperation.h

FORMS += \
        mainwindow.ui \
    setting/settingdialog.ui \
    database/datadialog.ui \
    errordialog.ui

CONFIG+=resources_big

RESOURCES += \
    rec.qrc
