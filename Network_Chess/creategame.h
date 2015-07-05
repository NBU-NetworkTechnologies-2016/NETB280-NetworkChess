#ifndef CREATEGAME_H
#define CREATEGAME_H

#include <QDialog>

namespace Ui {
class CreateGame;
}

class CreateGame : public QDialog
{
    Q_OBJECT

public:
    explicit CreateGame(QWidget *parent = 0);
    ~CreateGame();

private:
    Ui::CreateGame *ui;
};

#endif // CREATEGAME_H
