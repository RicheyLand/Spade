QT += widgets core gui

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

QMAKE_CXXFLAGS_RELEASE -= -O1
QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE += -std=c++14 -O3

CONFIG += c++14

CONFIG(release, debug|release) {
    CONFIG += optimize_full
}

RESOURCES += \
    resources.qrc

DISTFILES +=
