#include <headers/graphwindow.h>
#include <iostream>

GraphWindow::GraphWindow()
{
    std::cout << "here" << std::endl;
    points = std::vector<QPoint>();
    view = new QGraphicsView();
    scene = new QGraphicsScene();
    view->setScene(scene);
    view->resize(500,500);
    GraphWindow::draw();
    view->show();
}

void GraphWindow::draw() {

    for(int i = 0; i < 10; i++) {
        points.push_back(QPoint(i,i));
        std::cout << "loop 1" << std::endl;
    }

    for(std::vector<QPoint>::iterator it = points.begin(); it != points.end(); it++) {
        QPoint current = *it;
        std::cout << "loop 2" << std::endl;
        scene->addEllipse(current.x(), current.y(), 2, 2);
    }

}

