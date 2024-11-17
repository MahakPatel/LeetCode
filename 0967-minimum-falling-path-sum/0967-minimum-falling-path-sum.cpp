class Solution {
public:
    // ++++++++++++++++= Recursive ++++++++++++++++++++++++
    // int f(int i, int j, int m, vector<vector<int>>& matrix,
    //       vector<vector<int>>& dp) {
    //     // Base case: if the column is out of bounds, return a large value
    //     if (j < 0 || j >= m)
    //         return 1e9;
    //     // Base case: if we are in the first row, return the value at that
    //     cell if (i == 0)
    //         return matrix[0][j];

    //     // Check if the result has already been calculated for this cell
    //     if (dp[i][j] != -1)
    //         return dp[i][j];

    //     // Recursive case: calculate the path sum for each direction
    //     int up = matrix[i][j] + f(i - 1, j, m, matrix, dp);
    //     int leftDiagonal = matrix[i][j] + f(i - 1, j - 1, m, matrix, dp);
    //     int rightDiagonal = matrix[i][j] + f(i - 1, j + 1, m, matrix, dp);

    //     // Store the minimum result for this cell and return it
    //     return dp[i][j] = min(up, min(leftDiagonal, rightDiagonal));
    // }

    // int minFallingPathSum(vector<vector<int>>& matrix) {
    //     int n = matrix.size();
    //     int m = matrix[0].size();

    //     // Initialize a DP array to store the minimum falling path sum for
    //     each
    //     // cell
    //     vector<vector<int>> dp(n, vector<int>(m, -1));

    //     int mini = INT_MAX;

    //     // Calculate the minimum falling path sum starting from each element
    //     in
    //     // the last row
    //     for (int j = 0; j < m; j++) {
    //         int ans = f(n - 1, j, m, matrix,
    //                     dp); // Calculate the result for each starting point
    //         mini = min(mini, ans); // Update the minimum path sum
    //     }

    //     return mini;
    // }

    // +++++++++++++++++++ Memoization ++++++++++++++++++++++
    // // Function to recursively find the maximum path sum for a given cell
    // int getMinUtil(int i, int j, int m, vector<vector<int>>& matrix,
    //                vector<vector<int>>& dp) {
    //     // Base Conditions
    //     if (j < 0 || j >= m)
    //         return 1e9; // Return a large number for invalid paths

    //     if (i == 0)
    //         return matrix[0][j]; // The base case: top row, so return its
    //         value

    //     if (dp[i][j] != -1)
    //         return dp[i][j]; // If already computed, return the stored value

    //     // Calculate the minimum path sum by considering three possible
    //     // directions
    //     int up = matrix[i][j] + getMinUtil(i - 1, j, m, matrix, dp);
    //     int leftDiagonal =
    //         matrix[i][j] + getMinUtil(i - 1, j - 1, m, matrix, dp);
    //     int rightDiagonal =
    //         matrix[i][j] + getMinUtil(i - 1, j + 1, m, matrix, dp);

    //     // Return the minimum of the three possible directions
    //     return dp[i][j] = min(up, min(leftDiagonal, rightDiagonal));
    // }

    // // Function to find the minimum falling path sum
    // int minFallingPathSum(vector<vector<int>>& matrix) {
    //     int n = matrix.size();    // Number of rows
    //     int m = matrix[0].size(); // Number of columns

    //     vector<vector<int>> dp(n, vector<int>(m, -1)); // DP table

    //     int mini = INT_MAX; // Initialize minimum path sum

    //     // Try to start the path from each element in the first row
    //     for (int j = 0; j < m; j++) {
    //         int ans = getMinUtil(n - 1, j, m, matrix,
    //                              dp); // Get min path sum for each element
    //         mini = min(mini, ans);    // Update the minimum path sum
    //     }

    //     return mini; // Return the overall minimum path sum
    // }

    //+++++++++++++++++++++ Tabulation ++++++++++++++++++++++++++++
    // int minFallingPathSum(vector<vector<int>>& matrix) {
    //     int n = matrix.size();    // Number of rows in the matrix
    //     int m = matrix[0].size(); // Number of columns in the matrix

    //     int dp[n][m]; // Create a DP table to store the minimum path sum for
    //                   // each cell

    //     // Initialize the first row of the dp array
    //     for (int j = 0; j < m; j++) {
    //         dp[0][j] =
    //             matrix[0][j]; // The first row is the same as the matrix
    //             itself
    //                           // since there are no previous rows to consider
    //     }

    //     // Fill the dp table for all rows starting from the second row
    //     for (int i = 1; i < n; i++) {
    //         for (int j = 0; j < m; j++) {
    //             // The current cell is the value in the matrix plus the
    //             minimum
    //             // of three possible cells:
    //             // 1. The cell directly above the current cell (up)
    //             // 2. The cell diagonally left above the current cell
    //             // (leftDiagonal)
    //             // 3. The cell diagonally right above the current cell
    //             // (rightDiagonal)

    //             int leftDiagonal =
    //                 matrix[i][j]; // Start with the current value of the cell
    //             int rightDiagonal =
    //                 matrix[i][j]; // Start with the current value of the cell
    //             int up = matrix[i][j] +
    //                      dp[i - 1][j]; // Value coming straight down from
    //                      above

    //             // If there is a valid left diagonal cell (check if j - 1 is
    //             // within bounds)
    //             if (j - 1 >= 0) {
    //                 leftDiagonal +=
    //                     dp[i - 1][j - 1]; // Add the value from the left
    //                                       // diagonal cell above
    //             } else {
    //                 leftDiagonal += 1e9; // If no left diagonal exists, add a
    //                                      // very large number to "ignore" it
    //             }

    //             // If there is a valid right diagonal cell (check if j + 1 is
    //             // within bounds)
    //             if (j + 1 < m) {
    //                 rightDiagonal +=
    //                     dp[i - 1][j + 1]; // Add the value from the right
    //                                       // diagonal cell above
    //             } else {
    //                 rightDiagonal += 1e9; // If no right diagonal exists, add
    //                 a
    //                                       // very large number to "ignore" it
    //             }

    //             // Take the minimum value from the three possible directions
    //             // (up, leftDiagonal, rightDiagonal)
    //             dp[i][j] = min(up, min(leftDiagonal, rightDiagonal));
    //         }
    //     }

    //     int mini = INT_MAX; // Variable to keep track of the minimum path sum
    //                         // from the last row

    //     // Find the minimum value in the last row of the dp table
    //     for (int j = 0; j < m; j++) {
    //         mini = min(mini, dp[n - 1][j]); // Compare each value in the last
    //                                         // row to get the minimum
    //     }

    //     return mini; // Return the final minimum value
    // }

    // +++++++++++++++++++++++ Space Optimization ++++++++++++++++++++
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();    // Number of rows in the matrix
        int m = matrix[0].size(); // Number of columns in the matrix

        int dp[n][m]; // Create a DP table to store the minimum path sum for
                      // each cell

        vector<int> prev(m, 0), cur(m, 0);

        // Initialize the first row of the dp array
        for (int j = 0; j < m; j++) {
            prev[j] =
                matrix[0][j]; // The first row is the same as the matrix itself
                              // since there are no previous rows to consider
        }

        // Fill the dp table for all rows starting from the second row
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // The current cell is the value in the matrix plus the minimum
                // of three possible cells:
                // 1. The cell directly above the current cell (up)
                // 2. The cell diagonally left above the current cell
                // (leftDiagonal)
                // 3. The cell diagonally right above the current cell
                // (rightDiagonal)

                int leftDiagonal =
                    matrix[i][j]; // Start with the current value of the cell
                int rightDiagonal =
                    matrix[i][j]; // Start with the current value of the cell
                int up = matrix[i][j] +
                         prev[j]; // Value coming straight down from above

                // If there is a valid left diagonal cell (check if j - 1 is
                // within bounds)
                if (j - 1 >= 0) {
                    leftDiagonal += prev[j - 1]; // Add the value from the left
                                                 // diagonal cell above
                } else {
                    leftDiagonal += 1e9; // If no left diagonal exists, add a
                                         // very large number to "ignore" it
                }

                // If there is a valid right diagonal cell (check if j + 1 is
                // within bounds)
                if (j + 1 < m) {
                    rightDiagonal += prev[j + 1]; // Add the value from the
                                                  // right diagonal cell above
                } else {
                    rightDiagonal += 1e9; // If no right diagonal exists, add a
                                          // very large number to "ignore" it
                }

                // Take the minimum value from the three possible directions
                // (up, leftDiagonal, rightDiagonal)
                cur[j] = min(up, min(leftDiagonal, rightDiagonal));
            }

            prev = cur;
        }

        int mini = INT_MAX; // Variable to keep track of the minimum path sum
                            // from the last row

        // Find the minimum value in the last row of the dp table
        for (int j = 0; j < m; j++) {
            mini = min(mini, prev[j]); // Compare each value in the last
                                       // row to get the minimum
        }

        return mini; // Return the final minimum value
    }
};