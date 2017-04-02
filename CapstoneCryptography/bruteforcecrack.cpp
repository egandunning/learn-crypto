

#include <QtTest/QtTest>
#include <string>
#include <headers/mainwindow.h>
#include <headers/generateprimes.h>
#include <headers/bruteforcefactor.h>
#include <headers/bruteforcecrack.h>
#include <headers/dictionarycrack.h>
#include <headers/sha512.h>
#include <headers/md5.h>
#include <headers/pbkdf2.h>




class BruteForceCrack: public QObject
{
    Q_OBJECT
private slots:
    void basicFindLetters();
    void manualFindLetters();
    //void test();
};
