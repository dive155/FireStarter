#-------------------------------------------------
#
# Project created by QtCreator 2016-03-25T21:41:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FireStarter
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    roomclass.cpp \
    fireextclass.cpp \
    trespasclass.cpp

HEADERS  += mainwindow.h \
    roomclass.h \
    fireextclass.h \
    trespasclass.h

FORMS    += mainwindow.ui

RESOURCES += \
    pictures.qrc
