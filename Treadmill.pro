HEADERS = include/TreadmillAutomation.h
SOURCES = src/main.cpp \
          src/TreadmillAutomation.cpp
TARGET = TreadmillAutomation

QT += core gui opengl network datavisualization widgets 

QMAKE_CXX     = /usr/local/mxe/mxe/usr/bin/x86_64-w64-mingw32.static-g++
QMAKE_LINK    = /usr/local/mxe/mxe/usr/bin/x86_64-w64-mingw32.static-g++
QMAKE_LFLAGS = -L/usr/local/mxe/mxe/usr/x86_64-w64-mingw32.static/qt5/lib/


