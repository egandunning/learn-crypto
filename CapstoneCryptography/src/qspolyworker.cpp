#include <headers/qspolyworker.h>

QSPolyWorker::QSPolyWorker(mpz_class num, mpz_class x, unsigned int id, unsigned int count) :
    n(num),
    x0(x),
    threadId(id),
    threadCount(count),
    output(),
    kill(false)
{}

QSPolyWorker::~QSPolyWorker() {

}

void QSPolyWorker::stop() {
    kill = true;
}

std::vector<std::pair<mpz_class,mpz_class>> QSPolyWorker::getOutput() {
    return output;
}

void QSPolyWorker::run() {

    unsigned int i = threadId;
    while(!kill) {
        mpz_class x = x0+i;
        output.push_back(std::pair<mpz_class,mpz_class>(x*x-n, x));
        i+=threadCount;
    }
}
