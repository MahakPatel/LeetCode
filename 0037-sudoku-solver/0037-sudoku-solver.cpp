class Solution {
public:
    // TC O((9^(n^2)))
    // SC O(1)
    void solveSudoku(vector<vector<char>>& board) { solve(board); }

    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {     // Loop through all rows
            for (int j = 0; j < 9; j++) { // Loop through all columns
                if (board[i][j] == '.') { // Found an empty cell
                    for (char c = '1'; c <= '9';
                         c++) { // Try placing numbers 1-9
                        if (isValid(board, i, j,
                                    c)) {    // Check if the number is valid
                            board[i][j] = c; // Place the number

                            if (solve(board)) { // Recursively try to solve the
                                                // rest of the board
                                return true;    // If successful, return true
                            }

                            board[i][j] = '.'; // Backtrack if it leads to an
                                               // invalid state
                        }
                    }
                    return false; // No valid number could be placed, backtrack
                }
            }
        }
        return true; // If no empty cells remain, Sudoku is solved
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            // Check the row
            if (board[row][i] == c)
                return false;

            // Check the column
            if (board[i][col] == c)
                return false;

            // Check the 3x3 subgrid
            int subRow = 3 * (row / 3) + i / 3;
            int subCol = 3 * (col / 3) + i % 3;
            if (board[subRow][subCol] == c)
                return false;
        }
        return true; // Placement is valid
    }
};