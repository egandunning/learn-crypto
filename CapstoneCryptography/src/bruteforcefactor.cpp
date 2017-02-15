#include <headers/bruteforcefactor.h>

BruteForceFactor::BruteForceFactor() {
    decreasing = false;
}

BruteForceFactor::BruteForceFactor(bool bigToSmall) {
    decreasing = bigToSmall;
}

QPointF BruteForceFactor::factor(mpz_class composite) {

    if(decreasing) {
        return bruteForceFactorDecreasing(composite);
    }
    return bruteForceFactorIncreasing(composite);
}

/**
 * Trial division starting with 2.
 * @brief Factor::bruteForceFactor
 * @param composite number to factor
 * @return A point (number of digits, time to Factor(milliseconds))
 */
QPointF BruteForceFactor::bruteForceFactorIncreasing(mpz_class composite) {
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

    return QPointF(composite.get_str(10).length(), elapsed);
}
/**
 * Trial division starting with sqrt(composite)
 * @brief BruteForceFactor::bruteForceFactorDecreasing
 * @param composite number to factor
 * @return A point (number of digits, time to Factor(milliseconds))
 */
QPointF BruteForceFactor::bruteForceFactorDecreasing(mpz_class composite) {
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

    return QPointF(composite.get_str(10).length(), elapsed);
}
