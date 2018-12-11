# Copyright(C) 2018 Andrey Yaromenok, ayaromenok@gmail.com
# MIT License - https://github.com/ayaromenok/OpenCVwithQt/blob/master/LICENSE

#OpenCV SDK places on different platforms
CVLINUX = /usr/local
CVANDROID = /opt/cvAndroid/3/sdk/native
CVANDROID_BIFROST = /opt/cvAndroid/bifrost
CVANDROID_STATIC = /home/az/sdk/src/opencv/build/AndroidArm32/install/sdk/native
CVANDROID_DYNAMIC = /home/az/sdk/src/opencv/build/AndroidArm32/install/sdk/native
CVMACX = /usr/local
CVIOS = /Users/az/sdk/opencv/iOS
CVWIN = C:\sdk\opencv
#OpenCV platform dependend settings
linux:!android {
    message("* OpenCV settings for Unix/Linux.")
    INCLUDEPATH += $${CVLINUX}/include/opencv4
    LIBS += -L$${CVLINUX}/lib
    LIBS += -lopencv_core -lopencv_imgcodecs -lopencv_imgproc -lopencv_img_hash -lopencv_videoio
    LIBS += -lopencv_calib3d -lopencv_superres
    LIBS += -lOpenCL

CONFIG(debug, debug|release) {
        message("* use DEBUG HIGHGUI for Unix/Linux only.")
        #use for show intermediate debug windows for now
        DEFINES += CVQT_DEBUG_HIGHGUI
        LIBS += -lopencv_highgui
        # to use highgui with QtQuick app
        QT += widgets
    }

    contains(QMAKE_HOST.arch, x86_64){
        message("        arch: amd64")
        #LIB += -L$${CVLINUX}/lib64
    }
    contains(QMAKE_HOST.arch, x86){
        message("        arch: i386")
        #LIB += -L$${CVLINUX}/lib32
    }
    contains(QMAKE_HOST.arch, arm.*){
        message("        arch: armeabi-v7a")
        #LIB += -L$${CVLINUX}/lib32
    }
}

android {
    INCLUDEPATH += $${CVANDROID_DYNAMIC}/jni/include

    message("* OpenCV settings for Android.")
    contains(ANDROID_TARGET_ARCH,armeabi-v7a) {
        message("        arch: armeabi-v7a")
        message("        opencv: Dynamic/OpenCL")
        LIBS += -L$${CVANDROID_DYNAMIC}/libs/armeabi-v7a
        LIBS += -lopencv_core -lopencv_videoio -lopencv_imgproc
        LIBS += -lopencv_imgcodecs

       ANDROID_EXTRA_LIBS = \
            $${CVANDROID_DYNAMIC}/libs/armeabi-v7a/libopencv_core.so \
            $${CVANDROID_DYNAMIC}/libs/armeabi-v7a/libopencv_videoio.so \
            $${CVANDROID_DYNAMIC}/libs/armeabi-v7a/libopencv_imgproc.so \
            $${CVANDROID_DYNAMIC}/libs/armeabi-v7a/libopencv_imgcodecs.so
    }
}

macx {
    message("* OpenCV settings for Mac OSX")
    INCLUDEPATH += $${CVMACX}/include
    LIBS += -L$${CVMACX}/lib
    LIBS += -lopencv_core -lopencv_imgcodecs -lopencv_imgproc -lopencv_videoio -lopencv_superres
    LIBS += -lopencv_calib3d
    contains(QMAKE_HOST.arch, x86_64){
        message("        arch: amd64")
        #LIB += -L$${CVMACX}/lib64
    }
    contains(QMAKE_HOST.arch, x86){
        message("        arch: i386")
        #LIB += -L$${CVMACX}/lib32
    }
}

ios {
    LIBS += -F$${CVIOS}
    LIBS += -framework opencv2
    simulator {
        message("* OpenCV settings for iOS Simulator")
    }
    device{
        message("* OpenCV settings for iOS")
    }
}

#win32:debug {
#      CONFIG += console
#}
win32{
    message("* OpenCV settings for Windows.")
    INCLUDEPATH += $${CVWIN}/include

    contains(QMAKE_TARGET.arch, x86_64){
        message("        arch: amd64")
        win32-msvc* {
            MSVC_VER = $$(VisualStudioVersion)
            equals(MSVC_VER, 12.0){
                message("           msvc12 - 2013")
                # MSVC2013 build required camera capture via file
                DEFINES += CAMERA_CAPTURE_VIA_FILE
                LIBS += -L$${CVWIN}/x64/vc12/lib
                CONFIG(debug, debug|release) {
                    message( "           debug" )
                    CONFIG += console
                    LIBS += -lopencv_world400d -lopencv_img_hash400d
                } else {
                    message( "           release" )
                    LIBS += -lopencv_world400 -lopencv_img_hash400
                }           }
            equals(MSVC_VER, 13.0){
                # camera capture via buffer NOT tested
                message("           msvc13 - 2014")
            }
            equals(MSVC_VER, 14.0){
                # camera capture via buffer NOT tested
                message("           msvc14 - 2015")
            }
            equals(MSVC_VER, 15.0){

                message("           msvc15 - 2017")
                LIBS += -L$${CVWIN}/x64/vc15/lib
                # MSVC2017 required camera capture via file
                DEFINES += CAMERA_CAPTURE_VIA_FILE
                CONFIG(debug, debug|release) {
                    message( "           debug" )
                    CONFIG += console
                    LIBS += -lopencv_world400d -lopencv_img_hash400d
                } else {
                    message( "           release" )
                    LIBS += -lopencv_world400 -lopencv_img_hash400
                }
            }
        }
    }
#    contains(QMAKE_TARGET.arch, x86){
#        message("        arch: i386")
        win32-g++ {
            message("               compiler: mingw-32")
            # mingw-32 required camera capture via file
            DEFINES += CAMERA_CAPTURE_VIA_FILE
            LIBS += $${CVWIN}\x86\mingw\bin\libopencv_*.dll
        }
#    }
}
