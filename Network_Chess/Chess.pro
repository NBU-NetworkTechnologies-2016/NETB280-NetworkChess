#-------------------------------------------------
#
# Project created by QtCreator 2015-04-04T13:22:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Chess
TEMPLATE = app


SOURCES += main.cpp\
        mainboard.cpp \
    menu.cpp \
    chesslogic.cpp \
    piece.cpp \
    whitepawn.cpp \
    move.cpp \
    blackpawn.cpp \
    king.cpp \
    knight.cpp \
    rook.cpp \
    bishop.cpp \
    queen.cpp \
    creategame.cpp \
    joingame.cpp

HEADERS  += mainboard.h \
    menu.h \
    chesslogic.h \
    piece.h \
    whitepawn.h \
    move.h \
    blackpawn.h \
    king.h \
    knight.h \
    rook.h \
    bishop.h \
    queen.h \
    creategame.h \
    joingame.h

FORMS    += mainboard.ui \
    menu.ui \
    creategame.ui \
    joingame.ui

RESOURCES += \
    resource.qrc
