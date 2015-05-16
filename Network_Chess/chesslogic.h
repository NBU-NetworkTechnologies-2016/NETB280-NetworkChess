#ifndef CHESSLOGIC_H
#define CHESSLOGIC_H

#include "QString"

class ChessLogic
{
    struct position {
      int x;
      int y;
    } ;

//TODO Add notion of win / loose
private:
    int board[8][8];


     int WHITE_PAWN;
     int WHITE_KNIGHT1;
     int WHITE_KNIGHT2;
     int WHITE_ROOK;
     int WHITE_BISHOP_W;
     int WHITE_BISHOP_B;
     int WHITE_KING;
     int WHITE_QUEEN;

     int BLACK_PAWN;
     int BLACK_KNIGHT1;
     int BLACK_KNIGHT2;
     int BLACK_ROOK;
     int BLACK_BISHOP_W;
     int BLACK_BISHOP_B;
     int BLACK_KING;
     int BLACK_QUEEN;

     int RESULT_WHITE_WINS;
     int RESULT_BLACK_WINS;
     int RESULT_DRAW;

     int CURRENT_TURN_WHITE;
     int CURRENT_TURN_BLACK;


    int current_turn;
public:
    ChessLogic(int skirmish); // Initialize the game board
    void MovePiece(position old_pos, position new_pos);
    int** GetBoard(); // return A COPY of the array
    int** GetPossibleMoves(position piece_position);
    int CheckResult(); //0 still played 1 white wins 2 black wins 3 draw
};

#endif // CHESSLOGIC_H
