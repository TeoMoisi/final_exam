#-------------------------------------------------
#
# Project created by QtCreator 2018-06-18T14:15:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = examen-final
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


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    screenwriter.cpp \
    idea.cpp \
    repo.cpp \
    ctrl.cpp \
    tableview.cpp \
    exception.cpp \
    tester.cpp \
    gui.cpp

HEADERS += \
        mainwindow.h \
    screenwriter.h \
    idea.h \
    repo.h \
    ctrl.h \
    tableview.h \
    exception.h \
    tester.h \
    gui.h

FORMS += \
        mainwindow.ui \
    gui.ui

DISTFILES += \
    ideas.txt \
    writers.txt \
    saved.txt \
    sdeas.txt
