
class Solution {
public:
    //. ++++++++++++++++++++ memoization +++++++++++++++++++++++++
    // int memoization(const std::vector<int> &nums, std::vector<int> &dp, int
    // index) {
    //     if (index == 0) return nums[index];  // Base case: only one house

    //     if (index < 0) return 0;  // Out of bounds

    //     if (dp[index] != -1) return dp[index];  // Return already computed
    //     value

    //     // Option 1: Pick the current house and move to index - 2
    //     int picked = nums[index] + memoization(nums, dp, index - 2);

    //     // Option 2: Skip the current house and move to index - 1
    //     int notPicked = memoization(nums, dp, index - 1);

    //     // Store the maximum of picking or not picking the current house
    //     return dp[index] = std::max(picked, notPicked);
    // }

    // int rob(const std::vector<int>& nums) {
    //     int n = nums.size();

    //     if (n == 0) return 0;  // Edge case: no houses

    //     std::vector<int> dp(n, -1);  // Initialize dp vector for n houses

    //     return memoization(nums, dp, n - 1);  // Compute the maximum profit
    // }


// ++++++++++++++++++++ bottom-up(tabular) ++++++++++++++++
    // int rob(const std::vector<int>& nums) {
    //     int n = nums.size();

    //     if (n == 0)
    //         return 0; // Edge case: no houses

    //     // Initialize dp vector with appropriate size and values
    //     std::vector<int> dp(n, 0);

    //     // Base case: only one house
    //     dp[0] = nums[0];

    //     // Iterate through the houses
    //     for (int i = 1; i < n; ++i) {
    //         // Option 1: Pick the current house
    //         int picked = nums[i];
    //         if (i > 1) {
    //             picked += dp[i - 2];
    //         }

    //         // Option 2: Skip the current house
    //         int notPicked = dp[i - 1];

    //         // Store the maximum of picking or not picking the current house
    //         dp[i] = std::max(picked, notPicked);
    //     }

    //     // The maximum amount of money that can be robbed is stored in dp[n-1]
    //     return dp[n - 1];
    // }
    // ++++++++++++++++ Space optimazation ++++++++++++++++++++
    int rob(const std::vector<int>& nums) {
        int n = nums.size();

        // Edge case: no houses
        if (n == 0)
            return 0;

        // Edge case: only one house
        if (n == 1)
            return nums[0];

        int prev2 = 0;      // Maximum amount robbed two houses before
        int prev = nums[0]; // Maximum amount robbed one house before

        // Iterate through the houses starting from the second house
        for (int i = 1; i < n; ++i) {
            // Option 1: Pick the current house
            int picked = nums[i];
            if (i > 1) {
                picked += prev2;
            }

            // Option 2: Skip the current house
            int notPicked = prev;

            // Update current max amount
            int current = std::max(picked, notPicked);

            // Update prev2 and prev for the next iteration
            prev2 = prev;
            prev = current;
        }

        // The maximum amount of money that can be robbed
        return prev;
    }
};