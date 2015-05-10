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
//TODO implement piece movement
//TODO implement GetPossibleMoves
private:
    int board[7][7];

    const int WHITE_PAWN = 11;
    const int WHITE_KNIGHT1 = 12;
    const int WHITE_KNIGHT2 = 13;
    const int WHITE_ROOK    = 14;
    const int WHITE_BISHOP_W = 15;
    const int WHITE_BISHOP_B = 16;
    const int WHITE_KING = 17;
    const int WHITE_QUEEN = 18;

    const int BLACK_PAWN = 21;
    const int BLACK_KNIGHT1 = 22;
    const int BLACK_KNIGHT2 = 23;
    const int BLACK_ROOK    = 24;
    const int BLACK_BISHOP_W = 25;
    const int BLACK_BISHOP_B = 26;
    const int BLACK_KING = 27;
    const int BLACK_QUEEN = 28;

    const int RESULT_WHITE_WINS = 1;
    const int RESULT_BLACK_WINS = 2;
    const int RESULT_DRAW = 3;

    const int CURRENT_TURN_WHITE = 1;
    const int CURRENT_TURN_BLACK = 2;

    int current_turn;
public:
    ChessLogic(int skirmish); // Initialize the game board
    void MovePiece(position old_pos, position new_pos);
    int** GetBoard(); // return A COPY of the array
    int** GetPossibleMoves(position piece_position);
    int CheckResult(); //0 still played 1 white wins 2 black wins 3 draw
};

#endif // CHESSLOGIC_H
