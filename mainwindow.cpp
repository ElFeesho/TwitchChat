#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    chat("/home/chris/.twitchchat", this)
{
    ui->setupUi(this);
    this->connect(&chat, SIGNAL(connectionEstablished()), this, SLOT(enableUI()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::enableUI()
{
    qDebug("Connection Established!");
}
