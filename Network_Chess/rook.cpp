#include "rook.h"

Rook::Rook()
{
}

Rook::~Rook()
{
    // For the sake of less code, there will be a few invalid turns here.

}

QVector<Move > Rook::getPossibleMoves(int x, int y)
{
    qDebug() << "Rook getPossibleMoves!!!!";
    QVector<Move> a;

    for(int i = 0; i < 8; i++)
    {
        a.push_back(Move(i, y, false, false, false));
    }

    for(int j = 0; j < 8; j++)
    {
        a.push_back(Move(x, j, false, false, false));
    }
    return a;
}

