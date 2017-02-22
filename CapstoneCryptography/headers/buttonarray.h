#ifndef BUTTONARRAY_H
#define BUTTONARRAY_H

class ButtonArray{

private:
    QPushButton *buttonArray;

pubic:
    ButtonArray(std::string);
    std::string makeGuess(std::char, std::char);
};

#endif // BUTTONARRAY_H

