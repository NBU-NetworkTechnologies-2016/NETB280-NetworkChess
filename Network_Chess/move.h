#ifndef MOVE_H
#define MOVE_H
#include "move.h"

class Move
{
public:
    Move();
    Move(int x, int y, bool must_be_first, bool must_contain_enemy, bool can_fly = false);
    int x;
    int y;
    bool must_be_first;
    bool must_contain_enemy;
    bool can_fly;
};

#endif // MOVE_H
