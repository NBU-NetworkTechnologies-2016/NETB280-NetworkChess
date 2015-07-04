#ifndef WHITEPAWN_H
#define WHITEPAWN_H

#include "piece.h"
#include <QPair>
#include <QVector>
#include <QDebug>
#include "move.h"

class WhitePawn: public Piece
{
public:
    WhitePawn();
    ~WhitePawn();
    QVector<Move > getPossibleMoves(int x, int y);
};

#endif // WHITEPAWN_H
