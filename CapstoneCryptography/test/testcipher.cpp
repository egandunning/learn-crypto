
#include <QtTest/QtTest>
#include </home/onetrueq/learn-crypto/CapstoneCryptography/headers/cipher.h>




class TestCipher: public QObject
{
    Q_OBJECT
private slots:
    void findLetters();
};


void TestCipher::findLetters(){

    Cipher tc = new Cipher();
    int[] count = new int[26];

    for(int i = 0; i<26; i++){
        count[i] = 0;
    }

    for(int i = 0; i<26; i++){
        count[tc.getChar(i) - 65] = count[tc.getChar(i) - 65] + 1;
    }

    bool check = true;

    for(int i = 0; i<26; i++){
        if(count[i] > 1){
            check = false;
            break;
        }
    }




    QVERIFY(check);

}


QTEST_MAIN(TestCipher)
#include "testcipher.moc"
