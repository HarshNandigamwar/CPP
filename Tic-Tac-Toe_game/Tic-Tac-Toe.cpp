#include <iostream>
using namespace std;

char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
char currentMarker;
int currentPlayer;

void drawBoard() {
    cout << " " << board[0][0] << " | " << board[0][1]<< " | " << board[0][2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[1][0] << " | " << board[1][1]<< " | " << board[1][2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[2][0] << " | " << board[2][1]<< " | " << board[2][2] << "\n\n";
}

bool placeMarker(int slot) {
    int row = (slot-1) / 3;
    int col = (slot-1) % 3;
    if(board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentMarker;
        return true;
    }
    return false;
}

int winner() {
    // Rows
    for(int i=0; i<3; i++)
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return currentPlayer;

    // Columns
    for(int i=0; i<3; i++)
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return currentPlayer;

    // Diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return currentPlayer;

    if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return currentPlayer;

    return 0;
}

bool boardFilled() {
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            if(board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

void swapPlayerAndMarker() {
    if(currentMarker == 'X') currentMarker = 'O';
    else currentMarker = 'X';

    if(currentPlayer == 1) currentPlayer = 2;
    else currentPlayer = 1;
}

int main() {
    cout << "Tic-Tac-Toe Game!\n";
    currentPlayer = 1;
    currentMarker = 'X';

    drawBoard();

    while(true) {
        int slot;
        cout << "Player " << currentPlayer << " (" << currentMarker << ") , enter slot (1-9): ";
        cin >> slot;

        if(slot < 1 || slot > 9) {
            cout << "Invalid slot. Try again.\n";
            continue;
        }

        if(!placeMarker(slot)) {
            cout << "Slot already taken! Try again.\n";
            continue;
        }

        drawBoard();

        if(winner() == currentPlayer) {
            cout << "Player " << currentPlayer << " wins! Congratulations!\n";
            break;
        } else if(boardFilled()) {
            cout << "It's a draw!\n";
            break;
        }

        swapPlayerAndMarker();
    }
    return 0;
}

// You can compile and run it like this:

// g++ tic_tac_toe.cpp -o tic_tac_toe
// ./tic_tac_toe
