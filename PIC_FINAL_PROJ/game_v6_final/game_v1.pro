#-------------------------------------------------
#
# Project created by QtCreator 2019-02-10T10:01:51
#
#-------------------------------------------------

QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = game_v1
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
        main.cpp \
        mainwindow.cpp \
    door.cpp \
    doorpage.cpp \
    gameone.cpp \
    gametwo.cpp \
    key.cpp \
    gamethree.cpp \
    finalpage.cpp \
    spacerunner.cpp \
    shooting_game.cpp \
    lose.cpp \
    game_over.cpp \
    live.cpp \
    win_page_1.cpp \
    instructions.cpp

HEADERS += \
        mainwindow.h \
    door.h \
    door.h \
    doorpage.h \
    gameone.h \
    gametwo.h \
    key.h \
    gamethree.h \
    finalpage.h \
    spacerunner.h \
    shooting_game.h \
    lose.h \
    game_over.h \
    live.h \
    win_page_1.h \
    instructions.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    sounds.qrc \
    images.qrc

DISTFILES += \
    ../closedDoor.png
