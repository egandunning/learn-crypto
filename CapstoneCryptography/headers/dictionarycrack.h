#ifndef DICTIONARYCRACK_H
#define DICTIONARYCRACK_H

#include <headers/crack.h>

#include <fstream>
#include <gmpxx.h>

#include <QElapsedTimer>

class DictionaryCrack : public Crack {
public:
    DictionaryCrack(Hash*, std::string);
    virtual QPointF reverse() override;
    virtual void setOptions(unsigned int words, unsigned int endDigits, unsigned int preDigits, unsigned int symb, unsigned int cap) override;

    unsigned int numWords = 1;
    unsigned int appendedDigits = 0;
    unsigned int prependedDigits = 0;
    unsigned int symbols = 0;
    unsigned int capCount = 0;

private:
    std::string filename;
    std::vector<std::string> words;
    unsigned int verifyGuess();
    std::string getWordCombo(mpz_class);
};

#endif // DICTIONARYCRACK_H

