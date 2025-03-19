class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();    // Number of rows in the grid
        int m = grid[0].size(); // Number of columns in the grid

        queue<pair<int, int>> q; // Queue to hold positions of rotten oranges
        int countFresh = 0;      // Count of fresh oranges
        int tm = 0;              // Time taken for the process to complete

        // Directions for adjacent cells (up, right, down, left)
        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};

        // Step 1: Initialize the queue and count fresh oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j}); // Add rotten oranges to the queue
                } else if (grid[i][j] == 1) {
                    countFresh++; // Count fresh oranges
                }
            }
        }

        // Step 2: BFS to rot the fresh oranges
        while (!q.empty()) {
            int size = q.size(); // Current level size

            for (int i = 0; i < size; i++) {
                int r = q.front().first;  // Current row
                int c = q.front().second; // Current column
                q.pop();                  // Remove the current rotten orange

                // Process all 4 possible directions
                for (int j = 0; j < 4; j++) {
                    int nRow = r + dRow[j]; // New row
                    int nCol = c + dCol[j]; // New column

                    // Check if the new position is valid and contains a fresh
                    // orange
                    if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                        grid[nRow][nCol] == 1) {
                        grid[nRow][nCol] = 2; // Rot the fresh orange
                        q.push({nRow, nCol}); // Add to the queue
                    }
                }
            }
            tm++; // Increase time after processing one level
        }

        // Step 3: Check if all fresh oranges are rotten
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    return -1; // If any fresh orange is left, return -1
                }
            }
        }

        if (tm == 0) {
            return 0; // If no time was taken, return 0
        } else {
            return tm -
                   1; // Otherwise, return the time minus the last increment
        }
    }
};