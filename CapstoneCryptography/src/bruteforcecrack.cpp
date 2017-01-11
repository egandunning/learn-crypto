#include <headers/bruteforcecrack.h>

#include <iostream>

BruteForceCrack::BruteForceCrack(Hash h) {
    hashType = h;
}

int BruteForceCrack::reverse(int charCount) {
    std::string plaintextGuess = "";

    for(int i = 0; i < charCount; i++) {
        plaintextGuess = plaintextGuess + 'a';

        for(int j = 0; j < plaintextGuess.size(); j++) {
            for(int k = charRangeMin; k < charRangeMax; k++) {
                plaintextGuess.replace(j, 1, 1, (char)k);
                std::cout << plaintextGuess << std::endl;
                hashType.plaintext = plaintextGuess;
                hashType.compute();

                if(digest.compare(hashType.digest) == 0) {
                    plaintext = plaintextGuess;
                    return 1;
                }
            }
        }
    }

    return 0;
}
