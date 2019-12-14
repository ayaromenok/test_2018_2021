import QtQuick 2.14
import QtQuick.Controls 2.14

Page {
    width: 600
    height: 400

    header: Label {
        text: qsTr("Page 1")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }

    Label {
        text: qsTr("You are on Page 1.")
        anchors.centerIn: parent
    }

    Text {
        id: element
        x: 98
        y: 88
        text: qsTr("CMake  Test")
        font.pixelSize: 20
    }
}
