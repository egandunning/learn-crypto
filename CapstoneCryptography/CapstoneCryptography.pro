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
        src/console.cpp \
        src/cryptogame.cpp

HEADERS  += headers/mainwindow.h\
		headers/generateprimes.h\
		headers/primefactorization.h\
        headers/Cipher.h \
        headers/cryptogame.h

unix:{LIBS	 += -L/usr/local/lib \
			-lgmp
			-lgmpxx}


FORMS    += forms/mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../Desktop/crypto/Win32/Output/release/ -lcryptlib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../Desktop/crypto/Win32/Output/debug/ -lcryptlib

INCLUDEPATH += $$PWD/../../../Desktop/crypto
DEPENDPATH += $$PWD/../../../Desktop/crypto

RESOURCES += \
    resources.qrc
