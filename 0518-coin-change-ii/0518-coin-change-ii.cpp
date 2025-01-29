class Solution {
public:
    // // ++++++++++ Recursive +++++++++ TC O(2^n).  SC O(amount) +++++++++++++
    // int f(int amount, vector<int>& coins, int index) {
    //     // Base case: If we are at the first coin
    //     if (index == 0) {
    //         return (amount % coins[index] == 0) ? 1 : 0;
    //     }

    //     // Option 1: Do not take the current coin
    //     int notTake = f(amount, coins, index - 1);

    //     // Option 2: Take the current coin if possible
    //     int take = 0;
    //     if (coins[index] <= amount) {
    //         take = f(amount - coins[index], coins,
    //                  index); // Use this coin and reduce the amount
    //     }

    //     // Return the sum of both options
    //     return take + notTake;
    // }

    // int change(int amount, vector<int>& coins) {
    //     int n = coins.size();

    //     // Call the recursive function
    //     return f(amount, coins, n - 1);
    // }

    // ++++++++++ Memoization +++++++++ TC O(n * amount).  SC O(amount * n +
    // amount) +++++++++++++ int f(int amount, vector<int>& coins, int index,
    // vector<vector<int>>& dp) {
    //     // Base case
    //     if (index == 0) {
    //         return (amount % coins[index] == 0) ? 1 : 0;
    //     }

    //     // Check if already computed
    //     if (dp[index][amount] != -1) {
    //         return dp[index][amount];
    //     }

    //     // Option 1: Do not take the current coin
    //     int notTake = f(amount, coins, index - 1, dp);

    //     // Option 2: Take the current coin if possible
    //     int take = 0;
    //     if (coins[index] <= amount) {
    //         take = f(amount - coins[index], coins, index, dp);
    //     }

    //     // Store result in dp table and return
    //     dp[index][amount] = take + notTake;
    //     return dp[index][amount];
    // }

    // int change(int amount, vector<int>& coins) {
    //     int n = coins.size();

    //     // Initialize dp table with -1 (indicating uncomputed states)
    //     vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

    //     // Call the recursive function with memoization
    //     return f(amount, coins, n - 1, dp);
    // }

    // ++++++++++++++++ Tabulation +++++++++++++ TC O(n*amount) SC O(n*amount)
    // int change(int amount, vector<int>& coins) {
    //     int n = coins.size();

    //     // Initialize dp table with 0
    //     vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

    //     // Base case: If amount is 0, there is one way to make the sum, which
    //     is
    //     // not using any coins
    //     dp[0][0] = 1;

    //     // Initialize the first row based on the first coin
    //     for (int a = 1; a <= amount; a++) {
    //         dp[0][a] = (a % coins[0] == 0) ? 1 : 0;
    //     }

    //     // Fill the DP table for other coins
    //     for (int ind = 1; ind < n; ind++) {
    //         for (int a = 0; a <= amount; a++) {

    //             // Option 1: Do not take the current coin (carry over the
    //             result
    //             // from the previous row)
    //             int notTake = dp[ind - 1][a];

    //             // Option 2: Take the current coin if possible (subtract coin
    //             // value from current amount)
    //             int take = 0;
    //             if (coins[ind] <= a) {
    //                 take = dp[ind][a - coins[ind]];
    //             }

    //             // Store the result for the current state
    //             dp[ind][a] = take + notTake;
    //         }
    //     }

    //     // The result will be in the last cell of the table
    //     return dp[n - 1][amount];
    // }

    // ++++++++++++++++ Space Optimzation(2D array) +++++++++++++ TC O(n*amount)
    // SC. O(amount) int change(int amount, vector<int>& coins) {
    //     int n = coins.size();

    //     // Initialize dp table with 0
    //     vector<long long> prev(amount + 1, 0), cur(amount + 1, 0);

    //     // Base case: If amount is 0, there is one way to make the sum, which
    //     is
    //     // not using any coins
    //     prev[0] = 1;

    //     // Initialize the first row based on the first coin
    //     for (int a = 1; a <= amount; a++) {
    //         prev[a] = (a % coins[0] == 0) ? 1 : 0;
    //     }

    //     // Fill the DP table for other coins
    //     for (int ind = 1; ind < n; ind++) {
    //         for (int a = 0; a <= amount; a++) {

    //             // Option 1: Do not take the current coin (carry over the
    //             result
    //             // from the previous row)
    //             int notTake = prev[a];

    //             // Option 2: Take the current coin if possible (subtract coin
    //             // value from current amount)
    //             int take = 0;
    //             if (coins[ind] <= a) {
    //                 take = cur[a - coins[ind]]; // Use prev instead of cur
    //             }

    //             // Store the result for the current state
    //             cur[a] = take + notTake;
    //         }

    //         // Move the current row to previous for the next iteration
    //         prev = cur;
    //     }

    //     // The result will be in the last cell of the table
    //     return prev[amount];
    // }

    //    // ++++++++++++++++ Space Optimzation(1D array) +++++++++++++ TC
    //    O(n*amount) SC. O(amount)
    //     int change(int amount, vector<int>& coins) {
    //         int n = coins.size();

    //         // Initialize dp table with 0
    //         vector<long long> prev(amount + 1, 0);

    //         // Base case: If amount is 0, there is one way to make the sum,
    //         which is
    //         // not using any coins
    //         prev[0] = 1;

    //         // Initialize the first row based on the first coin
    //         for (int a = 1; a <= amount; a++) {
    //             prev[a] = (a % coins[0] == 0) ? 1 : 0;
    //         }

    //         // Fill the DP table for other coins
    //         for (int ind = 1; ind < n; ind++) {
    //             for (int a = 0; a <= amount; a++) {

    //                 // Option 1: Do not take the current coin (carry over the
    //                 result
    //                 // from the previous row)
    //                 int notTake = prev[a];

    //                 // Option 2: Take the current coin if possible (subtract
    //                 coin
    //                 // value from current amount)
    //                 int take = 0;
    //                 if (coins[ind] <= a) {
    //                     take = prev[a - coins[ind]]; // Use prev instead of
    //                     cur
    //                 }

    //                 // Store the result for the current state
    //                 prev[a] = take + notTake;
    //             }
    //         }

    //         // The result will be in the last cell of the table
    //         return prev[amount];
    //     }

    // The way in which we compute the tabulation changes the solution efficiency.
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<uint64_t> dp(amount + 1, 0);
        dp[0] = 1;
        
        for(int coin = n - 1;coin >=0;coin--){
            for(int target = 0;target <= amount;target++){
                if(target >= coins[coin]){
                    dp[target] += dp[target - coins[coin]];
                }
            }
        }
        return dp[amount];
    }
};
