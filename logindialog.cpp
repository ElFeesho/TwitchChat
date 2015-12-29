#include "logindialog.h"
#include "ircchatwindow.h"

#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) : QDialog(parent), ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

void LoginDialog::on_connectButton_clicked()
{
    IrcChatWindow *win = new IrcChatWindow(ui->usernameText->text(), ui->channelText->text());
    win->show();
    close();
}
