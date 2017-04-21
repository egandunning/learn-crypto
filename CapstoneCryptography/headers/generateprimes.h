#ifndef __GENERATEPRIMES_H_INCLUDED__
#define __GENERATEPRIMES_H_INCLUDED__


#include <vector>
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <gmpxx.h>

using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::string;
using std::ofstream;
using std::ifstream;

class GeneratePrimes {
	
private:
	long upperBound;
	long lowerBound; //used for writing to file
    vector<long> primes;
    vector<bool> composites;
	
public:
	GeneratePrimes();
	GeneratePrimes(long, long);
	~GeneratePrimes();
	bool writePrimes(char*);
	long readRandomPrime(char*);
	void generate();
    std::vector<mpz_class> generate(mpz_class);
	long randomPrime();
    static mpz_class randomPrime(unsigned int numDigits);
	void printPrimes();
    vector<long> getPrimes() { return primes; }
};

#endif
