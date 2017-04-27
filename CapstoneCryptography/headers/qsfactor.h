#ifndef QSFACTOR
#define QSFACTOR

#include <headers/factor.h>
#include <headers/qsworker.h>
#include <headers/generateprimes.h>

#include <bitset>
#include <iomanip>
#include <vector>
#include <list>
#include <map>
#include <queue>

class QSFactor : public Factor {

    Q_OBJECT

public:
    QSFactor();
    ~QSFactor();

    QPointF factor(mpz_class);

    //represents a row in an exponent vector: the vector v that represents num and x1,x2,.. where num = (x1^2-n)(x2^2-n)...
    /*struct row {
        long vec = 0;
        std::vector<mpz_class> xVals;
    };*/

public slots:
    void assignJob(unsigned int);

private:
    long B; //smoothness bound
    mpz_class composite;
    mpz_class x;

    std::vector<mpz_class> primes;
    std::map<mpz_class, row> expVectors;
    std::priority_queue<size_t, std::vector<size_t>, std::greater<size_t>> jobList;
    std::vector<QSWorker*> threads;

    mpz_class solveQuadraticModN(mpz_class, mpz_class);
    std::list<std::pair<long, std::vector<mpz_class>>> gaussElim(std::list<std::pair<long,std::vector<mpz_class>>>);
    void quadraticSieve(int pow = 0);
    std::pair<mpz_class,mpz_class> solveQuadratic(mpz_class);
    void printVectors();
    mpz_class bigLog(mpz_class);
    mpz_class gcd(mpz_class, mpz_class);
    long computeB();
    void initThreads(unsigned int);
};

#endif // QSFACTOR

