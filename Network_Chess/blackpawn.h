#ifndef BLACKPAWN_H
#define BLACKPAWN_H
#include "piece.h"
#include <QPair>
#include <QVector>
#include <QDebug>
#include "move.h"
class BlackPawn: public Piece
{
public:
    BlackPawn();
    ~BlackPawn();
    QVector<Move > getPossibleMoves(int x, int y);
};

#endif // BLACKPAWN_H
