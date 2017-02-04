#include <headers/crack.h>

void Crack::setDigest(QString d) {
    digest = d.toStdString();
}

QString Crack::getDigest() {
    return QString::fromStdString(digest);
}

QString Crack::getPlaintext() {
    return QString::fromStdString(plaintext);
}
