class Solution {
public:
    // ++++++++++++++++ Optimal Solution +++++++++++++++
    // TC O(n^3)
    // TC O(number of quadruplets)
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans; // To store the final list of quadruplets

        sort(nums.begin(),
             nums.end()); // Sort the array to handle duplicates more easily

        // Outer loop for the first element of the quadruplet
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue; // Skip duplicates of the first element

            // Inner loop for the second element of the quadruplet
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue; // Skip duplicates of the second element

                int left = j + 1,
                    right = n - 1; // Two pointers for the remaining elements

                // While loop for checking the third and fourth elements using
                // two pointers
                while (left < right) {
                    long long sum =
                        (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target) {
                        ans.push_back(
                            {nums[i], nums[j], nums[left],
                             nums[right]}); // Found a valid quadruplet

                        // Skip duplicates for the left pointer
                        while (left < right && nums[left] == nums[left + 1])
                            left++;
                        // Skip duplicates for the right pointer
                        while (left < right && nums[right] == nums[right - 1])
                            right--;

                        left++;  // Move the left pointer to the right
                        right--; // Move the right pointer to the left

                    } else if (sum < target) {
                        left++; // Increase the sum by moving the left pointer
                                // to the right
                    } else {
                        right--; // Decrease the sum by moving the right pointer
                                 // to the left
                    }
                }
            }
        }

        return ans; // Return the list of valid quadruplets
    }
};