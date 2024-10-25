

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        if (goal < 0) return 0; // Edge case: if goal is negative, return 0
        int count = 0; // Variable to store the count of valid subarrays
        int sum = 0; // Variable to track the cumulative sum
        map<int, int> sumCount; // Map to count occurrences of cumulative sums
        sumCount[0] = 1; // Initialize for the case when a subarray equals the goal from the start

        // Iterate through the array
        for (int num : nums) {
            sum += num; // Update the cumulative sum
            
            // Check if there exists a cumulative sum that matches (current sum - goal)
            if (sumCount.find(sum - goal) != sumCount.end()) {
                count += sumCount[sum - goal]; // Increment count by the occurrences of (sum - goal)
            }

            // Increment the count of the current cumulative sum in the map
            sumCount[sum]++;
        }

        return count; // Return the total count of valid subarrays
    }
};
