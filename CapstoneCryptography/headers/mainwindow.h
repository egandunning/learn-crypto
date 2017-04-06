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
#include <headers/crack.h>
#include <headers/bruteforcecrack.h>
#include <headers/dictionarycrack.h>
#include <headers/graphwindow.h>
#include <headers/generatedata.h>
#include <headers/workerthreadcrack.h>
#include <headers/workerthreadfactor.h>
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

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_random_composite_clicked();

    void on_hashButton_clicked();

    void on_randomSaltButton_clicked();

    void on_crackButton_clicked();

    void update_crack_result();

    void update_factor_result();

    void on_drawFactoring_clicked();

    void on_plotCrackButton_clicked();

    void on_hashLogScaleCheckBox_clicked();

    void on_factorLogScaleCheckBox_clicked();

    void on_cancelCrackButton_clicked();

private:
    Ui::MainWindow *ui;
    cryptogame *agame;
    Hash *hashAlg;
    QString digest;
    QString guessedWord;
    GraphWindow* fg; //for factoring
    GraphWindow* cg; //for hash cracking
    WorkerThreadCrack threadCrack;
    WorkerThreadFactor threadFactor;

    std::vector<QPointF> crackDataPoints;
    std::vector<QPointF> factorDataPoints;


    std::string bruteForceAlphabet();
    void dictionaryOptions(Crack *);
};

#endif // MAINWINDOW_H
