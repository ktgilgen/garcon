#-------------------------------------------------
#
# Project created by QtCreator 2012-10-16T09:39:11
#
#-------------------------------------------------

QT       += core gui

TARGET = VRMenu
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ../../garcon/src/AppInfo.cpp \
    ../../garcon/src/AppManager.cpp \
    editApp.cpp \
    dialog.cpp \
    controls.cpp

HEADERS  += mainwindow.h \
    ../../garcon/src/AppInfo.h \
    ../../garcon/src/AppManager.h \
    editApp.h \
    dialog.h \
    controls.h

FORMS    += mainwindow.ui \
    editApp.ui \
    dialog.ui \
    controls.ui

QMAKE_CXXFLAGS += -std=c++0x
