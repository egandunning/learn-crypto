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
    std::cout << "B=" << B << std::endl;

    mpz_class x = sqrt(composite) + 1;
    /*threadCount = 4;
    for(unsigned int id = 0; id < threadCount; id++) {
        //create and start threads
        polyThreads.push_back(new QSPolyWorker(composite, x, id, threadCount));
        polyThreads.at(id)->start();
    }*/
B = 14;

    //generate primes less than B
    GeneratePrimes gen = GeneratePrimes(0,B+1);
    gen.generate();
    std::vector<long> primes = gen.getPrimes();

    std::vector<solution> factorBase;
    for(unsigned long i = 0; i < primes.size(); i++) {

        //eq. to solve: Q(i) = (ceil(sqrt(n))+i)^2-n = i^2 + bi + c = 0 (mod p)

        //solve eq. for powers of primes
        mpz_class c = 4 * composite;
        for(int power = 1; power <= 4; power++) {

            mpz_class m = pow(primes.at(i),power);
            mpz_class x1 = solveQuadraticModN(c, m);

            std::cout << m.get_str() << " " << x1.get_str() << std::endl;

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


    for(size_t i = 0; i < factorBase.size(); i++) {
        solution s = factorBase[i];
        std::cout << std::setw(5) << primes.at(s.primeIndex) << "^" << s.power
                  << std::setw(3) << " x1: "
                  << std::setw(5) << s.x1.get_str()
                  << std::setw(3) << " x2: "
                  << std::setw(5) << s.x2.get_str() << std::endl;
    }

    // ^--- complete!

    std::list<std::pair<long,mpz_class>> expVectors;

    for(mpz_class i = 0; i < 10; i++) {
        mpz_class Q = (x+i)*(x+i) - composite;
        mpz_class QCopy = Q;
        long vec = 0;
        for(int index = factorBase.size()-1; index >= 0; index--) {
            mpz_class temp = i % factorBase.at(index).modulus;
            if(temp == factorBase.at(index).x1 || temp == factorBase.at(index).x2) {
                vec = vec ^ (1 << factorBase.at(index).primeIndex);
                if(QCopy % factorBase.at(index).modulus == 0) {
                    QCopy /= factorBase.at(index).modulus;
                }

                std::cout << "\t" << Q.get_str() << " -> " << QCopy.get_str() << " " << factorBase.at(index).modulus << std::endl;
            }
        }
        std::cout << QCopy.get_str() << std::endl;
        if(QCopy == 1) {
            expVectors.push_back(std::pair<long,mpz_class>(vec,Q));
        }
    }


    expVectors.sort();

    std::cout << "sorted vectors:" << std::endl;
    for(std::list<std::pair<long,mpz_class>>::iterator it = expVectors.begin(); it != expVectors.end(); it++) {
        std::cout << std::bitset<64>(it->first) << " " << it->second << std::endl;
    }

    //"psuedo-gaussian elimination"
    long index = 1;
    for(std::list<std::pair<long,mpz_class>>::iterator it = expVectors.begin(); it != expVectors.end(); it++) {

        while(it->first > index) {
            index = index << 1;
        }

        std::list<std::pair<long,mpz_class>>::iterator it2 = it;
        it2++;
        for(; it2 != expVectors.end(); it2++) {
            if(it2->first <= index) {
                it2->first = it2->first ^ it->first; //addition mod 2
                it2->second = it2->second * it->second;

            }
        }
    }


    std::cout << std::endl;
    mpz_class square = 0;
    for(std::list<std::pair<long,mpz_class>>::iterator it = expVectors.begin(); it != expVectors.end(); it++) {
        if(it->first == 0) { //we've got a square
            std::cout << it->second.get_str() << std::endl;

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
