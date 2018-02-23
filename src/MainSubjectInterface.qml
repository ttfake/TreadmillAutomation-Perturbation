import QtQuick 2.3
import QtQuick.Controls 1.4

Item {
    id: mainsubjiface
    width: 1920
    height: 1080

    SubjectInterface {
        id: sIface
        rectTxt: ""
    }

    Smiley {
        id: smiley
        visible: false
    }
    
    function updateTextField(text){
        console.debug("setTextField: " + text)
        sIface.rectTxt = text
    }

    function setTextColor(color)
    {
        sIface.textColor = color
    }

    function showGreenCircle(){
        sIface.showGreenCircle()
    }

    function hideGreenCircle(){
        sIface.hideGreenCircle()
    }

    function showRedCircle(){
        sIface.showRedCircle()
    }

    function hideRedCircle(){
        sIface.hideRedCircle()
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
