#include <headers/dictionarycrack.h>

DictionaryCrack::DictionaryCrack(Hash* h, std::string file) {
	
	hashType = h;
    filename = file;

    digest = "";
    //load dictionary into vector
    std::ifstream f;
    try {

        f.open(filename.c_str());
        std::string word;
        while(getline(f, word)) {
            words.push_back(word);
        }
        f.close();

        //used for counting indices
        wordIndex = std::vector<std::vector<std::string>::iterator>();
        wordIndex.push_back(words.begin());

    } catch(int e) {
        f.close();
        std::cout << "error " << e << std::endl;
        std::cout << "File " << filename << " not found" << std::endl;
    }
}

QPointF DictionaryCrack::reverse() {
	
    plaintext = "";

	if(hashType == NULL) {
        return QPointF(-1,-1);
	}

    QElapsedTimer timer;
    long elapsed;
    timer.start();

    for(mpz_class i = 0; i < mpz_class(pow(words.size(),numWords)); i++) {

        //std::string guess = getWordCombo(i);
        std::string guess = getNextWord();
        hashType->plaintext = guess;

        int plaintextLength = verifyGuess();
        if(plaintextLength != 0) {
            elapsed = timer.elapsed();
            return QPointF(plaintextLength, elapsed);
        }

        if(capWords) {
            if(guess.size() > 0) {
                std::string temp = guess;
                if(temp[0] > 96 && temp[0] < 123) {
                    temp[0] = temp[0] - 32;
                    hashType->plaintext = temp;

                    int plaintextLength = verifyGuess();
                    if(plaintextLength != 0) {
                        elapsed = timer.elapsed();
                        return QPointF(plaintextLength, elapsed);
                    }
                }
            }
        }

        if(appendedDigits > 0) {
            for(unsigned int i = 0; i < (unsigned int)pow(10,appendedDigits); i++) {

                hashType->plaintext = guess + std::to_string(i);

                int plaintextLength = verifyGuess();
                if(plaintextLength != 0) {
                    elapsed = timer.elapsed();
                    return QPointF(plaintextLength, elapsed);
                }
            }
        }

        if(prependedDigits > 0) {
            for(unsigned int i = 0; i < (unsigned int)pow(10,prependedDigits); i++) {

                hashType->plaintext = std::to_string(i) + guess;

                int plaintextLength = verifyGuess();
                if(plaintextLength != 0) {
                    elapsed = timer.elapsed();
                    return QPointF(plaintextLength, elapsed);
                }
            }
        }
    }


    elapsed = timer.elapsed();
    return QPointF(0, elapsed);
}

unsigned int DictionaryCrack::verifyGuess() {
    hashType->compute();
    if(digest.compare(hashType->digest) == 0) {
        plaintext = hashType->plaintext;
        return plaintext.length();
    }
    return 0;
}

/**
 * Converts decimal number into combination of words based on the number of words in
 * the dictionary file.
 * @brief DictionaryCrack::getWordCombo
 * @param num number to convert
 * @return number converted to a string.
 */
std::string DictionaryCrack::getWordCombo(mpz_class num) {

    mpz_class base = words.size();
    if(base == 0) {
        return "Divide by zero!!!";
    }

    std::string result;
    while(num > 0) {
        mpz_class temp = (num % base);
        result += words.at(temp.get_ui());
        num /= base;
    }
    return result; //reverse string
}

std::string DictionaryCrack::getNextWord() {

    //find the words to combine
    std::string word = "";
    for(unsigned int i = 0; i < wordIndex.size(); i++) {
        word += *wordIndex.at(i);
    }

    //increment index
    bool carry = true;
    int index = 0;
    while(carry) {
        if(index > wordIndex.size() - 1) {
            wordIndex.push_back(words.begin());
        }
        if(wordIndex.at(index)+1 == words.end()) {
            wordIndex.at(index) = words.begin();
        } else {
            wordIndex.at(index)++;
            carry = false;
            break;
        }
        index++;
    }

    return word;
}

/*void DictionaryCrack::incrementWordIndex() {
    bool carry = true;
    int index = 0;
    while(carry) {
        if(index > wordIndices.size() - 1) {
            wordIndices.push_back(0);
        }
        if(wordIndices.at(index) == words.size()) {
            wordIndices.at(index) = 0;
        } else {
            wordIndices.at(index)++;
            carry = false;
            break;
        }
        index++;
    }

}*/

void DictionaryCrack::setOptions(unsigned int words, unsigned int endDigits,
                                 unsigned int preDigits, unsigned int symb,
                                 bool cap) {
    numWords = words;
    appendedDigits = endDigits;
    prependedDigits = preDigits;
    symbols = symb;
    capWords = cap;
}
