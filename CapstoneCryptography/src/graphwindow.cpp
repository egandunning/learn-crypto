#include <headers/graphwindow.h>
#include <headers/bruteforcefactor.h>
#include <headers/generatedata.h>
#include <headers/bruteforcecrack.h>
#include <headers/md5.h>

#include <iostream>
GraphWindow::GraphWindow(std::vector<QPointF> pts)
{
    points = pts;

    //Set up graph GUI
    view = new QGraphicsView();
    scene = new QGraphicsScene();

    hSize = 600;
    vSize = 600;

    scene->setSceneRect(0,0,hSize-50,-vSize+50); //I dont know why this works
    view->setScene(scene);
    view->resize(hSize,vSize);

    //Draw points
    GraphWindow::draw();

    view->show();
}


void GraphWindow::draw() {

    BruteForceFactor* bf = new BruteForceFactor();

    Md5* md5 = new Md5();
    std::string alphabet = " abcdefghijklmnopqrstuvwxyz";
    BruteForceCrack* bc = new BruteForceCrack(md5, alphabet, 6);

    std::vector<mpz_class> comps = GenerateData::composites(2, 7);
    std::vector<std::string> words = GenerateData::plaintexts(1,5);
    std::vector<std::string> digests = GenerateData::getHashes(words, md5);

    points = GenerateData::factor(comps, bf);
    //points = GenerateData::crack(digests, bc);

    QLine yAxis(QPoint(0,0),QPoint(0,-vSize + 100));
    QLine xAxis(QPoint(0,0),QPoint(hSize - 100,0));
    scene->addLine(yAxis);
    scene->addLine(xAxis);

    //Add the tick marks to the line.
    addTicks(vSize - 100, hSize - 100, 10, 10);

    //Adds the chosen labels
    addLabels("Seconds", "Number of digits", vSize - 100, hSize - 100);
    //addTitle("Factoring Semiprime Numbers");


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

void GraphWindow::addTicks(int yMax, int xMax, int ticksX, int ticksY) {

    /*
     * addTicks takes in yMax, and xMax as the maximum value of the y and x axises.
     * It also takes in the number of ticks that should appear on the the graph.
     *
     */


    int y = yMax / ticksX ;
    int x = xMax / ticksY ;

    QFont font("Times", 8);

    for(int i = 1; i<= ticksY; i++){
        scene->addLine(QLine(QPoint(0, i * -y), QPoint(2, i * -y)));

        if(i%2 == 0){
            string number = std::to_string(i);

            QString str = QString::fromStdString(number);
            QGraphicsTextItem *temp = scene->addText(str, font);
            temp->setPos(-16, (i* -y) - 3);
        }
    }

    for(int i = 1; i<= ticksX; i++){
        scene->addLine(QLine(QPoint(i * x, 0), QPoint(i * x, -2)));

        if(i%2 == 0){
            string number = std::to_string(i);

            QString str = QString::fromStdString(number);
            QGraphicsTextItem *temp = scene->addText(str, font);
            temp->setPos(i * x, -5);
        }
    }
}


void GraphWindow::addLabels(std::string ylabel, std::string xlabel, int yMax, int xMax){

    /*
     * addLabels, adds two custom strings to label the y-axis and the x-axis on the graph.
     * Also include the maximum y value, and the maximum x value.
     */

    QString str = QString::fromStdString(xlabel);
    QGraphicsTextItem *txt = scene->addText(str, QFont());
    txt->setPos((xMax - 5*xlabel.length()) /2, 0);

    QString stry = QString::fromStdString(ylabel);
    QGraphicsTextItem *txty = scene->addText(stry, QFont());
    txty->setPos(-30, -(yMax - (int)(5*ylabel.length()))/ 2);
    std::cout << (-1*(yMax - 5*ylabel.length())/ 2) << std::endl;
    txty->setRotation(270);
}

std::vector<QPointF> GraphWindow::scalePoints(std::vector<QPointF> points) {

    //Find point with highest value for x and y.
    // -Assume this point is the last in vector

    double scaleFactor = 1;

    //scale
    QPointF last = points.at(points.size()-1);
    QPointF current;

    //scale down graph so the y's fit if neccesary
    if(last.y() != (vSize-100) && last.y() != 0) {
        scaleFactor = (vSize-100) / last.y();

        for(unsigned int i = 0; i < points.size(); i++) {
            current = points.at(i);
            //current.setX(current.x() * scaleFactor);
            current.setY(current.y() * scaleFactor);
            points.at(i) = current;

        }
    }

    //scale down graph so the x's fit if neccesary
    if(last.x() != (hSize-100) && last.x() != 0) {
        scaleFactor = (hSize-100) / last.x();

        for(unsigned int i = 0; i < points.size(); i++) {
            current = points.at(i);
            current.setX(current.x() * scaleFactor);
            //current.setY(current.y() * scaleFactor);
            points.at(i) = current;
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
