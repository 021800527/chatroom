#-------------------------------------------------
#
# Project created by QtCreator 2019-01-31T22:40:37
#
#-------------------------------------------------
QT       += core gui multimedia
QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = ChatRoom
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    audio.cpp \
    chat.cpp \
    http.cpp \
        main.cpp \
        login.cpp \
    basewindow.cpp \
    mydevice.cpp \
    mytitlebar.cpp \
    spe.cpp \
    speech.cpp \
    tcpclient.cpp \
    tcpserver.cpp \
    chatroom.cpp

HEADERS += \
    audio.h \
    chat.h \
    http.h \
        login.h \
    basewindow.h \
    mydevice.h \
    mytitlebar.h \
    spe.h \
    speech.h \
    tcpclient.h \
    tcpserver.h \
    chatroom.h \ \
    ui_widget.h

FORMS += \
    chat.ui \
        login.ui \
    spe.ui \
    spe.ui \
    tcpclient.ui \
    tcpserver.ui \
    chatroom.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

#set icon
RC_ICONS = chaticon.ico

DISTFILES += \
    icon/IP.png \
    icon/background.jpg \
    icon/bargroud.jpg \
    icon/close.png \
    icon/head.jpg \
    icon/max.png \
    icon/min.png \
    icon/name.png \
    image/bold.png \
    image/clear.png \
    image/color.png \
    image/italic.png \
    image/save.png \
    image/send.png \
    image/skin.png \
    image/speak.png \
    image/under.png \
    libeay32.dll \
    ssleay32.dll
