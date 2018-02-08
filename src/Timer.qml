import QtQuick 2.3
import QtQuick.Controls 1.4
import QtGraphicalEffects 1.0
import QtQuick.Layouts 1.3
import QtQuick.Controls.Styles 1.4

Item {
    id: stimTimer
    width: 950
    height: 750
    property double timerValue
    timerValue: 0.0
    property double currentStep
    currentStep: timerStepSpinbox.value
    property double step
    step: 0.25
    signal timerUpdated();

    function incrementTimer()
    {
        timerValue += currentStep
        timerUpdated()
    }
    function decrementTimer()
    {
        timerValue -= currentStep
        timerUpdated()
    }
    function getTimerValue()
    {
        return timerValue
    }

    Rectangle {
        id: stimTimerPanel
        width: 950 
        height: 750
        color: "dark grey"

        GridLayout {
            id: stimGrid
            columns: 3
        
            Text {
                id: interStimTimerLabel;
                text: "Interstimulation Time:";
                font.bold: true;
                color: "white";
                font.pointSize: 20;
                Layout.row: 0;
                Layout.column: 0;
            }
            TextField {
               id: stimTimerTextField;
               property string stimTimerPlaceholderText
               property string units
               units: "ms"
               stimTimerPlaceholderText: (timerValue).toLocaleString(Qt.locale("en_US")) + units;
               placeholderText: stimTimerPlaceholderText;
               readOnly: true;
               Layout.row: 0; 
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
                   selectedTextColor: "blue"
                   selectionColor: "blue" 
               }
            }

            Button {
                id: stimTimerUpButton;
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
                onClicked: incrementTimer()
            }
            Button {
                id: stimTimerDownButton;
                Layout.row: 1;
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
                onClicked: decrementTimer()
            }

            Text {
                id: interStimTimerStepSizeLabel;
                text: "Interstimulation Time Step Size:";
                font.bold: true;
                color: "white";
                font.pointSize: 20;
                Layout.row: 2;
                Layout.column: 0;
            }
            SpinBox { 
                id: timerStepSpinbox
                suffix: "ms"
                Layout.row: 2;
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
        }        
    }
} 
