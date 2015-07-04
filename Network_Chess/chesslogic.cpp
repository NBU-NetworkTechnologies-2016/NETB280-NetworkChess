#include "chesslogic.h"
#include <QDebug>
#include <cmath>
#include "piece.h"


ChessLogic::ChessLogic()
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

    board[4][4] = 17;
    board[6][4] = 27;
    //Initialize the pieces in the map;
}

/*
 * checks if a piece can move to a location. if it can moves it.
 * if it can't move throws an exception
 */

bool ChessLogic::MovePiece(int old_x, int old_y, int new_x, int new_y)
{
    int piece_type = board[old_x][old_y];

    WhitePawn wp;
    Piece *a = &wp;
    pieces[11] = a;
    BlackPawn bp;
    Piece *b = &bp;
    pieces[21] = b;
    King k;
    Piece* kk = &k;
    pieces[17] = kk;
    pieces[27] = kk;
    Knight kn;
    Piece* kkn = &kn;
    pieces[13] = kkn;
    pieces[23] = kkn;

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

    if(!pieces.contains(piece_type))
    {
        return false;
    }

    bool is_move_possible = false;
    QVector<Move> moves = pieces[piece_type]->getPossibleMoves(old_x, old_y);
    qDebug() << "Possible moves are: " << moves.length();
    for(int i = 0; i < moves.length(); i++)
    {
        qDebug() << "New possible move!" << moves[i].x << "  " << moves[i].y;
        if(moves[i].x == new_x && moves[i].y == new_y)
        {
            qDebug() << " Matching move!";
            is_move_possible = true;
            if(moves[i].must_be_first)
            {
                qDebug() << " Must be first";
                if(old_y != 1 && old_y != 6)
                {
                    qDebug() << "Is not first";
                    is_move_possible = false;
                }
            }
            if(moves[i].must_contain_enemy)
            {
                qDebug() << " Must contain enemy";
                if(board[new_x][new_y] == 0)
                {
                    qDebug() << " Doesn't contain enemey";
                    is_move_possible = true;
                }
            }
            if(!moves[i].can_fly)
            {
                if(!IsPathEmpty( old_x,  old_y,  new_x,  new_y))
                {
                    return false;
                }
            }
        }
    }
    if(!is_move_possible)
    {
        qDebug() << "Move is not possible!";
        return false;
    }
/*
    //White rook
    else if(piece_type == 12 || piece_type == 22)
    {
       if(!(
            (old_x < new_x && old_y == new_y) // move right 
            || (old_x > new_x && old_y == new_y) // move left
            || (old_x == new_x && old_y < new_y) // move down
            || (old_x == new_x && old_y > new_y) // move up
           ))
       {
           return false;
       }
    }
    //bishop
    else if(piece_type == 15 || piece_type == 25)
    {
        if(!(
                abs(old_x - new_x) == abs(old_y - new_y)
          ))
        {
            return false;
        }
    }
    //queens
    else if(piece_type == 18 || piece_type == 28)
    {
        //empty since queens can move everywhere
    }
*/

    // Check if you are not killing your own piece
    int taken_type =  board[new_x][new_y];
    while(taken_type > 9)
        taken_type /= 10;

    if(taken_type == this->current_turn)
    {
        return false;
    }

    //Change the current player turn
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

bool ChessLogic::IsPathEmpty(int old_x, int old_y, int new_x, int new_y)
{
    qDebug() << "Entering IsPathEmpty old_x: " << old_x << " old y: " << old_y << " new_x: " << new_x << " new_y: " << new_y;
    while(old_x != new_x || old_y != new_y)
    {
        if(old_x != new_x)
        {
            //qDebug() << "X is different!";
            if(old_x < new_x)
            {
                old_x++;
            }
            else
            {
                old_x--;
            }
            //qDebug() << "New x is: " << old_x;
        }
         if(old_y != new_y)
        {
             //qDebug() << "Y is different";
            if(old_y < new_y)
            {
                old_y++;
            }
            else
            {
                old_y--;
            }
            //qDebug() << "New y is: " << old_y;
        }
        if(board[old_x][old_y] != 0)
        {
            qDebug() << "There is NO path!";
            return false;
        }
        //qDebug() << "We are at: " << old_x << " " << old_y << "and value is: " << board[old_x][old_y];
    }
    qDebug() << "There is a path!";
    return true;
}
