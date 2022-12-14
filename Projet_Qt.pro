QT += core gui widgets sql

TARGET = Projet_Qt
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

ICON = images/app.icns
RC_ICONS = images/app.ico

SOURCES += \
        src/main.cpp \
        src/Contact/QtContact.cpp \
        src/MainWindow/MainWindow.cpp \
        src/Contact/Widget/GroupeBoxContact.cpp \
        src/Contact/Widget/ListContactWidget.cpp \
        src/ContactDialog/ModifContactDialog.cpp \
        src/ContactDialog/ContactDialog.cpp \
        src/Contact/StdContact.cpp \
        src/ContactDialog/CreationContactDialog.cpp \
        src/Contact/StdListContact.cpp \
        src/Interaction/Interaction.cpp \
        src/Interaction/Widget/CreationInteractionDialog.cpp \
        src/Interaction/Widget/GroupBoxInteraction.cpp \
        src/Interaction/Widget/ListInteractionWidget.cpp \
        src/BaseDeDonnees/BD.cpp \
        src/Menu/MenuBar.cpp \
        src/Interaction/ListInteraction.cpp \
        src/Tache/Tache.cpp \
        src/Tache/ListTache.cpp \
        src/Json/JsonConverter.cpp \
        src/Menu/ExportImportContacts/ExportImportMenu.cpp \
        src/Utility/Utility.cpp \
        src/ToolBar/ToolBar.cpp \
        src/ToolBar/RechercheContact/RechercheContactDialog.cpp \
        src/Interaction/Widget/InteractionTextEdit.cpp \
        src/Tache/Widget/RechercheTaches.cpp \
        src/Historique/ListHistorique.cpp \
        src/ToolBar/RechercheTache/TreeTacheDialog.cpp \
        src/ToolBar/Suppression/SuppressionDialog.cpp \
        src/ToolBar/Suppression/TreeWidget.cpp

HEADERS += \
        src/Contact/QtContact.h \
        src/MainWindow/MainWindow.h \
        src/Contact/Widget/GroupeBoxContact.h \
        src/Contact/Widget/ListContactWidget.h \
        src/ContactDialog/ModifContactDialog.h \
        src/ContactDialog/ContactDialog.h \
        src/Contact/StdContact.h \
        src/ContactDialog/CreationContactDialog.h \
        src/Contact/StdListContact.h \
        src/Interaction/Interaction.h \
        src/Interaction/Widget/CreationInteractionDialog.h \
        src/Interaction/Widget/GroupBoxInteraction.h \
        src/Interaction/Widget/ListInteractionWidget.h \
        src/BaseDeDonnees/BD.h \
        src/Menu/MenuBar.h \
        src/Interaction/ListInteraction.h \
        src/Tache/Tache.h \
        src/Tache/ListTache.h \
        src/Json/JsonConverter.h \
        src/Menu/ExportImportContacts/ExportImportMenu.h \
        src/Utility/Utility.h \
        src/ToolBar/ToolBar.h \
        src/ToolBar/RechercheContact/RechercheContactDialog.h \
        src/Interaction/Widget/InteractionTextEdit.h \
        src/Tache/Widget/RechercheTaches.h \
        src/Historique/ListHistorique.h \
        src/ToolBar/RechercheTache/TreeTacheDialog.h \
        src/ToolBar/Suppression/SuppressionDialog.h \
        src/ToolBar/Suppression/TreeWidget.h

RESOURCES += \
    application.qrc

CONFIG -= console