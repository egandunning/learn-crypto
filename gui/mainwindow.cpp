#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QDialog(parent)
{
    resize(700,600);

    tabWidget = new QTabWidget;
    tabWidget->addTab(new HashTab, tr("Hashes"));
    tabWidget->addTab(new RsaTab, tr("RSA encryption"));
    tabWidget->addTab(new HelpTab, tr("Help"));

    buttonBox = new QDialogButtonBox;
    buttonBox->addButton(tr("Enable hardware acceleration"), QDialogButtonBox::ActionRole);
    buttonBox->addButton(tr("Disable hardware acceleration"), QDialogButtonBox::ActionRole);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(tabWidget);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);

    setWindowTitle(tr("Crypto Learning Tool"));
}

MainWindow::~MainWindow()
{

}

HashTab::HashTab(QWidget *parent) : QWidget(parent)
{
    chooseHash = new QComboBox;
    chooseHash->addItem("SHA1");
    chooseHash->addItem("SHA256");
    chooseHash->addItem("SHA512");
    chooseHash->addItem("MD5");
    chooseHash->addItem("Tiger");

    QLabel *instructionLabel = new QLabel(tr("Enter plaintext to hash:"));
    hashEdit = new QLineEdit();
    QHBoxLayout *hashEditLayout = new QHBoxLayout();
    hashEditLayout->addWidget(instructionLabel);
    hashEditLayout->addWidget(hashEdit);

    timeInfoLabel = new QLabel(tr("Time to compute hash:"));
    timeEdit = new QLineEdit();
    timeEdit->setReadOnly(true);
    QHBoxLayout *timeLayout = new QHBoxLayout();
    timeLayout->addWidget(timeInfoLabel);
    timeLayout->addWidget(timeEdit);

    QLabel *resultLabel = new QLabel(tr("Result of hashing:"));
    hashResult = new QLineEdit();
    hashResult->setReadOnly(true);
    QHBoxLayout *hashResultLayout = new QHBoxLayout();
    hashResultLayout->addWidget(resultLabel);
    hashResultLayout->addWidget(hashResult);

    QPushButton *computeButton = new QPushButton("Compute");

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(chooseHash);
    mainLayout->addLayout(hashEditLayout);
    mainLayout->addLayout(hashResultLayout);
    mainLayout->addLayout(timeLayout);
    mainLayout->addWidget(computeButton);
    mainLayout->addStretch(1); //keeps stuff stuck to the top
    setLayout(mainLayout);

    QObject::connect(computeButton, SIGNAL(clicked()), this, SLOT(computeHash()));

}

void HashTab::computeHash() {

    int hashChoice = chooseHash->currentIndex();
    double duration;
    string source = (hashEdit->text()).toUtf8().constData();
    string result;
    clock_t start;
    HashTransformation* hash;

    switch(hashChoice) {
    case 0:
        hash = new SHA1;
        break;
    case 1:
        hash = new SHA256;
        break;
    case 2:
        hash = new SHA512;
        break;
    case 3:
        hash = new MD5;
        break;
    case 4:
        hash = new Tiger;
        break;
    }

    start = clock();
    StringSource ss(source, true, new HashFilter(*hash, new HexEncoder(new StringSink(result))));
    duration = (clock() - start) / (double) CLOCKS_PER_SEC;

    cout << hashChoice << endl;
    cout << "Plaintext: " << source << endl;
    cout << "Hash: " << result << endl;
    cout << "Elapsed time: " << duration << endl;

    hashResult->setText(QString::fromStdString(result));
    timeEdit->setText(QString::number(duration));
}

RsaTab::RsaTab(QWidget *parent) : QWidget(parent)
{

}

HelpTab::HelpTab(QWidget *parent) : QWidget(parent)
{

}
