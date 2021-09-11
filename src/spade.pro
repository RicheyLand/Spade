#-------------------------------------------------
#
# Project created by QtCreator 2018-02-03T16:14:45
#
#-------------------------------------------------

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = spade
TEMPLATE = app


SOURCES += main.cpp\
        window.cpp \
    element.cpp \
    elements.cpp \
    highlighter.cpp \
    spade.cpp

HEADERS  += window.h \
    element.h \
    elements.h \
    highlighter.h \
    spade.h

FORMS    += window.ui \
    element.ui \
    elements.ui \
    spade.ui

CONFIG += c++14

RESOURCES += \
    resources.qrc

DISTFILES +=
