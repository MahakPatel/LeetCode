class Solution {
private:
    // Depth-first search function to mark connected 'O's
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &board, int delRow[], int delCol[]) {
        vis[row][col] = 1; // Mark the current cell as visited
        int n = board.size(); // Number of rows in the board
        int m = board[0].size(); // Number of columns in the board

        // Explore all four possible directions
        for (int i = 0; i < 4; i++) {
            int nrow = row + delRow[i]; // New row index
            int ncol = col + delCol[i]; // New column index

            // Check for valid position and if it contains 'O'
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && board[nrow][ncol] == 'O') {
                dfs(nrow, ncol, vis, board, delRow, delCol); // Recursive call
            }
        }
    }

public:
    // Main function to solve the surrounded regions problem
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return; // Handle empty board case

        int n = board.size(); // Number of rows
        int m = board[0].size(); // Number of columns
        int delRow[] = {-1, 0, +1, 0}; // Directions for row movement
        int delCol[] = {0, 1, 0, -1}; // Directions for column movement
        vector<vector<int>> vis(n, vector<int>(m, 0)); // Visited array

        // Check the first and last rows for 'O's
        for (int j = 0; j < m; j++) {
            if (!vis[0][j] && board[0][j] == 'O') {
                dfs(0, j, vis, board, delRow, delCol); // DFS for top row
            }
            if (!vis[n - 1][j] && board[n - 1][j] == 'O') {
                dfs(n - 1, j, vis, board, delRow, delCol); // DFS for bottom row
            }
        }

        // Check the first and last columns for 'O's
        for (int i = 0; i < n; i++) {
            if (!vis[i][0] && board[i][0] == 'O') {
                dfs(i, 0, vis, board, delRow, delCol); // DFS for left column
            }
            if (!vis[i][m - 1] && board[i][m - 1] == 'O') {
                dfs(i, m - 1, vis, board, delRow, delCol); // DFS for right column
            }
        }

        // Flip the unvisited 'O's to 'X's
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X'; // Mark as 'X' if not connected to the boundary
                }
            }
        }
    }
};
