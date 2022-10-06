cmake_minimum_required(VERSION 3.23)
project(untitled2)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/Users/sr-71/Qt/6.3.2/macos/lib/cmake")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(untitled2 main.cpp Contact/CreateFicheWidget.cpp Contact/CreateFicheWidget.h Contact/FicheContact.cpp Contact/FicheContact.h MainWindow/MainWindow.cpp MainWindow/MainWindow.h MdificationContact/WidgetContact.cpp MdificationContact/WidgetContact.cpp MdificationContact/WidgetContact.h MdificationContact/ModificationWidget.cpp MdificationContact/ModificationWidget.h)
target_link_libraries(untitled2
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

