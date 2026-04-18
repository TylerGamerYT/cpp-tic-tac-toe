#ifndef GAME_H
#define GAME_H

class Game {
public:
    void run();

private:
    char board[3][3];
    char player;
    int scoreX, scoreO;

    void initBoard();
    void drawBoard();
    bool checkWin();
    bool checkDraw();
    void inputMove();
    void saveScore();
    void loadScore();
};

#endif
