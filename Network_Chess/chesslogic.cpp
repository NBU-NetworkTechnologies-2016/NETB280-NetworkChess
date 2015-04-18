#include "chesslogic.h"

ChessLogic::ChessLogic(int skirmish)
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            board[i][j] = 0;
        }
    }
    /*
     *
     * struct piece{
            int symbol;
            CanMove can_move;
        };
    */

    //init the skirmish (every skirmish has his own pieces)
    if(skirmish == 0)
    {

    }
    // General Case, standard chess game
    else
    {
        piece whitePawn;
        whitePawn.symbol = 1;
        whitePawn.owner = 0;

    }

}


bool ChessLogic::MoviePiece(position old_pos, position new_pos)
{
    return game_pieces[board[new_pos.x][new_pos.y]].can_move(old_pos, new_pos) ? true : false;
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
