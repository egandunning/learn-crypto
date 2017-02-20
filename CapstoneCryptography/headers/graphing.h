#ifndef REGRESSION_H
#define REGRESSION_H

#include <vector>
#include <utility>
#include <cmath>
#include <QPoint>

class Graphing {
public:
    Graphing();
    std::pair<double,double> calculate(std::vector<QPoint>);
};

#endif // REGRESSION_H

