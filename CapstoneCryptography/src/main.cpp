#include "headers/mainwindow.h"
#include "headers/generateprimes.h"
#include "headers/primefactorization.h"
#include <QApplication>

void test() {

	cout<<"Testing for generateprimes and primefactorization."<<endl;
	GeneratePrimes gp = GeneratePrimes(1000);
	gp.generate();
	gp.printPrimes();
	
	PrimeFactorization pf = PrimeFactorization();
		
	long* primeFactors = pf.bruteForceFactor(77);//7*11
	cout<<primeFactors[0]<<","<<primeFactors[1]<<endl;
	
	long* primeFactors1 = pf.bruteForceFactor(187); //11*17
	cout<<primeFactors1[0]<<","<<primeFactors1[1]<<endl;
	
	long* primeFactors2 = pf.bruteForceFactor(101767); //149*683
	cout<<primeFactors2[0]<<","<<primeFactors2[1]<<endl;
	
	long* primeFactors3 = pf.bruteForceFactor(854429); //997*857
	cout<<primeFactors3[0]<<","<<primeFactors3[1]<<endl;
	
	long* primeFactors4 = pf.bruteForceFactor(99460729); //9973*9973
	cout<<primeFactors4[0]<<","<<primeFactors4[1]<<endl;
}

int main(int argc, char *argv[])
{
  /*  if(argc == 2  && *argv[1] == 't') {
		cout<<"Begin testing"<<endl;		
		test(); //run tests
    } else { */

		QApplication a(argc, argv);
		MainWindow w;
		w.show();

		return a.exec();
    //}
}


