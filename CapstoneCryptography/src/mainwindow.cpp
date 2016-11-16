#include "headers/mainwindow.h"
#include "headers/cryptogame.h"
#include "ui_mainwindow.h"
#include "QPushButton"

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

void MainWindow::on_factorPrimesButton_clicked()
{

}
