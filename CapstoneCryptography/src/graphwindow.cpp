#include <headers/graphwindow.h>
#include <iostream>

#include <headers/bruteforcefactor.h>
#include <headers/generatedata.h>

GraphWindow::GraphWindow(std::vector<QPointF> pts)
{
    points = pts;

    //Set up graph GUI
    view = new QGraphicsView();
    scene = new QGraphicsScene();

    int hSize = 500;
    int vSize = 500;

    scene->setSceneRect(0,0,hSize-50,-vSize+50); //I dont know why this works
    view->setScene(scene);
    view->resize(hSize,vSize);

    //Draw points
    GraphWindow::draw();

    view->show();
}

/*QPointF fact(mpz_class n) {
    BruteForceFactor b = BruteForceFactor();
    return b.factor(n);
}*/

void GraphWindow::draw() {

    std::vector<mpz_class> vec;
    vec.push_back(100);
    vec.push_back(300);
    BruteForceFactor* b = new BruteForceFactor();

    //GenerateData::generate(b->factor, vec);

    for(int i = 0; i <= 10; i++) {
        points.push_back(QPointF(i,i*i));
    }

    QLine yAxis(QPoint(0,0),QPoint(0,-100));
    QLine xAxis(QPoint(0,0),QPoint(100,0));
    scene->addLine(yAxis);
    scene->addLine(xAxis);

    for(std::vector<QPointF>::iterator it = points.begin(); it != points.end(); it++) {
        QPointF current = transform(*it);
        scene->addEllipse(current.x()+3, current.y()-3, 3, 3);
    }

}

QPointF GraphWindow::transform(QPointF original) {
    double x = original.x();
    double y = original.y();

    int windowSize = view->size().width();

    QPointF transformed(x, y*-1);
    return transformed;
}
