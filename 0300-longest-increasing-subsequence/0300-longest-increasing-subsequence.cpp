class Solution {
public:
    // +++++++++++++ Recursive +++++++++++++++++++
    // TC O(2^n)
    // SC O(N)
    // Recursive function to calculate LIS
    // int f(int index, int prev_index, vector<int>& nums) {
    //     int n = nums.size();

    //     // Base case: If we reach the end of the array, return 0
    //     if (index == n) return 0;

    //     // Option 1: Skip the current element
    //     int notTake = f(index + 1, prev_index, nums);

    //     // Option 2: Take the current element if it is greater than the
    //     previous element int take = 0; if (prev_index == -1 || nums[index] >
    //     nums[prev_index]) {
    //         take = 1 + f(index + 1, index, nums);
    //     }

    //     // Return the maximum of both choices
    //     return max(take, notTake);
    // }

    // int lengthOfLIS(vector<int>& nums) {
    //     return f(0, -1, nums);
    // }

    // +++++++++++++++ Memoization ++++++++++++
    // TC O(n^2)
    // SC O(n^2) + o(n)
    // int f(int index, int prev_index, vector<int>& nums,
    //       vector<vector<int>>& dp) {
    //     int n = nums.size();

    //     // Base case: If we reach the end of the array, return 0
    //     if (index == n)
    //         return 0;

    //     // Check if the result is already computed
    //     if (dp[index][prev_index + 1] != -1)
    //         return dp[index][prev_index + 1];

    //     // Option 1: Skip the current element
    //     int notTake = f(index + 1, prev_index, nums, dp);

    //     // Option 2: Take the current element if it is greater than the previous
    //     // element
    //     int take = 0;
    //     if (prev_index == -1 || nums[index] > nums[prev_index]) {
    //         take = 1 + f(index + 1, index, nums, dp);
    //     }

    //     // Store and return the maximum of both choices
    //     return dp[index][prev_index + 1] = max(take, notTake);
    // }

    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();
    //     // DP table with dimensions [n][n+1], initialized with -1
    //     vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    //     return f(0, -1, nums, dp);
    // }

    // +++++++++++++ tabulation +++++++++++++
    // TC O(n^2)
    // SC O(n^2)
    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();
        
    //     // DP table where dp[index][prev_index + 1] stores the length of LIS 
    //     // starting from 'index' with 'prev_index' as the previous element
    //     vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    //     // Iterate through the array in reverse order (bottom-up approach)
    //     for (int index = n - 1; index >= 0; index--) {
    //         for (int prev_index = index - 1; prev_index >= -1; prev_index--) {
                
    //             // Option 1: Skip the current element
    //             int notTake = dp[index + 1][prev_index + 1];

    //             // Option 2: Take the current element if it's greater than the previous element
    //             int take = 0;
    //             if (prev_index == -1 || nums[index] > nums[prev_index]) {
    //                 take = 1 + dp[index + 1][index + 1]; // Move to the next index
    //             }

    //             // Store the maximum of both choices
    //             dp[index][prev_index + 1] = max(take, notTake);
    //         }
    //     }

    //     // The answer is stored in dp[0][0], which considers the entire array
    //     return dp[0][0];
    // }
    // +++++++++++++ Space Optimization +++++++++++++
    // TC O(n^2)
    // SC O(n)
        int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        // We only need two 1D arrays instead of a full 2D DP table.
        // `ahead` represents the future state (dp[index + 1])
        // `cur` represents the current state (dp[index])
        vector<int> ahead(n + 1, 0), cur(n + 1, 0);

        // Traverse the array from right to left (bottom-up approach)
        for (int index = n - 1; index >= 0; index--) {
            for (int prev_index = index - 1; prev_index >= -1; prev_index--) {
                
                // Option 1: Skip the current element
                int notTake = ahead[prev_index + 1];

                // Option 2: Take the current element if it's greater than the previous element
                int take = 0;
                if (prev_index == -1 || nums[index] > nums[prev_index]) {
                    take = 1 + ahead[index + 1]; // Move to the next index
                }

                // Store the maximum of both choices in the current array
                cur[prev_index + 1] = max(take, notTake);
            }

            // Update `ahead` to be the `cur` for the next iteration (moving backwards)
            ahead = cur;
        }

        // The answer is stored in ahead[0], which considers the entire array
        return ahead[0];
    }


};