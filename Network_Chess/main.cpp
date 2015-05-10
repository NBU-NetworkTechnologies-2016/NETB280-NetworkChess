#include "mainboard.h"
#include <QApplication>
#include "menu.h"
#include "chesslogic.h"
#include "QDebug"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainBoard w;
    //w.show();
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
    m.show();
    return a.exec();
}
