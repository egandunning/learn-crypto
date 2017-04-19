#ifndef QSFACTOR
#define QSFACTOR

#include <headers/factor.h>
#include <headers/qspolyworker.h>
#include <headers/generateprimes.h>

#include <bitset>
#include <iomanip>

class QSFactor : public Factor {

public:
    QSFactor();
    ~QSFactor();

    QPointF factor(mpz_class);

    struct solution {
        int primeIndex;
        int power;
        mpz_class modulus;
        mpz_class x1;
        mpz_class x2;
    };

private:
    long B;
    std::vector<QSPolyWorker*> polyThreads;
    std::vector<mpz_class> primes;
    mpz_class solveQuadraticModN(mpz_class, mpz_class);
    mpz_class gcd(mpz_class, mpz_class);
};

#endif // QSFACTOR

