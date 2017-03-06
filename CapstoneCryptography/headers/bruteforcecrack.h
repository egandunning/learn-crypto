#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H

#include <headers/crack.h>

#include <math.h>
#include <gmpxx.h>

#include <QElapsedTimer>

/**
 * Class to crack hashes via brute force. The list of possible characters
 * can be given as a range of ascii values or as a string.
 */
class BruteForceCrack : public Crack {

public:    
    BruteForceCrack(Hash*, std::string, int);
    std::string baseTenToBaseN(unsigned long, unsigned int);
    virtual QPointF reverse() override;
    void setOptions(unsigned int words, unsigned int endDigits, unsigned int preDigits, unsigned int symb, unsigned int cap) override;
    void setMin(int);
    void setMax(int);
    void setAlphabet(std::string);
    void addToAlphabet(std::string);
    void createAlphabet(int, int);

    std::string alphabet;
    int charCount;
};

#endif // BRUTEFORCE_H

