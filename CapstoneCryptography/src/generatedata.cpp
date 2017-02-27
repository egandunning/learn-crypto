#include <headers/generatedata.h>

std::vector<mpz_class> GenerateData::composites(int startDigits, int count) {

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

std::vector<QPointF> GenerateData::factor(std::vector<mpz_class> nums, Factor* alg) {

    std::vector<QPointF> points;

    for(std::vector<mpz_class>::iterator it = nums.begin(); it != nums.end(); it++) {
        //QPointF point;
        //point.setX(it->get_str(10).size()); //number of digits
        //point.setY(alg->factor(*it));
        points.push_back(alg->factor(*it));
    }
    return points;
}

