#include <headers/crack.h>

void Crack::setDigest(QString d) {
    digest = d.toStdString();
}

int Crack::reverse() {
    std::cout << "Incorrect usage of crack class. Needs \"Crack* c = new X\" where X is a subclass of Crack." << std::endl;
    return -1;
}

QString Crack::getDigest() {
    return QString::fromStdString(digest);
}

QString Crack::getPlaintext() {
    return QString::fromStdString(plaintext);
}
