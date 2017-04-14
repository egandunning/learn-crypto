#ifndef HASH_H
#define HASH_H

/*
 * Wrapper class to streamline hash digest computing.
 */

#include <QString>
#include <string>
#include <iostream>
#include <cryptopp/hex.h>
#include <cryptopp/filters.h>
#include <cryptopp/osrng.h>
#include <cryptopp/des.h>

class Hash {

public:

    int saltlen;
    std::string salt;
    std::string plaintext;
    std::string digest;
    std::string name;
    CryptoPP::HashTransformation* hashType;

    Hash(CryptoPP::HashTransformation*);
    Hash();
    Hash(const Hash& h);
    Hash& operator=(const Hash& h);
    virtual ~Hash();
    virtual void compute();

    void generateSalt(int);
    void setPlaintext(QString);
    void setSalt(QString);
    QString getPlaintext();
    QString getDigest();
    QString getSalt();

private:

};
#endif
