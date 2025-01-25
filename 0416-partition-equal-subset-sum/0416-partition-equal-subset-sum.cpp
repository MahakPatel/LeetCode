class Solution {
public:
    // Function to check if there exists a subset with a given sum
    bool isSubsetSum(vector<int>& arr, int target) {
        int n = arr.size(); // Get the size of the array

        // Two arrays: 'prev' stores the previous row, 'cur' stores the current
        // row
        vector<bool> prev(target + 1, false), cur(target + 1, false);

        // Base case: Subset sum of 0 is always possible (empty subset)
        prev[0] = cur[0] = true;

        // Initialize the first row for the first element of the array
        // If the first element is less than or equal to the target, mark it as
        // possible
        if (arr[0] <= target) {
            prev[arr[0]] = true;
        }

        // Iterate through the rest of the array (from the second element
        // onward)
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= target; j++) {
                // Option 1: Do not include the current element in the subset
                bool notTake = prev[j];

                // Option 2: Include the current element in the subset, if
                // possible
                bool take = false;
                if (j >= arr[i]) {
                    take = prev[j - arr[i]]; // Check if the remaining sum can
                                             // be achieved
                }

                // Update the current state with the result of either taking or
                // not taking the element
                cur[j] = take || notTake;
            }

            // Move to the next row by copying the current row into 'prev'
            prev = cur;
        }

        // The answer to whether a subset with the target sum exists is in
        // prev[target]
        return prev[target];
    }

    // Function to determine if the array can be partitioned into two subsets of
    // equal sum
    bool canPartition(vector<int>& nums) {
        int n = nums.size(); // Get the size of the input array

        int totalSum =
            0; // Variable to store the sum of all elements in the array

        // Calculate the total sum of the array
        for (int i = 0; i < n; i++) {
            totalSum += nums[i];
        }

        // If the total sum is odd, it's impossible to partition into two equal
        // subsets
        if (totalSum % 2 != 0) {
            return false;
        }

        // Use the isSubsetSum function to check if there exists a subset with
        // sum equal to totalSum / 2
        return isSubsetSum(nums, totalSum / 2);
    }
};