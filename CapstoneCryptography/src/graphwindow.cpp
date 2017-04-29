#include <headers/graphwindow.h>
#include <headers/bruteforcefactor.h>
#include <headers/generatedata.h>
#include <headers/bruteforcecrack.h>
#include <headers/md5.h>

#include <iostream>

GraphWindow::GraphWindow() :
    hSize(0),
    vSize(0),
    xLimit(0),
    yLimit(0),
    yLogLimit(0),
    logMax(0),
    logLabelsY(),
    labelsY(),
    labelsX(),
    maximum(0,0)
{}

GraphWindow::GraphWindow(QGraphicsView* graphicsView, std::vector<QPointF> pts) :
    points(pts),
    view(graphicsView),
    hSize(600),
    vSize(600)
{
    setMaxPoint();
    setLimits();
    yLogLimit = log(yLimit);

    setLabelsX();
    setLabelsY();

    //Set up graph GUI
    scene = new QGraphicsScene();

    scene->setSceneRect(0,0,hSize-50,-vSize+50);
    view->setScene(scene);
    view->resize(hSize,vSize);
}

void GraphWindow::draw() {


    QLine yAxis(QPoint(0,0),QPoint(0,-vSize + 100));
    QLine xAxis(QPoint(0,0),QPoint(hSize - 100,0));
    scene->addLine(yAxis);
    scene->addLine(xAxis);

    std::vector<QPointF> scaledPoints = getScaledPoints(points,yLimit);

    //draw labels
    addTicksX(labelsX);
    addTicksY(labelsY);

    QPointF previous;
    int i = 0;
    for(std::vector<QPointF>::iterator it = scaledPoints.begin(); it != scaledPoints.end(); it++) {
        QPointF current = transform(*it);

        scene->addEllipse((int)current.x()-3, (int)current.y()-3, 6, 6, QPen(Qt::black), QBrush(Qt::black));
        std::cout<<"("<<points.at(i).x()<<","<<points.at(i).y()<<"),  ";
        if(!previous.isNull()) {
            QPoint a((int)current.x(), (int)current.y());
            QPoint b((int)previous.x(), (int)previous.y());
            scene->addLine(QLine(a,b));
        }
        i++;
        previous = current;
    }
    std::cout<<std::endl;
}

void GraphWindow::drawNewLayer(std::vector<QPointF> pts, Qt::GlobalColor color) {
    std::vector<QPointF> scaledPoints = getScaledPoints(pts,yLimit);
std::cout << "GraphWindow::drawNewLayer" << std::endl;
    QPointF previous;
    int i = 0;
    for(std::vector<QPointF>::iterator it = scaledPoints.begin(); it != scaledPoints.end(); it++) {
        QPointF current = transform(*it);

        scene->addEllipse((int)current.x()-3, (int)current.y()-3, 6, 6, QPen(color), QBrush(color));
        std::cout<<"("<<pts.at(i).x()<<","<<pts.at(i).y()<<"),  ";
        if(!previous.isNull()) {
            QPoint a((int)current.x(), (int)current.y());
            QPoint b((int)previous.x(), (int)previous.y());
            scene->addLine(QLine(a,b), QPen(color));
        }
        i++;
        previous = current;
    }
    std::cout<<std::endl;
}

void GraphWindow::logScaleDraw() {

    //get y axis labels
    setLogLabelsY();
    addTicksY(logLabelsY);
    addTicksX(labelsX);

    //scale points
    std::vector<QPointF> scaledPoints = getScaledPoints(getLogPoints(),yLogLimit);

    //draw points
    QPointF previous;
    int i = 0;
    for(std::vector<QPointF>::iterator it = scaledPoints.begin(); it != scaledPoints.end(); it++) {
        QPointF current = *it;

        current = transform(current);
        scene->addEllipse((int)current.x()-3, (int)current.y()-3, 6, 6, QPen(Qt::black), QBrush(Qt::black));
        std::cout<<"("<<points.at(i).x()<<","<<points.at(i).y()<<"),  ";
        if(!previous.isNull()) {
            QPoint a((int)current.x(), (int)current.y());
            QPoint b((int)previous.x(), (int)previous.y());
            scene->addLine(QLine(a,b));
        }
        i++;
        previous = current;
    }
    std::cout<<std::endl;

}

void GraphWindow::addTicksY(std::vector<QString> labels) {



    /*
     * addTicks takes in yMax as the maximum value of the y axis.
     * It also takes in the number of ticks that should appear on the the graph.
     *
     */
    //draw y axis
    QLine yAxis(QPoint(0,0),QPoint(0,-vSize + 100));
    scene->addLine(yAxis);

    if(labels.size() == 0) {
        std::cout << "Tried to draw x-labels, but the labels have not been created yet. Exiting graphwindow::addTicksY" << std::endl;
        return;
    }

    //draw axis labels
    int y = (vSize-100) / labels.size();


    QFont font("Times", 8);

    for(unsigned int i = 0; i < labels.size(); i++){
        int pos = -i*y;
        scene->addLine(QLine(QPoint(0, pos), QPoint(2, pos)));

        QGraphicsTextItem *temp = scene->addText(labels.at(i), font);
        temp->setPos(-16, pos + 10);
        temp->setRotation(270);
    }
}

void GraphWindow::addTicksX(std::vector<QString> labels) {

    //draw x axis
    QLine xAxis(QPoint(0,0),QPoint(hSize - 100,0));
    scene->addLine(xAxis);

    if(labels.size() == 0 || points.size() == 0) {
        std::cout << "Tried to draw x-labels, but the labels have not been created yet or there are no points to draw. Exiting graphwindow::addTicksX" << std::endl;
        return;
    }

    QFont font("Times", 8);

    std::vector<QPointF> scaledPoints = getScaledPoints(points, yLimit);
    for(unsigned int i = 0; i < labels.size(); i ++) {
        QPointF current = scaledPoints.at(i);
        scene->addLine(QLine(QPoint((int)current.x(), 0), QPoint((int)current.x(), -2)));

        QGraphicsTextItem *temp = scene->addText(labels.at(i), font);
        temp->setPos((int)current.x() - 5, -3);
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
    txt->setPos((xMax - 5*xlabel.length()) /2, 5);

    QString stry = QString::fromStdString(ylabel);
    QGraphicsTextItem *txty = scene->addText(stry, QFont());
    txty->setPos(-30, -(yMax - (int)(5*ylabel.length()))/ 2);

    txty->setRotation(270);
}

/**
 * Make sure all points fit in the window.
 * @brief GraphWindow::scalePoints
 * @param points
 * @return
 */
std::vector<QPointF> GraphWindow::getScaledPoints(std::vector<QPointF> pts, double maxY) {

    std::vector<QPointF> scaledPoints(pts);

    double scaleFactor = 1;

    //scale points to fit in window
    QPointF current;

    //scale down graph so the y's fit if neccesary
    if(yLimit != (vSize-100) && maxY != 0) {
        scaleFactor = (vSize-100) / maxY;

        for(unsigned int i = 0; i < pts.size(); i++) {
            current = pts.at(i);
            current.setY(current.y() * scaleFactor);
            scaledPoints.at(i) = current;
        }
    }

    //scale down graph so the x's fit if neccesary
    if(xLimit != (hSize-100) && xLimit != 0) {
        scaleFactor = (hSize-100) / xLimit;

        for(unsigned int i = 0; i < pts.size(); i++) {
            current = pts.at(i);
            scaledPoints.at(i).setX(current.x() * scaleFactor);

        }
    }

    return scaledPoints;

}

/**
 * Trivial transformation to flip y coord and cast to int
 * @brief GraphWindow::transform
 * @param original point to transform
 * @return
 */
QPoint GraphWindow::transform(QPointF original) {

    return QPoint((int)original.x(), -1 * (int)original.y());
}

/**
 * Find the point with the maximum y-value and assign it to maximum
 * @brief GraphWindow::setMaxPoint
 */
void GraphWindow::setMaxPoint() {

    QPointF maxY(0,0);
    for(unsigned int i = 0; i < points.size(); i++) {
        if(points.at(i).y() > maxY.y()) {
            maxY = points.at(i);
        }
    }
    maximum = maxY;
}

/**
 * Set the maximum value that the graph will show on x,y axes
 * @brief GraphWindow::setLimits
 */
void GraphWindow::setLimits() {

    xLimit = points.back().x();
    yLimit = maximum.y();
}

/**
 * Set x labels for graph
 * @brief GraphWindow::setLabelsX
 */
void GraphWindow::setLabelsX() {

    labelsX = std::vector<QString>();

    for(std::vector<QPointF>::iterator it = points.begin(); it != points.end(); it++) {
        QPointF temp = *it;
        labelsX.push_back(QString::number(temp.x()));

    }
}

/**
 * Set y labels for graph
 * @brief GraphWindow::setLabelsY
 */
void GraphWindow::setLabelsY(unsigned int count) {

    labelsY = std::vector<QString>();

    if(count == 0) {
        std::cout << "Generated zero y-labels as requested." << std::endl;
        return;
    }

    int increment = yLimit / count;

    for(unsigned int i = 0; i < count; i++) {
        labelsY.push_back(QString::number(i*increment));
    }
}

/**
 * Set labels for log scale graph
 * @brief GraphWindow::setLogLabelsY
 */
void GraphWindow::setLogLabelsY() {

    logLabelsY.clear();

    logLabelsY.push_back(QString::number(0));
    logLabelsY.push_back(QString::number(1));

    int max = 1;
    while(true) {
        max *= 10;
        if(max > yLimit) {
            break;
        }
        logLabelsY.push_back(QString::number(max));
    }
}

/**
 * Log transform data points if possible
 * @brief GraphWindow::getLogPoints
 * @return
 */
std::vector<QPointF> GraphWindow::getLogPoints() {

    std::vector<QPointF> logPoints;

    for(std::vector<QPointF>::iterator it = points.begin(); it != points.end(); it++) {
        QPointF current = *it;
        if(current.y() > 0) {
            current.setY(log(current.y()));

        } else {
            std::cout << "log(" << current.y() << ") is undefined! Skipping log transform for this point." << std::endl;
        }
        logPoints.push_back(current);
    }
    return logPoints;
}

/**
 * Add a centered title to graph.
 * @brief GraphWindow::addTitle
 * @param title the title to add.
 */
void GraphWindow::addTitle(std::string title) {
    QGraphicsTextItem *text = scene->addText(QString::fromStdString(title));
    text->setX(250 - (title.size()*5 / 2));
    text->setY(-550);
}

void GraphWindow::addLegend(QString legendText, Qt::GlobalColor color, int count) {

    QGraphicsTextItem *text = scene->addText(legendText);
    text->setY(-450 + 12*count);
    text->setX(10);
    text->setDefaultTextColor(color);
}
