#ifndef ROW_H
#define ROW_H

#include <gmpxx.h>
#include <vector>
#include <sstream>
#include <bitset>
#include <cstring>

#define VECTOR_SIZE 5

class row {

public:

    row() :
        xVals(), vec{0}
    {}

    std::vector<mpz_class> xVals;
    long vec[VECTOR_SIZE];

    row& operator=(const row& other) {
        memcpy(this->vec, other.vec, VECTOR_SIZE);
        this->xVals = other.xVals;
        return *this;
    }

    bool operator>(const row& other) {
        for(size_t i = 0; i < VECTOR_SIZE; i++) {
            if(this->vec[i] > other.vec[i]) {
                return 1;
            }
        }
        return 0;
    }

    bool operator<(const row& other) {
        if(*this >= other) {
            return 0;
        }
        return 1;
    }

    bool operator==(const row& other) {
        for(size_t i = 0; i < VECTOR_SIZE; i++) {
            if(this->vec[i] != other.vec[i]) {
                return 0;
            }
        }
        return 1;
    }

    bool operator>=(const row& other) {
        if(*this > other || *this == other) {
            return 1;
        }
        return 0;
    }

    row operator+(const row& other) {
        for(size_t i = 0; i < VECTOR_SIZE; i++) {
            this->vec[i] = this->vec[i] ^ other.vec[i];
        }
        return *this;
    }

    /**
     * print row vector up to length
     * @brief print
     * @param length
     */
    void print(int length) {
        std::stringstream ss;
        for(int i = VECTOR_SIZE-1; i >= 0; i--) {
            ss << std::bitset<64>(vec[i]);
        }
        std::string printStr = ss.str();
        printStr = printStr.substr(printStr.size() - length, printStr.size()-1);
        std::cout << printStr << " ";

        for(size_t i = 0; i < xVals.size(); i++) {
            std::cout << xVals.at(i).get_str() << ", ";
        }
        std::cout << std::endl;
    }

    /**
     * adds one at index in the vector
     * @brief add
     * @param index
     */
    void add(int index) {
        for(int i = 0; i < VECTOR_SIZE; i++) {
            long temp = 1;
            if(index < 64) {
                vec[i] = vec[i] ^ (temp << index);
                return;
            }
            index -= 64;
        }
    }

    bool at(int index) {
        for(int i = 0; i < VECTOR_SIZE; i++) {
            if(index < 64) {
                return std::bitset<64>(vec[i])[index];
            }
            index -= 64;
        }
        return 0;
    }

    bool zeroVector() {
        for(int i = 0; i < VECTOR_SIZE; i++) {
            if(vec[i] != 0) {
                return 0;
            }
        }
        return 1;
    }

    /**
     * Inserts number into vector of numbers
     * @brief insert
     * @param xVal
     */
    void insert(mpz_class xVal) {
        xVals.push_back(xVal);
    }

};

#endif // ROW_H

