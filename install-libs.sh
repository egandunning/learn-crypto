#!bin/bash
#Downloads and installs required libraries for the learn-crypto repo
#install location: /usr/local

if [ ! -d ~/temporary ]; then
	mkdir ~/temporary
fi

cd ~/temporary

#gmp - GNU Multi Precision library, for big integers.
#https://gmplib.org/
if [ ! -d gmp-6.1.1.1 ]; then
	wget -O gmp.tar.bz2 https://ftp.gnu.org/gnu/gmp/gmp-6.1.1.tar.bz2
	bzip2 -d gmp.tar.bz2
	tar -xf gmp.tar
fi

cd gmp-6.1.1
./configure
make
make check
sudo make install

#crypto++ - C++ crypto library
#https://www.cryptopp.com/
cd ~/temporary
wget -O cryptopp.zip https://www.cryptopp.com/cryptopp565.zip
unzip cryptopp.zip
make
make test
sudo make install
./cryptest.exe v
./cryptest.exe tv all

