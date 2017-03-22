#include <headers/crack.h>

Crack::~Crack() {
    delete hashType;
}

void Crack::setDigest(QString d) {
    digest = d.toStdString();
}

QPointF Crack::reverse() {
    std::cout << "Incorrect usage of crack class. Needs \"Crack* c = new X\" where X is a subclass of Crack." << std::endl;
    return QPointF(-1, -1);
}

void Crack::setOptions(unsigned int words, unsigned int endDigits, unsigned int preDigits, unsigned int symb, bool cap) {
    std::cout << "Incorrect usage of crack class. Needs \"Crack* c = new X\" where X is an instance of DictionaryCrack." << std::endl;
}

QString Crack::getDigest() {
    return QString::fromStdString(digest);
}

QString Crack::getPlaintext() {
    return QString::fromStdString(plaintext);
}
