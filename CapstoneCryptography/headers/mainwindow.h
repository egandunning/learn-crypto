#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QElapsedTimer>
#include <QStringRef>
#include <QInputDialog>
#include <headers/cryptogame.h>
#include <headers/hash.h>
#include <headers/md5.h>
#include <headers/sha512.h>
#include <headers/pbkdf2.h>
#include <headers/generateprimes.h>
#include <headers/bruteforcefactor.h>
#include <headers/qsfactor.h>
#include <headers/crack.h>
#include <headers/bruteforcecrack.h>
#include <headers/dictionarycrack.h>
#include <headers/graphwindow.h>
#include <headers/generatedata.h>
#include <headers/workerthreadcrack.h>
#include <headers/workerthreadfactor.h>
#include <headers/workerthreadgenerate.h>
#include <headers/buttonarray.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_factorPrimesButton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_random_composite_clicked();

    void on_hashButton_clicked();

    void on_randomSaltButton_clicked();

    void on_crackButton_clicked();

    void update_crack_result();

    void update_factor_result();

    void on_drawFactoring_clicked();

    void update_factor_graph();

    void on_plotCrackButton_clicked();

    void update_crack_graph();

    void on_hashLogScaleCheckBox_clicked();

    void on_factorLogScaleCheckBox_clicked();

    void on_cancelCrackButton_clicked();

    void on_stopFactorPushButton_clicked();

    void on_HELPBUTTONCLICKED();

private:
    Ui::MainWindow *ui;
    cryptogame *agame;
    Factor* factorAlg=0;
    Hash *hashAlg=0;
    QString digest;
    GraphWindow* fg=0; //for factoring
    GraphWindow* cg=0; //for hash cracking
    WorkerThreadCrack threadCrack;
    WorkerThreadFactor threadFactor;
    WorkerThreadGenerate threadCrackData;
    WorkerThreadGenerate threadFactorData;

    std::vector<QPointF> crackDataPoints;
    std::vector<QPointF> factorDataPoints;


    std::string bruteForceAlphabet();
    void dictionaryOptions(Crack *);
    mpz_class evaluateExpression(std::string);
    bool isDigit(char);
    QString smartTime(long);
};

#endif // MAINWINDOW_H
