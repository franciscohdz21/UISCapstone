#ifndef CORELOGIC_H
#define CORELOGIC_H

#include <QObject>
#include <QThread>
#include <QStringList>
#include <QTimer>

class CoreLogic : public QTimer
{
    Q_OBJECT
    Q_PROPERTY(QStringList board READ board WRITE setBoard NOTIFY boardChanged)
    Q_PROPERTY(double pieceX READ pieceX WRITE setPieceX NOTIFY pieceXChanged)
    Q_PROPERTY(double pieceY READ pieceY WRITE setPieceY NOTIFY pieceYChanged)
    Q_PROPERTY(int pieceWidth READ pieceWidth WRITE setPieceWidth NOTIFY pieceWidthChanged)
    Q_PROPERTY(int pieceHeight READ pieceHeight WRITE setPieceHeight NOTIFY pieceHeightChanged)
public:
    ~CoreLogic();
    static CoreLogic &Instance();

    //Q_PROPERTIES
    QStringList board()const;
    void setBoard(const QStringList &board);
    double pieceX()const;
    void setPieceX(double pieceX);
    double pieceY()const;
    void setPieceY(double pieceY);
    int pieceWidth()const;
    void setPieceWidth(int pieceWidth);
    int pieceHeight()const;
    void setPieceHeight(int pieceHeight);

    //Other
    void init();
    Q_INVOKABLE int getBoardIndex(double x, double y);
    Q_INVOKABLE void setPieceAtBoard(int index, QString color);
    Q_INVOKABLE void checkForCompleteRow();

    //Bounds
    Q_INVOKABLE bool canMoveLeft();
    Q_INVOKABLE bool canMoveRight();
    Q_INVOKABLE bool canMoveDown();

    //Piece movement
    Q_INVOKABLE void movePieceDown();
    Q_INVOKABLE void movePieceRight();
    Q_INVOKABLE void movePieceLeft();
    Q_INVOKABLE void resetPiece();

    //Timer
    Q_INVOKABLE void startTimer();
    Q_INVOKABLE void stopTimer();

signals:
    void boardChanged();
    void pieceXChanged();
    void pieceYChanged();
    void pieceWidthChanged();
    void pieceHeightChanged();

public slots:
    void gameRunning();


private:
    CoreLogic();
    CoreLogic(CoreLogic const&)=delete;
    void operator = (CoreLogic const&)=delete;

    QStringList m_board;
    double m_pieceX;
    double m_pieceY;
    QTimer *m_timer;
    int m_moveDownVelocity;
    int m_pieceWidth;
    int m_pieceHeight;
};

#endif // CORELOGIC_H
