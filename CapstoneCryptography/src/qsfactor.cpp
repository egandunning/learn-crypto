#include <headers/qsfactor.h>

QSFactor::QSFactor() :
    B(0),
    composite(0),
    x(0),
    threads(),
    primes(),
    expVectors(),
    smoothVectors(),
    fb()
{
    name = "Quadratic sieve";
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
    std::cout << "number to factor: " << composite.get_str() << std::endl;
    int numDigits = composite.get_str(10).length();
    B = computeB();
    std::cout << "B=" << B << std::endl;

    x = sqrt(composite) + 1;

    //generate primes less than B
    GeneratePrimes gen = GeneratePrimes();

    primes = gen.generate(B+1);

    std::cout << "starting exponent vector generation" << std::endl;

    for(mpz_class i : primes) {
        std::cout << i.get_str() << ", ";
    }
    std::cout << endl;

    generateFactorBase();

    std::cout << "finished step" << std::endl;
    for(factorBase i : fb) {
        std::cout << i.prime.get_str() << " " << i.pIndex << " " << i.s1.get_str() << " " << i.s2.get_str() << std::endl;
    }

    std::cout << std::endl << "primes: ";
    for(mpz_class i : primes) {
        std::cout << i.get_str() << ", ";
    }
    std::cout << std::endl;

    std::cout << "before sieve" << std::endl;
    sieve();
    std::cout << "after sieve" << std::endl;

    printVectors();


// end "trying something new"

    //quadratic sieve step
  /*  mpz_class lBound = x;
    mpz_class uBound = x+3*B;
    quadraticSieve(uBound);

    std::cout << "starting lin. algebra step with " << expVectors.size() << " rows." << std::endl;

    printVectors();

    int power = 1;
    tryagain:*/

   /* for(std::map<mpz_class,row>::iterator it = expVectors.begin(); it != expVectors.end(); it++) {
        if(it->second.xVals.at(0) < B) {
            smoothVectors[it->first] = it->second;
        }
    }*/


    for(std::map<mpz_class,row>::iterator it = smoothVectors.begin(); it != smoothVectors.end(); it++) {

        if(it->second.xVals.at(0) > primes.back()) { //number is not smooth
            continue;
        }

        std::map<mpz_class,row>::iterator it2 = it;
        it2++;
        for(; it2 != smoothVectors.end(); it2++) {
            if(it2->second.vec != 0 && it2->second.vec == it->second.vec) {
                it2->second.vec = it2->second.vec ^ it->second.vec; //addition mod 2
                it2->second.xVals.push_back(it->first);
            }
        }
    }

    std::cout << "lin alg done. " << std::endl;

    printVectors();

    mpz_class square1 = 1;
    mpz_class square2 = 1;


    for(std::map<mpz_class,row>::iterator it = smoothVectors.begin(); it != smoothVectors.end(); it++) {
        if(it->second.vec == 0) { //number is square
            std::vector<mpz_class> xTerms = it->second.xVals;
            xTerms.push_back(it->first);
            square1 = 1;
            square2 = 1;
            for(int xTerm = 1; xTerm < xTerms.size(); xTerm++) {
                //std::cout << xTerms.at(xTerm).get_str() << " ";
                mpz_class temp = (xTerms.at(xTerm))*(xTerms.at(xTerm));
                square1 *= temp;
                square2 *= (temp - composite);
            }
            //std::cout << std::endl;
            //std::cout << square2.get_str() << " " << std::bitset<64>(it->second.vec) << std::endl;
            if(!mpz_perfect_square_p(square2.get_mpz_t())) {
                //std::cout << "exponent vector 0, but number is not square" << std::endl;
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

    /*if(p1 == 0 || p2 == 0) {
        power++;
        std::cout << "power = " << power << std::endl;
        if(power > 9) {
            long elapsed = timer.elapsed();
            return QPointF(numDigits, elapsed);
        }
        //lBound += B;
        uBound += 2*B;
        quadraticSieve(uBound, power);
        goto tryagain;
    }*/

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


void QSFactor::sieve() {

    for(factorBase factor : fb) {

        for(mpz_class i = factor.s1; i < 2*x; i+=factor.prime) {
            if(i < x) {
                continue;
            }
            row currentVector = expVectors[i];

            currentVector.vec = currentVector.vec ^ (1 << factor.pIndex);
            if(currentVector.xVals.size() == 0) {
                mpz_class temp = ((i*i)-composite) / primes.at(factor.pIndex);//primes.at(pIndex);
                currentVector.xVals.push_back(temp);
            } else {
                currentVector.xVals.at(0) = currentVector.xVals.at(0) / primes.at(factor.pIndex);
            }
            mpz_class temp = ((i*i)-composite);
            //std::cout << i.get_str() << " " << temp.get_str() << " ~ " << currentVector.xVals.at(0).get_str() << " * " << primes.at(factor.pIndex).get_str() << " " << factor.prime.get_str() << std::endl;
           // currentVector.xVals.push_back(modulus);
            expVectors[i] = currentVector;
            if(currentVector.xVals.at(0) == 1) {
                smoothVectors[i] = currentVector;
            }
        }

        if(factor.s1 == factor.s2) {
            //only one solution
            std::cout << "one solution for " << factor.prime.get_str() << std::endl;
            continue;
        }

        for(mpz_class i = factor.s2; i < 2*x; i+=factor.prime) {
            if(i < x) {
                continue;
            }
            row currentVector = expVectors[i];

            currentVector.vec = currentVector.vec ^ (1 << factor.pIndex);

            if(currentVector.xVals.size() == 0) {
                mpz_class temp = ((i*i)-composite) / primes.at(factor.pIndex);//primes.at(pIndex);
                currentVector.xVals.push_back(temp);
            } else {
                //std::cout << "HERE " << i.get_str() << std::endl;
                currentVector.xVals.at(0) = currentVector.xVals.at(0) / primes.at(factor.pIndex);
                //std::cout << currentVector.xVals.at(0).get_str() << std::endl;
            }
            mpz_class temp = ((i*i)-composite);
            //std::cout << i.get_str() << " " << temp.get_str() << " ~ " << currentVector.xVals.at(0).get_str() << " * " << primes.at(factor.pIndex).get_str() << " " << factor.prime.get_str() << std::endl;
           // currentVector.xVals.push_back(modulus);
            expVectors[i] = currentVector;
            if(currentVector.xVals.at(0) == 1) {
                smoothVectors[i] = currentVector;
            }
        }

        if(smoothVectors.size() > primes.size()) {
            return;
        }

    }
}

/**
 * Sieving step. For each prime p less than B, solve x^2-n=0 (mod p) for x.
 * For the solutions x1,x2, let i=x1 and increment by p, flip the pth bit of
 * the exponent vector
 * expVectors[i] =
 * @brief QSFactor::quadraticSieve
 */
void QSFactor::quadraticSieve(mpz_class upperBound, int power) {

    std::cout << "upperBound: " << upperBound << std::endl;

    int numDigits = composite.get_str(10).length();

    std::cout << primes.size() << " primes." << std::endl;
    for(size_t pIndex = 0; pIndex < primes.size(); pIndex++) {

        mpz_class modulus = primes.at(pIndex);
        for(int i = 1; i < power; i++) {
            modulus *= primes.at(pIndex);
            //printVectors();
            if(modulus > 5000) {
                std::cout << "modulus too big: " << modulus << std::endl;
                break;
            }
        }

        if(modulus > 5000) {
            continue;
        }

        //solve x^2-n=0 mod p for x
        std::pair<mpz_class,mpz_class> solution = solveQuadratic(modulus);
        if(solution.first == -1 && solution.second == -1) {
            continue;
        }

        for(mpz_class x1 = solution.first; x1 < upperBound; x1 += modulus) {
            if(x1 < x) {
                continue;
            }
            //std::cout << "in qs: x1: " << x1.get_str() << std::endl;
            row currentVector = expVectors[x1];
            currentVector.vec = currentVector.vec ^ (1 << pIndex);
            if(currentVector.xVals.size() == 0) {
                mpz_class temp = ((x1*x1)-composite) / modulus;//primes.at(pIndex);
                currentVector.xVals.push_back(temp);
            } else {
                currentVector.xVals.at(0) = currentVector.xVals.at(0) / primes.at(pIndex);
            }
            mpz_class temp = ((x1*x1)-composite);
            std::cout << x1.get_str() << " " << temp.get_str() << " " << currentVector.xVals.at(0).get_str() << std::endl;
           // currentVector.xVals.push_back(modulus);
            expVectors[x1] = currentVector;

            //std::cout << std::bitset<32>(currentVector.vec) << " "primes.at(pIndex) << pIndex << " " << x1.get_str() << std::endl;
        }

        if(solution.first != solution.second || pIndex == 0) { //one solution
            continue;
        }

        for(mpz_class x2 = solution.second; x2 < upperBound; x2 += modulus) {
            if(x2 < x) {
                continue;
            }
            //std::cout << "in qs: x2: " << x2.get_str() << std::endl;
            row currentVector = expVectors[x2];
            currentVector.vec = currentVector.vec ^ (1 << pIndex);
            if(currentVector.xVals.size() == 0) {
                mpz_class temp = ((x2*x2)-composite) / modulus;//primes.at(pIndex);
                currentVector.xVals.push_back(temp);
            } else {
                currentVector.xVals.at(0) = currentVector.xVals.at(0) / primes.at(pIndex);
            }
         //   currentVector.xVals.push_back(modulus);
            expVectors[x2] = currentVector;

            //std::cout << std::bitset<32>(currentVector.vec) << " " << pIndex << " " << x2.get_str() << std::endl;
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


     for(mpz_class i = 0; i < p; i++) {
         if( (i*i-n) % p == 0 ) {
             return std::pair<mpz_class,mpz_class>(i,p-i);
         }
     }
     return std::pair<mpz_class,mpz_class>(-1,-1);
}

/**
 * Print exponent vectors
 * @brief QSFactor::printVectors
 */
void QSFactor::printVectors() {
    for(std::map<mpz_class,row>::iterator it = smoothVectors.begin(); it != smoothVectors.end(); it++) {

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
    long exp = (.8)*(temp.get_si());
    b = pow(2,exp) + 5;
    return b;
}

void QSFactor::initThreads(unsigned int count) {

    /*threadCount = count;

    for(unsigned int i = 0; i < count; i++) {
        row temp = row();
        temp.vec = 0;
        temp.xVals = std::vector<mpz_class>();
        // expVectors, primes must be pointers to enable this code threads.push_back(new QSWorker(composite, expVectors, primes, i, count));
        connect(threads.at(i), SIGNAL(finished(unsigned int)), this, SLOT(assignJob(unsigned int)));
    }*/

}

void QSFactor::assignJob(unsigned int id) {
    std::cout << "thread " << id << "finished, starting new job" << std::endl;
    if(jobList.size() == 0) {
        return;
    }
    threads.at(id)->work(jobList.top());
    jobList.pop();
}

void QSFactor::generateFactorBase() {
    std::vector<std::vector<mpz_class>::iterator> eraseMe = std::vector<std::vector<mpz_class>::iterator>();

    int primeIndex = 0;
    for(std::vector<mpz_class>::iterator pIt = primes.begin(); pIt != primes.end(); pIt++) {

        mpz_class p = *pIt;
        std::pair<mpz_class,mpz_class> solution = solveQuadratic(p);
        if(solution.first == -1 && solution.second == -1) {
            //No solution!
            std::cout << "x^2 - " << composite.get_str() << " = 0 mod " << p.get_str() << " has no solution." << std::endl;
            eraseMe.push_back(pIt);
            //primeIndex++;
            continue;
        }
        factorBase temp = {p, primeIndex, 1, solution.first, solution.second};
        fb.push_back(temp);
        primeIndex++;
    }

    for(auto it : eraseMe) {
        primes.erase(it);
        eraseMe.clear();
    }

    // for all squares of primes
    primeIndex = 0;
    for(std::vector<mpz_class>::iterator pIt = primes.begin(); pIt != primes.end(); pIt++) {
        mpz_class p = *pIt * *pIt;
        std::pair<mpz_class,mpz_class> solution = solveQuadratic(p);
        if(solution.first == -1 && solution.second == -1) {
            //No solution!
            std::cout << "x^2 - " << composite.get_str() << " = 0 mod " << p.get_str() << " has no solution." << std::endl;
            primeIndex++;
            continue;
        }
        factorBase temp = {p, primeIndex, 2, solution.first, solution.second};
        fb.push_back(temp);
        primeIndex++;
    }

    // for cubes of most primes
    primeIndex = 0;
    for(std::vector<mpz_class>::iterator pIt = primes.begin(); pIt != primes.end(); pIt++) {
        if(*pIt > 128) {
            break;
        }
        mpz_class p = *pIt * *pIt * *pIt;
        std::pair<mpz_class,mpz_class> solution = solveQuadratic(p);
        if(solution.first == -1 && solution.second == -1) {
            //No solution!
            std::cout << "x^2 - " << composite.get_str() << " = 0 mod " << p.get_str() << " has no solution." << std::endl;
            primeIndex++;
            continue;
        }
        factorBase temp = {p, primeIndex, 3, solution.first, solution.second};
        fb.push_back(temp);
        primeIndex++;
    }

    for(mpz_class i : primes) {
        std::cout << i.get_str() << ", ";
    }
    std::cout << std::endl;

    //higher powers of small primes
    primeIndex = 0;
    for(std::vector<mpz_class>::iterator pIt = primes.begin(); pIt != primes.end(); pIt++) {
        if(*pIt > 16) {
            break;
        }
        for(int j = 4; j < 6; j++) {
            mpz_class p = *pIt;
            p = pow(pIt->get_si(), j);

            std::pair<mpz_class,mpz_class> solution = solveQuadratic(p);
            if(solution.first == -1 && solution.second == -1) {
                //No solution!
                std::cout << "x^2 - " << composite.get_str() << " = 0 mod " << p.get_str() << " has no solution." << std::endl;
                //eraseMe.push_back(pIt);
                //primeIndex++;
                continue;
            }
            factorBase temp = {p, primeIndex, j, solution.first, solution.second};
            fb.push_back(temp);

        }
        primeIndex++;
    }

}
