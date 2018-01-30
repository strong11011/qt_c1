TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    main.c \
    rvsapi.c \
    rvscallback.c \
    loadcmd.c

HEADERS += \
    rvsapi.h \
    RvsTypes.h \
    rvscallback.h \
    rvsinit.h \
    loadcmd.h
