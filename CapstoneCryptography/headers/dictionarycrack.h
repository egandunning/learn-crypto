#ifndef DICTIONARYCRACK_H
#define DICTIONARYCRACK_H

#include <headers/crack.h>
#include <fstream>

class DictionaryCrack : public Crack {
public:
    DictionaryCrack(Hash h, std::string);
    virtual int reverse() override;

    /*Hash hashType;
    std::string digest;
    std::string plaintext;*/
private:
    std::string filename;
};

#endif // DICTIONARYCRACK_H

