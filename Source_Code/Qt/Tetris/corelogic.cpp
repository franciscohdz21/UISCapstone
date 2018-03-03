#include <QDebug>
#include <QString>
#include <QStringList>
#include <QTimer>
#include "corelogic.h"

#define TABLE_WIDTH 26
#define TABLE_HEIGHT 36
#define MIN_PIECE_LENGTH 15
#define BLACK "#000000"
#define GRID_WIDTH 390
#define GRID_HEIGHT 540

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
    m_moveDownVelocity = 1000;
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(gameRunning()));
    setPieceHeight(15);
    setPieceWidth(15);
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
    return (x/MIN_PIECE_LENGTH) + (y/MIN_PIECE_LENGTH * TABLE_WIDTH);
}
void CoreLogic::setPieceAtBoard(int index, QString color)
{
    m_board.replace(index, color);
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
bool CoreLogic::canMoveLeft()
{
    if (m_pieceX == 0)
        return false;
    else
        return true;
}
bool CoreLogic::canMoveRight()
{
    if (m_pieceX + m_pieceWidth == GRID_WIDTH)
        return false;
    else
        return true;
}
bool CoreLogic::canMoveDown()
{
    if (m_pieceY + m_pieceHeight == 540)
        return false;
    else if (m_board.value(getBoardIndex(m_pieceX, m_pieceY) + TABLE_WIDTH) != BLACK)
    {
        return false;
    }
    else
        return true;
}
void CoreLogic::movePieceDown()
{
    if (canMoveDown() == true)
        setPieceY(m_pieceY + MIN_PIECE_LENGTH);
}
void CoreLogic::movePieceRight()
{
    setPieceX(m_pieceX + MIN_PIECE_LENGTH);
}
void CoreLogic::movePieceLeft()
{
    setPieceX(m_pieceX - MIN_PIECE_LENGTH);
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
int CoreLogic::pieceWidth() const
{
    return m_pieceWidth;
}
void CoreLogic::setPieceWidth(int pieceWidth)
{
    if (pieceWidth != m_pieceWidth)
    {
        m_pieceWidth = pieceWidth;
        emit pieceWidthChanged();
    }
}
int CoreLogic::pieceHeight() const
{
    return m_pieceHeight;
}
void CoreLogic::setPieceHeight(int pieceHeight)
{
    if (pieceHeight != m_pieceHeight)
    {
        m_pieceHeight = pieceHeight;
        emit pieceHeightChanged();
    }
}
