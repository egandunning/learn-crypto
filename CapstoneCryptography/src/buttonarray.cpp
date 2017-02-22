#include <headers/buttonarray.h>

ButtonArray::ButtonArray(std::string s, QWidget* ui){

    buttonArray = new QPushButton[s.length()];

    for(int i=0; i<s.length(); i++){
        buttonArray[i] = new QPushButton(s.at(i), ui);
    }

}

string ButtonArray::makeGuess(char original, char guess){
    for(int i=0; i<buttonArray.size(); i++){
        if(buttonArray[i]->text().at(0) == guess){
            buttonArray[i]->setText(guess);
        }
    }
    return "";
}

void displayButtons(){
    for(int i=0; i<buttonArray.size(); i++){
        buttonArray[i]->display;
    }
}
