#include <iostream>
#include <vector>

using namespace std;

int solutionCount = 0;

// Function to print the chessboard
void printBoard(const vector<vector<int> >& board, int n) {
    cout << "Solution Number" << ++solutionCount << ":" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (board[i][j] ? "Q " : "_ ");
        }
        cout << endl;
    }
    cout << "_____________________" << endl;
}

// Check if a queen can be safely placed
bool isSafe(const vector<vector<int> >& board, int row, int col, int n) {
    for (int i = 0; i < col; i++)
        if (board[row][i]) return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;

    for (int i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j]) return false;

    return true;
}

// Recursive function modified to find ALL solutions
void solveNQueens(vector<vector<int> >& board, int col, int n) {
    // Base case: If all queens are placed, print the board
    if (col == n) {
        printBoard(board, n);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            board[i][col] = 1; // Place queen

            // Recur to place the rest
            solveNQueens(board, col + 1, n);

            board[i][col] = 0; // Backtrack (Crucial for finding more solutions)
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of Queens (N): ";
    if (!(cin >> n) || n <= 0) {
        cout << "Invalid input." << endl;
        return 0;
    }

    // Initialize board with 0
    vector<vector<int> > board(n, vector<int>(n, 0));

    solveNQueens(board, 0, n);

    if (solutionCount == 0) {
        cout << "No solution exists for N = " << n << endl;
    } else {
        cout << "Total solutions found: " << solutionCount << endl;
    }

    return 0;
}
