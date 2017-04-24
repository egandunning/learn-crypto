#ifndef QSWORKER_H
#define QSWORKER_H

#include <QThread>
#include <QMutex>
#include <QMutexLocker>

#include <vector>
#include <utility>
#include <iostream>

#include <gmpxx.h>

class QSWorker : public QThread {

    Q_OBJECT

public:
    QSWorker();
    QSWorker(mpz_class,mpz_class,unsigned int,unsigned int);
    QSWorker(const QSWorker&);
    ~QSWorker();
    void stop();
    std::vector<std::pair<mpz_class,mpz_class>> getOutput();

    const mpz_class n;
    const mpz_class x0;
    const unsigned int threadId;
    const unsigned int threadCount;
    std::vector<std::pair<mpz_class,mpz_class>> output;
    bool kill;
    QMutex mutex;

private:
    void run();
};

#endif // QSWORKER_H

