#ifndef BRUTEFORCEFACTOR_H
#define BRUTEFORCEFACTOR_H

#include <headers/factor.h>

#include <QElapsedTimer>

class BruteForceFactor : public Factor {
public:
    BruteForceFactor();
    virtual QPointF factor(mpz_class) override;
};

#endif // BRUTEFORCEFACTOR_H

