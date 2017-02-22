#include <headers/buttonarray.h>
#include <string>
#include "QPushButton"
#include "QWidget"
#include "QString"

ButtonArray::ButtonArray(std::string s, QWidget* ui){

    buttonArray = new QPushButton[s.length()];
    scrambledWord = s;

    for(int i=0; i<s.length(); i++){
       // buttonArray[i] = new QPushButton(new QString(s.at(i)), ui);
    }

}

std::string ButtonArray::makeGuess(char original, char guess){
    for(int i=0; i<scrambledWord.length(); i++){
        if(buttonArray[i].text().at(0) == guess){
           // buttonArray[i].setText(new QString(guess));
        }
    }
    return "";
}

