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
    std::string plaintext;
    std::string digest;
    void setDigest(QString);
    QString getDigest();
    QString getPlaintext();
    Hash* hashType; //needs to be pointer for inheritance to work?
};

#endif // CRACK_H

