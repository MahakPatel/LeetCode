class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // If goal is negative, return 0 as there can't be any valid subarrays
        if (goal < 0)
            return 0;
        // Calculate the number of subarrays with exactly 'goal' 1s
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }

    // Helper function to count subarrays with at most 'goal' 1s
    int atMost(vector<int>& nums, int goal) {
        if (goal < 0)
            return 0; // Return 0 if goal is negative

        int l = 0;           // Left pointer for the sliding window
        int ans = 0;         // Variable to store the count of valid subarrays
        int n = nums.size(); // Size of the input array
        int sum =
            0;     // Variable to track the cumulative sum of the current window
        int r = 0; // Right pointer for the sliding window

        while (r < n) {     // Iterate with the right pointer
            sum += nums[r]; // Add the current element to the sum

            // While the sum exceeds the goal, shrink the window from the left
            while (sum > goal) {
                sum -= nums[l]; // Subtract the leftmost element from the sum
                l++;            // Move the left pointer to the right
            }

            // Count the number of valid subarrays ending at 'r'
            ans += (r - l +
                    1); // Add all valid subarrays ending at the right pointer
            r++;        // Move the right pointer to the right
        }

        return ans; // Return the total count of valid subarrays
    }
};
