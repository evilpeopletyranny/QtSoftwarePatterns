cmake_minimum_required(VERSION 3.5)

project(QtSoftwarePatterns VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        shapes/myshape.cpp
        shapes/myshape.h
        shapes/shapecreator.cpp
        shapes/shapecreator.h
        shapes/shapecreatormultiton.cpp
        shapes/shapecreatormultiton.h
        shapes/chain/eventhandler.cpp
        shapes/chain/eventhandler.h
        shapes/chain/wheeleventhandler.cpp
        shapes/chain/wheeleventhandler.h
        shapes/chain/wheelshifteventhandler.cpp
        shapes/chain/wheelshifteventhandler.h
        shapes/rectangles/rectangle.cpp
        shapes/rectangles/rectangle.h
        shapes/rectangles/rectanglecreator.cpp
        shapes/rectangles/rectanglecreator.h
        shapes/circles/circle.cpp
        shapes/circles/circle.h
        shapes/circles/circlecreator.cpp
        shapes/circles/circlecreator.h
        shapes/triangles/triangle.cpp
        shapes/triangles/triangle.h
        shapes/triangles/trianglecreator.cpp
        shapes/triangles/trianglecreator.h
        shapes/groups/group.cpp
        shapes/groups/group.h
        commands/shapecommand.cpp
        commands/shapecommand.h
        widgets/shapemediatorwidget.cpp
        widgets/shapemediatorwidget.h
        widgets/shapeeditorwidget.cpp
        widgets/shapeeditorwidget.h
        widgets/shapebutton.cpp
        widgets/shapebutton.h
        widgets/shapeviewwidget.cpp
        widgets/shapeviewwidget.h
        widgets/shapescenewidget.cpp
        widgets/shapescenewidget.h
        dialogs/windowmanager.cpp
        dialogs/windowmanager.h
        form.cpp
        form.h
        form.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(QtSoftwarePatterns
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET QtSoftwarePatterns APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(QtSoftwarePatterns SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(QtSoftwarePatterns
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(QtSoftwarePatterns PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(QtSoftwarePatterns PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(QtSoftwarePatterns)
endif()
