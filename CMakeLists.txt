cmake_minimum_required(VERSION 3.23)
project(Projet-QT)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/Users/sr-71/Qt/6.4.0/macos/lib/cmake")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Sql
        REQUIRED)

add_executable(Projet-QT main.cpp Contact/QtContact.cpp Contact/QtContact.h MainWindow/MainWindow.cpp MainWindow/MainWindow.h ModificationContact/GroupeBoxContact.cpp ModificationContact/GroupeBoxContact.cpp ModificationContact/GroupeBoxContact.h ModificationContact/ModificationDialog.cpp ModificationContact/ModificationDialog.h ModificationContact/ModifContactDialog.cpp ModificationContact/ModifContactDialog.h ContactDialog/ContactDialog.cpp ContactDialog/ContactDialog.h Contact/StdContact.cpp Contact/StdContact.h CreationContact/CreationContactDialog.cpp CreationContact/CreationContactDialog.h Contact/TraductionQtStd.cpp Contact/TraductionQtStd.h Contact/StdListContact.cpp Contact/StdListContact.h Interaction/Interaction.cpp Interaction/Interaction.h Interaction/CreationInteractionDialog.cpp Interaction/CreationInteractionDialog.h Interaction/InteractionGroupBox.cpp Interaction/InteractionGroupBox.h Interaction/ListInteractionDialog.cpp Interaction/ListInteractionDialog.h BaseDeDonne/BD.cpp BaseDeDonne/BD.h)
target_link_libraries(Projet-QT
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Sql
        )

set_target_properties(Projet-QT PROPERTIES
        MACOSX_BUNDLE TRUE
        )

