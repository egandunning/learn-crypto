#ifndef BRUTEFORCEFACTOR_H
#define BRUTEFORCEFACTOR_H

#include <headers/factor.h>

#include <QElapsedTimer>

class BruteForceFactor : public Factor {
public:
    BruteForceFactor();
    BruteForceFactor(bool);
    virtual QPointF factor(mpz_class) override;
private:
    bool decreasing;
    QPointF bruteForceFactorIncreasing(mpz_class);
    QPointF bruteForceFactorDecreasing(mpz_class);
};

#endif // BRUTEFORCEFACTOR_H

