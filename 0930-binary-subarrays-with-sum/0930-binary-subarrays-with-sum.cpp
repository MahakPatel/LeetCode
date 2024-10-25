class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        if (goal < 0) return 0; // Edge case: if goal is negative, return 0
        int n = nums.size(); // Size of the input array
        int left = 0; // Left pointer for the sliding window
        int count = 0; // Variable to store the count of valid subarrays
        int sum = 0; // Variable to track the sum of the current window

        // Iterate through the array with the right pointer
        for (int right = 0; right < n; right++) {
            sum += nums[right]; // Add the current element to the sum
            
            // While the sum exceeds the goal, shrink the window from the left
            while (sum > goal) {
                sum -= nums[left]; // Subtract the leftmost element from the sum
                left++; // Move the left pointer to the right
            }

            // If the sum equals the goal, count the valid subarrays
            // Count the number of subarrays ending at 'right' with the exact sum of 'goal'
            if (sum == goal) {
                count++; // Count the current subarray
            }

            // Handle additional subarrays when the sum is equal to the goal
            // Check for contiguous zeros (when the sum is equal to the goal)
            int tempLeft = left; // Temporary left pointer to count zeros
            while (tempLeft < right && nums[tempLeft] == 0) {
                count++; // Count subarrays formed with zeros
                tempLeft++; // Move temporary left pointer to the right
            }
        }

        return count; // Return the count of valid subarrays
    }
};
