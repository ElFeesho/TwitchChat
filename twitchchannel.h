#ifndef TWITCHCHANNEL_H
#define TWITCHCHANNEL_H

#include <QAbstractItemModel>
#include <QList>
#include <QStringListModel>
#include "ircmessage.h"

class twitchchannel : public QStringListModel
{
    Q_OBJECT

public:
    explicit twitchchannel(QObject *parent = 0);

public slots:
    void on_chatMessage(ircmessage message);
};

#endif // TWITCHCHANNEL_H
