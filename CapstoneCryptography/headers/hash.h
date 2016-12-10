#ifndef HASH_H
#define HASH_H

/*
 * Wrapper class to streamline hash digest computing.
 */

#include <QString>
#include <string>
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
    CryptoPP::HashTransformation* hashType;

    Hash(CryptoPP::HashTransformation*);
    void compute();

    void generateSalt(int);
    void setPlaintext(QString);
    QString getPlaintext();
    QString getDigest();

private:


};
#endif
