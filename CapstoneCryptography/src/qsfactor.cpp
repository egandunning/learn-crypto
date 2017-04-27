#include <headers/qsfactor.h>

QSFactor::QSFactor() :
    B(0),
    composite(0),
    x(0),
    threads(),
    primes()
{
    int idealThreadCount = QThread::idealThreadCount();
    if(idealThreadCount < 1) {
        threadCount = 1;
    } else {
        threadCount = idealThreadCount;
    }
}

QSFactor::~QSFactor() {}

QPointF QSFactor::factor(mpz_class comp) {

    QElapsedTimer timer;
    timer.start();

    composite = comp;
    int numDigits = composite.get_str(10).length();
    B = computeB();
    std::cout << "B=" << B << std::endl;

    x = sqrt(composite) + 1;

    //generate primes less than B
    GeneratePrimes gen = GeneratePrimes();

    primes = new std::vector<mpz_class>(gen.generate(B+1));

    initThreads(threadCount);

    std::cout << "starting exponent vector generation" << std::endl;

    //quadratic sieve step
    quadraticSieve();

    std::cout << "starting lin. algebra step with " << expVectors->size() << " rows." << std::endl;

    //printVectors();

    for(std::map<mpz_class,row>::iterator it = expVectors->begin(); it != expVectors->end(); it++) {

        std::map<mpz_class,row>::iterator it2 = it;
        it2++;
        for(; it2 != expVectors->end(); it2++) {
            if(it2->second.vec != 0 && it2->second.vec == it->second.vec) {
                it2->second.vec = it2->second.vec ^ it->second.vec; //addition mod 2
                it2->second.xVals.push_back(it->first);
            }
        }
    }

    std::cout << "lin alg done. " << std::endl;

    //printVectors();

    mpz_class square1 = 1;
    mpz_class square2 = 1;
    for(std::map<mpz_class,row>::iterator it = expVectors->begin(); it != expVectors->end(); it++) {
        if(it->second.vec == 0) { //number is square
            std::vector<mpz_class> xTerms = it->second.xVals;
            xTerms.push_back(it->first);
            square1 = 1;
            square2 = 1;
            for(int xTerm = 0; xTerm < xTerms.size(); xTerm++) {
                //std::cout << xTerms.at(xTerm).get_str() << " ";
                mpz_class temp = (xTerms.at(xTerm))*(xTerms.at(xTerm));
                square1 *= temp;
                square2 *= (temp - composite);
            }
            std::cout << std::endl;

            if(!mpz_perfect_square_p(square2.get_mpz_t())) {
                std::cout << "exponent vector 0, but number is not square" << std::endl;
                continue;
            }

            std::cout << "composite: " << composite.get_str() << " square1: " << square1.get_str() << " square2: " << square2.get_str() << std::endl;
            if(square1 % composite == square2 % composite && sqrt(square1) % composite != sqrt(square2) % composite) {
                std::cout << "made it" << std::endl;
                std::cout << "square1: " << square1.get_str() << " square2: " << square2.get_str() << std::endl;
                p1 = gcd(sqrt(square1)+sqrt(square2),composite);
                p2 = gcd(sqrt(square1)-sqrt(square2),composite);
                if(p1*p2==composite) {
                    break;
                }
                p1 = p2 = 0;

            }
        }
    }

    long elapsed = timer.elapsed();
    return QPointF(numDigits, elapsed);
}


mpz_class QSFactor::gcd(mpz_class a, mpz_class b) {

    std::cout << a.get_str() << " " << b.get_str() << std::endl;

    mpz_class result = 0;
    if(a == 0 || b == 0) {
        return result;
    }
    mpz_gcd(result.get_mpz_t(), a.get_mpz_t(), b.get_mpz_t());
    return result;
}

/**
 * Sieving step. For each prime p less than B, solve x^2-n=0 (mod p) for x.
 * For the solutions x1,x2, let i=x1 and increment by p, flip the pth bit of
 * the exponent vector
 * expVectors[i] =
 * @brief QSFactor::quadraticSieve
 */
void QSFactor::quadraticSieve() {

    int numDigits = composite.get_str(10).length();

    std::cout << primes->size() << " primes." << std::endl;
    for(size_t pIndex = 0; pIndex < primes->size(); pIndex++) {

        jobList.push(pIndex);

        /*//solve x^2-n=0 mod p for x
        std::pair<mpz_class,mpz_class> solution = solveQuadratic(primes.at(pIndex));

        for(mpz_class x1 = solution.first; x1 < 2*x+B*B; x1 += primes.at(pIndex)) {
            if(x1 < x) {
                continue;
            }
            //std::cout << "in qs: x1: " << x1.get_str() << std::endl;
            row currentVector = expVectors[x1];
            currentVector.vec = currentVector.vec ^ (1 << pIndex);
            expVectors[x1] = currentVector;

            //std::cout << std::bitset<32>(currentVector.vec) << " " << pIndex << " " << x1.get_str() << std::endl;
        }

        if(solution.first != solution.second || pIndex == 0) { //one solution
            continue;
        }

        for(mpz_class x2 = solution.second; x2 < 2*x+B*B; x2 += primes.at(pIndex)) {
            if(x2 < x) {
                continue;
            }
            //std::cout << "in qs: x2: " << x2.get_str() << std::endl;
            row currentVector = expVectors[x2];
            currentVector.vec = currentVector.vec ^ (1 << pIndex);
            expVectors[x2] = currentVector;

            //std::cout << std::bitset<32>(currentVector.vec) << " " << pIndex << " " << x2.get_str() << std::endl;
        }*/
    }

    for(unsigned int id = 0; id < threadCount; id++) {
        if(!threads.at(id)->isRunning()) {
            threads.at(id)->work(jobList.top());
            jobList.pop();
        }
    }

}

/**
 * Solve x^2-n=0 (mod p) for x. n is the number to be factored
 * @brief QSFactor::solveQuadratic
 * @param p
 * @return
 */
std::pair<mpz_class, mpz_class> QSFactor::solveQuadratic(mpz_class p) {

     mpz_class n = composite % p;
     p *= 4;

     for(mpz_class i = 0; i < p; i++) {
         if( (i*i-n) % p == 0 ) {
             return std::pair<mpz_class,mpz_class>(i,p-i);
         }
     }
     return std::pair<mpz_class,mpz_class>(0,0);
}

/**
 * Print exponent vectors
 * @brief QSFactor::printVectors
 */
void QSFactor::printVectors() {
    for(std::map<mpz_class,row>::iterator it = expVectors->begin(); it != expVectors->end(); it++) {
        std::cout << it->first.get_str() << " " << std::bitset<64>(it->second.vec);
        for(size_t i = 0; i < it->second.xVals.size(); i++) {
            std::cout << " " << it->second.xVals.at(i).get_str();
        }
        std::cout << std::endl;
    }
}

/**
 * Approximates logarithm using the fact: ln(ab) = ln(a) + ln(b)
 * @brief QSFactor::log
 * @return
 */
mpz_class QSFactor::bigLog(mpz_class x) {

    if(x==1) {
        return 0;
    }
    if(x < 1) {
        return -1;
    }
    long maxLong = std::numeric_limits<long>::max()-1;

    mpz_class logarithm = 0;

    while(x / maxLong > maxLong) {
        x /= maxLong;
        logarithm += log(maxLong);
    }
    logarithm += log(x.get_si());
    return logarithm;
}

/**
 * Compute the smoothness bound B
 * @brief QSFactor::computeB
 * @return
 */
long QSFactor::computeB() {
    long b = 0;
    mpz_class temp = sqrt(bigLog(composite)*bigLog(bigLog(composite)));
    long exp = (.75)*(temp.get_si());
    b = pow(2,exp) + 5;
    return b;
}

void QSFactor::initThreads(unsigned int count) {

    threadCount = count;

    for(unsigned int i = 0; i < count; i++) {
        row temp = row();
        temp.vec = 0;
        temp.xVals = std::vector<mpz_class>();
        threads.push_back(new QSWorker(composite, expVectors, primes, i, count));
        connect(threads.at(i), SIGNAL(finished(unsigned int)), this, SLOT(assignJob(unsigned int)));
    }

}

void QSFactor::assignJob(unsigned int id) {
    std::cout << "thread " << id << "finished, starting new job" << std::endl;
    if(jobList.size() == 0) {
        threads.at(id)->work(0);
        return;
    }
    threads.at(id)->work(jobList.top());
    jobList.pop();
}
