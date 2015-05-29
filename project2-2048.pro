#-------------------------------------------------
#
# Project created by QtCreator 2015-05-24T22:38:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = project2-2048
TEMPLATE = app


SOURCES += main.cpp\
        start.cpp \
    puzzle.cpp \
    result.cpp

HEADERS  += start.h \
    puzzle.h \
    result.h

FORMS    += start.ui \
    puzzle.ui \
    result.ui

RESOURCES += \
    bg.qrc

DISTFILES +=
