#ifndef ROW_H
#define ROW_H

#include <gmpxx.h>
#include <vector>

class row {

public:

    row() :
        vec(0),
        xVals()
    {}

    long vec;
    std::vector<mpz_class> xVals;

};

#endif // ROW_H

