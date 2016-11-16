#include "headers/mainwindow.h"
#include "headers/cryptogame.h"
#include "headers/primefactorization.h"
#include "headers/generateprimes.h"
#include "ui_mainwindow.h"
#include "QPushButton"

#include "iostream" //for debugging

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_GPUCheckBox_clicked()
{

}

void MainWindow::on_factorPrimesButton_clicked()
{
	using std::cout;
	using std::endl;
	
	cout<< "'Factor Primes' button pressed" <<endl;
	
	GeneratePrimes gp = GeneratePrimes(10000);
	gp.generate();
	long composite = gp.randomPrime() * gp.randomPrime();
	
	cout << "Number to factor: " << endl << composite;
	
	PrimeFactorization pf = PrimeFactorization();
	long* primes = pf.bruteForceFactor(composite);
	
	cout << "=" << primes[0] <<	"*" << primes[1] << endl;
}
