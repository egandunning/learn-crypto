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
    QLabel *instructionLabel = new QLabel(tr("Enter hash to break:"));
    QLineEdit *hashEdit = new QLineEdit();

    QLabel *timeInfoLabel = new QLabel(tr("Time to break hash:"));
    QLineEdit *timeEdit = new QLineEdit();
    timeEdit->setReadOnly(true);
    timeEdit->setText(QString::number((hashEdit->text()).length()));
    QHBoxLayout *timeLayout = new QHBoxLayout();
    timeLayout->addWidget(timeInfoLabel);
    timeLayout->addWidget(timeEdit);


    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(instructionLabel);
    mainLayout->addWidget(hashEdit);
    mainLayout->addLayout(timeLayout);
    mainLayout->addStretch(1); //keeps stuff stuck to the top
    setLayout(mainLayout);
}

RsaTab::RsaTab(QWidget *parent) : QWidget(parent)
{

}

HelpTab::HelpTab(QWidget *parent) : QWidget(parent)
{

}
