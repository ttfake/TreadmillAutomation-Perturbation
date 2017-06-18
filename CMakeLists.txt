cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project(TreadmillAutomation)

set (WINDOWS_QT
    /home/tim/projects/crossCompileWindowsLibraries/qt/5.9/msvc2015_64/)

include_directories(include ${WINDOWS_QT})
set (CMAKE_INCLUDE_CURRENT_DIR ON)
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../lib)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../lib)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)
set (CMAKE_AUTOMOC ON)
file(GLOB SOURCES "src/*.cpp")

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Network REQUIRED)
find_package(Qt5DataVisualization REQUIRED)


qt5_wrap_cpp(moc_TreadmillAutomation.cpp TreadmillAutomation.cpp
    TreadmillAutomation.h)


add_executable(TreadmillAutomation ${SOURCES})
target_link_libraries(TreadmillAutomation Qt5::Widgets Qt5::Network
    Qt5::DataVisualization)
