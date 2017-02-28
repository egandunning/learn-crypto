#include <headers/generatedata.h>

std::vector<mpz_class> GenerateData::composites(unsigned int startDigits, unsigned int count) {

    std::vector<mpz_class> composites;

    //startDigits must be at least 2.
    if(startDigits < 2) {
        std::cout << "in GenerateData::composites() - startDigits was set to ";
        std::cout << startDigits << " but must be greater than 2. startDigits reassigned to 2";
        std::cout << std::endl;
        startDigits = 2;
    }

    for(unsigned int i = 0; i < count; i++) {
        //to get a composite number with n digits, each factor can have n-1 digits
        mpz_class prime1 = GeneratePrimes::randomPrime(startDigits - 1);
        mpz_class prime2 = GeneratePrimes::randomPrime(startDigits - 1);
        composites.push_back(prime1 * prime2);

        //increment number of digits
        startDigits++;
    }

    return composites;
}

std::vector<std::string> GenerateData::plaintexts(unsigned int startLength, unsigned int count) {

    std::vector<std::string> plaintexts;

    for(unsigned int i = startLength; i < count + startLength; i++) {
        std::string plaintext(i, 'a');
        plaintexts.push_back(plaintext);
    }
    return plaintexts;
}

std::vector<std::string> GenerateData::getHashes(std::vector<std::string> plaintexts, Hash* alg) {

    std::vector<std::string> digests;

    if(alg == NULL) {
        std::cout << "Null pointer in GenerateData::getHashes()" << std::endl;
        return digests;
    }

    for(unsigned int i = 0; i < plaintexts.size(); i++) {
        alg->plaintext = plaintexts.at(i);
        alg->compute();
        digests.push_back(alg->digest);
    }

    return digests;
}

std::vector<QPointF> GenerateData::factor(std::vector<mpz_class> nums, Factor* alg) {

    std::vector<QPointF> points;

    if(alg == NULL) {
        std::cout << "Null pointer in GenerateData::factor()" << std::endl;
        return points;
    }

    for(std::vector<mpz_class>::iterator it = nums.begin(); it != nums.end(); it++) {

        points.push_back(alg->factor(*it));
    }
    return points;
}

std::vector<QPointF> GenerateData::crack(std::vector<std::string> strings, Crack* alg) {

    std::vector<QPointF> points;

    if(alg == NULL) {
        std::cout << "Null pointer in GenerateData::crack()" << std::endl;
        return points;
    }

    /*for(std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); it++) {
        alg->digest = *it;
        points.push_back(alg->reverse());
    }*/

    for(unsigned int i = 0; i < strings.size(); i++) {
        alg->digest = strings.at(i);
        std::cout << "in generatedata::crack()" << std::endl;
        points.push_back(alg->reverse());
    }

    return points;

}
