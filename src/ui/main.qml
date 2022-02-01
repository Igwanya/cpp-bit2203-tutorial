import QtQuick 2.11
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Layouts 1.12

ApplicationWindow {
    visible: true
    width: 1024
    height: 800
    font.family: opensans.name
    title: qsTr("Application")

    FontLoader {
        id: opensans
        source: "qrc:/fonts/OpenSans-Regular.ttf"
    }

    FontLoader {
        id: fontawesome
        source: "qrc:/icons/fa-solid-900.ttf"
    }

    menuBar: MenuBar {

        Menu {
            title: qsTr("File")
            font.family: opensans.name
            font.pixelSize: 24
            MenuItem {
                text: qsTr("&Open")
                font.family: opensans.name
                font.pixelSize: 16
                onTriggered: console.log("Open action triggered")
            }

            MenuItem {
                text: qsTr("&Settings")
                font.family: opensans.name
                font.pixelSize: 16
                onTriggered: console.log("Settings action triggered")
            }

            MenuSeparator {}
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit()
                font.family: opensans.name
                font.pixelSize: 16
            }
        }
        Menu {
            id: user_profile_menu
            title: "\uf2bd"
            font.family: fontawesome.name
            font.pixelSize: 24
            MenuItem {
                text: qsTr("\uf4fe Profile")
                font.family: opensans.name
                font.pixelSize: 16
                onTriggered: console.log("Profile action triggered")
            }

            MenuSeparator {}
            MenuItem {
                text: qsTr("\uf2f6 Log in")
                font.family: opensans.name
                font.pixelSize: 16
                onTriggered: console.log("Login action triggered")
            }

            MenuItem {
                text: qsTr("\uf2f5 Log out")
                font.family: opensans.name
                font.pixelSize: 16
                onTriggered: console.log("Logout action triggered")
                visible: false
            }
        }
    }

    StackLayout {
        id: layout
        anchors.fill: parent
        currentIndex: 1
        Rectangle {
            color: 'teal'
            implicitWidth: 200
            implicitHeight: 200
        }
        Rectangle {
            color: 'plum'
            implicitWidth: 300
            implicitHeight: 200
        }
    }
}
