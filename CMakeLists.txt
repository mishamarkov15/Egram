cmake_minimum_required(VERSION 3.24)
project(Egram)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        WebSockets
        Sql
        REQUIRED)

add_executable(Egram main.cpp src/MainWindow.cpp headers/MainWindow.h)
target_link_libraries(Egram
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::WebSockets
        Qt::Sql
        )

