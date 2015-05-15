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
    w.disableButtons();//disabling unsued buttons at newgame
    w.RefreshBoard();
    w.show();
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
