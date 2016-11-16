/*
Cipher class to test the Keyword Cipher.

*/
#include<map>
#include<string>
#include<vector>
#include<stdlib.h>
#include<ctime>
#include<cstdlib>
#include<sstream>
#include"headers/Cipher.h"


//String holds the name of the Cipher type for reference.
std::string CipherType;
//Map holds the relation from the character in the text to the character
//that is in the message.
std::map<char, char> Key;

Cipher::Cipher(std::string keyword, std::string name){
	  //Set the name of the Cipher
	  CipherType = name;
      //Do something to generate a random Key.
	  char currentLetter = 'A';

	  for (int i = 0; i < keyword.size(); i++) {
		  Key[keyword[i]] = 'A' + i;
	  }

    for(int i = 0; i< 26 -keyword.size(); i++){
      std::map<char,char>::iterator it = Key.find('A' + i);
      if(it != Key.end()){
        continue;
      }
      else{
      Key['A' + i] = 'A' + keyword.size() + i;
    }
    }


}
Cipher::Cipher(){

}

  char Cipher::getChar(char in){
    return Key[in];
  }

  std::string Cipher::encrypt(std::string in){
    std::string ret = "";
    for(int i = 0; i< in.size(); i++){
      if(in[i] == ' '){
        ret+= ' ';
        continue;
      }
      char temp = in[i];
      temp = getChar(temp);
      ret += temp;
    }
    return ret;
  }
