#include "joingame.h"
#include "ui_joingame.h"

JoinGame::JoinGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JoinGame)
{
    ui->setupUi(this);
}

JoinGame::~JoinGame()
{
    delete ui;
}
