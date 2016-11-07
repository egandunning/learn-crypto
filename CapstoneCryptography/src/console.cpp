#include <iostream>
#include <string>
#include "headers/Cipher.h"

int main() {

	std::cout<<"Please Enter a Keyword for the Cipher using non-repeating letters:"<<std::endl;
	std::string keyword;
	std::cin >> keyword;

	std::string hello = "Keyword";

	Cipher k = Cipher(keyword, hello);

	std::cout<<"Please Enter a phrase you would like encrypted using your keyword:"<<std::endl;
	std::string phrase;
	std::cin.ignore();
	std::getline (std::cin, phrase);

	std::string encrypted = k.encrypt(phrase);

	std::cout<<encrypted<<std::endl;



	return 0;
}
