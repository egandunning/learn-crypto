#ifndef __FACTOR_H_INCLUDED__
#define __FACTOR_H_INCLUDED__

#include <headers/generateprimes.h>

#include <QPointF>
#include <QElapsedTimer>
#include <QObject>
#include <gmpxx.h>
#include <iostream>

class Factor : public QObject {

public:
    Factor();
    virtual ~Factor(){}
    virtual QPointF factor(mpz_class);
    void stop();
    bool kill = false;
	mpz_class p1;
    mpz_class p2;
    unsigned int threadCount;
    mpz_class getPrime1();
    mpz_class getPrime2();
};

#endif
