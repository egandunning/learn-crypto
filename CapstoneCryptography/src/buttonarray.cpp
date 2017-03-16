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


ButtonArray::ButtonArray(QString qS, QWidget* ui){

    scrambledWord = qS;
    parent = ui;

    for(int i=0; i<qS.length(); i++){
        //Convert i character of s to a QString
        QString qSTemp = QChar(qS.at(i));
        //Make QString size one
        qSTemp.resize(1);
        //Make new pushbutton, have pointer p point to it
        QPushButton *p = new QPushButton(qSTemp, ui);
        //Set Maximum Width to 25
        p->setMaximumWidth(25);
        //Object, then related signal, object, then related slot
        connect(p, SIGNAL(clicked(bool)), this, SLOT(show_input_box()));
        //Add pointer p to the QVector
        buttonPointerVector.append(p);
    }

}

QString ButtonArray::makeGuess(QString original, QString guess){
    //Make QString size one
    original.resize(1);
    guess.resize(1);
    for(int i=0; i<scrambledWord.length(); i++){
        if(buttonPointerVector.at(i)->text().at(0) == original){
           buttonPointerVector.at(i)->setText(guess);
        }
    }
    return "";
}

QPushButton* ButtonArray::get(int i){
    return buttonPointerVector.at(i);
}

void ButtonArray::show_input_box(){

    bool changed;
    std::string title = "Guess a Letter";
    std::string label = "Guess";
    std::string defaultGuess = " ";
    QString letter = QInputDialog::getText(parent, QString::fromStdString(title), QString::fromStdString(label), QLineEdit::Normal, QString::fromStdString(defaultGuess), &changed);

    if(changed && !letter.isEmpty()){
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
        ButtonArray::makeGuess(buttonPointerVector.at(1)->text(), letter);
    }
}

