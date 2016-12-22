#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QElapsedTimer>
#include <QStringRef>
#include <headers/cryptogame.h>
#include <headers/hash.h>
#include <headers/md5.h>
#include <headers/sha512.h>
#include <headers/pbkdf2.h>

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

private:
    Ui::MainWindow *ui;
    cryptogame *agame;
};

#endif // MAINWINDOW_H
