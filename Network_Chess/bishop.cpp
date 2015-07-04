#include "bishop.h"

Bishop::Bishop()
{
}

Bishop::~Bishop()
{
}

QVector<Move > Bishop::getPossibleMoves(int x, int y)
{
    qDebug() << "Bishop getPossibleMoves!!!!";
    QVector<Move> a;

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
    qDebug() << "Bishop moves count: " << a.length();
    return a;
}
