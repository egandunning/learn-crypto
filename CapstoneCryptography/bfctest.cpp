
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




class BFCTest: public QObject
{
    Q_OBJECT
private slots:
    void stringIncrement();
    //void test();
};

void stringIncrement(){
    std::string test = "hello";

    BruteForceCrack* d = new BruteForceCrack(new Md5(), "abcd", 1, "a","aa");

    std::string check = d->incrementString(test);

    bool c = false;

    if(check.compare("hellp") == 0){
        c = true;
    }
    QVERIFY(c);

    test = "hellz";
    check = d->incrementString(test);

    if(check.compare("hellaa") == 0){
        c = true;
    }

    QVERIFY(c);
}
