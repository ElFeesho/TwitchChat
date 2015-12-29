#ifndef IRCMESSAGE_H
#define IRCMESSAGE_H

#include <QString>

class ircmessage
{
public:
    ircmessage(const QString &sender, const QString &message);

    QString message_sender();
    QString message_data();
private:
    QString _sender;
    QString _message;
};

#endif // IRCMESSAGE_H
