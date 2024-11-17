class Solution {
public:
    // ++++++++++++ Recursion ++++++++++++++++++++++++
    // Helper function to calculate unique paths
    // int f(int i, int j) {
    //     // Base case: if we are at the top-left corner, there's exactly one
    //     way
    //     // to be there (stay in place)
    //     if (i == 0 && j == 0)
    //         return 1;

    //     // Base case: if we go out of bounds, return 0 (no valid path)
    //     if (i < 0 || j < 0)
    //         return 0;

    //     // Recursive case: calculate the number of paths from the cell above
    //     // (up) and the cell to the left (left)
    //     int up = f(i - 1, j);   // Paths from the top
    //     int left = f(i, j - 1); // Paths from the left

    //     // Return the sum of paths from up and left
    //     return up + left;
    // }

    // // Function to calculate unique paths from the top-left to the
    // bottom-right int uniquePaths(int m, int n) {
    //     // Call the helper function with the bottom-right corner coordinates
    //     // (m-1, n-1)
    //     return f(m - 1, n - 1);
    // }
    // Helper function to calculate unique paths

    // ++++++++++++= Memoization ++++++++++++++++++++++++++++
    // int f(int i, int j, vector<vector<int>>& dp) {
    //     // Base case: if we are at the top-left corner, there's exactly one
    //     way
    //     // to be there (stay in place)
    //     if (i == 0 && j == 0)
    //         return 1;

    //     // Base case: if we go out of bounds, return 0 (no valid path)
    //     if (i < 0 || j < 0)
    //         return 0;

    //     // If we already have the result stored in dp, return it
    //     (memoization) if (dp[i][j] != -1)
    //         return dp[i][j];

    //     // Recursive case: calculate the number of paths from the cell above
    //     // (up) and the cell to the left (left)
    //     int up = f(i - 1, j, dp);   // Paths from the top
    //     int left = f(i, j - 1, dp); // Paths from the left

    //     // Store the result in dp and return the sum of paths from up and
    //     left return dp[i][j] = up + left;
    // }

    // // Function to calculate unique paths from the top-left to the
    // bottom-right int uniquePaths(int m, int n) {
    //     // Initialize dp table where all values are -1 (indicating uncomputed
    //     // results)
    //     vector<vector<int>> dp(
    //         n, vector<int>(m, -1)); // We need m columns and n rows

    //     // Call the helper function with the bottom-right corner coordinates
    //     // (m-1, n-1)
    //     return f(m - 1, n - 1, dp);
    // }

    // ++++++++++++++++ Tabulation +++++++++++++++++++++++

    // int uniquePaths(int m, int n) {
    //     // Create a 2D dp array with dimensions m x n
    //     int dp[m][n];

    //     // Loop through the rows
    //     for (int i = 0; i < m; i++) {
    //         // Loop through the columns
    //         for (int j = 0; j < n; j++) {
    //             // Base case: If we are at the top-left corner, there is only
    //             1
    //             // way (stay in place)
    //             if (i == 0 && j == 0) {
    //                 dp[i][j] = 1;
    //             } else {
    //                 int up = 0;   // Number of ways coming from the top
    //                 int left = 0; // Number of ways coming from the left

    //                 // If we are not at the first row, add the number of ways
    //                 // from the top
    //                 if (i > 0)
    //                     up = dp[i - 1][j];

    //                 // If we are not at the first column, add the number of
    //                 ways
    //                 // from the left
    //                 if (j > 0)
    //                     left = dp[i][j - 1];

    //                 // The current number of paths is the sum of the ways
    //                 from
    //                 // top and left
    //                 dp[i][j] = up + left;
    //             }
    //         }
    //     }

    //     // The result is stored in the bottom-right corner of the dp array
    //     return dp[m - 1][n - 1];
    // }


    // +++++++++++++++ Space Optimazation ++++++++++++++++++++++++++++++++++++

    int uniquePaths(int m, int n) {
        // Create a 1D dp array to store the number of paths to each cell in the
        // current row
        vector<int> prev(n, 0);

        // Loop through the rows of the grid
        for (int i = 0; i < m; i++) {
            // Create a new 1D array to store the current row's path values
            vector<int> cur(n, 0);

            // Loop through the columns of the grid
            for (int j = 0; j < n; j++) {
                // Base case: If we are at the top-left corner, there's only one
                // way to reach it (stay in place)
                if (i == 0 && j == 0) {
                    cur[j] = 1;
                } else {
                    int up = 0;   // Number of ways coming from the top
                    int left = 0; // Number of ways coming from the left

                    // If we're not in the first row, add the number of ways
                    // from the top
                    if (i > 0) {
                        up = prev[j];
                    }

                    // If we're not in the first column, add the number of ways
                    // from the left
                    if (j > 0) {
                        left = cur[j - 1];
                    }

                    // The current number of paths is the sum of the ways from
                    // top and left
                    cur[j] = up + left;
                }
            }

            // Move the current row's result to the previous row for the next
            // iteration
            prev = cur;
        }

        // The result is stored in the last cell of the last row (bottom-right
        // corner)
        return prev[n - 1];
    }
};