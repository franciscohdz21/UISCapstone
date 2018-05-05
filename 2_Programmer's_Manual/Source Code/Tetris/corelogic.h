#ifndef CORELOGIC_H
#define CORELOGIC_H

#include <QObject>
#include <QThread>
#include <QStringList>
#include <QTimer>
#include <QVector>

class CoreLogic : public QTimer
{
    //Macro needed for Q Objects
    Q_OBJECT
    //Data container that saves the board
    Q_PROPERTY(QStringList board READ board WRITE setBoard NOTIFY boardChanged)
    //Data container that saves the moving shape
    Q_PROPERTY(QStringList dynamicPiece READ dynamicPiece WRITE setDynamicPiece NOTIFY dynamicPieceChanged)
    //X position of shape
    Q_PROPERTY(double pieceX READ pieceX WRITE setPieceX NOTIFY pieceXChanged)
    //Y position of shape
    Q_PROPERTY(double pieceY READ pieceY WRITE setPieceY NOTIFY pieceYChanged)
    //Game level difficulty
    Q_PROPERTY(int gameLevel READ gameLevel WRITE setGameLevel NOTIFY gameLevelChanged)
    //Boolean holding wether the shape has moved once - for game over purposes
    Q_PROPERTY(bool dynamicPieceMovedDownOnce READ dynamicPieceMovedDownOnce WRITE setDynamicPieceMovedDownOnce NOTIFY dynamicPieceMovedDownOnceChanged)
    //Game over boolean
    Q_PROPERTY(bool gameOver READ gameOver WRITE setGameOver NOTIFY gameOverChanged)
    //Score of the game
    Q_PROPERTY(int score READ score WRITE setScore NOTIFY scoreChanged)

public:
    ~CoreLogic();
    static CoreLogic &Instance();

    /*
     * Q Properties
     * Qt provides a sophisticated property system similar to the ones supplied by some compiler vendors.
     * However, as a compiler- and platform-independent library,
     * Qt does not rely on non-standard compiler features like __property or [property].
     * Source: http://doc.qt.io/qt-5/properties.html
     */
    QStringList board()const;
    void setBoard(const QStringList &board);
    QStringList dynamicPiece()const;
    void setDynamicPiece(QStringList piece);
    double pieceX()const;
    void setPieceX(double pieceX);
    double pieceY()const;
    void setPieceY(double pieceY);
    int gameLevel()const;
    void setGameLevel(int level);
    bool dynamicPieceMovedDownOnce()const;
    void setDynamicPieceMovedDownOnce(bool trueOrFalse);
    bool gameOver()const;
    void setGameOver(bool trueOrFalse);
    int score()const;
    void setScore(int score);

    /*
     * Misc functionality functions
     */

    //Initiliazes necessary logic of application
    void init();

    //Builds easy, medium, and hard shapes
    void buildPieces();
    void buildEasyPieces();
    void buildMediumPieces();
    void buildHardPieces();

    //Returns board index given x and y coordinates
    Q_INVOKABLE int getBoardIndex(double x, double y);

    //Returns board index when given a specific index of the moving shape
    int getBoardIndexFromPieceIndex(int pieceIndex);

    //Sets the moving piece at the board
    Q_INVOKABLE void setPieceAtBoard();

    //Checks if a row was complete and clears it if did
    Q_INVOKABLE void checkForCompleteRow();

    //Generates a new shape to move down
    void loadNewPiece();

    //Random number helper function
    int getRandomNumber(int range);

    //Reset necessary variables to reset game
    Q_INVOKABLE void resetGame();

    //Reset board to initial state
    void resetBoard();

    /*
     * Color related functions
     */

    //Colors that will be used
    QStringList listOfColors();

    //Return random color
    Q_INVOKABLE QString getRandomColor();

    /*
     * Bounds related functions
     */

    //Container with down most indexes of color squares in dynamic shape
    QVector <int> downMostPiecesIndexes()const;
    void setDownMostPiecesIndexes();

    //Container with left most indexes of color squares in dynamic shape
    QVector <int> leftMostPiecesIndexes()const;
    void setLeftMostPiecesIndexes();

    //Container with right most indexes of color squares in dynamic shape
    QVector <int> rightMostPiecesIndexes()const;
    void setRightMostPiecesIndexes();

    //Booleans to check if left, right or down movement is allowed.
    Q_INVOKABLE bool canMoveLeft();
    Q_INVOKABLE bool canMoveRight();
    Q_INVOKABLE bool canMoveDown();
    Q_INVOKABLE bool canRotate();

    //Update out of board indexes of dynamic shape
    void updateLeftOutOfBoardPieceIndexes();
    void updateRightOutOfBoardPieceIndexes();

    //Piece movement
    Q_INVOKABLE void rotatePiece();
    Q_INVOKABLE void movePieceDown();
    Q_INVOKABLE void movePieceRight();
    Q_INVOKABLE void movePieceLeft();
    Q_INVOKABLE void resetPiece();

    //Timer
    Q_INVOKABLE void startTimer();
    Q_INVOKABLE void stopTimer();
    Q_INVOKABLE bool timerIsRunning();

    /*
     * Signals emmited to update Q Properties
     */
signals:
    void boardChanged();
    void pieceXChanged();
    void pieceYChanged();
    void dynamicPieceChanged();
    void gameLevelChanged();
    void dynamicPieceMovedDownOnceChanged();
    void gameOverChanged();
    void scoreChanged();

    /*
     * Slots - From Qt signal and slot system
     */
public slots:
    void gameRunning();

private:
    CoreLogic();
    CoreLogic(CoreLogic const&)=delete;
    void operator = (CoreLogic const&)=delete;

    //Q Properties
    QStringList m_board;
    QStringList m_dynamicPiece;
    double m_pieceX;
    double m_pieceY;
    int m_gameLevel;
    bool m_dynamicPieceMovedDownOnce;
    bool m_gameOver;
    int m_score;

    //Other
    QTimer *m_timer;
    int m_moveDownVelocity;
    int m_currentPiece;
    QStringList m_listOfColors;
    QVector <int> m_downMostPiecesIndexes;
    QVector <int> m_leftMostPiecesIndexes;
    QVector <int> m_rightMostPiecesIndexes;
    QVector <int> m_pieceIndexesInsideBoard;
    int m_dynamicPieceBoardState;
    QVector <QStringList> m_easyPieces;
    QVector <QStringList>  m_mediumPieces;
    QVector <QStringList> m_hardPieces;
};

#endif // CORELOGIC_H
