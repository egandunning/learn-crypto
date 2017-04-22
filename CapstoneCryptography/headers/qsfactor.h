#ifndef QSFACTOR
#define QSFACTOR

#include <headers/factor.h>
#include <headers/qspolyworker.h>
#include <headers/generateprimes.h>

#include <bitset>
#include <iomanip>
#include <vector>
#include <list>
#include <map>

class QSFactor : public Factor {

public:
    QSFactor();
    ~QSFactor();

    QPointF factor(mpz_class);

    //represents a row in an exponent vector: the vector v that represents num and x1,x2,.. where num = (x1^2-n)(x2^2-n)...
    struct row {
        long vec = 0;
        std::vector<mpz_class> xVals;
    };

private:
    long B; //smoothness bound
    std::vector<mpz_class> primes;
    std::map<mpz_class,row> expVectors;
    mpz_class composite;
    mpz_class x;

    mpz_class solveQuadraticModN(mpz_class, mpz_class);

    std::list<std::pair<long, std::vector<mpz_class>>> gaussElim(std::list<std::pair<long,std::vector<mpz_class>>>);
    void quadraticSieve();
    std::pair<mpz_class,mpz_class> solveQuadratic(mpz_class);
    void printVectors();
    mpz_class bigLog(mpz_class);
    mpz_class gcd(mpz_class, mpz_class);
    long computeB();
};

#endif // QSFACTOR

