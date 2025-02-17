class Solution {
public:
    // ++++++++++++++++++ Brute Force +++++++++++++++++
    // TC O(N^3)
    // SC O(1)
    // int maxProduct(vector<int>& nums) {
    //     int n = nums.size();

    //     int maxi = INT_MIN; // Stores the maximum product found

    //     // Iterate over all subarrays
    //     for (int i = 0; i < n; i++) {
    //         for (int j = i; j < n; j++) {
    //             int product = 1; // Stores product of current subarray

    //             // Compute the product of subarray nums[i..j]
    //             for (int k = i; k <= j; k++) {
    //                 product = product * nums[k];
    //             }

    //             // Update maximum product found so far
    //             maxi = max(maxi, product);
    //         }
    //     }

    //     return maxi; // Return the largest product found
    // }

    // ++++++++++++++++++ Better Solution +++++++++++++++++
    // TC O(N^2)
    // SC O(1)
    // int maxProduct(vector<int>& nums) {
    //     int n = nums.size();

    //     int maxi = INT_MIN; // Stores the maximum product found

    //     // Iterate over all possible subarrays
    //     for (int i = 0; i < n; i++) {
    //         int product = 1; // Stores the product of the current subarray

    //         // Expand the subarray from index i to j
    //         for (int j = i; j < n; j++) {
    //             product = product * nums[j]; // Compute product incrementally

    //             maxi = max(maxi, product); // Update the maximum product
    //             found
    //         }
    //     }

    //     return maxi; // Return the largest product found
    // }


    // ++++++++++++++++++ Optimal Solution +++++++++++++++++
    // TC O(N)
    // SC O(1)
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int maxi = INT_MIN; // Stores the maximum product found so far
        int product = 1;    // Stores the product of the current subarray

        // Traverse the array to compute the maximum product subarray
        for (int i = 0; i < n; i++) {
            product =
                product * nums[i]; // Multiply current element with the product

            maxi =
                max(maxi, product); // Update the maximum product found so far

            // Reset product to 1 if it becomes negative
            // This is incorrect in some cases, as negative numbers might lead
            // to larger products later
            if (product < 0) {
                product = 1;
            }
        }

        return maxi; // Return the maximum product found
    }
};