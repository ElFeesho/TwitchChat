#include "ircchatwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IrcChatWindow w("elfeesho", "#ismailzd");
    w.show();

    return a.exec();
}
