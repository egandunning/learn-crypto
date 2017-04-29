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
        srand(time(NULL));
        int index = rand() % lines.size();
        d_message = lines.at(index);

        /*
        std::ifstream hintsFile;
        hintsFile.open("../hints.txt");
        std::vector<std::string> allTheHints;

        while(getline(hintsFile,line)){
            allTheHints.push_back(line);
        }

        hint = allTheHints.at(index);
        */

    } catch (int e) {
        std::cout << "File io execption occurred: " << e << std::endl;
    }

    //Find another way to create a randomized key
    messageCipher = Cipher();

    //Encrypt the message and add it to the e_message
    e_message = messageCipher.encrypt(d_message);

    //Make the hint

    hint.append(1, e_message.at(0));
    hint.append(" is equal to ");
    hint.append(1, d_message.at(0));
    hint.append(" in this game.");
}

/**
 * @brief cryptogame::getEncryptedMessage
 * @return
 */
std::string cryptogame::getEncryptedMessage(){
    return e_message;
}

/**
 * @brief cryptogame::getHint
 * @return
 */
std::string cryptogame::getHint(){
    return hint;
}

/**
 * @brief cryptogame::sendCurrentGuess
 * @param g
 */
bool cryptogame::sendCurrentGuess(std::string g){

    if(0 == d_message.compare(g)){
        return true;
    }
    else{
        return false;
    }
}


/**
 * @brief cryptogame::~cryptogame
 */
cryptogame::~cryptogame() {
    //If there are any pointers in the future delete them here

}
