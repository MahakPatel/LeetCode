class Solution {
public:
//+++++++++++++++++++++ Brute Force ++++++++++++++++++++++++++++
//     int subarraysWithKDistinct(vector<int>& nums, int k) {
//         int n = nums.size(); // Size of the input array
//         int count = 0; // Variable to store the count of valid subarrays

//         // Iterate through each starting index of the subarray
//         for (int i = 0; i < n; i++) {
//             map<int, int> mp; // Map to store the count of distinct elements

//             // Iterate through the subarray starting from index i
//             for (int j = i; j < n; j++) {
//                 mp[nums[j]]++; // Add the current element to the map

//                 // Check if the number of distinct elements is exactly k
//                 if (mp.size() == k) {
//                     count++; // Increment the count of valid subarrays
//                 } else if (mp.size() > k) {
//                     break; // Stop if more than k distinct elements are found
//                 }
//             }
//         }

//         return count; // Return the total count of valid subarrays
//     }
// };


// +++++++++++++++++ Optimal Solution ++++++++++++++++++++++++++
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // Calculate the number of subarrays with exactly 'k' distinct integers
        // by using the helper function for at most 'k' distinct and at most 'k-1' distinct
        return helper(nums, k) - helper(nums, k - 1);
    }

    // Helper function to count subarrays with at most 'k' distinct integers
    int helper(vector<int>& nums, int k) {
        int n = nums.size(); // Size of the input array
        int count = 0; // Variable to store the count of valid subarrays
        map<int, int> mp; // Map to store the count of distinct elements

        int r = 0; // Right pointer for the sliding window
        int l = 0; // Left pointer for the sliding window

        while (r < n) { // Iterate with the right pointer
            mp[nums[r]]++; // Add the current element to the map

            // While the number of distinct elements exceeds 'k', shrink the window from the left
            while (mp.size() > k) {
                mp[nums[l]]--; // Decrease the count of the leftmost element
                // If the count drops to zero, remove the element from the map
                if (mp[nums[l]] == 0) 
                    mp.erase(nums[l]); 
                l++; // Move the left pointer to the right
            }

            // Add the count of valid subarrays ending at 'r'
            count += (r - l + 1); // The number of valid subarrays is equal to the number of ways to choose the left pointer
            r++; // Move the right pointer to the right
        }

        return count; // Return the total count of valid subarrays
    }
};
