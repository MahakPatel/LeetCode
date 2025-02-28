class Solution {
public:
    // +++++++++++++++++++ Recursive. +++++++++++++++ TC O(2^n). SC O(amount)
    // int f(int index, vector<int>& coins, int amount) {
    //     // Base case: If we are at the first coin
    //     if (index == 0) {
    //         // Check if the amount can be formed using the first coin
    //         if (amount % coins[index] == 0) {
    //             return (amount /
    //                     coins[index]); // Return the number of coins needed
    //         } else {
    //             return -1; // Return -1 if the amount cannot be formed
    //         }
    //     }

    //     // Recursive case 1: Do not take the current coin
    //     int notTake = f(index - 1, coins, amount);

    //     // Recursive case 2: Take the current coin, if possible
    //     int take = INT_MAX;
    //     if (coins[index] <= amount) {
    //         int res =f(index, coins,amount - coins[index]); // Recursive call
    //         for remaining amount if (res !=-1) { // Check if it's possible to
    //         form the remaining amount
    //             take = 1 + res; // Add 1 to account for the current coin
    //         }
    //     }

    //     // Return the minimum of the two cases
    //     if (take == INT_MAX) return notTake; // If taking the coin is not
    //     possible if (notTake == -1) return take;     // If not taking the
    //     coin is not possible return min(take, notTake);          // Return
    //     the minimum of the two cases
    // }

    // int coinChange(vector<int>& coins, int amount) {
    //     int n = coins.size();

    //     // Start the recursion from the last index of the coins array
    //     return f(n - 1, coins, amount);
    // }

    // ++++++++++++++ Memoization ++++++++ TC O(n * amount).  SC O(n * amount)
    // int f(int index, vector<int>& coins, int amount, vector<vector<int>>& dp)
    // {
    //     // Base case: If we are at the first type of coin
    //     // Check if the amount can be formed using only this coin
    //     if (index == 0) {
    //         return (amount % coins[index] == 0) ? (amount / coins[index])
    //                                             : INT_MAX;
    //     }

    //     // Check if the result for the current state is already computed
    //     if (dp[index][amount] != -1) {
    //         return dp[index][amount]; // Return the stored result to avoid
    //                                   // recomputation
    //     }

    //     // Option 1: Do not take the current coin and move to the previous
    //     coin int notTake = f(index - 1, coins, amount, dp);

    //     // Option 2: Take the current coin, if the coin's value is less than
    //     or
    //     // equal to the remaining amount
    //     int take = INT_MAX;
    //     if (coins[index] <= amount) {
    //         int res = f(index, coins, amount - coins[index],
    //                     dp);      // Solve for the reduced amount
    //         if (res != INT_MAX) { // Only update if the result is valid
    //             take = 1 + res;   // Add 1 to include the current coin
    //         }
    //     }

    //     // Store the result in the dp table and return the minimum of the two
    //     // options
    //     return dp[index][amount] = min(take, notTake);
    // }

    // int coinChange(vector<int>& coins, int amount) {
    //     int n = coins.size();
    //     // Create a dp table initialized with -1 to indicate uncomputed
    //     states vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

    //     // Call the recursive function starting with the last coin and the
    //     full
    //     // amount
    //     int result = f(n - 1, coins, amount, dp);

    //     // If the result is INT_MAX, it means the amount cannot be formed, so
    //     // return -1
    //     return (result == INT_MAX) ? -1 : result;
    // }

    // +++++++++++++ Tabulation ++++++++++++ TC O(n*amount). SC O(n*amount)
    // int coinChange(vector<int>& coins, int amount) {
    //     int n = coins.size();
    //     // Create a dp table where dp[i][j] represents the minimum number of
    //     // coins needed to form the amount j using the first i coins
    //     vector<vector<int>> dp(n, vector<int>(amount + 1, INT_MAX));

    //     // Base case: When we only have one type of coin
    //     for (int target = 0; target <= amount; target++) {
    //         if (target % coins[0] == 0) {
    //             dp[0][target] =
    //                 target /
    //                 coins[0]; // Use as many of the first coin as needed
    //         } else {
    //             dp[0][target] =
    //                 INT_MAX; // Otherwise, it's not possible to form the
    //                 amount
    //         }
    //     }

    //     // Fill the dp table for the rest of the coins
    //     for (int index = 1; index < n; index++) {
    //         for (int target = 0; target <= amount; target++) {
    //             // Option 1: Do not take the current coin
    //             int notTake = dp[index - 1][target];

    //             // Option 2: Take the current coin, if possible
    //             int take = INT_MAX;
    //             if (coins[index] <= target) {
    //                 int res =
    //                     dp[index][target - coins[index]]; // Reduced amount
    //                 if (res != INT_MAX) {
    //                     take = 1 + res; // Add 1 for the current coin
    //                 }
    //             }

    //             // Take the minimum of the two options
    //             dp[index][target] = min(take, notTake);
    //         }
    //     }

    //     // The result is stored in the last cell of the table
    //     int result = dp[n - 1][amount];

    //     // If the result is INT_MAX, it means the amount cannot be formed
    //     return (result == INT_MAX) ? -1 : result;
    // }

    // +++++++++++++ space optimzation ++++++++++++ TC O(n*amount). SC O(amount)
    // O(n*amount)
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        // Space-optimized DP arrays
        vector<int> prev(amount + 1, INT_MAX), cur(amount + 1, INT_MAX);

        // Base case: When we only have one type of coin
        for (int target = 0; target <= amount; target++) {
            if (target % coins[0] == 0) {
                prev[target] =
                    target /
                    coins[0]; // Use as many of the first coin as needed
            }
        }

        // Fill the dp table for the rest of the coins
        for (int index = 1; index < n; index++) {
            for (int target = 0; target <= amount; target++) {
                // Option 1: Do not take the current coin
                int notTake = prev[target];

                // Option 2: Take the current coin, if possible
                int take = INT_MAX;
                if (coins[index] <= target) {
                    int res = cur[target -
                                  coins[index]]; // Solve for the reduced amount
                    if (res != INT_MAX) {
                        take = 1 + res; // Add 1 for the current coin
                    }
                }

                // Take the minimum of the two options
                cur[target] = min(take, notTake);
            }

            // Update the previous array for the next iteration
            prev = cur;
        }

        // The result is stored in the last cell of the previous row
        int result = prev[amount];

        // If the result is INT_MAX, it means the amount cannot be formed
        return (result == INT_MAX) ? -1 : result;
    }
};
