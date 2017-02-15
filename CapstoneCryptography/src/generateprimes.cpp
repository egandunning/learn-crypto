//implementation of the Sieve of Eratosthenes - more info at 
//https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

#include "headers/generateprimes.h"


GeneratePrimes::GeneratePrimes() {
	srand(time(NULL));
}

GeneratePrimes::GeneratePrimes(long floor, long ceiling) {
	
    primes = vector<long>();
	lowerBound = floor;
	upperBound = ceiling;
	
	srand(time(NULL));
    composites = vector<bool>(upperBound, 0); //keeps track of composite numbers. If i is prime,
                                             //then composites[i]=false
    composites.at(0) = 1; //pretend 0 and 1 are prime for simplicity
    composites.at(1) = 1;
}

GeneratePrimes::~GeneratePrimes() {}

bool GeneratePrimes::writePrimes(char* filename) {
    if(primes.empty()) {
        return 1;
    }
	try {
		ofstream fp;
		fp.open(filename);
		
        for(std::vector<long>::iterator it = primes.begin(); it != primes.end(); ++it)  {
            if(*it > lowerBound) {
            	fp << *it << '\n';
            }
		}
		
		fp.close();
		return 0;
	} catch (int e) {
        cerr << "File io exception occurred: " << e << endl;
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
		
        //prevent divide by 0 error
        if(lines.size() == 0) {
            cout << filename << " empty. Exiting readRandomPrime()." << endl;
            return 1;
        }

		int index = rand() % lines.size();
		return lines.at(index);
		
	} catch (int e) {
		cerr << "File io execption occurred: " << e << endl;
	}
	return 1;
}
			

void GeneratePrimes::generate() {

	for(long i = 0; i < upperBound; i++) {
		
        if(!composites.at(i)) {

            primes.push_back(i);
		
			for(long j = 0; j < upperBound; j++) {
				long product = j * i; //find composite numbers
				if( product >= upperBound ) { //out of bounds
					break;
				}
                composites.at(j*i) = 1;
			}
		}
	}
}

long GeneratePrimes::randomPrime() {
	
    //prevent divide by 0 error
    if(primes.size() == 0) {
        cout << "List of primes empty. Exiting randomPrime()." << endl;
        return 1;
    }

    int index = rand() % primes.size();
    return primes.at(index);
}

void GeneratePrimes::printPrimes() {
	
    cout << "All prime numbers less than " << upperBound << endl;
	
    for(std::vector<long>::iterator it = primes.begin(); it != primes.end(); ++it) {
        cout << *it << " ";
	}
	cout << endl;
}
