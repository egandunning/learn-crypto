#ifndef DICTIONARYCRACK_H
#define DICTIONARYCRACK_H

#include <headers/crack.h>

#include <fstream>

#include <QElapsedTimer>

class DictionaryCrack : public Crack {
public:
    DictionaryCrack(Hash*, std::string);
    virtual QPointF reverse() override;

private:
    std::string filename;
};

#endif // DICTIONARYCRACK_H

