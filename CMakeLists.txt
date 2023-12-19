cmake_minimum_required(VERSION 3.24)
project(Egram)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "C:/Qt/6.6.0/mingw_64")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        WebSockets
        Sql
        REQUIRED)


set(SOURCES src/chatbannerwidget.cpp src/chatmessagewidget.cpp src/ContactItem.cpp src/ContactList.cpp src/MainWindow.cpp src/ChatWidget.cpp src/Chat.cpp)
set(HEADERS headers/chatbannerwidget.h headers/chatmessagewidget.h headers/ContactItem.h headers/ContactList.h headers/MainWindow.h headers/ChatWidget.h headers/Chat.h src/DatabaseManager.cpp headers/DatabaseManager.h)

add_executable(Egram main.cpp ${SOURCES} ${HEADERS})

target_link_libraries(Egram
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::WebSockets
        Qt::Sql
        )

if (WIN32)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()

