#include <headers/buttonarray.h>
#include <string>
#include <QPushButton>
#include <QWidget>
#include <QString>
#include <QChar>
#include <QVector>

ButtonArray::ButtonArray(QString qS, QWidget* ui){

    scrambledWord = qS;

    for(int i=0; i<qS.length(); i++){
        //Convert i character of s to a QString
        QString qSTemp = QChar(qS.at(i));
        //Make QString size one
        qSTemp.resize(1);
        //Make new pushbutton, have pointer p point to it
        QPushButton *p = new QPushButton(qSTemp, ui);
        //Add pointer p to the QVector
        buttonPointerVector.append(p);
    }

}

QString ButtonArray::makeGuess(char guess){
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

QPushButton* ButtonArray::get(int i){
    return buttonPointerVector.at(i);
}

