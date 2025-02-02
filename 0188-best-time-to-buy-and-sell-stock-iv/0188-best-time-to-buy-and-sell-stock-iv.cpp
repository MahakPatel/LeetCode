class Solution {
public:
    // +++++++++++++++ Memoization ++++++++++++++
    // TC O(n*k)
    // SC 0(n*k + (n+k))
    // Recursive function to calculate the maximum profit
    // int getAns(vector<int>& Arr, int n, int ind, int buy, int cap,
    //            vector<vector<vector<int>>>& dp) {
    //     // Base case: If we are out of days or if we can't make any more
    //     // transactions (cap is 0)
    //     if (ind == n || cap == 0)
    //         return 0;

    //     // Check if the result is already computed (memoization)
    //     if (dp[ind][buy][cap] != -1)
    //         return dp[ind][buy][cap];

    //     int profit;

    //     // Case 1: We can buy the stock (if buy == 0)
    //     if (buy == 0) {
    //         profit = max(0 + getAns(Arr, n, ind + 1, 0, cap,
    //                                 dp), // Don't buy, move to next day
    //                      -Arr[ind] + getAns(Arr, n, ind + 1, 1, cap,
    //                                         dp) // Buy and move to next day
    //         );
    //     }

    //     // Case 2: We can sell the stock (if buy == 1)
    //     if (buy == 1) {
    //         profit = max(0 + getAns(Arr, n, ind + 1, 1, cap,
    //                                 dp), // Don't sell, move to next day
    //                      Arr[ind] + getAns(Arr, n, ind + 1, 0, cap - 1,
    //                                        dp) // Sell and move to next day
    //                                        with
    //                                            // one less transaction
    //         );
    //     }

    //     // Store the computed result in the DP array for memoization and
    //     return
    //     // the result
    //     return dp[ind][buy][cap] = profit;
    // }

    // // Wrapper function to initialize the recursive function
    // int maxProfit(int k, vector<int>& prices) {
    //     int n = prices.size();

    //     // Create a 3D DP array with dimensions [n][2][k+1]
    //     // n: number of days
    //     // 2: two states (buy or sell)
    //     // k+1: transaction count from 0 to k
    //     vector<vector<vector<int>>> dp(
    //         n, vector<vector<int>>(2, vector<int>(k + 1, -1)));

    //     // Call the recursive function starting from index 0, with buy
    //     allowed
    //     // and k transactions left
    //     return getAns(prices, n, 0, 0, k, dp);
    // }

    //
    // +++++++++++++++ Tabulation ++++++++++++++
    // TC O(n*k)
    // SC 0(n*k)
    // int maxProfit(int k, vector<int>& Arr) {
    //     int n = Arr.size();

    //     // Create a 3D DP array of size [n+1][2][k+1]
    //     // dp[ind][buy][cap] represents the maximum profit achievable
    //     starting
    //     // from day 'ind', with 'buy' (0: buying allowed, 1: selling
    //     allowed),
    //     // and 'cap' (the number of remaining transactions) allowed.
    //     vector<vector<vector<int>>> dp(
    //         n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

    //     // Loop through the stock prices starting from the last day to the
    //     first for (int ind = n - 1; ind >= 0; ind--) {
    //         for (int buy = 0; buy <= 1; buy++) {
    //             for (int cap = 1; cap <= k; cap++) {

    //                 // Case when we can buy the stock (buy == 0)
    //                 if (buy == 0) {
    //                     // Option 1: Skip buying (stay at the same state)
    //                     // Option 2: Buy the stock (reduce the available
    //                     // transactions)
    //                     dp[ind][buy][cap] =
    //                         max(0 + dp[ind + 1][0]
    //                                   [cap], // Skip buying, stay at 'buy'
    //                                   state
    //                             -Arr[ind] + dp[ind + 1][1][cap] // Buy the
    //                             stock
    //                         );
    //                 }

    //                 // Case when we can sell the stock (buy == 1)
    //                 if (buy == 1) {
    //                     // Option 1: Skip selling (stay at the same state)
    //                     // Option 2: Sell the stock (reduce the number of
    //                     // remaining transactions)
    //                     dp[ind][buy][cap] = max(
    //                         0 + dp[ind + 1][1]
    //                               [cap], // Skip selling, stay at 'sell'
    //                               state
    //                         Arr[ind] + dp[ind + 1][0][cap - 1] // Sell the
    //                         stock
    //                     );
    //                 }
    //             }
    //         }
    //     }

    //     // The result is stored in dp[0][0][k] (starting from index 0, buying
    //     // allowed, with k transactions)
    //     return dp[0][0][k];
    // }

    // +++++++++++++++ Space Optimization ++++++++++++++
    // TC O(n*k)
    // SC 0(k)
    int maxProfit(int k, vector<int>& Arr) {
        int n = Arr.size();

        // Create two 2D arrays: 'ahead' for the results of the next iteration,
        // and 'cur' for the results of the current iteration.
        // ahead[buy][cap] represents the maximum profit achievable starting
        // from the current index, with the option to buy (buy = 0) or sell (buy
        // = 1), and with the given number of remaining transactions (cap).
        vector<vector<int>> ahead(2, vector<int>(k + 1, 0));
        vector<vector<int>> cur(2, vector<int>(k + 1, 0));

        // Loop through the stock prices from the last day (n-1) to the first
        // (0)
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= k; cap++) {
                    if (buy == 0) { // We can buy the stock
                        // Option 1: Skip buying (stay at the same state)
                        // Option 2: Buy the stock (move to the next day and
                        // reduce transactions)
                        cur[buy][cap] =
                            max(0 + ahead[0][cap],          // Skip buying
                                -Arr[ind] + ahead[1][cap]); // Buy the stock
                    }

                    if (buy == 1) { // We can sell the stock
                        // Option 1: Skip selling (stay at the same state)
                        // Option 2: Sell the stock (move to the next day and
                        // reduce transactions)
                        cur[buy][cap] =
                            max(0 + ahead[1][cap],             // Skip selling
                                Arr[ind] + ahead[0][cap - 1]); // Sell the stock
                    }
                }
            }

            // After calculating the values for the current day, update 'ahead'
            // with the results of 'cur'
            ahead = cur;
        }

        // The result is stored in ahead[0][k], which represents the maximum
        // profit starting from day 0, with buying allowed, and with k
        // transactions remaining
        return ahead[0][k];
    }
};