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
    else{
        QString t = QString::fromStdString(agame->currentGuess);
        ui->textEdit->setText(t);
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    //Somehow give a hint to the player.
    ui->textEdit->setText("Here's a hint: There are no hints");
}

void MainWindow::on_factorPrimesButton_clicked()
{
    //reset label text
    ui->resultLabel->setText(QString::fromStdString("Result:"));
    ui->timeLabel->setText(QString::fromStdString("Time: "));
    ui->resultLabel->repaint();
    ui->timeLabel->repaint();

	QElapsedTimer timer;
	
    mpz_class composite;
    string s = ui->compositeTextField->text().toStdString();
    composite.set_str(s, 10);
    PrimeFactorization pf = PrimeFactorization();
    
    timer.start();
    pf.bruteForceFactor(composite);
    long elapsed = timer.elapsed();
    
    string s2 = "Time: " + QString::number(elapsed).toStdString() + " ms";
    ui->timeLabel->setText(QString::fromStdString(s2));
    
    s = "Result: " + pf.p1.get_str(10) + " * " + pf.p2.get_str(10);
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
