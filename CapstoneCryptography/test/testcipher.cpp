
#include <QtTest/QtTest>
#include </home/onetrueq/learn-crypto/CapstoneCryptography/headers/cipher.h>




class TestCipher: public QObject
{
    Q_OBJECT
private slots:
    void basicFindLetters();
    void manualFindLetters();
};


/**
 * @brief TestCipher::basicFindLetters
 * This test examines 10000 random ciphers, and makes sure that each letter
 * in the map pertains to only one other letter.
 */
void TestCipher::basicFindLetters(){

    bool check = true;

    for(int i = 0; i<10000; i++){
        Cipher tc = Cipher();
        int count[26];

        for(int i = 0; i<26; i++){
            count[i] = 0;
        }

        for(int i = 0; i<26; i++){
            count[tc.getChar(i + 65) - 65] = count[tc.getChar(i + 65) - 65] + 1;
        }

        check = true;

        for(int i = 0; i<26; i++){
            if(count[i] > 1){
                check = false;
                break;
            }
        }
        QVERIFY(check);
    }
}


void TestCipher::manualFindLetters(){

    Cipher tc = Cipher("JOB","TEST");
    int count[26];

    for(int i = 0; i<26; i++){
        count[i] = 0;
    }

    for(int i = 0; i<26; i++){
        count[tc.getChar(i + 65) - 65] = count[tc.getChar(i + 65) - 65] + 1;
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
