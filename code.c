#include <stdio.h>
#include <stdbool.h>

#define BOARD_SIZE 3

char board[BOARD_SIZE][BOARD_SIZE]; // The Tic-Tac-Toe board

// Initialize the board with empty spaces
void initializeBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Display the current state of the board
void displayBoard() {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < BOARD_SIZE - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i < BOARD_SIZE - 1) {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

// Check if the game is over (either a player wins or the board is full)
bool isGameOver() {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < BOARD_SIZE; i++) {
        // Check rows
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true; // Row win
        }
        // Check columns
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return true; // Column win
        }
    }
    // Check diagonals
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true; // Diagonal (top-left to bottom-right) win
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true; // Diagonal (top-right to bottom-left) win
    }

    // Check if the board is full (draw)
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                return false; // Board is not full
            }
        }
    }
    return true; // Board is full (draw)
}

// Get player's move (row and column)
void getPlayerMove(int *row, int *col) {
    printf("Enter your move (row and column): ");
    scanf("%d %d", row, col);
    while (getchar() != '\n'); // Clear input buffer
}

// Make a move on the board
void makeMove(int row, int col, char player) {
    if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == ' ') {
        board[row][col] = player;
    } else {
        printf("Invalid move. Try again.\n");
        getPlayerMove(&row, &col);
        makeMove(row, col, player);
    }
}

int main() {
    char currentPlayer = 'X'; // Starting player ('X' goes first)
    int row, col;

    initializeBoard();

    printf("Welcome to Tic-Tac-Toe!\n");
    printf("Player 'X' will go first.\n");

    while (!isGameOver()) {
        displayBoard();
        getPlayerMove(&row, &col);
        makeMove(row, col, currentPlayer);

        // Switch player for the next turn
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    displayBoard();

    // Determine the winner or declare a draw
    char winner = (currentPlayer == 'X') ? 'O' : 'X';
    if (isGameOver()) {
        printf("Game over!\n");
        printf("Player '%c' wins!\n", winner);
    } else {
        printf("It's a draw!\n");
    }

    return 0;
}
