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
#include"../headers/cipher.h"


//String holds the name of the Cipher type for reference.
std::string CipherType;
//Map holds the relation from the character in the text to the character
//that is in the message.
std::map<char, char> Key;

/**
 * @brief Cipher::Cipher
 * @param keyword
 * @param name
 *
 * Cipher constructor for a predetermined cipher, the user of this method will have to determine the type of cipher.
 */
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

/**
 * @brief Cipher::Cipher
 * Constructor for the Cipher class, this is the random Cipher type constructor. It generates a random Cipher.
 *
 */
Cipher::Cipher(){
    CipherType = "Random";
    char currentLetter = 'A';

    //Generate the map with all letters corresponding to themselves.
    for(int i = 0; i< 26; i++){

        Key['A' + i] = 'A' + i;

    }

    //Switches the letters a lot using random numbers and running the loop 1000 times.
    //Most likely a more efficient way to do this.
    for(int i = 0; i <10000; i++){
        int temp = rand()%25;
        char cur = 'A' + temp;
        int temp2 = rand()%25;
        char cur2 = 'A' + temp2;

        if(cur2 == cur){
            continue;
        }
        else{
            char t = Key[cur];
            Key[cur] = Key[cur2];
            Key[cur2] = t;
        }
    }
}

  char Cipher::getChar(char in){
    return Key[in];
  }
  /**
   * @brief Cipher::encrypt
   * @param in
   * @return
   *
   * Method to encrypt some string, returns a string with the encrypted text. The input string must be lowercase!
   */
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
