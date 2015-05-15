#include "chesslogic.h"

//SETTINGS AND MAPPINGS



ChessLogic::ChessLogic(int skirmish)
{
    this->WHITE_PAWN = 11;
    this->WHITE_KNIGHT1 = 12;
    this->WHITE_KNIGHT2 = 13;
    this->WHITE_ROOK    = 14;
    this->WHITE_BISHOP_W = 15;
    this->WHITE_BISHOP_B = 16;
    this->WHITE_KING = 17;
    this->WHITE_QUEEN = 18;

    this->BLACK_PAWN = 21;
    this->BLACK_KNIGHT1 = 22;
    this->BLACK_KNIGHT2 = 23;
    this->BLACK_ROOK    = 24;
    this->BLACK_BISHOP_W = 25;
    this->BLACK_BISHOP_B = 26;
    this->BLACK_KING = 27;
    this->BLACK_QUEEN = 28;

    this->RESULT_WHITE_WINS = 1;
    this->RESULT_BLACK_WINS = 2;
    this->RESULT_DRAW = 3;

    this->CURRENT_TURN_WHITE = 1;
    this->CURRENT_TURN_BLACK = 2;

    this->current_turn = CURRENT_TURN_WHITE;
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            board[i][j] = 0;
        }
    }

    //init the skirmish (every skirmish has his own pieces)
    if(skirmish == 0)
    {

    }
    // General Case, standard chess game
    else
    {

        // White pieces
        board[1][0] = WHITE_PAWN;
        board[1][1] = WHITE_PAWN;
        board[1][2] = WHITE_PAWN;
        board[1][3] = WHITE_PAWN;
        board[1][4] = WHITE_PAWN;
        board[1][5] = WHITE_PAWN;
        board[1][6] = WHITE_PAWN;
        board[1][7] = WHITE_PAWN;

        board[0][0] = WHITE_ROOK;
        board[0][7] = WHITE_ROOK;
        board[0][1] = WHITE_KNIGHT1;
        board[0][6] = WHITE_KNIGHT2;
        board[0][2] = WHITE_BISHOP_W;
        board[0][5] = WHITE_BISHOP_B;
        board[0][4] = WHITE_QUEEN;
        board[0][3] = WHITE_KING;

        //Black pieces
        board[6][0] = BLACK_PAWN;
        board[6][1] = BLACK_PAWN;
        board[6][2] = BLACK_PAWN;
        board[6][3] = BLACK_PAWN;
        board[6][4] = BLACK_PAWN;
        board[6][5] = BLACK_PAWN;
        board[6][6] = BLACK_PAWN;
        board[6][7] = BLACK_PAWN;


        board[7][0] = BLACK_ROOK;
        board[7][7] = BLACK_ROOK;
        board[7][1] = BLACK_KNIGHT1;
        board[7][6] = BLACK_KNIGHT2;
        board[7][2] = BLACK_BISHOP_W;
        board[7][5] = BLACK_BISHOP_B;
        board[7][4] = BLACK_QUEEN;
        board[7][3] = BLACK_KING;
    }

}

/*
 * checks if a piece can move to a location. if it can moves it.
 * if it can't move throws an exception
 */

void ChessLogic::MovePiece(position old_pos, position new_pos)
{
    int piece_type = board[old_pos.x][old_pos.y];


    int piece_owner = piece_type;
    while(piece_owner > 9)
        piece_owner /= 10;

    if(current_turn != piece_type)
    {
        //todo throw exception
    }

    if(new_pos.x > 7 || new_pos.x < 0 || new_pos.y > 7 || new_pos.y < 0)
    {
        // throw exception for new position
    }

    if(old_pos.x > 7 || old_pos.x < 0 || old_pos.y > 7 || old_pos.y < 0)
    {
        // throw exception for new position
    }

    if(piece_type == WHITE_PAWN)
    {

    }
    else if(piece_type == WHITE_KNIGHT1)
    {

    }
    else if(piece_type == WHITE_KNIGHT2)
    {

    }
    else if(piece_type == WHITE_ROOK)
    {

    }
    else if(piece_type == WHITE_BISHOP_W)
    {

    }
    else if(piece_type == WHITE_BISHOP_B)
    {

    }
    else if(piece_type == WHITE_KING)
    {

    }
    else if(piece_type == WHITE_QUEEN)
    {

    }
    else if(piece_type == BLACK_PAWN)
    {

    }
    else if(piece_type == BLACK_KNIGHT1)
    {

    }
    else if(piece_type == BLACK_KNIGHT2)
    {

    }
    else if(piece_type == BLACK_ROOK)
    {

    }
    else if(piece_type == BLACK_BISHOP_W)
    {

    }
    else if(piece_type == BLACK_BISHOP_B)
    {

    }
    else if(piece_type == BLACK_KING)
    {

    }
    else if(piece_type == BLACK_QUEEN)
    {

    }

    if(this->current_turn == CURRENT_TURN_WHITE)
    {
        this->current_turn = CURRENT_TURN_BLACK;
    }
    this->current_turn = CURRENT_TURN_WHITE;
}

int** ChessLogic::GetBoard() // return A COPY of the array
{
    int** board_copy;
    board_copy = 0;
    board_copy = new int*[8];

    for(int i = 0; i < 8; i++)
    {
        board_copy[i] = new int[8];
        for(int j = 0; j < 8; j++)
        {
            board_copy[i][j] = board[i][j];
        }
    }

    return board_copy;
}

int** ChessLogic::GetPossibleMoves(position piece_position)
{
    int **board;
    return board;
}

int ChessLogic::CheckResult(){return 0;} //0 still played 1 white wins 2 black wins 3 draw
