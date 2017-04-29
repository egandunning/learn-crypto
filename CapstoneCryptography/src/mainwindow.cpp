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
#include <QUrl>
#include <QDesktopServices>

#include "iostream" //for debugging

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    agame(),
    factorAlg(),
    hashAlg(),
    digest(),
    fg(),
    cg(),
    threadCrack(),
    threadFactor(),
    threadCrackData(),
    threadFactorData(),
    crackDataPoints(),
    factorDataPoints(),
    colors({Qt::blue, Qt::red, Qt::magenta, Qt::cyan, Qt::green, Qt::yellow}),
    currentColor(colors.begin()),
    factorLegendCounter(0),
    crackLegendCounter(0)
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

    delete agame;

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
        if(i >= 10 && q.at(counter) == ' '){
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

/**
 * Factor number in text field with the selected algorithm.
 * @brief MainWindow::on_factorPrimesButton_clicked
 */
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
    string s = ui->compositeTextField->toPlainText().toStdString();

    composite = evaluateExpression(s);

    ui->compositeTextField->document()->setPlainText(QString::fromStdString(composite.get_str()));

    threadFactor.setFactor(factorAlg, composite);
    threadFactor.work();

    ui->factorPrimesButton->setDisabled(true);
}

/**
 * Updates gui to show result of factoring. Called when worker thread finishes.
 * @brief MainWindow::update_factor_result
 */
void MainWindow::update_factor_result() {

    long elapsed = threadFactor.getResult();
    Factor* pf = threadFactor.getFactor();

    string s = "Time: " + std::to_string(elapsed) + " ms";
    ui->timeLabel->setText(QString("Time: ")+smartTime(elapsed));

    s = pf->p1.get_str(10) + " * " + pf->p2.get_str(10);
    ui->resultField->document()->setPlainText(QString::fromStdString(s));

    ui->factorPrimesButton->setDisabled(false);
}

/**
 * Generate two random prime numbers, display the product.
 * @brief MainWindow::on_random_composite_clicked
 */
void MainWindow::on_random_composite_clicked()
{
    mpz_class composite, p, q;
    GeneratePrimes gp = GeneratePrimes();
    p = gp.readRandomPrime((char*)"primes.txt");
    q = gp.readRandomPrime((char*)"primes.txt");
    composite = p * q;
    string s = composite.get_str(10);
    ui->compositeTextField->document()->setPlainText(QString::fromStdString(s));
}

/**
 * Hash the text in the text field with the selected algorithm.
 * @brief MainWindow::on_hashButton_clicked
 */
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

/**
 * Generate a random salt.
 * @brief MainWindow::on_randomSaltButton_clicked
 */
void MainWindow::on_randomSaltButton_clicked()
{
    Hash h;
    h.generateSalt(16);
    ui->saltField->setText(h.getSalt());
}

/**
 * Crack the hash with the selected algorithm.
 * @brief MainWindow::on_crackButton_clicked
 */
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

/**
 * Displays the result of the cracked hash, called when worker thread finishes.
 * @brief MainWindow::update_crack_result
 */
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
    ui->crackTimeLabel->setText(QString("Time: " + smartTime(elapsed)));

    ui->crackButton->setDisabled(false);
}

/**
 * Retrieve the alphabet to be used for brute force hash cracking.
 * @brief MainWindow::bruteForceAlphabet
 * @return the alphabet selected by the user.
 */
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

/**
 * Retrieve options for dictionary crack.
 * @brief MainWindow::dictionaryOptions
 * @param d
 */
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

/**
 * Generate points to plot.
 * @brief MainWindow::on_drawFactoring_clicked
 */
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

/**
 * Draw points, called when worker thread finishes.
 * @brief MainWindow::update_factor_graph
 */
void MainWindow::update_factor_graph() {

    factorDataPoints = threadFactorData.getResult();

    if(fg == nullptr) {
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
        fg->addTitle("Number of digits vs. time to find two factors.");
        fg->addLegend("Legend:", Qt::black, factorLegendCounter);
        factorLegendCounter++;
        fg->addLegend(threadFactorData.getFactorAlgName(), Qt::black, factorLegendCounter);
    } else {
        factorLegendCounter++;
        addToGraph(fg, factorDataPoints, threadFactorData.getFactorAlgName(), factorLegendCounter);
    }

    fg->view->show();

    ui->drawFactoring->setDisabled(false);
}

/**
 * Generate data points to plot.
 * @brief MainWindow::on_plotCrackButton_clicked
 */
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

/**
 * Draw points, called when worker thread exits
 * @brief MainWindow::update_crack_graph
 */
void MainWindow::update_crack_graph() {

    crackDataPoints = threadCrackData.getResult();

    if(cg == nullptr) {
        //begin graphing new graph
        cg = new GraphWindow(ui->crackGraphicsView, crackDataPoints);
        cg->vSize = 600;
        cg->hSize = 600;

        if(ui->hashLogScaleCheckBox->isChecked()) {
            cg->logScaleDraw();
        } else {
            cg->draw();
        }
        cg->addLabels("Milliseconds", "Number of characters");
        cg->addTitle("Length of password vs time to crack.");
        cg->addLegend("Legend: ", Qt::black, crackLegendCounter);
        crackLegendCounter++;
        cg->addLegend(threadCrackData.getHashAlgName() + ", " + threadCrackData.getCrackAlgName(), Qt::black, crackLegendCounter);
    } else {
        crackLegendCounter++;
        addToGraph(cg, crackDataPoints, threadCrackData.getHashAlgName() + ", " + threadCrackData.getCrackAlgName(), crackLegendCounter);
    }
    cg->view->show();

    ui->plotCrackButton->setEnabled(true);
}

/**
 * @brief MainWindow::addToGraph
 * @param graph to add points to
 * @param pts points to plot
 */
void MainWindow::addToGraph(GraphWindow* graph, std::vector<QPointF> pts, QString legendText, int legendPosition) {

    if(graph == nullptr) {
        std::cout << "In MainWindow::addToGraph : graph object is null! Nothing to draw on." << std::endl;
        return;
    }

    if(currentColor == colors.end()) {
        currentColor = colors.begin();
    } else {
        currentColor++;
    }
    graph->drawNewLayer(pts, *currentColor);
    graph->addLegend(legendText, *currentColor, legendPosition);
}

/**
 * Updates graph to show log scale for hash cracking data points.
 * @brief MainWindow::on_hashLogScaleCheckBox_clicked
 */
void MainWindow::on_hashLogScaleCheckBox_clicked()
{
    if(cg == nullptr) {
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

/**
 * Updates graph to show log scale for factoring data points.
 * @brief MainWindow::on_factorLogScaleCheckBox_clicked
 */
void MainWindow::on_factorLogScaleCheckBox_clicked()
{
    if(fg == nullptr) {
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

/**
 * Cancel hash cracking - the cracking algorithm decides how to handle this.
 * @brief MainWindow::on_cancelCrackButton_clicked
 */
void MainWindow::on_cancelCrackButton_clicked()
{
    threadCrack.stop();
}

/**
 * Cancel factoring - the factoring algorithm decides how to handle this.
 * @brief MainWindow::on_stopFactorPushButton_clicked
 */
void MainWindow::on_stopFactorPushButton_clicked()
{
    threadFactor.stop();
}

/**
 * Launch help website.
 * @brief MainWindow::on_HELPBUTTONCLICKED
 */
void MainWindow::on_HELPBUTTONCLICKED(){
    QString url = "https://cryptowiki.herokuapp.com/";
    bool hi = QDesktopServices::openUrl(QUrl(url));
    if(!hi) {
        std::cout << "Error opening webpage: " << url.toStdString() << std::endl;
    }
}

/**
 * Given a string containing two numbers a,b separated by any character,
 * evaluate a*b. Example: expressionEvaluator("2 7") returns 14.
 * @brief MainWindow::expressionEvaluator
 * @param inString
 * @return
 */
mpz_class MainWindow::evaluateExpression(std::string input) {

    size_t index = 0;
    std::string num1="";
    std::string num2="";
    while(index < input.size() && isDigit(input.at(index))) {
        num1.append(1,input.at(index));
        index++;
    }
    while(index < input.size() && !isDigit(input.at(index))) {
        index++;
    }
    if(index >= input.size()) {
        try {
            return mpz_class(num1);
        } catch(std::invalid_argument e) {
            std::cout << "incorrect format: " << input << std::endl;
            std::cout << "format should be: [number] or [number][anything][number]" << std::endl;
            return mpz_class(0);
        }
    }
    while(index < input.size() && isDigit(input.at(index))) {
        num2.append(1,input.at(index));
        index++;
    }

    try{
        mpz_class a(num1);
        mpz_class b(num2);
        return a*b;
    } catch (std::invalid_argument e) {
        std::cout << "incorrect format: " << input << std::endl;
        std::cout << "format should be: [number] or [number][anything][number]" << std::endl;
        return mpz_class(0);
    }
}

/**
 * Helper method for evaluateExpression.
 * @brief MainWindow::isDigit
 * @param c character to check if digit
 * @return true if c is a digit
 */
bool MainWindow::isDigit(char c) {
    if(c <= '9' && c >= '0') {
        return true;
    }
    return false;
}

/**
 * Adjusts units of time based on magnitude.
 * @brief MainWindow::smartTime
 * @param ms
 * @return
 */
QString MainWindow::smartTime(long ms) {

    std::string output = "";

    if(ms >= 8640000) {
        double days = ms / 8640000.0;
        return QString::number(days,'f',2) + QString(" days");
    }
    if(ms >= 360000) {
        double hours = ms / 360000.0;
        return QString::number(hours,'f',2) + QString(" hours");
    }
    if(ms >= 60000) {
        double minutes = ms / 60000.0;
        return QString::number(minutes,'f',2) + QString(" minutes");
    }
    if(ms >= 1000) {
        double seconds = ms / 1000.0;
        return QString::number(seconds,'f',2) + QString(" seconds");
    }
    return QString::number(ms) + QString(" milliseconds");
}

/**
 * Clear the factoring graph.
 * @brief MainWindow::on_clearFactorGraph_clicked
 */
void MainWindow::on_clearFactorGraph_clicked()
{
    if(fg != nullptr) {
        fg->scene->clear();
        fg->view->update();
        fg = 0;
    }
}

/**
 * Clear the hash cracking graph.
 * @brief MainWindow::on_clearFactorGraph_2_clicked
 */
void MainWindow::on_clearFactorGraph_2_clicked()
{
    if(cg != nullptr) {
        cg->scene->clear();
        cg->view->update();
        cg = 0;
    }
}
