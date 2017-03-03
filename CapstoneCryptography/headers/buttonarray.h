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
    QWidget *parent;

public:
    ButtonArray(QString, QWidget*);
    QString makeGuess(QChar);
    QPushButton* get(int);

public slots:
    void show_input_box();
};

#endif // BUTTONARRAY_H

