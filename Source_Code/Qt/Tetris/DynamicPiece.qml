import QtQuick 2.0

Component {
    Item {
        id: dynamicPieceItem
        width: 60
        height: 60
        x: corelogic.pieceX
        y: corelogic.pieceY
        onYChanged: {
            if (corelogic.canMoveDown() === false)
            {
                loader.sourceComponent = undefined
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
                if (corelogic.dynamicPiece[0] === "transparent")
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
                if (corelogic.dynamicPiece[1] === "transparent")
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
                if (corelogic.dynamicPiece[2] === "transparent")
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
                if (corelogic.dynamicPiece[3] === "transparent")
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
                if (corelogic.dynamicPiece[4] === "transparent")
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
                if (corelogic.dynamicPiece[5] === "transparent")
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
                if (corelogic.dynamicPiece[6] === "transparent")
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
                if (corelogic.dynamicPiece[7] === "transparent")
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
                if (corelogic.dynamicPiece[8] === "transparent")
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
                if (corelogic.dynamicPiece[9] === "transparent")
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
                if (corelogic.dynamicPiece[10] === "transparent")
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
                if (corelogic.dynamicPiece[11] === "transparent")
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
                if (corelogic.dynamicPiece[12] === "transparent")
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
                if (corelogic.dynamicPiece[13] === "transparent")
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
                if (corelogic.dynamicPiece[14] === "transparent")
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
                if (corelogic.dynamicPiece[15] === "transparent")
                    return "transparent"
                else
                    return "black"
            }
        }
    }
}
