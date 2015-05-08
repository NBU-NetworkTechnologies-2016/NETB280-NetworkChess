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

bool  ChessLogic::PawnCanMove(position old_pos, position new_pos)
{
    // Board boundries
    if(new_pos.x > 7 || new_pos.x < 0 || new_pos.y > 7 || new_pos.y < 0)
    {
        return false;
    }

    // White move
/*
    if(game_pieces[board[old_pos.x][old_pos.y]].owner == OWNER_WHITE)
    {

    }
    // Black move
    if(game_pieces[board[old_pos.x][old_pos.y]].owner == OWNER_BLACK)
    {

    }
*/
    return true;

}
