cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project(RTClientSDK)

SET (CMAKE_AUTOMOC ON)

SET (WINDOWS_QT
    /home/tim/projects/crossCompileWindowsLibraries/qt/5.9/msvc2015_64/)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include/RTClientSDK/)
link_directories(${LINK_DIRECTORIES} ${CMAKE_BINARY_DIR}/../lib
    /usr/local/mxe/mxe/usr/x86_64-w64-mingw32.shared/qt5/lib)
SET (CMAKE_INCLUDE_CURRENT_DIR ON)
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
SET(CMAKE_BUILD_TYPE Release)

SET(GCC_COVERAGE_COMPILE_FLAGS "-shared ")

file(GLOB SOURCES "*.cpp")

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Network REQUIRED)

add_library(RTClientSDK RTProtocol.cpp Network.cpp Markup.cpp RTPacket.cpp)
target_link_libraries(RTClientSDK Qt5::Widgets Qt5::Network
    ws2_32
    )
