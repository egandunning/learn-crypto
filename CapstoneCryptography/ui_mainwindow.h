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
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
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
    QGridLayout *gridLayout_5;
    QHBoxLayout *layoutForButtons;
    QTextEdit *textEdit;
    QWidget *tab_3;
    QGridLayout *gridLayout_4;
    QLabel *label_2;
    QGraphicsView *crackGraphicsView;
    QComboBox *crackComboBox;
    QLabel *label_9;
    QTextEdit *digestField;
    QLabel *label_6;
    QLabel *label_3;
    QLabel *label_8;
    QSpinBox *charCountSpinBox_2;
    QVBoxLayout *verticalLayout;
    QTabWidget *crackTabWidget;
    QWidget *tab;
    QLabel *label_10;
    QCheckBox *lettersCheckBox;
    QSpinBox *charCountSpinBox;
    QCheckBox *upCaseCheckBox;
    QCheckBox *numbersCheckBox;
    QCheckBox *customCheckBox;
    QCheckBox *symbolsCheckBox;
    QLineEdit *alphabetField;
    QWidget *tab_2;
    QLabel *label_5;
    QSpinBox *wordCountSpinBox;
    QLabel *label_11;
    QCheckBox *appendCheckBox;
    QLabel *label_12;
    QCheckBox *prependCheckBox;
    QLabel *label_13;
    QSpinBox *digitCountSpinBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLabel *crackPlotLabel;
    QLineEdit *crackedField;
    QLineEdit *saltField;
    QLineEdit *plaintextField;
    QPushButton *crackButton;
    QSpinBox *crackPointCountSpinBox;
    QPushButton *randomSaltButton;
    QPushButton *hashButton;
    QComboBox *hashComboBox;
    QLabel *crackTimeLabel;
    QPushButton *plotCrackButton;
    QLabel *pointCountLabel;
    QLabel *charCountLabel;
    QCheckBox *logScaleCheckBox;
    QWidget *tab_4;
    QGridLayout *gridLayout_2;
    QPushButton *random_composite;
    QPushButton *drawFactoring;
    QLabel *timeLabel;
    QLineEdit *compositeTextField;
    QComboBox *factorAlgChooser;
    QGraphicsView *factoringGraphicsView;
    QLabel *resultLabel;
    QPushButton *factorPrimesButton;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_4;
    QLabel *dataCountLabel;
    QSpinBox *dataPointsSpinBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *dataStartLabel;
    QSpinBox *startDigitsSpinBox;
    QLabel *plotLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1014, 648);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
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

        gridLayout_3->addWidget(pushButton_3, 5, 2, 1, 1);

        pushButton = new QPushButton(gameTab);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_3->addWidget(pushButton, 5, 0, 1, 1);

        pushButton_2 = new QPushButton(gameTab);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout_3->addWidget(pushButton_2, 5, 1, 1, 1);

        label = new QLabel(gameTab);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_3->addWidget(label, 0, 0, 1, 3);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));

        gridLayout_3->addLayout(gridLayout_5, 1, 0, 1, 1);

        layoutForButtons = new QHBoxLayout();
        layoutForButtons->setSpacing(6);
        layoutForButtons->setObjectName(QStringLiteral("layoutForButtons"));

        gridLayout_3->addLayout(layoutForButtons, 3, 0, 2, 1);

        textEdit = new QTextEdit(gameTab);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout_3->addWidget(textEdit, 2, 0, 1, 3);

        tabWidget->addTab(gameTab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_4 = new QGridLayout(tab_3);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_2 = new QLabel(tab_3);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_4->addWidget(label_2, 0, 0, 1, 1);

        crackGraphicsView = new QGraphicsView(tab_3);
        crackGraphicsView->setObjectName(QStringLiteral("crackGraphicsView"));
        crackGraphicsView->setMinimumSize(QSize(600, 0));

        gridLayout_4->addWidget(crackGraphicsView, 0, 3, 12, 1);

        crackComboBox = new QComboBox(tab_3);
        crackComboBox->setObjectName(QStringLiteral("crackComboBox"));

        gridLayout_4->addWidget(crackComboBox, 4, 1, 1, 1);

        label_9 = new QLabel(tab_3);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_4->addWidget(label_9, 4, 0, 1, 1);

        digestField = new QTextEdit(tab_3);
        digestField->setObjectName(QStringLiteral("digestField"));
        digestField->setMinimumSize(QSize(0, 30));
        digestField->setMaximumSize(QSize(100000, 50));

        gridLayout_4->addWidget(digestField, 3, 1, 1, 2);

        label_6 = new QLabel(tab_3);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_4->addWidget(label_6, 3, 0, 1, 1);

        label_3 = new QLabel(tab_3);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_4->addWidget(label_3, 1, 0, 1, 1);

        label_8 = new QLabel(tab_3);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_4->addWidget(label_8, 2, 0, 1, 1);

        charCountSpinBox_2 = new QSpinBox(tab_3);
        charCountSpinBox_2->setObjectName(QStringLiteral("charCountSpinBox_2"));
        charCountSpinBox_2->setValue(1);

        gridLayout_4->addWidget(charCountSpinBox_2, 8, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        crackTabWidget = new QTabWidget(tab_3);
        crackTabWidget->setObjectName(QStringLiteral("crackTabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label_10 = new QLabel(tab);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 0, 138, 27));
        lettersCheckBox = new QCheckBox(tab);
        lettersCheckBox->setObjectName(QStringLiteral("lettersCheckBox"));
        lettersCheckBox->setGeometry(QRect(10, 30, 138, 22));
        lettersCheckBox->setChecked(true);
        charCountSpinBox = new QSpinBox(tab);
        charCountSpinBox->setObjectName(QStringLiteral("charCountSpinBox"));
        charCountSpinBox->setGeometry(QRect(140, 0, 131, 27));
        charCountSpinBox->setMinimum(1);
        charCountSpinBox->setValue(30);
        upCaseCheckBox = new QCheckBox(tab);
        upCaseCheckBox->setObjectName(QStringLiteral("upCaseCheckBox"));
        upCaseCheckBox->setGeometry(QRect(10, 50, 138, 22));
        numbersCheckBox = new QCheckBox(tab);
        numbersCheckBox->setObjectName(QStringLiteral("numbersCheckBox"));
        numbersCheckBox->setGeometry(QRect(160, 30, 135, 22));
        customCheckBox = new QCheckBox(tab);
        customCheckBox->setObjectName(QStringLiteral("customCheckBox"));
        customCheckBox->setGeometry(QRect(10, 70, 134, 22));
        symbolsCheckBox = new QCheckBox(tab);
        symbolsCheckBox->setObjectName(QStringLiteral("symbolsCheckBox"));
        symbolsCheckBox->setGeometry(QRect(160, 50, 173, 22));
        alphabetField = new QLineEdit(tab);
        alphabetField->setObjectName(QStringLiteral("alphabetField"));
        alphabetField->setGeometry(QRect(150, 70, 173, 27));
        crackTabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 10, 111, 17));
        wordCountSpinBox = new QSpinBox(tab_2);
        wordCountSpinBox->setObjectName(QStringLiteral("wordCountSpinBox"));
        wordCountSpinBox->setGeometry(QRect(120, 0, 44, 27));
        wordCountSpinBox->setValue(1);
        label_11 = new QLabel(tab_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 40, 121, 17));
        appendCheckBox = new QCheckBox(tab_2);
        appendCheckBox->setObjectName(QStringLiteral("appendCheckBox"));
        appendCheckBox->setGeometry(QRect(130, 40, 88, 22));
        label_12 = new QLabel(tab_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(160, 40, 59, 17));
        prependCheckBox = new QCheckBox(tab_2);
        prependCheckBox->setObjectName(QStringLiteral("prependCheckBox"));
        prependCheckBox->setGeometry(QRect(220, 40, 88, 22));
        label_13 = new QLabel(tab_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(250, 40, 59, 17));
        digitCountSpinBox = new QSpinBox(tab_2);
        digitCountSpinBox->setObjectName(QStringLiteral("digitCountSpinBox"));
        digitCountSpinBox->setGeometry(QRect(290, 30, 44, 27));
        crackTabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(crackTabWidget);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));

        verticalLayout->addLayout(horizontalLayout_5);


        gridLayout_4->addLayout(verticalLayout, 11, 0, 1, 3);

        label_4 = new QLabel(tab_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_4->addWidget(label_4, 5, 0, 1, 1);

        crackPlotLabel = new QLabel(tab_3);
        crackPlotLabel->setObjectName(QStringLiteral("crackPlotLabel"));

        gridLayout_4->addWidget(crackPlotLabel, 7, 0, 1, 1);

        crackedField = new QLineEdit(tab_3);
        crackedField->setObjectName(QStringLiteral("crackedField"));
        crackedField->setReadOnly(true);

        gridLayout_4->addWidget(crackedField, 5, 1, 1, 1);

        saltField = new QLineEdit(tab_3);
        saltField->setObjectName(QStringLiteral("saltField"));

        gridLayout_4->addWidget(saltField, 2, 1, 1, 1);

        plaintextField = new QLineEdit(tab_3);
        plaintextField->setObjectName(QStringLiteral("plaintextField"));

        gridLayout_4->addWidget(plaintextField, 1, 1, 1, 1);

        crackButton = new QPushButton(tab_3);
        crackButton->setObjectName(QStringLiteral("crackButton"));

        gridLayout_4->addWidget(crackButton, 4, 2, 1, 1);

        crackPointCountSpinBox = new QSpinBox(tab_3);
        crackPointCountSpinBox->setObjectName(QStringLiteral("crackPointCountSpinBox"));
        crackPointCountSpinBox->setValue(3);

        gridLayout_4->addWidget(crackPointCountSpinBox, 9, 1, 1, 1);

        randomSaltButton = new QPushButton(tab_3);
        randomSaltButton->setObjectName(QStringLiteral("randomSaltButton"));

        gridLayout_4->addWidget(randomSaltButton, 2, 2, 1, 1);

        hashButton = new QPushButton(tab_3);
        hashButton->setObjectName(QStringLiteral("hashButton"));

        gridLayout_4->addWidget(hashButton, 1, 2, 1, 1);

        hashComboBox = new QComboBox(tab_3);
        hashComboBox->setObjectName(QStringLiteral("hashComboBox"));
        hashComboBox->setMaximumSize(QSize(100, 16777215));

        gridLayout_4->addWidget(hashComboBox, 0, 1, 1, 1);

        crackTimeLabel = new QLabel(tab_3);
        crackTimeLabel->setObjectName(QStringLiteral("crackTimeLabel"));

        gridLayout_4->addWidget(crackTimeLabel, 5, 2, 1, 1);

        plotCrackButton = new QPushButton(tab_3);
        plotCrackButton->setObjectName(QStringLiteral("plotCrackButton"));

        gridLayout_4->addWidget(plotCrackButton, 10, 0, 1, 1);

        pointCountLabel = new QLabel(tab_3);
        pointCountLabel->setObjectName(QStringLiteral("pointCountLabel"));

        gridLayout_4->addWidget(pointCountLabel, 9, 0, 1, 1);

        charCountLabel = new QLabel(tab_3);
        charCountLabel->setObjectName(QStringLiteral("charCountLabel"));

        gridLayout_4->addWidget(charCountLabel, 8, 0, 1, 1);

        logScaleCheckBox = new QCheckBox(tab_3);
        logScaleCheckBox->setObjectName(QStringLiteral("logScaleCheckBox"));

        gridLayout_4->addWidget(logScaleCheckBox, 10, 1, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        gridLayout_2 = new QGridLayout(tab_4);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        random_composite = new QPushButton(tab_4);
        random_composite->setObjectName(QStringLiteral("random_composite"));

        gridLayout_2->addWidget(random_composite, 3, 0, 1, 1);

        drawFactoring = new QPushButton(tab_4);
        drawFactoring->setObjectName(QStringLiteral("drawFactoring"));

        gridLayout_2->addWidget(drawFactoring, 16, 0, 2, 1);

        timeLabel = new QLabel(tab_4);
        timeLabel->setObjectName(QStringLiteral("timeLabel"));

        gridLayout_2->addWidget(timeLabel, 7, 0, 1, 1);

        compositeTextField = new QLineEdit(tab_4);
        compositeTextField->setObjectName(QStringLiteral("compositeTextField"));

        gridLayout_2->addWidget(compositeTextField, 2, 0, 1, 1);

        factorAlgChooser = new QComboBox(tab_4);
        factorAlgChooser->setObjectName(QStringLiteral("factorAlgChooser"));

        gridLayout_2->addWidget(factorAlgChooser, 0, 0, 1, 1);

        factoringGraphicsView = new QGraphicsView(tab_4);
        factoringGraphicsView->setObjectName(QStringLiteral("factoringGraphicsView"));
        factoringGraphicsView->setMinimumSize(QSize(600, 0));

        gridLayout_2->addWidget(factoringGraphicsView, 0, 2, 28, 1);

        resultLabel = new QLabel(tab_4);
        resultLabel->setObjectName(QStringLiteral("resultLabel"));

        gridLayout_2->addWidget(resultLabel, 6, 0, 1, 1);

        factorPrimesButton = new QPushButton(tab_4);
        factorPrimesButton->setObjectName(QStringLiteral("factorPrimesButton"));

        gridLayout_2->addWidget(factorPrimesButton, 4, 0, 2, 1);

        label_7 = new QLabel(tab_4);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_2->addWidget(label_7, 1, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        dataCountLabel = new QLabel(tab_4);
        dataCountLabel->setObjectName(QStringLiteral("dataCountLabel"));

        horizontalLayout_4->addWidget(dataCountLabel);

        dataPointsSpinBox = new QSpinBox(tab_4);
        dataPointsSpinBox->setObjectName(QStringLiteral("dataPointsSpinBox"));
        dataPointsSpinBox->setValue(10);

        horizontalLayout_4->addWidget(dataPointsSpinBox);


        gridLayout_2->addLayout(horizontalLayout_4, 13, 0, 2, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        dataStartLabel = new QLabel(tab_4);
        dataStartLabel->setObjectName(QStringLiteral("dataStartLabel"));

        horizontalLayout_2->addWidget(dataStartLabel);

        startDigitsSpinBox = new QSpinBox(tab_4);
        startDigitsSpinBox->setObjectName(QStringLiteral("startDigitsSpinBox"));
        startDigitsSpinBox->setValue(2);

        horizontalLayout_2->addWidget(startDigitsSpinBox);


        gridLayout_2->addLayout(horizontalLayout_2, 11, 0, 1, 1);

        plotLabel = new QLabel(tab_4);
        plotLabel->setObjectName(QStringLiteral("plotLabel"));

        gridLayout_2->addWidget(plotLabel, 10, 0, 1, 1);

        tabWidget->addTab(tab_4, QString());

        horizontalLayout->addWidget(tabWidget);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1014, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);
        crackTabWidget->setCurrentIndex(1);


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
        label_2->setText(QApplication::translate("MainWindow", "Hash Function", 0));
        crackComboBox->clear();
        crackComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Brute force", 0)
         << QApplication::translate("MainWindow", "Dictionary attack", 0)
         << QApplication::translate("MainWindow", "Lookup tables", 0)
        );
        label_9->setText(QApplication::translate("MainWindow", "Crack algorithm", 0));
        label_6->setText(QApplication::translate("MainWindow", "Hashed text:", 0));
        label_3->setText(QApplication::translate("MainWindow", "Your Text:", 0));
        label_8->setText(QApplication::translate("MainWindow", "Salt:", 0));
        label_10->setText(QApplication::translate("MainWindow", "Character Count:", 0));
        lettersCheckBox->setText(QApplication::translate("MainWindow", "Letters", 0));
        upCaseCheckBox->setText(QApplication::translate("MainWindow", "Include uppercase", 0));
        numbersCheckBox->setText(QApplication::translate("MainWindow", "Numbers", 0));
        customCheckBox->setText(QApplication::translate("MainWindow", "Custom alphabet:", 0));
        symbolsCheckBox->setText(QApplication::translate("MainWindow", "Symbols", 0));
        crackTabWidget->setTabText(crackTabWidget->indexOf(tab), QApplication::translate("MainWindow", "Brute force settings", 0));
        label_5->setText(QApplication::translate("MainWindow", "Number of words:", 0));
        label_11->setText(QApplication::translate("MainWindow", "Add numbers to end", 0));
        appendCheckBox->setText(QString());
        label_12->setText(QApplication::translate("MainWindow", "beginning", 0));
        prependCheckBox->setText(QString());
        label_13->setText(QApplication::translate("MainWindow", "Digits:", 0));
        crackTabWidget->setTabText(crackTabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Dictionary crack settings", 0));
        label_4->setText(QApplication::translate("MainWindow", "Result:", 0));
        crackPlotLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Plot data points</span></p></body></html>", 0));
        crackButton->setText(QApplication::translate("MainWindow", "Reverse!", 0));
        randomSaltButton->setText(QApplication::translate("MainWindow", "Random", 0));
        hashButton->setText(QApplication::translate("MainWindow", "Hash!", 0));
        hashComboBox->clear();
        hashComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "MD5", 0)
         << QApplication::translate("MainWindow", "SHA-512", 0)
         << QApplication::translate("MainWindow", "PBKDF2", 0)
        );
        crackTimeLabel->setText(QApplication::translate("MainWindow", "Time:", 0));
        plotCrackButton->setText(QApplication::translate("MainWindow", "Draw points", 0));
        pointCountLabel->setText(QApplication::translate("MainWindow", "Number of points", 0));
        charCountLabel->setText(QApplication::translate("MainWindow", "Starting characters", 0));
        logScaleCheckBox->setText(QApplication::translate("MainWindow", "Use log scale", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Hash", 0));
        random_composite->setText(QApplication::translate("MainWindow", "Random", 0));
        drawFactoring->setText(QApplication::translate("MainWindow", "Draw points", 0));
        timeLabel->setText(QApplication::translate("MainWindow", "Time: ", 0));
        factorAlgChooser->clear();
        factorAlgChooser->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Brute force (small to big)", 0)
         << QApplication::translate("MainWindow", "Brute force (big to small)", 0)
         << QApplication::translate("MainWindow", "Quadratic sieve", 0)
        );
        resultLabel->setText(QApplication::translate("MainWindow", "Result:", 0));
        factorPrimesButton->setText(QApplication::translate("MainWindow", "Factor", 0));
        label_7->setText(QApplication::translate("MainWindow", "Enter a product of two primes:", 0));
        dataCountLabel->setText(QApplication::translate("MainWindow", "Number of points", 0));
        dataStartLabel->setText(QApplication::translate("MainWindow", "Starting digits", 0));
        plotLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Plot data points</span></p></body></html>", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Factoring", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
