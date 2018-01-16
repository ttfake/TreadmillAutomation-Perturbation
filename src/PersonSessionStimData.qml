import QtQuick 2.3
import QtQuick.Controls 1.4
import QtGraphicalEffects 1.0
import QtQuick.Layouts 1.3
import QtQuick.Controls.Styles 1.4

Item {
    id: mainStimIface
    width: 950
    height: 750
    property double currentValue
    currentValue: 0.0
    property double step
    step: 0.25
    property double currentStep
    currentStep: spinbox.value
    property string subjectId
    property string sessionId

    function incrementCurrent()
    {
        currentValue += (currentStep * 10)
    }
    function decrementCurrent()
    {
        currentValue -= (currentStep * 10)
    }
    function setSubjectId(subject)
    {
        subjectId: subject
    }
    function setSessionId(session)
    {
        sessionId: session
    }
    function getCurrent()
    {
        return currentValue
    }
   
    Rectangle {
        id: stimControlPanel
        width: 950 
        height: 750
        color: "black"

        GridLayout {
            id: grid
            columns: 3
            
            Text { id: personIdLabel; text: "Subject ID: "; 
                   font.bold: true; 
                   color: "white"; 
                   font.pointSize: 25; 
                   Layout.row: 0;
                   Layout.column: 0; 
                 }
            Text { id: personIdValue;
                   text: subjectId
                   color: "white"
                   font.pointSize: 25;
                   Layout.row: 0;
                   Layout.column: 1;
            }
            Text { id: sessionId; 
                   text: "Session ID: "; 
                   font.bold: true;
                   color: "white"; 
                   font.pointSize: 25;
                   Layout.row: 1;
                   Layout.column: 0; 
                 }
            Text { id: stimCurrentLevel;
                   text: "Stimulation Current: "
                   font.bold: true;
                   color: "white";
                   font.pointSize: 25;
                   Layout.row: 2;
                   Layout.column: 0;
                   Layout.rowSpan: 2;
            }

            TextField {
                   property string currentPlaceholderText
                   id: currentTextField;
                   currentPlaceholderText: (currentValue/10).toLocaleString(Qt.locale("en_US"));
                   placeholderText: currentPlaceholderText;
                   readOnly: true;
                   Layout.row: 2;
                   Layout.column: 1;
                   font.pointSize: 25;
                   Layout.rowSpan: 2;
                   horizontalAlignment: Text.AlignHCenter
                   style: TextFieldStyle {
                          background: Rectangle {
                              implicitWidth: 150
                              implicitHeight: 50
                              border.color: "gray"
                              color: "gray"
                              radius: 2
                          }
                      }
            }

            Button {
                id: stimUpButton;
                Layout.row: 2;
                Layout.column: 2
                height: 15 

                style: ButtonStyle {
                    label: Component {
                        Text {
                            id: up
                            text: "Up"
                            clip: true
                            wrapMode: Text.WordWrap
                            verticalAlignment: Text.AlignVCenter
                            horizontalAlignment: Text.AlignHCenter
                            anchors.fill: parent
                            font.pointSize: 10;
                            font.bold: true
                        }
                    }
                }
                onClicked: incrementCurrent()
            }

            Button {
                id: stimDownButton;
                Layout.row: 3;
                Layout.column: 2
                height: 15

                style: ButtonStyle {
                    label: Component {
                        Text {
                            id: down
                            text: "Down"
                            clip: true
                            wrapMode: Text.WordWrap
                            verticalAlignment: Text.AlignVCenter
                            horizontalAlignment: Text.AlignHCenter
                            anchors.fill: parent
                            font.pointSize: 10;
                            font.bold: true
                        }
                    }
                }
                onClicked: decrementCurrent()
            }

            Text { id: stimStepSize;
                   text: "Stimulation Step Size: ";
                   font.bold: true;
                   color: "white";
                   font.pointSize: 25;
                   Layout.row: 4;
                   Layout.column: 0;
            }

            SpinBox { id: spinbox
                      Layout.row: 4;
                      Layout.column: 1;
                      font.pointSize: 25;
                      horizontalAlignment: Text.AlignHCenter;
                      decimals: 2;
                      stepSize: step;
                      value: currentStep;
                      style: SpinBoxStyle {
                          textColor: "#656363"
                          background: Rectangle {
                              implicitWidth: 150
                              implicitHeight: 50
                              border.color: "gray"
                              color: "gray"
                              radius: 2
                          }
                      }
            }
            Glow {
                anchors.fill: stimUpButton.up
                radius: 18
                samples: 37
                color: "#15bdff"
                source: stimUpButton.up
            }
            

        }
    }
}
