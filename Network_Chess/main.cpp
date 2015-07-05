#include "mainboard.h"
#include <QApplication>
#include "menu.h"
#include "chesslogic.h"
#include "QDebug"
#include "piece.h"
#include "whitepawn.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainBoard w;
    //w.show();

    Menu m;
    m.show();
    qDebug() << "Boom!";
    //w.disableButtons();//disabling unsued buttons at newgame
    //w.RefreshBoard();
    //w.show();
    /*other menus, new game options etc...*/

/*
    WhitePawn p1;
    Piece* p11 = &p1;
    p11->getPossibleMoves(1,1);
*/
    /*
    ChessLogic cl;
    cl.PrintGameBoard();
    cl.MovePiece(4,4,5,5);
    cl.MovePiece(6,4,5,3);
    cl.MovePiece(5,5,6,6);
    cl.PrintGameBoard();
   // cl.MovePiece(0,0,0,1);
    //cl.MovePiece(2,6,2,5);
   // cl.PrintGameBoard();
    //Menu m;
    //m.show();*/

    qDebug() << "Boom!";
    //w.disableButtons();//disabling unsued buttons at newgame
    //w.RefreshBoard();//this way we call the refreshBoard twice, because the function is invoked in the constructor as well

    /*other menus, new game options etc...
    ChessLogic cl(1);
    int** arr = cl.GetBoard();
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            qDebug() << arr[i][j];
        }
    }
    Menu m;
    m.show();*/

    return a.exec();
}
