#-------------------------------------------------
#
# Project created by QtCreator 2015-12-28T23:34:05
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TwitchChat
TEMPLATE = app


SOURCES += main.cpp\
    twitchchat.cpp \
    twitchchannel.cpp \
    ircmessage.cpp \
    ircchatwindow.cpp

HEADERS  += \
    twitchchat.h \
    twitchchannel.h \
    ircmessage.h \
    ircchatwindow.h

FORMS    += \
    ircchatwindow.ui \
    logindialog.ui
