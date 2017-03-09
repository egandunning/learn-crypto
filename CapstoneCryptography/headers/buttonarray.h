#ifndef BUTTONARRAY_H
#define BUTTONARRAY_H

#include <string>
#include <vector>
#include <QPushButton>
#include <QWidget>
#include <QVector>
#include <QString>
#include <QObject>

class ButtonArray : public QObject{

   Q_OBJECT

public:
    ButtonArray(QString, QWidget*);
    QString makeGuess(QChar);
    QPushButton* get(int);

private slots:
    void show_input_box();

private:
    QVector<QPushButton *> buttonPointerVector;
    QString scrambledWord;
    QWidget *parent;
};

#endif // BUTTONARRAY_H

