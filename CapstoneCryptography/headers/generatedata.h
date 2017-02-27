#ifndef GENERATEDATA_H
#define GENERATEDATA_H

#include <vector>
#include <iostream>
#include <functional>

#include <QPointF>
#include <gmpxx.h>

#include <headers/generateprimes.h>

template <class T>
class GenerateData {
public:

    static std::vector<mpz_class> composites(int startDigits, int count);

    static QPointF factor(std::vector<mpz_class>);
    static QPointF crack(std::vector<mpz_class>);
};

#endif
