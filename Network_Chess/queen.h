#ifndef QUEEN_H
#define QUEEN_H
#include "piece.h"
#include <QPair>
#include <QVector>
#include <QDebug>
#include "move.h"

class Queen: public Piece
{
public:
    Queen();
    ~Queen();
    QVector<Move > getPossibleMoves(int x, int y);
};

#endif // QUEEN_H
