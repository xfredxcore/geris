# CMakeLists.txt
cmake_minimum_required(VERSION 3.16)
project(geris LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick Widgets)

qt_add_executable(geris_app
    src/main.cpp
    src/fileio.h
)

qt_add_qml_module(geris_app
    URI geris
    VERSION 1.0
    RESOURCE_PREFIX "/res"
    QML_FILES
        src/qml/main.qml
)

target_link_libraries(geris_app PRIVATE Qt6::Core Qt6::Gui Qt6::Qml Qt6::Quick Qt6::Widgets)