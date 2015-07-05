#include "king.h"

King::King()
{
}

King::~King()
{
}

/*
 * Generates all possible moves for the piece
 */
QVector<Move > King::getPossibleMoves(int x, int y)
{
    qDebug() << "King getPossibleMoves!!!!";
    QVector<Move> a;
    a.push_back(Move(x, y+1, false, false));
    a.push_back(Move(x, y-1, false, false));
    a.push_back(Move(x+1, y, false, false));
    a.push_back(Move(x-1, y, false, false));
    a.push_back(Move(x+1, y+1, false, false));
    a.push_back(Move(x+1, y-1, false, false));
    a.push_back(Move(x-1, y+1, false, false));
    a.push_back(Move(x-1, y-1, false, false));
    return a;
}

