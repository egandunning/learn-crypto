#include <headers/buttonarray.h>
#include <string>
#include <QPushButton>
#include <QWidget>
#include <QString>
#include <QChar>
#include <QVector>
#include <QCoreApplication>
#include <QInputDialog>
#include <QDir>
#include <QLineEdit>
#include <QObject>
#include <QMessageBox>
#include <QSignalMapper>
#include "headers/cryptogame.h"


ButtonArray::ButtonArray(QString qS, QWidget* ui, cryptogame *agame){

    scrambledWord = qS;
    parent = ui;
    mapper = new QSignalMapper(this);
    game = agame;

    for(int i=0; i<qS.length(); i++){
        //Convert i character of s to a QString
        QString qSTemp = " ";//QChar(qS.at(i));
        //Make QString size one
        qSTemp.resize(1);
        //Make new pushbutton, have pointer p point to it
        QPushButton *p = new QPushButton(qSTemp, ui);
        //Set Maximum Width to 25
        p->setMaximumWidth(25);
        //Object, then related signal, object, then related slot
        connect(p, SIGNAL(clicked(bool)), mapper, SLOT(map()));
        mapper->setMapping(p, i);
        //Add pointer p to the QVector
        buttonPointerVector.append(p);
    }

    connect(mapper, SIGNAL(mapped(int)), this, SLOT(show_input_box(int)));

}

ButtonArray::~ButtonArray(){
    for(int i = 0; i<buttonPointerVector.length(); i++){
        delete buttonPointerVector.at(i);
    }
    //delete buttonPointerVector;
}

void ButtonArray::makeGuess(QString original, QString guess){
    //Make QString size one
    original.resize(1);
    guess.resize(1);
    QString newWord;
    for(int i=0; i<scrambledWord.length(); i++){
        if(scrambledWord.at(i) == original){
           buttonPointerVector.at(i)->setText(guess);
        }
        newWord.append(buttonPointerVector.at(i)->text());
    }

    if(game->sendCurrentGuess(newWord.toStdString())){
        QMessageBox winningMessage;
        winningMessage.setText("You won! Yay!                                               ");
        winningMessage.exec();
    }

}


QPushButton* ButtonArray::get(int i){
    return buttonPointerVector.at(i);
}

void ButtonArray::show_input_box(int index){

    bool changed;
    std::string title = "Guess a Letter";
    std::string label = "Guess";
    std::string defaultGuess = " ";
    QString letter = QInputDialog::getText(parent, QString::fromStdString(title), QString::fromStdString(label), QLineEdit::Normal, QString::fromStdString(defaultGuess), &changed);

    //make sure that a letter was guessed and that the input character is actually a letter
    if(changed && !letter.isEmpty() && letter.at(0).isLetter()){
        //Make QString size one
        letter.resize(1);
        //Make letter upper case
        letter = letter.toUpper();
        for(int i=0; i<scrambledWord.length(); i++){
            if(buttonPointerVector.at(i)->text().at(0) == letter){
                QMessageBox invalidEntry;
                invalidEntry.setText("You have already used this letter: " + letter);
                invalidEntry.exec();
                return;
            }
        }
        ButtonArray::makeGuess(QString(scrambledWord.at(index)), letter);
    }
}

