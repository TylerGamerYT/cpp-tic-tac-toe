#include <iostream>
using namespace std;

char board[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

char player = 'X';

void drawBoard() {
    system("clear"); // use "cls" if you're on Windows

    cout << "\nTIC TAC TOE\n\n";

    for (int i = 0; i < 3; i++) {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << "\n";
        if (i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}

bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;

    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;

    return true;
}

void inputMove() {
    int move;
    cout << "Player " << player << " choose (1-9): ";
    cin >> move;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == move + '0') {
                board[i][j] = player;
            }
        }
    }

    player = (player == 'X') ? 'O' : 'X';
}

int main() {
    while (true) {
        drawBoard();
        inputMove();

        if (checkWin()) {
            drawBoard();
            cout << "Player " << (player == 'X' ? 'O' : 'X') << " wins!\n";
            break;
        }

        if (checkDraw()) {
            drawBoard();
            cout << "Draw!\n";
            break;
        }
    }

    return 0;
}
