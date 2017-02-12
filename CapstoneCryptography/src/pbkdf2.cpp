#include <headers/pbkdf2.h>
#include <iostream>

Pbkdf2::Pbkdf2(CryptoPP::HashTransformation* h):Hash(h){
    name = "PBKDF2";
}

void Pbkdf2::compute() {

    unsigned int iterations = 20000;
    CryptoPP::PKCS5_PBKDF2_HMAC<CryptoPP::SHA1> pbkdf2;

    int passlen = plaintext.size();
    int slen = salt.size();

    byte password[passlen];
    for(int i = 0; i < passlen; i++) {
        password[i] = plaintext.data()[i];
    }

    byte saltBuf[slen];
    for(int i = 0; i < slen; i++) {
        saltBuf[i] = salt.data()[i];
    }

    byte derived[20];

    pbkdf2.DeriveKey(derived, sizeof(derived), 0, password, passlen, saltBuf, slen, iterations);

    std::string result;
    CryptoPP::HexEncoder encoder(new CryptoPP::StringSink(result));

    encoder.Put(derived, sizeof(derived));
    encoder.MessageEnd();
    digest = result;
}
