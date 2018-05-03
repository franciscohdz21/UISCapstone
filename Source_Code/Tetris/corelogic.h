#ifndef CORELOGIC_H
#define CORELOGIC_H

#include <QObject>
#include <QThread>
#include <QStringList>
#include <QTimer>
#include <QVector>

class CoreLogic : public QTimer
{
    Q_OBJECT
    Q_PROPERTY(QStringList board READ board WRITE setBoard NOTIFY boardChanged)
    Q_PROPERTY(QStringList dynamicPiece READ dynamicPiece WRITE setDynamicPiece NOTIFY dynamicPieceChanged)
    Q_PROPERTY(double pieceX READ pieceX WRITE setPieceX NOTIFY pieceXChanged)
    Q_PROPERTY(double pieceY READ pieceY WRITE setPieceY NOTIFY pieceYChanged)
    Q_PROPERTY(int gameLevel READ gameLevel WRITE setGameLevel NOTIFY gameLevelChanged)
    Q_PROPERTY(bool dynamicPieceMovedDownOnce READ dynamicPieceMovedDownOnce WRITE setDynamicPieceMovedDownOnce NOTIFY dynamicPieceMovedDownOnceChanged)
    Q_PROPERTY(bool gameOver READ gameOver WRITE setGameOver NOTIFY gameOverChanged)
    Q_PROPERTY(int score READ score WRITE setScore NOTIFY scoreChanged)

public:
    ~CoreLogic();
    static CoreLogic &Instance();

    //Q_PROPERTIES
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

    //Other
    void init();
    void buildPieces();
    void buildEasyPieces();
    void buildMediumPieces();
    void buildHardPieces();
    Q_INVOKABLE int getBoardIndex(double x, double y);
    int getBoardIndexFromPieceIndex(int pieceIndex);
    Q_INVOKABLE void setPieceAtBoard();
    Q_INVOKABLE void checkForCompleteRow();
    Q_INVOKABLE int getCurrentPiece()const;
    Q_INVOKABLE void setCurrentPiece(int piece);
    void loadNewPiece();
    int getRandomNumber(int range);
    Q_INVOKABLE void resetGame();
    void resetBoard();

    //Color
    QStringList listOfColors();
    Q_INVOKABLE QString getRandomColor();

    //Bounds
    QVector <int> downMostPiecesIndexes()const;
    void setDownMostPiecesIndexes();
    QVector <int> leftMostPiecesIndexes()const;
    void setLeftMostPiecesIndexes();
    QVector <int> rightMostPiecesIndexes()const;
    void setRightMostPiecesIndexes();
    Q_INVOKABLE bool canMoveLeft();
    Q_INVOKABLE bool canMoveRight();
    Q_INVOKABLE bool canMoveDown();
    Q_INVOKABLE bool canRotate();
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



signals:
    void boardChanged();
    void pieceXChanged();
    void pieceYChanged();
    void dynamicPieceChanged();
    void gameLevelChanged();
    void dynamicPieceMovedDownOnceChanged();
    void gameOverChanged();
    void scoreChanged();

public slots:
    void gameRunning();


private:
    CoreLogic();
    CoreLogic(CoreLogic const&)=delete;
    void operator = (CoreLogic const&)=delete;

    QStringList m_board;
    QStringList m_dynamicPiece;
    double m_pieceX;
    double m_pieceY;
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
    int m_gameLevel;
    bool m_dynamicPieceMovedDownOnce;
    bool m_gameOver;
    int m_score;
};

#endif // CORELOGIC_H
