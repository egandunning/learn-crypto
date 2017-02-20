#include <headers/graphing.h>

Graphing::Graphing() {

}

/**
 * @brief Graphing::calculate
 * Simple exp regression. y = a^x
 * @param points
 * @return
 */
std::pair<double,double> Graphing::calculate(std::vector<QPoint> points) {

    std::vector<double> constants(points.size());
    for(unsigned int i = 0; i < points.size(); i++) {
        double x = points.at(i).x;
        if(x == 0) {
            std::cout << "div by zero. exiting Graphing::calculate()." << std::endl;
            return {0,0};
        }
        double y = points.at(i).y;
        constants.push_back(pow(y, 1/x));
    }
}
