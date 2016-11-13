#include "headers/mainwindow.h"
#include "ui_mainwindow.h"
#include "QPushButton"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPushButton buttons[5];

    for(int i=0; i<5; i++){
        buttons[i].show();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
