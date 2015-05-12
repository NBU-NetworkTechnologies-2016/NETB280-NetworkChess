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
    piece.cpp

HEADERS  += mainboard.h \
    menu.h \
    chesslogic.h \
    piece.h

FORMS    += mainboard.ui \
    menu.ui

RESOURCES += \
    resource.qrc
