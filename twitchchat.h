#ifndef TWITCHCHAT_H
#define TWITCHCHAT_H

#include <QObject>
#include <QString>
#include <QTcpSocket>

class twitchchat : public QObject
{
    Q_OBJECT
public:
    explicit twitchchat(const QString &oauthTokenFile, QObject *parent = 0);

signals:
    void connectionEstablished();

public slots:
    void ircConnected();
    void canRead();
private:
    QTcpSocket ircSocket;
    QString oauthToken;
};

#endif // TWITCHCHAT_H
