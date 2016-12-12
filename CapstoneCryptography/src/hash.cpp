#include <headers/hash.h>

Hash::Hash(CryptoPP::HashTransformation* h){
    this->hashType = h;
    plaintext = "";
    digest = "";
    saltlen = 0;
    salt = "";
}

void Hash::compute() {
    digest = "";
    using CryptoPP::StringSource;
    using CryptoPP::HashFilter;
    using CryptoPP::HexEncoder;
    using CryptoPP::StringSink;
    StringSource(salt + plaintext, true, new HashFilter(*hashType, new HexEncoder(new StringSink(digest))));
}

void Hash::generateSalt(int len) {

    unsigned char* buf = new unsigned char[len+1];

    CryptoPP::AutoSeededX917RNG<CryptoPP::DES> securePrg;
    securePrg.GenerateBlock(buf, len);
    buf[len] = '\0';
    salt = std::string((char*)buf);
}
