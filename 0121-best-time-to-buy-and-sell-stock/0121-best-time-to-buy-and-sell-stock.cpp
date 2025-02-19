class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Get the size of the prices array
        int n = prices.size();

        // Initialize variables to track the minimum price encountered so far
        // and the maximum profit that can be achieved
        int mini =
            prices[0];     // Initialize mini with the first price in the array
        int maxProfit = 0; // Initialize maxProfit to 0

        // Traverse through the prices array
        for (int i = 0; i < n; i++) {
            // Calculate the potential profit if selling at the current price
            int profitIfSoldToday = prices[i] - mini;

            // Update maxProfit to store the maximum profit seen so far
            maxProfit = max(profitIfSoldToday, maxProfit);

            // Update mini to store the minimum price encountered so far
            mini = min(mini, prices[i]);
        }

        // Return the maximum profit that can be achieved
        return maxProfit;
    }
};