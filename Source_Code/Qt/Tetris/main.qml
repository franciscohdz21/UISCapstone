import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.3
import QtQuick.Controls.Styles 1.4

Window {
    visible: true
    width: 960
    minimumWidth: 960
    maximumWidth: 960
    height: 650
    minimumHeight: 650
    maximumHeight: 650
    title: "TETRIS ON STEROIDS"
    Component.onCompleted: {
        loader.sourceComponent = myDynComp;
    }

    Rectangle {
        anchors.fill: parent
        color: "black"

        MouseArea {
            id: outerMostMouseArea
            anchors.fill: parent
            hoverEnabled: true
            onPositionChanged: {
//                console.log("Mouse X: " + mouse.x + ", Mouse Y: " + mouse.y)
            }
        }
        Item {
            id: keysPressedItem
            anchors.fill: parent
            focus: true
            Keys.onPressed: {
                if (corelogic.canMoveDown() === true)
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

                        Component {
                            id: myDynComp
                            Rectangle {
                                id: movingPiece
                                x: corelogic.pieceX
                                y: corelogic.pieceY
                                width: corelogic.pieceWidth
                                height: corelogic.pieceHeight
                                color: "green"
                                onYChanged: {
                                    if (corelogic.canMoveDown() === false)
                                    {
                                        corelogic.setPieceAtBoard(corelogic.getBoardIndex(x, y), color)
                                        corelogic.checkForCompleteRow()
                                        loader.sourceComponent = undefined;
                                        corelogic.resetPiece()
                                        loader.sourceComponent = myDynComp
                                    }
                                }
                            }
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
