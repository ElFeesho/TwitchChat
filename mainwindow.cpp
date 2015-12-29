#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    chat("/home/chris/.twitchchat", this)
{
    ui->setupUi(this);
    this->connect(&chat, SIGNAL(connectionEstablished()), this, SLOT(enableUI()));
    this->connect(&chat, SIGNAL(chatMessage(ircmessage)), &channel, SLOT(on_chatMessage(ircmessage)));

    ui->chatMessages->setModel(&channel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::enableUI()
{
    qDebug("Connection Established!");
}

void MainWindow::on_messageInput_returnPressed()
{
    qDebug("WOOP : %s", ui->messageInput->text().toStdString().c_str());
    chat.sendMessage(ui->messageInput->text());
    channel.on_chatMessage(ircmessage("ElFeesho", ui->messageInput->text()));

    ui->messageInput->clear();
}
