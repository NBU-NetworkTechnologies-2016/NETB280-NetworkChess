#ifndef CHESSLOGIC_H
#define CHESSLOGIC_H

#include "QString"


struct position {
  int x;
  int y;
} ;


typedef bool (*CanMove) (position old_pos, position new_pos);


struct piece{
    int symbol;
    int owner; // 0 white 1 black
    CanMove can_move;
};
class ChessLogic
{
private:
    int board[8][8];
    piece game_pieces[10000];
public:
    ChessLogic(int skirmish); // Initialize the game board
    bool MoviePiece(position old_pos, position new_pos);
    int** GetBoard(); // return A COPY of the array

    int CheckResult(); //0 still played 1 white wins 2 black wins 3 draw

};

#endif // CHESSLOGIC_H
