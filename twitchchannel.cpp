#include "twitchchannel.h"

twitchchannel::twitchchannel(QObject *parent)
    : QStringListModel(parent)
{
}

void twitchchannel::on_chatMessage(ircmessage message)
{
    setStringList(stringList() << message.message_data());
}
