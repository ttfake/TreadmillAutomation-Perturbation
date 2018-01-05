import QtQuick 2.3

Rectangle {
    id: mainRect
    width: parent.width
    height: parent.height
    color: "black"
    property string rectTxt
    rectTxt: "Please Stand Quietly"
    property string circleColor
    circleColor: "black"
    property string textColor
    textColor: "yellow"

    Rectangle {
        id: circle
        anchors { horizontalCenter: parent.horizontalCenter; top: parent.top}
        width: parent.width<parent.height?parent.width:parent.height
        height: width
        color: circleColor
        border.color: "black"
        border.width: 1
        radius: width*0.5
        Text {
            anchors { horizontalCenter: parent.horizontalCenter}
            y: 400
            color: textColor
            font.pointSize: 104 
            font.bold: true
            text: rectTxt
        }
    }

    function destroyCircle() {
        circle.destroy()
    }

}
