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
#include <QtWebKit>
#include <QUrl>

#include "iostream" //for debugging

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    connect(&threadCrack, SIGNAL(finished()), this, SLOT(update_crack_result()));
    connect(&threadFactor, SIGNAL(finished()), this, SLOT(update_factor_result()));
    connect(&threadCrackData, SIGNAL(finished()), this, SLOT(update_crack_graph()));
    connect(&threadFactorData, SIGNAL(finished()), this, SLOT(update_factor_graph()));
    ui->setupUi(this);

    QAction *act = new QAction(QString("Help"), this);

    connect(act, &QAction::triggered, this, &MainWindow::on_HELPBUTTONCLICKED);

    ui->menuBar->addAction(act);

}

MainWindow::~MainWindow()
{
    delete ui;

    if(threadCrack.isRunning()) {
        threadCrack.quit();
    }
    if(threadFactor.isRunning()) {
        threadFactor.quit();
    }

    if(factorAlg != NULL) {
        delete factorAlg;
    }
    if(hashAlg != NULL) {
        delete hashAlg;
    }

    if(fg != NULL) {
        delete fg;
    }
    if(cg != NULL) {
        delete cg;
    }
}

void MainWindow::on_pushButton_clicked()
{

    //Delete all buttons in the and labels in the gameGrid
   for(int i=0; i<ui->gameGrid->columnCount(); i++){
       for(int j = 0; j<ui->gameGrid->rowCount(); j++){

       QLayoutItem *button = ui->gameGrid->itemAtPosition(j,i);
       if(button){
           ui->gameGrid->removeItem(button);
          delete button->widget();
       }


        QLayoutItem *label = ui->gameGrid->itemAtPosition(j,i);
        if(label){
            ui->gameGrid->removeItem(label);

            delete label->widget();
        }

       }

    }

    agame = new cryptogame();
    QString q = QString::fromStdString(agame->getEncryptedMessage());
    //ui->label->setText(q);
    LabelArray *lptr = new LabelArray(q, ui->tabWidget);
    ButtonArray *buttonPtrs = new ButtonArray(q, ui->tabWidget, agame);
    int j = 0;
    int i = 0;
    int counter = 0;
    while(counter < q.length()){
        if(i >= 3 && q.at(counter) == ' '){
            j += 2;
            i = 0;
        } else {
        ui->gameGrid->addWidget(lptr->get(counter), j, i);
        ui->gameGrid->addWidget(buttonPtrs->get(counter), j+1, i);
        i++;
        }
        counter++;
    }


}


void MainWindow::on_pushButton_3_clicked()
{
    //Give a hint to the player
    QMessageBox hintMessage;
    hintMessage.setText(QString::fromStdString(agame->getHint()));
    hintMessage.exec();
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

    switch(algChoice) {
    case 0:{
        factorAlg = new BruteForceFactor();
        break;}
    case 1:{
        factorAlg = new QSFactor();
        std::cout<<"Quadratic sieve feature is in progress!"<<std::endl;
        break;}
    }
	
    mpz_class composite;
    string s = ui->compositeTextField->text().toStdString();
    composite.set_str(s, 10);

    threadFactor.setFactor(factorAlg, composite);
    threadFactor.work();

    ui->factorPrimesButton->setDisabled(true);
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

    Crack* c = new Crack();
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
    //set algorithm
    int algChoice = ui->factorAlgChooser->currentIndex();

    switch(algChoice) {
    case 0:
        factorAlg = new BruteForceFactor();
        break;
    case 1:
        //Quadratic sieve here
        std::cout<<"Quadratic sieve feature is in progress!"<<std::endl;
        return;
        break;
    }

    //generate data
    int beginDigits = ui->startDigitsSpinBox->text().toInt();
    unsigned int count = ui->dataPointsSpinBox->text().toInt();

    threadFactorData.factorData(beginDigits, count, factorAlg);

    ui->drawFactoring->setDisabled(true);
}

void MainWindow::update_factor_graph() {

    factorDataPoints = threadFactorData.getResult();

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

    ui->drawFactoring->setDisabled(false);
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

    Crack* c = new Crack();
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

    threadCrackData.crackData(beginChars, count, hashAlg, c);

    ui->plotCrackButton->setEnabled(false);
}

void MainWindow::update_crack_graph() {

    crackDataPoints = threadCrackData.getResult();

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

    ui->plotCrackButton->setEnabled(true);
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

void MainWindow::on_stopFactorPushButton_clicked()
{
    threadFactor.stop();
}

void MainWindow::on_HELPBUTTONCLICKED(){
    bool hi = QDesktopServices::openUrl(QUrl("https://cryptowiki.herokuapp.com/"));
}
