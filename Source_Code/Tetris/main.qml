import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.3
import QtQuick.Controls.Styles 1.4
import QtQuick.Dialogs 1.3

Window {
    visible: true
    width: 965
    minimumWidth: 965
    maximumWidth: 965
    height: 650
    minimumHeight: 650
    maximumHeight: 650
    title: "TETRIS"
    Component.onCompleted: {
        loader.sourceComponent = dynamicPiece;
    }

    MessageDialog {
        id: gameOverMessageDialog
        title: "Game over."
        text: "Thanks for playing! Score: " + corelogic.score
        onAccepted: {
            //reset game
            easyRadioButton.checked = true
            corelogic.resetGame()
            startButton.state = ""
            startButtonText.state = ""
            corelogic.gameOver = false
            corelogic.score = 0
        }
        visible: corelogic.gameOver
    }

    Rectangle {
        anchors.fill: parent
        color: "black"

        MouseArea {
            id: outerMostMouseArea
            anchors.fill: parent
            hoverEnabled: true
        }
        Item {
            id: keysPressedItem
            anchors.fill: parent
            focus: true
            Keys.onPressed: {
                if (corelogic.canMoveDown() === true && corelogic.timerIsRunning() === true)
                {
                    if (event.key === Qt.Key_Left) {
                        if (corelogic.canMoveLeft() === true)
                            corelogic.movePieceLeft()
                    }
                    else if (event.key === Qt.Key_Right) {
                        if (corelogic.canMoveRight() === true)
                            corelogic.movePieceRight()
                    }
                    else if (event.key === Qt.Key_Down) {
                        if (corelogic.canMoveDown() === true)
                            corelogic.movePieceDown()
                    }
                    else if(event.key === Qt.Key_Up)
                    {
                        if (corelogic.canRotate() === true)
                            corelogic.rotatePiece()
                    }
                    event.accepted = true;
                }
            }
        }

        ColumnLayout {
            id: columnLayout
            spacing: 20

            RowLayout {
                id: mainRowLayout
                anchors.fill: parent
                anchors.leftMargin: 20
                anchors.rightMargin: 20
                anchors.topMargin: 20
                anchors.bottomMargin: 20
                spacing: 20

                Rectangle {
                    id: leftRectangle
                    height: 550
                    width: 235
                    border.color: "#17FF00"
                    border.width: 1
                    color: "black"
                    Text {
                        x: 10
                        y: 10
                        text: "Developed by:"
                        color: "#17FF00"
                        font.family: "Courier"
                        font.pixelSize: 14
                    }
                    Text {
                        x: 14
                        y: 110
                        text: "Francisco Hernandez"
                        color: "#17FF00"
                        font.family: "Courier"
                        font.pixelSize: 14
                    }
                    Text {
                        x: 18
                        y: 210
                        text: "Jonathan Tielebein"
                        color: "#17FF00"
                        font.family: "Courier"
                        font.pixelSize: 14
                    }
                    Text {
                        x: 20
                        y: 310
                        text: "Zachary Trujillo"
                        color: "#17FF00"
                        font.family: "Courier"
                        font.pixelSize: 14
                    }
                }
                Rectangle {
                    id: middleRectangle
                    height: 570
                    width: 420
                    border.color: "#17FF00"
                    border.width: 2
                    color: "black"

                    Rectangle {
                        id: innerMiddleRectangle
                        height: 540
                        width: 390
                        anchors.top: middleRectangle.top
                        anchors.left: middleRectangle.left
                        anchors.right: middleRectangle.right
                        anchors.bottom: middleRectangle.bottom
                        anchors.leftMargin: 15
                        anchors.rightMargin: 15
                        anchors.bottomMargin: 15
                        anchors.topMargin: 15
                        border.color: "#17FF00"

                        Grid {
                            id: grid
                            x: 0
                            y: 0
                            columns: 26
                            spacing: 0
                            Repeater {
                                id: pieceRepeater
                                model: corelogic.board
                                Rectangle {
                                    id: piece
                                    width: 15; height: 15
                                    border.width: 1
                                    color: corelogic.board[index]
                                    MouseArea {
                                        anchors.fill: parent
                                        onClicked: {
                                            console.log("Clicked " + index)
                                        }
                                    }
                                }
                            }
                        }
                        Loader {
                            id: loader
                        }
                        DynamicPiece {
                            id: dynamicPiece
                        }
                    }

                }
                Rectangle {
                    id: rightRectangle
                    height: 550
                    width: 235
                    border.color: "#17FF00"
                    border.width: 1
                    color: "black"
                    Text {
                        x: 45
                        y: 20
                        text: "Select difficulty:"
                        font.family: "Courier"
                        font.pixelSize: 14
                        color: "#17FF00"
                    }
                    ColumnLayout {
                        x: 10
                        y: 120
                        spacing: 20
                        RadioButton {
                            id: easyRadioButton
                            checked: true
                            onCheckedChanged: {
                                if (easyRadioButton.checked === true)
                                    corelogic.gameLevel = 1
                                startButtonText.state = ""
                                startButton.state = ""
                                corelogic.stopTimer()
                            }
                            Text {
                                x: 50
                                y: 10
                                text: qsTr("Easy")
                                font.family: "Courier"
                                font.pixelSize: 14
                                color: "#17FF00"
                            }
                        }
                        RadioButton {
                            id: mediumRadioButton
                            checked: false
                            onCheckedChanged: {
                                if (mediumRadioButton.checked === true)
                                    corelogic.gameLevel = 2
                                startButtonText.state = ""
                                startButton.state = ""
                                corelogic.stopTimer()
                            }
                            Text {
                                x: 50
                                y: 10
                                text: qsTr("Medium")
                                font.family: "Courier"
                                font.pixelSize: 14
                                color: "#17FF00"
                            }
                        }
                        RadioButton {
                            id: hardRadioButton
                            checked: false
                            onCheckedChanged: {
                                if (hardRadioButton.checked === true)
                                    corelogic.gameLevel = 3
                                startButtonText.state = ""
                                startButton.state = ""
                                corelogic.stopTimer()
                            }

                            Text {
                                x: 50
                                y: 10
                                text: qsTr("Hard")
                                font.family: "Courier"
                                font.pixelSize: 14
                                color: "#17FF00"
                            }
                        }
                    }

                    Text {
                        x: 50
                        y: 420
                        text: "Score:  " + corelogic.score
                        font.family: "Courier"
                        font.pixelSize: 14
                        color: "#17FF00"
                    }
                }
            }
            Item {
                id: startButtonItem
                anchors.top: mainRowLayout.bottom
                anchors.topMargin: 55
                anchors.left: parent.left

                Rectangle {
                    id: bottomLine
                    anchors.top: startButtonItem.top
                    anchors.topMargin: 20
                    height: 1
                    width: 960
                    color: "#32CD32"
                }

                Button {
                    id: startButton
                    anchors.left: parent.left
                    anchors.leftMargin: 430
                    anchors.top: startButtonItem.bottom
                    background: Rectangle {
                        id: buttonBackground
                        implicitWidth: 100
                        implicitHeight: 40
                        color: startButton.down ? "#21371F" : "black"
                        border.color: "#17FF00"
                        border.width: 1
                        radius: 4
                    }
                    states: [
                        State {
                            name: "Clicked"
                            PropertyChanges { target: startButton;}
                        }
                    ]

                    MouseArea {
                        id: buttonMouseArea
                        anchors.fill: parent
                        onClicked: {
                            startButton.state == 'Clicked' ? startButton.state = "" : startButton.state = 'Clicked';
                            startButtonText.state == 'Clicked' ? startButtonText.state = "" : startButtonText.state = 'Clicked';
                            if (startButton.state == "Clicked")
                            {
                                corelogic.startTimer()
                                keysPressedItem.focus = true
                            }
                            else
                            {
                                corelogic.stopTimer()
                                keysPressedItem.focus = true
                            }
                        }
                    }
                    Text {
                        id: startButtonText
                        text: "START"
                        color: "#17FF00"
                        font.family: "Courier"
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                        states: [
                            State {
                                name: "Clicked"
                                PropertyChanges { target: startButtonText; text: "PAUSE" }
                            }
                        ]
                    }
                }
            }
        }
    }
}
