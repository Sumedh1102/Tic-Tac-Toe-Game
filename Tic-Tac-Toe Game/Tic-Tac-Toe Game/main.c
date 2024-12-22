#include <stdio.h>
#include <stdbool.h>

char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char currentPlayer = 'X';

void printBoard();
void makeMove();
bool checkWin();
bool isDraw();

int main() {
    printf("Welcome to Tic-Tac-Toe!\n");

    while (true) {
        printBoard();
        makeMove();

        if (checkWin()) {
            printBoard();
            printf("\nPlayer %c wins!\n", currentPlayer);
            break;
        } else if (isDraw()) {
            printBoard();
            printf("\nIt's a draw!\n");
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}

void printBoard() {
    printf("\n");
    printf(" %c | %c | %c \n", board[0], board[1], board[2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[3], board[4], board[5]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[6], board[7], board[8]);
    printf("\n");
}

void makeMove() {
    int choice;
    printf("Player %c, enter your move (1-9): ", currentPlayer);
    scanf("%d", &choice);

    if (choice < 1 || choice > 9 || board[choice - 1] == 'X' || board[choice - 1] == 'O') {
        printf("Invalid move! Try again.\n");
        makeMove();
    } else {
        board[choice - 1] = currentPlayer;
    }
}

bool checkWin() {
    int winPatterns[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
        {0, 4, 8}, {2, 4, 6}
    };

    for (int i = 0; i < 8; i++) {
        if (board[winPatterns[i][0]] == currentPlayer &&
            board[winPatterns[i][1]] == currentPlayer &&
            board[winPatterns[i][2]] == currentPlayer) {
            return true;
        }
    }
    return false;
}

bool isDraw() {
    for (int i = 0; i < 9; i++) {
        if (board[i] != 'X' && board[i] != 'O') {
            return false;
        }
    }
    return true;
}
