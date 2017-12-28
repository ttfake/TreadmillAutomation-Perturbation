import QtQuick 2.0

Item {
    id: main
    width: 600
    height: 400
    
    ControlPanel {
        id: controlPanel
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.leftMargin: 5
    
        onSignalSourceChanged: {
            if (source == "sin")
                dataSource.generateData(0, signalCount, sampleCount);
            else
                dataSource.generateData(1, signalCount, sampleCount);
            scopeView.axisX().max = sampleCount;
        }
        onSeriesTypeChanged: scopeView.changeSeriesType(type);
        onRefreshRateChanged: scopeView.changeRefreshRate(rate);
        onAntialiasingEnabled: scopeView.antialiasing = enabled;
        onOpenGlChanged: {
            scopeView.openGL = enabled;
        }
    }

    ScopeView {
        id: scopeView
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.left: controlPanel.right
        anchors.right:parent.right
        height: main.height
        anchors.topMargin: 40
        anchors.bottomMargin: 40
        anchors.leftMargin: 40

        onOpenGLSupportedChanged: {
            if (!openGLSupported) {
                controlPanel.openGLButton.enabled = false
                controlPanel.openGLButton.currentSelection = 0
            }
        }

    }
}
