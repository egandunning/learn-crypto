#include "headers/primefactorization.h"

PrimeFactorization::PrimeFactorization() {
	
}

/**
 * Trial division starting with 2.
 * @brief PrimeFactorization::bruteForceFactor
 * @param composite
 * @return A point (number of digits, time to factor(milliseconds))
 */
QPointF* PrimeFactorization::bruteForceFactor(mpz_class composite) {
	mpz_class i, upperBound;
    upperBound = sqrt(composite);

    QElapsedTimer timer;
    timer.start();
	for(i = 2; i < upperBound; i++ ) {
		if(composite % i == 0) {
			p1 = i;
			p2 = composite / i;
            break;
		}
	}
    long elapsed = timer.elapsed();

    return new QPointF(composite.get_str(10).length(), elapsed);
}

/**
 * Trial division starting at sqrt(n)
 * @brief PrimeFactorization::bruteForceFactor2
 * @param composite
 * @return
 */
QPointF* PrimeFactorization::bruteForceFactor2(mpz_class composite) {
    mpz_class i, upperBound;
    upperBound = sqrt(composite);

    QElapsedTimer timer;
    timer.start();
    for(i = upperBound; i > 2; i-- ) {
        if(composite % i == 0) {
            p1 = i;
            p2 = composite / i;
            break;
        }
    }
    long elapsed = timer.elapsed();

    return new QPointF(composite.get_str(10).length(), elapsed);
}

QPointF* PrimeFactorization::quadraticSieve(mpz_class composite) {

}

