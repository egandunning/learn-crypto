#include <headers/pbkdf2.h>
#include <iostream>

Pbkdf2::Pbkdf2(CryptoPP::HashTransformation* h):Hash(h){}

void Pbkdf2::compute(unsigned int iterations = 20000) {

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

/*
    unsigned char bufOut[32]; //32 -> 256-bit output

    int len = plaintext.length();
    unsigned char bufIn[len];


    std::cout << "\t\t"<<sizeof(bufOut)<<std::endl;

    for(int i = 0; i < plaintext.length(); i++) {
        bufIn[i] = (unsigned char)plaintext.at(i);
    }


    std::cout << "\t\t"<<sizeof(bufIn)<<" "<<len<<" "<<plaintext<<" ";
    for(int i = 0; i < sizeof(bufIn); i++) {
        std::cout << bufIn[i];
    }

    std::cout << std::endl;

    const unsigned char* saltBuf = new unsigned char(saltlen);
    saltBuf = (unsigned char*)salt.c_str();

    pbkdf2.DeriveKey(bufOut, sizeof(bufOut), 0, bufIn, sizeof(bufIn), saltBuf, sizeof(saltBuf), iterations);

    //hex encoding
    digest = "";
    using CryptoPP::StringSource;
    using CryptoPP::StringSink;
    using CryptoPP::HexEncoder;
    StringSource ss(bufOut, sizeof(bufOut), true, new HexEncoder(new StringSink(digest)));
    std::cout << "\t\tIn pbkdf2::compute() digest:" << digest << std::endl;

    std::cout << "\t\t" << std::string((char*)bufOut);
    for(int i = 0; i < digest.length(); i++) {
        std::cout << (digest.at(i));
    }

    std::cout << std::endl<<"\t\t"<<sizeof(bufOut);
    std::cout << std::endl<<"\t\t";
    for(int i = 0; i < sizeof(bufOut); i++) {
        std::cout << (bufOut[i]);
    }
    std::cout << std::endl;
    */
}
