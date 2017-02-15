#ifndef __FACTOR_H_INCLUDED__
#define __FACTOR_H_INCLUDED__

#include <headers/generateprimes.h>
#include <QPointF>
#include <QElapsedTimer>
#include <gmpxx.h>
#include <iostream>

class Factor {

public:
    Factor(){}
    virtual ~Factor(){}
    virtual QPointF factor(mpz_class);
	mpz_class p1;
	mpz_class p2;
    mpz_class getPrime1();
    mpz_class getPrime2();
};

#endif
