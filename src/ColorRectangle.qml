import QtQuick 2.3

Rectangle {
    width: 200
    height: 100
    color: "red"
    signal submitTextField(string text)

    property string rectTxt
    rectTxt: "Hello, World"
    
    Text {
        anchors.centerIn: parent
        text: rectTxt
    }

    function onSubmitTextField(text){
        console.log("setTextField: " + text)
        rectTxt: text
    }
}
