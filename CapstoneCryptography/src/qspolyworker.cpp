#include <headers/qspolyworker.h>

QSPolyWorker::QSPolyWorker() :
    n(0),
    x0(0),
    threadId(0),
    threadCount(0),
    output(),
    kill(false),
    mutex()
{}

QSPolyWorker::QSPolyWorker(mpz_class num, mpz_class x, unsigned int id, unsigned int count) :
    n(num),
    x0(x),
    threadId(id),
    threadCount(count),
    output(),
    kill(false),
    mutex()
{}

QSPolyWorker::QSPolyWorker(const QSPolyWorker & other) :
    n(other.n),
    x0(other.x0),
    threadId(other.threadId),
    threadCount(other.threadCount),
    output(other.output),
    kill(other.kill),
    mutex()
{}

QSPolyWorker::~QSPolyWorker() {

}

void QSPolyWorker::stop() {
    kill = true;
}

/**
 * @brief QSPolyWorker::getOutput returns the current progress in the
 * output vector, and clears the output vector
 * @return
 */
std::vector<std::pair<mpz_class,mpz_class>> QSPolyWorker::getOutput() {
    QMutexLocker locker(&mutex);
    if(output.size() == 0) {
        return output;
    }
    std::vector<std::pair<mpz_class,mpz_class>> temp = output;
    std::cout << "inside QSPolyWorker::getOutput() " << threadId << std::endl;
    output.clear();

    return temp;
}

void QSPolyWorker::run() {
    //QMutexLocker locker(&mutex);
    std::cout << "thread " << threadId << " running." << std::endl;
    unsigned int i = threadId;
    while(!kill) {
        mpz_class x = x0+i;
        mutex.lock();
        output.push_back(std::pair<mpz_class,mpz_class>(x*x-n, x));
        mutex.unlock();
        //std::cout << x << std::endl;
        i+=threadCount;
    }
}
