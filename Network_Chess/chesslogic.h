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

    const int WHITE_PAWN;
    const int WHITE_KNIGHT1;
    const int WHITE_KNIGHT2;
    const int WHITE_ROOK;
    const int WHITE_BISHOP_W;
    const int WHITE_BISHOP_B;
    const int WHITE_KING;
    const int WHITE_QUEEN;

    const int BLACK_PAWN;
    const int BLACK_KNIGHT1;
    const int BLACK_KNIGHT2;
    const int BLACK_ROOK;
    const int BLACK_BISHOP_W;
    const int BLACK_BISHOP_B;
    const int BLACK_KING;
    const int BLACK_QUEEN;

    const int RESULT_WHITE_WINS;
    const int RESULT_BLACK_WINS;
    const int RESULT_DRAW;

    const int CURRENT_TURN_WHITE;
    const int CURRENT_TURN_BLACK;

    int current_turn;
public:
    ChessLogic(int skirmish); // Initialize the game board
    void MovePiece(position old_pos, position new_pos);
    int** GetBoard(); // return A COPY of the array
    int** GetPossibleMoves(position piece_position);
    int CheckResult(); //0 still played 1 white wins 2 black wins 3 draw
};

#endif // CHESSLOGIC_H
