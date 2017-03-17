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


ButtonArray::ButtonArray(QString qS, QWidget* ui){

    scrambledWord = qS;
    parent = ui;
    mapper = new QSignalMapper(this);
    newWord.append(" ");

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

void ButtonArray::makeGuess(QString original, QString guess){
    //Make QString size one
    original.resize(1);
    guess.resize(1);
    newWord.clear();
    for(int i=0; i<scrambledWord.length(); i++){
        if(scrambledWord.at(i) == original){
           buttonPointerVector.at(i)->setText(guess);
        }
        newWord.append(buttonPointerVector.at(i)->text());
    }

}

QString ButtonArray::checkGuess(){
    return newWord;
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

