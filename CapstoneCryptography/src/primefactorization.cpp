#include "headers/primefactorization.h"

PrimeFactorization::PrimeFactorization() {
	
}

bool PrimeFactorization::bruteForceFactor(mpz_class composite) {
	mpz_class i, upperBound;
	upperBound = (composite + 1) / 2;
	
	for(i = 2; i < upperBound; i++ ) {
		if(composite % i == 0) {
			p1 = i;
			p2 = composite / i;
			return 1;
		}
	}
	return 0;
	
 /*   GeneratePrimes gp = GeneratePrimes(composite/2 + 100);
	gp.generate();
	
	long bound = gp.getPrimes().size();
	
	for(long i = 0; i < bound; i++) {
		for(long j = 0; j < bound; j++) {
			
			if(i * j == composite) {
				factors[0] = i;
				factors[1] = j;
				return factors;
			}
		}
    }*/
}

/*bool PrimeFactorization::numberFieldSieve(mpz_class composite) {
	return 0;
}*/

