#include <headers/pbkdf2.h>

Pbkdf2::Pbkdf2(CryptoPP::HashTransformation* h):Hash(h){}

void Pbkdf2::compute(unsigned int iterations = 20000) {

    CryptoPP::PKCS5_PBKDF2_HMAC<CryptoPP::SHA1> pbkdf2;



    unsigned char* bufOut = new unsigned char(32); //256-bit output

    int len = plaintext.length();
    const unsigned char* bufIn = new unsigned char(len);

    bufIn = (unsigned char*)plaintext.c_str();

    const unsigned char* saltBuf = new unsigned char(saltlen);
    saltBuf = (unsigned char*)salt.c_str();

    pbkdf2.DeriveKey(bufOut, (size_t)32, (byte)0, bufIn, (size_t)len, saltBuf, (size_t)saltlen, iterations);

    digest = std::string((char*)bufOut);
}
