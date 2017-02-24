#ifndef BUTTONARRAY_H
#define BUTTONARRAY_H

#include <string>
#include <vector>
#include <QPushButton>
#include <QWidget>
#include <QVector>
#include <QString>

class ButtonArray{

private:
    QVector<QPushButton *> buttonPointerVector;
    QString scrambledWord;

public:
    ButtonArray(QString, QWidget*);
    QString makeGuess(char);
    QPushButton* get(int);
};

#endif // BUTTONARRAY_H

