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
        headers/cryptogame.h \

unix:{  LIBS	 += -L/usr/local/lib \
			-lgmp
                        -lgmpxx}

INCLUDEPATH += "/usr/local/include/gmp.h"
FORMS    += forms/mainwindow.ui

#Under here is Windows stuff, don't touch!

win32:{

    win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../lib/crypto/Win32/Output/release/ -lcryptlib
    else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../lib/crypto/Win32/Output/debug/ -lcryptlib

    INCLUDEPATH += $$PWD/../../../../../../lib/crypto
    DEPENDPATH += $$PWD/../../../../../../lib/crypto

    win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../lib/gmp-6.1.1/.libs/ -lgmp
    else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../lib/gmp-6.1.1/.libs/ -lgmp

    INCLUDEPATH += $$PWD/../../../../../../lib/gmp-6.1.1
    DEPENDPATH += $$PWD/../../../../../../lib/gmp-6.1.1

    win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../lib/gmp-6.1.1/.libs/ -lgmpxx
    else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../lib/gmp-6.1.1/.libs/ -lgmpxx

    INCLUDEPATH += $$PWD/../../../../../../lib/gmp-6.1.1
    DEPENDPATH += $$PWD/../../../../../../lib/gmp-6.1.1

}
