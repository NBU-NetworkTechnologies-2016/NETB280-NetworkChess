# NETB280-NetworkChess

Using the programming language C++ and the programming framework Qt write a computer program network chess game.
The program has graphical user interface (GUI) that represents a chess board and allows the user to play the game of chess against another user over the network.

The program supports the following network operations:

* given an IP address and port number the program connects over the network with the same client program on the machine that corresponds to the provided IP;
* when the user whose turn is makes a move, the program communicates over the network with the other client and sends the move information;
* when the game is over, the program displays the winner's user name, and asks if another game will be played.


The program supports the flowing visual capabilities:

* it visualizes a chess board and the black and white pieces on it;
* it does allow the user to move his/her pieces only if the move is legal;
* it allows game options like: propose a draw, quit, start new game.
* The program must suggest the user the set of possible moves when the user selects a piece to play with.
