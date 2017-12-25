#!/bin/bash

rm -R CMakeFiles/ CMakeCache.txt TreadmillAutomation_automoc.* Makefile moc_TreadmillAutomation.cpp_parameters moc_* ../include/moc_*
cmake -G "MSYS Makefiles" ..
make
cp ../bin/TreadmillAutomation.exe /home/user/TreadmillAutomationBinaryTestbed/
cp ../src/main.qml /home/user/TreadmillAutomationBinaryTestbed/
cp ../src/NewButton.qml /home/user/TreadmillAutomationBinaryTestbed/
cp ../bin/TreadmillAutomation.exe /home/user/HReflex_Windows/bin/
