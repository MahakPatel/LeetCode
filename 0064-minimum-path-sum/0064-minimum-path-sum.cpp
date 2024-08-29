class Solution {
public:
    // ++++++++++++++++++++++++ Memoization function to find the minimum path
    // sum to (i, j) ++++++++++++ long long memoization(vector<vector<int>>&
    // grid, int i, int j, vector<vector<long long>> &dp) {
    //     // Base case: If at the top-left corner, return the value of the cell
    //     if (i == 0 && j == 0) return grid[i][j];

    //     // If out of bounds, return a very large value (effectively infinity)
    //     if (i < 0 || j < 0) return LLONG_MAX;

    //     // Return the cached result if it exists
    //     if (dp[i][j] != -1) return dp[i][j];

    //     // Recursive calls with bounds checking
    //    long long up = LLONG_MAX, right = LLONG_MAX;
    //         if (i > 0) up = grid[i][j] + memoization(grid, i - 1, j, dp);
    //         if (j > 0) right = grid[i][j] + memoization(grid, i, j - 1, dp);

    //     // Store and return the minimum of the two computed path sums
    //     return dp[i][j] = min(up, right);
    // }

    // // Function to initialize the memoization table and start the computation
    // int minPathSum(vector<vector<int>>& grid) {
    //     int n = grid.size();          // Number of rows in the grid
    //     int m = grid[0].size();       // Number of columns in the grid

    //     // Initialize the memoization table with -1
    //     vector<vector<long long>> dp(n, vector<long long>(m, -1));

    //     // Compute the minimum path sum starting from the bottom-right corner
    //     long long result = memoization(grid, n - 1, m - 1, dp);

    //     // Return the result, making sure it's within valid integer range
    //     return (result < INT_MAX) ? static_cast<int>(result) : INT_MAX;
    // }

    // ++++++++++++++++ Tabulation +++++++++++++++++++++++++++++

    // Function to compute the minimum path sum in a grid
    // int minPathSum(vector<vector<int>>& grid) {
    //     int n = grid.size();    // Get the number of rows in the grid
    //     int m = grid[0].size(); // Get the number of columns in the grid

    //     // Initialize the dp table with a large number (1e9), representing
    //     // infinity This will be used to store the minimum path sum to each
    //     cell vector<vector<long long>> dp(n, vector<long long>(m, 0));

    //     // Iterate over each cell in the grid
    //     for (int i = 0; i < n; ++i) {      // Loop through each row
    //         for (int j = 0; j < m; ++j) {  // Loop through each column
    //             if (i == 0 && j == 0) {    // If at the top-left corner
    //                 dp[i][j] = grid[i][j]; // Initialize with the value of
    //                 the
    //                                        // starting cell
    //             } else {
    //                 // Calculate the minimum path sum coming from the cell
    //                 above
    //                 // (i-1, j)
    //                 long long up = grid[i][j];
    //                 if (i > 0) { // Check if the above cell exists
    //                     up += dp[i - 1]
    //                             [j]; // Add the path sum from the above cell
    //                 } else {
    //                     up += 1e9;
    //                 }

    //                 // Calculate the minimum path sum coming from the cell to
    //                 // the left (i, j-1)
    //                 long long right = grid[i][j];
    //                 if (j > 0) { // Check if the left cell exists
    //                     right +=
    //                         dp[i][j - 1]; // Add the path sum from the left
    //                         cell
    //                 } else {
    //                     up += 1e9;
    //                 }

    //                 // Store the minimum path sum to reach the current cell
    //                 dp[i][j] = min(
    //                     up,
    //                     right); // Take the minimum of the two possible paths
    //             }
    //         }
    //     }

    //     return dp[n - 1][m - 1]; // Return the minimum path sum to reach the
    //                              // bottom-right corner
    // }

    // ++++++++++++++ Space Otimazation ++++++++++++++++
    // Function to compute the minimum path sum in a grid
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();    // Get the number of rows in the grid
        int m = grid[0].size(); // Get the number of columns in the grid

        // Vector to store the minimum path sums for the previous row
        vector<int> prev(m, 0);

        // Iterate over each row in the grid
        for (int i = 0; i < n; ++i) { // Loop through each row
            // Vector to store the minimum path sums for the current row
            vector<int> cur(m, 0);

            // Iterate over each column in the current row
            for (int j = 0; j < m; ++j) { // Loop through each column
                if (i == 0 && j == 0) { // If at the top-left corner of the grid
                    cur[j] = grid[i][j]; // Initialize with the value of the
                                         // starting cell
                } else {
                    // Calculate the minimum path sum coming from the cell above
                    // (i-1, j)
                    long long up = grid[i][j];
                    if (i > 0) {       // Check if the above cell exists
                        up += prev[j]; // Add the path sum from the above cell
                    } else {
                        up += 1e9; // If no above cell, set to a large number
                                   // (infinity)
                    }

                    // Calculate the minimum path sum coming from the cell to
                    // the left (i, j-1)
                    long long right = grid[i][j];
                    if (j > 0) { // Check if the left cell exists
                        right +=
                            cur[j - 1]; // Add the path sum from the left cell
                    } else {
                        right += 1e9; // If no left cell, set to a large number
                                      // (infinity)
                    }

                    // Store the minimum path sum to reach the current cell
                    cur[j] = min(
                        up,
                        right); // Take the minimum of the two possible paths
                }
            }

            // Move to the next row, updating prev to the current row's results
            prev = cur;
        }

        return prev[m - 1]; // Return the minimum path sum to reach the
                            // bottom-right corner
    }
};