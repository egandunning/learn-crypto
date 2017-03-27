#include <headers/workerthreadcrack.h>

WorkerThreadCrack::WorkerThreadCrack(QObject *parent) : QThread(parent) {
    elapsed = -1;
    stop = false;
}

WorkerThreadCrack::~WorkerThreadCrack() {
    QMutexLocker locker(&mutex);
    delete c;
    stop = true;
}

void WorkerThreadCrack::work() {
    if(!isRunning()) {
        start();
    }
}

void WorkerThreadCrack::run() {
    QMutexLocker locker(&mutex);
    elapsed = c->reverse().y();
}

void WorkerThreadCrack::setCrackType(Crack* cr) {
    QMutexLocker locker(&mutex);
    c = cr;
}

Crack* WorkerThreadCrack::getCrack() {
    QMutexLocker locker(&mutex);
    return c;
}

long WorkerThreadCrack::getResult() {
    QMutexLocker locker(&mutex);
    return elapsed;
}
