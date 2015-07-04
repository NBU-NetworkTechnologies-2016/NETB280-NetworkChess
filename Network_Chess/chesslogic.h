#ifndef CHESSLOGIC_H
#define CHESSLOGIC_H

#include "QString"
#include <QMap>
#include "piece.h"
#include "whitepawn.h"
#include "move.h"
#include "blackpawn.h"
#include "king.h"
#include "knight.h"
#include "rook.h"
#include "piece.h"
#include "bishop.h"

class ChessLogic
{

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

    QMap<int, Piece*> pieces;
public:
    ChessLogic(); // Initialize the game board
    bool MovePiece(int old_x, int old_y, int new_x, int new_y);
    int** GetBoard(); // return A COPY of the array
    int CheckResult(); //0 still played 1 white wins 2 black wins 3 draw
    void PrintGameBoard();
    bool IsPathEmpty(int old_x, int old_y, int new_x, int new_y);
};

#endif // CHESSLOGIC_H
