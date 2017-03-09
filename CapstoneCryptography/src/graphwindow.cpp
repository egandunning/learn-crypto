#include <headers/graphwindow.h>
#include <headers/bruteforcefactor.h>
#include <headers/generatedata.h>
#include <headers/bruteforcecrack.h>
#include <headers/md5.h>

#include <iostream>
GraphWindow::GraphWindow(QGraphicsView* graphicsView)
{
    points = std::vector<QPointF>();

    //Set up graph GUI
    view = graphicsView;
    scene = new QGraphicsScene();

    hSize = 600;
    vSize = 600;

    scene->setSceneRect(0,0,hSize-50,-vSize+50); //I dont know why this works
    view->setScene(scene);
    view->resize(hSize,vSize);
}

void GraphWindow::draw() {

    QLine yAxis(QPoint(0,0),QPoint(0,-vSize + 100));
    QLine xAxis(QPoint(0,0),QPoint(hSize - 100,0));
    scene->addLine(yAxis);
    scene->addLine(xAxis);



    //Add the tick marks to the line.
    int xLimit = (int)points.at(points.size()-1).x();
    //find largest y-value
    double yLimit = 0;
    for(unsigned int i = 0; i < points.size(); i++) {
        if(points.at(i).y() > yLimit) {
            yLimit = points.at(i).y();
        }
    }
    addTicksY(vSize - 100, 10, (int)yLimit);

    points = scalePoints(points);

    QPointF previous;
    for(std::vector<QPointF>::iterator it = points.begin(); it != points.end(); it++) {
        QPointF current = transform(*it);
        std::cout << current.x() << "," << current.y() << std::endl;
        scene->addEllipse((int)current.x()-3, (int)current.y()-3, 6, 6, QPen(Qt::black), QBrush(Qt::black));
        if(!previous.isNull()) {
            QPoint a((int)current.x(), (int)current.y());
            QPoint b((int)previous.x(), (int)previous.y());
            scene->addLine(QLine(a,b));
        }
        previous = current;
    }
}

void GraphWindow::logScale(int base) {

    for(std::vector<QPointF>::iterator it = points.begin(); it != points.end(); it++) {
        QPointF current = *it;
        if(current.y() > 0) {
            current.setY( log(current.y()) / log(base));
        }
        *it = current;
    }
}

void GraphWindow::undoLogScale(int base) {

    for(std::vector<QPointF>::iterator it = points.begin(); it != points.end(); it++) {
        QPointF current = *it;
        if(current.y() != 0) {
            current.setY( pow(base,current.y()) );
        }
        *it = current;
    }
}

void GraphWindow::addTicksY(int yMax, int ticksY, int yValue) {

    /*
     * addTicks takes in yMax as the maximum value of the y axis.
     * It also takes in the number of ticks that should appear on the the graph.
     *
     */

    int y = yMax / ticksY;

    QFont font("Times", 8);

    int yIncrement = yValue / ticksY;

    for(int i = 0; i<= ticksY; i++){
        scene->addLine(QLine(QPoint(0, -i*y), QPoint(2, -i*y)));

        QGraphicsTextItem *temp = scene->addText(QString::number(i*yIncrement), font);
        temp->setPos(-16, -i*y + 10);
        temp->setRotation(270);

    }
}


void GraphWindow::addLabels(std::string ylabel, std::string xlabel){

    /*
     * addLabels, adds two custom strings to label the y-axis and the x-axis on the graph.
     * Also include the maximum y value, and the maximum x value.
     */

    int xMax = hSize - 100;
    int yMax = vSize - 100;

    QString str = QString::fromStdString(xlabel);
    QGraphicsTextItem *txt = scene->addText(str, QFont());
    txt->setPos((xMax - 5*xlabel.length()) /2, 0);

    QString stry = QString::fromStdString(ylabel);
    QGraphicsTextItem *txty = scene->addText(stry, QFont());
    txty->setPos(-30, -(yMax - (int)(5*ylabel.length()))/ 2);
    std::cout << (-1*(yMax - 5*ylabel.length())/ 2) << std::endl;
    txty->setRotation(270);
}

/**
 * Make sure all points fit in the window, and draw the x axis labels.
 * @brief GraphWindow::scalePoints
 * @param points
 * @return
 */
std::vector<QPointF> GraphWindow::scalePoints(std::vector<QPointF> points) {

    //Find point with highest value for x and y.
    // -Assume this point is the last in vector

    QPointF maxY(0,0);
    QPointF maxX(0,0);
    for(unsigned int i = 0; i < points.size(); i++) {
        if(points.at(i).x() > maxX.x()) {
            maxX = points.at(i);
        }
        if(points.at(i).y() > maxY.y()) {
            maxY = points.at(i);
        }
    }

    double scaleFactor = 1;

    //scale
    QPointF current;

    //scale down graph so the y's fit if neccesary
    if(maxY.y() != (vSize-100) && maxY.y() != 0) {
        scaleFactor = (vSize-100) / maxY.y();

        for(unsigned int i = 0; i < points.size(); i++) {
            current = points.at(i);
            //current.setX(current.x() * scaleFactor);
            current.setY(current.y() * scaleFactor);
            points.at(i) = current;

        }
    }

    //scale down graph so the x's fit if neccesary
    if(maxX.x() != (hSize-100) && maxX.x() != 0) {
        scaleFactor = (hSize-100) / maxX.x();

        for(unsigned int i = 0; i < points.size(); i++) {
            current = points.at(i);
            double tempX = current.x();
            current.setX(tempX * scaleFactor);
            points.at(i) = current;

            //draw x axis labels
            scene->addLine(QLine(QPoint((int)current.x(), 0), QPoint((int)current.x(), -2)));

            QGraphicsTextItem *temp = scene->addText(QString::number((int)tempX), QFont("times",8));
            temp->setPos((int)current.x() - 5, -3);

        }
    }

    return points;

}

QPointF GraphWindow::transform(QPointF original) {
    double x = original.x();
    double y = original.y();

    QPointF transformed(x, y*-1);
    return transformed;
}
