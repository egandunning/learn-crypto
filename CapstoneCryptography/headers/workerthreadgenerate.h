#ifndef WORKERTHREADGENERATE
#define WORKERTHREADGENERATE

#include <QThread>
#include <QMutex>
#include <QMutexLocker>

#include <iostream>

#include <headers/generatedata.h>

class WorkerThreadGenerate : public QThread {

    Q_OBJECT;

public:
    WorkerThreadGenerate();
    ~WorkerThreadGenerate();

    void crackData(int, int, Hash*, Crack*);
    void factorData(int, int, Factor*);
    void stop();
    std::vector<QPointF> getResult();
    QString getFactorAlgName();
    QString getCrackAlgName();
    QString getHashAlgName();

signals:
    void finished(std::vector<QPointF>);

private:
    void run();
    QMutex mutex;
    bool kill;
    int typeOfData = 0;

    //vars for crack data
    int beginChars;
    int count;
    Hash* hashType;
    Crack* crackAlg;
    std::vector<QPointF> dataPoints;

    //vars for factor data
    int beginDigits;
    int countFactor;
    Factor* factorAlg;

};

#endif // WORKERTHREADGENERATE

