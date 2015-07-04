#ifndef BISHOP_H
#define BISHOP_H
#include "piece.h"
#include "move.h"

class Bishop: public Piece
{
public:
    Bishop();
    ~Bishop();
    QVector<Move > getPossibleMoves(int x, int y);
};

#endif // BISHOP_H
