#include <headers/factor.h>

/**
 * @brief Factor::Factor
 * @param composite
 * @return
 *//*
QPointF Factor::factor(mpz_class composite) {
    p1 = 0;
    p2 = 0;
    switch(algorithm) {
    case 0:
        return bruteForceFactor(composite);
        break;
    case 1:
        return bruteForceFactor2(composite);
        break;
    //default:
      //  return quadraticSieveFactor(composite);
    }
}*/

/**
 * Trial division starting with 2.
 * @brief Factor::bruteForceFactor
 * @param composite
 * @return A point (number of digits, time to Factor(milliseconds))
 *//*
QPointF* Factor::bruteForceFactor(mpz_class composite) {
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
}*/

/**
 * Trial division starting at sqrt(n)
 * @brief Factor::bruteForceFactor2
 * @param composite
 * @return
 *//*
QPointF* Factor::bruteForceFactor2(mpz_class composite) {
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
}*/

/**
 * @brief Factor::quadraticSieveFactor
 * @param composite
 * @return
 *//*
QPointF* Factor::quadraticSieveFactor(mpz_class composite) {

}*/

