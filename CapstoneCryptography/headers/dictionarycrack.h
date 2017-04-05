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
    virtual void setOptions(unsigned int words, unsigned int endDigits, unsigned int preDigits, bool symb, bool cap, bool complete) override;

    unsigned int numWords = 1;
    unsigned int appendedDigits = 0;
    unsigned int prependedDigits = 0;
    bool symbols = false;
    bool capWords = false;
    bool completeMode = false;

private:
    std::string filename;
    std::vector<std::string> words;
    std::vector<std::vector<std::string>::iterator> wordIndex;
    std::pair<char,char> symbolConversion[10];
    unsigned int symbolArraySize;
    unsigned int verifyGuess();
    std::string getWordCombo(mpz_class);
    std::string getNextWord();
};

#endif // DICTIONARYCRACK_H

