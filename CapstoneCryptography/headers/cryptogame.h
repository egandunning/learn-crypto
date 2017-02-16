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
    bool sendCurrentGuess(std::string g);
    std::string d_message;
    std::string currentGuess;



private:
    //std::string d_message;
    std::string e_message;
    Cipher messageCipher;
    std::string getRandomMessage();

};

#endif // CRYPTOGAME_H
