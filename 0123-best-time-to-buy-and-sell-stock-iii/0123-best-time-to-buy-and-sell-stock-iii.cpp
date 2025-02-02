class Solution {
public:
    // +++++++++++++++++ Recursive +++++++++++++++++++++++
    // TC O(2^n)
    // SC O(n)

    // // Recursive function to find the maximum profit with at most 2
    // transactions int f(int index, int buy, vector<int>& prices, int cap) {
    //     int n = prices.size();

    //     // Base case: If we reach the end of the array, no more transactions
    //     can
    //     // be made.
    //     if (index == n)
    //         return 0;

    //     // If we have used up our 2 transactions, we cannot make any more
    //     // trades.
    //     if (cap == 0)
    //         return 0;

    //     int profit = 0;

    //     // If 'buy' is 1, we have the option to buy the stock or skip
    //     if (buy) {
    //         profit = max(-prices[index] +
    //                          f(index + 1, 0, prices,
    //                            cap), // Buy the stock and reduce buy
    //                            opportunity
    //                      f(index + 1, 1, prices,
    //                        cap) // Skip buying and move to the next day
    //         );
    //     }
    //     // If 'buy' is 0, we have the option to sell the stock or skip
    //     else {
    //         profit = max(
    //             prices[index] +
    //                 f(index + 1, 1, prices,
    //                   cap -
    //                       1), // Sell the stock and reduce transaction
    //                       capacity
    //             f(index + 1, 0, prices,
    //               cap) // Skip selling and move to the next day
    //         );
    //     }

    //     return profit;
    // }

    // // Wrapper function to initialize the recursive function
    // int maxProfit(vector<int>& prices) {
    //     return f(0, 1, prices, 2); // Start from index 0, buying is allowed,
    //     and
    //                                // we can make at most 2 transactions
    // }

    // +++++++++++++++++ Memoization +++++++++++++++++++++++
    // TC O(2*3*n)
    // SC O(n + n)

    // // Recursive function to find the maximum profit with at most 2
    // transactions int f(int index, int buy, vector<int>& prices, int cap,
    //       vector<vector<vector<int>>>& dp) {
    //     int n = prices.size();

    //     // Base case: If we reach the end of the array, no more transactions
    //     can
    //     // be made.
    //     if (index == n)
    //         return 0;

    //     // If we have used up our 2 transactions, we cannot make any more
    //     // trades.
    //     if (cap == 0)
    //         return 0;

    //     // Memoization check: If the result is already computed, return it.
    //     if (dp[index][buy][cap] != -1)
    //         return dp[index][buy][cap];

    //     int profit = 0;

    //     // If 'buy' is 1, we have the option to buy the stock or skip
    //     if (buy) {
    //         profit =
    //             max(-prices[index] + f(index + 1, 0, prices, cap,
    //                                    dp), // Buy the stock and move to the
    //                                         // next index with 'buy' set to 0
    //                 f(index + 1, 1, prices, cap,
    //                   dp) // Skip buying and move to the next day
    //             );
    //     }
    //     // If 'buy' is 0, we have the option to sell the stock or skip
    //     else {
    //         profit =
    //             max(prices[index] +
    //                     f(index + 1, 1, prices, cap - 1,
    //                       dp), // Sell the stock and reduce transaction
    //                       capacity
    //                 f(index + 1, 0, prices, cap,
    //                   dp) // Skip selling and move to the next day
    //             );
    //     }

    //     // Store the computed result in the dp table
    //     return dp[index][buy][cap] = profit;
    // }

    // // Wrapper function to initialize the recursive function
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();

    //     // Memoization table: dp[index][buy][cap]
    //     // Dimensions: n+1 (days) × 2 (buy/sell) × 3 (at most 2 transactions)
    //     vector<vector<vector<int>>> dp(
    //         n + 1, vector<vector<int>>(2, vector<int>(3, -1)));

    //     // Start from index 0, buying is allowed, and we can make at most 2
    //     // transactions
    //     return f(0, 1, prices, 2, dp);
    // }

    // // +++++++++++++++++ Tabulation +++++++++++++++++++++++
    // // TC O(2*3*n)
    // // SC O(n)
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();

    //     // Memoization table: dp[index][buy][cap]
    //     // Dimensions: (n+1) days × 2 (buy/sell) × 3 (at most 2 transactions)
    //     vector<vector<vector<int>>> dp(
    //         n + 1, vector<vector<int>>(2, vector<int>(3, -1)));

    //     // Base case: No profit can be made after the last day
    //     for (int i = 0; i <= n; i++) {
    //         for (int buy = 0; buy <= 1; buy++) {
    //             dp[i][buy][0] = 0; // No transactions left
    //         }
    //     }

    //     // Initialize dp[n][buy][cap] = 0 (No transactions after the last
    //     day) for (int buy = 0; buy <= 1; buy++) {
    //         for (int cap = 0; cap <= 2; cap++) {
    //             dp[n][buy][cap] = 0;
    //         }
    //     }

    //     // Fill the dp table in reverse order (from the last day to the
    //     first) for (int i = n - 1; i >= 0; i--) {
    //         for (int buy = 0; buy <= 1; buy++) {
    //             for (int cap = 1; cap <= 2; cap++) {
    //                 int profit = 0;

    //                 // If 'buy' is 1, we have the option to buy the stock or
    //                 // skip
    //                 if (buy) {
    //                     profit =
    //                         max(-prices[i] +
    //                                 dp[i + 1][0]
    //                                   [cap], // Buy the stock and move to the
    //                                          // next index with 'buy' set to
    //                                          0
    //                             dp[i + 1][1]
    //                               [cap] // Skip buying and move to the next
    //                               day
    //                         );
    //                 }
    //                 // If 'buy' is 0, we have the option to sell the stock or
    //                 // skip
    //                 else {
    //                     profit =
    //                         max(prices[i] +
    //                                 dp[i + 1][1]
    //                                   [cap - 1], // Sell the stock and reduce
    //                                              // transaction capacity
    //                             dp[i + 1][0]
    //                               [cap] // Skip selling and move to the next
    //                               day
    //                         );
    //                 }

    //                 // Store the computed result in the dp table
    //                 dp[i][buy][cap] = profit;
    //             }
    //         }
    //     }

    //     // Start from index 0, buying is allowed, and we can make at most 2
    //     // transactions
    //     return dp[0][1][2];
    // }

    // +++++++++++++++++ Space Optimization +++++++++++++++++++++++
    // TC O(2*3*n)
    // SC O(1)
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // Create dp tables for storing results:
        // `after` stores the results for the next day (future states)
        // `cur` stores the results for the current day
        vector<vector<int>> after(2, vector<int>(3, -1));
        vector<vector<int>> cur(2, vector<int>(3, -1));

        // Fill the dp table in reverse order (from the last day to the first)
        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= 2; cap++) {
                    int profit = 0;

                    // If 'buy' is 1, we have the option to buy the stock or
                    // skip
                    if (buy) {
                        profit = max(
                            -prices[i] +
                                after[0][cap], // Buy the stock and move to the
                                               // next day with 'buy' set to 0
                            after[1]
                                 [cap] // Skip buying and move to the next day
                        );
                    }
                    // If 'buy' is 0, we have the option to sell the stock or
                    // skip
                    else {
                        profit = max(
                            prices[i] +
                                after[1][cap - 1], // Sell the stock and reduce
                                                   // transaction capacity
                            after[0]
                                 [cap] // Skip selling and move to the next day
                        );
                    }

                    // Store the computed result in the dp table for the current
                    // day
                    cur[buy][cap] = profit;
                }
            }

            // After processing the current day, move the `cur` array to `after`
            // for the next iteration
            after = cur;
        }

        // Start from index 0, buying is allowed, and we can make at most 2
        // transactions
        return after[1][2]; // The final result is the maximum profit starting
                            // at day 0 with 2 transactions allowed
    }
};