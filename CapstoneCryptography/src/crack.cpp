#include <headers/crack.h>

Crack::Crack(const Crack& c) {
    plaintext = c.plaintext;
    digest = c.digest;
    hashType = c.hashType;
}

Crack& Crack::operator=(const Crack& c) {
    plaintext = c.plaintext;
    digest = c.digest;
    hashType = c.hashType;
    return *this;
}

Crack::~Crack() {
    kill=true;
    delete hashType;
}

void Crack::setDigest(QString d) {
    digest = d.toStdString();
    DIGEST = d.toStdString();
}

QPointF Crack::reverse() {
    std::cout << "Incorrect usage of crack class. Needs \"Crack* c = new X\" where X is a subclass of Crack." << std::endl;
    return QPointF(-1, -1);
}

void Crack::setOptions(unsigned int words, unsigned int endDigits, unsigned int preDigits, bool symb, bool cap, bool complete) {
    std::cout << "Incorrect usage of crack class. Needs \"Crack* c = new X\" where X is an instance of DictionaryCrack." << std::endl;
}

QString Crack::getDigest() {
    return QString::fromStdString(digest);
}

QString Crack::getPlaintext() {
    return QString::fromStdString(plaintext);
}

void Crack::stop() {
    kill = true;
}
