#ifndef ROOK_H
#define ROOK_H
#include "piece.h"
#include <QPair>
#include <QVector>
#include <QDebug>
#include "move.h"

class Rook: public Piece
{
public:
    Rook();
    ~Rook();
    QVector<Move > getPossibleMoves(int x, int y);
};

#endif // ROOK_H
