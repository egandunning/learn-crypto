#ifndef REGRESSION_H
#define REGRESSION_H

#include <vector>
#include <utility>
#include <QPoint>

class Regression {
public:
    Regression();
    std::pair<double> calculate(std::vector<QPoint>);
};

#endif // REGRESSION_H

