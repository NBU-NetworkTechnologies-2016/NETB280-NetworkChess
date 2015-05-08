#include "chesslogic.h"

//SETTINGS AND MAPPINGS



ChessLogic::ChessLogic(int skirmish, int current_turn)
{
    if(current_turn == WHITE_TURN || current_turn == BLACK_TURN)
    {
        this->current_turn = current_turn;
    }
    else
    {
        this->current_turn = WHITE_TURN;
    }
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
    //return game_pieces[board[old_pos.x][old_pos.y]]->*can_move(old_pos, new_pos) ? true : false;
    piece p = game_pieces[board[old_pos.x][old_pos.y]];

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
