#include <headers/qsfactor.h>

QSFactor::QSFactor() :
    B(0),
    composite(0),
    x(0),
    primes()
{}

QSFactor::~QSFactor() {}

QPointF QSFactor::factor(mpz_class comp) {

    QElapsedTimer timer;
    timer.start();

    composite = comp;
    int numDigits = composite.get_str(10).length();
    B = pow(2,(.75)*sqrt(numDigits*log(numDigits)));
    std::cout << "B=" << B << std::endl;

    B = 12;

    x = sqrt(composite) + 1;

    //generate primes less than B
    GeneratePrimes gen = GeneratePrimes();
    primes = gen.generate(B+1);

    std::cout << "starting exponent vector generation" << std::endl;

    //quadratic sieve step
    quadraticSieve();

    std::cout << "starting lin. algebra step with " << expVectors.size() << " rows." << std::endl;

    for(std::map<mpz_class,row>::iterator it = expVectors.begin(); it != expVectors.end(); it++) {
        std::cout << it->first.get_str() << " " << std::bitset<64>(it->second.vec);
        for(size_t i = 0; i < it->second.xVals.size(); i++) {
            std::cout << " " << it->second.xVals.at(i).get_str();
        }
        std::cout << std::endl;
    }

    for(std::map<mpz_class,row>::iterator it = expVectors.begin(); it != expVectors.end(); it++) {

        std::map<mpz_class,row>::iterator it2 = it;
        it2++;
        for(; it2 != expVectors.end(); it2++) {
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
    for(std::map<mpz_class,row>::iterator it = expVectors.begin(); it != expVectors.end(); it++) {
        if(it->second.vec == 0) { //number is square
            std::vector<mpz_class> xTerms = it->second.xVals;
            xTerms.push_back(it->first);
            square1 = 1;
            square2 = 1;
            for(int xTerm = 0; xTerm < xTerms.size(); xTerm++) {
                std::cout << xTerms.at(xTerm).get_str() << " ";
                mpz_class temp = (xTerms.at(xTerm))*(xTerms.at(xTerm));
                square1 *= temp;
                square2 *= (temp - composite);
                //std::cout << square1.get_str() << " " << square2.get_str() << std::endl;

            }
            std::cout << std::endl;

            if(!mpz_perfect_square_p(square2.get_mpz_t())) {
                std::cout << "exponent vector 0, but number is not square" << std::endl;
                continue;
            }

            if(square1 % composite == square2 % composite && sqrt(square1) % composite != sqrt(square2) % composite) {
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

/**
 * @brief QSFactor::solveQuadraticModN find x: x^2-c = 0 (mod 4modulus)
 * @param c
 * @param modulus
 * @return -1 if no solution
 */
mpz_class QSFactor::solveQuadraticModN(mpz_class c, mpz_class modulus) {

    modulus *= 4;
    c = c % modulus;

    for(mpz_class i = 0; i < 4*modulus; i++) {
        if( (i*i-c) % modulus == 0 ) {
            return i;
        }
    }
    return -1;
}

mpz_class QSFactor::gcd(mpz_class a, mpz_class b) {

    std::cout << a.get_str() << " " << b.get_str() << std::endl;

    mpz_class result = 0;
    mpz_gcd(result.get_mpz_t(), a.get_mpz_t(), b.get_mpz_t());
    return result;
}

std::list<std::pair<long, std::vector<mpz_class>>> QSFactor::gaussElim(std::list<std::pair<long, std::vector<mpz_class> > > rows) {
    rows.sort(std::greater<std::pair<long,std::vector<mpz_class>>>());
        //std::cout << std::endl;
        /*for(std::list<std::pair<long,mpz_class>>::iterator it = rows.begin(); it != rows.end(); it++) {
            std::cout << std::bitset<12>(it->first) << " " << it->second << std::endl;
        }*/

    long index = 1;

    //std::cout << "index: " << std::bitset<12>(index) << std::endl;
    for(std::list<std::pair<long,std::vector<mpz_class>>>::reverse_iterator it = rows.rbegin(); it != rows.rend(); it++) {

        //find new index
        while(it->first > index<<1) {
            index = index << 1;
        }
        //std::cout << "index: " << std::bitset<12>(index) << " " << it->second << std::endl;

        std::list<std::pair<long,std::vector<mpz_class>>>::reverse_iterator it2 = it;
        it2++;
        for( ; it2 != rows.rend(); it2++) {
            if(it2->first == it->first) { //if(it2->first <= index) {
                it2->first = it2->first ^ it->first; //addition mod 2
                //it2->second = it2->second * it->second;
                for(size_t index = 0; index < it->second.size(); index++) {
                    it2->second.push_back(it->second.at(index));
                }
                if(it2->first == 0) { //exponent vector is the 0 vector
                    break;
                }
            }
        }
    }
    return rows;
}

/**
 * Sieving step. For each prime p less than B, solve x^2-n=0 (mod p) for x.
 * For the solutions x1,x2, let i=x1 and increment by p, flip the pth bit of
 * the exponent vector
 * expVectors[i] =
 * @brief QSFactor::quadraticSieve
 */
void QSFactor::quadraticSieve() {

    std::cout << primes.size() << " primes." << std::endl;
    for(size_t pIndex = 0; pIndex < primes.size(); pIndex++) {
        //solve x^2-n=0 mod p for x
        std::pair<mpz_class,mpz_class> solution = solveQuadratic(primes.at(pIndex));

        for(mpz_class x1 = solution.first; x1 < 100; x1 += primes.at(pIndex)) {
            if(x1 < x) {
                continue;
            }
            row currentVector = expVectors[x1];
            currentVector.vec = currentVector.vec ^ (1 << pIndex);
            expVectors[x1] = currentVector;

            std::cout << std::bitset<32>(currentVector.vec) << " " << pIndex << " " << x1.get_str() << std::endl;
        }

        if(solution.first!=solution.second || pIndex == 0) { //one solution
            continue;
        }

        for(mpz_class x2 = solution.second; x2 < 100; x2 += primes.at(pIndex)) {
            if(x2 < x) {
                continue;
            }
            row currentVector = expVectors[x2];
            currentVector.vec = currentVector.vec ^ (1 << pIndex);
            expVectors[x2] = currentVector;

            std::cout << std::bitset<32>(currentVector.vec) << " " << pIndex << " " << x2.get_str() << std::endl;
        }
        /*if(expVectors.size() > B) {
            return;
        }*/
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
    for(std::map<mpz_class,row>::iterator it = expVectors.begin(); it != expVectors.end(); it++) {
        std::cout << it->first.get_str() << " " << std::bitset<64>(it->second.vec);
        for(size_t i = 0; i < it->second.xVals.size(); i++) {
            std::cout << " " << it->second.xVals.at(i).get_str();
        }
        std::cout << std::endl;
    }
}
