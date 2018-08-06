import QtQuick 2.0

Item {
    id: main
    width: 600
    height: 200
    
    Channel8ScopeView {
        id: channel8scopeView
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.left: parent.left 
        anchors.right:parent.right
        height: main.height
    }
}
