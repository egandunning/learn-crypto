#ifndef MD5_H
#define MD5_H
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1

#include <headers/hash.h>
#include <cryptopp/md5.h>

class Md5 : public Hash
{
public:
    Md5(CryptoPP::HashTransformation* h = new CryptoPP::Weak::MD5);
};

#endif // MD5_H
