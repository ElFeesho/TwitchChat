#ifndef TWITCHCHAT_H
#define TWITCHCHAT_H

#include <QObject>
#include <QString>
#include <QTcpSocket>
#include "ircmessage.h"

class twitchchat : public QObject
{
    Q_OBJECT
public:
    explicit twitchchat(const QString &oauthTokenFile, const QString &nick, const QString &channel, QObject *parent = 0);

    void sendMessage(const QString &message);
    void handleNumeric(int numeric);
signals:
    void connectionEstablished();
    void chatMessage(ircmessage message);

public slots:
    void ircConnected();
    void canRead();
private:
    QTcpSocket ircSocket;
    QString oauthToken;
    QString nickName;
    QString channelName;
};

#endif // TWITCHCHAT_H
