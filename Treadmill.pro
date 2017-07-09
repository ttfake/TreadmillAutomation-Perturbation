HEADERS = ../include/TreadmillAutomation.h \
          ../include/NetworkTabWidget.h \
          ../include/NetworkTabWidgetLights.h \
          ../include/PerturbationTabWidget.h \
          ../include/SendSetpoints.h \
          ../include/treadmill-remote.h
SOURCES = ../src/main.cpp \
          ../src/TreadmillAutomation.cpp \
          ../src/NetworkTabWidget.cpp \
          ../src/NetworkTabWidgetLights.cpp \
          ../src/PerturbationTabWidget.cpp \
          ../src/SendSetpoints.cpp 

TARGET = TreadmillAutomation

QT += core gui opengl network datavisualization widgets 

QMAKE_CXX     = /usr/local/mxe/mxe/usr/bin/x86_64-w64-mingw32.static-g++
QMAKE_LINK    = /usr/local/mxe/mxe/usr/bin/x86_64-w64-mingw32.static-g++
QMAKE_LFLAGS = -L/usr/local/mxe/mxe/usr/x86_64-w64-mingw32.static/qt5/lib/


