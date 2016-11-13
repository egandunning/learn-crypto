#-------------------------------------------------
#
# Project created by QtCreator 2016-11-06T19:17:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CapstoneCryptography
TEMPLATE = app


SOURCES += src/main.cpp\
       	src/mainwindow.cpp\
		src/generateprimes.cpp\
		src/primefactorization.cpp\
        src/Cipher.cpp\
        src/console.cpp

HEADERS  += headers/mainwindow.h\
		headers/generateprimes.h\
		headers/primefactorization.h\
        headers/Cipher.h

FORMS    += forms/mainwindow.ui

RESOURCES += \
    resources.qrc
