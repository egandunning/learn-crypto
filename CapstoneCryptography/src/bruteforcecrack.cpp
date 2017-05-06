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

/**
 * @brief BruteForceCrack::worker
 * @param begin
 * @param end
 * @param whash
 * @param d
 * @param alpha
 * @return
 *
 * Worker method that takes a string where to begin, and where to end, and a selected hash and it increments the recommended ammount of times,
 * determined by the variable threadCount. Continues to search for the answer until the global boolean finished is marked true either by the worker
 * or by another instance.
 *
 * When found the solution is put in plaintext, which is then returned to the view.
 *
 */
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
        for(unsigned int i = 0; i < threadCount; i++) {
            plaintextGuess = incrementString(plaintextGuess, alpha);
        }


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
    name = "Brute force";
    threadCount = QThread::idealThreadCount();
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

    //threads = 100;


    std::string a = "";
    char t = alphabet[0];
    a += t;

    QFuture<bool> temp;
    //while(threads != 0){
    for(unsigned int i = 0; i < threadCount; i++) {
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
 * Increments a stirng by the next lowercase character. Takes into account the given alphabet and when to add an extra character.
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





