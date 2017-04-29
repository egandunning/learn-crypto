#ifndef GENERATEDATA_H
#define GENERATEDATA_H

#include <vector>
#include <iostream>

#include <QPointF>
#include <gmpxx.h>

#include <headers/generateprimes.h>
#include <headers/factor.h>
#include <headers/crack.h>
#include <headers/hash.h>

class GenerateData : public QObject {

    Q_OBJECT

public:

    GenerateData(){}

    std::vector<QPointF> factorMember(std::vector<mpz_class>, Factor*);
    std::vector<QPointF> crackMember(std::vector<std::string>, Crack*);

    static std::vector<mpz_class> composites(unsigned int, unsigned int);
    static std::vector<std::string> plaintexts(unsigned int, unsigned int);
    static std::vector<std::string> getHashes(std::vector<std::string>, Hash*);

    static std::vector<QPointF> factor(std::vector<mpz_class>, Factor*);
    static std::vector<QPointF> crack(std::vector<std::string>, Crack*);

signals:
    void point(int);

};

#endif
