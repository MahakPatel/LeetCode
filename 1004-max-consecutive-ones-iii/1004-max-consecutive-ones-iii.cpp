class Solution {
public:
    // +++++++++++++++++++ Brute Force +++++++++++++++++++
    // Function to find the longest contiguous subarray of 1's with at most k
    // flips
    //     int longestOnes(vector<int>& nums, int k) {
    //         int n = nums.size(); // Size of the input array
    //         int maxLen = 0; // Variable to store the maximum length of the
    //         subarray

    //         // Iterate through each starting point
    //         for (int i = 0; i < n; i++) {
    //             int zero = 0; // Counter for zeros in the current subarray
    //             // Check the subarray starting from index i
    //             for (int j = i; j < n; j++) {
    //                 // Count zeros
    //                 if (nums[j] == 0) {
    //                     zero++;
    //                 }
    //                 // If the number of zeros is within the limit, calculate
    //                 the length if (zero <= k) {
    //                     int length = j - i + 1; // Calculate the length of
    //                     the subarray maxLen = max(maxLen, length); // Update
    //                     maxLen if needed
    //                 }
    //             }
    //         }

    //         return maxLen; // Return the maximum length found
    //     }
    // };

    // ++++++++++++++++++++ Better Approch +++++++++++++++++++++

    //     int longestOnes(vector<int>& nums, int k) {
    //         int n = nums.size();     // Size of the input array
    //         int left = 0;            // Left pointer
    //         int right = 0;           // Right pointer
    //         int zero = 0;            // Count of zeros in the current window
    //         int maxLen = 0;          // Maximum length of the subarray

    //         while (right < n) { // Iterate over the array with the right
    //         pointer
    //             if (nums[right] == 0) {
    //                 zero++; // Count the zeros
    //             }

    //             // If the count of zeros exceeds k, move the left pointer
    //             while (zero > k) {
    //                 if (nums[left] == 0) {
    //                     zero--; // Reduce the zero count
    //                 }
    //                 left++; // Move the left pointer to the right
    //             }

    //             // Calculate the length of the current valid window
    //             int length = right - left + 1;
    //             maxLen = max(maxLen, length); // Update maximum length if
    //             needed

    //             right++; // Move the right pointer to the right
    //         }

    //         return maxLen; // Return the maximum length of subarray found
    //     }
    // };

    // +++++++++++++++ Optimal Approch ++++++++++++++++++++++++++
    // Function to find the longest contiguous subarray of 1's with at most k
    // flips
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(); // Size of the input array
        int left = 0;        // Left pointer
        int right = 0;       // Right pointer
        int zero = 0;        // Count of zeros in the current window
        int maxLen = 0;      // Maximum length of the subarray

        // Iterate through the array with the right pointer
        while (right < n) {
            // Count the number of zeros in the current window
            if (nums[right] == 0) {
                zero++;
            }

            // If the count of zeros exceeds k, move the left pointer
            while (zero > k) {
                if (nums[left] == 0) {
                    zero--; // Decrease the zero count
                }
                left++; // Move the left pointer to the right
            }

            // Calculate the length of the current valid window
            int len = right - left + 1;
            maxLen = max(maxLen, len); // Update the maximum length if needed

            // Move the right pointer to expand the window
            right++;
        }

        return maxLen; // Return the maximum length found
    }
};

