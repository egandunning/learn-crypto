#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1

#include <cryptopp/sha.h>
#include <cryptopp/md5.h>
#include <cryptopp/tiger.h>

#include <cryptopp/hex.h>
//#include <cryptopp/stringsource.h>
//#include <cryptopp/stringsink.h>
#include <cryptopp/filters.h>
//#include <cryptopp/hashtransformation.h>

#include <ctime>
#include <string>
#include <iostream>

using CryptoPP::SHA1;
using CryptoPP::Weak::MD5;
using CryptoPP::Tiger;

using CryptoPP::HexEncoder;
using CryptoPP::StringSource;
using CryptoPP::StringSink;
using CryptoPP::HashFilter;
using CryptoPP::HashTransformation;

using std::clock;
using std::clock_t;
using std::string;
using std::cout;
using std::cin;
using std::endl;
