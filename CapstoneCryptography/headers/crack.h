#ifndef CRACK_H
#define CRACK_H

#include <headers/hash.h>
#include <string>
#include <QString>

class Crack {

public:
    Crack(Hash);
    Crack(){}
    virtual int reverse(int) = 0;
    std::string plaintext;
    std::string digest;
    void setDigest(QString);
    //void setAlphabet(std::string);
    QString getDigest();
    QString getPlaintext();
    Hash hashType;

    std::string alphabet;
};

#endif // CRACK_H

