#ifndef __GENERATEPRIMES_H_INCLUDED__
#define __GENERATEPRIMES_H_INCLUDED__


#include <vector>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>

using std::cout;
using std::endl;
using std::vector;

class GeneratePrimes {
	
private:
	int upperBound;
	vector<long> primes;
	bool* composites;
	
public:
	GeneratePrimes(long);
	void generate();
	long randomPrime();
	void printPrimes();
	vector<long> getPrimes() { return primes; }
};

#endif
