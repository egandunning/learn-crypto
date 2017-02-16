/*
Header file for the Cipher class
*/
#include<map>
#include<string>
#include<vector>
#include<stdlib.h>
#include<ctime>
#include<cstdlib>
#include<sstream>

class Cipher {

public:
  std::string CipherType;
  //Cipher(std::map k, std::string name);
  Cipher(std::string, std::string);
  Cipher();
  char getChar(char);
  std::string encrypt(std::string);

private:
  std::map<char,char> Key;

};
