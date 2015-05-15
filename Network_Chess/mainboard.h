#ifndef MAINBOARD_H
#define MAINBOARD_H

#include <QMainWindow>
#include <QLabel>
#include <QString>
#include <QPushButton>
#include <QIcon>
#include <QSize>

#include "chesslogic.h";

namespace Ui {
class MainBoard;
}

class MainBoard : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainBoard(QWidget *parent = 0);

    void createPawns();
    void createBishops();
    void createHorses();
    void createRooks();
    void createQueens();
    void createKings();

    void RefreshBoard();
    void createFigures();

    void disableButtons();
    ~MainBoard();

private:
    void initializeBoard();
    void createBoard();

    void initializeFigures();
    Ui::MainBoard *ui;
    const static int BOARD_ROWS = 8;
    const static int BOARD_COLS = 8;

    const static int NUMBER_OF_FIGURES = 6;

    const static int squares_size = 100;
    const static int squares_label_width = 12;
    const static int squares_label_height = 20;

    int x_axis[8] = {480, 580, 680, 780, 880, 980, 1080, 1180}; //pushing columns from left to right, starting at 480 pixels
    int y_axis[8] = {50, 150, 250, 350, 450, 550, 650, 750}; //pushing rows from top to bottom, starting at 50 pixels

    // Stores the states and logic of the game
    //ChessLogic cl = ChessLogic(0);
    ChessLogic* cl;

    QString numb_label[8] ={"8", "7", "6", "5", "4", "3", "2", "1"};
    QString letter_label[8] = {"A", "B", "C", "D", "E", "F", "G", "H"};
    QString whiteFigureNames[NUMBER_OF_FIGURES] = {":/wPawn", ":/wBishop", ":/wHorse", ":/wRook", ":/wQueen", ":/wKing"};
    QString blackFigureNames[NUMBER_OF_FIGURES] = {":/bPawn", ":/bBishop", ":/bHorse", ":/bRook", ":/bQueen", ":/bKing"};

    QLabel* Sqares[BOARD_COLS][BOARD_ROWS];
    QLabel* square_numb_label[8];
    QLabel* square_letter_label[8];

    QPushButton* positions[BOARD_COLS][BOARD_ROWS]; //buttons ontop of sqares labels

    QIcon* blackFigures[NUMBER_OF_FIGURES];
    QIcon* whiteFigures[NUMBER_OF_FIGURES];

    QIcon* figures[40];

    QSize size;
};

#endif // MAINBOARD_H
