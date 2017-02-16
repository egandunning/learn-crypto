#-------------------------------------------------
#
# Project created by QtCreator 2016-11-06T19:17:37
#
#-------------------------------------------------

QT       += core gui\
        testlib

CONFIG   += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CapstoneCryptography
TEMPLATE = app


SOURCES += src/main.cpp\
       	src/mainwindow.cpp\
        src/generateprimes.cpp\
        src/console.cpp \
        src/hash.cpp \
        src/cryptogame.cpp \
        src/sha512.cpp \
        src/md5.cpp \
        src/pbkdf2.cpp \
    src/crack.cpp \
    src/bruteforcecrack.cpp \
    src/dictionarycrack.cpp \
    src/factor.cpp \
    src/bruteforcefactor.cpp \
<<<<<<< HEAD
    src/cipher.cpp \
=======
<<<<<<< HEAD
    src/buttonarray.cpp
=======
>>>>>>> 4074187ab21eba056c2062131c966ee5fd8242ba
    src/graphing.cpp
>>>>>>> 2925be4e6679e3a8b6f3fb7107bd050292c41522

HEADERS  += headers/mainwindow.h\
        headers/generateprimes.h\
        headers/hash.h \
        headers/cryptogame.h \
        headers/sha512.h \
        headers/md5.h \
        headers/pbkdf2.h \
        headers/crack.h \
    headers/bruteforcecrack.h \
    headers/dictionarycrack.h \
    headers/bruteforcefactor.h \
    headers/factor.h \
<<<<<<< HEAD
    headers/cipher.h
=======
<<<<<<< HEAD
    src/buttonarray.h
=======
>>>>>>> 4074187ab21eba056c2062131c966ee5fd8242ba
    headers/graphing.h
>>>>>>> 2925be4e6679e3a8b6f3fb7107bd050292c41522

unix:{  LIBS	 += -L/usr/local/lib \
                    -lgmp \
                    -lgmpxx \
                    -lcryptopp

}


INCLUDEPATH += "/usr/local/include/" \
FORMS    += forms/mainwindow.ui
macx:{
 INCLUDEPATH += "gmp/include"
 LIBS += -L../CapstoneCryptography/gmp/lib -lgmp -lgmpxx
}

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
RESOURCES += \
    resources.qrc

macx: LIBS += -L$$PWD/../../../../../../usr/local/lib/ -lgmp

INCLUDEPATH += $$PWD/../../../../../../usr/local/include
DEPENDPATH += $$PWD/../../../../../../usr/local/include

macx: PRE_TARGETDEPS += $$PWD/../../../../../../usr/local/lib/libgmp.a

FORMS += \
    forms/mainwindow.ui
