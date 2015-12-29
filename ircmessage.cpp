#include "ircmessage.h"

ircmessage::ircmessage(bool serverMessage, const QString &sender, const QString &message) : _serverMessage(serverMessage), _sender(sender), _message(message)
{

}

bool ircmessage::is_server_message()
{
    return _serverMessage;
}

QString ircmessage::message_sender()
{
    return _sender;
}

QString ircmessage::message_data()
{
    return _message;
}
