#ifndef DICTIONARYCRACK_H
#define DICTIONARYCRACK_H

#include <iostream>
#include <fstream>
#include <string>
#include <headers/hash.h>

class DictionaryCrack {
public:
    DictionaryCrack(Hash h, std::string);
    int reverse();

    Hash hashType;
    std::string digest;
    std::string plaintext;
private:
    std::string filename;
};

#endif // DICTIONARYCRACK_H

