#ifndef __PRIMEFACTORIZATION_H_INCLUDED__
#define __PRIMEFACTORIZATION_H_INCLUDED__

#include <gmp.h>
#include "generateprimes.h"

class PrimeFactorization {
	
private:
	
public:
	PrimeFactorization();
	bool bruteForceFactor(mpz_class);
	bool numberFieldSieve(mpz_class);
	mpz_class p1;
	mpz_class p2;
};

#endif
