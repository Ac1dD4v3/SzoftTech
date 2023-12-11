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
#    hiba.cpp \
    hiba.cpp \
        main.cpp \
    orvos.cpp \
    recept.cpp \
    szerepkor.cpp \
#    orvosinput.txt \
#    beteginput.txt \
    HealthcareSystem.cpp


HEADERS += \
    HealthcareSystem.h \
    beteg.h \
    datum.h \
    felhasznalo.h \
#    gyogyszer.h \
    gyogyszer.h \
    gyogyszertar.h \
#    hiba.h \
    hiba.h \
    orvos.h \
    recept.h \
    szerepkor.h \
    szerepkortipus.h

DISTFILES +=
