#include "headers/mainwindow.h"
#include "headers/cryptogame.h"
#include "ui_mainwindow.h"
#include "QPushButton"
#include <QLayoutItem>
#include <QMessageBox>
#include <QtConcurrent/QtConcurrent>
#include <QFuture>
#include "headers/buttonarray.h"
#include "headers/labelarray.h"

#include "iostream" //for debugging

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    connect(&threadCrack, SIGNAL(finished()), this, SLOT(update_crack_result()));
    connect(&threadFactor, SIGNAL(finished()), this, SLOT(update_factor_result()));
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    threadCrack.quit();
    threadFactor.quit();
    //delete hashAlg;
}

void MainWindow::on_pushButton_clicked()
{
   // std::cout<<"Start the game."<<std::endl;

   // std::cout<<"Rows: " << ui->gameGrid->rowCount()<<std::endl;
    //std::cout<<"Columns: " << ui->gameGrid->columnCount()<<std::endl;

    /*if(buttonPtrs){
        delete buttonPtrs;
    } */

    //QLayoutItem *nullLayout = NULL;
    //Delete all buttons in the and labels in the gameGrid
   for(int i=0; i<ui->gameGrid->columnCount(); i++){

       QLayoutItem *button = ui->gameGrid->itemAtPosition(1,i);
       if(button){
          delete button->widget();
           //delete button;
           //QLayoutItem::~QLayoutItem();
        //std::cout<<"Deleting button number: " << i<<std::endl;
       }


        QLayoutItem *label = ui->gameGrid->itemAtPosition(0,i);
        if(label){
            delete label->widget();
        }
       /* delete label->widget();
        delete label;*/

    }

    agame = new cryptogame();
    QString q = QString::fromStdString(agame->getEncryptedMessage());
    //ui->label->setText(q);
    LabelArray *lptr = new LabelArray(q, ui->tabWidget);
    ButtonArray *buttonPtrs = new ButtonArray(q, ui->tabWidget, agame);
    for(int i=0; i<q.size(); i++){
        ui->gameGrid->addWidget(lptr->get(i), 0, i);
        ui->gameGrid->addWidget(buttonPtrs->get(i), 1, i);
    }
    guessedWord.clear();
    guessedWord = buttonPtrs->checkGuess();

}

void MainWindow::on_pushButton_2_clicked(){}

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
        pf = new BruteForceFactor();
        break;
    case 1:
        //Quadratic sieve here
        std::cout<<"Quadratic sieve feature is in progress!"<<std::endl;
        return;
        break;
    }
	
    mpz_class composite;
    string s = ui->compositeTextField->text().toStdString();
    composite.set_str(s, 10);

    threadFactor.setFactor(pf, composite);
    threadFactor.work();

    ui->factorPrimesButton->setDisabled(true);
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

    //Perhaps make this an option?
    //hashAlg->salt = "";
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

    Crack* c;
    if(hashAlg == NULL) {
    	return;
    }


    switch(ui->crackTabWidget->currentIndex()) {
    case 0:
        {int maxLength = ui->charCountSpinBox->text().toInt();
        c = new BruteForceCrack(hashAlg,bruteForceAlphabet(), maxLength);
        break;}

    case 1:
        {c = new DictionaryCrack(hashAlg, "../dictionary.txt");
        dictionaryOptions(c);
        break;}
    }

    c->setDigest(digest);

    threadCrack.setCrackType(c);
    threadCrack.work();

    ui->crackButton->setDisabled(true);
}

void MainWindow::update_crack_result() {

    long elapsed;
    bool success;

    elapsed = threadCrack.getResult();
    Crack* c = threadCrack.getCrack();
    success = c->getPlaintext().length();


    if(success) {
        ui->crackedField->setText(threadCrack.getCrack()->getPlaintext());
    } else {
        ui->crackedField->setText("\"Uncrackable!!\"");
    }

    string s = "Time: " + std::to_string(elapsed) + " ms";
    ui->crackTimeLabel->setText(QString::fromStdString(s));

    ui->crackButton->setDisabled(false);
}

void MainWindow::update_factor_result() {

    long elapsed = threadFactor.getResult();
    Factor* pf = threadFactor.getFactor();

    string s = "Time: " + std::to_string(elapsed) + " ms";
    ui->timeLabel->setText(QString::fromStdString(s));

    s = "Result: " + pf->p1.get_str(10) + " * " + pf->p2.get_str(10);
    ui->resultLabel->setText(QString::fromStdString(s));

    ui->factorPrimesButton->setDisabled(false);
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

    bool cap = ui->capCheckBox->isChecked();
    bool symbols = ui->dictSymbolsCheckBox->isChecked();
    bool complete = ui->completeModeCheckBox->isChecked();

    d->setOptions(numWords,appendedDigits,prependedDigits,symbols,cap,complete);
}

void MainWindow::on_drawFactoring_clicked()
{
    //generate data
    int beginDigits = ui->startDigitsSpinBox->text().toInt();
    int count = ui->dataPointsSpinBox->text().toInt();
    std::vector<mpz_class> comps = GenerateData::composites(beginDigits, count);
    factorDataPoints = GenerateData::factor(comps, new BruteForceFactor);

    //draw points
    fg = new GraphWindow(ui->factoringGraphicsView, factorDataPoints);
    fg->vSize = 600;
    fg->hSize = 600;

    if(ui->factorLogScaleCheckBox->isChecked()) {
        fg->logScaleDraw();
    } else {
        fg->draw();
    }
    fg->addLabels("Milliseconds", "Number of digits");

    fg->view->show();
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

    switch(ui->crackTabWidget->currentIndex()) {
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
    crackDataPoints = GenerateData::crack(digests, c);

    //begin graphing
    cg = new GraphWindow(ui->crackGraphicsView, crackDataPoints);
    cg->vSize = 600;
    cg->hSize = 600;

    if(ui->hashLogScaleCheckBox->isChecked()) {
        cg->logScaleDraw();
    } else {
        cg->draw();
    }
    cg->addLabels("Milliseconds", "Number of characters");

    cg->view->show();
}

void MainWindow::on_hashLogScaleCheckBox_clicked()
{
    if(cg == NULL) {
        std::cout << "graphwindow object not initialized. No action to take." << std::endl;
        return;
    }
    if(crackDataPoints.size() == 0) {
        std::cout << "No points to graph." << std::endl;
        return;
    }

    cg = new GraphWindow(ui->crackGraphicsView, crackDataPoints);
    cg->vSize = 600;
    cg->hSize = 600;

    if(ui->hashLogScaleCheckBox->isChecked()) {
        cg->logScaleDraw();
    } else {
        cg->draw();
    }
    cg->addLabels("Milliseconds", "Number of characters");

    cg->view->show();
}

void MainWindow::on_factorLogScaleCheckBox_clicked()
{
    if(fg == NULL) {
        std::cout << "graphwindow object not initialized. No action to take." << std::endl;
        return;
    }
    if(factorDataPoints.size() == 0) {
        std::cout << "No points to graph." << std::endl;
        return;
    }

    fg = new GraphWindow(ui->factoringGraphicsView, factorDataPoints);
    fg->vSize = 600;
    fg->hSize = 600;

    if(ui->factorLogScaleCheckBox->isChecked()) {
        fg->logScaleDraw();
    } else {
        fg->draw();
    }
    fg->addLabels("Milliseconds", "Number of characters");

    fg->view->show();
}

void MainWindow::on_cancelCrackButton_clicked()
{
    threadCrack.stop();
}
