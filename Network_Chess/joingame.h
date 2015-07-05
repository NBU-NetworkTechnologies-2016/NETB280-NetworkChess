#ifndef JOINGAME_H
#define JOINGAME_H

#include <QDialog>

namespace Ui {
class JoinGame;
}

class JoinGame : public QDialog
{
    Q_OBJECT

public:
    explicit JoinGame(QWidget *parent = 0);
    ~JoinGame();

private:
    Ui::JoinGame *ui;
};

#endif // JOINGAME_H
