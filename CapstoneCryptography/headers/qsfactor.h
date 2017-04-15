#ifndef QSFACTOR
#define QSFACTOR

#include <headers/factor.h>

class QSFactor : public Factor {

    QSFactor();
    ~QSFactor();

    QPointF reverse(mpz_class);

private:
    unsigned long B;
};

#endif // QSFACTOR

