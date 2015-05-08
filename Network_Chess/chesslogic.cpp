#include "chesslogic.h"

//SETTINGS AND MAPPINGS



ChessLogic::ChessLogic(int skirmish)
{
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


bool ChessLogic::MovePiece(position old_pos, position new_pos)
{
    //return game_pieces[board[old_pos.x][old_pos.y]]->*can_move(old_pos, new_pos) ? true : false;
    int piece_type = game_pieces[board[old_pos.x][old_pos.y]];

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
