import QtQuick 2.1
import QtQuick.Layouts 1.0

ColumnLayout {
    property alias channel1: channel1 
    spacing: 8
    Layout.fillHeight: true
    signal animationsEnabled(bool enabled)
    signal seriesTypeChanged(string type)
    signal refreshRateChanged(variant rate);
    signal signalSourceChanged(string source, int signalCount, int sampleCount);
    signal antialiasingEnabled(bool enabled)
    signal openGlChanged(bool enabled)

    Text {
        text: "Scope"
        font.pointSize: 18
        color: "white"
    }

    MultiButton {
        id: channel1 
        text: "Channel "
        currentSelection: 1
        onSelectionChanged: openGlChanged(currentSelection == 1);
    }

    MultiButton {
        id: channel2 
        text: "Channel 2"
        currentSelection: 1
        onSelectionChanged: openGlChanged(currentSelection == 1);
    }

    MultiButton {
        id: channel3 
        text: "Channel 3"
        currentSelection: 1
        onSelectionChanged: openGlChanged(currentSelection == 1);
    }

    MultiButton {
        id: channel4 
        text: "Channel 4"
        currentSelection: 1
        onSelectionChanged: openGlChanged(currentSelection == 1);
    }
    
    MultiButton {
        id: channel5 
        text: "Channel 5"
        currentSelection: 1
        onSelectionChanged: openGlChanged(currentSelection == 1);
    }

    MultiButton {
        id: channel6 
        text: "Channel 6"
        currentSelection: 1
        onSelectionChanged: openGlChanged(currentSelection == 1);
    }

    MultiButton {
        id: channel7 
        text: "Channel 7"
        currentSelection: 1
        onSelectionChanged: openGlChanged(currentSelection == 1);
    }

    MultiButton {
        id: channel8 
        text: "Channel 8"
        currentSelection: 1
        onSelectionChanged: openGlChanged(currentSelection == 1);
    }
}
