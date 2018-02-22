import QtQuick 2.3
import QtQuick.Controls 1.4
import QtGraphicalEffects 1.0
import QtQuick.Layouts 1.3
import QtQuick.Controls.Styles 1.4
import QtQuick.Window 2.2

Item {
    id: mainStimIface
    width: 950
    height: 750
    property double leftCurrentValue
    leftCurrentValue: 0.0
    property double rightCurrentValue
    rightCurrentValue: 0.0
    property double step
    step: 0.25
    property double currentStep
    currentStep: spinbox.value
    property string subjectId
    subjectId: "test"
    property string sessionId
    property string leftStimUpButtonColor
    leftStimUpButtonColor: "grey"

    signal changeCurrent()
    signal changeSubjectId()
    
    
    function incrementLeftCurrent()
    {
        leftCurrentValue += (currentStep * 10)
        setLeftStimButtonColor()
    }
    function decrementLeftCurrent()
    {
        leftCurrentValue -= (currentStep * 10)
    }
    function incrementRightCurrent()
    {
        rightCurrentValue += (currentStep * 10)
    }
    function decrementRightCurrent()
    {
        rightCurrentValue -= (currentStep * 10)
    }
    function setSubjectId(subject)
    {
        console.debug(subject)
        subjectId = subject
    }
    function setSessionId(session)
    {
        sessionId = session
    }
    function getLeftCurrent()
    {
        return leftCurrentValue
    }
    function getRightCurrent()
    {
        return rightCurrentValue
    }
    function setLeftStimButtonColor()
    {
        leftStimUpButtonColor: "blue"
    }
   
    Rectangle {
        id: stimControlPanel
        width: 950 
        height: 750
        color: "black"

        GridLayout {
            id: grid
            columns: 3
            
            Text { id: personIdLabel; 
                   text: "Subject ID: "; 
                   font.bold: true; 
                   color: "white"; 
                   font.pointSize: 25; 
                   Layout.row: 0;
                   Layout.column: 0; 
                 }
            TextField { id: personIdValue;
                        font.pointSize: 25;
                        Layout.row: 0;
                        Layout.column: 1;
                        Layout.rowSpan: 1;
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
                      text: subjectId
            }
            Button {
                id: personIdChangeButton;
                Layout.row: 0;
                Layout.column: 2
                height: 15 
                style: ButtonStyle {
                    background: Rectangle {
                        implicitWidth: 100
                        implicitHeight: 25
                        border.width: control.activeFocus ? 2 : 1
                        border.color: "#888"
                        radius: 4
                        gradient: Gradient {
                            GradientStop { position: 0 ; color: control.pressed ? "#ccc" : "#eee" }
                            GradientStop { position: 1 ; color: control.pressed ? "#aaa" : "#ccc" }
                        }
                    }

                    label: Component {
                        Text {
                            id: personIdChange
                            text: "Change"
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
                onClicked: changeSubjectId()
            }

            Text { id: sessionIdLabel; 
                   text: "Session ID: "; 
                   font.bold: true;
                   color: "white"; 
                   font.pointSize: 25;
                   Layout.row: 1;
                   Layout.column: 0; 
                 }
            TextField { id: sessionIdValue;
                        font.pointSize: 25;
                        Layout.row: 1;
                        Layout.column: 1;
                        Layout.rowSpan: 1;
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
                        placeholderText: sessionId
            }
 
            Text { id: leftStimCurrentLevel;
                   text: "Left Stimulation Current: "
                   font.bold: true;
                   color: "white";
                   font.pointSize: 25;
                   Layout.row: 2;
                   Layout.column: 0;
                   Layout.rowSpan: 2;
            }

            TextField {
                   id: leftCurrentField;
                   property string leftCurrentPlaceholderText
                   property string units
                   units: "mA"
                   leftCurrentPlaceholderText: (leftCurrentValue/10).toLocaleString(Qt.locale("en_US")) + units;
                   placeholderText: leftCurrentPlaceholderText;
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
            Text { id: rightStimCurrentLevel;
                   text: "Right Stimulation Current: "
                   font.bold: true;
                   color: "white";
                   font.pointSize: 25;
                   Layout.row: 4;
                   Layout.column: 0;
                   Layout.rowSpan: 2;
            }

            TextField {
                   id: rightCurrentTextField;
                   property string rightCurrentPlaceholderText
                   property string units
                   units: "mA"
                   rightCurrentPlaceholderText: (rightCurrentValue/10).toLocaleString(Qt.locale("en_US")) + units;
                   placeholderText: rightCurrentPlaceholderText;
                   readOnly: true;
                   Layout.row: 4;
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
                id: leftStimUpButton;
                Layout.row: 2;
                Layout.column: 2
                height: 15 
                style: ButtonStyle {
                    background: Rectangle {
                        implicitWidth: 100
                        implicitHeight: 25
                        border.width: control.activeFocus ? 2 : 1
                        border.color: "#888"
                        radius: 4
                        gradient: Gradient {
                            GradientStop { position: 0 ; color: control.pressed ? "#ccc" : "#eee" }
                            GradientStop { position: 1 ; color: control.pressed ? "#aaa" : "#ccc" }
                        }
                    }

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
                onClicked: incrementLeftCurrent()
            }

            Button {
                id: leftStimDownButton;
                Layout.row: 3;
                Layout.column: 2
                height: 15

                style: ButtonStyle {
                    background: Rectangle {
                        implicitWidth: 100
                        implicitHeight: 25
                        border.width: control.activeFocus ? 2 : 1
                        border.color: "#888"
                        radius: 4
                        gradient: Gradient {
                            GradientStop { position: 0 ; color: control.pressed ? "#ccc" : "#eee" }
                            GradientStop { position: 1 ; color: control.pressed ? "#aaa" : "#ccc" }
                        }
                    }

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
                onClicked: decrementLeftCurrent()
            }

            Button {
                id: rightStimUpButton;
                Layout.row: 4;
                Layout.column: 2
                height: 15 

                style: ButtonStyle {
                    background: Rectangle {
                        implicitWidth: 100
                        implicitHeight: 25
                        border.width: control.activeFocus ? 2 : 1
                        border.color: "#888"
                        radius: 4
                        gradient: Gradient {
                            GradientStop { position: 0 ; color: control.pressed ? "#ccc" : "#eee" }
                            GradientStop { position: 1 ; color: control.pressed ? "#aaa" : "#ccc" }
                        }
                    }

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
                onClicked: incrementRightCurrent()
            }

            Button {
                id: rightStimDownButton;
                Layout.row: 5;
                Layout.column: 2
                height: 15

                style: ButtonStyle {
                    background: Rectangle {
                        implicitWidth: 100
                        implicitHeight: 25
                        border.width: control.activeFocus ? 2 : 1
                        border.color: "#888"
                        radius: 4
                        gradient: Gradient {
                            GradientStop { position: 0 ; color: control.pressed ? "#ccc" : "#eee" }
                            GradientStop { position: 1 ; color: control.pressed ? "#aaa" : "#ccc" }
                        }
                    }

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
                onClicked: decrementRightCurrent()
            }


            Text { id: stimStepSize;
                   text: "Stimulation Step Size: ";
                   font.bold: true;
                   color: "white";
                   font.pointSize: 25;
                   Layout.row: 6;
                   Layout.column: 0;
            }

            SpinBox { id: spinbox
                      suffix: "mA"
                      Layout.row: 6;
                      Layout.column: 1;
                      font.pointSize: 22;
                      horizontalAlignment: Text.AlignHCenter;
                      decimals: 2;
                      stepSize: step;
                      value: currentStep;
                      style: SpinBoxStyle {
                          textColor: "#434343"
                          background: Rectangle {
                              implicitWidth: 150
                              implicitHeight: 50
                              border.color: "gray"
                              color: "gray"
                              radius: 2
                          }
                      }
            }
/*            Glow {
                anchors.fill: leftStimUpButton.pressed ? leftStimUpButton : leftStimDownButton;
                radius: 18
                samples: 37
                color: "#15bdff"
                source: leftStimUpButton
            }
 */
            

        }
    }
}
