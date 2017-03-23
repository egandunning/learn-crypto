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
    virtual void setOptions(unsigned int words, unsigned int endDigits, unsigned int preDigits, unsigned int symb, bool cap) override;

    unsigned int numWords = 1;
    unsigned int appendedDigits = 0;
    unsigned int prependedDigits = 0;
    unsigned int symbols = 0;
    bool capWords = false;

private:
    std::string filename;
    std::vector<std::string> words;
    std::vector<std::vector<std::string>::iterator> wordIndex;
    unsigned int verifyGuess();
    std::string getWordCombo(mpz_class);
    std::string getNextWord();
};

#endif // DICTIONARYCRACK_H

