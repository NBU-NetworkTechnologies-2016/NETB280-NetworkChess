#include "mainboard.h"
#include "ui_mainboard.h"
#include <QLabel>

MainBoard::MainBoard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainBoard)
{
    ui->setupUi(this);
    this->setFixedSize(1920, 1080);
    this->setStyleSheet("background-color: lightgray;");



    /*************Sqare A***************/
    //label 1
    QLabel *sqare_1 = new QLabel(this);
    sqare_1->setText("1");
    sqare_1->setGeometry(465,785, 12, 20);
    //label A
    QLabel *sqare_A = new QLabel(this);
    sqare_A->setText("A");
    sqare_A->setGeometry(525, 850, 12, 20);
    sqare_A->setVisible(true);
    // A1
    QLabel *sqare_A1 = new QLabel(this);
    sqare_A1->setStyleSheet("background-color: black;");
    sqare_A1->setGeometry(480, 750, 100, 100);
    sqare_A1->setVisible(true);
    // A2
    QLabel *sqare_A2 = new QLabel(this);
    sqare_A2->setStyleSheet("background-color: white;");
    sqare_A2->setGeometry(480, 650, 100, 100);
    sqare_A2->setVisible(true);
    // A3
    QLabel *sqare_A3 = new QLabel(this);
    sqare_A3->setStyleSheet("background-color: black;");
    sqare_A3->setGeometry(480, 550, 100, 100);
    sqare_A3->setVisible(true);
    // A4
    QLabel *sqare_A4 = new QLabel(this);
    sqare_A4->setStyleSheet("background-color: white;");
    sqare_A4->setGeometry(480, 450, 100, 100);
    sqare_A4->setVisible(true);
    // A5
    QLabel *sqare_A5 = new QLabel(this);
    sqare_A5->setStyleSheet("background-color: black;");
    sqare_A5->setGeometry(480, 350, 100, 100);
    sqare_A5->setVisible(true);
    // A6
    QLabel *sqare_A6 = new QLabel(this);
    sqare_A6->setStyleSheet("background-color: white;");
    sqare_A6->setGeometry(480, 250, 100, 100);
    sqare_A6->setVisible(true);
    // A7
    QLabel *sqare_A7 = new QLabel(this);
    sqare_A7->setStyleSheet("background-color: black;");
    sqare_A7->setGeometry(480, 150, 100, 100);
    sqare_A7->setVisible(true);
    // A8
    QLabel *sqare_A8 = new QLabel(this);
    sqare_A8->setStyleSheet("background-color: white;");
    sqare_A8->setGeometry(480, 50, 100, 100);
    sqare_A8->setVisible(true);



    /*************Sqare B***************/
    //label 2
    QLabel *sqare_2 = new QLabel(this);
    sqare_2->setText("2");
    sqare_2->setGeometry(465,685, 12, 20);
    //label B
    QLabel *sqare_B = new QLabel(this);
    sqare_B->setText("B");
    sqare_B->setGeometry(625, 850, 12, 20);
    sqare_B->setVisible(true);
    // B1
    QLabel *sqare_B1 = new QLabel(this);
    sqare_B1->setStyleSheet("background-color: white;");
    sqare_B1->setGeometry(580, 750, 100, 100);
    sqare_B1->setVisible(true);
    // B2
    QLabel *sqare_B2 = new QLabel(this);
    sqare_B2->setStyleSheet("background-color: black;");
    sqare_B2->setGeometry(580, 650, 100, 100);
    sqare_B2->setVisible(true);
    // B3
    QLabel *sqare_B3 = new QLabel(this);
    sqare_B3->setStyleSheet("background-color: white;");
    sqare_B3->setGeometry(580, 550, 100, 100);
    sqare_B3->setVisible(true);
    // B4
    QLabel *sqare_B4 = new QLabel(this);
    sqare_B4->setStyleSheet("background-color: black;");
    sqare_B4->setGeometry(580, 450, 100, 100);
    sqare_B4->setVisible(true);
    // B5
    QLabel *sqare_B5 = new QLabel(this);
    sqare_B5->setStyleSheet("background-color: white;");
    sqare_B5->setGeometry(580, 350, 100, 100);
    sqare_B5->setVisible(true);
    // B6
    QLabel *sqare_B6 = new QLabel(this);
    sqare_B6->setStyleSheet("background-color: black;");
    sqare_B6->setGeometry(580, 250, 100, 100);
    sqare_B6->setVisible(true);
    // B7
    QLabel *sqare_B7 = new QLabel(this);
    sqare_B7->setStyleSheet("background-color: white;");
    sqare_B7->setGeometry(580, 150, 100, 100);
    sqare_B7->setVisible(true);
    // B8
    QLabel *sqare_B8 = new QLabel(this);
    sqare_B8->setStyleSheet("background-color: black;");
    sqare_B8->setGeometry(580, 50, 100, 100);
    sqare_B8->setVisible(true);



    /*************Sqare C***************/
    //label 1
    QLabel *sqare_3 = new QLabel(this);
    sqare_3->setText("3");
    sqare_3->setGeometry(465,585, 12, 20);
    //label C
    QLabel *sqare_C = new QLabel(this);
    sqare_C->setText("C");
    sqare_C->setGeometry(725, 850, 12, 20);
    sqare_C->setVisible(true);
    // C1
    QLabel *sqare_C1 = new QLabel(this);
    sqare_C1->setStyleSheet("background-color: black;");
    sqare_C1->setGeometry(680, 750, 100, 100);
    sqare_C1->setVisible(true);
    // C2
    QLabel *sqare_C2 = new QLabel(this);
    sqare_C2->setStyleSheet("background-color: white;");
    sqare_C2->setGeometry(680, 650, 100, 100);
    sqare_C2->setVisible(true);
    // C3
    QLabel *sqare_C3 = new QLabel(this);
    sqare_C3->setStyleSheet("background-color: black;");
    sqare_C3->setGeometry(680, 550, 100, 100);
    sqare_C3->setVisible(true);
    // C4
    QLabel *sqare_C4 = new QLabel(this);
    sqare_C4->setStyleSheet("background-color: white;");
    sqare_C4->setGeometry(680, 450, 100, 100);
    sqare_C4->setVisible(true);
    // C5
    QLabel *sqare_C5 = new QLabel(this);
    sqare_C5->setStyleSheet("background-color: black;");
    sqare_C5->setGeometry(680, 350, 100, 100);
    sqare_C5->setVisible(true);
    // C6
    QLabel *sqare_C6 = new QLabel(this);
    sqare_C6->setStyleSheet("background-color: white;");
    sqare_C6->setGeometry(680, 250, 100, 100);
    sqare_C6->setVisible(true);
    // C7
    QLabel *sqare_C7 = new QLabel(this);
    sqare_C7->setStyleSheet("background-color: black;");
    sqare_C7->setGeometry(680, 150, 100, 100);
    sqare_C7->setVisible(true);
    // C8
    QLabel *sqare_C8 = new QLabel(this);
    sqare_C8->setStyleSheet("background-color: white;");
    sqare_C8->setGeometry(680, 50, 100, 100);
    sqare_C8->setVisible(true);



    /*************Sqare D***************/
    //label 4
    QLabel *sqare_4 = new QLabel(this);
    sqare_4->setText("4");
    sqare_4->setGeometry(465,485, 12, 20);
    //label D
    QLabel *sqare_D = new QLabel(this);
    sqare_D->setText("D");
    sqare_D->setGeometry(825, 850, 12, 20);
    sqare_D->setVisible(true);
    // D1
    QLabel *sqare_D1 = new QLabel(this);
    sqare_D1->setStyleSheet("background-color: white;");
    sqare_D1->setGeometry(780, 750, 100, 100);
    sqare_D1->setVisible(true);
    // D2
    QLabel *sqare_D2 = new QLabel(this);
    sqare_D2->setStyleSheet("background-color: black;");
    sqare_D2->setGeometry(780, 650, 100, 100);
    sqare_D2->setVisible(true);
    // D3
    QLabel *sqare_D3 = new QLabel(this);
    sqare_D3->setStyleSheet("background-color: white;");
    sqare_D3->setGeometry(780, 550, 100, 100);
    sqare_D3->setVisible(true);
    // D4
    QLabel *sqare_D4 = new QLabel(this);
    sqare_D4->setStyleSheet("background-color: black;");
    sqare_D4->setGeometry(780, 450, 100, 100);
    sqare_D4->setVisible(true);
    // D5
    QLabel *sqare_D5 = new QLabel(this);
    sqare_D5->setStyleSheet("background-color: white;");
    sqare_D5->setGeometry(780, 350, 100, 100);
    sqare_D5->setVisible(true);
    // D6
    QLabel *sqare_D6 = new QLabel(this);
    sqare_D6->setStyleSheet("background-color: black;");
    sqare_D6->setGeometry(780, 250, 100, 100);
    sqare_D6->setVisible(true);
    // D7
    QLabel *sqare_D7 = new QLabel(this);
    sqare_D7->setStyleSheet("background-color: white;");
    sqare_D7->setGeometry(780, 150, 100, 100);
    sqare_D7->setVisible(true);
    // D8
    QLabel *sqare_D8 = new QLabel(this);
    sqare_D8->setStyleSheet("background-color: black;");
    sqare_D8->setGeometry(780, 50, 100, 100);
    sqare_D8->setVisible(true);



    /*************Sqare E***************/
    //label 5
    QLabel *sqare_5 = new QLabel(this);
    sqare_5->setText("5");
    sqare_5->setGeometry(465,385, 12, 20);
    //label E
    QLabel *sqare_E = new QLabel(this);
    sqare_E->setText("E");
    sqare_E->setGeometry(925, 850, 12, 20);
    sqare_E->setVisible(true);
    // E1
    QLabel *sqare_E1 = new QLabel(this);
    sqare_E1->setStyleSheet("background-color: black;");
    sqare_E1->setGeometry(880, 750, 100, 100);
    sqare_E1->setVisible(true);
    // E2
    QLabel *sqare_E2 = new QLabel(this);
    sqare_E2->setStyleSheet("background-color: white;");
    sqare_E2->setGeometry(880, 650, 100, 100);
    sqare_E2->setVisible(true);
    // E3
    QLabel *sqare_E3 = new QLabel(this);
    sqare_E3->setStyleSheet("background-color: black;");
    sqare_E3->setGeometry(880, 550, 100, 100);
    sqare_E3->setVisible(true);
    // E4
    QLabel *sqare_E4 = new QLabel(this);
    sqare_E4->setStyleSheet("background-color: white;");
    sqare_E4->setGeometry(880, 450, 100, 100);
    sqare_E4->setVisible(true);
    // E5
    QLabel *sqare_E5 = new QLabel(this);
    sqare_E5->setStyleSheet("background-color: black;");
    sqare_E5->setGeometry(880, 350, 100, 100);
    sqare_E5->setVisible(true);
    // E6
    QLabel *sqare_E6 = new QLabel(this);
    sqare_E6->setStyleSheet("background-color: white;");
    sqare_E6->setGeometry(880, 250, 100, 100);
    sqare_E6->setVisible(true);
    // E7
    QLabel *sqare_E7 = new QLabel(this);
    sqare_E7->setStyleSheet("background-color: black;");
    sqare_E7->setGeometry(880, 150, 100, 100);
    sqare_E7->setVisible(true);
    // E8
    QLabel *sqare_E8 = new QLabel(this);
    sqare_E8->setStyleSheet("background-color: white;");
    sqare_E8->setGeometry(880, 50, 100, 100);
    sqare_E8->setVisible(true);



    /*************Sqare F***************/
    //label 6
    QLabel *sqare_6 = new QLabel(this);
    sqare_6->setText("6");
    sqare_6->setGeometry(465,285, 12, 20);
    //label F
    QLabel *sqare_F = new QLabel(this);
    sqare_F->setText("F");
    sqare_F->setGeometry(1025, 850, 12, 20);
    sqare_F->setVisible(true);
    // F1
    QLabel *sqare_F1 = new QLabel(this);
    sqare_F1->setStyleSheet("background-color: white;");
    sqare_F1->setGeometry(980, 750, 100, 100);
    sqare_F1->setVisible(true);
    // F2
    QLabel *sqare_F2 = new QLabel(this);
    sqare_F2->setStyleSheet("background-color: black;");
    sqare_F2->setGeometry(980, 650, 100, 100);
    sqare_F2->setVisible(true);
    // F3
    QLabel *sqare_F3 = new QLabel(this);
    sqare_F3->setStyleSheet("background-color: white;");
    sqare_F3->setGeometry(980, 550, 100, 100);
    sqare_F3->setVisible(true);
    // F4
    QLabel *sqare_F4 = new QLabel(this);
    sqare_F4->setStyleSheet("background-color: black;");
    sqare_F4->setGeometry(980, 450, 100, 100);
    sqare_F4->setVisible(true);
    // F5
    QLabel *sqare_F5 = new QLabel(this);
    sqare_F5->setStyleSheet("background-color: white;");
    sqare_F5->setGeometry(980, 350, 100, 100);
    sqare_F5->setVisible(true);
    // F6
    QLabel *sqare_F6 = new QLabel(this);
    sqare_F6->setStyleSheet("background-color: black;");
    sqare_F6->setGeometry(980, 250, 100, 100);
    sqare_F6->setVisible(true);
    // F7
    QLabel *sqare_F7 = new QLabel(this);
    sqare_F7->setStyleSheet("background-color: white;");
    sqare_F7->setGeometry(980, 150, 100, 100);
    sqare_F7->setVisible(true);
    // F8
    QLabel *sqare_F8 = new QLabel(this);
    sqare_F8->setStyleSheet("background-color: black;");
    sqare_F8->setGeometry(980, 50, 100, 100);
    sqare_F8->setVisible(true);


    /*************Sqare G***************/
    //label 7
    QLabel *sqare_7 = new QLabel(this);
    sqare_7->setText("7");
    sqare_7->setGeometry(465,185, 12, 20);
    //label G
    QLabel *sqare_G = new QLabel(this);
    sqare_G->setText("G");
    sqare_G->setGeometry(1125, 850, 12, 20);
    sqare_G->setVisible(true);
    // G1
    QLabel *sqare_G1 = new QLabel(this);
    sqare_G1->setStyleSheet("background-color: black;");
    sqare_G1->setGeometry(1080, 750, 100, 100);
    sqare_G1->setVisible(true);
    // G2
    QLabel *sqare_G2 = new QLabel(this);
    sqare_G2->setStyleSheet("background-color: white;");
    sqare_G2->setGeometry(1080, 650, 100, 100);
    sqare_G2->setVisible(true);
    // G3
    QLabel *sqare_G3 = new QLabel(this);
    sqare_G3->setStyleSheet("background-color: black;");
    sqare_G3->setGeometry(1080, 550, 100, 100);
    sqare_G3->setVisible(true);
    // G4
    QLabel *sqare_G4 = new QLabel(this);
    sqare_G4->setStyleSheet("background-color: white;");
    sqare_G4->setGeometry(1080, 450, 100, 100);
    sqare_G4->setVisible(true);
    // G5
    QLabel *sqare_G5 = new QLabel(this);
    sqare_G5->setStyleSheet("background-color: black;");
    sqare_G5->setGeometry(1080, 350, 100, 100);
    sqare_G5->setVisible(true);
    // G6
    QLabel *sqare_G6 = new QLabel(this);
    sqare_G6->setStyleSheet("background-color: white;");
    sqare_G6->setGeometry(1080, 250, 100, 100);
    sqare_G6->setVisible(true);
    // G7
    QLabel *sqare_G7 = new QLabel(this);
    sqare_G7->setStyleSheet("background-color: black;");
    sqare_G7->setGeometry(1080, 150, 100, 100);
    sqare_G7->setVisible(true);
    // G8
    QLabel *sqare_G8 = new QLabel(this);
    sqare_G8->setStyleSheet("background-color: white;");
    sqare_G8->setGeometry(1080, 50, 100, 100);
    sqare_G8->setVisible(true);


    /*************Sqare H***************/
    //label 8
    QLabel *sqare_8 = new QLabel(this);
    sqare_8->setText("8");
    sqare_8->setGeometry(465,85, 12, 20);
    //label H
    QLabel *sqare_H = new QLabel(this);
    sqare_H->setText("H");
    sqare_H->setGeometry(1225, 850, 12, 20);
    sqare_H->setVisible(true);
    // H1
    QLabel *sqare_H1 = new QLabel(this);
    sqare_H1->setStyleSheet("background-color: white;");
    sqare_H1->setGeometry(1180, 750, 100, 100);
    sqare_H1->setVisible(true);
    // H2
    QLabel *sqare_H2 = new QLabel(this);
    sqare_H2->setStyleSheet("background-color: black;");
    sqare_H2->setGeometry(1180, 650, 100, 100);
    sqare_H2->setVisible(true);
    // H3
    QLabel *sqare_H3 = new QLabel(this);
    sqare_H3->setStyleSheet("background-color: white;");
    sqare_H3->setGeometry(1180, 550, 100, 100);
    sqare_H3->setVisible(true);
    // H4
    QLabel *sqare_H4 = new QLabel(this);
    sqare_H4->setStyleSheet("background-color: black;");
    sqare_H4->setGeometry(1180, 450, 100, 100);
    sqare_H4->setVisible(true);
    // H5
    QLabel *sqare_H5 = new QLabel(this);
    sqare_H5->setStyleSheet("background-color: white;");
    sqare_H5->setGeometry(1180, 350, 100, 100);
    sqare_H5->setVisible(true);
    // H6
    QLabel *sqare_H6 = new QLabel(this);
    sqare_H6->setStyleSheet("background-color: black;");
    sqare_H6->setGeometry(1180, 250, 100, 100);
    sqare_H6->setVisible(true);
    // H7
    QLabel *sqare_H7 = new QLabel(this);
    sqare_H7->setStyleSheet("background-color: white;");
    sqare_H7->setGeometry(1180, 150, 100, 100);
    sqare_H7->setVisible(true);
    // H8
    QLabel *sqare_H8 = new QLabel(this);
    sqare_H8->setStyleSheet("background-color: black;");
    sqare_H8->setGeometry(1180, 50, 100, 100);
    sqare_H8->setVisible(true);


}


MainBoard::~MainBoard()
{
    delete ui;
}
