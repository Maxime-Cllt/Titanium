QT       += core gui widgets sql

TARGET = Projet_Qt
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

ICON = images/app.icns
RC_ICONS = images/app.ico

SOURCES += \
        main.cpp \
        Contact/QtContact.cpp \
        MainWindow/MainWindow.cpp \
        Contact/Widget/GroupeBoxContact.cpp \
        Contact/Widget/ListContactWidget.cpp \
        ContactDialog/ModifContactDialog.cpp \
        ContactDialog/ContactDialog.cpp \
        Contact/StdContact.cpp \
        ContactDialog/CreationContactDialog.cpp \
        Contact/StdListContact.cpp \
        Interaction/Interaction.cpp \
        Interaction/Widget/CreationInteractionDialog.cpp \
        Interaction/Widget/GroupBoxInteraction.cpp \
        Interaction/Widget/ListInteractionWidget.cpp \
        BaseDeDonnees/BD.cpp \
        Menu/MenuBar.cpp \
        Interaction/ListInteraction.cpp \
        Tache/Tache.cpp \
        Tache/ListTache.cpp \
        Json/JsonConverter.cpp \
        Menu/ExportImportContacts/ExportImportMenu.cpp \
        Utility/Utility.cpp \
        ToolBar/ToolBar.cpp \
        ToolBar/RechercheContact/RechercheContactDialog.cpp \
        Interaction/Widget/InteractionTextEdit.cpp \
        Tache/Widget/RechercheTaches.cpp \
        Historique/ListHistorique.cpp \
        ToolBar/RechercheTache/TreeTacheDialog.cpp \
        ToolBar/Suppression/SuppressionDialog.cpp \
        ToolBar/Suppression/TreeWidget.cpp

HEADERS += \
        Contact/QtContact.h \
        MainWindow/MainWindow.h \
        Contact/Widget/GroupeBoxContact.h \
        Contact/Widget/ListContactWidget.h \
        ContactDialog/ModifContactDialog.h \
        ContactDialog/ContactDialog.h \
        Contact/StdContact.h \
        ContactDialog/CreationContactDialog.h \
        Contact/StdListContact.h \
        Interaction/Interaction.h \
        Interaction/Widget/CreationInteractionDialog.h \
        Interaction/Widget/GroupBoxInteraction.h \
        Interaction/Widget/ListInteractionWidget.h \
        BaseDeDonnees/BD.h \
        Menu/MenuBar.h \
        Interaction/ListInteraction.h \
        Tache/Tache.h \
        Tache/ListTache.h \
        Json/JsonConverter.h \
        Menu/ExportImportContacts/ExportImportMenu.h \
        Utility/Utility.h \
        ToolBar/ToolBar.h \
        ToolBar/RechercheContact/RechercheContactDialog.h \
        Interaction/Widget/InteractionTextEdit.h \
        Tache/Widget/RechercheTaches.h \
        Historique/ListHistorique.h \
        ToolBar/RechercheTache/TreeTacheDialog.h \
        ToolBar/Suppression/SuppressionDialog.h \
        ToolBar/Suppression/TreeWidget.h

RESOURCES += \
    application.qrc

CONFIG -= console