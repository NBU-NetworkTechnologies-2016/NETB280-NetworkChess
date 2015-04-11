#include "mainboard.h"
#include "ui_mainboard.h"
#include <QTextStream>
#include <QLabel>
#include <QString>


MainBoard::MainBoard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainBoard)
{
    ui->setupUi(this);
    this->setFixedSize(1920, 1080);
    this->setStyleSheet("background-color: #85C2FF;");

    const int BOARD_ROWS = 8;
    const int BOARD_COLS = 8;
    const int squares_size = 100;
    const int squares_label_width = 12;
    const int squares_label_height = 20;
    const int x_axis[8] = {480, 580, 680, 780, 880, 980, 1080, 1180}; //pushing columns from left to right, starting at 480 pixels
    const int y_axis[8] = {50, 150, 250, 350, 450, 550, 650, 750}; //pushing rows from top to bottom, starting at 50 pixels
    const QString numb_label[8] ={"8", "7", "6", "5", "4", "3", "2", "1"};
    const QString letter_label[8] = {"A", "B", "C", "D", "E", "F", "G", "H"};

    QLabel* Sqares[BOARD_COLS][BOARD_ROWS];
    QLabel* square_numb_label[8];
    QLabel* square_letter_label[8];

    //initializing each QLabel
    for(int i = 0; i < 8; i++)
    {
        square_letter_label[i] = new QLabel(this);
        square_numb_label[i] = new QLabel(this);

        for(int j = 0; j < 8; j++)
        {
            Sqares[i][j] = new QLabel(this);
        }
    }
    //chess board
    for(int i = 0; i < 8; i++)
    {
        square_letter_label[i]->setText(letter_label[i]);
        square_letter_label[i]->setGeometry(x_axis[i] + 45, y_axis[7] + 100, squares_label_width, squares_label_height);

        square_numb_label[i]->setText(numb_label[i]);
        square_numb_label[i]->setGeometry(x_axis[0] - 25,y_axis[i] + 35, squares_label_width, squares_label_height);
        for(int j = 0; j < 8; j++)
        {
            Sqares[i][j]->setGeometry(x_axis[i],y_axis[j], squares_size,squares_size);


            if((i%2) == 0)
            {
                if((j % 2) == 0)
                {
                    Sqares[i][j]->setStyleSheet("background-color: white;");
                }
                else
                {
                    Sqares[i][j]->setStyleSheet("background-color: black;");
                }
            }
            else
            {
               if((j % 2) != 0)
               {
                    Sqares[i][j]->setStyleSheet("background-color: white ;");
               }
               else
               {
                    Sqares[i][j]->setStyleSheet("background-color: black;");
               }
            }
        }
    }

    /* tester to see position of QLabel
    Sqares[1][1]->setStyleSheet("background-color: red");
    */

}


MainBoard::~MainBoard()
{
    delete ui;
}
