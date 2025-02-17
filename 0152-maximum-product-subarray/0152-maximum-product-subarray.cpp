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

        int pre = 1, suff = 1; // Prefix and Suffix product trackers
        int maxi = INT_MIN;    // Stores the maximum product found so far

        // Iterate through the array while maintaining both prefix and suffix
        // products
        for (int i = 0; i < n; i++) {

            // Reset prefix and suffix products to 1 when encountering zero
            if (pre == 0)
                pre = 1;
            if (suff == 0)
                suff = 1;

            // Compute prefix product from left to right
            pre = pre * nums[i];

            // Compute suffix product from right to left
            suff = suff * nums[n - i - 1];

            // Update the global maximum product using both prefix and suffix
            maxi = max(maxi, max(pre, suff));
        }

        return maxi; // Return the maximum product subarray
    }
};