#ifndef QSWORKER_H
#define QSWORKER_H

#include <QThread>
#include <QMutex>
#include <QMutexLocker>
#include <QReadWriteLock>

#include <vector>
#include <utility>
#include <iostream>
#include <map>

#include <gmpxx.h>
#include <headers/row.h>

class QSWorker : public QThread {

    Q_OBJECT

public:

    QSWorker();
    QSWorker(mpz_class, std::map<mpz_class, row>*, std::vector<mpz_class>*, unsigned int, unsigned int);
    QSWorker(const QSWorker&);
    ~QSWorker();
    void stop();
    void work(size_t);

    std::map<mpz_class,row> getOutput();

    const mpz_class n;
    const unsigned int threadId;
    const unsigned int threadCount;
    std::vector<mpz_class>& primes;
    std::vector<std::pair<mpz_class,mpz_class>> output;
    std::map<mpz_class, row>& expVecRef;
    bool kill;
    QMutex mutex;
    QReadWriteLock lock;
    row currentRow;
    size_t pIndex;

private:

    void run();

    std::pair<mpz_class, mpz_class> solveQuadratic(mpz_class p);

signals:

    void finished(unsigned int);


};


#endif // QSWORKER_H

