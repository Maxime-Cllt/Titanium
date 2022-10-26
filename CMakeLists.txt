cmake_minimum_required(VERSION 3.23)
project(Projet-QT)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/home/rahman/Qt/6.4.0/gcc_64/lib/cmake/")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Sql
        REQUIRED)

add_executable(Projet-QT main.cpp Contact/QtContact.cpp Contact/QtContact.h MainWindow/MainWindow.cpp MainWindow/MainWindow.h ListContactWidget/GroupeBoxContact.cpp ListContactWidget/GroupeBoxContact.cpp ListContactWidget/GroupeBoxContact.h ListContactWidget/ListContactWidget.cpp ListContactWidget/ListContactWidget.h ContactDialog/ModifContactDialog.cpp ContactDialog/ModifContactDialog.h ContactDialog/ContactDialog.cpp ContactDialog/ContactDialog.h Contact/StdContact.cpp Contact/StdContact.h ContactDialog/CreationContactDialog.cpp ContactDialog/CreationContactDialog.h Contact/TraductionQtStd.cpp Contact/TraductionQtStd.h Contact/StdListContact.cpp Contact/StdListContact.h Interaction/Interaction.cpp Interaction/Interaction.h Interaction/CreationInteractionDialog.cpp Interaction/CreationInteractionDialog.h Interaction/GroupBoxInteraction.cpp Interaction/GroupBoxInteraction.h Interaction/ListInteractionWidget.cpp Interaction/ListInteractionWidget.h BaseDeDonne/BD.cpp BaseDeDonne/BD.h Modification/Modification.cpp Modification/Modification.h Modification/ListModification.cpp Modification/ListModification.h Menu/MenuBar.cpp Menu/MenuBar.h Interaction/ListInteraction.cpp Interaction/ListInteraction.h Tache/Tache.cpp Tache/Tache.h Tache/ListTache.cpp Tache/ListTache.h Menu/RechercheContact/RechercheContactDialog.cpp Menu/RechercheContact/RechercheContactDialog.h)
target_link_libraries(Projet-QT
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Sql
        )

set_target_properties(Projet-QT PROPERTIES
        MACOSX_BUNDLE TRUE
        )

