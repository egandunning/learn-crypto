#include "headers/primefactorization.h"

PrimeFactorization::PrimeFactorization() {
	
}

long* PrimeFactorization::bruteForceFactor(long composite) {
	
	GeneratePrimes gp = GeneratePrimes(composite/2 + 100);
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
	}
}

long* PrimeFactorization::numberFieldSieve(long composite) {
	
}
