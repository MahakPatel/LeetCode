class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();         // Number of rows in the grid
        int m = grid[0].size();      // Number of columns in the grid

        queue<pair<int, int>> q;     // Queue for BFS
        vector<vector<int>> vis(n, vector<int>(m, 0)); // Visited array

        // Process all border cells
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Check if the cell is on the border
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    // Only enqueue if it's land (1)
                    if (grid[i][j] == 1) {
                        q.push({i, j});
                        vis[i][j] = 1; // Mark as visited
                    }
                }
            }
        }
        
        // Directions for adjacent cells (up, right, down, left)
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};

        // BFS to mark all land cells connected to the border
        while (!q.empty()) {
            int row = q.front().first;  // Current row
            int col = q.front().second; // Current column
            q.pop();

            // Check all four possible directions
            for (int i = 0; i < 4; i++) {
                int nrow = row + delRow[i]; // New row index
                int ncol = col + delCol[i]; // New column index

                // Check if the new position is valid and is land (1)
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                    q.push({nrow, ncol}); // Add to queue for further processing
                    vis[nrow][ncol] = 1;  // Mark as visited
                }
            }
        }

        // Count the number of enclaves
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Count cells that are land (1) and not visited
                if (grid[i][j] == 1 && vis[i][j] == 0) {
                    count++; // Increment count for enclaves
                }
            }
        }

        return count; // Return the total count of enclaves
    }
};
