#ifndef KING_H
#define KING_H
#include "piece.h"
#include <QPair>
#include <QVector>
#include <QDebug>
#include "move.h"

class King: public Piece
{
public:
    King();
    ~King();
    QVector<Move > getPossibleMoves(int x, int y);
};

#endif // KING_H
