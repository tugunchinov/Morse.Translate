import QtQuick 2.6
import QtQuick.Controls 2.6
import QtQuick.Dialogs 1.3

import backend 1.0

ApplicationWindow {
    title: qsTr("Morse.Translate")

    width: 768
    height: 480

    visible: true

    menuBar: Rectangle {
        height: 74
        color: "mediumblue"

        Text {
            text: "Morse.Translate"
            color: "white"

            leftPadding: 20
            font.pixelSize: 32
            font.weight: Font.DemiBold
            anchors.fill: parent
            verticalAlignment: Text.AlignVCenter
        }
    }

    Backend {
        id: backend
    }

    header: Row {
        Text {
            text: backend.strInputType

            width: parent.width/3
            height: langChange.height

            color: "mediumblue"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        Rectangle {
            id: langChange

            width: parent.width/3
            height: 40

            Image {
                source: "img/arrows.png"

                sourceSize.width: 24
                sourceSize.height: 24

                x: (parent.width - width)/2
                y: (parent.height - height)/2

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        [backend.inputType, backend.outputType] = [backend.outputType, backend.inputType];
                        [backend.input, backend.output] = [backend.output, backend.input];
                    }
                }
           }
        }

        Text {
            text: backend.strOutputType

            width: parent.width/3
            height: langChange.height

            color: "mediumblue"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }
    }

    Row {
        id: textAreas

        width: parent.width
        height: output.height

        TextArea {
            id: input

            width: parent.width/2
            height: output.height

            text: backend.input
            placeholderText: "Введите текст"
            wrapMode: Text.Wrap
            selectByMouse: true

            onTextChanged: backend.input = text
        }

        Rectangle {
            width: parent.width/2
            height: output.height

            color: "lightgray"

            TextArea {
                id: output

                width: parent.width
                height: Math.max(input.contentHeight + input.font.pixelSize, contentHeight + font.pixelSize, 128)

                placeholderText: "Перевод"
                wrapMode: Text.Wrap
                text: backend.output
                selectByMouse: true
                readOnly: true
            }
        }
    }

    function openFile(fileUrl) {
        var request = new XMLHttpRequest();
        request.open("GET", fileUrl, false);
        request.send(null);
        return request.responseText;
    }

    function saveFile(fileUrl, text) {
        var request = new XMLHttpRequest();
        request.open("PUT", fileUrl, false);
        request.send(text);
        return request.status;
    }

    FileDialog {
        id: openFileDialog
        nameFilters: ["Text files (*.txt)", "All files (*)"]
        onAccepted: backend.input = openFile(openFileDialog.fileUrl)
    }

    FileDialog {
        id: saveFileDialog
        selectExisting: false
        sidebarVisible: true
        nameFilters: ["Text files (*.txt)", "All files (*)"]
        onAccepted: saveFile(saveFileDialog.fileUrl, output.text)
    }

    Button {
        text: "Загрузить файл"
        anchors.top: textAreas.bottom
        anchors.left: textAreas.left
        anchors.topMargin: 10
        anchors.leftMargin: 20

        onClicked: openFileDialog.open()
    }

    Button {
        text: "Сохранить в файл"
        anchors.top: textAreas.bottom
        anchors.right: textAreas.right
        anchors.topMargin: 10
        anchors.rightMargin: 20

        onClicked: saveFileDialog.open()
    }
}