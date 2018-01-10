#!/bin/bash

rm -R CMakeFiles/ CMakeCache.txt TreadmillAutomation_automoc.* Makefile moc_TreadmillAutomation.cpp_parameters moc_* ../include/moc_*
cmake -G "MSYS Makefiles" ..
make
cp ../bin/TreadmillAutomation.exe /home/user/TreadmillAutomationBinaryTestbed/
cp ../src/main.qml /home/user/TreadmillAutomationBinaryTestbed/
cp ../src/NewButton.qml /home/user/TreadmillAutomationBinaryTestbed/
cp ../src/SubjectInterface.qml /home/user/TreadmillAutomationBinaryTestbed/
cp ../src/MainSubjectInterface.qml /home/user/TreadmillAutomationBinaryTestbed/
cp ../bin/TreadmillAutomation.exe /home/user/HReflex_Windows/bin/
cp ../src/ChannelPanel.qml /home/user/TreadmillAutomationBinaryTestbed/
cp ../src/ChannelPanel.qml /home/user/HReflex_Windows/bin/ 
cp ../src/InstrumentationPanel.qml /home/user/TreadmillAutomationBinaryTestbed/
cp ../src/InstrumentationPanel.qml /home/user/HReflex_Windows/bin/
cp ../src/MultiButton.qml /home/user/TreadmillAutomationBinaryTestbed/
cp ../src/MultiButton.qml /home/user/HReflex_Windows/bin/
cp ../src/ScopeView.qml /home/user/TreadmillAutomationBinaryTestbed/
cp ../src/ScopeView.qml /home/user/HReflex_Windows/bin/
cp ../src/SubjectInterface.qml /home/user/TreadmillAutomationBinaryTestbed/
cp ../src/SubjectInterface.qml /home/user/HReflex_Windows/bin/
cp ../src/ColorRectangle.qml /home/user/TreadmillAutomationBinaryTestbed/
cp ../src/ColorRectangle.qml /home/user/HReflex_Windows/bin/
cp ../src/MainInstrumentationPanel.qml /home/user/TreadmillAutomationBinaryTestbed/
cp ../src/MainInstrumentationPanel.qml /home/user/HReflex_Windows/bin/
cp ../src/NewButton.qml /home/user/TreadmillAutomationBinaryTestbed/
cp ../src/NewButton.qml /home/user/HReflex_Windows/bin/
cp ../src/Smiley.qml /home/user/TreadmillAutomationBinaryTestbed/
cp ../src/Smiley.qml /home/user/HReflex_Windows/bin/
cp ../src/main.qml /home/user/TreadmillAutomationBinaryTestbed/
cp ../src/main.qml /home/user/HReflex_Windows/bin/
cp ../src/ControlPanel.qml /home/user/TreadmillAutomationBinaryTestbed/
cp ../src/ControlPanel.qml /home/user/HReflex_Windows/bin/
cp ../src/MainSubjectInterface.qml /home/user/TreadmillAutomationBinaryTestbed/   
cp ../src/MainSubjectInterface.qml /home/user/HReflex_Windows/bin/
cp ../src/QmlInterface.qml /home/user/TreadmillAutomationBinaryTestbed/ 
cp ../src/QmlInterface.qml /home/user/HReflex_Windows/bin/
cp ../src/SmileyGone.qml /home/user/HReflex_Windows/bin/
cp ../src/SmileyGone.qml /home/user/TreadmillAutomationBinaryTestbed/

tar czvf /home/user/HReflex_Windows/bin/latest_qml.tar.gz /home/user/HReflex_Windows/bin/*.qml 
