#ifndef LABELARRAY
#define LABELARRAY

#include <string>
#include <vector>
#include <QLabel>
#include <QWidget>
#include <QVector>
#include <QString>
#include <QObject>

class LabelArray {


public:
    LabelArray(QString, QWidget*);
    QLabel* get(int);


private:
    QVector<QLabel *> labelPointerVector;
    QString scrambledWord;
    QWidget *parent;

};
#endif // LABELARRAY

