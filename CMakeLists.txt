cmake_minimum_required(VERSION 3.23)
project(Projet-QT)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        Sql
        REQUIRED)

add_executable(Projet-QT main.cpp Contact/QtContact.cpp Contact/QtContact.h MainWindow/MainWindow.cpp
        MainWindow/MainWindow.h Contact/Widget/GroupeBoxContact.cpp Contact/Widget/GroupeBoxContact.cpp
        Contact/Widget/GroupeBoxContact.h Contact/Widget/ListContactWidget.cpp Contact/Widget/ListContactWidget.h
        ContactDialog/ModifContactDialog.cpp ContactDialog/ModifContactDialog.h ContactDialog/ContactDialog.cpp
        ContactDialog/ContactDialog.h Contact/StdContact.cpp Contact/StdContact.h ContactDialog/CreationContactDialog.cpp
        ContactDialog/CreationContactDialog.h Contact/StdListContact.cpp
        Contact/StdListContact.h Interaction/Interaction.cpp Interaction/Interaction.h Interaction/Widget/CreationInteractionDialog.cpp
        Interaction/Widget/CreationInteractionDialog.h Interaction/Widget/GroupBoxInteraction.cpp Interaction/Widget/GroupBoxInteraction.h
        Interaction/Widget/ListInteractionWidget.cpp Interaction/Widget/ListInteractionWidget.h BaseDeDonnees/BD.cpp
        BaseDeDonnees/BD.h Menu/MenuBar.cpp Menu/MenuBar.h Interaction/ListInteraction.cpp Interaction/ListInteraction.h
        Tache/Tache.cpp Tache/Tache.h Tache/ListTache.cpp Tache/ListTache.h Json/JsonConverter.cpp Json/JsonConverter.h
        Menu/ExportImportContacts/ExportImportMenu.cpp Menu/ExportImportContacts/ExportImportMenu.h Utility/Utility.cpp
        Utility/Utility.h ToolBar/ToolBar.cpp ToolBar/ToolBar.h ToolBar/RechercheContact/RechercheContactDialog.cpp
        ToolBar/RechercheContact/RechercheContactDialog.h Interaction/Widget/InteractionTextEdit.cpp Interaction/Widget/InteractionTextEdit.h Tache/Widget/RechercheTaches.cpp
        Tache/Widget/RechercheTaches.h Historique/ListHistorique.cpp Historique/ListHistorique.h ToolBar/RechercheTache/TreeTacheDialog.cpp ToolBar/RechercheTache/TreeTacheDialog.h)

target_link_libraries(Projet-QT
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Sql
        )


set_target_properties(Projet-QT PROPERTIES
        MACOSX_BUNDLE TRUE
        )

