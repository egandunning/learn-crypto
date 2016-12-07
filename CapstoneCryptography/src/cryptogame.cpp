#include "headers/cryptogame.h"



/**
 * @brief cryptogame::cryptogame
 */
cryptogame::cryptogame()
{
    //Find a way to randomize the messages. And hold that in l.
    try {

        std::ifstream fp;
        fp.open("../quotes.txt");
        std::string line;
        std::vector<std::string> lines;

        while(getline(fp, line)) {
            lines.push_back(line);
        }

        int index = rand() % lines.size();
        d_message = lines.at(index);

    } catch (int e) {
        std::cout << "File io execption occurred: " << e << std::endl;
    }

    //Find another way to create a randomized key
    messageCipher = Cipher();

    //Encrypt the message and add it to the e_message
    e_message = messageCipher.encrypt(d_message);
    currentGuess = e_message;


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

    currentGuess = g;
    int t = 0;
    for(char& c : currentGuess){
        if(c == d_message[t]){
            currentGuess[t] = toupper(c);
        }
        else{
            currentGuess[t] = tolower(c);
        }
        t+= 1;
    }

    if(0 == d_message.compare(g)){
        return true;
    }
    else{
        return false;
    }
}

/**
 * Code to grab a random message for the constructor.
 * @brief cryptogame::getRandomMessage
 * @return
 */
std::string cryptogame::getRandomMessage(){
    int randomNumber = rand()*2000;
    return "";
}

/**
 * @brief cryptogame::~cryptogame
 */
cryptogame::~cryptogame() {
    //If there are any pointers in the future delete them here

}
