#ifndef SHA512_H
#define SHA512_H

#include <headers/hash.h>
#include <cryptopp/sha.h>

class Sha512 : public Hash {

public:
    Sha512(CryptoPP::HashTransformation* = new CryptoPP::SHA512);
    //void compute();
};

#endif // SHA512_H

