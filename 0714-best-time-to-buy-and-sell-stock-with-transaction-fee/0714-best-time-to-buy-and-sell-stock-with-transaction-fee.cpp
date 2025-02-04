class Solution {
public:
    // +++++++++++++++++ Recursive +++++++++++++++++++++++
    // TC O(2^n)
    // SC O(n)
    // int f(int index, int buy, vector<int>& prices, int fee) {
    //     int n = prices.size();

    //     // Base case: If we reach the end of the array, no more transactions can
    //     // be made.
    //     if (index == n)
    //         return 0;

    //     int profit = 0;

    //     // Case when we are allowed to buy
    //     if (buy) {
    //         // Two choices:
    //         // 1. Buy the stock (-prices[index]) and move to the next index with
    //         // 'buy' set to 0
    //         // 2. Skip buying and keep 'buy' as 1
    //         profit = max(-prices[index] + f(index + 1, 0, prices, fee), // Buy
    //                      f(index + 1, 1, prices, fee) // Skip buying
    //         );
    //     }
    //     // Case when we must sell
    //     else {
    //         // Two choices:
    //         // 1. Sell the stock (+prices[index]) and sub the transaction fee
    //         // and move to the next index with 'buy' set to 1
    //         // 2. Skip selling and keep 'buy' as 0
    //         profit =
    //             max(prices[index] - fee + f(index + 1, 1, prices, fee), // Sell
    //                 f(index + 1, 0, prices, fee) // Skip selling
    //             );
    //     }

    //     return profit;
    // }

    // int maxProfit(vector<int>& prices, int fee) {
    //     return f(0, 1, prices, fee); // Start from index 0 with buying allowed
    // }

    // +++++++++++++++++ Memoization +++++++++++++++++++++++
    // TC O(n)
    // SC O(n + n)
    // int f(int index, int buy, vector<int>& prices, vector<vector<int>>& dp,int fee) {
    //     int n = prices.size();

    //     // Base case: If we reach the end of the array, no more transactions can
    //     // be made.
    //     if (index == n)
    //         return 0;

    //     // If the result for the current state is already computed, return it. 
    //     if (dp[index][buy] != -1)
    //         return dp[index][buy];

    //     int profit = 0;

    //     if (buy) { // Buying allowed
    //         profit = max(-prices[index] + f(index + 1, 0, prices, dp,fee), // Buy
    //                      f(index + 1, 1, prices, dp,fee) // Skip buying
    //         );
    //     } else { // Selling allowed
    //         profit = max(prices[index] - fee + f(index + 1, 1, prices, dp,fee), // Sell
    //                      f(index + 1, 0, prices, dp,fee) // Skip selling
    //         );
    //     }

    //     return dp[index][buy] = profit; // Store the result in DP table
    // }

    // int maxProfit(vector<int>& prices,int fee) {
    //     int n = prices.size();
    //     vector<vector<int>> dp(
    //         n, vector<int>(2, -1)); // DP table initialized with -1
    //     return f(0, 1, prices, dp,fee);
    // }

    // ++++++++++++++++++++ Tabulation +++++++++++++++++
    // TC O(n)
    // SC O(n)
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<int>> dp(
    //         n + 1, vector<int>(2, 0)); // DP table with size (n+1) × 2

    //     // Base case: If we are at index `n`, no transactions can be made
    //     dp[n][0] = dp[n][1] = 0;

    //     // Iterate backward from the last day
    //     for (int i = n - 1; i >= 0; i--) {
    //         for (int buy = 0; buy <= 1; buy++) {
    //             if (buy) {
    //                 // Either buy or skip buying
    //                 dp[i][buy] = max(-prices[i] + dp[i + 1][0], dp[i +
    //                 1][1]);
    //             } else {
    //                 // Either sell or skip selling
    //                 dp[i][buy] = max(prices[i] - fee + dp[i + 1][1], dp[i + 1][0]);
    //             }
    //         }
    //     }
    //     return dp[0][1]; // Max profit starting at day 0 with buying allowed
    // }
    // ++++++++++++++++++++ Space Optimization +++++++++++++++++
    // TC O(n)
    // SC O(1)
    int maxProfit(vector<int>& prices,int fee) {
        int n = prices.size();
        vector<int> ahead(2, 0), cur(2, 0);

        // Base case: If we are at index `n`, no transactions can be made
        ahead[0] = ahead[1] = 0;

        // Iterate backward from the last day
        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy) {
                    // Either buy or skip buying
                    cur[buy] = max(-prices[i] + ahead[0], ahead[1]);
                } else {
                    // Either sell or skip selling
                    cur[buy] = max(prices[i] - fee + ahead[1], ahead[0]);
                }
            }
            // Move current state to previous state
            ahead = cur;
        }
        return ahead[1]; // Return `ahead[1]` instead of `cur[1]`
    }
};