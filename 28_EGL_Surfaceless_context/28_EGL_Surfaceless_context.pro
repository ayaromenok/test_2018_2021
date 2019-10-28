#required to build with GLESv2 lib from QMake
QT       += core gui

CONFIG += c++11 console
CONFIG -= app_bundle

INCLUDEPATH += -I/usr/include/libdrm
LIBS += -lGLESv2 -lEGL -lgbm



DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
