#ifndef BUTTONARRAY_H
#define BUTTONARRAY_H

#include <string>
#include <vector>
#include <QPushButton>
#include <QWidget>
#include <QVector>

class ButtonArray{

private:
    QVector<QPushButton *> buttonVector;
    std::string scrambledWord;

public:
    ButtonArray(std::string, QWidget*);
    std::string makeGuess(char);
};

#endif // BUTTONARRAY_H

