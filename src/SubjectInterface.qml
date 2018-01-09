import QtQuick 2.3

import QtQuick 2.3

Rectangle {
    id: mainRect
    width: parent.width
    height: parent.height
    color: "black"
    property string rectTxt
    rectTxt: "Please Stand Quietly"
    property string textColor
    textColor: "yellow"

    Text {
        anchors { horizontalCenter: parent.horizontalCenter}
        y: 400
        color: textColor
        font.pointSize: 104 
        font.bold: true
        text: rectTxt
    }

    Image {
        id: plsCircId
        width: parent.width<parent.height?parent.width:parent.height
        height: width
        anchors { horizontalCenter: parent.horizontalCenter}
        source: "images/Icons8_flat_plus.svg"
        visible: false
    }

    function hideGreenCircle(){
        console.debug("Hiding Circle")
        plsCircId.visible = false
    }

    function showGreenCircle(){
        plsCircId.visible = true
    }
}

