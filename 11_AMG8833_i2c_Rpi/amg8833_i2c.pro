QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle
TARGET = testAmg8833_i2c

HEADER += \
	qamg8833.h

SOURCES += \
	qamg8833.cpp \
	amg8833_i2c.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
