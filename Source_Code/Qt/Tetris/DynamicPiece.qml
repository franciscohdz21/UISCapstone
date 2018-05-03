import QtQuick 2.0

Component {
    Item {
        id: dynamicPieceItem
        width: 60
        height: 60
        x: corelogic.pieceX
        y: corelogic.pieceY
        property bool movedDownOnce: corelogic.dynamicPieceMovedDownOnce

        onYChanged: {
            if (corelogic.canMoveDown() === false)
            {
                loader.sourceComponent = undefined
                corelogic.dynamicPieceMovedDownOnce = false
                corelogic.setPieceAtBoard()
                corelogic.checkForCompleteRow()
                corelogic.resetPiece()
                loader.sourceComponent = dynamicPiece
            }
        }

        Rectangle {
            id: piece1
            anchors.top: parent.top
            anchors.left: parent.left
            width: 15
            height: 15
            color: corelogic.dynamicPiece[0]
            border.width: 1
            border.color: {
                if ((corelogic.dynamicPiece[0] === "transparent") || (corelogic.dynamicPiece[0] === "OUT OF BOARD"))
                    return "transparent"
                else
                    return "black"
            }
        }
        Rectangle {
            id: piece2
            anchors.top: piece1.top
            anchors.left: piece1.right
            width: 15
            height: 15
            color: corelogic.dynamicPiece[1]
            border.width: 1
            border.color: {
                if ((corelogic.dynamicPiece[1] === "transparent") || (corelogic.dynamicPiece[1] === "OUT OF BOARD"))
                    return "transparent"
                else
                    return "black"
            }
        }
        Rectangle {
            id: piece3
            anchors.top: piece1.top
            anchors.left: piece2.right
            width: 15
            height: 15
            color: corelogic.dynamicPiece[2]
            border.width: 1
            border.color: {
                if ((corelogic.dynamicPiece[2] === "transparent") || (corelogic.dynamicPiece[2] === "OUT OF BOARD"))
                    return "transparent"
                else
                    return "black"
            }
        }
        Rectangle {
            id: piece4
            anchors.top: piece1.top
            anchors.left: piece3.right
            width: 15
            height: 15
            color: corelogic.dynamicPiece[3]
            border.width: 1
            border.color: {
                if ((corelogic.dynamicPiece[3] === "transparent") || (corelogic.dynamicPiece[3] === "OUT OF BOARD"))
                    return "transparent"
                else
                    return "black"
            }
        }
        Rectangle {
            id: piece5
            anchors.top: piece1.bottom
            anchors.left: piece1.left
            width: 15
            height: 15
            color: corelogic.dynamicPiece[4]
            border.width: 1
            border.color: {
                if ((corelogic.dynamicPiece[4] === "transparent") || (corelogic.dynamicPiece[4] === "OUT OF BOARD"))
                    return "transparent"
                else
                    return "black"
            }
        }
        Rectangle {
            id: piece6
            anchors.top: piece5.top
            anchors.left: piece5.right
            width: 15
            height: 15
            color: corelogic.dynamicPiece[5]
            border.width: 1
            border.color: {
                if ((corelogic.dynamicPiece[5] === "transparent") || (corelogic.dynamicPiece[5] === "OUT OF BOARD"))
                    return "transparent"
                else
                    return "black"
            }
        }
        Rectangle {
            id: piece7
            anchors.top: piece5.top
            anchors.left: piece6.right
            width: 15
            height: 15
            color: corelogic.dynamicPiece[6]
            border.width: 1
            border.color: {
                if ((corelogic.dynamicPiece[6] === "transparent") || (corelogic.dynamicPiece[6] === "OUT OF BOARD"))
                    return "transparent"
                else
                    return "black"
            }
        }
        Rectangle {
            id: piece8
            anchors.top: piece5.top
            anchors.left: piece7.right
            width: 15
            height: 15
            color: corelogic.dynamicPiece[7]
            border.width: 1
            border.color: {
                if ((corelogic.dynamicPiece[7] === "transparent") || (corelogic.dynamicPiece[7] === "OUT OF BOARD"))
                    return "transparent"
                else
                    return "black"
            }
        }
        Rectangle {
            id: piece9
            anchors.top: piece8.bottom
            anchors.left: piece1.left
            width: 15
            height: 15
            color: corelogic.dynamicPiece[8]
            border.width: 1
            border.color: {
                if ((corelogic.dynamicPiece[8] === "transparent") || (corelogic.dynamicPiece[8] === "OUT OF BOARD"))
                    return "transparent"
                else
                    return "black"
            }
        }
        Rectangle {
            id: piece10
            anchors.top: piece9.top
            anchors.left: piece9.right
            width: 15
            height: 15
            color: corelogic.dynamicPiece[9]
            border.width: 1
            border.color: {
                if ((corelogic.dynamicPiece[9] === "transparent") || (corelogic.dynamicPiece[9] === "OUT OF BOARD"))
                    return "transparent"
                else
                    return "black"
            }
        }
        Rectangle {
            id: piece11
            anchors.top: piece9.top
            anchors.left: piece10.right
            width: 15
            height: 15
            color: corelogic.dynamicPiece[10]
            border.width: 1
            border.color: {
                if ((corelogic.dynamicPiece[10] === "transparent") || (corelogic.dynamicPiece[10] === "OUT OF BOARD"))
                    return "transparent"
                else
                    return "black"
            }
        }
        Rectangle {
            id: piece12
            anchors.top: piece9.top
            anchors.left: piece11.right
            width: 15
            height: 15
            color: corelogic.dynamicPiece[11]
            border.width: 1
            border.color: {
                if ((corelogic.dynamicPiece[11] === "transparent") || (corelogic.dynamicPiece[11] === "OUT OF BOARD"))
                    return "transparent"
                else
                    return "black"
            }
        }
        Rectangle {
            id: piece13
            anchors.top: piece9.bottom
            anchors.left: piece1.left
            width: 15
            height: 15
            color: corelogic.dynamicPiece[12]
            border.width: 1
            border.color: {
                if ((corelogic.dynamicPiece[12] === "transparent") || (corelogic.dynamicPiece[12] === "OUT OF BOARD"))
                    return "transparent"
                else
                    return "black"
            }
        }
        Rectangle {
            id: piece14
            anchors.top: piece13.top
            anchors.left: piece13.right
            width: 15
            height: 15
            color: corelogic.dynamicPiece[13]
            border.width: 1
            border.color: {
                if ((corelogic.dynamicPiece[13] === "transparent") || (corelogic.dynamicPiece[13] === "OUT OF BOARD"))
                    return "transparent"
                else
                    return "black"
            }
        }
        Rectangle {
            id: piece15
            anchors.top: piece13.top
            anchors.left: piece14.right
            width: 15
            height: 15
            color: corelogic.dynamicPiece[14]
            border.width: 1
            border.color: {
                if ((corelogic.dynamicPiece[14] === "transparent") || (corelogic.dynamicPiece[14] === "OUT OF BOARD"))
                    return "transparent"
                else
                    return "black"
            }
        }
        Rectangle {
            id: piece16
            anchors.top: piece13.top
            anchors.left: piece15.right
            width: 15
            height: 15
            color: corelogic.dynamicPiece[15]
            border.width: 1
            border.color: {
                if ((corelogic.dynamicPiece[15] === "transparent") || (corelogic.dynamicPiece[15] === "OUT OF BOARD"))
                    return "transparent"
                else
                    return "black"
            }
        }
    }
}
