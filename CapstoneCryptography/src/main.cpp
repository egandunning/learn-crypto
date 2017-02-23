#include <headers/mainwindow.h>
#include <headers/generateprimes.h>
#include <headers/bruteforcefactor.h>
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
