#ifndef __PRIMEFACTORIZATION_H_INCLUDED__
#define __PRIMEFACTORIZATION_H_INCLUDED__

#include <headers/generateprimes.h>
#include <QPointF>
#include <QElapsedTimer>
#include <gmpxx.h>
#include <iostream>

class PrimeFactorization {

private:
    QPointF* bruteForceFactor(mpz_class);
    QPointF* bruteForceFactor2(mpz_class);
    QPointF* quadraticSieveFactor(mpz_class);

public:
    PrimeFactorization(int);
    enum algorithmTypes {bruteForce=0, bruteForce2=1, quadraticSieve=2} alg;
    int algorithm;
    QPointF* factor(mpz_class);
	mpz_class p1;
	mpz_class p2;
};

#endif
