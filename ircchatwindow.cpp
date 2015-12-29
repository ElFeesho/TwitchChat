#include "ircchatwindow.h"
#include "ui_ircchatwindow.h"

IrcChatWindow::IrcChatWindow(const QString &nick, const QString &channel, QWidget *parent) :
    QMainWindow(parent),
    nickName(nick),
    channelName(channel),
    ui(new Ui::IRCChatWindow),
    chat("/home/chris/.twitchchat",nick, channel, this)
{
    ui->setupUi(this);
    this->connect(&chat, SIGNAL(connectionEstablished()), this, SLOT(enableUI()));
    this->connect(&chat, SIGNAL(chatMessage(ircmessage)), &channelModel, SLOT(on_chatMessage(ircmessage)));

    ui->chatMessages->setModel(&channelModel);
}

IrcChatWindow::~IrcChatWindow()
{
    delete ui;
}

void IrcChatWindow::enableUI()
{
}

void IrcChatWindow::on_messageInput_returnPressed()
{
    chat.sendMessage(ui->messageInput->text());
    channelModel.on_chatMessage(ircmessage(false, nickName, ui->messageInput->text()));
    ui->messageInput->clear();
}
