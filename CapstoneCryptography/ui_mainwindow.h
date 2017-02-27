/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *gameTab;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QTextEdit *textEdit;
    QWidget *tab_3;
    QGridLayout *gridLayout_4;
    QCheckBox *numbersCheckBox;
    QLabel *label_5;
    QComboBox *crackComboBox;
    QPushButton *hashButton;
    QLineEdit *plaintextField;
    QPushButton *randomSaltButton;
    QCheckBox *lettersCheckBox;
    QTextEdit *digestField;
    QLabel *label_3;
    QLineEdit *crackedField;
    QComboBox *hashComboBox;
    QLabel *label_9;
    QLabel *label_6;
    QLabel *crackTimeLabel;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_8;
    QCheckBox *upCaseCheckBox;
    QPushButton *crackButton;
    QLineEdit *saltField;
    QCheckBox *symbolsCheckBox;
    QCheckBox *customCheckBox;
    QLineEdit *alphabetField;
    QLabel *label_10;
    QSpinBox *charCountSpinBox;
    QWidget *tab_4;
    QGridLayout *gridLayout_2;
    QPushButton *factorPrimesButton;
    QLabel *timeLabel;
    QCheckBox *GPUCheckBox;
    QLabel *label_7;
    QPushButton *random_composite;
    QGraphicsView *graphicsView;
    QLineEdit *compositeTextField;
    QLabel *resultLabel;
    QSpacerItem *verticalSpacer;
    QComboBox *factorAlgChooser;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(626, 492);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));

        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        gameTab = new QWidget();
        gameTab->setObjectName(QStringLiteral("gameTab"));
        gridLayout_3 = new QGridLayout(gameTab);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        pushButton_3 = new QPushButton(gameTab);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout_3->addWidget(pushButton_3, 3, 2, 1, 1);

        pushButton = new QPushButton(gameTab);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_3->addWidget(pushButton, 3, 0, 1, 1);

        pushButton_2 = new QPushButton(gameTab);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout_3->addWidget(pushButton_2, 3, 1, 1, 1);

        label = new QLabel(gameTab);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_3->addWidget(label, 0, 0, 1, 3);

        textEdit = new QTextEdit(gameTab);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout_3->addWidget(textEdit, 1, 0, 1, 3);

        tabWidget->addTab(gameTab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_4 = new QGridLayout(tab_3);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        numbersCheckBox = new QCheckBox(tab_3);
        numbersCheckBox->setObjectName(QStringLiteral("numbersCheckBox"));

        gridLayout_4->addWidget(numbersCheckBox, 10, 1, 1, 1);

        label_5 = new QLabel(tab_3);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_4->addWidget(label_5, 8, 0, 1, 1, Qt::AlignBottom);

        crackComboBox = new QComboBox(tab_3);
        crackComboBox->setObjectName(QStringLiteral("crackComboBox"));

        gridLayout_4->addWidget(crackComboBox, 4, 1, 1, 1);

        hashButton = new QPushButton(tab_3);
        hashButton->setObjectName(QStringLiteral("hashButton"));

        gridLayout_4->addWidget(hashButton, 1, 2, 1, 1);

        plaintextField = new QLineEdit(tab_3);
        plaintextField->setObjectName(QStringLiteral("plaintextField"));

        gridLayout_4->addWidget(plaintextField, 1, 1, 1, 1);

        randomSaltButton = new QPushButton(tab_3);
        randomSaltButton->setObjectName(QStringLiteral("randomSaltButton"));

        gridLayout_4->addWidget(randomSaltButton, 2, 2, 1, 1);

        lettersCheckBox = new QCheckBox(tab_3);
        lettersCheckBox->setObjectName(QStringLiteral("lettersCheckBox"));
        lettersCheckBox->setChecked(true);

        gridLayout_4->addWidget(lettersCheckBox, 10, 0, 1, 1);

        digestField = new QTextEdit(tab_3);
        digestField->setObjectName(QStringLiteral("digestField"));
        digestField->setMinimumSize(QSize(290, 30));
        digestField->setMaximumSize(QSize(100000, 50));

        gridLayout_4->addWidget(digestField, 3, 1, 1, 1);

        label_3 = new QLabel(tab_3);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_4->addWidget(label_3, 1, 0, 1, 1);

        crackedField = new QLineEdit(tab_3);
        crackedField->setObjectName(QStringLiteral("crackedField"));
        crackedField->setReadOnly(true);

        gridLayout_4->addWidget(crackedField, 5, 1, 1, 1);

        hashComboBox = new QComboBox(tab_3);
        hashComboBox->setObjectName(QStringLiteral("hashComboBox"));
        hashComboBox->setMaximumSize(QSize(100, 16777215));

        gridLayout_4->addWidget(hashComboBox, 0, 1, 1, 1);

        label_9 = new QLabel(tab_3);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_4->addWidget(label_9, 4, 0, 1, 1);

        label_6 = new QLabel(tab_3);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_4->addWidget(label_6, 3, 0, 1, 1);

        crackTimeLabel = new QLabel(tab_3);
        crackTimeLabel->setObjectName(QStringLiteral("crackTimeLabel"));

        gridLayout_4->addWidget(crackTimeLabel, 5, 2, 1, 1);

        label_4 = new QLabel(tab_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_4->addWidget(label_4, 5, 0, 1, 1);

        label_2 = new QLabel(tab_3);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_4->addWidget(label_2, 0, 0, 1, 1);

        label_8 = new QLabel(tab_3);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_4->addWidget(label_8, 2, 0, 1, 1);

        upCaseCheckBox = new QCheckBox(tab_3);
        upCaseCheckBox->setObjectName(QStringLiteral("upCaseCheckBox"));

        gridLayout_4->addWidget(upCaseCheckBox, 11, 0, 1, 1);

        crackButton = new QPushButton(tab_3);
        crackButton->setObjectName(QStringLiteral("crackButton"));

        gridLayout_4->addWidget(crackButton, 4, 2, 1, 1);

        saltField = new QLineEdit(tab_3);
        saltField->setObjectName(QStringLiteral("saltField"));

        gridLayout_4->addWidget(saltField, 2, 1, 1, 1);

        symbolsCheckBox = new QCheckBox(tab_3);
        symbolsCheckBox->setObjectName(QStringLiteral("symbolsCheckBox"));

        gridLayout_4->addWidget(symbolsCheckBox, 11, 1, 1, 1);

        customCheckBox = new QCheckBox(tab_3);
        customCheckBox->setObjectName(QStringLiteral("customCheckBox"));

        gridLayout_4->addWidget(customCheckBox, 12, 0, 1, 1);

        alphabetField = new QLineEdit(tab_3);
        alphabetField->setObjectName(QStringLiteral("alphabetField"));

        gridLayout_4->addWidget(alphabetField, 12, 1, 1, 1);

        label_10 = new QLabel(tab_3);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_4->addWidget(label_10, 9, 0, 1, 1);

        charCountSpinBox = new QSpinBox(tab_3);
        charCountSpinBox->setObjectName(QStringLiteral("charCountSpinBox"));
        charCountSpinBox->setMinimum(1);
        charCountSpinBox->setValue(30);

        gridLayout_4->addWidget(charCountSpinBox, 9, 1, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        gridLayout_2 = new QGridLayout(tab_4);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        factorPrimesButton = new QPushButton(tab_4);
        factorPrimesButton->setObjectName(QStringLiteral("factorPrimesButton"));

        gridLayout_2->addWidget(factorPrimesButton, 3, 1, 1, 1);

        timeLabel = new QLabel(tab_4);
        timeLabel->setObjectName(QStringLiteral("timeLabel"));

        gridLayout_2->addWidget(timeLabel, 6, 1, 1, 1);

        GPUCheckBox = new QCheckBox(tab_4);
        GPUCheckBox->setObjectName(QStringLiteral("GPUCheckBox"));

        gridLayout_2->addWidget(GPUCheckBox, 0, 0, 1, 1);

        label_7 = new QLabel(tab_4);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_2->addWidget(label_7, 1, 0, 1, 1);

        random_composite = new QPushButton(tab_4);
        random_composite->setObjectName(QStringLiteral("random_composite"));

        gridLayout_2->addWidget(random_composite, 2, 1, 1, 1);

        graphicsView = new QGraphicsView(tab_4);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        gridLayout_2->addWidget(graphicsView, 0, 2, 6, 1);

        compositeTextField = new QLineEdit(tab_4);
        compositeTextField->setObjectName(QStringLiteral("compositeTextField"));

        gridLayout_2->addWidget(compositeTextField, 1, 1, 1, 1);

        resultLabel = new QLabel(tab_4);
        resultLabel->setObjectName(QStringLiteral("resultLabel"));

        gridLayout_2->addWidget(resultLabel, 5, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 7, 1, 1, 1);

        factorAlgChooser = new QComboBox(tab_4);
        factorAlgChooser->setObjectName(QStringLiteral("factorAlgChooser"));

        gridLayout_2->addWidget(factorAlgChooser, 0, 1, 1, 1);

        tabWidget->addTab(tab_4, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 626, 19));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "Hint", 0));
        pushButton->setText(QApplication::translate("MainWindow", "New Game", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Guess", 0));
        label->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        tabWidget->setTabText(tabWidget->indexOf(gameTab), QApplication::translate("MainWindow", "Game", 0));
        numbersCheckBox->setText(QApplication::translate("MainWindow", "Numbers", 0));
        label_5->setText(QApplication::translate("MainWindow", "Alphabet Settings for Brute Force", 0));
        crackComboBox->clear();
        crackComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Brute force", 0)
         << QApplication::translate("MainWindow", "Dictionary attack", 0)
         << QApplication::translate("MainWindow", "Lookup tables", 0)
        );
        hashButton->setText(QApplication::translate("MainWindow", "Hash!", 0));
        randomSaltButton->setText(QApplication::translate("MainWindow", "Random", 0));
        lettersCheckBox->setText(QApplication::translate("MainWindow", "Letters", 0));
        label_3->setText(QApplication::translate("MainWindow", "Your Text:", 0));
        hashComboBox->clear();
        hashComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "MD5", 0)
         << QApplication::translate("MainWindow", "SHA-512", 0)
         << QApplication::translate("MainWindow", "PBKDF2", 0)
        );
        label_9->setText(QApplication::translate("MainWindow", "Choose hash cracking algorithm", 0));
        label_6->setText(QApplication::translate("MainWindow", "Character representation of Hash", 0));
        crackTimeLabel->setText(QApplication::translate("MainWindow", "Time:", 0));
        label_4->setText(QApplication::translate("MainWindow", "Result:", 0));
        label_2->setText(QApplication::translate("MainWindow", "Choose a Hash Function", 0));
        label_8->setText(QApplication::translate("MainWindow", "Salt:", 0));
        upCaseCheckBox->setText(QApplication::translate("MainWindow", "Include uppercase", 0));
        crackButton->setText(QApplication::translate("MainWindow", "Reverse!", 0));
        symbolsCheckBox->setText(QApplication::translate("MainWindow", "Symbols", 0));
        customCheckBox->setText(QApplication::translate("MainWindow", "Custom alphabet:", 0));
        label_10->setText(QApplication::translate("MainWindow", "Character Count:", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Hash", 0));
        factorPrimesButton->setText(QApplication::translate("MainWindow", "Factor", 0));
        timeLabel->setText(QApplication::translate("MainWindow", "Time: ", 0));
        GPUCheckBox->setText(QApplication::translate("MainWindow", "Use GPU", 0));
        label_7->setText(QApplication::translate("MainWindow", "Enter a product of two primes:", 0));
        random_composite->setText(QApplication::translate("MainWindow", "Random", 0));
        resultLabel->setText(QApplication::translate("MainWindow", "Result:", 0));
        factorAlgChooser->clear();
        factorAlgChooser->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Brute force (small to big)", 0)
         << QApplication::translate("MainWindow", "Brute force (big to small)", 0)
         << QApplication::translate("MainWindow", "Quadratic sieve", 0)
        );
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Factoring", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
