#ifndef WORKERTHREADFACTOR_H
#define WORKERTHREADFACTOR_H

#include <QThread>
#include <QMutex>
#include <QMutexLocker>

#include <headers/factor.h>

#include <gmpxx.h>

class WorkerThreadFactor : public QThread {

    Q_OBJECT;

public:
    WorkerThreadFactor(QObject *parent = 0);
    ~WorkerThreadFactor();

    void work();
    void stop();

    void setFactor(Factor* factor, mpz_class num);
    long getResult();
    Factor* getFactor();

signals:
    void finished(Factor* result);

private:
    void run();
    QMutex mutex;
    long elapsed;
    Factor* f;
    mpz_class number;
};

#endif // WORKERTHREADFACTOR_H

