#include <headers/bruteforcecrack.h>

//base conversion: http://stackoverflow.com/questions/8870121/c-template-for-conversion-between-decimal-and-arbitrary-base#8870154

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

	if(hashType == NULL) {
        return QPointF(-1,-1);
	}
	
    std::string plaintextGuess = "";
    int range = alphabet.length();

    //watch out for overflow errors here
    unsigned long n = (unsigned long)pow(range, charCount);
    if(n == 0) {
        std::cout << "Avoiding overflow error! Setting n to max value: " << std::numeric_limits<unsigned long>::max() << std::endl;
        n = std::numeric_limits<unsigned long>::max();
    }
    QElapsedTimer timer;
    long elapsed;
    timer.start();
    for(unsigned long i = 0; i < n; i++) {
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

void BruteForceCrack::setOptions(unsigned int words, unsigned int endDigits, unsigned int preDigits, unsigned int symb, bool cap) {
    std::cout << "Incorrect usage of crack class. This method is for DictionaryCrack." << std::endl;
}
