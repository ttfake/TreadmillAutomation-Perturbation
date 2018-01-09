import QtQuick 2.3
import QtQuick.Controls 1.4

Item {
    id: mainsubjiface
    width: 1950
    height: 1460

    SubjectInterface {
        id: sIface
        rectTxt: "Please Stand Quietly"
    }

    Smiley {
        id: smiley
        visible: false
    }

    
    function updateTextField(text){
        console.debug("setTextField: " + text)
        sIface.rectTxt = text
    }

    function showGreenCircle(){
        sIface.showGreenCircle()
    }

    function hideGreenCircle(){
        sIface.hideGreenCircle()
    }

    function updateCircleToSmiley(){
        sIface.circleColor = "black"
        showSmileyFace()
    }
    
    function hideSmileyFace() {
        smiley.visible = false
    }

    function showSmileyFace() {
        smiley.visible = true
    }
} 
