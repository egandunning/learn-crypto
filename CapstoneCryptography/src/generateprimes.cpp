//implementation of the Sieve of Eratosthenes - more info at 
//https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

#include "headers/generateprimes.h"


GeneratePrimes::GeneratePrimes() :
    primes(),
    lowerBound(0),
    upperBound(0),
    composites(0)
{
    srand(time(NULL));
    std::cout << "here" <<std::endl;
}

GeneratePrimes::GeneratePrimes(long floor, long ceiling) {
	
    primes = vector<long>();
	lowerBound = floor;
	upperBound = ceiling;
	
	srand(time(NULL));
    composites = vector<bool>(upperBound, 0); //keeps track of composite numbers. If i is prime,
                                             //then composites[i]=false
    composites.at(0) = 1; //0 and 1 are not prime
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

std::vector<mpz_class> GeneratePrimes::generate(mpz_class ceiling) {

    std::vector<mpz_class> primeNums = std::vector<mpz_class>();
    if(!ceiling.fits_slong_p()) {
        std::cout << "number is too big to generate primes. exiting generate(mpz_class)" << std::endl;
        return primeNums;
    }
    long bound = ceiling.get_si();
    std::vector<bool> comps = std::vector<bool>(bound, 0);
    comps.at(0) = 1;
    comps.at(1) = 1;

    for(long i = 0; i < bound; i++) {

        if(!comps.at(i)) {

            primeNums.push_back(i);

            for(long j = 0; j < bound; j++) {
                long product = j * i; //find composite numbers
                if( product >= bound ) { //out of bounds
                    break;
                }
                comps.at(j*i) = 1;
            }
        }
    }
    return primeNums;
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

/**
 * @brief GeneratePrimes::randomPrime generates a random prime number with
 * numDigits digits
 * @param numDigits
 * @return
 */
mpz_class GeneratePrimes::randomPrime(unsigned int numDigits) {

    begin: //use goto, while loop implementation is unneccessarily complex

    //create random string of numDigits characters
    std::random_device r;
    std::mt19937 gen(r());
    std::uniform_int_distribution<short> dist(0,9);

    std::string number = "";

    for(unsigned int i = 0; i < numDigits-1; i++) {
        number += std::to_string(dist(gen));
    }
    //make sure the last digit is odd
    std::uniform_int_distribution<short> oddDist(1,5);
    short lastDigit = oddDist(gen);
    lastDigit = (lastDigit*2) - 1;
    number += std::to_string(lastDigit);

    //convert string to big num
    mpz_class primeCandidate(number,10);

    //check if num is prime
    for(mpz_class i = 2; i <= sqrt(primeCandidate); i++) {
        if(primeCandidate % i == 0) {

            //primeCandidate has a factor, try again.
            goto begin;
        }
    }
    if(primeCandidate < 2) {
        goto begin;
    }
    // primeCandidate has no factors, must be prime
    return primeCandidate;
}

void GeneratePrimes::printPrimes() {
	
    cout << "All prime numbers less than " << upperBound << endl;
	
    for(std::vector<long>::iterator it = primes.begin(); it != primes.end(); ++it) {
        cout << *it << " ";
	}
	cout << endl;
}
