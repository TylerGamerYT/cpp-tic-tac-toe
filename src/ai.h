#ifndef AI_H
#define AI_H

class AI {
public:
    void bestMove(char board[3][3], char &player);

private:
    int minimax(char board[3][3], bool isMax);
};

#endif
