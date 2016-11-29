#include "headers/mainwindow.h"
#include "headers/cryptogame.h"
#include "headers/primefactorization.h"
#include "headers/generateprimes.h"
#include "ui_mainwindow.h"
#include "QPushButton"
#include "gmpxx.h"

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
    cryptogame agame = cryptogame();
    std::cout<<agame.getEncryptedMessage()<<std::endl;

}

void MainWindow::on_factorPrimesButton_clicked()
{
    mpz_class composite;
    string s = ui->compositeTextField->text().toStdString();
    composite.set_str(s, 10);
    PrimeFactorization pf = PrimeFactorization();
    pf.bruteForceFactor(composite);
    s = pf.p1.get_str(10) + " * " + pf.p2.get_str(10);
    ui->resultLabel->setText(QString::fromStdString(s));
}

void MainWindow::on_random_composite_clicked()
{
    mpz_class composite, p, q;
    GeneratePrimes gp = GeneratePrimes();
    p = gp.readRandomPrime("primes.txt");
    q = gp.readRandomPrime("primes.txt");
    composite = p * q;
    string s = composite.get_str(10);
    ui->compositeTextField->setText(QString::fromStdString(s));
}
