#include "mainboard.h"
#include "ui_mainboard.h"
#include <QTextStream>
#include <QLabel>
#include <QString>
#include <QPushButton>
#include <QIcon>
#include <QSize>
#include <QObject>
#include <QSignalMapper>
#include "chesslogic.h";
#include "QDebug";

MainBoard::MainBoard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainBoard)
{
    ui->setupUi(this);
    this->setFixedSize(1920, 1080);
    this->setStyleSheet("background-color: #F0E8E8;");

    //TODO this must not be hardcoded when we have more than 1 skirmishes
    cl = new ChessLogic();

    QString whiteFigureNames[NUMBER_OF_FIGURES] = {":/wPawn", ":/wBishop", ":/wHorse", ":/wRook", ":/wQueen", ":/wKing"};
    QString blackFigureNames[NUMBER_OF_FIGURES] = {":/bPawn", ":/bBishop", ":/bHorse", ":/bRook", ":/bQueen", ":/bKing"};
    for(int i = 0; i < 50; i++)
    {
        figures[i] = new QIcon(":/bKing");
    }


    figures[11] = new QIcon(whiteFigureNames[0]);
    figures[12] = new QIcon(whiteFigureNames[2]);
    figures[13] = new QIcon(whiteFigureNames[2]);
    figures[14] = new QIcon(whiteFigureNames[3]);
    figures[15] = new QIcon(whiteFigureNames[1]);
    figures[15] = new QIcon(whiteFigureNames[1]);
    figures[17] = new QIcon(whiteFigureNames[5]);
    figures[18] = new QIcon(whiteFigureNames[4]);

    figures[21] = new QIcon(blackFigureNames[0]);
    figures[22] = new QIcon(blackFigureNames[2]);
    figures[23] = new QIcon(blackFigureNames[2]);
    figures[24] = new QIcon(blackFigureNames[3]);
    figures[25] = new QIcon(blackFigureNames[1]);
    figures[25] = new QIcon(blackFigureNames[1]);
    figures[27] = new QIcon(blackFigureNames[5]);
    figures[28] =new QIcon( blackFigureNames[4]);
    //Initialize Figures
    size.setHeight(60);
    size.setWidth(60);




    initializeBoard(); //initializing the QLabel & QPushButton objects
    initializeFigures();//initializing QIcons (figures)
    createBoard(); //creating the board and the QpushButtons on top of the board
    RefreshBoard();
    //positions[5][5]->setStyleSheet("background-color: red");
    mapper = new QSignalMapper(this);
    connect(mapper, SIGNAL(mapped(int)), this, SLOT(movePieceStart(int)));
    int holder[8][8];


    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            holder[0][j] = 100 + j;
            if(i > 0)
            {
                holder[i][j] = (i * 10) + j;
            }

            mapper->setMapping(positions[i][j], holder[i][j]);
            connect(positions[i][j], SIGNAL(clicked()), mapper, SLOT(map()));

        }

    }

    pieceSignals();

}
void MainBoard::pieceSignals()
{
    //connect(positions[globalButtonCoordinateX][globalButtonCoordinateY], SIGNAL(clicked()), this, SLOT(movePieceStart(int)));
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            connect(positions[i][j], SIGNAL(clicked()), this, SLOT(movingPieces()));
        }
    }


}
void MainBoard::movingPieces()
{

    if(onMove)
    {
        
        qDebug() << "onMove-true";
        positions[oldGlobalButtonCoordinateX][oldGlobalButtonCoordinateY]->setIcon(QIcon());
        //positions[globalButtonCoordinateX][globalButtonCoordinateY]->setIcon(currentPieceIcon);
        cl->MovePiece(oldGlobalButtonCoordinateX, oldGlobalButtonCoordinateY,
                      globalButtonCoordinateX, globalButtonCoordinateY);
        RefreshBoard();


    }
}

void MainBoard::movePieceStart(int i)
{

    mappedButtons = i;//from value to index

    qDebug() << "mappedButtons: " << mappedButtons;
    int firstColumn = 100;//first column mapping
    int currentX = 0;//all other columns mapping
    for(int z = 10; z <=80; z+=10)
    {
        currentX++;
        for(int j = 0; j <= 7; j++)
        {
            if(mappedButtons >= firstColumn)
            {
                globalButtonCoordinateX = 0;
                globalButtonCoordinateY = j;
                firstColumn++;
            }
            if(mappedButtons >=z && mappedButtons <= z + 10 - 3)
            {
                globalButtonCoordinateX = currentX;
                globalButtonCoordinateY = j;
                z++;
            }
         }
    }
    qDebug() << "X: " << globalButtonCoordinateX;
    qDebug() << "Y: " << globalButtonCoordinateY;

    QIcon currentIcon = positions[globalButtonCoordinateX][globalButtonCoordinateY]->icon();
    if((currentIcon.isNull()) == false)
    {
        onMove = true;
        currentPieceIcon = positions[globalButtonCoordinateX][globalButtonCoordinateY]->icon();
        oldGlobalButtonCoordinateX = globalButtonCoordinateX;
        oldGlobalButtonCoordinateY = globalButtonCoordinateY;
    }

}

//will disable buttons that are not used at start game
void MainBoard::disableButtons()
{
    for(int i = 0; i < BOARD_COLS; i++)
    {
        for(int j = 2; j < BOARD_ROWS - 2; j++)
        {
            positions[i][j]->setEnabled(false);
        }
    }
}

//initialize each QIcon (each figure) and setting the size of all figures
void MainBoard::initializeFigures()
{

    for(int i = 0; i < NUMBER_OF_FIGURES; i++)
    {
        whiteFigures[i] = new QIcon(whiteFigureNames[i]);//{"wPawn", "wBishop", "wHorse", "wRook", "wQueen", "wKing"};
        blackFigures[i] = new QIcon(blackFigureNames[i]);//{"bPawn", "bBishop", "bHorse", "bRook", "bQueen", "bKing"};
    }

}
//initializing each QLabel and QPushButton
void MainBoard::initializeBoard()
{

    for(int i = 0; i < BOARD_COLS; i++)
    {

        square_letter_label[i] = new QLabel(this);
        square_numb_label[i] = new QLabel(this);

        for(int j = 0; j < BOARD_ROWS; j++)
        {
            Sqares[i][j] = new QLabel(this);
            positions[i][j] = new QPushButton(this);
        }
    }

}


//creating chess board and buttons for the figures
void MainBoard::createBoard()
{

    for(int i = 0; i < BOARD_COLS; i++)
    {
        square_letter_label[i]->setText(letter_label[i]);
        square_letter_label[i]->setGeometry(x_axis[i] + 45, y_axis[7] + 100, squares_label_width, squares_label_height);

        square_numb_label[i]->setText(numb_label[i]);
        square_numb_label[i]->setGeometry(x_axis[0] - 25,y_axis[i] + 35, squares_label_width, squares_label_height);
        for(int j = 0; j < BOARD_ROWS; j++)
        {
            Sqares[i][j]->setGeometry(x_axis[i],y_axis[j], squares_size,squares_size);
            positions[i][j]->setGeometry(x_axis[i],y_axis[j], squares_size,squares_size);
            positions[i][j]->setIconSize(size);
            positions[i][j]->setStyleSheet("background-color: transparent;");
            if((i%2) == 0)
            {
                if((j % 2) == 0)
                {
                    Sqares[i][j]->setStyleSheet("background-color: #EBF5FF;");
                }
                else
                {
                    Sqares[i][j]->setStyleSheet("background-color: #6A1919;");
                }
            }
            else
            {
               if((j % 2) != 0)
               {
                    Sqares[i][j]->setStyleSheet("background-color: #EBF5FF ;");
               }
               else
               {
                    Sqares[i][j]->setStyleSheet("background-color: #6A1919;");
               }
            }
        }
    }

}

void MainBoard::RefreshBoard()
{

    int** currentBoard = cl->GetBoard();

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            //*figures[currentBoard[i][j]];
            if(currentBoard[i][j] > 0)
            {
                positions[i][j]->setIcon(*figures[currentBoard[i][j]]);
            }
            //qDebug() << i << "  " << j << "  " << currentBoard[i][j];
        }
    }

}


MainBoard::~MainBoard()
{
    delete ui;
    delete cl;
}

void MainBoard::on_pushButton_clicked()
{
    cl->Surrender();
    int state = cl->CheckResult();
    QMessageBox::information(0, QString("Information"), QString("You've surrendered. Player  " + QString::number(state) + " wins!"), QMessageBox::Ok);
}
