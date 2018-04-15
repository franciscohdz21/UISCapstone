#include <QDebug>
#include <QString>
#include <QStringList>
#include <QTimer>
#include <cstdlib>
#include "corelogic.h"

//table info
#define TABLE_WIDTH 26
#define TABLE_HEIGHT 36
//colors
#define BLACK        "#000000"
#define BROWN        "#8B4513"
#define YELLOW       "#FFC900"
#define LIGHT_BLUE   "#00FFCD"
#define DARK_BLUE    "#059BF6"
#define PURPLE       "#A516EC"
#define PINK         "#F711EC"
#define RED          "#F71111"
#define GREY         "#A0A0A0"
#define TRANSPARENT  "transparent"
#define OUT_OF_BOARD "OUT OF BOARD"


CoreLogic::~CoreLogic()
{
    delete m_timer;
}
CoreLogic &CoreLogic::Instance()
{
    static CoreLogic instance; //Guaranteed to be destroyed
    return instance;
}
void CoreLogic::init()
{
    //add colors
    m_listOfColors.push_back(BROWN);
    m_listOfColors.push_back(YELLOW);
    m_listOfColors.push_back(LIGHT_BLUE);
    m_listOfColors.push_back(DARK_BLUE);
    m_listOfColors.push_back(PURPLE);
    m_listOfColors.push_back(PINK);
    m_listOfColors.push_back(RED);
    m_listOfColors.push_back(GREY);
    //dynamic piece colors
    m_dynamicPiece.push_back(YELLOW);
    m_dynamicPiece.push_back(TRANSPARENT);
    m_dynamicPiece.push_back(TRANSPARENT);
    m_dynamicPiece.push_back(TRANSPARENT);
    m_dynamicPiece.push_back(TRANSPARENT);
    m_dynamicPiece.push_back(TRANSPARENT);
    m_dynamicPiece.push_back(TRANSPARENT);
    m_dynamicPiece.push_back(TRANSPARENT);
    m_dynamicPiece.push_back(TRANSPARENT);
    m_dynamicPiece.push_back(TRANSPARENT);
    m_dynamicPiece.push_back(TRANSPARENT);
    m_dynamicPiece.push_back(TRANSPARENT);
    m_dynamicPiece.push_back(TRANSPARENT);
    m_dynamicPiece.push_back(TRANSPARENT);
    m_dynamicPiece.push_back(TRANSPARENT);
    m_dynamicPiece.push_back(TRANSPARENT);
    m_moveDownVelocity = 1000;
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(gameRunning()));
    setPieceX(180);
    setPieceY(0);
    for (auto i = 0; i < (TABLE_HEIGHT*TABLE_WIDTH); i++)
    {
        m_board.push_back(BLACK);
    }
//    m_board.push_back(BLACK);
//    for (auto i = 0; i < (25); i++)
//    {
//        m_board.push_back("#FF0000");
//    }
//    for (auto i = 0; i < (884); i++)
//    {
//        m_board.push_back(BLACK);
//    }
//    for (auto i = 0; i < (26); i++)
//    {
//        m_board.push_back("#FF0000");
//    }
    emit boardChanged();
}
int CoreLogic::getBoardIndex(double x, double y)
{
    return (x/15) + (y/15 * TABLE_WIDTH);
}
int CoreLogic::getBoardIndexFromPieceIndex(int pieceIndex)
{
    double firstIndex = (m_pieceX/15) + (m_pieceY/15 * TABLE_WIDTH);
    if (pieceIndex == 0)
        return firstIndex;
    else if (pieceIndex == 1)
        return firstIndex + 1;
    else if (pieceIndex == 2)
        return firstIndex + 2;
    else if (pieceIndex == 3)
        return firstIndex + 3;
    else if (pieceIndex == 4)
        return firstIndex + TABLE_WIDTH;
    else if (pieceIndex == 5)
        return firstIndex + TABLE_WIDTH + 1;
    else if (pieceIndex == 6)
        return firstIndex + TABLE_WIDTH + 2;
    else if (pieceIndex == 7)
        return firstIndex + TABLE_WIDTH + 3;
    else if (pieceIndex == 8)
        return firstIndex + (TABLE_WIDTH*2);
    else if (pieceIndex == 9)
        return firstIndex + (TABLE_WIDTH*2) + 1;
    else if (pieceIndex == 10)
        return firstIndex + (TABLE_WIDTH*2) + 2;
    else if (pieceIndex == 11)
        return firstIndex + (TABLE_WIDTH*2) + 3;
    else if (pieceIndex == 12)
        return firstIndex + (TABLE_WIDTH*3);
    else if (pieceIndex == 13)
        return firstIndex + (TABLE_WIDTH*3) + 1;
    else if (pieceIndex == 14)
        return firstIndex + (TABLE_WIDTH*3) + 2;
    else if (pieceIndex == 15)
        return firstIndex + (TABLE_WIDTH*3) + 3;
    return -1;
}
void CoreLogic::setPieceAtBoard()
{
    for (int i = 0; i < m_dynamicPiece.size(); i++)
    {
        if (m_dynamicPiece.at(i) != TRANSPARENT)
        {
            m_board.replace(getBoardIndexFromPieceIndex(i), m_dynamicPiece.at(i));
        }
    }
    emit boardChanged();
}
void CoreLogic::checkForCompleteRow()
{
    for (int i = 0; i < TABLE_HEIGHT; i++)
    {
        for (int j = 0; j < TABLE_WIDTH; j++)
        {
            //qDebug() << "Index: " << ((i*26)+j) <<  " Value: " << m_board.at((i*26)+j);
            if (m_board.at((i*26)+j) == BLACK)
            {
                break;
            }
            if (j == 25)
            {
                for (int k = 0; k < TABLE_WIDTH; k++)
                {
                    m_board.replace(((i*26)+k), BLACK);
                }
                //Move rows
                for (int l = i; l != 0; l--)
                {
                    for (int m = 0; m < TABLE_WIDTH; m++)
                    {
                        m_board.replace(((l*26)+m), m_board.value(((l-1)*26)+m));
                    }
                }
                //Set upper row to black
                for (int m = 0; m < TABLE_WIDTH; m++)
                {
                    m_board.replace(m, BLACK);
                }
            }
        }
    }
    emit boardChanged();
}
int CoreLogic::getCurrentPiece() const
{
    return m_currentPiece;
}
void CoreLogic::setCurrentPiece(int piece)
{
    m_currentPiece = piece;
}
QStringList CoreLogic::listOfColors()
{
    return m_listOfColors;
}
QString CoreLogic::getRandomColor()
{
    int randomNumber;
    srand(time(NULL));
    randomNumber = rand()% 8;
    return m_listOfColors.at(randomNumber);
}
QVector<int> CoreLogic::downMostPiecesIndexes() const
{
    return m_downMostPiecesIndexes;
}
void CoreLogic::setDownMostPiecesIndexes()
{
    bool colorPieceFound = false;
    m_downMostPiecesIndexes.clear();
    for (int i = 15; i >= 0; i--)
    {
        if (i == 11 && colorPieceFound == true)
            break;
        else if (i == 7 && colorPieceFound == true)
            break;
        else if (i == 3 && colorPieceFound == true)
            break;
        if (m_dynamicPiece.at(i) != TRANSPARENT)
        {
            colorPieceFound = true;
            m_downMostPiecesIndexes.push_back(i);
        }
    }
}
QVector<int> CoreLogic::leftMostPiecesIndexes() const
{
    return m_leftMostPiecesIndexes;
}
void CoreLogic::setLeftMostPiecesIndexes()
{
    bool colorPieceFound = false;
    m_leftMostPiecesIndexes.clear();
    for (int i = 0; i != 19; i=i+4)
    {
        if (i < 15 && i > -1 && m_dynamicPiece.at(i) != TRANSPARENT && m_dynamicPiece.at(i) != OUT_OF_BOARD)
        {
            colorPieceFound = true;
            m_leftMostPiecesIndexes.push_back(i);
        }
        if (i == 16)
        {
            if (colorPieceFound == true)
                break;
            i = -3;
        }
        else if (i == 17)
        {
            if (colorPieceFound == true)
                break;
            i = -2;
        }
        else if (i == 18)
        {
            if (colorPieceFound == true)
                break;
            i = -1;
        }
    }
}
QVector<int> CoreLogic::rightMostPiecesIndexes() const
{
    return m_rightMostPiecesIndexes;
}
void CoreLogic::setRightMostPiecesIndexes()
{
    bool colorPieceFound = false;
    m_rightMostPiecesIndexes.clear();
    for (int i = 3; i != 16; i=i+4)
    {
        if (i < 15 && i > -1 && m_dynamicPiece.at(i) != TRANSPARENT && m_dynamicPiece.at(i) != OUT_OF_BOARD)
        {
            colorPieceFound = true;
            m_rightMostPiecesIndexes.push_back(i);
        }
        if (i == 19)
        {
            if (colorPieceFound == true)
                break;
            i = -2;
        }
        else if (i == 18)
        {
            if (colorPieceFound == true)
                break;
            i = -3;
        }
        else if (i == 17)
        {
            if (colorPieceFound == true)
                break;
            i = -4;
        }
    }
}
//QVector<int> CoreLogic::getPieceIndexesInsideBoard() const
//{
//    return m_pieceIndexesInsideBoard;
//}
//void CoreLogic::setPieceIndexesInsideBoard()
//{
//    //first column
//    if (m_dynamicPiece.at(0)  != TRANSPARENT ||
//        m_dynamicPiece.at(4)  != TRANSPARENT ||
//        m_dynamicPiece.at(8)  != TRANSPARENT ||
//        m_dynamicPiece.at(12) != TRANSPARENT)
//    {
//        m_pieceIndexesInsideBoard.push_back(0);
//        m_pieceIndexesInsideBoard.push_back(4);
//        m_pieceIndexesInsideBoard.push_back(8);
//        m_pieceIndexesInsideBoard.push_back(12);
//    }
//    //second column
//    if (m_dynamicPiece.at(1)  != TRANSPARENT ||
//        m_dynamicPiece.at(5)  != TRANSPARENT ||
//        m_dynamicPiece.at(9)  != TRANSPARENT ||
//        m_dynamicPiece.at(13) != TRANSPARENT)
//    {
//        m_pieceIndexesInsideBoard.push_back(1);
//        m_pieceIndexesInsideBoard.push_back(5);
//        m_pieceIndexesInsideBoard.push_back(9);
//        m_pieceIndexesInsideBoard.push_back(13);
//    }
//    //third column
//    if (m_dynamicPiece.at(2)  != TRANSPARENT ||
//        m_dynamicPiece.at(6)  != TRANSPARENT ||
//        m_dynamicPiece.at(10) != TRANSPARENT ||
//        m_dynamicPiece.at(14) != TRANSPARENT)
//    {
//        m_pieceIndexesInsideBoard.push_back(2);
//        m_pieceIndexesInsideBoard.push_back(6);
//        m_pieceIndexesInsideBoard.push_back(10);
//        m_pieceIndexesInsideBoard.push_back(14);
//    }
//    //fourth column
//    if (m_dynamicPiece.at(3)  != TRANSPARENT ||
//        m_dynamicPiece.at(7)  != TRANSPARENT ||
//        m_dynamicPiece.at(11) != TRANSPARENT ||
//        m_dynamicPiece.at(15) != TRANSPARENT)
//    {
//        m_pieceIndexesInsideBoard.push_back(3);
//        m_pieceIndexesInsideBoard.push_back(7);
//        m_pieceIndexesInsideBoard.push_back(11);
//        m_pieceIndexesInsideBoard.push_back(15);
//    }
//}
bool CoreLogic::canMoveLeft()
{
    setLeftMostPiecesIndexes();
    for (int i = 0; i < m_leftMostPiecesIndexes.size(); i++)
    {
        if (getBoardIndexFromPieceIndex(m_leftMostPiecesIndexes.at(i)) % TABLE_WIDTH == 0)
        {
            return false;
        }
        else if (m_board.at(getBoardIndexFromPieceIndex(m_leftMostPiecesIndexes.at(i)) - 1) != BLACK)
        {
            return false;
        }
    }
    return true;
}
bool CoreLogic::canMoveRight()
{
    setRightMostPiecesIndexes();
    for (int i = 0; i < m_rightMostPiecesIndexes.size(); i++)
    {
        if ((getBoardIndexFromPieceIndex(m_rightMostPiecesIndexes.at(i))+1) % TABLE_WIDTH == 0)
        {
            return false;
        }
    }
    return true;
}
bool CoreLogic::canMoveDown()
{
    setDownMostPiecesIndexes();
    for (int i = 0; i < m_downMostPiecesIndexes.size(); i++)
    {
        if (getBoardIndexFromPieceIndex(m_downMostPiecesIndexes.at(i)) > 909)
        {
            return false;
        }
        else if (m_board.at(getBoardIndexFromPieceIndex(m_downMostPiecesIndexes.at(i)) + TABLE_WIDTH) != BLACK)
        {
            return false;
        }
    }
    return true;
}
bool CoreLogic::canRotate()
{
//    setPieceIndexesInsideBoard();
//    //store busy board indexes
//    QVector <int> busyBoardIndexes;
//    for (int i = 0; i < m_pieceIndexesInsideBoard.size(); i++)
//    {
//        busyBoardIndexes.push_back(getBoardIndexFromPieceIndex(m_pieceIndexesInsideBoard.at(i)));
//    }
//    QStringList dynamicPieceCopy = m_dynamicPiece;

//    //rotate copy of piece
//    QString color = dynamicPieceCopy.at(0);
//    dynamicPieceCopy.replace(0, dynamicPieceCopy.at(12));
//    dynamicPieceCopy.replace(12, dynamicPieceCopy.at(15));
//    dynamicPieceCopy.replace(15, dynamicPieceCopy.at(3));
//    dynamicPieceCopy.replace(3, color);

//    color = dynamicPieceCopy.at(1);
//    dynamicPieceCopy.replace(1, dynamicPieceCopy.at(8));
//    dynamicPieceCopy.replace(8, dynamicPieceCopy.at(14));
//    dynamicPieceCopy.replace(14, dynamicPieceCopy.at(7));
//    dynamicPieceCopy.replace(7, color);

//    color = dynamicPieceCopy.at(2);
//    dynamicPieceCopy.replace(2, dynamicPieceCopy.at(4));
//    dynamicPieceCopy.replace(4, dynamicPieceCopy.at(13));
//    dynamicPieceCopy.replace(13, dynamicPieceCopy.at(11));
//    dynamicPieceCopy.replace(11, color);

//    color = m_dynamicPiece.at(5);
//    dynamicPieceCopy.replace(5, dynamicPieceCopy.at(9));
//    dynamicPieceCopy.replace(9, dynamicPieceCopy.at(10));
//    dynamicPieceCopy.replace(10, dynamicPieceCopy.at(6));
//    dynamicPieceCopy.replace(6, color);

//    //store buys indexes of rotated piece
//    QVector <int> rotatedPieceIndexes;

//    //first column
//    if (dynamicPieceCopy.at(0)  != TRANSPARENT ||
//        dynamicPieceCopy.at(4)  != TRANSPARENT ||
//        dynamicPieceCopy.at(8)  != TRANSPARENT ||
//        dynamicPieceCopy.at(12) != TRANSPARENT)
//    {
//        rotatedPieceIndexes.push_back(0);
//        rotatedPieceIndexes.push_back(4);
//        rotatedPieceIndexes.push_back(8);
//        rotatedPieceIndexes.push_back(12);
//    }
//    //second column
//    if (dynamicPieceCopy.at(1)  != TRANSPARENT ||
//        dynamicPieceCopy.at(5)  != TRANSPARENT ||
//        dynamicPieceCopy.at(9)  != TRANSPARENT ||
//        dynamicPieceCopy.at(13) != TRANSPARENT)
//    {
//        rotatedPieceIndexes.push_back(1);
//        rotatedPieceIndexes.push_back(5);
//        rotatedPieceIndexes.push_back(9);
//        rotatedPieceIndexes.push_back(13);
//    }
//    //third column
//    if (dynamicPieceCopy.at(2)  != TRANSPARENT ||
//        dynamicPieceCopy.at(6)  != TRANSPARENT ||
//        dynamicPieceCopy.at(10) != TRANSPARENT ||
//        dynamicPieceCopy.at(14) != TRANSPARENT)
//    {
//        rotatedPieceIndexes.push_back(2);
//        rotatedPieceIndexes.push_back(6);
//        rotatedPieceIndexes.push_back(10);
//        rotatedPieceIndexes.push_back(14);
//    }
//    //fourth column
//    if (dynamicPieceCopy.at(3)  != TRANSPARENT ||
//        dynamicPieceCopy.at(7)  != TRANSPARENT ||
//        dynamicPieceCopy.at(11) != TRANSPARENT ||
//        dynamicPieceCopy.at(15) != TRANSPARENT)
//    {
//        rotatedPieceIndexes.push_back(3);
//        rotatedPieceIndexes.push_back(7);
//        rotatedPieceIndexes.push_back(11);
//        rotatedPieceIndexes.push_back(15);
//    }

//    //store rotated busy board indexes
//    QVector <int> rotatedPieceBoardIndexes;
//    for (int i = 0; i < rotatedPieceIndexes.size(); i++)
//    {
//        rotatedPieceBoardIndexes.push_back(getBoardIndexFromPieceIndex(rotatedPieceIndexes.at(i)));
//    }

//    //check for legal move
//    for (int i = 0; i < rotatedPieceBoardIndexes.size(); i++)
//    {
//        for (int j = 0; j < busyBoardIndexes.size(); j++)
//        {
//            if (busyBoardIndexes.at(j) == rotatedPieceBoardIndexes.at(i))
//            {
//                break;
//            }
//        }

    //    }
}
void CoreLogic::updateLeftOutOfBoardPieceIndexes()
{
    if ((getBoardIndexFromPieceIndex(0)+1) % TABLE_WIDTH == 0)
    {
        m_dynamicPiece.replace(0, OUT_OF_BOARD);
        m_dynamicPiece.replace(4, OUT_OF_BOARD);
        m_dynamicPiece.replace(8, OUT_OF_BOARD);
        m_dynamicPiece.replace(12, OUT_OF_BOARD);
    }
    else if ((getBoardIndexFromPieceIndex(1)+1) % TABLE_WIDTH == 0)
    {
        m_dynamicPiece.replace(0, OUT_OF_BOARD);
        m_dynamicPiece.replace(4, OUT_OF_BOARD);
        m_dynamicPiece.replace(8, OUT_OF_BOARD);
        m_dynamicPiece.replace(12, OUT_OF_BOARD);
        m_dynamicPiece.replace(1, OUT_OF_BOARD);
        m_dynamicPiece.replace(5, OUT_OF_BOARD);
        m_dynamicPiece.replace(9, OUT_OF_BOARD);
        m_dynamicPiece.replace(13, OUT_OF_BOARD);
    }
    else if ((getBoardIndexFromPieceIndex(2)+1) % TABLE_WIDTH == 0)
    {
        m_dynamicPiece.replace(0, OUT_OF_BOARD);
        m_dynamicPiece.replace(4, OUT_OF_BOARD);
        m_dynamicPiece.replace(8, OUT_OF_BOARD);
        m_dynamicPiece.replace(12, OUT_OF_BOARD);
        m_dynamicPiece.replace(1, OUT_OF_BOARD);
        m_dynamicPiece.replace(5, OUT_OF_BOARD);
        m_dynamicPiece.replace(9, OUT_OF_BOARD);
        m_dynamicPiece.replace(13, OUT_OF_BOARD);
        m_dynamicPiece.replace(2, OUT_OF_BOARD);
        m_dynamicPiece.replace(6, OUT_OF_BOARD);
        m_dynamicPiece.replace(10, OUT_OF_BOARD);
        m_dynamicPiece.replace(14, OUT_OF_BOARD);
    }
    else if ((getBoardIndexFromPieceIndex(3)+1) % TABLE_WIDTH == 0)
    {
        m_dynamicPiece.replace(0, OUT_OF_BOARD);
        m_dynamicPiece.replace(4, OUT_OF_BOARD);
        m_dynamicPiece.replace(8, OUT_OF_BOARD);
        m_dynamicPiece.replace(12, OUT_OF_BOARD);
        m_dynamicPiece.replace(1, OUT_OF_BOARD);
        m_dynamicPiece.replace(5, OUT_OF_BOARD);
        m_dynamicPiece.replace(9, OUT_OF_BOARD);
        m_dynamicPiece.replace(13, OUT_OF_BOARD);
        m_dynamicPiece.replace(2, OUT_OF_BOARD);
        m_dynamicPiece.replace(6, OUT_OF_BOARD);
        m_dynamicPiece.replace(10, OUT_OF_BOARD);
        m_dynamicPiece.replace(14, OUT_OF_BOARD);
        m_dynamicPiece.replace(3, OUT_OF_BOARD);
        m_dynamicPiece.replace(7, OUT_OF_BOARD);
        m_dynamicPiece.replace(11, OUT_OF_BOARD);
        m_dynamicPiece.replace(15, OUT_OF_BOARD);
    }
    for (int i = 0; i < m_dynamicPiece.size(); i++)
    {
        qDebug () << m_dynamicPiece.at(i);
    }
    qDebug () << "---------";

}
void CoreLogic::updateRightOutOfBoardPieceIndexes()
{
    if ((getBoardIndexFromPieceIndex(3)) % TABLE_WIDTH == 0)
    {
        m_dynamicPiece.replace(3, OUT_OF_BOARD);
        m_dynamicPiece.replace(7, OUT_OF_BOARD);
        m_dynamicPiece.replace(11, OUT_OF_BOARD);
        m_dynamicPiece.replace(15, OUT_OF_BOARD);
    }
    else if ((getBoardIndexFromPieceIndex(2)) % TABLE_WIDTH == 0)
    {
        m_dynamicPiece.replace(3, OUT_OF_BOARD);
        m_dynamicPiece.replace(7, OUT_OF_BOARD);
        m_dynamicPiece.replace(11, OUT_OF_BOARD);
        m_dynamicPiece.replace(15, OUT_OF_BOARD);
        m_dynamicPiece.replace(2, OUT_OF_BOARD);
        m_dynamicPiece.replace(6, OUT_OF_BOARD);
        m_dynamicPiece.replace(10, OUT_OF_BOARD);
        m_dynamicPiece.replace(14, OUT_OF_BOARD);
    }
    else if ((getBoardIndexFromPieceIndex(1)) % TABLE_WIDTH == 0)
    {
        m_dynamicPiece.replace(3, OUT_OF_BOARD);
        m_dynamicPiece.replace(7, OUT_OF_BOARD);
        m_dynamicPiece.replace(11, OUT_OF_BOARD);
        m_dynamicPiece.replace(15, OUT_OF_BOARD);
        m_dynamicPiece.replace(2, OUT_OF_BOARD);
        m_dynamicPiece.replace(6, OUT_OF_BOARD);
        m_dynamicPiece.replace(10, OUT_OF_BOARD);
        m_dynamicPiece.replace(14, OUT_OF_BOARD);
        m_dynamicPiece.replace(1, OUT_OF_BOARD);
        m_dynamicPiece.replace(5, OUT_OF_BOARD);
        m_dynamicPiece.replace(9, OUT_OF_BOARD);
        m_dynamicPiece.replace(13, OUT_OF_BOARD);
    }
    else if ((getBoardIndexFromPieceIndex(0)) % TABLE_WIDTH == 0)
    {
        m_dynamicPiece.replace(3, OUT_OF_BOARD);
        m_dynamicPiece.replace(7, OUT_OF_BOARD);
        m_dynamicPiece.replace(11, OUT_OF_BOARD);
        m_dynamicPiece.replace(15, OUT_OF_BOARD);
        m_dynamicPiece.replace(2, OUT_OF_BOARD);
        m_dynamicPiece.replace(6, OUT_OF_BOARD);
        m_dynamicPiece.replace(10, OUT_OF_BOARD);
        m_dynamicPiece.replace(14, OUT_OF_BOARD);
        m_dynamicPiece.replace(1, OUT_OF_BOARD);
        m_dynamicPiece.replace(5, OUT_OF_BOARD);
        m_dynamicPiece.replace(9, OUT_OF_BOARD);
        m_dynamicPiece.replace(13, OUT_OF_BOARD);
        m_dynamicPiece.replace(0, OUT_OF_BOARD);
        m_dynamicPiece.replace(4, OUT_OF_BOARD);
        m_dynamicPiece.replace(8, OUT_OF_BOARD);
        m_dynamicPiece.replace(12, OUT_OF_BOARD);
    }
    for (int i = 0; i < m_dynamicPiece.size(); i++)
    {
        qDebug () << m_dynamicPiece.at(i);
    }
    qDebug () << "---------";
}
void CoreLogic::rotatePiece()
{
    QString color = m_dynamicPiece.at(0);
    m_dynamicPiece.replace(0, m_dynamicPiece.at(12));
    m_dynamicPiece.replace(12, m_dynamicPiece.at(15));
    m_dynamicPiece.replace(15, m_dynamicPiece.at(3));
    m_dynamicPiece.replace(3, color);

    color = m_dynamicPiece.at(1);
    m_dynamicPiece.replace(1, m_dynamicPiece.at(8));
    m_dynamicPiece.replace(8, m_dynamicPiece.at(14));
    m_dynamicPiece.replace(14, m_dynamicPiece.at(7));
    m_dynamicPiece.replace(7, color);

    color = m_dynamicPiece.at(2);
    m_dynamicPiece.replace(2, m_dynamicPiece.at(4));
    m_dynamicPiece.replace(4, m_dynamicPiece.at(13));
    m_dynamicPiece.replace(13, m_dynamicPiece.at(11));
    m_dynamicPiece.replace(11, color);

    color = m_dynamicPiece.at(5);
    m_dynamicPiece.replace(5, m_dynamicPiece.at(9));
    m_dynamicPiece.replace(9, m_dynamicPiece.at(10));
    m_dynamicPiece.replace(10, m_dynamicPiece.at(6));
    m_dynamicPiece.replace(6, color);

    emit dynamicPieceChanged();
}
void CoreLogic::movePieceDown()
{
    setPieceY(m_pieceY + 15);
}
void CoreLogic::movePieceRight()
{
    setPieceX(m_pieceX + 15);
    updateRightOutOfBoardPieceIndexes();
}
void CoreLogic::movePieceLeft()
{
    setPieceX(m_pieceX - 15);
    updateLeftOutOfBoardPieceIndexes();
}
void CoreLogic::resetPiece()
{
    setPieceX(180);
    setPieceY(0);
}
void CoreLogic::stopTimer()
{
    m_timer->stop();
}
void CoreLogic::startTimer()
{
    m_timer->start(m_moveDownVelocity);
}
void CoreLogic::gameRunning()
{
    movePieceDown();
}
CoreLogic::CoreLogic()
{
    init();
}
QStringList CoreLogic::board() const
{
    return m_board;
}
void CoreLogic::setBoard(const QStringList &board)
{
    if (board != m_board)
    {
        m_board = board;
        emit boardChanged();
    }
}
QStringList CoreLogic::dynamicPiece() const
{
    return m_dynamicPiece;
}
void CoreLogic::setDynamicPiece(QStringList piece)
{
    if (piece != m_dynamicPiece)
    {
        m_dynamicPiece = piece;
        emit dynamicPieceChanged();
    }
}
double CoreLogic::pieceX() const
{
    return m_pieceX;
}
void CoreLogic::setPieceX(double pieceX)
{
    if (pieceX != m_pieceX)
    {
        m_pieceX = pieceX;
        emit pieceXChanged();
    }
}
double CoreLogic::pieceY() const
{
    return m_pieceY;
}
void CoreLogic::setPieceY(double pieceY)
{
    if (pieceY != m_pieceY)
    {
        m_pieceY = pieceY;
        emit pieceYChanged();
    }
}
QString CoreLogic::pieceColor() const
{
    return m_pieceColor;
}
void CoreLogic::setPieceColor(QString color)
{
    if (color != m_pieceColor)
    {
        m_pieceColor = color;
        emit pieceColorChanged();
    }
}
