cmake_minimum_required(VERSION 3.17)
project(MorseTranslate LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Quick Widgets REQUIRED)

set(GUI_SOURCES gui/qml.qrc src/backend.cpp include/backend.h)
set(LOGIC_SOURCES src/config.cpp src/code.cpp)
set(SOURCES src/main.cpp ${LOGIC_SOURCES} ${GUI_SOURCES})

set(QT5_LIBS Qt5::Quick Qt5::Widgets)

add_executable(MorseTranslate ${SOURCES})
target_include_directories(MorseTranslate PUBLIC include)
target_link_libraries(MorseTranslate ${QT5_LIBS})

if(BUILD_TESTING)
    enable_testing()
    add_subdirectory(tests)
endif()
