#ifndef GENERATEDATA_H
#define GENERATEDATA_H

#include <vector>
#include <iostream>

#include <QPointF>
#include <gmpxx.h>

#include <headers/generateprimes.h>
#include <headers/factor.h>
#include <headers/crack.h>

class GenerateData {
public:

    static std::vector<mpz_class> composites(int, int);

    static std::vector<QPointF> factor(std::vector<mpz_class>, Factor*);
    static std::vector<QPointF> crack(std::vector<mpz_class>, Crack*);
};

#endif
