#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H

#include <headers/crack.h>

class BruteForceCrack : public Crack {

public:
    BruteForceCrack(Hash);
    int reverse();
    int reverse(int);
    void setMin(int);
    void setMax(int);
    int charRangeMin = 33;
    int charRangeMax = 122;
};

#endif // BRUTEFORCE_H

