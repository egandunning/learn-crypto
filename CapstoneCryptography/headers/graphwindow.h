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
    QGraphicsScene* scene;
    void draw();
    void addTicksY(int yMax, int ticksY, int yValue);
    void addLabels(std::string ylabel, std::string xlabel);
    void logScale(int base = 10);
    void undoLogScale(int base = 10);
private:
    QFrame *ui;
    QPointF transform(QPointF);
    std::vector<QPointF> scalePoints(std::vector<QPointF>);
};

#endif // GRAPHWINDOW_H
