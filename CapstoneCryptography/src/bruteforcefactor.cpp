#include <headers/bruteforcefactor.h>

BruteForceFactor::BruteForceFactor() {
    name = "Brute force";
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
    upperBound = sqrt(composite) + 1;

	if(composite % 2 == 0) {
        p1 = i;
        p2 = composite / i;
    } else {

		for(i = 3; i < upperBound; i+=2 ) {
		    if(kill) {
		        p1 = 0;
		        p2 = 0;
		        long elapsed = timer.elapsed();

		        return QPointF(composite.get_str(10).length(), elapsed);
		    }
            if(composite % i == 0) { //i divides composite, so i is a factor.
		        p1 = i;
		        p2 = composite / i;
		        break;
		    }
		}
	}
	
    long elapsed = timer.elapsed();

    return QPointF(composite.get_str(10).length(), elapsed);
}
