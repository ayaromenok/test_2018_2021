# Copyright(C) 2018 Andrey Yaromenok, ayaromenok@gmail.com
# MIT License - https://github.com/ayaromenok/OpenCVwithQt/blob/master/LICENSE
QT += qml quick
CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS
include(opencv.pri)

HEADERS += \
    qcvobject.h \
    cvres.h \
    share.h

SOURCES += \
        main.cpp \
    qcvobject.cpp \
    cvres.cpp

RESOURCES += qml.qrc \
    data.qrc



# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
