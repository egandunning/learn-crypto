#include <headers/bruteforcecrack.h>
#include <QFuture>
#include <QThread>
#include <QtConcurrent/QtConcurrent>
#include <QtConcurrent/QtConcurrentRun>
#include <QtConcurrent/qtconcurrentrun.h>

//base conversion: http://stackoverflow.com/questions/8870121/c-template-for-conversion-between-decimal-and-arbitrary-base#8870154

std::string foundValue;
bool finished;

static std::string incrementStringW(std::string in){

    char z = 'z';

    if(!in.compare("")){
        return in.append("a");
    }
    else if(in[in.length()-1] == z){
        in.resize(in.length()-1);
        in = ::incrementStringW(in);
        in.append("a");
        return in;

    }
    else{
        char r = in[in.length()-1] +1;
        in[in.length()-1] = r;
        return in;
    }
}

static void worker(std::string begin, std::string end, Hash* whash, std::string d){

    std::string plaintextGuess = begin;

    bool check = true;

    while(check) {
        whash->plaintext = plaintextGuess;

        whash->compute();

        if(d.compare(whash->digest) == 0) {
            foundValue = plaintextGuess;
            finished = true;
        }
        plaintextGuess = incrementStringW(plaintextGuess);
        std::cout<<plaintextGuess<<std::endl;

        if(plaintextGuess.compare(end) == 0){
            break;
        }
    }
}



/**
 * Set the desired hash method.
 * @brief BruteForceCrack::BruteForceCrack
 * @param h the hash method to use: MD5, SHA, etc.
 */
BruteForceCrack::BruteForceCrack(Hash* h, std::string alph, int chCount) {

    hashType = h;
    alphabet = alph;
    charCount = chCount;

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

    foundValue = "";
    finished = false;

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

    std::string plaintextGuess = begin;

    QElapsedTimer timer;
    long elapsed;

    //Thread stuff starts here.
    int threads = QThread::idealThreadCount();

    std::vector<QFuture<void>> t;

    while(threads != 0){

        std::string a = "a";
        std::string b = "aaaaaaaaaaa";

        QFuture<void> temp = QtConcurrent::run(::worker, a, b, hashType ,digest);

        t.assign(1, temp);

        threads--;
    }

    timer.start();

    while(!finished);


    elapsed = timer.elapsed();

    return QPointF(charCount, elapsed);

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

/**
 * Increments a stirng by the next lowercase character.
 * @brief BruteForceCrack::incrementString
 * @param in
 * @return
 */
std::string BruteForceCrack::incrementString(std::string in){

    char z = 'z';

    if(!in.compare("")){
        return in.append("a");
    }
    else if(in[in.length()-1] == z){
        in.resize(in.length()-1);
        in = BruteForceCrack::incrementString(in);
        in.append("a");
        return in;

    }
    else{
        char r = in[in.length()-1] +1;
        in[in.length()-1] = r;
        return in;
    }
}

void BruteForceCrack::setOptions(unsigned int words, unsigned int endDigits, unsigned int preDigits, unsigned int symb, unsigned int cap) {
    std::cout << "Incorrect usage of crack class. This method is for DictionaryCrack." << std::endl;
}



