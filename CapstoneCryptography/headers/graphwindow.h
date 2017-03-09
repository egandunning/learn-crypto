#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <QWidget>
#include <QFrame>
#include <QPointF>
#include <QLine>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <vector>

#include <headers/generatedata.h>

class GraphWindow
{
public:
    GraphWindow(QGraphicsView*, std::vector<QPointF> pts);

    int hSize;
    int vSize;

    double maximumY;

    QGraphicsView* view;
    QGraphicsScene* scene;
    void draw();
    void addTicksY(int yMax, int ticksY, int yValue);
    void addTicksY(std::vector<QString>);
    void addLabels(std::string ylabel, std::string xlabel);
    void logScaleDraw(int base = 10);
    void undoLogScale(int base = 10);
private:
    std::vector<QPointF> points;
    QFrame *ui;
    QPointF transform(QPointF);
    std::vector<QPointF> scalePoints(std::vector<QPointF>);
};

#endif // GRAPHWINDOW_H
