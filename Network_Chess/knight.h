#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"
#include <QPair>
#include <QVector>
#include <QDebug>
#include "move.h"

class Knight: public Piece
{
public:
    Knight();
    ~Knight();
    QVector<Move > getPossibleMoves(int x, int y);
};

#endif // KNIGHT_H
