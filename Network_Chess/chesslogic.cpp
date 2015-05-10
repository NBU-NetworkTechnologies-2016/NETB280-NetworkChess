#include "chesslogic.h"

//SETTINGS AND MAPPINGS



ChessLogic::ChessLogic(int skirmish)
{
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
        piece whitePawn;
        //whitePawn.symbol = 1;
        //whitePawn.owner = 0;
        //whitePawn.can_move = &ChessLogic::PawnCanMove;
    }

}

/*
 * checks if a piece can move to a location. if it can moves it.
 * if it can't move throws an exception
 */

bool ChessLogic::MovePiece(position old_pos, position new_pos)
{
    piece p = game_pieces[board[old_pos.x][old_pos.y]];

    uint32_t powers_of_10[33] = {
        1000000000, 1000000000,
        100000000, 100000000, 100000000,
        10000000, 10000000, 10000000,
        1000000, 1000000, 1000000, 1000000,
        100000, 100000, 100000,
        10000, 10000, 10000,
        1000, 1000, 1000, 1000,
        100, 100, 100,
        10, 10, 10,
        1, 1, 1, 1, 1
    };

    int piece_owner;
    int piece_type = p.type;
    int leading_zeros = clz(piece_type);
    piece_type /= powers_of_10[leading_zeros];
    if (piece_type >= 10)
       piece_owner = 1;
    else
       piece_owner = piece_type;
    if(current_turn != piece_type)
    {
        return -1;
    }

    if(p.type == WHITE_PAWN)
    {

    }
    else if(p.type == WHITE_KNIGHT1)
    {

    }
    else if(p.type == WHITE_KNIGHT2)
    {

    }
    else if(p.type == WHITE_ROOK)
    {

    }
    else if(p.type == WHITE_BISHOP_W)
    {

    }
    else if(p.type == WHITE_BISHOP_B)
    {

    }
    else if(p.type == WHITE_KING)
    {

    }
    else if(p.type == WHITE_QUEEN)
    {

    }
    else if(p.type == BLACK_PAWN)
    {

    }
    else if(p.type == BLACK_KNIGHT1)
    {

    }
    else if(p.type == BLACK_KNIGHT2)
    {

    }
    else if(p.type == BLACK_ROOK)
    {

    }
    else if(p.type == BLACK_BISHOP_W)
    {

    }
    else if(p.type == BLACK_BISHOP_B)
    {

    }
    else if(p.type == BLACK_KING)
    {

    }
    else if(p.type == BLACK_QUEEN)
    {

    }

    if(this->current_turn == CURRENT_TURN_WHITE)
    {
        this->current_turn = CURRENT_TURN_BLACK;
        return true;
    }
    this->current_turn = CURRENT_TURN_WHITE;
    return true;
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

int ChessLogic::CheckResult(){return 0;} //0 still played 1 white wins 2 black wins 3 draw
