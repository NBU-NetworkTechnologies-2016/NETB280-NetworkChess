#include "funcptrtest.h"

FuncPtrTest::FuncPtrTest()
{
    CanMove a = &FuncPtrTest::FuncExample;
}

bool  FuncPtrTest::FuncExample(position old_pos, position new_pos)
{
    return true;
}
