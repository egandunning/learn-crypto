#include <headers/dictionarycrack.h>

DictionaryCrack::DictionaryCrack(Hash* h, std::string file) {
	
	hashType = h;
    filename = file;
    digest = "";
}

int DictionaryCrack::reverse() {
	
	if(hashType == NULL) {
		return 0;
	}
	
    try {
        std::ifstream f;
        f.open(filename.c_str());
        std::string word;
        while(getline(f, word)) {
            hashType->plaintext = word;
            hashType->compute();

            if(digest.compare(hashType->digest) == 0) {
                plaintext = word;

                return 1;
            }
        }
    } catch(int e) {
        std::cout << "error " << e << std::endl;
        return 0;
    }

    return 0;
}
