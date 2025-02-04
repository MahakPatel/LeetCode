class Solution {
public:
    // // +++++++++++++++++ Recursive +++++++++++++++++++++++
    // // TC O(2^n)
    // // SC O(n)
    // int f(int index, int buy, vector<int>& prices) {
    //     int n = prices.size();

    //     // Base case: If index goes beyond the array, return 0 (no profit)
    //     if (index >= n)
    //         return 0;

    //     int profit = 0;

    //     // Case when we are allowed to buy
    //     if (buy) {
    //         profit = max(-prices[index] + f(index + 1, 0, prices), // Buy
    //                      f(index + 1, 1, prices)); // Skip buying
    //     }
    //     // Case when we must sell
    //     else {
    //         profit = max(prices[index] + f(index + 2, 1, prices), // Sell
    //         with cooldown
    //                      f(index + 1, 0, prices)); // Skip selling
    //     }

    //     return profit;
    // }

    // int maxProfit(vector<int>& prices) {
    //     return f(0, 1, prices);
    // }

    // // +++++++++++++++++ Memoization +++++++++++++++++++++++
    // // TC O(n)
    // // SC O(n + n)
    // int f(int index, int buy, vector<int>& prices, vector<vector<int>>& dp) {
    //     int n = prices.size();

    //     // Base case: If index goes beyond the array, return 0 (no profit)
    //     if (index >= n)
    //         return 0;

    //     // Check if already computed
    //     if (dp[index][buy] != -1)
    //         return dp[index][buy];

    //     int profit = 0;

    //     // If we can buy
    //     if (buy) {
    //         profit = max(-prices[index] + f(index + 1, 0, prices, dp),  //
    //         Buy
    //                      f(index + 1, 1, prices, dp));                 //
    //                      Skip buying
    //     }
    //     // If we must sell
    //     else {
    //         profit = max(prices[index] + f(index + 2, 1, prices, dp),  //
    //         Sell (with cooldown)
    //                      f(index + 1, 0, prices, dp));                 //
    //                      Skip selling
    //     }

    //     return dp[index][buy] = profit;
    // }

    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<int>> dp(n, vector<int>(2, -1));  // Initialize DP
    //     array with -1 return f(0, 1, prices, dp);  // Start recursion from
    //     index 0, with buying allowed
    // }

    // // +++++++++++++++++ Tabulation +++++++++++++++++++++++
    // // TC O(n)
    // // SC O(n)
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<int>> dp(n + 2, vector<int>(2, 0));  // Extra row for
    //     handling index + 2 case

    //     // Fill DP table from last index to first
    //     for (int index = n - 1; index >= 0; index--) {
    //         for (int buy = 0; buy <= 1; buy++) {
    //             if (buy) {
    //                 dp[index][buy] = max(-prices[index] + dp[index + 1][0],
    //                 // Buy
    //                                      dp[index + 1][1]); // Skip buying
    //             } else {
    //                 dp[index][buy] = max(prices[index] + dp[index + 2][1], //
    //                 Sell (cooldown)
    //                                      dp[index + 1][0]); // Skip selling
    //             }
    //         }
    //     }

    //     return dp[0][1];  // Max profit starting from day 0 with buying
    //     allowed
    // }

    // // +++++++++++++++++ Space Optimization +++++++++++++++++++++++
    // // TC O(n)
    // // SC O(1)
        int maxProfit(vector<int>& prices) {
            int n = prices.size();

            // Space optimized variables
            vector<int> ahead(2, 0), cur(2, 0);
            vector<int> ahead2(2, 0); // Represents dp[index + 2]

            // Fill DP table from last index to first
            for (int index = n - 1; index >= 0; index--) {
                for (int buy = 0; buy <= 1; buy++) {
                    if (buy) {
                        // Buy the stock or skip
                        cur[buy] = max(-prices[index] + ahead[0], ahead[1]);
                    } else {
                        // Sell the stock or skip (considering cooldown)
                        cur[buy] = max(prices[index] + ahead2[1], ahead[0]);
                    }
                }

                // Shift ahead states
                ahead2 = ahead;
                ahead = cur;
            }

            return ahead[1]; // Max profit starting from day 0 with buying
                             // allowed
        }
    };
