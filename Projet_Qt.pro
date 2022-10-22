QT       += core gui widgets sql

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets

TARGET = Projet_Qt
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        Contact/StdContact.cpp \
        Contact/StdListContact.cpp \
        Interaction/Interaction.cpp \
        Interaction/ListInteraction.cpp \
        Tache/Tache.cpp \
        Tache/ListTache.cpp \


HEADERS += \
        Contact/StdContact.h \
        Contact/StdListContact.h \
        Interaction/Interaction.h \
        Interaction/ListInteraction.h \
        Tache/Tache.h \
        Tache/ListTache.h \
