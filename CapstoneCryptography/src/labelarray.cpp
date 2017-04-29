#include <headers/labelarray.h>
#include <string>
#include <QLabel>
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


LabelArray::LabelArray(QString qS, QWidget* ui){

    scrambledWord = qS;
    parent = ui;

    for(int i=0; i<qS.length(); i++){
        //Convert i character of s to a QString
        QString qSTemp = QChar(qS.at(i));
        //Make QString size one
        qSTemp.resize(1);
        //Make new pushbutton, have pointer p point to it
        //Offset the character to center the character over the button
        QLabel *p = new QLabel("  "+qSTemp, ui);

        //Set Maximum Width to 25
        p->setMaximumWidth(25);
        //Add pointer p to the QVector
        labelPointerVector.append(p);
    }

}

QLabel* LabelArray::get(int i){
    return labelPointerVector.at(i);
}




