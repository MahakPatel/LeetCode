class Solution {
public:
    void solve(int col, vector<vector<string>>& ans, vector<string>& board,
               int n, vector<int>& leftRow, vector<int>& upperDiagonal,
               vector<int>& lowerDiagonal) {
        // Base case: If all queens are placed, store the board configuration
        if (col == n) {
            ans.push_back(board);
            return;
        }

        // Try placing the queen in each row of the current column
        for (int row = 0; row < n; row++) {
            // Check if it's safe to place a queen at (row, col)
            if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 &&
                upperDiagonal[n - 1 + col - row] == 0) {

                // Place the queen
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;

                // Recur for the next column
                solve(col + 1, ans, board, n, leftRow, upperDiagonal,
                      lowerDiagonal);

                // Backtrack: Remove the queen and reset markers
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }

    // Function to solve N-Queens problem and return all valid board
    // configurations
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans; // Stores all possible solutions
        vector<string> board(n, string(n, '.')); // Initialize empty board

        // Arrays to track if a row, upper diagonal, or lower diagonal is
        // occupied
        vector<int> leftRow(n, 0);
        vector<int> upperDiagonal(2 * n - 1, 0);
        vector<int> lowerDiagonal(2 * n - 1, 0);

        // Start solving from the first column (col = 0)
        solve(0, ans, board, n, leftRow, upperDiagonal, lowerDiagonal);

        return ans;
    }
};