cmake_minimum_required(VERSION 3.23)
project(Titanium VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS
    Core
    Gui
    Widgets
    Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS
    Core
    Gui
    Widgets
    Sql)


set(SRC
        src/main.cpp src/Contact/QtContact.cpp src/Contact/QtContact.h src/MainWindow/MainWindow.cpp
        src/MainWindow/MainWindow.h src/Contact/Widget/GroupeBoxContact.cpp src/Contact/Widget/GroupeBoxContact.cpp
        src/Contact/Widget/GroupeBoxContact.h src/Contact/Widget/ListContactWidget.cpp src/Contact/Widget/ListContactWidget.h
        src/ContactDialog/ModifContactDialog.cpp src/ContactDialog/ModifContactDialog.h src/ContactDialog/ContactDialog.cpp
        src/ContactDialog/ContactDialog.h src/Contact/StdContact.cpp src/Contact/StdContact.h src/ContactDialog/CreationContactDialog.cpp
        src/ContactDialog/CreationContactDialog.h src/Contact/StdListContact.cpp
        src/Contact/StdListContact.h src/Interaction/Interaction.cpp src/Interaction/Interaction.h src/Interaction/Widget/CreationInteractionDialog.cpp
        src/Interaction/Widget/CreationInteractionDialog.h src/Interaction/Widget/GroupBoxInteraction.cpp src/Interaction/Widget/GroupBoxInteraction.h
        src/Interaction/Widget/ListInteractionWidget.cpp src/Interaction/Widget/ListInteractionWidget.h src/BaseDeDonnees/BD.cpp
        src/BaseDeDonnees/BD.h src/Menu/MenuBar.cpp src/Menu/MenuBar.h src/Interaction/ListInteraction.cpp src/Interaction/ListInteraction.h
        src/Tache/Tache.cpp src/Tache/Tache.h src/Tache/ListTache.cpp src/Tache/ListTache.h src/Json/JsonConverter.cpp src/Json/JsonConverter.h
        src/Menu/ExportImportContacts/ExportImportMenu.cpp src/Menu/ExportImportContacts/ExportImportMenu.h src/Utility/Utility.cpp
        src/Utility/Utility.h src/ToolBar/ToolBar.cpp src/ToolBar/ToolBar.h src/ToolBar/RechercheContact/RechercheContactDialog.cpp
        src/ToolBar/RechercheContact/RechercheContactDialog.h src/Interaction/Widget/InteractionTextEdit.cpp src/Interaction/Widget/InteractionTextEdit.h src/Tache/Widget/RechercheTaches.cpp
        src/Tache/Widget/RechercheTaches.h src/Historique/ListHistorique.cpp src/Historique/ListHistorique.h
        src/ToolBar/RechercheTache/TreeTacheDialog.cpp src/ToolBar/RechercheTache/TreeTacheDialog.h
        src/ToolBar/Suppression/SuppressionDialog.cpp src/ToolBar/Suppression/SuppressionDialog.h
        src/ToolBar/Suppression/TreeWidget.cpp src/ToolBar/Suppression/TreeWidget.h)

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(MACOSX_BUNDLE_ICON_FILE app.icns)
    set(myApp_ICON images/app.icns)
    set_source_files_properties(${myApp_ICON} PROPERTIES
            MACOSX_PACKAGE_LOCATION "Resources")
    add_executable(Titanium MACOSX_BUNDLE application.qrc ${myApp_ICON} ${SRC})
elseif (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    enable_language("RC")
    set(WIN32_ICO ${CMAKE_CURRENT_SOURCE_DIR}/MyApp.rc)
    add_executable(Titanium WIN32 application.qrc ${WIN32_ICO} ${IMAGES} ${SRC})
else ()
    add_executable(Titanium application.qrc ${IMAGES} ${SRC})
endif ()


target_link_libraries(Titanium PRIVATE
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Sql
        )

