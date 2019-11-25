TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp
LIBS += -lHalide -lpthread -ldl
LIBS += -ljpeg -lpng16
