cmake_minimum_required(VERSION 3.23)
project(untitled2)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/home/rahman/Qt/6.4.0/gcc_64/lib/cmake")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(untitled2 main.cpp Contact/QtFicheContact.cpp Contact/QtFicheContact.h MainWindow/MainWindow.cpp MainWindow/MainWindow.h ModificationContact/GroupeBoxContact.cpp ModificationContact/GroupeBoxContact.cpp ModificationContact/GroupeBoxContact.h ModificationContact/ModificationDialog.cpp ModificationContact/ModificationDialog.h ModificationContact/ModifContactDialog.cpp ModificationContact/ModifContactDialog.h FicheContactDialog/FicheContactDialog.cpp FicheContactDialog/FicheContactDialog.h Contact/StdFicheContact.cpp Contact/StdFicheContact.h CreationContact/CreationContactDialog.cpp CreationContact/CreationContactDialog.h Contact/TraductionQtStd.cpp Contact/TraductionQtStd.h)
target_link_libraries(untitled2
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

