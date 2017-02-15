#ifndef CRACK_H
#define CRACK_H

#include <headers/hash.h>
#include <string>
#include <QString>
#include <iostream>

class Crack {

public:
    Crack(){}
    virtual ~Crack();
    virtual int reverse();
    std::string plaintext;
    std::string digest;
    void setDigest(QString);
    QString getDigest();
    QString getPlaintext();
    Hash* hashType; //needs to be pointer for inheritance to work?
};

#endif // CRACK_H

