#include "chesslogic.h"
#include <QDebug>


ChessLogic::ChessLogic(int skirmish)
{


    //this->current_turn = CURRENT_TURN_WHITE;
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            board[i][j] = 0;
        }
    }

    current_turn = 1;

    /*
     WHITE_PAWN = 11;
     WHITE_KNIGHT1 = 12;
     WHITE_KNIGHT2 = 13;
     WHITE_ROOK  = 14;
     WHITE_BISHOP_W = 15;
     WHITE_BISHOP_B = 16;
     WHITE_KING = 17;
     WHITE_QUEEN = 18;

     BLACK_PAWN = 21;
     BLACK_KNIGHT1 = 22;
     BLACK_KNIGHT2 = 23;
     BLACK_ROOK   = 24;
     BLACK_BISHOP_W = 25;
     BLACK_BISHOP_B = 26;
     BLACK_KING = 27;
     BLACK_QUEEN = 28;

     RESULT_WHITE_WINS = 1;
     RESULT_BLACK_WINS = 2;
     RESULT_DRAW = 3;

     CURRENT_TURN_WHITE = 1;
     CURRENT_TURN_BLACK = 2;
*/
    //init the skirmish (every skirmish has his own pieces)
    if(skirmish == 5353534)
    {

    }
    // General Case, standard chess game
    else
    {
        //COLUMN, ROW

        // White pieces
        board[1][1] = 11;
        board[2][1] = 11;
        board[3][1] = 11;
        board[4][1] = 11;
        board[5][1] = 11;
        board[6][1] = 11;
        board[7][1] = 11;
        board[0][1] = 11;

        board[1][0] = 13;
        board[2][0] = 15;
        board[3][0] = 17;
        board[4][0] = 18;
        board[5][0] = 15;
        board[6][0] = 13;
        board[7][0] = 14;
        board[0][0] = 14;

        // Black pieces
        board[3][6] = 21;
        board[0][6] = 21;
        board[7][6] = 21;
        board[1][6] = 21;
        board[6][6] = 21;
        board[2][6] = 21;
        board[5][6] = 21;
        board[4][6] = 21;

        board[1][7] = 23;
        board[2][7] = 25;
        board[3][7] = 27;
        board[4][7] = 28;
        board[5][7] = 25;
        board[6][7] = 23;
        board[7][7] = 24;
        board[0][7] = 24;
    }

}

/*
 * checks if a piece can move to a location. if it can moves it.
 * if it can't move throws an exception
 */

bool ChessLogic::MovePiece(int old_x, int old_y, int new_x, int new_y)
{
    int piece_type = board[old_x][old_y];

    qDebug() << "old_pos.x: "  << old_x;
    qDebug() << "old_pos.y: "  << old_y;
    qDebug() << "new_pos.x: "  << new_x;
    qDebug() << "new_pos.y: "  << new_y;
    qDebug() << "piece: " << piece_type;

    int piece_owner = piece_type;
    while(piece_owner > 9)
        piece_owner /= 10;


    if(current_turn != piece_owner)
    {
        qDebug() << "Current turn is: " << current_turn  << "Not this player's turn!" << endl;
        return false;
    }
    if(new_x > 7 || new_x < 0 || new_y > 7 || new_y < 0)
    {
        return false;
    }

    if(old_x > 7 || old_x < 0 || old_y > 7 || old_y < 0)
    {
        return false;
    }
    //White Pawn
    if(piece_type == 11)
    {
        if(!((new_y == old_y +1) // standard move
           || (new_y == old_y +2) // first possible move
           || (new_y == old_y +1 && new_x == old_x + 1) // take piece left
           || (new_y == old_y +1 && new_x == old_x - 1))) // take piece right
        {
            return false;
        }
    }
    else if(piece_type == 13 || piece_type == 23)
    {
/*        if(!(
            ()
            ()
            ()
            ()
            ()
            ()
            ()
            ()
            ))
        {

        }*/
    }
    //White rook
    else if(piece_type == 12 || piece_type = 22)
    {
       if(!(
            (old_x < new_x && old_y == new_y) // move right 
            (old_x > new_x && old_y == new_y) // move left
            (old_x == new_x && old_y < new_y) // move down
            (old_x == new_x && old_y > new_y) // move up
           ))
       {
           return false;
       }
       else if()
       {
        // todo check if there are pieces in the way
       }
    }
    else if(piece_type == WHITE_BISHOP_B)
    {

    }
    else if(piece_type == WHITE_KING)
    {

    }
    //black pawn
    else if(piece_type == 21)
    {
        if(!((new_y == old_y -1) // standard move
           || (new_y == old_y -2) // first possible move
           || (new_y == old_y -1 && new_x == old_x + 1) // take piece left
           || (new_y == old_y -1 && new_x == old_x - 1))) // take piece right
        {
            return false;
        }


    }
    else if(piece_type == BLACK_QUEEN)
    {

    }
    //Simplicity is beautiful
    if(this->current_turn == 1)
    {
        this->current_turn = 2;
    }
    else
    {
        this->current_turn = 1;
    }

    board[old_x][old_y]  = 0;
    board[new_x][new_y] = piece_type;
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
            //qDebug() << board[i][j];
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

/*
 * This function is made for internal debug use
 */
void ChessLogic::PrintGameBoard()
{
    int** arr = this->GetBoard();
    for(int i = 0; i < 8; i++)
    {
        QString row;
        for(int j = 0; j < 8; j++)
        {
            //qDebug() << arr[i][j];
            row += QString::number(arr[j][i]);
            row += "-";
        }
        qDebug() << row;
    }
}

