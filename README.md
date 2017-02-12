# learn-crypto
PLU Computer Science Capstone project 2016-2017. 

A cryptography learning tool.


###Contributors: Quinton Teas, Egan Dunning, Philip Passantino

###Dependencies:
Gnu Multi Precision Arithmetic Library https://gmplib.org/

Crypto++ Library https://www.cryptopp.com/

To use the dictionary crack functionality, the user must provide
thier own dictionary. On linux, generate the dictionary with this
command (assuming the learn-crypto project is in the home folder): 

`$ cat /usr/share/dict/words | grep -v .*\'s > ~/learn-crypto/dictionary.txt`

