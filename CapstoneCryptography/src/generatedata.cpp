#include <headers/generatedata.h>

template <class T>
std::vector<mpz_class> GenerateData<T>::composites(int startDigits, int count) {

    std::vector<mpz_class> composites;

    //startDigits must be at least 2.
    if(startDigits < 2) {
        startDigits = 2;
    }

    for(int i = 0; i < count; i++) {
        //to get a composite number with n digits, each factor can have n-1 digits
        mpz_class prime1 = GeneratePrimes::randomPrime(startDigits - 1);
        mpz_class prime2 = GeneratePrimes::randomPrime(startDigits - 1);
        composites.push_back(prime1 * prime2);

        //increment number of digits
        startDigits++;
    }

    return composites;
}

