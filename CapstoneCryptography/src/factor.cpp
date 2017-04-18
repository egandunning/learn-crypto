#include <headers/factor.h>

Factor::Factor() :
    p1(0),
    p2(0),
    threadCount(1)
{}

mpz_class Factor::getPrime1() {
    return p1;
}

mpz_class Factor::getPrime2() {
    return p2;
}

QPointF Factor::factor(mpz_class) {
    std::cout << "Incorrect usage of Factor. Needs \"Crack* c = new X\" where X is a subclass of Crack." << std::endl;
    return QPointF(-1,-1);
}

void Factor::stop() {
    kill = true;
}
