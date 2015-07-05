#include "queen.h"

Queen::Queen()
{
}

Queen::~Queen()
{
}

/*
 * Generates all possible moves for the piece
 */
QVector<Move > Queen::getPossibleMoves(int x, int y)
{
    qDebug() << "Queen getPossibleMoves!!!!";
    QVector<Move> a;

    for(int i = 0; i < 8; i++)
    {
        a.push_back(Move(i, y, false, false, false));
    }

    for(int j = 0; j < 8; j++)
    {
        a.push_back(Move(x, j, false, false, false));
    }
    int x1 = x;
    int y1 = y;
    while(x1 < 8 || y1 < 8)
    {
        x1++;
        y1++;
       a.push_back(Move(x1, y1, false, false, false));
    }

    x1 = x;
    y1 = y;
    while(x1 > 0 || y1 < 8)
    {
        x1--;
        y1++;
       a.push_back(Move(x1, y1, false, false, false));
    }

    x1 = x;
    y1 = y;
    while(x1 < 8 || y1 > 8)
    {
        x1++;
        y1--;
       a.push_back(Move(x1, y1, false, false, false));
    }

    x1 = x;
    y1 = y;
    while(x1 > 0 || y1 > 8)
    {
        x1--;
        y1--;
       a.push_back(Move(x1, y1, false, false, false));
    }
    return a;
}
