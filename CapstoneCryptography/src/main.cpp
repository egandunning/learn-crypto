#include "headers/mainwindow.h"
#include "headers/generateprimes.h"
#include "headers/primefactorization.h"
#include "headers/cryptogame.h"
#include <QApplication>
#include <string>

void test() {

    cout<<"Testing for generateprimes and primefactorization. And the cryptogame class testing."<<endl;
	GeneratePrimes gp = GeneratePrimes();

	cout << "random prime: " << gp.readRandomPrime("primes.txt") << endl;
	cout << "random prime: " << gp.readRandomPrime("primes.txt") << endl;
	cout << "random prime: " << gp.readRandomPrime("primes.txt") << endl;
	cout << "random prime: " << gp.readRandomPrime("primes.txt") << endl;
	
	PrimeFactorization pf = PrimeFactorization();
	
	mpz_class comp;
	comp = 77;
	cout << "number to factor: " << comp.get_str(10) << endl;
	
	pf.bruteForceFactor(comp);//7*11
	cout << "factors: ";
	cout << pf.p1.get_str(10) << " ";
	cout << pf.p2.get_str(10) << endl;
	
	mpz_class p, q;
	p = gp.readRandomPrime("primes.txt");
	q = gp.readRandomPrime("primes.txt");
	comp = p * q;
	
	cout << "number to factor: " << p.get_str(10) <<" "<< q.get_str(10) << " = " << comp.get_str(10) << endl;
	
	pf.bruteForceFactor(comp);
	cout << "factors: ";
	cout << pf.p1.get_str(10) << " ";
	cout << pf.p2.get_str(10) << endl;
	
	/*long* primeFactors1 = pf.bruteForceFactor(187); //11*17
	cout<<primeFactors1[0]<<","<<primeFactors1[1]<<endl;
	
	long* primeFactors2 = pf.bruteForceFactor(101767); //149*683
	cout<<primeFactors2[0]<<","<<primeFactors2[1]<<endl;
	
	long* primeFactors3 = pf.bruteForceFactor(854429); //997*857
	cout<<primeFactors3[0]<<","<<primeFactors3[1]<<endl;
	
	long* primeFactors4 = pf.bruteForceFactor(99460729); //9973*9973
	cout<<primeFactors4[0]<<","<<primeFactors4[1]<<endl;*/

}

int main(int argc, char *argv[])
{
	
    if(argc == 2  && strcmp(argv[1], "test") == 0) {
    	
		cout<<"Begin testing"<<endl;		
		test(); //run tests
		
	} else if(argc == 2 && strcmp(argv[1], "init") == 0) {
		
		cout << "Begin initialization" << endl;
		GeneratePrimes gp = GeneratePrimes(500000, 10000000);
		cout << "constructor done" << endl;
		gp.generate();
		cout << "generate done" << endl;
		gp.writePrimes("primes.txt");
		cout << "Prime numbers are in primes.txt" << endl;
		return 0;
		
    } else {

		QApplication a(argc, argv);
		MainWindow w;
		w.show();

		return a.exec();
    }
}


