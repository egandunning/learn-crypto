#ifndef __PRIMEFACTORIZATION_H_INCLUDED__
#define __PRIMEFACTORIZATION_H_INCLUDED__

<<<<<<< HEAD
#include <gmp.h>
#include "generateprimes.h"
=======
#include <gmpxx.h>
#include <gmp.h>
#include <iostream>
>>>>>>> b9bb9acacffe51dc972eed67d44f09aad18960be

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
