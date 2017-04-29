#include <headers/workerthreadgenerate.h>

WorkerThreadGenerate::WorkerThreadGenerate() : genData() {
    kill = false;
    crackAlg = 0;
    factorAlg = 0;
    hashType = 0;
}

WorkerThreadGenerate::~WorkerThreadGenerate() {
    /*if(isRunning()) {
        std::cout << "here" << std::endl;
        stop();
    }*/
    if(crackAlg != NULL) {
        delete crackAlg;
    }
    if(factorAlg != NULL) {
        delete factorAlg;
    }
    if(hashType != NULL) {
        delete hashType;
    }
}

void WorkerThreadGenerate::crackData(int begin, int ct, Hash* h, Crack* c) {

    beginChars = begin;
    count = ct;
    hashType = h;
    crackAlg = c;

    typeOfData = 0;
    if(!isRunning()) {
        start();
    }
}

void WorkerThreadGenerate::factorData(int begin, int count, Factor* f) {
    beginDigits = begin;
    countFactor = count;
    factorAlg = f;

    typeOfData = 1;
    if(!isRunning()) {
        start();
    }
}

void WorkerThreadGenerate::stop() {
    if(crackAlg != NULL) {
        crackAlg->stop();
    }
    if(factorAlg != NULL) {

    }
}

std::vector<QPointF> WorkerThreadGenerate::getResult() {
    QMutexLocker locker(&mutex);
    return dataPoints;
}

void WorkerThreadGenerate::run() {
    QMutexLocker locker(&mutex);
    if(genData == nullptr) {
        genData = new GenerateData();
    }
    connect(genData, SIGNAL(point(int)), this, SLOT(pointGenerated(int)));

    switch(typeOfData) {
    case 0:{
        std::vector<std::string> strings = GenerateData::plaintexts(beginChars, count);
        std::cout << "number of strings : " << strings.size() << std::endl;
        std::vector<std::string> digests = GenerateData::getHashes(strings, hashType);
        std::cout << "number of digests : " << digests.size() << std::endl;
        dataPoints = genData->crackMember(digests, crackAlg);
        break;}
    case 1:{
        std::vector<mpz_class> comps = GenerateData::composites(beginDigits, countFactor);
        dataPoints = genData->factorMember(comps, factorAlg);
        break;}
    }
}

void WorkerThreadGenerate::pointGenerated(int progress) {
    emit updateProgressBar(progress);
}

QString WorkerThreadGenerate::getFactorAlgName() {
    return factorAlg->name;
}

QString WorkerThreadGenerate::getCrackAlgName() {
    return crackAlg->name;
}

QString WorkerThreadGenerate::getHashAlgName() {
    return hashType->name;
}
