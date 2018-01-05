import QtQuick 2.3
import QtQuick.Controls 1.4

Item {
    id: mainsubjiface
    width: 1950
    height: 960

    SubjectInterface {
        id: sIface
    }

    Loader { id: smileyLoader }

    function updateTextField(text){
        console.debug("setTextField: " + text)
        sIface.rectTxt = text
    }

    function updateCircleColor(color){
        sIface.circleColor = color
    }

    function updateCircleToSmiley(){
        console.debug("smiley")
        sIface.circleColor = "black"
        smileyLoader.source = "Smiley.qml"
    }

    function deleteSmileyFace() {
        smileyLoader.source = "SmileyGone.qml"
} 
