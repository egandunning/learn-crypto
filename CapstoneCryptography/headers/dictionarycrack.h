#ifndef DICTIONARYCRACK_H
#define DICTIONARYCRACK_H

#include <headers/crack.h>
#include <fstream>

class DictionaryCrack : public Crack {
public:
    DictionaryCrack(Hash h, std::string);
    virtual int reverse() override;

private:
    std::string filename;
};

#endif // DICTIONARYCRACK_H

