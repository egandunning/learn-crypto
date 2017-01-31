#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H

#include <headers/crack.h>
#include <math.h>
#include <vector>

/**
 * Class to crack hashes via brute force. The list of possible characters
 * can be given as a range of ascii values or as a string.
 */
class BruteForceCrack : public Crack {

public:    
    BruteForceCrack(Hash);
    int reverse();
    std::string baseTenToBaseN(unsigned int, unsigned int);
    int reverse(int);
    void setMin(int);
    void setMax(int);
    void setAlphabet(std::string);
    void addToAlphabet(std::string);
    void createAlphabet(int, int);

private:
    std::string alphabet;
};

#endif // BRUTEFORCE_H

