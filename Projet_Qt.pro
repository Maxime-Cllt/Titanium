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
        Contact/QtContact.cpp \
        MainWindow/MainWindow.cpp \
        Contact/Widget/GroupeBoxContact.cpp \
        Contact/Widget/ListContactWidget.cpp \
        ContactDialog/ModifContactDialog.cpp \
        ContactDialog/ContactDialog.cpp \
        ContactDialog/CreationContactDialog.cpp \
        Contact/TraductionQtStd.cpp \
        Interaction/Widget/CreationInteractionDialog.cpp \
        Interaction/Widget/GroupBoxInteraction.cpp \
        Interaction/Widget/ListInteractionWidget.cpp \
        BaseDeDonnees/BD.cpp \
        Menu/MenuBar.cpp \
        Menu/RechercheContact/RechercheContactDialog.cpp
        Json/JsonConverter.cpp \



HEADERS += \
        Contact/StdContact.h \
        Contact/StdListContact.h \
        Interaction/Interaction.h \
        Interaction/ListInteraction.h \
        Tache/Tache.h \
        Tache/ListTache.h \
        Contact/QtContact.h \
        MainWindow/MainWindow.h \
        Contact/Widget/GroupeBoxContact.h \
        Contact/Widget/ListContactWidget.h \
        ContactDialog/ModifContactDialog.h \
        ContactDialog/ContactDialog.h \
        ContactDialog/CreationContactDialog.h \
        Contact/TraductionQtStd.h \
        Interaction/Widget/CreationInteractionDialog.h \
        Interaction/Widget/GroupBoxInteraction.h \
        Interaction/Widget/ListInteractionWidget.h \
        BaseDeDonnees/BD.h \
        Menu/MenuBar.h \
        Menu/RechercheContact/RechercheContactDialog.h \
        Json/JsonConverter.h
