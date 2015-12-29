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

void twitchchat::ircConnected()
{
    qDebug("Connected!");
    emit connectionEstablished();
    ircSocket.write(QByteArray((QString("PASS ") + oauthToken + QString("\r\n")).toStdString().c_str()));
    ircSocket.write(QByteArray("NICK elfeesho\r\n"));
    ircSocket.write("JOIN #ElFeesho\r\n");
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
    qDebug("RECV: %s", message.toStdString().c_str());
}

// TEA TIME
