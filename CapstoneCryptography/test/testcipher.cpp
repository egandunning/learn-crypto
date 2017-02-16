
#include <QtTest/QtTest>
#include <headers/cipher.h>




class TestCipher: public QObject
{
    Q_OBJECT
private slots:
    void findLetters();
};


void TestCipher::findLetters(){
    QString yo = "Yo";
    QVERIFY(yo.toUpper() == "YO");
}


QTEST_MAIN(TestCipher)
#include "testcipher.moc"
