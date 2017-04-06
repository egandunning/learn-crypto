#include <headers/workerthreadfactor.h>

WorkerThreadFactor::WorkerThreadFactor(QObject *parent) : QThread(parent) {
    elapsed = -1;
    number = 0;
    f=0;
}

WorkerThreadFactor::~WorkerThreadFactor() {
    QMutexLocker locker(&mutex);
    if(f != NULL) {
        delete f;
    }
}

void WorkerThreadFactor::work() {
    if(!isRunning()) {
        start();
    }
}

void WorkerThreadFactor::stop() {
    if(isRunning()) {
        f->stop();
    }
}

void WorkerThreadFactor::run() {
    QMutexLocker locker(&mutex);
    elapsed = f->factor(number).y();
}

void WorkerThreadFactor::setFactor(Factor* factor, mpz_class num) {
    QMutexLocker locker(&mutex);
    f = factor;
    number = num;
}

Factor* WorkerThreadFactor::getFactor() {
    QMutexLocker locker(&mutex);
    return f;
}

long WorkerThreadFactor::getResult() {
    QMutexLocker locker(&mutex);
    return elapsed;
}

