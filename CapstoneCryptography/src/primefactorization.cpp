#include "headers/primefactorization.h"

PrimeFactorization::PrimeFactorization() {
	
}

long* PrimeFactorization::bruteForceFactor(long composite) {
	
	
	
	GeneratePrimes gp = GeneratePrimes(composite);
	gp.generate();
	
	int bound = gp.getPrimes().size();
	
	for(long i = 0; i < bound; i++) {
		for(long j = 0; j < bound; j++) {
			
			if(i * j == composite) {

				long factors [2] = {i, j};
				return factors;
			}
		}
	}
}
