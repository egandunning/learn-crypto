#include "headers/cryptogame.h"



/**
 * @brief cryptogame::cryptogame
 */
cryptogame::cryptogame()
{
    //Find a way to randomize the messages.
    d_message = "FLEE WE ARE DISCOVERED";

    //Find another way to create a randomized key
    messageCipher = Cipher();

    //Encrypt the message and add it to the e_message
    e_message = messageCipher.encrypt(d_message);


}

/**
 * @brief cryptogame::getEncryptedMessage
 * @return
 */
std::string cryptogame::getEncryptedMessage(){
    return e_message;
}

/**
 * @brief cryptogame::sendCurrentGuess
 * @param g
 */
bool cryptogame::sendCurrentGuess(std::string g){

    return currentGuess;
}

