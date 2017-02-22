#ifndef BUTTONARRAY_H
#define BUTTONARRAY_H

class ButtonArray{

private:
    QPushButton *buttonArray;

public:
    ButtonArray(std::string, QWidget*);
    std::string makeGuess(char, char);
};

#endif // BUTTONARRAY_H

