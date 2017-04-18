#include <headers/bruteforcefactor.h>

BruteForceFactor::BruteForceFactor() {
    decreasing = false;
}

BruteForceFactor::BruteForceFactor(bool bigToSmall) {
    decreasing = bigToSmall;
}

/**
 * Trial division starting with 2.
 * @brief Factor::bruteForceFactor
 * @param composite number to factor
 * @return A point (number of digits, time to Factor(milliseconds))
 */
QPointF BruteForceFactor::factor(mpz_class composite) {

    QElapsedTimer timer;
    timer.start();

    mpz_class i, upperBound;
    upperBound = sqrt(composite);

    for(i = 2; i < upperBound; i++ ) {
        if(kill) {
            p1 = 0;
            p2 = 0;
            long elapsed = timer.elapsed();

            return QPointF(composite.get_str(10).length(), elapsed);
        }
        if(composite % i == 0) {
            p1 = i;
            p2 = composite / i;
            break;
        }
    }
    long elapsed = timer.elapsed();

    return QPointF(composite.get_str(10).length(), elapsed);
}


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
