#ifndef QSPOLYWORKER_H
#define QSPOLYWORKER_H

#include <QThread>
#include <QMutex>
#include <QMutexLocker>

#include <vector>
#include <utility>

#include <gmpxx.h>

class QSPolyWorker : public QThread {

    Q_OBJECT

public:
    QSPolyWorker(mpz_class,mpz_class,unsigned int,unsigned int);
    ~QSPolyWorker();
    void stop();
    std::vector<std::pair<mpz_class,mpz_class>> getOutput();

private:
    void run();
    const mpz_class n;
    const mpz_class x0;
    const unsigned int threadId;
    const unsigned int threadCount;
    std::vector<std::pair<mpz_class,mpz_class>> output;
    bool kill;
};

#endif // QSPOLYWORKER_H

