#ifndef BUTTONARRAY_H
#define BUTTONARRAY_H

class ButtonArray{

private:
    QPushButton *buttonArray;

pubic:
    ButtonArray(std::string, QWidget*);
    std::string makeGuess(std::char, std::char);
    void displayButtons();
};

#endif // BUTTONARRAY_H

