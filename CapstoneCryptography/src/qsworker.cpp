#include <headers/qsworker.h>

QSWorker::QSWorker() :
    n(0),
    threadId(0),
    threadCount(0),
    primes( *(new std::vector<mpz_class>()) ),
    expVecRef( *(new std::map<mpz_class,row>()) ),
    kill(false),
    mutex(),
    currentRow(),
    pIndex(0)


{}

QSWorker::QSWorker(mpz_class num, std::map<mpz_class, row>* expVecRef, std::vector<mpz_class>* p, unsigned int id, unsigned int count) :
    n(num),
    threadId(id),
    threadCount(count),
    kill(false),
    currentRow(),
    primes(*p),
    pIndex(0),
    expVecRef(*expVecRef),
    mutex()
{
    std::cout << "thread " << threadId << " constructor: " << primes.size() << " prime numbers" << std::endl;
}

QSWorker::QSWorker(const QSWorker & other) :
    n(other.n),
    threadId(other.threadId),
    threadCount(other.threadCount),
    primes(other.primes),
    expVecRef(other.expVecRef),
    kill(other.kill),
    mutex(),
    currentRow(other.currentRow),
    pIndex(other.pIndex)
{}

QSWorker::~QSWorker() {

}

void QSWorker::stop() {
    kill = true;
}

void QSWorker::work(size_t index) {
    //std::cout << "in thread " << threadId << std::endl;
    pIndex = index;
    if(index == 0) {
        sleep(1);
        emit finished(threadId);
        return;
    }
    start();
}

void QSWorker::run() {

    //std::cout << "in thread " << threadId << ": prime count: " << primes.size() << std::endl;
/*
    lock.lockForRead();
    const mpz_class prime = primes.at(pIndex);
    const mpz_class B = primes.back();
    lock.unlock();

    std::pair<mpz_class, mpz_class> solution = solveQuadratic(prime);
    mpz_class x = sqrt(n);
    for(mpz_class x1 = solution.first; x1 < x+10*B; x1 += prime) {
        if(x1 < x) {
            continue;
        }
        //std::cout << "in qs: x1: " << x1.get_str() << std::endl;
        lock.lockForRead();
        row currentVector = expVecRef[x1];
        lock.unlock();

        currentVector.vec = currentVector.vec ^ (1 << pIndex);

        lock.lockForWrite();
        expVecRef[x1] = currentVector;
        lock.unlock();

        //std::cout << std::bitset<32>(currentVector.vec) << " " << pIndex << " " << x1.get_str() << std::endl;
    }

    if(solution.first != solution.second || pIndex == 0) { //one solution
        emit finished(threadId);
        return;
    }

    for(mpz_class x2 = solution.second; x2 < x+10*B; x2 += prime) {
        if(x2 < x) {
            continue;
        }
        //std::cout << "in qs: x2: " << x2.get_str() << std::endl;
        lock.lockForRead();
        row currentVector = expVecRef[x2];
        lock.unlock();

        currentVector.vec = currentVector.vec ^ (1 << pIndex);

        lock.lockForWrite();
        expVecRef[x2] = currentVector;
        lock.unlock();
        //std::cout << std::bitset<32>(currentVector.vec) << " " << pIndex << " " << x2.get_str() << std::endl;
    }

    emit finished(threadId);*/
}

/**
 * Solve x^2-n=0 (mod p) for x. n is the number to be factored
 * @brief QSWorker::solveQuadratic
 * @param p
 * @return
 */
std::pair<mpz_class, mpz_class> QSWorker::solveQuadratic(mpz_class p) {

     mpz_class m = n % p;
     p *= 4;

     for(mpz_class i = 0; i < p; i++) {
         if( (i*i-m) % p == 0 ) {
             return std::pair<mpz_class,mpz_class>(i,p-i);
         }
     }
     return std::pair<mpz_class,mpz_class>(0,0);
}
