#ifndef BRUTEFORCEFACTOR_H
#define BRUTEFORCEFACTOR_H

#include <headers/factor.h>

class BruteForceFactor : public Factor {
public:
    BruteForceFactor(bool=false);
    virtual QPointF factor(mpz_class) override;
private:
    bool decreasing;
    QPointF bruteForceFactorIncreasing(mpz_class);
    QPointF bruteForceFactorDecreasing(mpz_class);
};

#endif // BRUTEFORCEFACTOR_H

