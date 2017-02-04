#ifndef PBKDF2_H
#define PBKDF2_H

#include <headers/hash.h>
#include <cryptopp/sha.h>
#include <cryptopp/pwdbased.h>

class Pbkdf2 : public Hash {
public:
    Pbkdf2(CryptoPP::HashTransformation* h = new CryptoPP::SHA1);

    virtual void compute() override;
};

#endif // PBKDF2_H

