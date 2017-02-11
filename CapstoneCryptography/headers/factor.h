#ifndef __FACTOR_H_INCLUDED__
#define __FACTOR_H_INCLUDED__

#include <headers/generateprimes.h>
#include <QPointF>
#include <QElapsedTimer>
#include <gmpxx.h>
#include <iostream>

class Factor {

private:
   /* QPointF* bruteForceFactor(mpz_class);
    QPointF* bruteForceFactor2(mpz_class);
    QPointF* quadraticSieveFactor(mpz_class);*/

public:
    Factor(){}
    ~Factor(){}
    //enum algorithmTypes {bruteForce=0, bruteForce2=1, quadraticSieve=2} alg;
    //int algorithm;
    virtual QPointF factor(mpz_class){}
	mpz_class p1;
	mpz_class p2;
};

#endif
