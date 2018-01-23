TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    main.c \
    rvsapi.c \
    rvscallback.c

HEADERS += \
    rvsapi.h \
    RvsTypes.h \
    rvscallback.h
