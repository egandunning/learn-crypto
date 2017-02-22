#ifndef BUTTONARRAY_H
#define BUTTONARRAY_H

#include <string>
#include "QPushButton"
#include "QWidget"

class ButtonArray{

private:
    QPushButton *buttonArray;
    std::string scrambledWord;

public:
    ButtonArray(std::string, QWidget*);
    std::string makeGuess(char, char);
};

#endif // BUTTONARRAY_H

