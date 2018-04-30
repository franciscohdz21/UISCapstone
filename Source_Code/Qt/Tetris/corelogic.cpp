#include <QDebug>
#include <QString>
#include <QStringList>
#include <QVector>
#include <QTimer>
#include <cstdlib>
#include <ctime>
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
#define WHITE        "#ffffff"
#define TRANSPARENT  "transparent"
#define OUT_OF_BOARD "OUT OF BOARD"
#define COLOR        "color"


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
    setScore(0);
    setDynamicPieceMovedDownOnce(false);
    m_dynamicPieceBoardState = -1;
    m_gameOver = false;

    //add colors
    m_listOfColors.push_back(BROWN);
    m_listOfColors.push_back(YELLOW);
    m_listOfColors.push_back(LIGHT_BLUE);
    m_listOfColors.push_back(DARK_BLUE);
    m_listOfColors.push_back(PURPLE);
    m_listOfColors.push_back(PINK);
    m_listOfColors.push_back(RED);
    m_listOfColors.push_back(GREY);
    m_listOfColors.push_back(WHITE);

    //set game level
    m_gameLevel = 1;
    if (m_gameLevel == 1)
        m_moveDownVelocity = 1000;
    else if (m_gameLevel == 2)
        m_moveDownVelocity = 500;
    else if (m_gameLevel == 3)
        m_moveDownVelocity = 250;

    //build and load pieces
    buildPieces();
    loadNewPiece();

    //init timer
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(gameRunning()));

    //set piece
    setPieceX(180);
    setPieceY(0);

    //build board
    resetBoard();
    emit boardChanged();
}
void CoreLogic::buildPieces()
{
    //clear
    m_easyPieces.clear();
    m_mediumPieces.clear();
    m_hardPieces.clear();

    //build
    buildEasyPieces();
    buildMediumPieces();
    buildHardPieces();

    //add easy pieces to medium pieces
    for (int i = 0; i < m_easyPieces.size(); i++)
    {
        m_mediumPieces.push_back(m_easyPieces.at(i));
    }

    //add medium pieces to hard pieces
    for (int i = 0; i < m_mediumPieces.size(); i++)
    {
        m_hardPieces.push_back(m_mediumPieces.at(i));
    }
}
void CoreLogic::buildEasyPieces()
{
    //piece 1
    QStringList piece;
    piece.push_back(COLOR);
    piece.push_back(COLOR);
    piece.push_back(COLOR);
    piece.push_back(COLOR);

    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);

    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);

    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);

    m_easyPieces.push_back(piece);
    piece.clear();

    //piece 2
    piece.push_back(COLOR);
    piece.push_back(COLOR);
    piece.push_back(COLOR);
    piece.push_back(TRANSPARENT);

    piece.push_back(TRANSPARENT);
    piece.push_back(COLOR);
    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);

    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);

    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);

    m_easyPieces.push_back(piece);
    piece.clear();

    //piece 3
    piece.push_back(COLOR);
    piece.push_back(COLOR);
    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);

    piece.push_back(COLOR);
    piece.push_back(COLOR);
    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);

    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);

    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);

    m_easyPieces.push_back(piece);
    piece.clear();

    //piece 4
    piece.push_back(COLOR);
    piece.push_back(COLOR);
    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);

    piece.push_back(TRANSPARENT);
    piece.push_back(COLOR);
    piece.push_back(COLOR);
    piece.push_back(TRANSPARENT);

    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);

    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);

    m_easyPieces.push_back(piece);
    piece.clear();

    //piece 5
    piece.push_back(COLOR);
    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);

    piece.push_back(COLOR);
    piece.push_back(COLOR);
    piece.push_back(COLOR);
    piece.push_back(TRANSPARENT);

    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);

    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);

    m_easyPieces.push_back(piece);
    piece.clear();
}
void CoreLogic::buildMediumPieces()
{
    //piece 1
    QStringList piece;
    piece.push_back(TRANSPARENT);
    piece.push_back(COLOR);
    piece.push_back(COLOR);
    piece.push_back(TRANSPARENT);

    piece.push_back(COLOR);
    piece.push_back(COLOR);
    piece.push_back(COLOR);
    piece.push_back(COLOR);

    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);

    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);

    m_mediumPieces.push_back(piece);
    piece.clear();

    //piece 2
    piece.push_back(COLOR);
    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);

    piece.push_back(COLOR);
    piece.push_back(COLOR);
    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);

    piece.push_back(TRANSPARENT);
    piece.push_back(COLOR);
    piece.push_back(COLOR);
    piece.push_back(TRANSPARENT);

    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);

    m_mediumPieces.push_back(piece);
    piece.clear();

    //piece 3
    piece.push_back(COLOR);
    piece.push_back(COLOR);
    piece.push_back(COLOR);
    piece.push_back(TRANSPARENT);

    piece.push_back(COLOR);
    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);

    piece.push_back(COLOR);
    piece.push_back(COLOR);
    piece.push_back(COLOR);
    piece.push_back(TRANSPARENT);

    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);

    m_mediumPieces.push_back(piece);
    piece.clear();

    //piece 4
    piece.push_back(COLOR);
    piece.push_back(COLOR);
    piece.push_back(COLOR);
    piece.push_back(TRANSPARENT);

    piece.push_back(TRANSPARENT);
    piece.push_back(COLOR);
    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);

    piece.push_back(COLOR);
    piece.push_back(COLOR);
    piece.push_back(COLOR);
    piece.push_back(TRANSPARENT);

    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);

    m_mediumPieces.push_back(piece);
    piece.clear();
}
void CoreLogic::buildHardPieces()
{
    //piece 1
    QStringList piece;
    piece.push_back(COLOR);
    piece.push_back(COLOR);
    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);

    piece.push_back(TRANSPARENT);
    piece.push_back(COLOR);
    piece.push_back(COLOR);
    piece.push_back(TRANSPARENT);

    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);
    piece.push_back(COLOR);
    piece.push_back(COLOR);

    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);
    piece.push_back(COLOR);

    m_hardPieces.push_back(piece);
    piece.clear();

    //piece 2
    piece.push_back(COLOR);
    piece.push_back(COLOR);
    piece.push_back(COLOR);
    piece.push_back(COLOR);

    piece.push_back(TRANSPARENT);
    piece.push_back(COLOR);
    piece.push_back(COLOR);
    piece.push_back(TRANSPARENT);

    piece.push_back(TRANSPARENT);
    piece.push_back(COLOR);
    piece.push_back(COLOR);
    piece.push_back(TRANSPARENT);

    piece.push_back(COLOR);
    piece.push_back(COLOR);
    piece.push_back(COLOR);
    piece.push_back(COLOR);

    m_hardPieces.push_back(piece);
    piece.clear();

    //piece 3
    piece.push_back(COLOR);
    piece.push_back(COLOR);
    piece.push_back(COLOR);
    piece.push_back(COLOR);

    piece.push_back(COLOR);
    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);

    piece.push_back(COLOR);
    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);

    piece.push_back(COLOR);
    piece.push_back(COLOR);
    piece.push_back(COLOR);
    piece.push_back(COLOR);

    m_hardPieces.push_back(piece);
    piece.clear();

    //piece 4
    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);
    piece.push_back(COLOR);
    piece.push_back(COLOR);

    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);
    piece.push_back(COLOR);
    piece.push_back(TRANSPARENT);

    piece.push_back(TRANSPARENT);
    piece.push_back(COLOR);
    piece.push_back(COLOR);
    piece.push_back(COLOR);

    piece.push_back(COLOR);
    piece.push_back(COLOR);
    piece.push_back(TRANSPARENT);
    piece.push_back(TRANSPARENT);

    m_hardPieces.push_back(piece);
    piece.clear();
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
    else
        return -1;
}
void CoreLogic::setPieceAtBoard()
{
    for (int i = 0; i < m_dynamicPiece.size(); i++)
    {
        if (m_dynamicPiece.at(i) != TRANSPARENT && m_dynamicPiece.at(i) != OUT_OF_BOARD)
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
            //break if non-black square is found
            if (m_board.at((i*26)+j) == BLACK)
            {
                break;
            }
            //otherwise, row is complete
            if (j == 25)
            {
                //increment score
                if (m_gameLevel == 1)
                    setScore(m_score + 10);
                else if (m_gameLevel == 2)
                    setScore(m_score + 50);
                else if (m_gameLevel == 3)
                    setScore(m_score + 150);

                //Paint entire row back to black
                for (int k = 0; k < TABLE_WIDTH; k++)
                {
                    m_board.replace(((i*26)+k), BLACK);
                }
                //Move rows down 1
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
    //update board
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
void CoreLogic::loadNewPiece()
{
    //get piece according to level
    if (m_gameLevel == 1)
        m_dynamicPiece = m_easyPieces.at(getRandomNumber(4));

    else if (m_gameLevel == 2)
        m_dynamicPiece = m_mediumPieces.at(getRandomNumber(8));

    else if (m_gameLevel == 3)
        m_dynamicPiece = m_hardPieces.at(getRandomNumber(7));

    //fill color
    for (int i = 0; i < m_dynamicPiece.size(); i++)
    {
        if (m_dynamicPiece.at(i) == "color")
            m_dynamicPiece.replace(i, getRandomColor());
    }
    emit dynamicPieceChanged();
}
int CoreLogic::getRandomNumber(int range)
{
    int randomNumber;
    srand(time(NULL));
    randomNumber = rand()% range;
    return randomNumber;
}
void CoreLogic::resetGame()
{
    resetPiece();
    resetBoard();
}
void CoreLogic::resetBoard()
{
    m_board.clear();
    for (auto i = 0; i < (TABLE_HEIGHT*TABLE_WIDTH); i++)
    {
        m_board.push_back(BLACK);
    }
    emit boardChanged();
}
QStringList CoreLogic::listOfColors()
{
    return m_listOfColors;
}
QString CoreLogic::getRandomColor()
{
    return m_listOfColors.at(getRandomNumber(8));
}
QVector<int> CoreLogic::downMostPiecesIndexes() const
{
    return m_downMostPiecesIndexes;
}
void CoreLogic::setDownMostPiecesIndexes()
{
    m_downMostPiecesIndexes.clear();
    //column 1
    for (int i = 12; i >= 0; i=i-4)
    {
        if (m_dynamicPiece.at(i) != TRANSPARENT &&  m_dynamicPiece.at(i) != OUT_OF_BOARD)
        {
            m_downMostPiecesIndexes.push_back(i);
            break;
        }
    }

    //column 2
    for (int i = 13; i >= 1; i=i-4)
    {
        if (m_dynamicPiece.at(i) != TRANSPARENT &&  m_dynamicPiece.at(i) != OUT_OF_BOARD)
        {
            m_downMostPiecesIndexes.push_back(i);
            break;
        }
    }

    //column 3
    for (int i = 14; i >= 2; i=i-4)
    {
        if (m_dynamicPiece.at(i) != TRANSPARENT &&  m_dynamicPiece.at(i) != OUT_OF_BOARD)
        {
            m_downMostPiecesIndexes.push_back(i);
            break;
        }
    }

    //column 4
    for (int i = 15; i >= 3; i=i-4)
    {
        if (m_dynamicPiece.at(i) != TRANSPARENT &&  m_dynamicPiece.at(i) != OUT_OF_BOARD)
        {
            m_downMostPiecesIndexes.push_back(i);
            break;
        }
    }
}
QVector<int> CoreLogic::leftMostPiecesIndexes() const
{
    return m_leftMostPiecesIndexes;
}
void CoreLogic::setLeftMostPiecesIndexes()
{
    m_leftMostPiecesIndexes.clear();
    //row 1
    for (int i = 0; i <= 3; i++)
    {
        if (m_dynamicPiece.at(i) != TRANSPARENT &&  m_dynamicPiece.at(i) != OUT_OF_BOARD)
        {
            m_leftMostPiecesIndexes.push_back(i);
            break;
        }
    }

    //row 2
    for (int i = 4; i <= 7; i++)
    {
        if (m_dynamicPiece.at(i) != TRANSPARENT &&  m_dynamicPiece.at(i) != OUT_OF_BOARD)
        {
            m_leftMostPiecesIndexes.push_back(i);
            break;
        }
    }

    //row 3
    for (int i = 8; i <= 11; i++)
    {
        if (m_dynamicPiece.at(i) != TRANSPARENT &&  m_dynamicPiece.at(i) != OUT_OF_BOARD)
        {
            m_leftMostPiecesIndexes.push_back(i);
            break;
        }
    }

    //row 4
    for (int i = 12; i <= 15; i++)
    {
        if (m_dynamicPiece.at(i) != TRANSPARENT &&  m_dynamicPiece.at(i) != OUT_OF_BOARD)
        {
            m_leftMostPiecesIndexes.push_back(i);
            break;
        }
    }
}
QVector<int> CoreLogic::rightMostPiecesIndexes() const
{
    return m_rightMostPiecesIndexes;
}
void CoreLogic::setRightMostPiecesIndexes()
{
    m_rightMostPiecesIndexes.clear();
    //row 1
    for (int i = 3; i >= 0; i--)
    {
        if (m_dynamicPiece.at(i) != TRANSPARENT &&  m_dynamicPiece.at(i) != OUT_OF_BOARD)
        {
            m_rightMostPiecesIndexes.push_back(i);
            break;
        }
    }

    //row 2
    for (int i = 7; i >= 4; i--)
    {
        if (m_dynamicPiece.at(i) != TRANSPARENT &&  m_dynamicPiece.at(i) != OUT_OF_BOARD)
        {
            m_rightMostPiecesIndexes.push_back(i);
            break;
        }
    }

    //row 3
    for (int i = 11; i >= 8; i--)
    {
        if (m_dynamicPiece.at(i) != TRANSPARENT &&  m_dynamicPiece.at(i) != OUT_OF_BOARD)
        {
            m_rightMostPiecesIndexes.push_back(i);
            break;
        }
    }

    //row 4
    for (int i = 15; i >= 12; i--)
    {
        if (m_dynamicPiece.at(i) != TRANSPARENT &&  m_dynamicPiece.at(i) != OUT_OF_BOARD)
        {
            m_rightMostPiecesIndexes.push_back(i);
            break;
        }
    }
}
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
        else if (m_board.at(getBoardIndexFromPieceIndex(m_rightMostPiecesIndexes.at(i)) + 1) != BLACK)
        {
            return false;
        }
    }
    return true;
}
bool CoreLogic::canMoveDown()
{
    setDownMostPiecesIndexes();  
    //check bouds
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
    //can't rotate when out of bounds
    if (m_dynamicPieceBoardState != -1)
        return false;
    //check for empty spot after rotation
    else
    {
        for (int i = 0; i < m_dynamicPiece.size(); i++)
        {
            if (m_dynamicPiece.at(i) != TRANSPARENT && m_dynamicPiece.at(i) != OUT_OF_BOARD)
            {
                switch(i)
                {
                case 0 :
                {
                    if (m_board.at(getBoardIndexFromPieceIndex(3)) != BLACK)
                        return false;
                    break;
                }
                case 1 :
                {
                    if (m_board.at(getBoardIndexFromPieceIndex(7)) != BLACK)
                        return false;
                    break;
                }
                case 2 :
                {
                    if (m_board.at(getBoardIndexFromPieceIndex(11)) != BLACK)
                        return false;
                    break;
                }
                case 3 :
                {
                    if (m_board.at(getBoardIndexFromPieceIndex(15)) != BLACK)
                        return false;
                    break;
                }
                case 4 :
                {
                    if (m_board.at(getBoardIndexFromPieceIndex(2)) != BLACK)
                        return false;
                    break;
                }
                case 5 :
                {
                    if (m_board.at(getBoardIndexFromPieceIndex(6)) != BLACK)
                        return false;
                    break;
                }
                case 6 :
                {
                    if (m_board.at(getBoardIndexFromPieceIndex(10)) != BLACK)
                        return false;
                    break;
                }
                case 7 :
                {
                    if (m_board.at(getBoardIndexFromPieceIndex(14)) != BLACK)
                        return false;
                    break;
                }
                case 8 :
                {
                    if (m_board.at(getBoardIndexFromPieceIndex(1)) != BLACK)
                        return false;
                    break;
                }
                case 9 :
                {
                    if (m_board.at(getBoardIndexFromPieceIndex(5)) != BLACK)
                        return false;
                    break;
                }
                case 10 :
                {
                    if (m_board.at(getBoardIndexFromPieceIndex(9)) != BLACK)
                        return false;
                    break;
                }
                case 11 :
                {
                    if (m_board.at(getBoardIndexFromPieceIndex(13)) != BLACK)
                        return false;
                    break;
                }
                case 12 :
                {
                    if (m_board.at(getBoardIndexFromPieceIndex(0)) != BLACK)
                        return false;
                    break;
                }
                case 13 :
                {
                    if (m_board.at(getBoardIndexFromPieceIndex(4)) != BLACK)
                        return false;
                    break;
                }
                case 14 :
                {
                    if (m_board.at(getBoardIndexFromPieceIndex(8)) != BLACK)
                        return false;
                    break;
                }
                case 15 :
                {
                    if (m_board.at(getBoardIndexFromPieceIndex(12)) != BLACK)
                        return false;
                    break;
                }
                }
            }
        }
        return true;
    }
}
void CoreLogic::updateLeftOutOfBoardPieceIndexes()
{
    for (int i = 0; i < m_dynamicPiece.size(); i++)
    {
        if (m_dynamicPiece.at(i) == OUT_OF_BOARD)
        {
            m_dynamicPiece.replace(i, TRANSPARENT);
        }
    }
    if ((getBoardIndexFromPieceIndex(0)+1) % TABLE_WIDTH == 0)
    {
        m_dynamicPiece.replace(0, OUT_OF_BOARD);
        m_dynamicPiece.replace(4, OUT_OF_BOARD);
        m_dynamicPiece.replace(8, OUT_OF_BOARD);
        m_dynamicPiece.replace(12, OUT_OF_BOARD);
        m_dynamicPieceBoardState = 3;
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
        m_dynamicPieceBoardState = 2;
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
        m_dynamicPieceBoardState = 1;
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
        m_dynamicPieceBoardState = 0;
    }
    else
    {
        m_dynamicPieceBoardState = -1;
        for (int i = 0; i < m_dynamicPiece.size(); i++)
        {
            if (m_dynamicPiece.at(i) == OUT_OF_BOARD)
            {
                m_dynamicPiece.replace(i, TRANSPARENT);
            }
        }
    }
    for (int i = 0; i < m_dynamicPiece.size(); i++)
    {
        qDebug () << m_dynamicPiece.at(i);
    }
    qDebug () << "---------";

}
void CoreLogic::updateRightOutOfBoardPieceIndexes()
{
    for (int i = 0; i < m_dynamicPiece.size(); i++)
    {
        if (m_dynamicPiece.at(i) == OUT_OF_BOARD)
        {
            m_dynamicPiece.replace(i, TRANSPARENT);
        }
    }
    if (getBoardIndexFromPieceIndex(3) % TABLE_WIDTH == 0)
    {
        m_dynamicPiece.replace(3, OUT_OF_BOARD);
        m_dynamicPiece.replace(7, OUT_OF_BOARD);
        m_dynamicPiece.replace(11, OUT_OF_BOARD);
        m_dynamicPiece.replace(15, OUT_OF_BOARD);
        m_dynamicPieceBoardState = 4;
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
        m_dynamicPieceBoardState = 5;
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
        m_dynamicPieceBoardState = 6;
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
        m_dynamicPieceBoardState = 7;
    }
    else
    {
        m_dynamicPieceBoardState = -1;
        for (int i = 0; i < m_dynamicPiece.size(); i++)
        {
            if (m_dynamicPiece.at(i) == OUT_OF_BOARD)
            {
                m_dynamicPiece.replace(i, TRANSPARENT);
            }
        }
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

    setLeftMostPiecesIndexes();
    setRightMostPiecesIndexes();
    setDownMostPiecesIndexes();

    emit dynamicPieceChanged();
}
void CoreLogic::movePieceDown()
{
    setPieceY(m_pieceY + 15);
    setDynamicPieceMovedDownOnce(true);
}
void CoreLogic::movePieceRight()
{
    setPieceX(m_pieceX + 15);
    if (m_dynamicPieceBoardState == -1 || m_dynamicPieceBoardState > 3)
    {
        updateRightOutOfBoardPieceIndexes();
    }
    else if (m_dynamicPieceBoardState == 2)
    {
        if (m_dynamicPiece.at(2) == OUT_OF_BOARD)
            m_dynamicPiece.replace(2, TRANSPARENT);
        if (m_dynamicPiece.at(6) == OUT_OF_BOARD)
            m_dynamicPiece.replace(6, TRANSPARENT);
        if (m_dynamicPiece.at(10) == OUT_OF_BOARD)
            m_dynamicPiece.replace(10, TRANSPARENT);
        if (m_dynamicPiece.at(14) == OUT_OF_BOARD)
            m_dynamicPiece.replace(14, TRANSPARENT);
        m_dynamicPieceBoardState = 3;
    }
    else if (m_dynamicPieceBoardState == 3)
    {
        if (m_dynamicPiece.at(1) == OUT_OF_BOARD)
            m_dynamicPiece.replace(1, TRANSPARENT);
        if (m_dynamicPiece.at(5) == OUT_OF_BOARD)
            m_dynamicPiece.replace(5, TRANSPARENT);
        if (m_dynamicPiece.at(9) == OUT_OF_BOARD)
            m_dynamicPiece.replace(9, TRANSPARENT);
        if (m_dynamicPiece.at(13) == OUT_OF_BOARD)
            m_dynamicPiece.replace(13, TRANSPARENT);
        m_dynamicPieceBoardState = -1;
    }
    emit dynamicPieceChanged();
}
void CoreLogic::movePieceLeft()
{
    setPieceX(m_pieceX - 15);
    if (m_dynamicPieceBoardState == -1 || m_dynamicPieceBoardState < 4)
    {
        updateLeftOutOfBoardPieceIndexes();
    }
    else if (m_dynamicPieceBoardState == 5)
    {
        if (m_dynamicPiece.at(1) == OUT_OF_BOARD)
            m_dynamicPiece.replace(1, TRANSPARENT);
        if (m_dynamicPiece.at(5) == OUT_OF_BOARD)
            m_dynamicPiece.replace(5, TRANSPARENT);
        if (m_dynamicPiece.at(9) == OUT_OF_BOARD)
            m_dynamicPiece.replace(9, TRANSPARENT);
        if (m_dynamicPiece.at(13) == OUT_OF_BOARD)
            m_dynamicPiece.replace(13, TRANSPARENT);
        m_dynamicPieceBoardState = 4;
    }
    else if (m_dynamicPieceBoardState == 4)
    {
        if (m_dynamicPiece.at(2) == OUT_OF_BOARD)
            m_dynamicPiece.replace(2, TRANSPARENT);
        if (m_dynamicPiece.at(6) == OUT_OF_BOARD)
            m_dynamicPiece.replace(6, TRANSPARENT);
        if (m_dynamicPiece.at(10) == OUT_OF_BOARD)
            m_dynamicPiece.replace(10, TRANSPARENT);
        if (m_dynamicPiece.at(14) == OUT_OF_BOARD)
            m_dynamicPiece.replace(14, TRANSPARENT);
        m_dynamicPieceBoardState = -1;
    }
    emit dynamicPieceChanged();
}
void CoreLogic::resetPiece()
{
    //change piece
    loadNewPiece();
    emit dynamicPieceChanged();

    setPieceX(180);
    setPieceY(0);

    //check for game over
    if ((m_dynamicPieceMovedDownOnce == false) && (canMoveDown() == false))
    {
        stopTimer();
        setGameOver(true);
    }

    //increment score
    if (m_gameLevel == 1)
        setScore(m_score + 1);
    else if (m_gameLevel == 2)
        setScore(m_score + 5);
    else if (m_gameLevel == 3)
        setScore(m_score + 15);
}
void CoreLogic::stopTimer()
{
    m_timer->stop();
}
bool CoreLogic::timerIsRunning()
{
    return m_timer->isActive();
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
int CoreLogic::gameLevel() const
{
    return m_gameLevel;
}
void CoreLogic::setGameLevel(int level)
{
    if (level == 1)
        m_moveDownVelocity = 1000;
    else if (level == 2)
        m_moveDownVelocity = 500;
    else if (level == 3)
        m_moveDownVelocity = 250;
    if (level != m_gameLevel)
    {
        m_gameLevel = level;
        emit gameLevelChanged();
    }
}
bool CoreLogic::dynamicPieceMovedDownOnce() const
{
    return m_dynamicPieceMovedDownOnce;
}
void CoreLogic::setDynamicPieceMovedDownOnce(bool trueOrFalse)
{
    if (trueOrFalse != m_dynamicPieceMovedDownOnce)
    {
        m_dynamicPieceMovedDownOnce = trueOrFalse;
        emit dynamicPieceMovedDownOnceChanged();
    }
}
bool CoreLogic::gameOver() const
{
    return m_gameOver;
}
void CoreLogic::setGameOver(bool trueOrFalse)
{
    if (trueOrFalse != m_gameOver)
    {
        m_gameOver = trueOrFalse;
        emit gameOverChanged();
    }
}
int CoreLogic::score() const
{
    return m_score;
}
void CoreLogic::setScore(int score)
{
    if (score != m_score)
    {
        m_score = score;
        emit scoreChanged();
    }
}
