import QtQuick 2.3

Item {
    id: smiface
    width: 1950
    height: 900

    Image {
        id: smileyId
        width: parent.width<parent.height?parent.width:parent.height
        height: width
        anchors { horizontalCenter: parent.horizontalCenter}
        source: "images/smiley.jpg"
    }
}

