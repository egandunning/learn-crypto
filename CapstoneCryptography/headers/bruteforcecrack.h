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
    std::string incrementString(std::string in, std::string alpha);
    virtual QPointF reverse() override;
    void setOptions(unsigned int words, unsigned int endDigits, unsigned int preDigits, bool symb, bool cap, bool complete) override;
    void setMin(int);
    void setMax(int);
    void setAlphabet(std::string);
    void addToAlphabet(std::string);
    void createAlphabet(int, int);

    std::string alphabet;
    std::string begin;
    std::string end;
    int charCount;

    unsigned long n;

    static std::string incrementStringW(std::string);
    static void worker(std::string, std::string, Hash*, std::string);
};

#endif // BRUTEFORCE_H

