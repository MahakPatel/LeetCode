class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();    // Number of rows in the matrix
        int m = mat[0].size(); // Number of columns in the matrix

        vector<vector<int>> vis(n, vector<int>(m, 0));  // Visited array
        vector<vector<int>> dist(n, vector<int>(m, 0)); // Distance array

        queue<pair<int, int>> q; // Queue for BFS

        // Initialize the queue with all cells containing 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j}); // Push the cell with 0 to the queue
                    vis[i][j] = 1;  // Mark it as visited
                }
            }
        }

        // Directions for moving up, right, down, and left
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};

        // BFS to compute distances
        while (!q.empty()) {
            int row = q.front().first;  // Current row
            int col = q.front().second; // Current column
            q.pop();

            // Explore all four possible directions
            for (int i = 0; i < 4; i++) {
                int nRow = row + delRow[i]; // New row index
                int nCol = col + delCol[i]; // New column index

                // Check if the new position is valid and has not been visited
                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                    vis[nRow][nCol] == 0) {
                    // Mark as visited
                    vis[nRow][nCol] = 1;
                    // Update the distance from the nearest zero
                    dist[nRow][nCol] = dist[row][col] + 1;
                    // Push the new position to the queue
                    q.push({nRow, nCol});
                }
            }
        }

        // Return the distance matrix
        return dist;
    }
};
