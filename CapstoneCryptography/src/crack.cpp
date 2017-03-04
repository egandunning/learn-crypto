#include <headers/crack.h>

Crack::~Crack() {
    //delete hashType; why does this segfault?
    delete hashType;
}

void Crack::setDigest(QString d) {
    digest = d.toStdString();
}

QPointF Crack::reverse() {
    std::cout << "Incorrect usage of crack class. Needs \"Crack* c = new X\" where X is a subclass of Crack." << std::endl;
    return QPointF(-1, -1);
}

QString Crack::getDigest() {
    return QString::fromStdString(digest);
}

QString Crack::getPlaintext() {
    return QString::fromStdString(plaintext);
}
