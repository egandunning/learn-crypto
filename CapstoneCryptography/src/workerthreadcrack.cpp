#include <headers/workerthreadcrack.h>

WorkerThreadCrack::WorkerThreadCrack(QObject *parent) : QThread(parent) {
    elapsed = -1;
    kill = false;
}

WorkerThreadCrack::~WorkerThreadCrack() {
    QMutexLocker locker(&mutex);
    delete c;
    kill = true;
    c->stop();
}

void WorkerThreadCrack::work() {
    if(!isRunning()) {
        start();
    }
}

void WorkerThreadCrack::stop() {
    c->stop();
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
