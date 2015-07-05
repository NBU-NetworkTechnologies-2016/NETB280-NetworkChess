#include "menu.h"
#include "ui_menu.h"
#include "mainboard.h"
#include "qdebug.h"

Menu::Menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu)
{
    //MainBoard* w = new MainBoard();
    ui->setupUi(this);

}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_pushButton_released()
{

}

void Menu::on_pushButton_clicked()
{
    w.show();
}

//join game
void Menu::on_pushButton_3_clicked()
{
    jg.show();
}

/*
 * Start the new game
 */
void Menu::on_pushButton_4_clicked()
{

    w.show();
}

//create game
void Menu::on_pushButton_2_clicked()
{
    cg.show();
}
