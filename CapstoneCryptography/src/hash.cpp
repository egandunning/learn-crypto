#include <headers/hash.h>

Hash::Hash(CryptoPP::HashTransformation* h) {
    this->hashType = h;
    plaintext = "";
    digest = "";
    saltlen = 0;
    salt = "";
}

Hash::Hash(){
    this->hashType = new CryptoPP::SHA1();
    name = "SHA 1";
}

Hash::Hash(const Hash &h) {
    saltlen = h.saltlen;
    salt = h.salt;
    plaintext = h.plaintext;
    digest = h.digest;
    name = h.name;
    hashType = h.hashType;
}

Hash& Hash::operator=(const Hash& h) {
    saltlen = h.saltlen;
    salt = h.salt;
    plaintext = h.plaintext;
    digest = h.digest;
    name = h.name;
    hashType = h.hashType;
    return *this;
}

Hash::~Hash() {
    if(hashType != NULL) {
        delete hashType;
    }
}

void Hash::compute() {

    digest = "";
    using CryptoPP::StringSource;
    using CryptoPP::HashFilter;
    using CryptoPP::HexEncoder;
    using CryptoPP::StringSink;

    StringSource(salt + plaintext, true, new HashFilter(*hashType, new HexEncoder(new StringSink(digest))));
}

void Hash::generateSalt(int len) {

    unsigned char* buf = new unsigned char[len];

    CryptoPP::AutoSeededX917RNG<CryptoPP::DES> securePrg;
    securePrg.GenerateBlock(buf, len);

    //hex encoding
    salt = "";
    using CryptoPP::StringSource;
    using CryptoPP::StringSink;
    using CryptoPP::HexEncoder;
    StringSource ss(buf, len, true, new HexEncoder(new StringSink(salt)));
}

void Hash::setPlaintext(QString s) {
    plaintext = s.toStdString();
}

void Hash::setSalt(QString s) {
    salt = s.toStdString();
}

QString Hash::getDigest() {
    return QString::fromStdString(digest);
}

QString Hash::getPlaintext() {
    return QString::fromStdString(plaintext);
}

QString Hash::getSalt() {
    return QString::fromStdString(salt);
}
