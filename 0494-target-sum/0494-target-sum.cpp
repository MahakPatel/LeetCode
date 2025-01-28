class Solution {
public:
    // +++++++++++++++ Tabulation ++++++++ TC O(n*target).  SC O(n * target)
    // ++++++++
    // // Function to calculate the number of ways to achieve a given target sum
    // // using subsets of the array
    // int perfectSum(vector<int>& arr, int target) {
    //     int n = arr.size(); // Size of the array

    //     // Create a DP table where dp[i][j] represents the number of ways to
    //     // achieve sum j using the first i elements
    //     vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    //     // Base case: If arr[0] == 0, there are two ways to form sum 0:
    //     include
    //     // or exclude 0
    //     dp[0][0] = (arr[0] == 0) ? 2 : 1; // If the first element is 0, two
    //     ways
    //                                       // to form sum 0: include or
    //                                       exclude 0

    //     // Base case: If arr[0] is nonzero and equals target, set
    //     dp[0][target]
    //     // = 1
    //     if (arr[0] != 0 && arr[0] <= target) {
    //         dp[0][arr[0]] =
    //             1; // Only one way to form sum equal to the first element
    //     }

    //     // Fill the DP table for all indices and target sums
    //     for (int ind = 1; ind < n; ind++) {
    //         for (int sum = 0; sum <= target; sum++) {
    //             // Case 1: Exclude the current element (don't take it)
    //             int notTake = dp[ind - 1][sum];

    //             // Case 2: Include the current element (if it does not exceed
    //             // the target sum)
    //             int take = 0;
    //             if (arr[ind] <= sum) {
    //                 take =
    //                     dp[ind - 1][sum - arr[ind]]; // Take the number of
    //                     ways
    //                                                  // to form sum -
    //                                                  arr[ind]
    //             }

    //             // Total ways to form the sum by either including or
    //             excluding
    //             // the current element
    //             dp[ind][sum] = take + notTake;
    //         }
    //     }

    //     // The result is stored in dp[n-1][target], which contains the number
    //     of
    //     // ways to form the target sum
    //     return dp[n - 1][target];
    // }

    // // Function to check if partitioning is possible and find the number of
    // ways
    // // to partition the array into subsets
    // int countPartitions(vector<int>& arr, int d) {
    //     int totalSum = 0;
    //     int n = arr.size();

    //     // Calculate the total sum of all elements in the array
    //     for (int i = 0; i < n; i++) {
    //         totalSum += arr[i];
    //     }

    //     // If partitioning is impossible (either totalSum - d is negative or
    //     not
    //     // even), return 0
    //     if (totalSum - d < 0 || (totalSum - d) % 2 != 0)
    //         return 0;

    //     // The target sum for partitioning is (totalSum - d) / 2
    //     int target = (totalSum - d) / 2;

    //     // Call perfectSum to find the number of ways to form the target sum
    //     return perfectSum(arr, target);
    // }

    // // Function to find the number of ways to assign + or - signs to achieve
    // the
    // // target sum
    // int findTargetSumWays(vector<int>& nums, int target) {
    //     return countPartitions(
    //         nums, target); // Calculate the result by partitioning the array
    // }


    // ++++++++++++++ Space Optimization +++++++++++ TC O(n*target).  Sc O(target)
    // Function to calculate the number of ways to achieve a given target sum
    // using subsets of the array
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size(); // Size of the array
        vector<int> prev(target + 1,
                         0); // DP array to store the number of ways to form
                             // each sum using previous elements

        // Base case: There is always one way to form sum 0 (by not picking any
        // elements) If the first element is 0, we have two ways to form sum 0:
        // include it or exclude it
        prev[0] = (arr[0] == 0) ? 2 : 1;

        // Base case: If the first element is equal to the target, we can form
        // that sum with just that element
        if (arr[0] != 0 && arr[0] <= target) {
            prev[arr[0]] = 1; // There's one way to form sum equal to the first
                              // element (include it)
        }

        // Start filling the DP table for remaining elements
        for (int ind = 1; ind < n; ind++) {
            vector<int> cur(
                target + 1,
                0); // Current DP array for this iteration (for current element)

            // Loop through all possible sums from 0 to target
            for (int sum = 0; sum <= target; sum++) {
                // Case 1: Do not include the current element
                int notTake = prev[sum];

                // Case 2: Include the current element, if it doesn't exceed the
                // current sum
                int take = 0;
                if (arr[ind] <= sum) {
                    take = prev[sum - arr[ind]]; // Add the number of ways to
                                                 // form sum - arr[ind]
                }

                // Total ways to form the current sum: either include or exclude
                // the current element
                cur[sum] = take + notTake;
            }

            prev = cur; // Move to the next element: update previous row to
                        // current row
        }

        // The answer is the number of ways to form the target sum using all
        // elements
        return prev[target];
    }

    // Function to check if it's possible to partition the array into two
    // subsets that satisfy the target difference
    int countPartitions(vector<int>& arr, int d) {
        int totalSum = 0;
        int n = arr.size();

        // Calculate the total sum of all elements in the array
        for (int i = 0; i < n; i++) {
            totalSum += arr[i];
        }

        // If the difference d is greater than the total sum, or if (totalSum -
        // d) is odd, partitioning is impossible
        if (totalSum - d < 0 || (totalSum - d) % 2 != 0)
            return 0;

        // The target sum for partitioning is (totalSum - d) / 2
        int target = (totalSum - d) / 2;

        // Use the perfectSum function to find the number of ways to form the
        // target sum
        return perfectSum(arr, target);
    }

    // Function to find the number of ways to assign + or - signs to achieve the
    // target sum
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums,
                               target); // Call the countPartitions function to
                                        // calculate the result
    }
};