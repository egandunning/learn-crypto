//implementation of the Sieve of Eratosthenes - more info at 
//https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

#include "headers/generateprimes.h"


GeneratePrimes::GeneratePrimes(long n) {
	upperBound = n;
	composites = new bool[n]; //keeps track of composite numbers. If i is prime, 
	memset(composites, 0, sizeof(composites)); 		//then composites[i]=false
	composites[0] = 1;
	composites[1] = 1;
}

void GeneratePrimes::generate() {
	
	long prime = 2;

	for(long i = 0; i < upperBound; i++) {
		
		if(!composites[i]) {

			primes.push_back(i);
		
			for(long j = 0; j < upperBound; j++) {
				long product = j * i; //find composite numbers
				if( product >= upperBound ) { //out of bounds
					break;
				}
				composites[j*i] = 1;
			}
		}
	}
}

void GeneratePrimes::printPrimes() {
	
	cout << "All prime numbers less than " << upperBound << endl;
	
	for(long i = 0; i < primes.size(); i++) {
		cout << primes[i] << " ";
	}
	cout << endl;
}
