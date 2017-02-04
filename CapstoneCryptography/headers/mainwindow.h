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
#include <headers/crack.h>
#include <headers/bruteforcecrack.h>
#include <headers/dictionarycrack.h>

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
    void on_GPUCheckBox_clicked();

    void on_factorPrimesButton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_random_composite_clicked();

    void on_hashButton_clicked();

    void on_randomSaltButton_clicked();

    void on_crackButton_clicked();

private:
    Ui::MainWindow *ui;
    cryptogame *agame;
    Hash *hashAlg;
    QString digest;

    std::string bruteForceAlphabet();
};

#endif // MAINWINDOW_H
