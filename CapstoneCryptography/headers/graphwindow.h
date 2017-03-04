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
    GraphWindow(QGraphicsView*);
    std::vector<QPointF> points;
    int hSize;
    int vSize;
    QGraphicsView* view;
    void draw();
    void addTicks(int yMax, int xMax, int ticksX, int ticksY);
    void addLabels(std::string ylabel, std::string xlabel, int yMax, int xMax);
private:
    QFrame *ui;
    QGraphicsScene* scene;
    QPointF transform(QPointF);
    std::vector<QPointF> scalePoints(std::vector<QPointF>);
};

#endif // GRAPHWINDOW_H
