#include <headers/generatedata.h>

/**
 * @brief GenerateData::composites
 * Generates a vector of composite numbers with count elements.
 * @param startDigits number of digits for the first composite number. Must be
 * greater than 2.
 * @param count number of composites to generate.
 * @return vector containing bignums
 */
std::vector<mpz_class> GenerateData::composites(unsigned int startDigits, unsigned int count) {

    std::vector<mpz_class> composites;

    //startDigits must be at least 3.
    if(startDigits < 3) {
        std::cout << "in GenerateData::composites() - startDigits was set to ";
        std::cout << startDigits << " but must be greater than 3. startDigits reassigned to 3";
        std::cout << std::endl;
        startDigits = 3;
    }
    startDigits++; // offset later subtraction
    mpz_class composite = 0;
    for(unsigned int i = 0; i < count; i++) {


        //to get a composite number with n digits, the factors can have x,y digits where n=x+y+1
        while(composite.get_str().length() != startDigits-1) {

            int digitCount1;
            int digitCount2;
            //startDigits odd
            if(startDigits % 2 == 1) {
                digitCount1 = (startDigits - 1)/2;
                digitCount2 = digitCount1;
            } else { //startDigits even
                digitCount1 = startDigits/2;
                digitCount2 = digitCount1 - 1;
            }
            mpz_class prime1 = GeneratePrimes::randomPrime(digitCount1);
            mpz_class prime2 = GeneratePrimes::randomPrime(digitCount2);
            composite = prime1 * prime2;
        }
        composites.push_back(composite);

        //increment number of digits
        startDigits++;
    }

    return composites;
}

/**
 * @brief GenerateData::plaintexts
 * Generate a vector of strings with this format: "a", "aa" "a...a" ...
 * @param startLength number of characters in the first string
 * @param count how many strings to generate
 * @return vector containing strings
 */
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

    for(unsigned int i = 0; i < strings.size(); i++) {
        alg->digest = strings.at(i);
        points.push_back(alg->reverse());
    }

    return points;

}
