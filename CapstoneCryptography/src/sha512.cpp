#include <headers/sha512.h>

Sha512::Sha512(CryptoPP::HashTransformation* h):Hash(h){}

/*void Sha512::compute() {
    using CryptoPP::StringSource;
    using CryptoPP::HashFilter;
    using CryptoPP::HexEncoder;
    using CryptoPP::StringSink;
    StringSource ss(plaintext, true, new HashFilter(*hashType, new HexEncoder(new StringSink(digest))));

}*/
