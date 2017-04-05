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

    double xLimit;
    double yLimit;
    double yLogLimit;

    double logMax;
    std::vector<QString> logLabelsY;
    std::vector<QString> labelsY;
    std::vector<QString> labelsX;

    QPointF maximum;

    QGraphicsView* view;
    QGraphicsScene* scene;

    void draw();
    void addTicksY(std::vector<QString>);
    void addTicksX(std::vector<QString>);
    void addLabels(std::string ylabel, std::string xlabel);
    void logScaleDraw();

private:
    std::vector<QPointF> points;
    QFrame *ui;
    QPoint transform(QPointF);
    std::vector<QPointF> getScaledPoints(std::vector<QPointF>, double);
    std::vector<QPointF> getLogPoints();
    void setMaxPoint();
    void setLimits();
    void setLabelsX();
    void setLabelsY(unsigned int count = 10);
    void setLogLabelsY();
};

#endif // GRAPHWINDOW_H
