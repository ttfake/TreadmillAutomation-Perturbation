import QtQuick 2.6
import QtQuick.Controls 2.0
import io.qt.examples.backend 1.0

ApplicationWindow {
    id: root
    width: 300
    height: 480
    visible: true

    QmlInterface {
        id: QmlInterface
    }

    TextField {
        text: QmlInterface.userName
        placeholderText: qsTr("User name")
        anchors.centerIn: parent

        onTextChanged: QmlInterface.userName = text
    }
}
