#include <headers/bruteforcecrack.h>
#include <QFuture>
#include <QtConcurrent/QtConcurrent>
#include <QtConcurrent/QtConcurrentRun>
#include <QtConcurrent/qtconcurrentrun.h>

//base conversion: http://stackoverflow.com/questions/8870121/c-template-for-conversion-between-decimal-and-arbitrary-base#8870154

unsigned long n;
unsigned long N;

Hash* HASH;
std::string ALPHABET;
std::string DIGEST;
std::string PLAINTEXT;
int CHARCOUNT;
/**
 * Set the desired hash method.
 * @brief BruteForceCrack::BruteForceCrack
 * @param h the hash method to use: MD5, SHA, etc.
 */
BruteForceCrack::BruteForceCrack(Hash* h, std::string alph, int chCount) {
    hashType = h;
    HASH = h;
    alphabet = alph;
    ALPHABET = alph;
    charCount = chCount;
    CHARCOUNT = chCount;
    DIGEST = digest;
    PLAINTEXT = plaintext;

}

QPointF BruteForceCrack::bruteLoopRunSmall(){

    std::string plaintextGuess = "";
    int range = alphabet.length();

    QElapsedTimer timer;
    long elapsed;
    timer.start();
    for(unsigned long i = 0; i < n/2; i++) {
        plaintextGuess = baseTenToBaseN(i, range);
        hashType->plaintext = plaintextGuess;

        hashType->compute();

        if(digest.compare(hashType->digest) == 0) {
            plaintext = plaintextGuess;
            elapsed = timer.elapsed();
            return QPointF(plaintext.length(), elapsed);
        }
    }

    elapsed = timer.elapsed();

    return QPointF(charCount, elapsed);

}

QPointF BruteForceCrack::bruteLoopRunBig(){

    std::string plaintextGuess = "";
    int range = ALPHABET.length();

    QElapsedTimer timer;
    long elapsed;
    timer.start();
    for(unsigned long i = N; i >= N/2; i--) {
        plaintextGuess = baseTenToBaseN(i, range);
        HASH->plaintext = plaintextGuess;

        HASH->compute();

        if(DIGEST.compare(HASH->digest) == 0) {
            PLAINTEXT = plaintextGuess;
            elapsed = timer.elapsed();
            return QPointF(PLAINTEXT.length(), elapsed);
        }
    }

    elapsed = timer.elapsed();

    return QPointF(charCount, elapsed);
}

/**
 * Reverses a hash using brute force. The idea is to count to
 * (alphabet length)^(password length) in base (alphabet length). This
 * ensures that every possible combination of the alphabet is guessed.
 * @brief BruteForceCrack::reverse
 * @param charCount user-specified password length
 * @return length,time pair if successful, max length,time if unsuccessful.
 */
QPointF BruteForceCrack::reverse() {

    plaintext = "";

	if(hashType == NULL) {
        return QPointF(-1,-1);
	}

    int range = alphabet.length();

    //watch out for overflow errors here
    n = (unsigned long)pow(range, charCount);
    if(n == 0) {
        std::cout << "Avoiding overflow error! Setting n to max value: " << std::numeric_limits<unsigned long>::max() << std::endl;
        n = std::numeric_limits<unsigned long>::max();
    }
    N = n;



    //Thread initialization
    QFuture<QPointF> small = QtConcurrent::run(this, &BruteForceCrack::bruteLoopRunSmall);
    QFuture<QPointF> big = QtConcurrent::run(this, &BruteForceCrack::bruteLoopRunBig);

    //Busy wait
    while(!big.isFinished() || !small.isFinished());

    if(small.isFinished()){

        std::cout<<"SMALL"<<std::endl;
    }
    else if(big.isFinished()){
        std::cout<<"BIG"<<std::endl;
    }

    //End both of the threads
    small.cancel();
    big.cancel();

    if(small.isFinished()){
        return small.result();
    }
    else{
        return big.result();
    }



}

/**
 * Converts decimal number into given base.
 * @brief BruteForceCrack::baseTenToBaseN
 * @param num number to convert
 * @param base base to convert to.
 * @return number converted to given base.
 */
std::string BruteForceCrack::baseTenToBaseN(unsigned long num, unsigned int base) {

    if(base == 0) { //lazy fix to avoid divide by zero
        return "Divide by zero!!!";
    }

    std::string result;
    while(num) {
        result += alphabet.at(num % base);
        num /= base;
    }
    return std::string(result.rbegin(), result.rend()); //reverse string
}

void BruteForceCrack::setOptions(unsigned int words, unsigned int endDigits, unsigned int preDigits, unsigned int symb, unsigned int cap) {
    std::cout << "Incorrect usage of crack class. This method is for DictionaryCrack." << std::endl;
}
