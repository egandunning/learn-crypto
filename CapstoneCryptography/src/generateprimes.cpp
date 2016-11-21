//implementation of the Sieve of Eratosthenes - more info at 
//https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

#include "headers/generateprimes.h"


GeneratePrimes::GeneratePrimes() {
	srand(time(NULL));
}

GeneratePrimes::GeneratePrimes(long floor, long ceiling) {
	
	primes = new vector<long>();
	lowerBound = floor;
	upperBound = ceiling;
	
	srand(time(NULL));
	composites = new bool[upperBound]; //keeps track of composite numbers. If i is prime, 
	memset(composites, 0, sizeof(*composites)); 		//then composites[i]=false
	composites[0] = 1;
	composites[1] = 1;
}

GeneratePrimes::~GeneratePrimes() {
	
}

bool GeneratePrimes::writePrimes(char* filename) {

	try {
		ofstream fp;
		fp.open(filename);
		
		for(int i = lowerBound; i < primes->size(); i++) {

			fp << primes->at(i) << '\n';
		}
		
		fp.close();
		return 0;
	} catch (int e) {
		cerr << "File io execption occurred: " << e << endl;
	}
	return 1;
}

long GeneratePrimes::readRandomPrime(char* filename) {
	try {
		
		ifstream fp;
		fp.open(filename);
		string line;
		vector<long> lines;
		
		while(getline(fp, line)) {
			lines.push_back(atol(line.c_str()));
		}
		
		int index = rand() % lines.size();
		return lines.at(index);
		
	} catch (int e) {
		cerr << "File io execption occurred: " << e << endl;
	}
	return 1;
}
			

void GeneratePrimes::generate() {
	
	long prime = 2;

	for(long i = 0; i < upperBound; i++) {
		
		if(!composites[i]) {

			primes->push_back(i);
		
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

long GeneratePrimes::randomPrime() {
	
	int index = rand() % primes->size();
	return primes->at(index);
}

void GeneratePrimes::printPrimes() {
	
	cout << "All prime numbers less than " << upperBound << endl;
	
	for(unsigned long i = 0; i < primes->size(); i++) {
		cout << primes->at(i) << " ";
	}
	cout << endl;
}
