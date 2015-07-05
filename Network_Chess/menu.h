#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include "mainboard.h"
#include "creategame.h"

namespace Ui {
class Menu;
}

class Menu : public QDialog
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = 0);
    ~Menu();

private slots:
    void on_pushButton_released();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Menu *ui;
    MainBoard w;
    CreateGame cg;
};

#endif // MENU_H
