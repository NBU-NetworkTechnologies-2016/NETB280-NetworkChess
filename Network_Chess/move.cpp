#include "move.h"

Move::Move(int x, int y, bool must_be_first, bool must_contain_enemy)
{
    this->x = x;
    this->y = y;
    this->must_be_first = must_be_first;
    this->must_contain_enemy = must_contain_enemy;
}

Move::Move(){}
