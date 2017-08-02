cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project(TreadmillAutomation)

set (CMAKE_AUTOMOC ON)

set (WINDOWS_QT
    /home/tim/projects/crossCompileWindowsLibraries/qt/5.9/msvc2015_64/)

include_directories(include ${WINDOWS_QT})
link_directories(${LINK_DIRECTORIES} ${CMAKE_BINARY_DIR}/../lib
    /usr/local/mxe/mxe/usr/x86_64-w64-mingw32.shared/qt5/lib)
set (CMAKE_INCLUDE_CURRENT_DIR ON)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)
SET(GCC_COVERAGE_COMPILE_FLAGS "-gstabs")

file(GLOB SOURCES "src/*.cpp")

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Network REQUIRED)

#qt5_wrap_cpp(moc_TreadmillAutomation.cpp moc_MccDaqInterface.cpp 
#    moc_NetworkTabWidget.cpp moc_PerturbationTabWidget.cpp TreadmillAutomation.cpp
#    TreadmillAutomation.h MccDaqInterface.cpp MccDaqInterface.h
#    NetworkTabWidget.cpp NetworkTabWidget.h PerturbationTabWidget.cpp
#    PerturbationTabWidget.h SendSetpoints.cpp SendSetpoints.h)

add_executable(TreadmillAutomation ${SOURCES})
target_link_libraries(TreadmillAutomation Qt5::Widgets Qt5::Network
    cbw64
    )
