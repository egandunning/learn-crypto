#ifndef __GENERATEPRIMES_H_INCLUDED__
#define __GENERATEPRIMES_H_INCLUDED__


#include <vector>
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <time.h>

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
	vector<long>* primes;
	bool* composites;
	
public:
	GeneratePrimes();
	GeneratePrimes(long, long);
	~GeneratePrimes();
	bool writePrimes(char*);
	long readRandomPrime(char*);
	void generate();
	long randomPrime();
	void printPrimes();
	vector<long> getPrimes() { return *primes; }
};

#endif
