TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    beteg.cpp \
    datum.cpp \
        felhasznalo.cpp \
    gyogyszer.cpp \
    gyogyszertar.cpp \
    hiba.cpp \
        main.cpp \
    orvos.cpp \
    recept.cpp \
    szerepkor.cpp \
    szerepkortipus.cpp

HEADERS += \
    beteg.h \
    datum.h \
    felhasznalo.h \
    gyogyszer.h \
    gyogyszertar.h \
    hiba.h \
    orvos.h \
    recept.h \
    szerepkor.h \
    szerepkortipus.h
