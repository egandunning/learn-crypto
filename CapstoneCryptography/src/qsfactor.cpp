#include <headers/qsfactor.h>

QSFactor::QSFactor() :
    B(0),
    primes()
{}

QSFactor::~QSFactor() {}

QPointF QSFactor::factor(mpz_class composite) {

    QElapsedTimer timer;
    timer.start();
    int numDigits = composite.get_str(10).length();
    B = pow(2,(.75)*sqrt(numDigits*log(numDigits)));
    if(B < 60) {
        B = 20;
    }
    std::cout << "B=" << B << std::endl;

    mpz_class x = sqrt(composite) + 1;
    /*threadCount = 4;
    for(unsigned int id = 0; id < threadCount; id++) {
        //create and start threads
        polyThreads.push_back(new QSPolyWorker(composite, x, id, threadCount));
        polyThreads.at(id)->start();
    }*/

    //generate primes less than B
    GeneratePrimes gen = GeneratePrimes(0,B+1);
    gen.generate();
    std::vector<long> primes = gen.getPrimes();

    std::vector<solution> factorBase;
    for(unsigned long i = 0; i < primes.size(); i++) {

        //eq. to solve: Q(i) = (ceil(sqrt(n))+i)^2-n = i^2 + bi + c = 0 (mod p)

        //solve eq. for powers of primes
        mpz_class c = 4 * composite;
        for(int power = 1; power <= 3; power++) {

            mpz_class m = pow(primes.at(i),power);
            mpz_class x1 = solveQuadraticModN(c, m);

            //std::cout << m.get_str() << " " << x1.get_str() << std::endl;

            if(x1 != -1) {

                x1 /= 2;

                solution s;
                s.primeIndex = i;
                s.power = power;
                s.modulus = m;
                if((x + x1) % m == 0) {
                    s.x1 = 0;
                    s.x2 = 0;
                } else {
                    s.x1 = m - ((x + x1) % m);
                    s.x2 = m - ((x - x1) % m);
                }
                factorBase.push_back(s);
            }

        }
    }


    /*for(size_t i = 0; i < factorBase.size(); i++) {
        solution s = factorBase[i];
        std::cout << std::setw(5) << primes.at(s.primeIndex) << "^" << s.power
                  << std::setw(3) << " x1: "
                  << std::setw(5) << s.x1.get_str()
                  << std::setw(3) << " x2: "
                  << std::setw(5) << s.x2.get_str() << std::endl;
    }*/

    // ^--- complete!

    std::cout << "starting exponent vector generation" << std::endl;
    std::list<std::pair<long,std::vector<mpz_class>>> expVectors;

    for(mpz_class i = 0; i < 1000000; i++) {



        mpz_class Q = (x+i)*(x+i) - composite;
        mpz_class QCopy = Q;
        if(i == 6035) {
            std::cout << Q.get_str() << std::endl;
        }
        long vec = 0;
        for(int index = factorBase.size()-1; index >= 0; index--) {
            mpz_class temp = i % factorBase.at(index).modulus;
            if(temp == factorBase.at(index).x1 || temp == factorBase.at(index).x2) {
                if(factorBase.at(index).power % 2 == 1) {
                    vec = vec ^ (1 << factorBase.at(index).primeIndex);
                }
                if(QCopy % factorBase.at(index).modulus == 0) {
                    QCopy /= factorBase.at(index).modulus;

                }
                //std::cout << "\t" << Q.get_str() << " -> " << QCopy.get_str() << " " << factorBase.at(index).modulus << std::endl;
            }
        }
        //std::cout << QCopy.get_str() << std::endl;
        if(QCopy == 1) {
            expVectors.push_back(std::pair<long,std::vector<mpz_class>>(vec, std::vector<mpz_class>(1,i) ));
            std::cout << expVectors.size() << " " << std::bitset<64>(expVectors.back().first) << " " << i.get_str() << std::endl;
        }
        if(expVectors.size() == B) {
            std::cout << "vectors generated" << std::endl;
            break;
        }
    }
    std::cout << "starting lin. algebra step" << std::endl;

    expVectors.sort();

    std::cout << "sorted vectors:" << std::endl;
    for(std::list<std::pair<long,std::vector<mpz_class>>>::iterator it = expVectors.begin(); it != expVectors.end(); it++) {
        std::cout << std::bitset<64>(it->first);
        for(size_t i = 0; i < it->second.size(); i++) {
            std::cout << " " << it->second.at(i).get_str();
        }
        std::cout << std::endl;
    }

    //"psuedo-gaussian elimination"
    long index = 1;

    for(std::list<std::pair<long,std::vector<mpz_class>>>::iterator it = expVectors.begin(); it != expVectors.end(); it++) {

        while(it->first > index) {
            index = index << 1;
        }
        std::list<std::pair<long,std::vector<mpz_class>>>::iterator it2 = it;
        it2++;
        for(; it2 != expVectors.end(); it2++) {
            if(it2->first <= index) {
                it2->first = it2->first ^ it->first; //addition mod 2

                for(size_t index = 0; index < it->second.size(); index++) {
                    it2->second.push_back(it->second.at(index));
                }
            }
        }

    }


    std::cout << std::endl;

    for(std::list<std::pair<long,std::vector<mpz_class>>>::iterator it = expVectors.begin(); it != expVectors.end(); it++) {
        std::cout << std::bitset<64>(it->first);
        for(size_t i = 0; i < it->second.size(); i++) {
            std::cout << " " << it->second.at(i).get_str();
        }
        std::cout << std::endl;
    }

    mpz_class square1 = 1;
    mpz_class square2 = 1;
    for(std::list<std::pair<long,std::vector<mpz_class>>>::iterator it = expVectors.begin(); it != expVectors.end(); it++) {
        if(it->first == 0) { //number is square
            std::vector<mpz_class> xTerms = it->second;
            for(int xTerm = 0; xTerm < xTerms.size(); xTerm++) {
                mpz_class temp = (x + xTerms.at(xTerm))*(x + xTerms.at(xTerm));
                square1 *= temp;
                square2 *= (temp - composite);

            }

            if(sqrt(square2)*sqrt(square2)!=square2) {
                std::cout << "exponent vector 0, but number is not square" << std::endl;
                continue;
            }

            if(square1 % composite == square2 % composite && sqrt(square1) % composite != sqrt(square2) % composite) {
                std::cout << "square1: " << square1.get_str() << " square2: " << square2.get_str() << std::endl;
                p1 = gcd(sqrt(square1)+sqrt(square2),composite);
                p2 = gcd(sqrt(square1)-sqrt(square2),composite);
                break;
            }
        }
    }

    /*for(unsigned long i = 0; i < primes.size(); i++) {
        std::cout << primes.at(i) << std::endl;
    }
    std::cout << std::endl;*/


    /*for(unsigned long i = 0; i < solutions.size(); i++) {
        std::cout << "x^2-" << composite%solutions[i].prime << "=0 mod " << solutions[i].prime << " x1 = " << solutions[i].x1 << std::endl;
    }*/

    /*for(unsigned int id = 0; id < threadCount; id++) {
        polyThreads.at(id)->stop();
    }*/

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
