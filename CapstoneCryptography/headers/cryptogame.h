#ifndef CRYPTOGAME_H
#define CRYPTOGAME_H
#include<string>
#include<headers/Cipher.h>


class cryptogame
{
public:
    cryptogame();
    std::string getEncryptedMessage();
    bool sendCurrentGuess(std::string g);

private:
    std::string d_message;
    std::string e_message;
    Cipher messageCipher;
    std::string currentGuess;

};

#endif // CRYPTOGAME_H
