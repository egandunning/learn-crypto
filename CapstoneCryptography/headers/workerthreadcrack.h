#ifndef WORKERTHREADCRACK_H
#define WORKERTHREADCRACK_H

#include <QThread>
#include <QMutex>
#include <QMutexLocker>

#include <iostream>

#include <headers/crack.h>

class WorkerThreadCrack : public QThread {

    Q_OBJECT;

public:
    WorkerThreadCrack(QObject *parent = 0);
    ~WorkerThreadCrack();

    void work();

    void setCrackType(Crack* c);
    long getResult();
    Crack* getCrack();

signals:
    void finished(Crack* result);

private:
    void run();
    QMutex mutex;
    long elapsed;
    bool stop;
    Crack* c;
};

#endif // WORKERTHREADCRACK_H

