#ifndef MOVE_H
#define MOVE_H
#include "move.h"

class Move
{
public:
    Move();
    Move(int x, int y, bool must_be_first, bool must_contain_enemy);
    int x;
    int y;
    bool must_be_first;
    bool must_contain_enemy;
};

#endif // MOVE_H
