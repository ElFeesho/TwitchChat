#include "twitchchannel.h"

twitchchannel::twitchchannel(QObject *parent)
    : QStringListModel(parent)
{
}

void twitchchannel::on_chatMessage(ircmessage message)
{
    if (message.is_server_message())
    {
        setStringList(stringList() << (QString("*** ") + message.message_sender()+QString("- ")+message.message_data()));
    }
    else
    {
        setStringList(stringList() << (message.message_sender()+QString(": ")+message.message_data()));
    }
}
