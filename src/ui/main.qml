import QtQuick 2.11
import QtQuick.Controls 2.12

ApplicationWindow {
    visible: true
    width: 600
    height: 400
    font.family: opensans.name
    title: qsTr("Application")

    FontLoader {
        id: opensans
        source: "qrc:/fonts/OpenSans-Regular.ttf"
    }

    FontLoader {
        id: fontello
        source: "qrc:/icons/fontello.ttf"
    }

    Rectangle {
        width: 200
        height: 100
        color: "red"

        Text {
            id: txt_rect
            //            text: qsTr("\0xe80f")
            text: "\0xe80f"
            font.family: "fontello"
            //            font.family: fontello.name
            anchors.centerIn: parent
        }
    }
}
