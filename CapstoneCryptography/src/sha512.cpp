#include <headers/sha512.h>

Sha512::Sha512(CryptoPP::HashTransformation* h):Hash(h){
    name = "SHA 512";
}
