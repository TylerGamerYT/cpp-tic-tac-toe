#ifndef GAME_H
#define GAME_H

class Game {
public:
    void menu();

private:
    char board[3][3];
    char player;
    int scoreX, scoreO;

    void startPvP();
    void startAI();

    void initBoard();
    void drawBoard();
    bool checkWin();
    bool checkDraw();
    void inputMove();

    void saveScore();
    void loadScore();
    void resetBoard();
};

#endif
