#ifndef CHESSLOGIC_H
#define CHESSLOGIC_H

#include "QString"

class ChessLogic
{
    struct position {
      int x;
      int y;
    } ;


    typedef struct piece{
      int type;
      int owner; // 0 white 1 black
      position current_pos;

      bool (ChessLogic::*can_move)(position old_pos, position new_pos);
    } piece_t;


private:
    int board[8][8];
    piece game_pieces[100];


    const int OWNER_WHITE = 0;
    const int OWNER_BLACK = 1;
    const int RESULT_ACTIVE = 0;
    const int RESULT_WHITE_WINS = 1;
    const int RESULT_BLACK_WINS = 2;
    const int RESULT_DRAW = 3;
public:
    ChessLogic(int skirmish); // Initialize the game board
    bool MovePiece(position old_pos, position new_pos);
    int** GetBoard(); // return A COPY of the array

    int CheckResult(); //0 still played 1 white wins 2 black wins 3 draw
    bool PawnCanMove(position old_pos, position new_pos);
};

#endif // CHESSLOGIC_H
