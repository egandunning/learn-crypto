#include "headers/mainwindow.h"
#include "headers/primefactorization.h"
#include "headers/cryptogame.h"
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

void MainWindow::on_pushButton_clicked()
{
    std::cout<<"Start the game."<<std::endl;
    agame = new cryptogame();
    QString q = QString::fromStdString(agame->getEncryptedMessage());
    ui->label->setText(q);

}

void MainWindow::on_pushButton_2_clicked()
{
    QString temp = ui->textEdit->toPlainText();
    std::string send = temp.toStdString();

    bool win = agame->sendCurrentGuess(send);

    /*
    //Debugging stuffs
    std::cout<<win<<std::endl;
    std::cout<<temp.toStdString()<<std::endl;
    std::cout<<agame->d_message<<std::endl;
    */

    if(win){
        //Call a victory condition here. Something nice.
        ui->textEdit->setText("You won! yay!");
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    //Somehow give a hint to the player.
    ui->textEdit->setText("Here's a hint: There are no hints");
}

void MainWindow::on_factorPrimesButton_clicked()
{
	using std::cout;
	using std::endl;
	
	cout<< "'Factor Primes' button pressed" <<endl;
	mpz_class composite, p, q;
	GeneratePrimes gp = GeneratePrimes();
	p = gp.readRandomPrime("primes.txt");
	q = gp.readRandomPrime("primes.txt");
	composite = p * q;
	
	cout << p.get_str(10) << " * " << q.get_str(10) << " = " << composite.get_str(10) << endl;
	
	cout << "Number to factor: " << composite.get_str(10) << endl;
	
	PrimeFactorization pf = PrimeFactorization();
	pf.bruteForceFactor(composite);
	
	cout << "factor 1: " << pf.p1.get_str(10) << endl;
	cout << "factor 2: " << pf.p2.get_str(10) << endl;
}
