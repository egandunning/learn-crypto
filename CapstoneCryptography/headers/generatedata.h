#ifndef GENERATEDATA_H
#define GENERATEDATA_H

#include <vector>
#include <iostream>
#include <functional>

#include <QPointF>
#include <gmpxx.h>

class GenerateData {
    static std::vector<QPointF> generate(std::function<QPointF(mpz_class)>, std::vector<mpz_class>);
};

#endif
