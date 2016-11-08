#ifndef __PRIMEFACTORIZATION_H_INCLUDED__
#define __PRIMEFACTORIZATION_H_INCLUDED__


#include "generateprimes.h"

class PrimeFactorization {
	
private:
	long factors[2] = {0,0};
	
public:
	PrimeFactorization();
	long* bruteForceFactor(long);
	
};

#endif
