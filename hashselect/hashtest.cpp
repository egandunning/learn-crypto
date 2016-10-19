#include "hashtest.h"

int main(int argc, char** argv) {
	
	string source = "Hello world";
	string result;
	int hashChoice = 0;
	int digestSize = 0;
	double duration;
	clock_t start;
	HashTransformation* hash;
	
	if(argc == 2) {
		source = argv[1];
	}
	
	cout << "Choose a hash function to use:" << endl;
	cout << "(1) SHA1" << endl;
	cout << "(2) SHA2" << endl;
	cout << "(3) MD5" << endl;
	cout << "(4) Tiger" << endl;
	cout << "Your choice: ";
	cin >> hashChoice;
	
	switch(hashChoice) {
	case 1:
		hash = new SHA1;
		break;
	case 2:
		
		//SHA2 has multiple digest sizes, query user to choose one.
		cout << "Choose digest(hash value) size:" << endl;
		cout << "(1) 224 bits" << endl;
		cout << "(2) 256 bits" << endl;
		cout << "(3) 384 bits" << endl;
		cout << "(4) 512 bits" << endl;
		cout << "Your choice: ";
		cin >> digestSize;
		switch(digestSize) {
		case 1:
			hash = new CryptoPP::SHA224;
			break;
		case 2:
			hash = new CryptoPP::SHA256;
			break;
		case 3:
			hash = new CryptoPP::SHA384;
			break;
		default:
			hash = new CryptoPP::SHA512;
			break;
		}
		
		break;
	case 3:
		hash = new MD5;
		break;
	case 4:
		hash = new Tiger;
		break;
	default:
		exit(0);
	}
	
	//compute hash	
	start = clock();
	StringSource ss(source, true, new HashFilter(*hash, new HexEncoder(new StringSink(result))));
	duration = (clock() - start) / (double) CLOCKS_PER_SEC;
	
	cout << "Plaintext: " << source << endl;
	cout << "Hash: " << result << endl;
	cout << "Elapsed time: " << duration << endl;
	
}