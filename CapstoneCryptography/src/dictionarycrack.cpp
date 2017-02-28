#include <headers/dictionarycrack.h>

DictionaryCrack::DictionaryCrack(Hash* h, std::string file) {
	
	hashType = h;
    filename = file;
    digest = "";
}

QPointF DictionaryCrack::reverse() {
	
    plaintext = "";

	if(hashType == NULL) {
        return QPointF(-1,-1);
	}
	
    QElapsedTimer timer;
    long elapsed;
    timer.start();

    try {
        std::ifstream f;
        f.open(filename.c_str());
        std::string word;
        while(getline(f, word)) {
            hashType->plaintext = word;
            hashType->compute();

            if(digest.compare(hashType->digest) == 0) {
                plaintext = word;

                elapsed = timer.elapsed();
                return QPointF(word.length(), elapsed);
            }
        }
    } catch(int e) {
        std::cout << "error " << e << std::endl;
        return QPointF(-1,-1);
    }

    elapsed = timer.elapsed();
    return QPointF(0, elapsed);
}
