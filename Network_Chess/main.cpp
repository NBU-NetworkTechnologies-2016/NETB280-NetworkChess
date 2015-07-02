#include "mainboard.h"
#include <QApplication>
#include "menu.h"
#include "chesslogic.h"
#include "QDebug"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainBoard w;

    qDebug() << "Boom!";
    //w.disableButtons();//disabling unsued buttons at newgame
    //w.RefreshBoard();
    //w.show();
    /*other menus, new game options etc...*/
    ChessLogic cl(1);
    cl.PrintGameBoard();
    cl.MovePiece(1,1,1,6);
    cl.PrintGameBoard();
    //Menu m;
    //m.show();*/
    return a.exec();
}
