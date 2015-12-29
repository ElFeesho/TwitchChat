#include "ircchatwindow.h"
#include "logindialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginDialog d;
    d.show();
    //IrcChatWindow w("elfeesho", "#ismailzd");
    //w.show();

    return a.exec();
}
