#include <iostream>
#include <fstream>
#include "game.h"

using namespace std;

void Game::initBoard() {
    char c = '1';
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = c++;
    player = 'X';
}

void Game::drawBoard() {
    system("clear"); // use "cls" on Windows

    cout << "\nTIC TAC TOE\n\n";

    for (int i = 0; i < 3; i++) {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << "\n";
        if (i < 2) cout << "---|---|---\n";
    }

    cout << "\nScore X: " << scoreX << " | Score O: " << scoreO << "\n\n";
}

bool Game::checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;

    return false;
}

bool Game::checkDraw() {
    for (auto &row : board)
        for (char c : row)
            if (c != 'X' && c != 'O')
                return false;
    return true;
}

void Game::inputMove() {
    int move;
    cout << "Player " << player << " move (1-9): ";
    cin >> move;

    if (move < 1 || move > 9) return;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == move + '0') {
                board[i][j] = player;
            }
        }
    }

    player = (player == 'X') ? 'O' : 'X';
}

void Game::saveScore() {
    ofstream file("data/scores.txt");
    file << scoreX << " " << scoreO;
    file.close();
}

void Game::loadScore() {
    ifstream file("data/scores.txt");
    if (file) file >> scoreX >> scoreO;
}

void Game::run() {
    loadScore();
    initBoard();

    while (true) {
        drawBoard();
        inputMove();

        if (checkWin()) {
            drawBoard();
            cout << "Winner: " << (player == 'X' ? 'O' : 'X') << endl;

            if (player == 'X') scoreO++;
            else scoreX++;

            saveScore();
            break;
        }

        if (checkDraw()) {
            drawBoard();
            cout << "Draw!\n";
            break;
        }
    }
}
