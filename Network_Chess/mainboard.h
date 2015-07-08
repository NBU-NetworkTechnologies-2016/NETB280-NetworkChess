#ifndef MAINBOARD_H
#define MAINBOARD_H

#include <QMainWindow>
#include <QLabel>
#include <QString>
#include <QPushButton>
#include <QIcon>
#include <QSize>
#include <QObject>
#include <QSignalMapper>
#include <QMessageBox>

#include "chesslogic.h";

namespace Ui {
class MainBoard;
}

class MainBoard : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainBoard(QWidget *parent = 0);

    //sasho test
    bool onMove = false;
    QIcon currentPieceIcon;
    int globalButtonCoordinateX;//the container for the current pressed button coordinates X axis
    int globalButtonCoordinateY;//analogy
    int oldGlobalButtonCoordinateX;//the X axis coordinates of the first selected piece
    int oldGlobalButtonCoordinateY;//analogy
    int mappedButtons;//mapped values, index of a pushed button
    //end sasho test

    void RefreshBoard();
    void createFigures();

    void disableButtons();
    void pieceSignals();
    void RefreshBoard1(int x, int y);
    ~MainBoard();

private slots:
    //sasho test
    void movePieceStart(int);//the start fuction that is triggered when we click on a piece we wish to move
    void movingPieces();//the end function that is triggered when we click on the button we wish to move on
    //end sasho test
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    //sasho test
    QSignalMapper *mapper;//mapper that will map some value on every button

    //sasho end
    void initializeBoard();
    void createBoard();

    void initializeFigures();

    int phase; //curent part of turn

    Ui::MainBoard *ui;
    const static int BOARD_ROWS = 8;
    const static int BOARD_COLS = 8;

    const static int NUMBER_OF_FIGURES = 7;

    const static int squares_size = 100;
    const static int squares_label_width = 12;
    const static int squares_label_height = 20;

    int x_axis[8] = {240, 290, 340, 390, 440, 490, 540, 590}; //pushing columns from left to right, starting at 480 pixels
    int y_axis[8] = {25, 75, 125, 175, 225, 275, 325, 375}; //pushing rows from top to bottom, starting at 50 pixels

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

    QIcon* figures[101];

    QSize size;
};

#endif // MAINBOARD_H
