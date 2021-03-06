#ifndef CRACK_H
#define CRACK_H

#include <headers/hash.h>

#include <string>
#include <iostream>

#include <QString>
#include <QPointF>

class Crack {

public:
    Crack();
    Crack(const Crack&);
    Crack& operator=(const Crack&);
    virtual ~Crack();
    void stop();
    virtual QPointF reverse();
    virtual void setOptions(unsigned int words=1, unsigned int endDigits=0, unsigned int preDigits=0, bool symb=0, bool cap=false, bool complete=false);
    std::string plaintext;
    std::string digest;
    std::string DIGEST;
    void setDigest(QString);
    QString getDigest();
    QString getPlaintext();
    Hash* hashType;
    unsigned int threadCount;
    bool kill = false;
    QString name;
};

#endif // CRACK_H

