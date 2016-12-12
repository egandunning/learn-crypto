#ifndef __PRIMEFACTORIZATION_H_INCLUDED__
#define __PRIMEFACTORIZATION_H_INCLUDED__

#include <headers/generateprimes.h>
#include <QPointF>
#include <QElapsedTimer>
#include <gmpxx.h>
#include <iostream>

class PrimeFactorization {
	
private:
	
public:
	PrimeFactorization();
    QPointF* bruteForceFactor(mpz_class);
    QPointF* bruteForceFactor2(mpz_class);
    QPointF* quadraticSieve(mpz_class);
	mpz_class p1;
	mpz_class p2;
};

#endif
