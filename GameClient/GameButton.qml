import QtQuick 2.15

Rectangle {
    id: button
    property color defaultColor: "#2a9d8f"
    property color onClickColor: "#264653"
    property string btnText: ""
    property int fontSize: 48
    property bool bold: true
    signal buttonClicked()

    color: defaultColor;
    radius: 10
    MouseArea{
        anchors.fill: parent
        onPressed: button.color = button.onClickColor
        onReleased: button.color = button.defaultColor
        onClicked: button.buttonClicked()
    }
    Text {
        text: btnText
        anchors.centerIn: parent
        font.pointSize: fontSize
        color: "#e9c46a"
        font.bold: bold
    }
}
