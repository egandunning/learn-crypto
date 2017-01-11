#ifndef CRACK_H
#define CRACK_H

#include <headers/hash.h>
#include <string>
#include <QString>

class Crack {

public:
    Crack(Hash);
    Crack(){}
    int reverse();
    std::string plaintext;
    std::string digest;
    void setDigest(QString);
    QString getDigest();
    QString getPlaintext();
    Hash hashType;
};

#endif // CRACK_H

