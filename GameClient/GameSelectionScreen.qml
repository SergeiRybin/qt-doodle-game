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
        id: createGameButton
        width: 400
        height: 100
        anchors {
            horizontalCenter: parent.horizontalCenter
            top: mainTitle.bottom
            topMargin: 40
        }
        btnText: "Create Game"
        onButtonClicked: manager.onNewGameRequest()
    }

    GameButton
    {
        id: joinGameButton
        width: 400
        height: 100
        anchors {
            horizontalCenter: parent.horizontalCenter
            top: createGameButton.bottom
            topMargin: 20
        }
        btnText: "Join Game"
        onButtonClicked: manager.onJoinGameRequest(1)
    }

    GameButton
    {
        id: backButton
        width: 400
        height: 100
        anchors {
            horizontalCenter: parent.horizontalCenter
            top: joinGameButton.bottom
            topMargin: 20
        }
        btnText: "Back"
        onButtonClicked: pageLoader.source = "WelcomeScreen.qml"
    }
}
