#include "ircmessage.h"

ircmessage::ircmessage(const QString &sender, const QString &message) : _sender(sender), _message(message)
{

}

QString ircmessage::message_sender()
{
    return _sender;
}

QString ircmessage::message_data()
{
    return _message;
}
