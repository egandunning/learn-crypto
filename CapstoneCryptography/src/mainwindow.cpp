#include "headers/mainwindow.h"
#include "headers/cryptogame.h"
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
    //delete hashAlg;
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

    //set algorithm
    int algChoice = ui->factorAlgChooser->currentIndex();
    Factor* pf;

    switch(algChoice) {
    case 0:
        pf = new BruteForceFactor(false);
        break;
    case 1:
        pf = new BruteForceFactor(true);
        break;
    }


    QElapsedTimer timer;
	
    mpz_class composite;
    string s = ui->compositeTextField->text().toStdString();
    composite.set_str(s, 10);

    
    timer.start();
    pf->factor(composite);
    long elapsed = timer.elapsed();
    
    string s2 = "Time: " + QString::number(elapsed).toStdString() + " ms";
    ui->timeLabel->setText(QString::fromStdString(s2));
    
    s = "Result: " + pf->p1.get_str(10) + " * " + pf->p2.get_str(10);
    ui->resultLabel->setText(QString::fromStdString(s));
    delete pf;
}

void MainWindow::on_random_composite_clicked()
{
    mpz_class composite, p, q;
    GeneratePrimes gp = GeneratePrimes();
    p = gp.readRandomPrime((char*)"primes.txt");
    q = gp.readRandomPrime((char*)"primes.txt");
    composite = p * q;
    string s = composite.get_str(10);
    ui->compositeTextField->setText(QString::fromStdString(s));
}

void MainWindow::on_hashButton_clicked()
{
    switch(ui->hashComboBox->currentIndex()) {
    case 0:
        hashAlg = new Md5();
        break;
    case 1:
        hashAlg = new Sha512();
        break;
    case 2:
        hashAlg = new Pbkdf2();
        break;
    }

    hashAlg->setPlaintext(ui->plaintextField->text());

    if(ui->saltField->text() != "") { //if not empty
        hashAlg->setSalt(ui->saltField->text());
    }
    hashAlg->compute();
    digest = hashAlg->getDigest();
    ui->digestField->setText(digest);

    //remove salt field so that crack doesn't "cheat"
    //i.e. cracking algorithm doesnt know salt value
    hashAlg->salt = "";
}

void MainWindow::on_randomSaltButton_clicked()
{
    Hash h;
    h.generateSalt(16);
    ui->saltField->setText(h.getSalt());
}

void MainWindow::on_crackButton_clicked()
{
    //reset label text
    ui->crackTimeLabel->setText("Time: ");
    ui->crackTimeLabel->repaint();

    QElapsedTimer timer;
    long elapsed;
    bool success;
    Crack* c;


    switch(ui->crackComboBox->currentIndex()) {
    case 0:
        {int maxLength = ui->charCountSpinBox->text().toInt();
        c = new BruteForceCrack(hashAlg,bruteForceAlphabet(), maxLength);
        break;}

    case 1:
        {c = new DictionaryCrack(*hashAlg, "../dictionary.txt");
        break;}
    }

    c->digest = digest.toStdString();

    timer.start();
    success = c->reverse();
    elapsed = timer.elapsed();

    if(success) {
        ui->crackedField->setText(QString::fromStdString(c->plaintext));
    } else {
        ui->crackedField->setText("\"Uncrackable!!\"");
    }

    string s = "Time: " + QString::number(elapsed).toStdString() + " ms";
    ui->crackTimeLabel->setText(QString::fromStdString(s));
}

std::string MainWindow::bruteForceAlphabet() {

    std::string alph = " ";

    if(ui->customCheckBox->isChecked()) {
        return ui->alphabetField->text().toStdString();
    }
    if(ui->lettersCheckBox->isChecked()) {
        alph += "abcdefghijklmnopqrstuvwxyz";
    }
    if(ui->upCaseCheckBox->isChecked()) {
        alph += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    }
    if(ui->numbersCheckBox->isChecked()) {
        alph += "1234567890";
    }
    if(ui->symbolsCheckBox->isChecked()) {
        alph += "`~!@#$%^&*()_+-=,.<>/?'[]{}";
    }
    return alph;
}


