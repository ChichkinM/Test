TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    variables.cpp \
    functions.cpp \
    graph.cpp \
    memory.cpp \
    exception.cpp

HEADERS += \
    variables.h \
    functions.h \
    graph.h \
    memory.h \
    exception.h
