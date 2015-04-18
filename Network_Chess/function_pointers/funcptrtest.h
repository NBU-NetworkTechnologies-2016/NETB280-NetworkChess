#ifndef FUNCPTRTEST_H
#define FUNCPTRTEST_H

class FuncPtrTest
{
public:
    struct position {
      int x;
      int y;
    } ;

    typedef bool (*CanMove) (position old_pos, position new_pos);
private:
    FuncPtrTest();
    bool FuncExample(position old_pos, position new_pos);
};

#endif // FUNCPTRTEST_H
