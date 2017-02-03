#include <headers/dictionarycrack.h>

DictionaryCrack::DictionaryCrack(Hash h, std::string file) {
    hashType = h;
    filename = file;
    digest = "";
}

int DictionaryCrack::reverse() {
    try {
        std::ifstream f;
        f.open(filename);
        std::string word;
        while(getline(f, word)) {
            hashType.plaintext = word;
            hashType.compute();

            if(digest.compare(hashType.digest) == 0) {
                plaintext = word;
                return 1;
            }
        }
        return 0;
    } catch(int e) {
        std::cout << "error " << e << std::endl;
    }
    return 0;
}
