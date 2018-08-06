import QtQuick 2.0

Item {
    id: main
    width: 600
    height: 200
    
    Channel1ScopeView {
        id: channel1scopeView
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.right:parent.right
        anchors.left:parent.left
        height: 200 
    }
}
