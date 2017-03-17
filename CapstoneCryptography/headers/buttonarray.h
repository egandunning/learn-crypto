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

class ButtonArray : public QObject{

   Q_OBJECT

public:
    ButtonArray(QString, QWidget*);
    QPushButton* get(int);

private slots:
    void show_input_box(int);

private:
    QString makeGuess(QString, QString);
    QVector<QPushButton *> buttonPointerVector;
    QString scrambledWord;
    QWidget *parent;
    QSignalMapper *mapper;
};

#endif // BUTTONARRAY_H

