#ifndef CRACK_H
#define CRACK_H

#include <headers/hash.h>

#include <string>
#include <iostream>

#include <QString>
#include <QPointF>

class Crack {

public:
    Crack(){}
    virtual ~Crack();
    virtual QPointF reverse();
    virtual void setOptions(unsigned int words=1, unsigned int endDigits=0, unsigned int preDigits=0, unsigned int symb=0, unsigned int cap=0);
    std::string plaintext;
    std::string digest;
    void setDigest(QString);
    QString getDigest();
    QString getPlaintext();
    Hash* hashType; //needs to be pointer for inheritance to work?
};

#endif // CRACK_H

