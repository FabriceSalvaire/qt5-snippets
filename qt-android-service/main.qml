import QtQuick 2.6
import QtQuick.Layouts 1.0
import QtQuick.Controls 2.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Button {
        id: start_button
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 50
        text: "Start"

        onClicked: android_activity.start_service()
    }

    Button {
        id: stop_button
        anchors.top: start_button.bottom
        anchors.topMargin: 50
        anchors.horizontalCenter: parent.horizontalCenter
        text: "Stop"

        onClicked: android_activity.stop_service()
    }
}
