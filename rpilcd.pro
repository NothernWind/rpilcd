HEADERS += \
    src/characterdisplay.h \
    src/window.h \
    src/bcm2835/spi0.h \
    src/bcm2835/gpio.h \
    src/bcm2835/bcm2835.h \
    src/spilcd.h

SOURCES += \
    src/characterdisplay.cpp \
    src/window.cpp \
    src/main.cpp \
    src/bcm2835/spi0.c \
    src/bcm2835/gpio.c \
    src/bcm2835/bcm2835.c \
    src/spilcd.c
