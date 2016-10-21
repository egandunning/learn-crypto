#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1

#include <QDialog>
#include <QPushButton>
#include <QString>
#include <QVBoxLayout>
#include <QtWidgets>
#include <QDialogButtonBox>
#include <QComboBox>

#include <cryptopp/sha.h>
#include <cryptopp/hex.h>
#include <cryptopp/md5.h>
#include <cryptopp/tiger.h>
#include <cryptopp/filters.h>

#include <ctime>
#include <string>
#include <iostream>

using CryptoPP::SHA1;
using CryptoPP::SHA256;
using CryptoPP::SHA512;
using CryptoPP::Weak::MD5;
using CryptoPP::Tiger;

using CryptoPP::HexEncoder;
using CryptoPP::StringSource;
using CryptoPP::StringSink;
using CryptoPP::HashFilter;
using CryptoPP::HashTransformation;

using std::clock;
using std::clock_t;
using std::string;
using std::cout;
using std::cin;
using std::endl;

class HashTab : public QWidget
{
    Q_OBJECT

private slots:
    void computeHash();

private:
    QComboBox *chooseHash;
    QLineEdit *hashEdit;
    QLabel *timeInfoLabel;
    QLineEdit *timeEdit;
    QLineEdit *hashResult;

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
