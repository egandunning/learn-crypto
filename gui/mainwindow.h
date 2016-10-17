#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QPushButton>
#include <QString>
#include <QVBoxLayout>
#include <QtWidgets>
#include <QDialogButtonBox>

class HashTab : public QWidget
{
    Q_OBJECT

public:
    explicit HashTab(QWidget *parent = 0);
};

class RsaTab : public QWidget
{
    Q_OBJECT

public:
    explicit RsaTab(QWidget *parent = 0);
};

class HelpTab : public QWidget
{
    Q_OBJECT

public:
    explicit HelpTab(QWidget *parent = 0);
};

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:


private:
    QTabWidget *tabWidget;
    QDialogButtonBox *buttonBox;
};

#endif // MAINWINDOW_H
