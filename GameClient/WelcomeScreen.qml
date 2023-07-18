import QtQuick 2.15

Rectangle {
    color: "#e76f51"
    anchors.fill: parent
    Text {
        anchors.horizontalCenter: parent.horizontalCenter
        id: mainTitle
        text: qsTr("Doodle game")
        font.pointSize: 48
        topPadding: 150
        color: "#e9c46a"
        font.bold: true
    }

    GameButton
    {
        id: playButton
        width: 240
        height: 100
        anchors.centerIn: parent
        btnText: "Play"
        onButtonClicked: {
            pageLoader.source = "GameSelectionScreen.qml"
            manager.connectToServer()
        }
    }

    GameButton
    {
        id: quitButton
        width: 240
        height: 100
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: playButton.bottom
        anchors.topMargin: 20
        btnText: "Quit"
        onButtonClicked: manager.clicked(btnText)
    }
}
