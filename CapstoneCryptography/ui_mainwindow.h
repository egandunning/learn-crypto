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
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
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
    QGridLayout *gameGrid;
    QWidget *tab_3;
    QGridLayout *gridLayout_4;
    QLabel *crackPlotLabel;
    QSpinBox *crackPointCountSpinBox;
    QPushButton *hashButton;
    QPushButton *randomSaltButton;
    QComboBox *hashComboBox;
    QCheckBox *hashLogScaleCheckBox;
    QPushButton *plotCrackButton;
    QLabel *crackTimeLabel;
    QPushButton *crackButton;
    QLabel *pointCountLabel;
    QGraphicsView *crackGraphicsView;
    QLabel *charCountLabel;
    QTextEdit *digestField;
    QLabel *label_2;
    QLabel *label_6;
    QLabel *label_3;
    QPushButton *cancelCrackButton;
    QLabel *label_4;
    QLineEdit *crackedField;
    QLineEdit *saltField;
    QLabel *label_8;
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
    QSpinBox *threadSpinBox;
    QLabel *label;
    QWidget *tab_2;
    QLabel *label_5;
    QSpinBox *wordCountSpinBox;
    QLabel *label_11;
    QCheckBox *appendCheckBox;
    QLabel *label_12;
    QCheckBox *prependCheckBox;
    QLabel *label_13;
    QSpinBox *digitCountSpinBox;
    QCheckBox *capCheckBox;
    QCheckBox *dictSymbolsCheckBox;
    QCheckBox *completeModeCheckBox;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *plaintextField;
    QSpinBox *charCountSpinBox_2;
    QPushButton *clearCrackGraph;
    QProgressBar *crackProgressBar;
    QWidget *tab_4;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *drawFactoring;
    QCheckBox *factorLogScaleCheckBox;
    QPushButton *clearFactorGraph;
    QHBoxLayout *horizontalLayout_4;
    QLabel *dataCountLabel;
    QSpinBox *dataPointsSpinBox;
    QPushButton *factorPrimesButton;
    QLabel *timeLabel;
    QLabel *plotLabel;
    QLabel *resultLabel;
    QComboBox *factorAlgChooser;
    QPlainTextEdit *compositeTextField;
    QGraphicsView *factoringGraphicsView;
    QLabel *label_7;
    QPushButton *stopFactorPushButton;
    QPushButton *random_composite;
    QPlainTextEdit *resultField;
    QHBoxLayout *horizontalLayout_2;
    QLabel *dataStartLabel;
    QSpinBox *startDigitsSpinBox;
    QProgressBar *factorProgressBar;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1014, 742);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMaximumSize(QSize(16777215, 900));
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
        tabWidget->setTabPosition(QTabWidget::West);
        gameTab = new QWidget();
        gameTab->setObjectName(QStringLiteral("gameTab"));
        gridLayout_3 = new QGridLayout(gameTab);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        pushButton_3 = new QPushButton(gameTab);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout_3->addWidget(pushButton_3, 1, 1, 1, 1);

        pushButton = new QPushButton(gameTab);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_3->addWidget(pushButton, 1, 0, 1, 1);

        gameGrid = new QGridLayout();
        gameGrid->setSpacing(6);
        gameGrid->setObjectName(QStringLiteral("gameGrid"));
        gameGrid->setContentsMargins(-1, 20, -1, 20);

        gridLayout_3->addLayout(gameGrid, 0, 0, 1, 2);

        tabWidget->addTab(gameTab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_4 = new QGridLayout(tab_3);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        crackPlotLabel = new QLabel(tab_3);
        crackPlotLabel->setObjectName(QStringLiteral("crackPlotLabel"));

        gridLayout_4->addWidget(crackPlotLabel, 7, 0, 1, 1);

        crackPointCountSpinBox = new QSpinBox(tab_3);
        crackPointCountSpinBox->setObjectName(QStringLiteral("crackPointCountSpinBox"));
        crackPointCountSpinBox->setValue(5);

        gridLayout_4->addWidget(crackPointCountSpinBox, 9, 1, 1, 1);

        hashButton = new QPushButton(tab_3);
        hashButton->setObjectName(QStringLiteral("hashButton"));

        gridLayout_4->addWidget(hashButton, 1, 2, 1, 1);

        randomSaltButton = new QPushButton(tab_3);
        randomSaltButton->setObjectName(QStringLiteral("randomSaltButton"));

        gridLayout_4->addWidget(randomSaltButton, 2, 2, 1, 1);

        hashComboBox = new QComboBox(tab_3);
        hashComboBox->setObjectName(QStringLiteral("hashComboBox"));
        hashComboBox->setMaximumSize(QSize(100, 16777215));

        gridLayout_4->addWidget(hashComboBox, 0, 1, 1, 1);

        hashLogScaleCheckBox = new QCheckBox(tab_3);
        hashLogScaleCheckBox->setObjectName(QStringLiteral("hashLogScaleCheckBox"));

        gridLayout_4->addWidget(hashLogScaleCheckBox, 11, 1, 1, 1);

        plotCrackButton = new QPushButton(tab_3);
        plotCrackButton->setObjectName(QStringLiteral("plotCrackButton"));

        gridLayout_4->addWidget(plotCrackButton, 11, 0, 1, 1);

        crackTimeLabel = new QLabel(tab_3);
        crackTimeLabel->setObjectName(QStringLiteral("crackTimeLabel"));

        gridLayout_4->addWidget(crackTimeLabel, 5, 2, 1, 1);

        crackButton = new QPushButton(tab_3);
        crackButton->setObjectName(QStringLiteral("crackButton"));

        gridLayout_4->addWidget(crackButton, 4, 1, 1, 1);

        pointCountLabel = new QLabel(tab_3);
        pointCountLabel->setObjectName(QStringLiteral("pointCountLabel"));

        gridLayout_4->addWidget(pointCountLabel, 9, 0, 1, 1);

        crackGraphicsView = new QGraphicsView(tab_3);
        crackGraphicsView->setObjectName(QStringLiteral("crackGraphicsView"));
        crackGraphicsView->setMinimumSize(QSize(600, 0));
        crackGraphicsView->setMaximumSize(QSize(16777215, 650));

        gridLayout_4->addWidget(crackGraphicsView, 0, 3, 14, 1);

        charCountLabel = new QLabel(tab_3);
        charCountLabel->setObjectName(QStringLiteral("charCountLabel"));

        gridLayout_4->addWidget(charCountLabel, 8, 0, 1, 1);

        digestField = new QTextEdit(tab_3);
        digestField->setObjectName(QStringLiteral("digestField"));
        digestField->setMinimumSize(QSize(0, 30));
        digestField->setMaximumSize(QSize(100000, 50));

        gridLayout_4->addWidget(digestField, 3, 1, 1, 2);

        label_2 = new QLabel(tab_3);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_4->addWidget(label_2, 0, 0, 1, 1);

        label_6 = new QLabel(tab_3);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_4->addWidget(label_6, 3, 0, 1, 1);

        label_3 = new QLabel(tab_3);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_4->addWidget(label_3, 1, 0, 1, 1);

        cancelCrackButton = new QPushButton(tab_3);
        cancelCrackButton->setObjectName(QStringLiteral("cancelCrackButton"));

        gridLayout_4->addWidget(cancelCrackButton, 4, 2, 1, 1);

        label_4 = new QLabel(tab_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_4->addWidget(label_4, 5, 0, 1, 1);

        crackedField = new QLineEdit(tab_3);
        crackedField->setObjectName(QStringLiteral("crackedField"));
        crackedField->setReadOnly(true);

        gridLayout_4->addWidget(crackedField, 5, 1, 1, 1);

        saltField = new QLineEdit(tab_3);
        saltField->setObjectName(QStringLiteral("saltField"));

        gridLayout_4->addWidget(saltField, 2, 1, 1, 1);

        label_8 = new QLabel(tab_3);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_4->addWidget(label_8, 2, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        crackTabWidget = new QTabWidget(tab_3);
        crackTabWidget->setObjectName(QStringLiteral("crackTabWidget"));
        crackTabWidget->setMaximumSize(QSize(16777215, 160));
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
        threadSpinBox = new QSpinBox(tab);
        threadSpinBox->setObjectName(QStringLiteral("threadSpinBox"));
        threadSpinBox->setGeometry(QRect(150, 100, 44, 27));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 100, 121, 21));
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
        capCheckBox = new QCheckBox(tab_2);
        capCheckBox->setObjectName(QStringLiteral("capCheckBox"));
        capCheckBox->setGeometry(QRect(10, 60, 131, 22));
        dictSymbolsCheckBox = new QCheckBox(tab_2);
        dictSymbolsCheckBox->setObjectName(QStringLiteral("dictSymbolsCheckBox"));
        dictSymbolsCheckBox->setGeometry(QRect(150, 60, 201, 22));
        completeModeCheckBox = new QCheckBox(tab_2);
        completeModeCheckBox->setObjectName(QStringLiteral("completeModeCheckBox"));
        completeModeCheckBox->setGeometry(QRect(10, 90, 141, 22));
        crackTabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(crackTabWidget);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));

        verticalLayout->addLayout(horizontalLayout_5);


        gridLayout_4->addLayout(verticalLayout, 13, 0, 1, 3);

        plaintextField = new QLineEdit(tab_3);
        plaintextField->setObjectName(QStringLiteral("plaintextField"));

        gridLayout_4->addWidget(plaintextField, 1, 1, 1, 1);

        charCountSpinBox_2 = new QSpinBox(tab_3);
        charCountSpinBox_2->setObjectName(QStringLiteral("charCountSpinBox_2"));
        charCountSpinBox_2->setValue(1);

        gridLayout_4->addWidget(charCountSpinBox_2, 8, 1, 1, 1);

        clearCrackGraph = new QPushButton(tab_3);
        clearCrackGraph->setObjectName(QStringLiteral("clearCrackGraph"));

        gridLayout_4->addWidget(clearCrackGraph, 11, 2, 1, 1);

        crackProgressBar = new QProgressBar(tab_3);
        crackProgressBar->setObjectName(QStringLiteral("crackProgressBar"));
        crackProgressBar->setMaximum(100);
        crackProgressBar->setValue(0);
        crackProgressBar->setTextVisible(false);

        gridLayout_4->addWidget(crackProgressBar, 12, 0, 1, 3);

        tabWidget->addTab(tab_3, QString());
        cancelCrackButton->raise();
        label_2->raise();
        crackGraphicsView->raise();
        digestField->raise();
        label_6->raise();
        label_3->raise();
        label_8->raise();
        charCountSpinBox_2->raise();
        saltField->raise();
        crackedField->raise();
        label_4->raise();
        crackPlotLabel->raise();
        plaintextField->raise();
        crackPointCountSpinBox->raise();
        randomSaltButton->raise();
        hashButton->raise();
        hashComboBox->raise();
        crackTimeLabel->raise();
        plotCrackButton->raise();
        pointCountLabel->raise();
        charCountLabel->raise();
        hashLogScaleCheckBox->raise();
        crackButton->raise();
        clearCrackGraph->raise();
        crackProgressBar->raise();
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        gridLayout_2 = new QGridLayout(tab_4);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        drawFactoring = new QPushButton(tab_4);
        drawFactoring->setObjectName(QStringLiteral("drawFactoring"));

        horizontalLayout_3->addWidget(drawFactoring);

        factorLogScaleCheckBox = new QCheckBox(tab_4);
        factorLogScaleCheckBox->setObjectName(QStringLiteral("factorLogScaleCheckBox"));

        horizontalLayout_3->addWidget(factorLogScaleCheckBox);

        clearFactorGraph = new QPushButton(tab_4);
        clearFactorGraph->setObjectName(QStringLiteral("clearFactorGraph"));

        horizontalLayout_3->addWidget(clearFactorGraph);


        gridLayout_2->addLayout(horizontalLayout_3, 15, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        dataCountLabel = new QLabel(tab_4);
        dataCountLabel->setObjectName(QStringLiteral("dataCountLabel"));

        horizontalLayout_4->addWidget(dataCountLabel);

        dataPointsSpinBox = new QSpinBox(tab_4);
        dataPointsSpinBox->setObjectName(QStringLiteral("dataPointsSpinBox"));
        dataPointsSpinBox->setMinimum(1);
        dataPointsSpinBox->setValue(10);

        horizontalLayout_4->addWidget(dataPointsSpinBox);


        gridLayout_2->addLayout(horizontalLayout_4, 14, 0, 1, 1);

        factorPrimesButton = new QPushButton(tab_4);
        factorPrimesButton->setObjectName(QStringLiteral("factorPrimesButton"));

        gridLayout_2->addWidget(factorPrimesButton, 5, 0, 1, 1);

        timeLabel = new QLabel(tab_4);
        timeLabel->setObjectName(QStringLiteral("timeLabel"));

        gridLayout_2->addWidget(timeLabel, 9, 0, 1, 1);

        plotLabel = new QLabel(tab_4);
        plotLabel->setObjectName(QStringLiteral("plotLabel"));

        gridLayout_2->addWidget(plotLabel, 12, 0, 1, 1);

        resultLabel = new QLabel(tab_4);
        resultLabel->setObjectName(QStringLiteral("resultLabel"));
        resultLabel->setWordWrap(true);

        gridLayout_2->addWidget(resultLabel, 7, 0, 1, 1);

        factorAlgChooser = new QComboBox(tab_4);
        factorAlgChooser->setObjectName(QStringLiteral("factorAlgChooser"));

        gridLayout_2->addWidget(factorAlgChooser, 0, 0, 1, 1);

        compositeTextField = new QPlainTextEdit(tab_4);
        compositeTextField->setObjectName(QStringLiteral("compositeTextField"));
        compositeTextField->setMaximumSize(QSize(16777215, 50));

        gridLayout_2->addWidget(compositeTextField, 2, 0, 1, 1);

        factoringGraphicsView = new QGraphicsView(tab_4);
        factoringGraphicsView->setObjectName(QStringLiteral("factoringGraphicsView"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(factoringGraphicsView->sizePolicy().hasHeightForWidth());
        factoringGraphicsView->setSizePolicy(sizePolicy1);
        factoringGraphicsView->setMinimumSize(QSize(600, 0));
        factoringGraphicsView->setMaximumSize(QSize(16777215, 800));

        gridLayout_2->addWidget(factoringGraphicsView, 0, 1, 35, 1);

        label_7 = new QLabel(tab_4);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_2->addWidget(label_7, 1, 0, 1, 1);

        stopFactorPushButton = new QPushButton(tab_4);
        stopFactorPushButton->setObjectName(QStringLiteral("stopFactorPushButton"));

        gridLayout_2->addWidget(stopFactorPushButton, 6, 0, 1, 1);

        random_composite = new QPushButton(tab_4);
        random_composite->setObjectName(QStringLiteral("random_composite"));

        gridLayout_2->addWidget(random_composite, 4, 0, 1, 1);

        resultField = new QPlainTextEdit(tab_4);
        resultField->setObjectName(QStringLiteral("resultField"));
        resultField->setMaximumSize(QSize(16777215, 60));
        resultField->setReadOnly(true);

        gridLayout_2->addWidget(resultField, 8, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        dataStartLabel = new QLabel(tab_4);
        dataStartLabel->setObjectName(QStringLiteral("dataStartLabel"));

        horizontalLayout_2->addWidget(dataStartLabel);

        startDigitsSpinBox = new QSpinBox(tab_4);
        startDigitsSpinBox->setObjectName(QStringLiteral("startDigitsSpinBox"));
        startDigitsSpinBox->setMinimum(3);
        startDigitsSpinBox->setValue(3);

        horizontalLayout_2->addWidget(startDigitsSpinBox);


        gridLayout_2->addLayout(horizontalLayout_2, 13, 0, 1, 1);

        factorProgressBar = new QProgressBar(tab_4);
        factorProgressBar->setObjectName(QStringLiteral("factorProgressBar"));
        factorProgressBar->setValue(0);
        factorProgressBar->setTextVisible(false);

        gridLayout_2->addWidget(factorProgressBar, 16, 0, 1, 1);

        tabWidget->addTab(tab_4, QString());

        horizontalLayout->addWidget(tabWidget);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

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
        crackTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Cryptography Playground", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "Hint", 0));
        pushButton->setText(QApplication::translate("MainWindow", "New Game", 0));
        tabWidget->setTabText(tabWidget->indexOf(gameTab), QApplication::translate("MainWindow", "Game", 0));
        crackPlotLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Plot data points</span></p></body></html>", 0));
        hashButton->setText(QApplication::translate("MainWindow", "Hash!", 0));
        randomSaltButton->setText(QApplication::translate("MainWindow", "Random", 0));
        hashComboBox->clear();
        hashComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "MD5", 0)
         << QApplication::translate("MainWindow", "SHA-512", 0)
         << QApplication::translate("MainWindow", "PBKDF2", 0)
        );
        hashLogScaleCheckBox->setText(QApplication::translate("MainWindow", "Use log scale", 0));
        plotCrackButton->setText(QApplication::translate("MainWindow", "Draw points", 0));
        crackTimeLabel->setText(QApplication::translate("MainWindow", "Time:", 0));
        crackButton->setText(QApplication::translate("MainWindow", "Reverse!", 0));
        pointCountLabel->setText(QApplication::translate("MainWindow", "Number of points", 0));
        charCountLabel->setText(QApplication::translate("MainWindow", "Starting characters", 0));
        label_2->setText(QApplication::translate("MainWindow", "Hash Function", 0));
        label_6->setText(QApplication::translate("MainWindow", "Hashed text:", 0));
        label_3->setText(QApplication::translate("MainWindow", "Your Text:", 0));
        cancelCrackButton->setText(QApplication::translate("MainWindow", "Cancel", 0));
        label_4->setText(QApplication::translate("MainWindow", "Result:", 0));
        label_8->setText(QApplication::translate("MainWindow", "Salt:", 0));
        label_10->setText(QApplication::translate("MainWindow", "Character Count:", 0));
        lettersCheckBox->setText(QApplication::translate("MainWindow", "Letters", 0));
        upCaseCheckBox->setText(QApplication::translate("MainWindow", "Include uppercase", 0));
        numbersCheckBox->setText(QApplication::translate("MainWindow", "Numbers", 0));
        customCheckBox->setText(QApplication::translate("MainWindow", "Custom alphabet:", 0));
        symbolsCheckBox->setText(QApplication::translate("MainWindow", "Symbols", 0));
        label->setText(QApplication::translate("MainWindow", "Number of threads:", 0));
        crackTabWidget->setTabText(crackTabWidget->indexOf(tab), QApplication::translate("MainWindow", "Brute force cracking", 0));
        label_5->setText(QApplication::translate("MainWindow", "Number of words:", 0));
        label_11->setText(QApplication::translate("MainWindow", "Add numbers to end", 0));
        appendCheckBox->setText(QString());
        label_12->setText(QApplication::translate("MainWindow", "beginning", 0));
        prependCheckBox->setText(QString());
        label_13->setText(QApplication::translate("MainWindow", "Digits:", 0));
        capCheckBox->setText(QApplication::translate("MainWindow", "Capitalize letters", 0));
        dictSymbolsCheckBox->setText(QApplication::translate("MainWindow", "Replace letters with symbols", 0));
        completeModeCheckBox->setText(QApplication::translate("MainWindow", "All combinations", 0));
        crackTabWidget->setTabText(crackTabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Dictionary attack", 0));
        clearCrackGraph->setText(QApplication::translate("MainWindow", "Clear graph", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Hash", 0));
        drawFactoring->setText(QApplication::translate("MainWindow", "Draw points", 0));
        factorLogScaleCheckBox->setText(QApplication::translate("MainWindow", "Use log scale", 0));
        clearFactorGraph->setText(QApplication::translate("MainWindow", "Clear graph", 0));
        dataCountLabel->setText(QApplication::translate("MainWindow", "Number of points", 0));
        factorPrimesButton->setText(QApplication::translate("MainWindow", "Factor", 0));
        timeLabel->setText(QApplication::translate("MainWindow", "Time: ", 0));
        plotLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Plot data points</span></p></body></html>", 0));
        resultLabel->setText(QApplication::translate("MainWindow", "Result:", 0));
        factorAlgChooser->clear();
        factorAlgChooser->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Brute force (trial division)", 0)
         << QApplication::translate("MainWindow", "Quadratic sieve", 0)
        );
        label_7->setText(QApplication::translate("MainWindow", "Enter a product of two primes:", 0));
        stopFactorPushButton->setText(QApplication::translate("MainWindow", "Cancel", 0));
        random_composite->setText(QApplication::translate("MainWindow", "Random", 0));
        dataStartLabel->setText(QApplication::translate("MainWindow", "Starting digits", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Factoring", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
