#include <headers/crack.h>

Crack::Crack(Hash h) {
    hashType = h;
}

int Crack::reverse(int) {}

//void Crack::setAlphabet(std::string){}

void Crack::setDigest(QString d) {
    digest = d.toStdString();
}

QString Crack::getDigest() {
    return QString::fromStdString(digest);
}

QString Crack::getPlaintext() {
    return QString::fromStdString(plaintext);
}
