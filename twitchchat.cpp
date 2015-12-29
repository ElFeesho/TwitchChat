#include "twitchchat.h"
#include <QHostAddress>
#include <assert.h>
#include <QFile>

twitchchat::twitchchat(const QString &twitchOAuthToken, QObject *parent) : QObject(parent), ircSocket(parent)
{
    QFile oauthToken(twitchOAuthToken);
    oauthToken.open(QIODevice::ReadOnly);
    QString oauthTokenRead(oauthToken.readAll());
    this->oauthToken = oauthTokenRead;
    oauthToken.close();

    connect(&ircSocket, SIGNAL(connected()), this, SLOT(ircConnected()));
    connect(&ircSocket, SIGNAL(readyRead()), this, SLOT(canRead()));
    ircSocket.connectToHost("irc.twitch.tv", 6667);
}

void twitchchat::handleNumeric(int numeric)
{
    if (numeric == 376)
    {
        ircSocket.write("JOIN #ismailzd\r\n");
    }
}

void twitchchat::sendMessage(const QString &message)
{
    ircSocket.write((QString("PRIVMSG #ismailzd :")+message+QString("\r\n")).toStdString().c_str());
}

void twitchchat::ircConnected()
{
    qDebug("Connected!");
    emit connectionEstablished();
    ircSocket.write(QByteArray((QString("PASS ") + oauthToken + QString("\r\n")).toStdString().c_str()));
    ircSocket.write(QByteArray("NICK elfeesho\r\n"));
}

void twitchchat::canRead()
{
    qDebug("Can read");
    bool hitLineFeed = false;
    char msgBuf[1024] = { 0 };
    QString message;
    while(!hitLineFeed)
    {
        qint64 readBytes = ircSocket.read(msgBuf, 1024);
        message.append(QString::fromLocal8Bit(msgBuf, readBytes));
        hitLineFeed = message.endsWith("\r\n");
    }

    foreach(QString ircMessage, message.split("\r\n"))
    {
        if (ircMessage.startsWith(":"))
        {
            QStringList messageComponents = ircMessage.split(" ");
            bool isNumber = false;
            messageComponents.at(1).toInt(&isNumber);
            if (isNumber)
            {
                handleNumeric(messageComponents.at(1).toInt());
                QString sender =  messageComponents.at(0);
                sender = sender.right(sender.length()-1);
                emit chatMessage(ircmessage(true, sender, ircMessage.right(ircMessage.length()-sender.length()-1)));
            }
            else if(messageComponents.at(1) == QString("PRIVMSG"))
            {
                QString nick = messageComponents.at(0);
                nick.truncate(nick.indexOf('!'));
                nick = nick.right(nick.length()-1);
                QString privmesg = ircMessage.mid(ircMessage.indexOf(':', ircMessage.indexOf(':')+1)+1);
                emit chatMessage(ircmessage(false, nick, privmesg));
            }

        }
        else if(ircMessage.startsWith("PING"))
        {
            // If we get a ping, we should be polite and pong
            QString server = ircMessage.split(":").at(1);
            qDebug("Sending pong to %s", server.toStdString().c_str());
            ircSocket.write((QString("PONG ")+server+QString("\r\n")).toStdString().c_str());
            emit chatMessage(ircmessage(true, server, "ping received"));
        }
        qDebug("IRC MESSAGE %s", ircMessage.toStdString().c_str());
    }

}
