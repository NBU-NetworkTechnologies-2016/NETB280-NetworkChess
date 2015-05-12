#include "mainboard.h"
#include "ui_mainboard.h"
#include <QTextStream>
#include <QLabel>
#include <QString>
#include <QPushButton>
#include <QIcon>
#include <QSize>

MainBoard::MainBoard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainBoard)
{
    ui->setupUi(this);
    this->setFixedSize(1920, 1080);
    this->setStyleSheet("background-color: #F0E8E8;");

     //tester to see position of QPushButtons
   //positions[0][2]->setStyleSheet("background-color: red;");
  // positions[2][1]->setEnabled(false);


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
    size.setHeight(60);
    size.setWidth(60);
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


//Functions that are creating all different figures
//creating PAWNS
void MainBoard::createPawns()
{
    for(int i = 0; i < BOARD_COLS; i++)
    {
        for(int j = 6; j < BOARD_ROWS - 1; j++)
        {
            positions[i][j]->setIcon(*whiteFigures[0]);//white pawns
            positions[i][j - 5]->setIcon(*blackFigures[0]);//black pawns
        }
    }
}
//creating BISHOPS
void MainBoard::createBishops()
{
    for(int i = 2; i <= 5; i = i + 3)
    {
        positions[i][7]->setIcon(*whiteFigures[1]);//creating white bishops
        positions[i][0]->setIcon(*blackFigures[1]);//creatinh black bishops
    }
}

//creating HORSES
void MainBoard::createHorses()
{
    for(int i = 1; i <=7; i = i +5)
    {
        positions[i][7]->setIcon(*whiteFigures[2]);//creating white horses
        positions[i][0]->setIcon(*blackFigures[2]);//creating black horses
    }
}
//creating ROOKS
void MainBoard::createRooks()
{
    for(int i = 0; i <=7; i = i + 7)
    {
        positions[i][7]->setIcon(*whiteFigures[3]);
        positions[i][0]->setIcon(*blackFigures[3]);
    }
}
//creating QUEENS
void MainBoard::createQueens()
{
    positions[3][7]->setIcon(*whiteFigures[4]);
    positions[3][0]->setIcon(*blackFigures[4]);
}

void MainBoard::createKings()
{
    positions[4][7]->setIcon(*whiteFigures[5]);
    positions[4][0]->setIcon(*blackFigures[5]);
}


//creating all figures(calling the upc reated functions)
void MainBoard::createFigures()
{
    createPawns();
    createBishops();
    createHorses();
    createRooks();
    createQueens();
    createKings();
}





MainBoard::~MainBoard()
{
    delete ui;
}
