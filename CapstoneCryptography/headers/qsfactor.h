#ifndef QSFACTOR
#define QSFACTOR

#include <headers/factor.h>
#include <headers/qsworker.h>
#include <headers/generateprimes.h>
#include <headers/row.h>

#include <bitset>
#include <iomanip>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <utility>
#include <cstring>

class QSFactor : public Factor {

    Q_OBJECT

public:
    QSFactor();
    ~QSFactor();

    QPointF factor(mpz_class);

public slots:
    void assignJob(unsigned int);

private:
    long B; //smoothness bound
    mpz_class composite;
    mpz_class x;

    std::vector<mpz_class> primes;
    std::map<mpz_class, row> expVectors;
    std::map<mpz_class, row> smoothVectors;
    //std::list<std::pair<long, std::vector<mpz_class>>> vectors;
    std::list<row> vectors;
    std::vector<std::vector<mpz_class>> squares;
    std::priority_queue<size_t, std::vector<size_t>, std::greater<size_t>> jobList;
    std::vector<QSWorker*> threads;

    struct factorBase {
        mpz_class prime;
        size_t pIndex;
        int power;
        mpz_class s1;
        mpz_class s2;
        mpz_class beginIndex1;
        mpz_class beginIndex2;
    };

    std::vector<factorBase> fb;

    mpz_class solveQuadraticModN(mpz_class, mpz_class);
    //std::list<std::pair<long, std::vector<mpz_class>>> gaussElim(std::list<std::pair<long,std::vector<mpz_class>>>);
    void sieve();
    void sieve2();
    void quadraticSieve(mpz_class upperBound, int pow = 0);
    std::pair<mpz_class,mpz_class> solveQuadratic(mpz_class);
    void printVectors();
    mpz_class bigLog(mpz_class);
    mpz_class gcd(const mpz_class &, const mpz_class &);
    long computeB();
    void initThreads(unsigned int);
    void generateFactorBase();

    //methods for manipulating exponent vectors
    void insert(long (&arr)[5], int index);
    void printVec(long (&arr)[5], int length);
};

#endif // QSFACTOR

