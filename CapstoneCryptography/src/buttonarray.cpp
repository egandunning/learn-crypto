#include <headers/buttonarray.h>
#include <string>
#include <QPushButton>
#include <QWidget>
#include <QString>
#include <QChar>
#include <QVector>

ButtonArray::ButtonArray(std::string s, QWidget* ui){

    scrambledWord = s;

    for(int i=0; i<s.length(); i++){
        //Convert i character of s to a QString
        QString qS = QChar(s.at(i));
        //Make QString size one
        qS.resize(1);
        //Make new pushbutton, have pointer p point to it
        QPushButton *p = new QPushButton(qS, ui);
        //Add pointer p to the QVector
        buttonPointerVector.append(p);
    }

}

std::string ButtonArray::makeGuess(char guess){
    //Convert guess to a QString
    QString qGuess = QChar(guess);
    //Make QString size one
    qGuess.resize(1);
    for(int i=0; i<scrambledWord.length(); i++){
        if(buttonPointerVector.at(i)->text().at(0) == guess){
           buttonPointerVector.at(i)->setText(qGuess);
        }
    }
    return "";
}

