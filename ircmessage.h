#ifndef IRCMESSAGE_H
#define IRCMESSAGE_H

#include <QString>

class ircmessage
{
public:
    ircmessage(bool serverMessage, const QString &sender, const QString &message);

    bool is_server_message();
    QString message_sender();
    QString message_data();
private:
    bool _serverMessage;
    QString _sender;
    QString _message;
};

#endif // IRCMESSAGE_H
