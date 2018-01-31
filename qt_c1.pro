TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    main.c \
    rvsapi.c \
    rvscallback.c \
    rvswritecmd.c \
    rvsreaddata.c

HEADERS += \
    rvsapi.h \
    RvsTypes.h \
    rvscallback.h \
    rvsinit.h \
    rvswritecmd.h \
    rvsreaddata.h
