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
        QPushButton *p = new QPushButton("philip", ui);
       buttonVector.append(p);
    }

}

std::string ButtonArray::makeGuess(char guess){
    QString qGuess = QChar(guess);
    qGuess.resize(1);
    for(int i=0; i<scrambledWord.length(); i++){
        if(buttonVector.at(i)->text().at(0) == guess){
           buttonVector.at(i)->setText(qGuess);
        }
    }
    return "";
}

