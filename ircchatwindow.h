#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "twitchchat.h"
#include "twitchchannel.h"

namespace Ui {
class IRCChatWindow;
}

class IrcChatWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit IrcChatWindow(const QString &nick, const QString &channel, QWidget *parent = 0);
    ~IrcChatWindow();
public slots:
    void enableUI();
private slots:
    void on_messageInput_returnPressed();

private:
    Ui::IRCChatWindow *ui;
    twitchchat chat;
    twitchchannel channelModel;
    QString nickName;
    QString channelName;
};

#endif // MAINWINDOW_H
