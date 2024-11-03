class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(); // Number of rows in the grid
        int m = grid[0].size(); // Number of columns in the grid

        // Directions to move in 8 possible directions (up, down, left, right, and diagonals)
        vector<pair<int, int>> possibleDirections = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0}, 
            {1, 1}, {1, -1}, {-1, -1}, {-1, 1}
        };

        // Check if the start or end cells are blocked
        if (grid[0][0] != 0 || grid[n - 1][m - 1] != 0) return -1;

        // Initialize a queue for BFS
        queue<pair<int, int>> q;
        q.push({0, 0}); // Start from the top-left corner (0, 0)

        grid[0][0] = 1; // Mark the starting cell as visited (distance is 1)

        // BFS loop
        while (!q.empty()) {
            auto it = q.front(); // Get the front element of the queue
            q.pop(); // Remove the front element from the queue

            int row = it.first; // Current row
            int col = it.second; // Current column
            int distance = grid[row][col]; // Current distance

            // If we reach the bottom-right corner, return the distance
            if (row == n - 1 && col == m - 1) {
                return distance; // Return the distance to reach the destination
            }

            // Explore all possible directions
            for (auto dir : possibleDirections) {
                int newRow = row + dir.first; // Calculate new row
                int newCol = col + dir.second; // Calculate new column

                // Check if the new position is within bounds and not blocked
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m 
                    && grid[newRow][newCol] == 0) {
                    
                    // Mark the new cell as visited by setting the distance
                    grid[newRow][newCol] = distance + 1; // Update the distance
                    // Push the new cell into the queue
                    q.push({newRow, newCol});
                }
            }
        }

        // If the destination was not reached, return -1
        return -1;
    }
};