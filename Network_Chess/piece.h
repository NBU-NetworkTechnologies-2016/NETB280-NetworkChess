#ifndef PIECE_H
#define PIECE_H

#include <QPair>
#include <QVector>
#include "move.h"
#include <QDebug>

class Piece
{
public:
     Piece();
     virtual QVector<Move > getPossibleMoves(int x, int y);
     ~Piece();
};

#endif // PIECE_H
