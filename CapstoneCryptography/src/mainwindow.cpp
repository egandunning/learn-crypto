#include "headers/mainwindow.h"
#include "headers/cryptogame.h"
#include "ui_mainwindow.h"
#include "QPushButton"
#include <QLayoutItem>
#include <QMessageBox>
#include "headers/buttonarray.h"
#include "headers/labelarray.h"

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

void MainWindow::on_pushButton_clicked()
{
    std::cout<<"Start the game."<<std::endl;

    //Delete all buttons in the layoutForButtons if there are existing buttons in the layout
    while(ui->layoutForButtons->count() > 0 || ui->layoutForLabels->count() > 0){
        if(ui->layoutForButtons->count() > 0){
        QLayoutItem *button = ui->layoutForButtons->takeAt(0);
        delete button->widget();
        delete button;
        }
        if(ui->layoutForLabels->count() > 0){
        QLayoutItem *label = ui->layoutForLabels->takeAt(0);
        delete label->widget();
        delete label;
        }
    }

    agame = new cryptogame();
    QString q = QString::fromStdString(agame->getEncryptedMessage());
    //ui->label->setText(q);
    LabelArray *lptr = new LabelArray(q, ui->tabWidget);
    ButtonArray *ptr = new ButtonArray(q, ui->tabWidget);
    for(int i=0; i<q.size(); i++){
        ui->layoutForLabels->addWidget(lptr->get(i));
        ui->layoutForButtons->addWidget(ptr->get(i));
    }
    guessedWord.clear();
    guessedWord = ptr->checkGuess();

}

void MainWindow::on_pushButton_2_clicked()
{

    QString temp = guessedWord;
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
        QMessageBox winningMessage;
        winningMessage.setText("You won! Yay!                                               ");
        winningMessage.exec();
        //ui->textEdit->setText("You won! yay!");
    }
    else{
        QMessageBox winningMessage;
        winningMessage.setText("You are not correct.                                               ");
        winningMessage.exec();
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    //Somehow give a hint to the player.
    QMessageBox winningMessage;
    //Note: there are tabs in the QString in the next sentence
    winningMessage.setText("Here's a hint: There are no hints                                             ");
    winningMessage.exec();
   // ui->textEdit->setText("Here's a hint: There are no hints");
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
    ui->crackedField->setText("");
    ui->crackedField->repaint();

    QElapsedTimer timer;
    long elapsed;
    bool success;
    Crack* c;
    if(hashAlg == NULL) {
    	return;
    }


    switch(ui->crackComboBox->currentIndex()) {
    case 0:
        {int maxLength = ui->charCountSpinBox->text().toInt();
        c = new BruteForceCrack(hashAlg,bruteForceAlphabet(), maxLength);
        break;}

    case 1:
        {c = new DictionaryCrack(hashAlg, "../dictionary.txt");
        dictionaryOptions(c);
        break;}
    }

    c->digest = digest.toStdString();

    timer.start();
    c->reverse();
    success = c->getPlaintext().length();
    elapsed = timer.elapsed();

    //if
    if(success) {
        ui->crackedField->setText(c->getPlaintext());
    } else {
        ui->crackedField->setText("\"Uncrackable!!\"");
    }

    string s = "Time: " + QString::number(elapsed).toStdString() + " ms";
    ui->crackTimeLabel->setText(QString::fromStdString(s));
}

std::string MainWindow::bruteForceAlphabet() {

    std::string alph = " ";//weird bug "fix"

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

void MainWindow::dictionaryOptions(Crack* d) {

    unsigned int numWords = ui->wordCountSpinBox->text().toInt();
    unsigned int appendedDigits = 0;
    if(ui->appendCheckBox->isChecked()) {
        appendedDigits = ui->digitCountSpinBox->text().toInt();
    }
    unsigned int prependedDigits = 0;
    if(ui->prependCheckBox->isChecked()) {
        prependedDigits = ui->digitCountSpinBox->text().toInt();
    }
    unsigned int symbols = 0;
    unsigned int cap = false;

    d->setOptions(numWords,appendedDigits,prependedDigits,symbols,cap);
}

void MainWindow::on_drawFactoring_clicked()
{
    //generate data
    int beginDigits = ui->startDigitsSpinBox->text().toInt();
    int count = ui->dataPointsSpinBox->text().toInt();
    std::vector<mpz_class> comps = GenerateData::composites(beginDigits, count);
    std::vector<QPointF> pts = GenerateData::factor(comps, new BruteForceFactor);

    //draw points
    g = new GraphWindow(ui->factoringGraphicsView, pts);
    g->vSize = 600;
    g->hSize = 600;

    if(ui->factorLogScaleCheckBox->isChecked()) {
        g->logScaleDraw();
    } else {
        g->draw();
    }
    g->addLabels("Milliseconds", "Number of digits");

    g->view->show();
}

void MainWindow::on_plotCrackButton_clicked()
{
    //grab hashing and cracking algorithms

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

    Crack* c;
    if(hashAlg == NULL) {
        return;
    }

    switch(ui->crackComboBox->currentIndex()) {
    case 0:
        {int maxLength = ui->charCountSpinBox->text().toInt();
        c = new BruteForceCrack(hashAlg,bruteForceAlphabet(), maxLength);
        break;}

    case 1:
        {c = new DictionaryCrack(hashAlg, "../dictionary.txt");
        break;}
    }



    //generate data
    int beginChars = ui->charCountSpinBox_2->text().toInt();
    int count = ui->crackPointCountSpinBox->text().toInt();
    std::vector<std::string> strings = GenerateData::plaintexts(beginChars, count);
    std::vector<std::string> digests = GenerateData::getHashes(strings, hashAlg);
    std::vector<QPointF> pts = GenerateData::crack(digests, c);

    //begin graphing
    g = new GraphWindow(ui->crackGraphicsView, pts);
    g->vSize = 600;
    g->hSize = 600;

    if(ui->hashLogScaleCheckBox->isChecked()) {
        g->logScaleDraw();
    } else {
        g->draw();
    }
    g->addLabels("Milliseconds", "Number of characters");

    g->view->show();
}
