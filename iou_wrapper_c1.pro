TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        src/demo.cpp \
        src/iou.cpp \
        src/main_c.c \
        src/wrapper_iou.cpp

HEADERS += \
    inc/IOU.h \
    inc/demo.h \
    inc/wrapper_iou.h
