cmake_minimum_required(VERSION 3.8)
project(OscilloScope)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_PREFIX_PATH "C:\\Qt\\Qt5.8.0\\5.8\\mingw53_32\\lib\\cmake")
set(CMAKE_AUTOMOC ON)

set(SOURCE_FILES main.cpp mainwindow.cpp mainwindow.h deviceAccessPage.cpp deviceAccessPage.h importFilePage.cpp importFilePage.h)
add_executable(OscilloScope ${SOURCE_FILES})

set(CMAKE_PREFIX_PATH "C:\\Qt\\Qt5.8.0\\5.8\\mingw53_32\\lib\\cmake")
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)
qt5_use_modules(OscilloScope Core Widgets Gui SerialPort)