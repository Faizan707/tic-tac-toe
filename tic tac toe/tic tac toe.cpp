#include <iostream>
using namespace std;

char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };

void drawBoard() {
    cout << "  1   2   3" << endl;
    cout << "1 " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << " ---|---|---" << endl;
    cout << "2 " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << " ---|---|---" << endl;
    cout << "3 " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool placeMarker(int row, int col, char marker) {
    if (row < 1 || row > 3 || col < 1 || col > 3) {
        cout << "Invalid row or column number. Please enter a number between 1 and 3." << endl;
        return false;
    }
    if (board[row - 1][col - 1] != ' ') {
        cout << "That spot is already taken. Please choose a different spot." << endl;
        return false;
    }
    board[row - 1][col - 1] = marker;
    return true;
}

bool checkForWin(char marker) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == marker && board[i][1] == marker && board[i][2] == marker) {
            return true;
        }
    }
    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == marker && board[1][i] == marker && board[2][i] == marker) {
            return true;
        }
    }
    // Check diagonals
    if (board[0][0] == marker && board[1][1] == marker && board[2][2] == marker) {
        return true;
    }
    if (board[0][2] == marker && board[1][1] == marker && board[2][0] == marker) {
        return true;
    }
    return false;
}

int main() {
    cout << "Welcome to Tic Tac Toe!" << endl;
    drawBoard();
    int row, col;
    char player1 = 'X', player2 = 'O';
    char currentPlayer = player1;
    int turn = 0;
    while (true) {
        cout << "Player " << currentPlayer << ", enter a row (1-3): ";
        cin >> row;
        cout << "Player " << currentPlayer << ", enter a column (1-3): ";
        cin >> col;
        if (placeMarker(row, col, currentPlayer)) {
            drawBoard();
            if (checkForWin(currentPlayer)) {
                cout << "Player " << currentPlayer << " wins!" << endl;
                break;
            }
            if (turn == 8) {
                cout << "It's a tie!" << endl;
                break;
            }
            turn++;
            currentPlayer = (currentPlayer == player1) ? player2 : player1;
        }
    }
    return 0;
}
