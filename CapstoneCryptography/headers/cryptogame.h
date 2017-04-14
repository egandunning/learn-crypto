#ifndef CRYPTOGAME_H
#define CRYPTOGAME_H
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<stdio.h>
#include<headers/cipher.h>


class cryptogame
{
public:
    cryptogame();
    ~cryptogame();
    std::string getEncryptedMessage();
    std::string getHint();
    bool sendCurrentGuess(std::string g);




private:
    //std::string d_message;
    std::string e_message;
    Cipher messageCipher;
    std::string d_message;
    std::string hint;

};

#endif // CRYPTOGAME_H
