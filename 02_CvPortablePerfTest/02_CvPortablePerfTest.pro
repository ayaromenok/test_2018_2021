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

contains(ANDROID_TARGET_ARCH,armeabi-v7a) {
    ANDROID_EXTRA_LIBS = \
        /home/az/sdk/src/opencv/build/AndroidArm32/install/sdk/native/libs/armeabi-v7a/libopencv_core.so \
        /mnt/homessd/home/az/projects/09_test/02_CvPortablePerfTest/../../../sdk/src/opencv/build/AndroidArm32/install/sdk/native/libs/armeabi-v7a/libopencv_imgcodecs.so \
        /mnt/homessd/home/az/projects/09_test/02_CvPortablePerfTest/../../../sdk/src/opencv/build/AndroidArm32/install/sdk/native/libs/armeabi-v7a/libopencv_imgproc.so \
        /mnt/homessd/home/az/projects/09_test/02_CvPortablePerfTest/../../../sdk/src/opencv/build/AndroidArm32/install/sdk/native/libs/armeabi-v7a/libopencv_superres.so \
        /mnt/homessd/home/az/projects/09_test/02_CvPortablePerfTest/../../../sdk/src/opencv/build/AndroidArm32/install/sdk/native/libs/armeabi-v7a/libopencv_videoio.so \
        $$PWD/../../../sdk/src/opencv/build/AndroidArm32/install/sdk/native/libs/armeabi-v7a/libopencv_aruco.so \
        $$PWD/../../../sdk/src/opencv/build/AndroidArm32/install/sdk/native/libs/armeabi-v7a/libopencv_bgsegm.so \
        $$PWD/../../../sdk/src/opencv/build/AndroidArm32/install/sdk/native/libs/armeabi-v7a/libopencv_bioinspired.so \
        $$PWD/../../../sdk/src/opencv/build/AndroidArm32/install/sdk/native/libs/armeabi-v7a/libopencv_calib3d.so \
        $$PWD/../../../sdk/src/opencv/build/AndroidArm32/install/sdk/native/libs/armeabi-v7a/libopencv_ccalib.so \
        $$PWD/../../../sdk/src/opencv/build/AndroidArm32/install/sdk/native/libs/armeabi-v7a/libopencv_core.so \
        $$PWD/../../../sdk/src/opencv/build/AndroidArm32/install/sdk/native/libs/armeabi-v7a/libopencv_datasets.so \
        $$PWD/../../../sdk/src/opencv/build/AndroidArm32/install/sdk/native/libs/armeabi-v7a/libopencv_dnn.so \
        $$PWD/../../../sdk/src/opencv/build/AndroidArm32/install/sdk/native/libs/armeabi-v7a/libopencv_dnn_objdetect.so \
        $$PWD/../../../sdk/src/opencv/build/AndroidArm32/install/sdk/native/libs/armeabi-v7a/libopencv_dpm.so \
        $$PWD/../../../sdk/src/opencv/build/AndroidArm32/install/sdk/native/libs/armeabi-v7a/libopencv_face.so \
        $$PWD/../../../sdk/src/opencv/build/AndroidArm32/install/sdk/native/libs/armeabi-v7a/libopencv_features2d.so \
        $$PWD/../../../sdk/src/opencv/build/AndroidArm32/install/sdk/native/libs/armeabi-v7a/libopencv_flann.so \
        $$PWD/../../../sdk/src/opencv/build/AndroidArm32/install/sdk/native/libs/armeabi-v7a/libopencv_fuzzy.so \
        $$PWD/../../../sdk/src/opencv/build/AndroidArm32/install/sdk/native/libs/armeabi-v7a/libopencv_hfs.so \
        $$PWD/../../../sdk/src/opencv/build/AndroidArm32/install/sdk/native/libs/armeabi-v7a/libopencv_highgui.so \
        $$PWD/../../../sdk/src/opencv/build/AndroidArm32/install/sdk/native/libs/armeabi-v7a/libopencv_imgcodecs.so \
        $$PWD/../../../sdk/src/opencv/build/AndroidArm32/install/sdk/native/libs/armeabi-v7a/libopencv_img_hash.so \
        $$PWD/../../../sdk/src/opencv/build/AndroidArm32/install/sdk/native/libs/armeabi-v7a/libopencv_imgproc.so \
        $$PWD/../../../sdk/src/opencv/build/AndroidArm32/install/sdk/native/libs/armeabi-v7a/libopencv_line_descriptor.so \
        $$PWD/../../../sdk/src/opencv/build/AndroidArm32/install/sdk/native/libs/armeabi-v7a/libopencv_ml.so \
        $$PWD/../../../sdk/src/opencv/build/AndroidArm32/install/sdk/native/libs/armeabi-v7a/libopencv_objdetect.so \
        $$PWD/../../../sdk/src/opencv/build/AndroidArm32/install/sdk/native/libs/armeabi-v7a/libopencv_optflow.so \
        $$PWD/../../../sdk/src/opencv/build/AndroidArm32/install/sdk/native/libs/armeabi-v7a/libopencv_phase_unwrapping.so \
        $$PWD/../../../sdk/src/opencv/build/AndroidArm32/install/sdk/native/libs/armeabi-v7a/libopencv_photo.so \
        $$PWD/../../../sdk/src/opencv/build/AndroidArm32/install/sdk/native/libs/armeabi-v7a/libopencv_plot.so \
        $$PWD/../../../sdk/src/opencv/build/AndroidArm32/install/sdk/native/libs/armeabi-v7a/libopencv_reg.so \
        $$PWD/../../../sdk/src/opencv/build/AndroidArm32/install/sdk/native/libs/armeabi-v7a/libopencv_rgbd.so \
        $$PWD/../../../sdk/src/opencv/build/AndroidArm32/install/sdk/native/libs/armeabi-v7a/libopencv_saliency.so \
        $$PWD/../../../sdk/src/opencv/build/AndroidArm32/install/sdk/native/libs/armeabi-v7a/libopencv_shape.so \
        $$PWD/../../../sdk/src/opencv/build/AndroidArm32/install/sdk/native/libs/armeabi-v7a/libopencv_stereo.so \
        $$PWD/../../../sdk/src/opencv/build/AndroidArm32/install/sdk/native/libs/armeabi-v7a/libopencv_stitching.so \
        $$PWD/../../../sdk/src/opencv/build/AndroidArm32/install/sdk/native/libs/armeabi-v7a/libopencv_structured_light.so \
        $$PWD/../../../sdk/src/opencv/build/AndroidArm32/install/sdk/native/libs/armeabi-v7a/libopencv_superres.so \
        $$PWD/../../../sdk/src/opencv/build/AndroidArm32/install/sdk/native/libs/armeabi-v7a/libopencv_surface_matching.so \
        $$PWD/../../../sdk/src/opencv/build/AndroidArm32/install/sdk/native/libs/armeabi-v7a/libopencv_text.so \
        $$PWD/../../../sdk/src/opencv/build/AndroidArm32/install/sdk/native/libs/armeabi-v7a/libopencv_tracking.so \
        $$PWD/../../../sdk/src/opencv/build/AndroidArm32/install/sdk/native/libs/armeabi-v7a/libopencv_video.so \
        $$PWD/../../../sdk/src/opencv/build/AndroidArm32/install/sdk/native/libs/armeabi-v7a/libopencv_videoio.so \
        $$PWD/../../../sdk/src/opencv/build/AndroidArm32/install/sdk/native/libs/armeabi-v7a/libopencv_videostab.so \
        $$PWD/../../../sdk/src/opencv/build/AndroidArm32/install/sdk/native/libs/armeabi-v7a/libopencv_xfeatures2d.so \
        $$PWD/../../../sdk/src/opencv/build/AndroidArm32/install/sdk/native/libs/armeabi-v7a/libopencv_ximgproc.so \
        $$PWD/../../../sdk/src/opencv/build/AndroidArm32/install/sdk/native/libs/armeabi-v7a/libopencv_xobjdetect.so \
        $$PWD/../../../sdk/src/opencv/build/AndroidArm32/install/sdk/native/libs/armeabi-v7a/libopencv_xphoto.so
}
