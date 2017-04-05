#ifndef BUTTONARRAY_H
#define BUTTONARRAY_H

#include <string>
#include <vector>
#include <QPushButton>
#include <QWidget>
#include <QVector>
#include <QString>
#include <QObject>
#include <QSignalMapper>
#include "headers/cryptogame.h"

class ButtonArray : public QObject{

   Q_OBJECT

public:
    ButtonArray(QString, QWidget*, cryptogame*);
    ~ButtonArray();
    QPushButton* get(int);
    QString checkGuess();

private slots:
    void show_input_box(int);

private:
    void makeGuess(QString, QString);
    QVector<QPushButton *> buttonPointerVector;
    QString scrambledWord;
    QWidget *parent;
    QSignalMapper *mapper;
    QString newWord;
    cryptogame *game;
};

#endif // BUTTONARRAY_H

