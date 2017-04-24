#include <headers/qsworker.h>

QSWorker::QSWorker() :
    threadId(0),
    threadCount(0),
    kill(false),
    mutex()
{}

QSWorker::QSWorker(mpz_class num, mpz_class x, unsigned int id, unsigned int count) :
    threadId(id),
    threadCount(count),
    kill(false),
    mutex()
{}

QSWorker::QSWorker(const QSWorker & other) :
    threadId(other.threadId),
    threadCount(other.threadCount),
    output(other.output),
    kill(other.kill),
    mutex()
{}

QSWorker::~QSWorker() {

}

void QSWorker::stop() {
    kill = true;
}

void QSWorker::run() {

}
