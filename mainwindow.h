#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "twitchchat.h"
#include "twitchchannel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void enableUI();
private slots:
    void on_messageInput_returnPressed();

private:
    Ui::MainWindow *ui;
    twitchchat chat;
    twitchchannel channel;
};

#endif // MAINWINDOW_H
