#include <headers/bruteforcecrack.h>
#include <iostream>
//base conversion: http://stackoverflow.com/questions/8870121/c-template-for-conversion-between-decimal-and-arbitrary-base#8870154

/**
 * Set the desired hash method.
 * @brief BruteForceCrack::BruteForceCrack
 * @param h the hash method to use: MD5, SHA, etc.
 */
BruteForceCrack::BruteForceCrack(Hash h) {
    hashType = h;
}

/**
 * Reverses a hash using brute force. The idea is to count to
 * (alphabet length)^(password length) in base (alphabet length). This
 * ensures that every possible combination of the alphabet is guessed.
 * @brief BruteForceCrack::reverse
 * @param charCount user-specified password length
 * @return 1 if successful, 0 if unsuccessful.
 */
int BruteForceCrack::reverse(int charCount) {

    std::string plaintextGuess = "";
    int range = alphabet.length();

    int n = (int)pow(range, charCount);

    for(int i = 0; i < n; i++) {
        plaintextGuess = baseTenToBaseN(i, range);
        hashType.plaintext = plaintextGuess;
        hashType.compute();

        if(digest.compare(hashType.digest) == 0) {
            plaintext = plaintextGuess;
            return 1;
        }
    }
    return 0;
}

/**
 * Converts decimal number into given base.
 * @brief BruteForceCrack::baseTenToBaseN
 * @param num number to convert
 * @param base base to convert to.
 * @return number converted to given base.
 */
std::string BruteForceCrack::baseTenToBaseN(unsigned int num, unsigned int base) {

    if(base == 0) { //lazy fix to avoid divide by zero
        return "Divide by zero!!!";
    }

    std::string result;
    while(num) {
        result += alphabet.at(num % base);
        num /= base;
    }
    return std::string(result.rbegin(), result.rend());
}

void BruteForceCrack::setAlphabet(std::string alph) {
    alphabet = alph;
}

void BruteForceCrack::addToAlphabet(std::string alph) {
    alphabet += alph;
}

/**
 * Given min and max ascii values, create the alphabet with all ascii values
 * between the min and max. Used to quickly create an alphabet, not user friendly.
 */
void BruteForceCrack::createAlphabet(int min, int max) {
    for(int i = min; i < max; i++) {
        alphabet += (char)i;
    }
}

void BruteForceCrack::setDigest(QString d) {
    digest = d.toStdString();
}

QString BruteForceCrack::getDigest() {
    return QString::fromStdString(digest);
}

QString BruteForceCrack::getPlaintext() {
    return QString::fromStdString(plaintext);
}
