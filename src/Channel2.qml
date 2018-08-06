import QtQuick 2.0

Item {
    id: main
    width: 600
    height: 200
    
    Channel2ScopeView {
        id: channel2ScopeView
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.right:parent.right
        anchors.left:parent.left
        height: main.height
    }
}
