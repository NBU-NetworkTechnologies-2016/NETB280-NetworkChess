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
    onMove = false;
    ui->setupUi(this);
    this->setFixedSize(1920, 1080);
    this->setStyleSheet("background-color: #F0E8E8;");

    phase = 0;

    cl = new ChessLogic();

    QString whiteFigureNames[NUMBER_OF_FIGURES] = {":/wPawn", ":/wBishop", ":/wHorse", ":/wRook", ":/wQueen", ":/wKing"};
    QString blackFigureNames[NUMBER_OF_FIGURES] = {":/bPawn", ":/bBishop", ":/bHorse", ":/bRook", ":/bQueen", ":/bKing", ":/red.png"};
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

    figures[100] =new QIcon( blackFigureNames[6]);
    //Initialize Figures
    size.setHeight(30);
    size.setWidth(30);




    initializeBoard(); //initializing the QLabel & QPushButton objects
    initializeFigures();//initializing QIcons (figures)
    createBoard(); //creating the board and the QpushButtons on top of the board
    RefreshBoard();
    //positions[5][5]->setStyleSheet("background-color: red");
    mapper = new QSignalMapper(this);//initializing the mapper
    connect(mapper, SIGNAL(mapped(int)), this, SLOT(movePieceStart(int)));//connecting the mapper with signal that wil return int to the first phase function
    int holder[8][8];//2d array with corresponding indexed with the buttons coordinates


    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            holder[0][j] = 100 + j;//assigning some specific values, so we can transfor them later into appropriate index values
            if(i > 0)
            {
                holder[i][j] = (i * 10) + j;//example: holder[0][1] will contain 101 value, holder[3][2] will container 32 
            }

            mapper->setMapping(positions[i][j], holder[i][j]);//mapping the buttons with the holder array
            connect(positions[i][j], SIGNAL(clicked()), mapper, SLOT(map()));//connecting all the buttons with the mapper

        }

    }

    pieceSignals();//signals for the second click

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
//the second phase function that will triger we select the button we wish to move out already selected piece
void MainBoard::movingPieces()
{
    qDebug() << "!!!!!!!!!!!!! MOVING_PIECES  phase: " << phase;

    if(phase <= 1)
    {
        return;
    }
    phase = 0;

    if(onMove)//if we are on the move
    {
        
        qDebug() << "onMove-true";
        positions[oldGlobalButtonCoordinateX][oldGlobalButtonCoordinateY]->setIcon(QIcon());//we remove the icon on the first selected button
        //positions[globalButtonCoordinateX][globalButtonCoordinateY]->setIcon(currentPieceIcon);
        cl->MovePiece(oldGlobalButtonCoordinateX, oldGlobalButtonCoordinateY,
                      globalButtonCoordinateX, globalButtonCoordinateY);
        int game_state = cl->CheckResult();//checks the game state
        if(game_state != 0)//if we have a winner
        {
            QMessageBox::information(0, QString("Information"), QString("The game has finished. Player  " + QString::number(game_state) + " wins!"), QMessageBox::Ok);
        }

        //onMove = false;
    }
    RefreshBoard();//we refresh the board
}
//the first phase function that will triger when we select a piece we wish to move
void MainBoard::movePieceStart(int i)
{
    mappedButtons = i;//we assign the mapped values to i, the parameter of the function

    int firstColumn = 100;//first column mapping
    int currentX = 0;//all other columns mapping
    //we calculate the appropriate indexx values from the mapped vlues we get
    //example: i = 55, globalButtonCoordinateX = 5; globalButtonCoordinateY = 5;
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
    qDebug() << "X: " << globalButtonCoordinateX;//check if we get the correct values
    qDebug() << "Y: " << globalButtonCoordinateY;

    if(phase == 1)
    {
        phase++;
    }

    QIcon currentIcon = positions[globalButtonCoordinateX][globalButtonCoordinateY]->icon();//we contain the current selected icon to currentIcon
    if((currentIcon.isNull()) == false )//if the button we click has an icon proceed
    {

        phase++;
        if(phase == 3)
        {
            return;
        }
        onMove = true;//we notify that we are on a move when a button with icon is clicked
        currentPieceIcon = positions[globalButtonCoordinateX][globalButtonCoordinateY]->icon();//we put the icon of the button that is clicked into a global QIcon valuable
        oldGlobalButtonCoordinateX = globalButtonCoordinateX;//we save the coordinates of the first button into a seperate variable
        oldGlobalButtonCoordinateY = globalButtonCoordinateY;
    }
    if(phase == 1)
    {
        RefreshBoard1(oldGlobalButtonCoordinateX, oldGlobalButtonCoordinateY);//the possible moves for the selected piece
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
        square_letter_label[i]->setGeometry(x_axis[i] + 23, y_axis[7] + 50, squares_label_width, squares_label_height);

        square_numb_label[i]->setText(numb_label[i]);
        square_numb_label[i]->setGeometry(x_axis[0] - 13,y_axis[i] + 18, squares_label_width, squares_label_height);
        for(int j = 0; j < BOARD_ROWS; j++)
        {
            Sqares[i][j]->setGeometry(x_axis[i],y_axis[j], 50,50);
            positions[i][j]->setGeometry(x_axis[i],y_axis[j], 50,50);
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

            if(currentBoard[i][j] > 0)
            {
                positions[i][j]->setIcon(*figures[currentBoard[i][j]]);
            }
            else if(currentBoard[i][j] == 0)
            {
                positions[i][j]->setIcon(QIcon());
            }
        }
    }

}

void MainBoard::RefreshBoard1(int x, int y)
{

    int** currentBoard = cl->GetPossibleTurnsVisual(x, y);

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            qDebug() << i << "  " << j << "  ";
            //*figures[currentBoard[i][j]];
            if(currentBoard[i][j] > 0)
            {
                positions[i][j]->setIcon(*figures[currentBoard[i][j]]);
            }
            qDebug() << i << "  " << j << "  " << currentBoard[i][j];
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

void MainBoard::on_pushButton_2_clicked()
{
    cl->Surrender();
    int state = cl->CheckResult();
    QMessageBox::information(0, QString("Information"), QString("The game is a draw as proposed by both players!"), QMessageBox::Ok);
}
