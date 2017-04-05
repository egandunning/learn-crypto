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

    //symbol replacement
    symbolConversion[0].first = 's';
    symbolConversion[0].second = '$';
    symbolConversion[1].first = 'S';
    symbolConversion[1].second = '$';

    symbolConversion[2].first = 'e';
    symbolConversion[2].second = '3';
    symbolConversion[3].first = 'E';
    symbolConversion[3].second = '3';

    symbolConversion[4].first = 'l';
    symbolConversion[4].second = '1';
    symbolConversion[5].first = 'L';
    symbolConversion[5].second = '1';

    symbolConversion[6].first = 't';
    symbolConversion[6].second = '7';
    symbolConversion[7].first = 'T';
    symbolConversion[7].second = '7';

    symbolConversion[8].first = 'o';
    symbolConversion[8].second = '0';
    symbolConversion[9].first = 'O';
    symbolConversion[9].second = '0';
}

QPointF DictionaryCrack::reverse() {
	
    plaintext = "";

	if(hashType == NULL) {
        return QPointF(-1,-1);
	}

    QElapsedTimer timer;
    long elapsed;
    timer.start();

    for(mpz_class i = 0; i < mpz_class(pow(words.size(), numWords)); i++) {

        //std::string guess = getWordCombo(i);
        std::string guess = getNextWord();
        hashType->plaintext = guess;

        int plaintextLength = verifyGuess();
        if(plaintextLength != 0) {
            elapsed = timer.elapsed();
            return QPointF(plaintextLength, elapsed);
        }

        if(symbols) {
            std::string temp = guess;
            for(unsigned int i = 0; i < temp.size(); i++) {
                for(unsigned int j = 0; j < 10; j++) {
                    if(temp[i] == symbolConversion[j].first) {
                        temp[i] = symbolConversion[j].second;
                        break;
                    }
                }
                hashType->plaintext = temp;

                int plaintextLength = verifyGuess();
                if(plaintextLength != 0) {
                    elapsed = timer.elapsed();
                    return QPointF(plaintextLength, elapsed);
                }

            }
        }

        if(capWords) {
            if(guess.size() > 0) {
                std::string temp = guess;
                //if first char of temp is lowercase
                if(temp[0] > 96 && temp[0] < 123) {
                    //convert to uppercase
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

void DictionaryCrack::setOptions(unsigned int words, unsigned int endDigits,
                                 unsigned int preDigits, bool symb,
                                 bool cap) {
    numWords = words;
    appendedDigits = endDigits;
    prependedDigits = preDigits;
    symbols = symb;
    capWords = cap;
}
