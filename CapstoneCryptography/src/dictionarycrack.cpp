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

    symbolConversion[1].first = 'e';
    symbolConversion[1].second = '3';

    symbolConversion[2].first = 'l';
    symbolConversion[2].second = '1';

    symbolConversion[3].first = 't';
    symbolConversion[3].second = '7';

    symbolConversion[4].first = 'o';
    symbolConversion[4].second = '0';

    symbolConversion[5].first = 'h';
    symbolConversion[5].second = '#';

    symbolConversion[6].first = 'i';
    symbolConversion[6].second = '!';

    symbolConversion[7].first = 'b';
    symbolConversion[7].second = '8';

    symbolConversion[8].first = 'a';
    symbolConversion[8].second = '@';

    symbolConversion[9].first = 'S';
    symbolConversion[9].second = '$';

    symbolArraySize = 10;
}

/**
 * Return true if binStr only contains 1s
 * @brief allOnes
 * @param binStr
 * @return
 */
bool allOnes(std::vector<char> binStr) {
    for(std::vector<char>::iterator it = binStr.begin(); it != binStr.end(); it++) {
        if(*it != '1') {
            return false;
        }
    }
    return true;
}

std::vector<char> incrementBinString(std::vector<char> binStr) {
    bool carry = false;
    for(int i = binStr.size()-1; i != -1; i--) {
        if(binStr[i] == '0') {
            binStr[i] = '1';
            if(!carry) {
                return binStr;
            }
            carry = false;
        } else {
            binStr[i] = '0';
            carry == true;
        }
    }
    if(carry) {
        std::vector<char> temp = std::vector<char>(binStr.rbegin(), binStr.rend());
        binStr.clear();
        binStr.push_back('1');
        while(!temp.empty()) {
            binStr.push_back(temp.back());
            temp.pop_back();
        }
    }
    return binStr;
}

QPointF DictionaryCrack::reverse() {
	
    plaintext = "";

	if(hashType == NULL) {
        return QPointF(-1,-1);
	}

    QElapsedTimer timer;
    long elapsed;
    timer.start();

    if(completeMode) { //tries every possible combination of words with capitalizations,
        std::string guess;
        std::string temp;
        std::string temp2;
        unsigned int guessSize;
        std::vector<char> binString;
        std::vector<char> binString2;

        while(true) {   //symbol substitution and digits at beginning and end of string

            if(kill) {
                plaintext = "Cancelled";
                elapsed = timer.elapsed();
                return QPointF(0, elapsed);
            }

            guess = getNextWord();

            temp = guess;
            temp2 = guess;
            guessSize = guess.size();
            binString = std::vector<char>(guessSize,'0');
            binString2 = binString;

            while(true) {

                if(kill) {
                    plaintext = "Cancelled";
                    elapsed = timer.elapsed();
                    return QPointF(0, elapsed);
                }

                temp = guess;

                for(unsigned int i = 0; i < guessSize; i++) {
                    if(binString[i] == '1') {
                        //capitalize letter
                        if(temp[i] > 96 && temp[i] < 123) {
                            //convert to uppercase
                            temp[i] = temp[i] - 32;
                        }

                        while(true) {

                            if(kill) {
                                plaintext = "Cancelled";
                                elapsed = timer.elapsed();
                                return QPointF(0, elapsed);
                            }

                            temp2 = temp;

                            for(unsigned int j = 0; j < guessSize; j++) {
                                //try symbol substitution
                                if(binString2[j] == '1') {
                                    for(unsigned int k = 0; k < symbolArraySize; k++) {
                                        if(temp2[j] == symbolConversion[k].first) {
                                            temp2[j] = symbolConversion[k].second;
                                            break;
                                        }
                                    }

                                    hashType->plaintext = temp2;
                                    int plaintextLength = verifyGuess();
                                    if(plaintextLength != 0) {
                                        elapsed = timer.elapsed();
                                        return QPointF(plaintextLength, elapsed);
                                    }
                                }
                            }
                            if(allOnes(binString2)) {
                                break;
                            }
                            binString2 = incrementBinString(binString2);
                        }
                    }
                }

                hashType->plaintext = temp;

                int plaintextLength = verifyGuess();
                if(plaintextLength != 0) {
                    elapsed = timer.elapsed();
                    return QPointF(plaintextLength, elapsed);
                }

                if(allOnes(binString)) {
                    break;
                }
                binString = incrementBinString(binString);
            }
        }
    } else { //not "complete mode"

        for(mpz_class i = 0; i < mpz_class(pow(words.size(), numWords)); i++) {

            if(kill) {
                plaintext = "Cancelled";
                elapsed = timer.elapsed();
                return QPointF(0, elapsed);
            }

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
                    for(unsigned int j = 0; j < symbolArraySize; j++) {
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
                                 bool cap, bool complete) {
    numWords = words;
    appendedDigits = endDigits;
    prependedDigits = preDigits;
    symbols = symb;
    capWords = cap;
    completeMode = complete;
}
