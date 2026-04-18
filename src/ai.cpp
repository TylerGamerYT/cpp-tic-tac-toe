#include "ai.h"

char aiPlayer = 'O';
char human = 'X';

bool isMovesLeft(char board[3][3]) {
    for (auto &r : board)
        for (char c : r)
            if (c != 'X' && c != 'O')
                return true;
    return false;
}

int evaluate(char b[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (b[i][0]==b[i][1] && b[i][1]==b[i][2]) {
            if (b[i][0]==aiPlayer) return +10;
            else return -10;
        }
        if (b[0][i]==b[1][i] && b[1][i]==b[2][i]) {
            if (b[0][i]==aiPlayer) return +10;
            else return -10;
        }
    }

    if (b[0][0]==b[1][1] && b[1][1]==b[2][2]) {
        if (b[0][0]==aiPlayer) return +10;
        else return -10;
    }

    if (b[0][2]==b[1][1] && b[1][1]==b[2][0]) {
        if (b[0][2]==aiPlayer) return +10;
        else return -10;
    }

    return 0;
}

int AI::minimax(char board[3][3], bool isMax) {
    int score = evaluate(board);

    if (score == 10 || score == -10) return score;
    if (!isMovesLeft(board)) return 0;

    if (isMax) {
        int best = -1000;

        for (int i=0;i<3;i++)
            for (int j=0;j<3;j++)
                if (board[i][j] != 'X' && board[i][j] != 'O') {
                    char backup = board[i][j];
                    board[i][j] = aiPlayer;

                    best = std::max(best, minimax(board,false));

                    board[i][j] = backup;
                }

        return best;
    }

    int best = 1000;

    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                char backup = board[i][j];
                board[i][j] = human;

                best = std::min(best, minimax(board,true));

                board[i][j] = backup;
            }

    return best;
}

void AI::bestMove(char board[3][3], char &player) {
    int bestVal = -1000;
    int moveRow = -1, moveCol = -1;

    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                char backup = board[i][j];
                board[i][j] = aiPlayer;

                int moveVal = minimax(board,false);

                board[i][j] = backup;

                if (moveVal > bestVal) {
                    moveRow = i;
                    moveCol = j;
                    bestVal = moveVal;
                }
            }

    board[moveRow][moveCol] = aiPlayer;
}
