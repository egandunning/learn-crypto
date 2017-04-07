#include <headers/bruteforcecrack.h>
#include <headers/md5.h>
#include <headers/pbkdf2.h>
#include <headers/sha512.h>
#include <QFuture>
#include <QThread>
#include <QtConcurrent/QtConcurrent>
#include <QtConcurrent/QtConcurrentRun>
#include <QtConcurrent/qtconcurrentrun.h>

//base conversion: http://stackoverflow.com/questions/8870121/c-template-for-conversion-between-decimal-and-arbitrary-base#8870154

//std::string foundValue;
int charCount;

int totalThreads;

std::string BruteForceCrack::incrementStringW(std::string in, std::string alpha, int increase){

    char z = alpha[alpha.size()-1];

    if(!in.compare("")){
        in += alpha[0];
        return in;
    }
    else if(in[in.length()-1] == z){
        in.resize(in.length()-1);
        in = incrementStringW(in, alpha, increase);
        in.append("a");
        return in;

    }
    else if(increase == 0){
        char r = in[in.length()-1];

        int i = alpha.find(r);

        r = alpha[ i + 1 ];

        in[in.length()-1] = r;
        return in;
    }
    else {
        return incrementStringW(in, alpha, increase -1);
    }
}

bool BruteForceCrack::worker(std::string begin, std::string end, Hash *whash, std::string d, std::string alpha){

    std::string plaintextGuess = begin;

    while(!finished) {
        if(kill) {
            finished = true;
            plaintext = "Cancelled";
            return 1;
        }
        whash->plaintext = plaintextGuess;

        whash->compute();

        if(d.compare(whash->digest) == 0) {
            //foundValue = plaintextGuess;
            plaintext = plaintextGuess;
            finished = true;
            break;
        }
        plaintextGuess = incrementStringW(plaintextGuess, alpha, totalThreads);


        if(plaintextGuess.compare(end) == 0){
            break;
        }
    }
    return 0;
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

    //foundValue = "";
    finished = false;

	if(hashType == NULL) {
        return QPointF(-1,-1);
	}

    QElapsedTimer timer;
    long elapsed;

    //Thread stuff starts here.
    int threads = QThread::idealThreadCount();
    //threads = 100;

    std::string a = "";
    char t = alphabet[0];
    a += t;

    QFuture<bool> temp;
    while(threads != 0){

        Hash* newH ;
        if(hashType->name == "MD5"){
            newH = new Md5();
        }
        else if(hashType->name == "PBKDF2"){
            newH = new Pbkdf2();
        }
        else{
            newH = new Sha512();
        }



        std::string b = "";
        temp = QtConcurrent::run(this, &BruteForceCrack::worker, a, b, newH ,digest, alphabet);



        //t.assign(1, temp);

        threads--;

        a = incrementString(a, alphabet);
    }

    timer.start();

    bool exitStatus = temp.result();

    elapsed = timer.elapsed();

    std::cout<<"BruteForceCrack::worker exited with code " << exitStatus <<std::endl;

    return QPointF(plaintext.size(), elapsed);

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

void BruteForceCrack::setOptions(unsigned int words, unsigned int endDigits, unsigned int preDigits, bool symb, bool cap, bool complete) {
    std::cout << "Incorrect usage of crack class. This method is for DictionaryCrack." << std::endl;
}

/**
 * Increments a stirng by the next lowercase character.
 * @brief BruteForceCrack::incrementString
 * @param in
 * @return
 */
std::string BruteForceCrack::incrementString(std::string in, std::string alpha){

    char z = alpha[alpha.size()-1];

    if(!in.compare("")){
        return in.append("a");
    }
    else if(in[in.length()-1] == z){
        in.resize(in.length()-1);
        in = incrementString(in, alpha);
        in.append("a");
        return in;

    }
    else{
        char r = in[in.length()-1];

        int i = alpha.find(r);

        r = alpha[ i + 1 ];

        in[in.length()-1] = r;
        return in;
    }
}





