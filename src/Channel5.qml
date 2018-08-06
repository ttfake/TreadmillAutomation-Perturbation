import QtQuick 2.0

Item {
    id: main
    width: 600
    height: 200
    
    Channel5ScopeView {
        id: channel5scopeView
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.left: parent.left 
        anchors.right:parent.right
        height: 200 
    }
}
