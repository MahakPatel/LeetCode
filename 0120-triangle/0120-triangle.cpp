class Solution {
public:
    // +++++++++++++++++++ Memoization +++++++++++++++++++++++++++++++
    // // Memoization function to find the minimum path sum from (i, j)
    // int memoization(vector<vector<int>>& triangle, int i, int j,
    //                 vector<vector<int>>& dp) {
    //     int n = triangle.size(); // Number of rows in the triangle

    //     // Base case: If at the last row, return the value of the current
    //     cell if (i == n - 1)
    //         return triangle[i][j];

    //     // Return the cached result if it exists
    //     if (dp[i][j] != -1)
    //         return dp[i][j];

    //     // Recursive calls to move down and diagonally
    //     int down = triangle[i][j] + memoization(triangle, i + 1, j, dp);
    //     int diagonal = triangle[i][j] + memoization(triangle, i + 1, j + 1,
    //     dp);

    //     // Store and return the minimum path sum for this cell
    //     return dp[i][j] = min(down, diagonal);
    // }

    // // Function to initialize the memoization table and start the computation
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     int n = triangle.size(); // Number of rows in the triangle

    //     // Initialize the memoization table with -1
    //     vector<vector<int>> dp(n, vector<int>(n, -1));

    //     // Start the computation from the top of the triangle
    //     return memoization(triangle, 0, 0, dp);
    // }

    // +++++++++++++++++ Tabulation ++++++++++++++++

    // // Function to initialize the memoization table and start the computation
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     int n = triangle.size(); // Number of rows in the triangle

    //     // Initialize the memoization table with -1
    //     vector<vector<int>> dp(n, vector<int>(n, -1));

    //     // Fill the last row of dp table with the values from the triangle's
    //     // last row
    //     for (int j = 0; j < n; j++) {
    //         dp[n - 1][j] = triangle[n - 1][j];
    //     }

    //     // Fill the dp table from bottom to top
    //     for (int i = n - 2; i >= 0;
    //          i--) { // Iterate from second last row to the top
    //         for (int j = 0; j <= i;
    //              j++) { // Iterate through each element in row i
    //             // Calculate the minimum path sum for the current cell
    //             // Option 1: Move straight down
    //             int down = triangle[i][j] + dp[i + 1][j];
    //             // Option 2: Move diagonally down to the right
    //             int diagonal = triangle[i][j] + dp[i + 1][j + 1];

    //             // Store the minimum path sum in the dp table
    //             dp[i][j] = min(down, diagonal);
    //         }
    //     }

    //     // The minimum path sum from top to bottom is stored in dp[0][0]
    //     return dp[0][0];
    // }

    // Function to initialize the memoization table and start the computation
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size(); // Number of rows in the triangle
        vector<int> cur(n, 0);
        vector<int> front(n, 0);
        for (int j = 0; j < n; j++) {
            front[j] = triangle[n - 1][j];
        }

        // Fill the dp table from bottom to top
        for (int i = n - 2; i >= 0;
             i--) { // Iterate from second last row to the top
            for (int j = 0; j <= i;
                 j++) { // Iterate through each element in row i
                // Calculate the minimum path sum for the current cell
                // Option 1: Move straight down
                int down = triangle[i][j] + front[j];
                // Option 2: Move diagonally down to the right
                int diagonal = triangle[i][j] + front[j + 1];

                // Store the minimum path sum in the dp table
                cur[j] = min(down, diagonal);
            }

            front = cur;
        }

        // The minimum path sum from top to bottom is stored in dp[0][0]
        return front[0];
    }
};