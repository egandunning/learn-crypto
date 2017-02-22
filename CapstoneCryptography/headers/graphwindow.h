#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <QWidget>
#include <QFrame>
#include <QPoint>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <vector>

class GraphWindow
{
public:
    GraphWindow();


private:
    QFrame *ui;
    QGraphicsView* view;
    QGraphicsScene* scene;
    std::vector<QPoint> points;
    void draw();
};

#endif // GRAPHWINDOW_H
