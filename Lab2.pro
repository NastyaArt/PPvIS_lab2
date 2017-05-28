#-------------------------------------------------
#
# Project created by QtCreator 2017-04-04T08:05:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Lab2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    addwindow.cpp \
    delwindow.cpp \
    searchwindow.cpp \
    student.cpp \
    database.cpp

HEADERS  += mainwindow.h \
    addwindow.h \
    delwindow.h \
    searchwindow.h \
    student.h \
    database.h

FORMS    += mainwindow.ui
