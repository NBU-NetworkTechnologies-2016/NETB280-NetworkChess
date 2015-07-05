#include "knight.h"

Knight::Knight()
{
}

Knight::~Knight()
{
}

/*
 * Generates all possible moves for the piece
 */
QVector<Move > Knight::getPossibleMoves(int x, int y)
{
    qDebug() << "Knight getPossibleMoves!!!!";
    QVector<Move> a;
    a.push_back(Move(x+1, y+2, false, false, true));
    a.push_back(Move(x-1, y+2, false, false, true));
    a.push_back(Move(x+1, y-2, false, false, true));
    a.push_back(Move(x-1, y-2, false, false, true));
    a.push_back(Move(x+2, y+1, false, false, true));
    a.push_back(Move(x+2, y-1, false, false, true));
    a.push_back(Move(x-2, y+1, false, false, true));
    a.push_back(Move(x-2, y-1, false, false, true));
    return a;
}

