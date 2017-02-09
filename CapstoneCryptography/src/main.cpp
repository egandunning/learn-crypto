#include <headers/mainwindow.h>
#include <headers/generateprimes.h>
#include <headers/primefactorization.h>
#include <headers/cryptogame.h>
//#include <headers/crack.h>
#include <headers/bruteforcecrack.h>
#include <headers/dictionarycrack.h>
#include <headers/sha512.h>
#include <headers/md5.h>
#include <headers/pbkdf2.h>
#include <QApplication>
#include <string>

void test();
void init();

int main(int argc, char *argv[])
{
    ifstream fp;
    fp.open("primes.txt");
    if(!fp.is_open()) {
        cout << "List of prime numbers not found!" << endl;
        init();
    }

    if(argc == 2  && strcmp(argv[1], "test") == 0) {

        cout<<"Begin testing"<<endl;
        test(); //run tests

    } else if(argc == 2 && strcmp(argv[1], "init") == 0) {

        init();

    } else {

        QApplication a(argc, argv);
        MainWindow w;
        w.resize(1000, 1000);
        w.show();

        return a.exec();
    }
}

/*** TESTING ****/

void test() {

//////Hash functions
    //sha512
    cout<<"\nSHA-512"<<endl;
    Sha512 sha = Sha512();
    sha.plaintext = "hello there";
    sha.compute();
    cout << "Plaintext: " << sha.plaintext << "\nDigest: " << sha.digest << endl;

    sha.plaintext = "Hello there";
    sha.compute();
    cout << "Plaintext: " << sha.plaintext << "\nDigest: " << sha.digest << endl;

    cout << "\nSalted SHA-512" << endl;
    Sha512 shaSalt = Sha512();
    shaSalt.plaintext = "hello there";
    shaSalt.generateSalt(64);
    shaSalt.compute();
    cout << "Salt + Plaintext: " << shaSalt.salt << shaSalt.plaintext << "\nDigest: " << shaSalt.digest << endl;

    shaSalt.plaintext = "Hello there";
    shaSalt.compute();
    cout << "Salt + Plaintext: " << shaSalt.salt << shaSalt.plaintext << "\nDigest: " << shaSalt.digest << endl;

    //md5
    cout<<"\nMD5"<<endl;
    Md5 md = Md5();
    md.plaintext = "hello there";
    md.compute();
    cout << "Plaintext: " << md.plaintext << "\nDigest: " << md.digest << endl;

    md.plaintext = "Hello there";
    md.compute();
    cout << "Plaintext: " << md.plaintext << "\nDigest: " << md.digest << endl;

    cout<<"\nSalted MD5"<<endl;
    Md5 mdSalt = Md5();
    mdSalt.plaintext = "hello there";
    mdSalt.generateSalt(64);
    mdSalt.compute();
    cout << "Salt + Plaintext: " << mdSalt.salt << mdSalt.plaintext << "\nDigest: " << mdSalt.digest << endl;

    mdSalt.generateSalt(64);
    mdSalt.compute();
    cout << "Salt + Plaintext: " << mdSalt.salt << mdSalt.plaintext << "\nDigest: " << mdSalt.digest << endl;

    mdSalt.plaintext = "Hello there";
    mdSalt.compute();
    cout << "Salt + Plaintext: " << mdSalt.salt << mdSalt.plaintext << "\nDigest: " << mdSalt.digest << endl;

    //pdkdf2
    cout<<"\nPBKDF2"<<endl;
    Pbkdf2 kdf = Pbkdf2();
    kdf.salt = "";
    kdf.plaintext = "Hello there";
    kdf.compute();
    cout << "Plaintext: " << kdf.plaintext << "\nDigest: " << kdf.digest << endl;

    kdf.generateSalt(64);
    kdf.plaintext = "Hello there";
    kdf.compute();
    cout << "Plaintext: " << kdf.plaintext << "\nDigest: " << kdf.digest << endl;

//////Prime number generation
    cout<<"Testing for generateprimes and primefactorization."<<endl;
    GeneratePrimes gp = GeneratePrimes();

    cout << "random prime: " << gp.readRandomPrime("primes.txt") << endl;
    cout << "random prime: " << gp.readRandomPrime("primes.txt") << endl;
    cout << "random prime: " << gp.readRandomPrime("primes.txt") << endl;
    cout << "random prime: " << gp.readRandomPrime("primes.txt") << endl;

//////Hash cracking
    cout << "\nTesting for hash cracking classes." << endl;

    cout<< "Brute force" << endl;
    Md5 m = Md5();
    Crack* c = new BruteForceCrack(m,"abcdefghijklmnopqrstuvwxyz", 3);

    m.plaintext = "hi";
    m.compute();
    c->digest = m.digest;
    c->reverse();
    cout << "Digest: " << c->digest << " Plaintext: " << c->plaintext << endl;

    cout << endl;
    cout << "Dictionary" << endl;

    Md5 m1 = Md5();
    DictionaryCrack d(m1, "../dictionary.txt");
    m1.plaintext = "gorilla";
    m1.compute();
    d.digest = m1.digest;
    d.reverse();
    cout << "Digest: " << d.digest << " Plaintext: " << d.plaintext << endl;

    cout << endl;


//////Factoring
    PrimeFactorization pf = PrimeFactorization(0);

    mpz_class comp;
    comp = 77;
    cout << "number to factor: " << comp.get_str(10) << endl;

    pf.factor(comp);//7*11
    cout << "factors: ";
    cout << pf.p1.get_str(10) << " ";
    cout << pf.p2.get_str(10) << endl;

    mpz_class p, q;
    p = gp.readRandomPrime("primes.txt");
    q = gp.readRandomPrime("primes.txt");
    comp = p * q;

    cout << "number to factor: " << p.get_str(10) <<" "<< q.get_str(10) << " = " << comp.get_str(10) << endl;

    pf.factor(comp);
    cout << "factors: ";
    cout << pf.p1.get_str(10) << " ";
    cout << pf.p2.get_str(10) << endl;

    p = gp.readRandomPrime("primes.txt");
    q = gp.readRandomPrime("primes.txt");
    comp = p * q;

    cout << "number to factor: " << p.get_str(10) <<" "<< q.get_str(10) << " = " << comp.get_str(10) << endl;

    pf.factor(comp);
    cout << "factors: ";
    cout << pf.p1.get_str(10) << " ";
    cout << pf.p2.get_str(10) << endl;


//////String conversion

    cout << "\nTest string to byte[] conversions" << endl;
    string test = "Hello world";
    cout << "std string: " << test << endl;
    cout << "after conversion to byte[]: ";
    unsigned char * testByte = new unsigned char(test.length());
    testByte = (unsigned char*)test.c_str();
    for(int i = 0; i < test.length(); i++) {
        cout << testByte[i];
    }
    cout << endl;

}

void init() {
    cout << "Begin initialization" << endl;
    int lowerBound = 500000;
    int upperBound = 10000000;
    GeneratePrimes gp = GeneratePrimes(lowerBound, upperBound);
    gp.generate();
    cout << "generate done: " << endl;
    cout << " primes from " << lowerBound << " to " << upperBound << " generated." << endl;
    gp.writePrimes("primes.txt");
    cout << "Prime numbers are in primes.txt" << endl;
}
