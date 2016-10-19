/*
Cipher class to test the Keyword Cipher.

*/
#include<std::map>
#include<std::string>
#include<stdlib.h>

class Cipher
{

//String holds the name of the Cipher type for reference.
std::string CipherType;
//Map holds the relation from the character in the text to the character
//that is in the message.
std::map<char, char> Key;

  Cipher::Cipher(){
  //Do something to generate a random Key.

}

  Cipher::Cipher(map k){
    //Sets the imported map that already has a key to Key.
    Key = k;
    CipherType = "Keyword";
  }



}
