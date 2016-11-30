#ifndef CRYPTOGAME_H
#define CRYPTOGAME_H
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<headers/Cipher.h>


class cryptogame
{
public:
    cryptogame();
    std::string getEncryptedMessage();
    bool sendCurrentGuess(std::string g);
    std::string d_message;



private:
    //std::string d_message;
    std::string e_message;
    Cipher messageCipher;
    std::string currentGuess;
    std::string getRandomMessage();

};

#endif // CRYPTOGAME_H
