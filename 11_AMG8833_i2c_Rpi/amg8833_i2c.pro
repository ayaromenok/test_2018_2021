QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    qamg8833.h

SOURCES += \
        main.cpp \
    qamg8833.cpp

LIBS += -lwiringPi

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

