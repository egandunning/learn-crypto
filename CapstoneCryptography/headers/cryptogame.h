#ifndef CRYPTOGAME_H
#define CRYPTOGAME_H
#include<string>
#include<headers/Cipher.h>


class cryptogame
{
public:
    cryptogame();
    std::string getEncryptedMessage();
    std::string sendCurrentGuess(Cipher g);
    bool winCondition();

private:
    std::string d_message;
    std::string e_message;
    Cipher messageCipher;
    std::string currentGuess;

};

#endif // CRYPTOGAME_H
