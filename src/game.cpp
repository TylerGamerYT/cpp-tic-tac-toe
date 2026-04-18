#include <iostream>
#include <fstream>
#include "game.h"
#include "ai.h"

using namespace std;

void Game::menu() {
    loadScore();

    int choice;

    while (true) {
        cout << "\n=== TIC TAC TOE ===\n";
        cout << "1. Player vs Player\n";
        cout << "2. Player vs AI\n";
        cout << "3. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) startPvP();
        else if (choice == 2) startAI();
        else break;
    }
}

void Game::initBoard() {
    char c = '1';
    for (auto &row : board)
        for (char &cell : row)
            cell = c++;

    player = 'X';
}

void Game::resetBoard() {
    initBoard();
}

void Game::drawBoard() {
    system("clear"); // cls for Windows

    cout << "\nTIC TAC TOE\n\n";

    for (int i = 0; i < 3; i++) {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << "\n";
        if (i < 2) cout << "---|---|---\n";
    }

    cout << "\nScore X: " << scoreX << " | Score O: " << scoreO << "\n";
}

bool Game::checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0]==board[i][1] && board[i][1]==board[i][2]) return true;
        if (board[0][i]==board[1][i] && board[1][i]==board[2][i]) return true;
    }

    if (board[0][0]==board[1][1] && board[1][1]==board[2][2]) return true;
    if (board[0][2]==board[1][1] && board[1][1]==board[2][0]) return true;

    return false;
}

bool Game::checkDraw() {
    for (auto &r : board)
        for (char c : r)
            if (c != 'X' && c != 'O')
                return false;
    return true;
}

void Game::inputMove() {
    int move;
    cout << "Player " << player << " move (1-9): ";
    cin >> move;

    for (auto &row : board)
        for (char &cell : row)
            if (cell == move + '0')
                cell = player;

    player = (player == 'X') ? 'O' : 'X';
}

void Game::saveScore() {
    ofstream file("data/scores.txt");
    file << scoreX << " " << scoreO;
}

void Game::loadScore() {
    ifstream file("data/scores.txt");
    if (file) file >> scoreX >> scoreO;
}

void Game::startPvP() {
    resetBoard();

    while (true) {
        drawBoard();
        inputMove();

        if (checkWin()) {
            drawBoard();
            cout << "Winner: " << (player=='X'?'O':'X') << "\n";
            if (player=='X') scoreO++; else scoreX++;
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

void Game::startAI() {
    resetBoard();
    AI ai;

    while (true) {
        drawBoard();

        if (player == 'X') {
            inputMove();
        } else {
            ai.bestMove(board, player);
            player = 'X';
        }

        if (checkWin()) {
            drawBoard();
            cout << "Winner: " << (player=='X'?'O':'X') << "\n";
            if (player=='X') scoreO++; else scoreX++;
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
