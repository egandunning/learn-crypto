#-------------------------------------------------
#
# Project created by QtCreator 2016-10-09T23:56:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestGUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    +=

#added by Egan
unix:LIBS += -L/usr/local/lib -lcryptopp

#For windows:
#win32:LIBS += C:/path/to/library


